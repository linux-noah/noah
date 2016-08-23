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
#include "x86/page.h"
#include "x86/vmemparam.h"
#include "elf.h"

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
    fprintf(stderr, "could not open file: %s\n", path);
    return -1;
  }

  fstat(fd, &st);

  data = mmap(0, st.st_size, PROT_READ | PROT_EXEC, MAP_PRIVATE, fd, 0);

  close(fd);

  h = (Elf64_Ehdr *)data;

  assert(IS_ELF(*h));

  if (! (h->e_type == ET_EXEC || h->e_type == ET_DYN))
    return -1;
  if (h->e_machine != EM_X86_64)
    return -1;

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
    if (p[i].p_flags & PF_X) prot |= L_PROT_EXEC;
    if (p[i].p_flags & PF_W) prot |= L_PROT_WRITE;
    if (p[i].p_flags & PF_R) prot |= L_PROT_READ;

    do_mmap(vaddr, size, prot, L_MAP_PRIVATE | L_MAP_FIXED | L_MAP_ANONYMOUS, -1, 0);

    memcpy(guest_to_host(vaddr) + offset, data + p[i].p_offset, p[i].p_filesz);

    map_top = MAX(map_top, roundup(vaddr + size, PAGE_SIZE(PAGE_4KB)));
  }

  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_RIP, load_addr + h->e_entry);
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
    return -1;
  }
  if (ehdr->e_machine != EM_X86_64) {
    fprintf(stderr, "not an x64 executable");
    return -1;
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
    if (p[i].p_flags & PF_X) prot |= L_PROT_EXEC;
    if (p[i].p_flags & PF_W) prot |= L_PROT_WRITE;
    if (p[i].p_flags & PF_R) prot |= L_PROT_READ;

    do_mmap(vaddr, size, prot, L_MAP_PRIVATE | L_MAP_FIXED | L_MAP_ANONYMOUS, -1, 0);

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
    hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_RIP, ehdr->e_entry);
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
  char sb_argv[SB_ARGC_MAX][L_PATH_MAX];
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
    if (n > L_PATH_MAX - 1) {
      return -1;
    }
    strncpy(sb_argv[sb_argc], script, n);
    sb_argv[sb_argc][n] = 0;

    script += n;                /* skip interp */
  }

 parse_end:
  if (sb_argc == 0) {
    return -1;
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

  hv_vcpu_read_register(vcpuid, HV_X86_RSP, &rsp);
  rsp -= size;
  hv_vcpu_write_register(vcpuid, HV_X86_RSP, rsp);

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
  do_mmap(STACK_TOP - STACK_SIZE, STACK_SIZE, L_PROT_READ | L_PROT_WRITE, L_MAP_PRIVATE | L_MAP_FIXED | L_MAP_ANONYMOUS, -1, 0);

  hv_vcpu_write_register(vcpuid, HV_X86_RSP, STACK_TOP);
  hv_vcpu_write_register(vcpuid, HV_X86_RBP, STACK_TOP);

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

int
do_exec(const char *elf_path, int argc, char *argv[], char **envp)
{
  int fd;
  struct stat st;
  char *data;

  if ((fd = do_open(elf_path, O_RDONLY, 0)) < 0) {
    fprintf(stderr, "do_exec: could not open file: %s\n", elf_path);
    return -1;
  }

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
    return -1;                  /* unsupported file type */
  }

  munmap(data, st.st_size);

  return 0;
}

#include <mach-o/dyld.h>

DEFINE_SYSCALL(execve, gaddr_t, gelf_path, gaddr_t, gargv, gaddr_t, genvp)
{
  int argc = 0, envc = 0;
  while (((gaddr_t*)guest_to_host(gargv))[argc] != 0) argc++;
  while (((gaddr_t*)guest_to_host(genvp))[envc] != 0) envc++;

  /* get this executable's path */
  uint32_t bufsize;
  _NSGetExecutablePath(NULL, &bufsize);
  char noah_path[bufsize];
  if (_NSGetExecutablePath(noah_path, &bufsize)) {
    return -1;
  }

  const char *elf_path = guest_to_host(gelf_path);;

  char *argv[argc + 2];
  argv[0] = noah_path;
  for (int i = 0; i < argc; i++) {
    argv[i + 1] = (char*)guest_to_host(((gaddr_t*)guest_to_host(gargv))[i]);
  }
  argv[argc + 1] = NULL;

  char *envp[envc + 1];
  for (int i = 0; i < envc; i++) {
    envp[i] = (char*)guest_to_host(((gaddr_t*)guest_to_host(genvp))[i]);
  }
  envp[envc] = NULL;

  vmm_destroy();

  return execve(noah_path, argv, envp);
}
