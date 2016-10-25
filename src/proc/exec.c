#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "noah.h"
#include "vmm.h"
#include "mm.h"
#include "x86/page.h"
#include "x86/vmemparam.h"
#include "elf.h"

#include "linux/common.h"
#include "linux/mman.h"
#include "linux/misc.h"

extern uint64_t brk_min;

void init_userstack(int argc, char *argv[], char **envp, uint64_t exe_base, const Elf64_Ehdr *ehdr, uint64_t interp_base);

int
load_elf_interp(const char *path, ulong load_addr)
{
  char *data;
  Elf64_Ehdr *h;
  uint64_t map_top = 0;
  int fd;
  struct stat st;

  if ((fd = do_open(path, O_RDONLY, 0)) < 0) {
    fprintf(stderr, "load_elf_interp, could not open file: %s\n", path);
    return -1;
  }

  fstat(fd, &st);

  data = mmap(0, st.st_size, PROT_READ | PROT_EXEC, MAP_PRIVATE, fd, 0);

  close(fd);

  h = (Elf64_Ehdr *)data;

  assert(IS_ELF(*h));

  if (! (h->e_type == ET_EXEC || h->e_type == ET_DYN)) {
    return -LINUX_ENOEXEC;
  }
  if (h->e_machine != EM_X86_64) {
    return -LINUX_ENOEXEC;
  }

  Elf64_Phdr *p = (Elf64_Phdr *)(data + h->e_phoff);

  for (int i = 0; i < h->e_phnum; i++) {
    if (p[i].p_type != PT_LOAD) {
      continue;
    }

    ulong p_vaddr = p[i].p_vaddr + load_addr;

    ulong mask = PAGE_SIZE(PAGE_4KB) - 1;
    ulong vaddr = p_vaddr & ~mask;
    ulong offset = p_vaddr & mask;
    ulong size = roundup(p[i].p_memsz + offset, PAGE_SIZE(PAGE_4KB));

    int prot = 0;
    if (p[i].p_flags & PF_X) prot |= LINUX_PROT_EXEC;
    if (p[i].p_flags & PF_W) prot |= LINUX_PROT_WRITE;
    if (p[i].p_flags & PF_R) prot |= LINUX_PROT_READ;

    do_mmap(vaddr, size, PROT_READ | PROT_WRITE, prot, LINUX_MAP_PRIVATE | LINUX_MAP_FIXED | LINUX_MAP_ANONYMOUS, -1, 0);

    memcpy(guest_to_host(vaddr) + offset, data + p[i].p_offset, p[i].p_filesz);

    map_top = MAX(map_top, roundup(vaddr + size, PAGE_SIZE(PAGE_4KB)));
  }

  vmm_write_vmcs(VMCS_GUEST_RIP, load_addr + h->e_entry);
  brk_min = map_top;

  munmap(data, st.st_size);

  return 0;
}

int
load_elf(Elf64_Ehdr *ehdr, int argc, char *argv[], char **envp)
{
  uint64_t map_top = 0;

  assert(IS_ELF(*ehdr));

  if (ehdr->e_type != ET_EXEC) {
    fprintf(stderr, "not an executable file");
    return -LINUX_ENOEXEC;
  }
  if (ehdr->e_machine != EM_X86_64) {
    fprintf(stderr, "not an x64 executable");
    return -LINUX_ENOEXEC;
  }

  Elf64_Phdr *p = (Elf64_Phdr *)((char *)ehdr + ehdr->e_phoff);

  uint64_t load_base = 0;
  bool load_base_set = false;

  for (int i = 0; i < ehdr->e_phnum; i++) {
    if (p[i].p_type != PT_LOAD) {
      continue;
    }

    ulong mask = PAGE_SIZE(PAGE_4KB) - 1;
    ulong vaddr = p[i].p_vaddr & ~mask;
    ulong offset = p[i].p_vaddr & mask;
    ulong size = roundup(p[i].p_memsz + offset, PAGE_SIZE(PAGE_4KB));

    int prot = 0;
    if (p[i].p_flags & PF_X) prot |= LINUX_PROT_EXEC;
    if (p[i].p_flags & PF_W) prot |= LINUX_PROT_WRITE;
    if (p[i].p_flags & PF_R) prot |= LINUX_PROT_READ;

    do_mmap(vaddr, size, PROT_READ | PROT_WRITE, prot, LINUX_MAP_PRIVATE | LINUX_MAP_FIXED | LINUX_MAP_ANONYMOUS, -1, 0);

    memcpy(guest_to_host(vaddr) + offset, (char *)ehdr + p[i].p_offset, p[i].p_filesz);

    if (! load_base_set) {
      load_base = p[i].p_vaddr - p[i].p_offset;
      load_base_set = true;
    }
    map_top = MAX(map_top, roundup(vaddr + size, PAGE_SIZE(PAGE_4KB)));
  }

  assert(load_base_set);

  int i;
  bool interp = false;
  for (i = 0; i < ehdr->e_phnum; i++) {
    if (p[i].p_type == PT_INTERP) {
      interp = true;
      break;
    }
  }
  if (interp) {
    char interp_path[p[i].p_filesz + 1];
    memcpy(interp_path, (char *)ehdr + p[i].p_offset, p[i].p_filesz);
    interp_path[p[i].p_filesz] = 0;

    if (load_elf_interp(interp_path, map_top) < 0) {
      return -1;
    }
  }
  else {
    vmm_write_vmcs(VMCS_GUEST_RIP, ehdr->e_entry);
    brk_min = map_top;
  }

  init_userstack(argc, argv, envp, load_base, ehdr, interp ? map_top : 0);

  return 1;
}

#define SB_ARGC_MAX 2

int
load_script(const char *script, size_t len, int argc, char *argv[], char **envp)
{
  const char *script_end = script + len;
  char sb_argv[SB_ARGC_MAX][LINUX_PATH_MAX];
  int sb_argc;
  size_t n;

  script += 2;                  /* skip shebang */

  for (sb_argc = 0; sb_argc < SB_ARGC_MAX; ++sb_argc) {
    while (isspace(*script) && *script != '\n') {
      if (script == script_end)
        goto parse_end;
      script++;
    }

    for (n = 0; ! isspace(script[n]); ++n) {
      if (script + n == script_end)
        goto parse_end;
    }
    if (n == 0) {
      goto parse_end;
    }
    if (n > LINUX_PATH_MAX - 1) {
      return -LINUX_ENAMETOOLONG;
    }
    strncpy(sb_argv[sb_argc], script, n);
    sb_argv[sb_argc][n] = 0;

    script += n;                /* skip interp */
  }

 parse_end:
  if (sb_argc == 0) {
    return -LINUX_EFAULT;
  }

  int newargc = sb_argc + argc;
  char *newargv[newargc];
  for (int i = 0; i < sb_argc; ++i) {
    newargv[i] = sb_argv[i];
  }
  memcpy(newargv + sb_argc, argv, argc * sizeof(char *));

  do_exec(newargv[0], newargc, newargv, envp);

  return 0;
}

uint64_t
push(const void *data, size_t n)
{
  uint64_t size = roundup(n, 8);
  uint64_t rsp;

  vmm_read_register(HV_X86_RSP, &rsp);
  rsp -= size;
  vmm_write_register(HV_X86_RSP, rsp);

  char *stackmem = guest_to_host(rsp);

  if (data != 0) {
    memcpy(stackmem, data, n);
  } else {
    memset(stackmem, 0, n);
  }

  return rsp;
}

void
init_userstack(int argc, char *argv[], char **envp, uint64_t exe_base, const Elf64_Ehdr *ehdr, uint64_t interp_base)
{
  do_mmap(STACK_TOP - STACK_SIZE, STACK_SIZE, PROT_READ | PROT_WRITE, LINUX_PROT_READ | LINUX_PROT_WRITE, LINUX_MAP_PRIVATE | LINUX_MAP_FIXED | LINUX_MAP_ANONYMOUS, -1, 0);

  vmm_write_register(HV_X86_RSP, STACK_TOP);
  vmm_write_register(HV_X86_RBP, STACK_TOP);

  char random[16];

  uint64_t rand_ptr = push(random, sizeof random);

  char **renvp;
  for (renvp = envp; *renvp; ++renvp)
    ;

  uint64_t total = 0, args_total = 0;

  for (int i = 0; i < argc; ++i) {
    total += strlen(argv[i]) + 1;
  }
  args_total = total;
  for (char **e = envp; *e; ++e) {
    total += strlen(*e) + 1;
  }

  char buf[total];

  uint64_t off = 0;

  for (int i = 0; i < argc; ++i) {
    size_t len = strlen(argv[i]);
    memcpy(buf + off, argv[i], len + 1);
    off += len + 1;
  }
  for (char **e = envp; *e; ++e) {
    size_t len = strlen(*e);
    memcpy(buf + off, *e, len + 1);
    off += len + 1;
  }

  uint64_t args_start = push(buf, total);
  uint64_t args_end = args_start + args_total, env_end = args_start + total;

  Elf64_Auxv aux[] = {
    { AT_BASE, interp_base },
    { AT_ENTRY, ehdr->e_entry },
    { AT_PHDR, exe_base + ehdr->e_phoff },
    { AT_PHENT, ehdr->e_phentsize },
    { AT_PHNUM, ehdr->e_phnum },
    { AT_PAGESZ, PAGE_SIZE(PAGE_4KB) },
    { AT_RANDOM, rand_ptr },
    { AT_NULL, 0 },
  };

  push(aux, sizeof aux);

  push(0, sizeof(uint64_t));

  uint64_t ptr = env_end;
  for (char **e = renvp - 1; e >= envp; --e) {
    ptr -= strlen(*e) + 1;
    push(&ptr, sizeof ptr);
    assert(strcmp(buf + (ptr - args_start), *e) == 0);
  }

  push(0, sizeof(uint64_t));

  ptr = args_end;
  for (int i = argc - 1; i >= 0; --i) {
    ptr -= strlen(argv[i]) + 1;
    push(&ptr, sizeof ptr);
    assert(strcmp(buf + (ptr - args_start), argv[i]) == 0);
  }

  uint64_t argc64 = argc;
  push(&argc64, sizeof argc64);
}

void init_brk();
int
do_exec(const char *elf_path, int argc, char *argv[], char **envp)
{
  int err;
  int fd;
  struct stat st;
  char *data;
  
  if ((err = do_access(elf_path, X_OK)) < 0) {
    return err;
  }
  if ((fd = do_open(elf_path, O_RDONLY, 0)) < 0) {
    return fd;
  }
  if (proc.nr_tasks > 1) {
    fprintf(stderr, "Multi-thread execve is not implemented yet\n");
    return -LINUX_EINVAL;
  }

  /* Reinitialize proc and task structures */
  /* Not handling locks seriously now because multi-thread execve is not implemented yet */
  proc.nr_tasks = 1;
  clear_mm(proc.mm, false); // munlock is also done by unmapping mm

  // TODO: handle close-on-exec after introducing vfs

  /* Now do exec */
  fstat(fd, &st);

  data = mmap(0, st.st_size, PROT_READ | PROT_EXEC, MAP_PRIVATE, fd, 0);

  close(fd);

  if (4 <= st.st_size && memcmp(data, ELFMAG, 4) == 0) {
    if (load_elf((Elf64_Ehdr *) data, argc, argv, envp) < 0)
      return -1;
  }
  else if (2 <= st.st_size && data[0] == '#' && data[1] == '!') {
    if (load_script(data, st.st_size, argc, argv, envp) < 0)
      return -1;
  }
  else {
    return -LINUX_ENOEXEC;                  /* unsupported file type */
  }

  munmap(data, st.st_size);
  init_brk();

  return 0;
}

static int count_strings(gaddr_t v, int max)
{
  int ret = 0;
  while (((gaddr_t*)guest_to_host(v))[ret] != 0) {
    ret++;
    if (ret > max) {
      return -LINUX_E2BIG;
    }
  }
  return ret;
}

DEFINE_SYSCALL(execve, gstr_t, gelf_path, gaddr_t, gargv, gaddr_t, genvp)
{
  int err;
  const char *elf_path = guest_to_host(gelf_path);

  if ((err = count_strings(gargv, LINUX_MAX_ARG_STRINGS)) < 0) {
    return err;
  }
  int argc = err;
  if ((err = count_strings(genvp, LINUX_MAX_ARG_STRINGS)) < 0) {
    return err;
  }
  int envc = err;

  char *argv[argc + 1], *envp[envc + 1];

  // Copy args
  char **vecs[] = {argv, envp};
  gaddr_t gvecs[] = {gargv, genvp};
  int maxs[] = {argc, envc};

  for (int i = 0; i < 2; i++) {
    char **vec = vecs[i];
    gaddr_t *gvec = (gaddr_t *) guest_to_host(gvecs[i]);
    int max_c = maxs[i];

    for (int j = 0; j < max_c; j++) {
      int size = strnsize_user(gvec[j], LINUX_MAX_ARG_STRLEN);
      if (size > LINUX_MAX_ARG_STRLEN) {
        return -LINUX_E2BIG;
      }
      vec[j] = alloca(size);
      strncpy_from_user(vec[j], gvec[j], size);
      // The string may be changed after strnsize_user by another thread
      if (vec[j][size - 1] != 0) {
        return -LINUX_E2BIG;
      }
    }

    vec[max_c] = NULL;
  }

  err = do_exec(elf_path, argc, argv, envp);
  if (err < 0) {
    return err;
  }

  // Now executable file was lodaed successfully
  uint64_t entry;
  vmm_read_register(HV_X86_RIP, &entry);
  vmm_write_register(HV_X86_RIP, entry - 2); // because syscall handler adds 2 to current rip when return to vmm_run

  return 0;
}
