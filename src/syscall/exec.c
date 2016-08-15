#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "../common.h"
#include "../sandbox.h"
#include "../x86/page.h"
#include "elf.h"

void
load_elf(char *path)
{
  char *data;
  Elf64_Ehdr *h;
  uint64_t map_top = 0;
  int fd;
  struct stat st;

  if ((fd = open(path, O_RDONLY)) < 0) {
    fprintf(stderr, "could not open file: %s\n", path);
    return;
  }

  stat(path, &st);

  data = mmap(0, st.st_size, PROT_READ | PROT_EXEC, MAP_SHARED, fd, 0);

  h = (Elf64_Ehdr *)data;

  assert(IS_ELF(*h));

  if (h->e_type != ET_EXEC) {
    fprintf(stderr, "not an executable file");
    return;
  }
  if (h->e_machine != EM_X86_64) {
    fprintf(stderr, "not an x64 executable");
    return;
  }

  Elf64_Phdr *p = (Elf64_Phdr *)(data + h->e_phoff);

  for (int i = 0; i < h->e_phnum; i++) {
    if (p[i].p_type != PT_LOAD) {
      continue;
    }

    ulong offset = p[i].p_vaddr & (PAGE_SIZE(PAGE_4KB) - 1);
    ulong start = p[i].p_vaddr - offset;
    ulong size = p[i].p_memsz + offset;

    char *segment = kalloc(size);
    memcpy(segment + offset, data + p[i].p_offset, p[i].p_filesz);

    vm_map(start, to_vmpa(segment), size, PAGE_4KB, PTE_W | PTE_P | PTE_U);

    map_top = MAX(map_top, start + size);
  }

  void *heapmem = kalloc(PAGE_SIZE(PAGE_2MB));
  uint64_t heap = roundup(map_top, PAGE_SIZE(PAGE_2MB));
  vm_map(heap, to_vmpa(heapmem), PAGE_SIZE(PAGE_2MB), PAGE_2MB, PTE_W | PTE_P | PTE_U);

  void *stackmem = kalloc(PAGE_SIZE(PAGE_2MB));
  uint64_t stack_top = rounddown(CANONICAL_LOWER_END, PAGE_SIZE(PAGE_2MB));
  vm_map(stack_top - PAGE_SIZE(PAGE_2MB), to_vmpa(stackmem), PAGE_SIZE(PAGE_2MB), PAGE_2MB, PTE_W | PTE_P | PTE_U);
  uint64_t stack_base = stack_top - PAGE_SIZE(PAGE_4KB);
  PRINTF("stack is from %p to %p in host\n", stackmem, stackmem + PAGE_SIZE(PAGE_2MB));

  uint64_t entry = h->e_entry;

  hv_vcpu_write_register(vcpuid, HV_X86_RSP, stack_base);
  hv_vcpu_write_register(vcpuid, HV_X86_RBP, stack_base);
  hv_vmx_vcpu_write_vmcs(vcpuid, VMCS_GUEST_RIP, entry);
}

uint64_t
push(hv_vcpuid_t vcpuid, const void *data, size_t n)
{
  uint64_t size = roundup(n, 8);
  uint64_t rsp;

  hv_vcpu_read_register(vcpuid, HV_X86_RSP, &rsp);
  hv_vcpu_write_register(vcpuid, HV_X86_RSP, rsp - size);

  char *stackmem = copy_from_user((void *)rsp);

  if (data != 0) {
    memcpy(stackmem - size, data, n);
  } else {
    memset(stackmem - size, 0, n);
  }

  PRINTF("guest: 0x%llx\n", rsp - size);
  PRINTF("host:  %p\n", stackmem - size);

  return rsp - size;
}

void
init_userstack(int argc, char *argv[], char **envp)
{
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

  uint64_t args_start = push(vcpuid, buf, total);
  uint64_t args_end = args_start + args_total, env_end = args_start + total;

  /* set margin */
  push(vcpuid, 0, 1024);

  push(vcpuid, 0, sizeof(uint64_t));

  uint64_t ptr = env_end;
  for (char **e = renvp - 1; e >= envp; --e) {
    ptr -= strlen(*e) + 1;
    push(vcpuid, &ptr, sizeof ptr);
    assert(strcmp(buf + (ptr - args_start), *e) == 0);
  }

  push(vcpuid, 0, sizeof(uint64_t));

  ptr = args_end;
  for (int i = argc - 1; i >= 0; --i) {
    ptr -= strlen(argv[i]) + 1;
    push(vcpuid, &ptr, sizeof ptr);
    assert(strcmp(buf + (ptr - args_start), argv[i]) == 0);
  }

  uint64_t argc64 = argc;
  push(vcpuid, &argc64, sizeof argc64);
}

void
do_exec(char *elf_path, int argc, char *argv[], char **envp)
{
  hv_return_t ret;
  uint64_t value;

  create_sandbox();
  load_elf(elf_path);
  init_userstack(argc, argv, envp);

  PUTS("now vm is ready");

  while (true) {
    if ((ret = hv_vcpu_run(vcpuid)) != HV_SUCCESS) {
      PUTS("oops, hv_vcpu_run fails");
      return;
    }

    hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_EXIT_QUALIFIC, &value);
    PRINTF("exit qualification = 0x%llx\n", value);

    hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_PHYSICAL_ADDRESS, &value);
    PRINTF("guest-physical address = 0x%llx\n", value);

    hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_RIP, &value);
    PRINTF("guest-rip = 0x%llx\n", value);

    hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_EXIT_REASON, &value);
    PRINTF("exit reason = 0x%llx\n", value);

    print_regs();

    switch (value) {
      uint64_t rax, rdi, rsi, rdx, r10, r8, r9;

    case VMX_REASON_VMCALL:
      PUTS("reason: vmcall");
      assert(false);
      break;

    case VMX_REASON_EXC_NMI: {
      uint64_t retval;

      PUTS("reason: exc or nmi");
      PUTS("");
      hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_IDT_VECTOR_INFO, &value);
      PRINTF("idt info = %lld\n", value);
      hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_RO_IDT_VECTOR_ERROR, &value);
      PRINTF("idt error = %lld\n", value);
      hv_vmx_vcpu_read_vmcs(vcpuid, VMCS_GUEST_INT_STATUS, &value);
      PRINTF("guest int status = %lld\n", value);
      PUTS("!!MAYBE A SYSENTER!!");

      hv_vcpu_read_register(vcpuid, HV_X86_RAX, &rax);

      if (rax >= NR_SYSCALLS) {
        printf("unknown system call: %llu\n", rax);
        exit(1);
      }

      hv_vcpu_read_register(vcpuid, HV_X86_RDI, &rdi);
      hv_vcpu_read_register(vcpuid, HV_X86_RSI, &rsi);
      hv_vcpu_read_register(vcpuid, HV_X86_RDX, &rdx);
      hv_vcpu_read_register(vcpuid, HV_X86_R10, &r10);
      hv_vcpu_read_register(vcpuid, HV_X86_R8, &r8);
      hv_vcpu_read_register(vcpuid, HV_X86_R9, &r9);

      PRINTF(">>>start syscall handling...: %llu\n", rax);
      retval = sc_handler_table[rax](rdi, rsi, rdx, r10, r8, r9);
      PUTS("<<<done");

      hv_vcpu_write_register(vcpuid, HV_X86_RAX, retval);

      hv_vcpu_read_register(vcpuid, HV_X86_RIP, &value);
      hv_vcpu_write_register(vcpuid, HV_X86_RIP, value + 2);

      break;
    }

    default:
      PRINTF("reason: %lld\n", value);
    }


    PUTS("");
  }

  PUTS("exit...");

  destroy_sandbox();
}
