#include <stdlib.h>
#include <stdio.h>
#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>
#include <stdarg.h>
#include <time.h>

#include "noah.h"

static FILE *printk_sink;

void
init_debug(const char *fn)
{
  if (! fn) {
    fn = "/dev/null";
  }
  printk_sink = fopen(fn, "a");

  char buf[1000];
  time_t now = time(0);
  struct tm tm = *gmtime(&now);
  strftime(buf, sizeof buf, "%a, %d %b %Y %H:%M:%S %Z", &tm);
  printk("\n//==================\n");
  printk("noah started: [%s]\n", buf);
}

void
printk(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  vfprintf(printk_sink, fmt, ap);
  va_end(ap);
}

char *vmcs_field_to_str(uint32_t vmcs_field) {
  switch(vmcs_field) {
    case VMCS_VPID:
      return "VMCS_VPID";
    case VMCS_CTRL_POSTED_INT_N_VECTOR:
      return "VMCS_CTRL_POSTED_INT_N_VECTOR";
    case VMCS_CTRL_EPTP_INDEX:
      return "VMCS_CTRL_EPTP_INDEX";
    case VMCS_GUEST_ES:
      return "VMCS_GUEST_ES";
    case VMCS_GUEST_CS:
      return "VMCS_GUEST_CS";
    case VMCS_GUEST_SS:
      return "VMCS_GUEST_SS";
    case VMCS_GUEST_DS:
      return "VMCS_GUEST_DS";
    case VMCS_GUEST_FS:
      return "VMCS_GUEST_FS";
    case VMCS_GUEST_GS:
      return "VMCS_GUEST_GS";
    case VMCS_GUEST_LDTR:
      return "VMCS_GUEST_LDTR";
    case VMCS_GUEST_TR:
      return "VMCS_GUEST_TR";
    case VMCS_GUEST_INT_STATUS:
      return "VMCS_GUEST_INT_STATUS";
    case VMCS_HOST_ES:
      return "VMCS_HOST_ES";
    case VMCS_HOST_CS:
      return "VMCS_HOST_CS";
    case VMCS_HOST_SS:
      return "VMCS_HOST_SS";
    case VMCS_HOST_DS:
      return "VMCS_HOST_DS";
    case VMCS_HOST_FS:
      return "VMCS_HOST_FS";
    case VMCS_HOST_GS:
      return "VMCS_HOST_GS";
    case VMCS_HOST_TR:
      return "VMCS_HOST_TR";
    case VMCS_CTRL_IO_BITMAP_A:
      return "VMCS_CTRL_IO_BITMAP_A";
    case VMCS_CTRL_IO_BITMAP_B:
      return "VMCS_CTRL_IO_BITMAP_B";
    case VMCS_CTRL_MSR_BITMAPS:
      return "VMCS_CTRL_MSR_BITMAPS";
    case VMCS_CTRL_VMEXIT_MSR_STORE_ADDR:
      return "VMCS_CTRL_VMEXIT_MSR_STORE_ADDR";
    case VMCS_CTRL_VMEXIT_MSR_LOAD_ADDR:
      return "VMCS_CTRL_VMEXIT_MSR_LOAD_ADDR";
    case VMCS_CTRL_VMENTRY_MSR_LOAD_ADDR:
      return "VMCS_CTRL_VMENTRY_MSR_LOAD_ADDR";
    case VMCS_CTRL_EXECUTIVE_VMCS_PTR:
      return "VMCS_CTRL_EXECUTIVE_VMCS_PTR";
    case VMCS_CTRL_TSC_OFFSET:
      return "VMCS_CTRL_TSC_OFFSET";
    case VMCS_CTRL_VIRTUAL_APIC:
      return "VMCS_CTRL_VIRTUAL_APIC";
    case VMCS_CTRL_APIC_ACCESS:
      return "VMCS_CTRL_APIC_ACCESS";
    case VMCS_CTRL_POSTED_INT_DESC_ADDR:
      return "VMCS_CTRL_POSTED_INT_DESC_ADDR";
    case VMCS_CTRL_VMFUNC_CTRL:
      return "VMCS_CTRL_VMFUNC_CTRL";
    case VMCS_CTRL_EPTP:
      return "VMCS_CTRL_EPTP";
    case VMCS_CTRL_EOI_EXIT_BITMAP_0:
      return "VMCS_CTRL_EOI_EXIT_BITMAP_0";
    case VMCS_CTRL_EOI_EXIT_BITMAP_1:
      return "VMCS_CTRL_EOI_EXIT_BITMAP_1";
    case VMCS_CTRL_EOI_EXIT_BITMAP_2:
      return "VMCS_CTRL_EOI_EXIT_BITMAP_2";
    case VMCS_CTRL_EOI_EXIT_BITMAP_3:
      return "VMCS_CTRL_EOI_EXIT_BITMAP_3";
    case VMCS_CTRL_EPTP_LIST_ADDR:
      return "VMCS_CTRL_EPTP_LIST_ADDR";
    case VMCS_CTRL_VMREAD_BITMAP_ADDR:
      return "VMCS_CTRL_VMREAD_BITMAP_ADDR";
    case VMCS_CTRL_VMWRITE_BITMAP_ADDR:
      return "VMCS_CTRL_VMWRITE_BITMAP_ADDR";
    case VMCS_CTRL_VIRT_EXC_INFO_ADDR:
      return "VMCS_CTRL_VIRT_EXC_INFO_ADDR";
    case VMCS_CTRL_XSS_EXITING_BITMAP:
      return "VMCS_CTRL_XSS_EXITING_BITMAP";
    case VMCS_GUEST_PHYSICAL_ADDRESS:
      return "VMCS_GUEST_PHYSICAL_ADDRESS";
    case VMCS_GUEST_LINK_POINTER:
      return "VMCS_GUEST_LINK_POINTER";
    case VMCS_GUEST_IA32_DEBUGCTL:
      return "VMCS_GUEST_IA32_DEBUGCTL";
    case VMCS_GUEST_IA32_PAT:
      return "VMCS_GUEST_IA32_PAT";
    case VMCS_GUEST_IA32_EFER:
      return "VMCS_GUEST_IA32_EFER";
    case VMCS_GUEST_IA32_PERF_GLOBAL_CTRL:
      return "VMCS_GUEST_IA32_PERF_GLOBAL_CTRL";
    case VMCS_GUEST_PDPTE0:
      return "VMCS_GUEST_PDPTE0";
    case VMCS_GUEST_PDPTE1:
      return "VMCS_GUEST_PDPTE1";
    case VMCS_GUEST_PDPTE2:
      return "VMCS_GUEST_PDPTE2";
    case VMCS_GUEST_PDPTE3:
      return "VMCS_GUEST_PDPTE3";
    case VMCS_HOST_IA32_PAT:
      return "VMCS_HOST_IA32_PAT";
    case VMCS_HOST_IA32_EFER:
      return "VMCS_HOST_IA32_EFER";
    case VMCS_HOST_IA32_PERF_GLOBAL_CTRL:
      return "VMCS_HOST_IA32_PERF_GLOBAL_CTRL";
    case VMCS_CTRL_PIN_BASED:
      return "VMCS_CTRL_PIN_BASED";
    case VMCS_CTRL_CPU_BASED:
      return "VMCS_CTRL_CPU_BASED";
    case VMCS_CTRL_EXC_BITMAP:
      return "VMCS_CTRL_EXC_BITMAP";
    case VMCS_CTRL_PF_ERROR_MASK:
      return "VMCS_CTRL_PF_ERROR_MASK";
    case VMCS_CTRL_PF_ERROR_MATCH:
      return "VMCS_CTRL_PF_ERROR_MATCH";
    case VMCS_CTRL_CR3_COUNT:
      return "VMCS_CTRL_CR3_COUNT";
    case VMCS_CTRL_VMEXIT_CONTROLS:
      return "VMCS_CTRL_VMEXIT_CONTROLS";
    case VMCS_CTRL_VMEXIT_MSR_STORE_COUNT:
      return "VMCS_CTRL_VMEXIT_MSR_STORE_COUNT";
    case VMCS_CTRL_VMEXIT_MSR_LOAD_COUNT:
      return "VMCS_CTRL_VMEXIT_MSR_LOAD_COUNT";
    case VMCS_CTRL_VMENTRY_CONTROLS:
      return "VMCS_CTRL_VMENTRY_CONTROLS";
    case VMCS_CTRL_VMENTRY_MSR_LOAD_COUNT:
      return "VMCS_CTRL_VMENTRY_MSR_LOAD_COUNT";
    case VMCS_CTRL_VMENTRY_IRQ_INFO:
      return "VMCS_CTRL_VMENTRY_IRQ_INFO";
    case VMCS_CTRL_VMENTRY_EXC_ERROR:
      return "VMCS_CTRL_VMENTRY_EXC_ERROR";
    case VMCS_CTRL_VMENTRY_INSTR_LEN:
      return "VMCS_CTRL_VMENTRY_INSTR_LEN";
    case VMCS_CTRL_TPR_THRESHOLD:
      return "VMCS_CTRL_TPR_THRESHOLD";
    case VMCS_CTRL_CPU_BASED2:
      return "VMCS_CTRL_CPU_BASED2";
    case VMCS_CTRL_PLE_GAP:
      return "VMCS_CTRL_PLE_GAP";
    case VMCS_CTRL_PLE_WINDOW:
      return "VMCS_CTRL_PLE_WINDOW";
    case VMCS_RO_INSTR_ERROR:
      return "VMCS_RO_INSTR_ERROR";
    case VMCS_RO_EXIT_REASON:
      return "VMCS_RO_EXIT_REASON";
    case VMCS_RO_VMEXIT_IRQ_INFO:
      return "VMCS_RO_VMEXIT_IRQ_INFO";
    case VMCS_RO_VMEXIT_IRQ_ERROR:
      return "VMCS_RO_VMEXIT_IRQ_ERROR";
    case VMCS_RO_IDT_VECTOR_INFO:
      return "VMCS_RO_IDT_VECTOR_INFO";
    case VMCS_RO_IDT_VECTOR_ERROR:
      return "VMCS_RO_IDT_VECTOR_ERROR";
    case VMCS_RO_VMEXIT_INSTR_LEN:
      return "VMCS_RO_VMEXIT_INSTR_LEN";
    case VMCS_RO_VMX_INSTR_INFO:
      return "VMCS_RO_VMX_INSTR_INFO";
    case VMCS_GUEST_ES_LIMIT:
      return "VMCS_GUEST_ES_LIMIT";
    case VMCS_GUEST_CS_LIMIT:
      return "VMCS_GUEST_CS_LIMIT";
    case VMCS_GUEST_SS_LIMIT:
      return "VMCS_GUEST_SS_LIMIT";
    case VMCS_GUEST_DS_LIMIT:
      return "VMCS_GUEST_DS_LIMIT";
    case VMCS_GUEST_FS_LIMIT:
      return "VMCS_GUEST_FS_LIMIT";
    case VMCS_GUEST_GS_LIMIT:
      return "VMCS_GUEST_GS_LIMIT";
    case VMCS_GUEST_LDTR_LIMIT:
      return "VMCS_GUEST_LDTR_LIMIT";
    case VMCS_GUEST_TR_LIMIT:
      return "VMCS_GUEST_TR_LIMIT";
    case VMCS_GUEST_GDTR_LIMIT:
      return "VMCS_GUEST_GDTR_LIMIT";
    case VMCS_GUEST_IDTR_LIMIT:
      return "VMCS_GUEST_IDTR_LIMIT";
    case VMCS_GUEST_ES_AR:
      return "VMCS_GUEST_ES_AR";
    case VMCS_GUEST_CS_AR:
      return "VMCS_GUEST_CS_AR";
    case VMCS_GUEST_SS_AR:
      return "VMCS_GUEST_SS_AR";
    case VMCS_GUEST_DS_AR:
      return "VMCS_GUEST_DS_AR";
    case VMCS_GUEST_FS_AR:
      return "VMCS_GUEST_FS_AR";
    case VMCS_GUEST_GS_AR:
      return "VMCS_GUEST_GS_AR";
    case VMCS_GUEST_LDTR_AR:
      return "VMCS_GUEST_LDTR_AR";
    case VMCS_GUEST_TR_AR:
      return "VMCS_GUEST_TR_AR";
    case VMCS_GUEST_IGNORE_IRQ:
      return "VMCS_GUEST_IGNORE_IRQ";
    case VMCS_GUEST_ACTIVITY_STATE:
      return "VMCS_GUEST_ACTIVITY_STATE";
    case VMCS_GUEST_SMBASE:
      return "VMCS_GUEST_SMBASE";
    case VMCS_GUEST_IA32_SYSENTER_CS:
      return "VMCS_GUEST_IA32_SYSENTER_CS";
    case VMCS_GUEST_VMX_TIMER_VALUE:
      return "VMCS_GUEST_VMX_TIMER_VALUE";
    case VMCS_HOST_IA32_SYSENTER_CS:
      return "VMCS_HOST_IA32_SYSENTER_CS";
    case VMCS_CTRL_CR0_MASK:
      return "VMCS_CTRL_CR0_MASK";
    case VMCS_CTRL_CR4_MASK:
      return "VMCS_CTRL_CR4_MASK";
    case VMCS_CTRL_CR0_SHADOW:
      return "VMCS_CTRL_CR0_SHADOW";
    case VMCS_CTRL_CR4_SHADOW:
      return "VMCS_CTRL_CR4_SHADOW";
    case VMCS_CTRL_CR3_VALUE0:
      return "VMCS_CTRL_CR3_VALUE0";
    case VMCS_CTRL_CR3_VALUE1:
      return "VMCS_CTRL_CR3_VALUE1";
    case VMCS_CTRL_CR3_VALUE2:
      return "VMCS_CTRL_CR3_VALUE2";
    case VMCS_CTRL_CR3_VALUE3:
      return "VMCS_CTRL_CR3_VALUE3";
    case VMCS_RO_EXIT_QUALIFIC:
      return "VMCS_RO_EXIT_QUALIFIC";
    case VMCS_RO_IO_RCX:
      return "VMCS_RO_IO_RCX";
    case VMCS_RO_IO_RSI:
      return "VMCS_RO_IO_RSI";
    case VMCS_RO_IO_RDI:
      return "VMCS_RO_IO_RDI";
    case VMCS_RO_IO_RIP:
      return "VMCS_RO_IO_RIP";
    case VMCS_RO_GUEST_LIN_ADDR:
      return "VMCS_RO_GUEST_LIN_ADDR";
    case VMCS_GUEST_CR0:
      return "VMCS_GUEST_CR0";
    case VMCS_GUEST_CR3:
      return "VMCS_GUEST_CR3";
    case VMCS_GUEST_CR4:
      return "VMCS_GUEST_CR4";
    case VMCS_GUEST_ES_BASE:
      return "VMCS_GUEST_ES_BASE";
    case VMCS_GUEST_CS_BASE:
      return "VMCS_GUEST_CS_BASE";
    case VMCS_GUEST_SS_BASE:
      return "VMCS_GUEST_SS_BASE";
    case VMCS_GUEST_DS_BASE:
      return "VMCS_GUEST_DS_BASE";
    case VMCS_GUEST_FS_BASE:
      return "VMCS_GUEST_FS_BASE";
    case VMCS_GUEST_GS_BASE:
      return "VMCS_GUEST_GS_BASE";
    case VMCS_GUEST_LDTR_BASE:
      return "VMCS_GUEST_LDTR_BASE";
    case VMCS_GUEST_TR_BASE:
      return "VMCS_GUEST_TR_BASE";
    case VMCS_GUEST_GDTR_BASE:
      return "VMCS_GUEST_GDTR_BASE";
    case VMCS_GUEST_IDTR_BASE:
      return "VMCS_GUEST_IDTR_BASE";
    case VMCS_GUEST_DR7:
      return "VMCS_GUEST_DR7";
    case VMCS_GUEST_RSP:
      return "VMCS_GUEST_RSP";
    case VMCS_GUEST_RIP:
      return "VMCS_GUEST_RIP";
    case VMCS_GUEST_RFLAGS:
      return "VMCS_GUEST_RFLAGS";
    case VMCS_GUEST_DEBUG_EXC:
      return "VMCS_GUEST_DEBUG_EXC";
    case VMCS_GUEST_SYSENTER_ESP:
      return "VMCS_GUEST_SYSENTER_ESP";
    case VMCS_GUEST_SYSENTER_EIP:
      return "VMCS_GUEST_SYSENTER_EIP";
    case VMCS_HOST_CR0:
      return "VMCS_HOST_CR0";
    case VMCS_HOST_CR3:
      return "VMCS_HOST_CR3";
    case VMCS_HOST_CR4:
      return "VMCS_HOST_CR4";
    case VMCS_HOST_FS_BASE:
      return "VMCS_HOST_FS_BASE";
    case VMCS_HOST_GS_BASE:
      return "VMCS_HOST_GS_BASE";
    case VMCS_HOST_TR_BASE:
      return "VMCS_HOST_TR_BASE";
    case VMCS_HOST_GDTR_BASE:
      return "VMCS_HOST_GDTR_BASE";
    case VMCS_HOST_IDTR_BASE:
      return "VMCS_HOST_IDTR_BASE";
    case VMCS_HOST_IA32_SYSENTER_ESP:
      return "VMCS_HOST_IA32_SYSENTER_ESP";
    case VMCS_HOST_IA32_SYSENTER_EIP:
      return "VMCS_HOST_IA32_SYSENTER_EIP";
    case VMCS_HOST_RSP:
      return "VMCS_HOST_RSP";
    case VMCS_HOST_RIP:
      return "VMCS_HOST_RIP";
    case VMCS_MAX:
      return "VMCS_MAX";
    default:
      return "UNKNOWN VMCS Field";
  }
}

void fprint_vmcs(FILE *out, hv_vcpuid_t vcpuid, uint32_t vmcs_field)
{
  uint64_t vmcs;

  if (hv_vmx_vcpu_read_vmcs(vcpuid, vmcs_field, &vmcs) != HV_SUCCESS) {
    fprintf(stderr, "read_vmcs failed, field: %s\n", vmcs_field_to_str(vmcs_field));
    return;
  }
  fprintf(out, "%s: 0x%016llx\n", vmcs_field_to_str(vmcs_field), vmcs);
}

void fhvdump(FILE *out, hv_vcpuid_t vcpuid)
{
  fprint_vmcs(out, vcpuid, VMCS_VPID);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_POSTED_INT_N_VECTOR);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_EPTP_INDEX);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_ES);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_CS);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_SS);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_DS);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_FS);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_GS);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_LDTR);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_TR);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_INT_STATUS);
  fprint_vmcs(out, vcpuid, VMCS_HOST_ES);
  fprint_vmcs(out, vcpuid, VMCS_HOST_CS);
  fprint_vmcs(out, vcpuid, VMCS_HOST_SS);
  fprint_vmcs(out, vcpuid, VMCS_HOST_DS);
  fprint_vmcs(out, vcpuid, VMCS_HOST_FS);
  fprint_vmcs(out, vcpuid, VMCS_HOST_GS);
  fprint_vmcs(out, vcpuid, VMCS_HOST_TR);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_IO_BITMAP_A);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_IO_BITMAP_B);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_MSR_BITMAPS);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMEXIT_MSR_STORE_ADDR);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMEXIT_MSR_LOAD_ADDR);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMENTRY_MSR_LOAD_ADDR);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_EXECUTIVE_VMCS_PTR);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_TSC_OFFSET);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VIRTUAL_APIC);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_APIC_ACCESS);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_POSTED_INT_DESC_ADDR);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMFUNC_CTRL);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_EPTP);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_EOI_EXIT_BITMAP_0);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_EOI_EXIT_BITMAP_1);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_EOI_EXIT_BITMAP_2);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_EOI_EXIT_BITMAP_3);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_EPTP_LIST_ADDR);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMREAD_BITMAP_ADDR);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMWRITE_BITMAP_ADDR);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VIRT_EXC_INFO_ADDR);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_XSS_EXITING_BITMAP);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_PHYSICAL_ADDRESS);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_LINK_POINTER);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_IA32_DEBUGCTL);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_IA32_PAT);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_IA32_EFER);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_IA32_PERF_GLOBAL_CTRL);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_PDPTE0);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_PDPTE1);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_PDPTE2);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_PDPTE3);
  fprint_vmcs(out, vcpuid, VMCS_HOST_IA32_PAT);
  fprint_vmcs(out, vcpuid, VMCS_HOST_IA32_EFER);
  fprint_vmcs(out, vcpuid, VMCS_HOST_IA32_PERF_GLOBAL_CTRL);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_PIN_BASED);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_CPU_BASED);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_EXC_BITMAP);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_PF_ERROR_MASK);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_PF_ERROR_MATCH);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_CR3_COUNT);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMEXIT_CONTROLS);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMEXIT_MSR_STORE_COUNT);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMEXIT_MSR_LOAD_COUNT);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMENTRY_CONTROLS);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMENTRY_MSR_LOAD_COUNT);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMENTRY_IRQ_INFO);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMENTRY_EXC_ERROR);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_VMENTRY_INSTR_LEN);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_TPR_THRESHOLD);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_CPU_BASED2);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_PLE_GAP);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_PLE_WINDOW);
  fprint_vmcs(out, vcpuid, VMCS_RO_INSTR_ERROR);
  fprint_vmcs(out, vcpuid, VMCS_RO_EXIT_REASON);
  fprint_vmcs(out, vcpuid, VMCS_RO_VMEXIT_IRQ_INFO);
  fprint_vmcs(out, vcpuid, VMCS_RO_VMEXIT_IRQ_ERROR);
  fprint_vmcs(out, vcpuid, VMCS_RO_IDT_VECTOR_INFO);
  fprint_vmcs(out, vcpuid, VMCS_RO_IDT_VECTOR_ERROR);
  fprint_vmcs(out, vcpuid, VMCS_RO_VMEXIT_INSTR_LEN);
  fprint_vmcs(out, vcpuid, VMCS_RO_VMX_INSTR_INFO);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_ES_LIMIT);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_CS_LIMIT);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_SS_LIMIT);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_DS_LIMIT);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_FS_LIMIT);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_GS_LIMIT);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_LDTR_LIMIT);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_TR_LIMIT);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_GDTR_LIMIT);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_IDTR_LIMIT);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_ES_AR);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_CS_AR);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_SS_AR);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_DS_AR);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_FS_AR);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_GS_AR);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_LDTR_AR);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_TR_AR);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_IGNORE_IRQ);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_ACTIVITY_STATE);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_SMBASE);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_IA32_SYSENTER_CS);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_VMX_TIMER_VALUE);
  fprint_vmcs(out, vcpuid, VMCS_HOST_IA32_SYSENTER_CS);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_CR0_MASK);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_CR4_MASK);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_CR0_SHADOW);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_CR4_SHADOW);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_CR3_VALUE0);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_CR3_VALUE1);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_CR3_VALUE2);
  fprint_vmcs(out, vcpuid, VMCS_CTRL_CR3_VALUE3);
  fprint_vmcs(out, vcpuid, VMCS_RO_EXIT_QUALIFIC);
  fprint_vmcs(out, vcpuid, VMCS_RO_IO_RCX);
  fprint_vmcs(out, vcpuid, VMCS_RO_IO_RSI);
  fprint_vmcs(out, vcpuid, VMCS_RO_IO_RDI);
  fprint_vmcs(out, vcpuid, VMCS_RO_IO_RIP);
  fprint_vmcs(out, vcpuid, VMCS_RO_GUEST_LIN_ADDR);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_CR0);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_CR3);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_CR4);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_ES_BASE);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_CS_BASE);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_SS_BASE);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_DS_BASE);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_FS_BASE);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_GS_BASE);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_LDTR_BASE);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_TR_BASE);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_GDTR_BASE);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_IDTR_BASE);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_DR7);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_RSP);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_RIP);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_RFLAGS);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_DEBUG_EXC);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_SYSENTER_ESP);
  fprint_vmcs(out, vcpuid, VMCS_GUEST_SYSENTER_EIP);
  fprint_vmcs(out, vcpuid, VMCS_HOST_CR0);
  fprint_vmcs(out, vcpuid, VMCS_HOST_CR3);
  fprint_vmcs(out, vcpuid, VMCS_HOST_CR4);
  fprint_vmcs(out, vcpuid, VMCS_HOST_FS_BASE);
  fprint_vmcs(out, vcpuid, VMCS_HOST_GS_BASE);
  fprint_vmcs(out, vcpuid, VMCS_HOST_TR_BASE);
  fprint_vmcs(out, vcpuid, VMCS_HOST_GDTR_BASE);
  fprint_vmcs(out, vcpuid, VMCS_HOST_IDTR_BASE);
  fprint_vmcs(out, vcpuid, VMCS_HOST_IA32_SYSENTER_ESP);
  fprint_vmcs(out, vcpuid, VMCS_HOST_IA32_SYSENTER_EIP);
  fprint_vmcs(out, vcpuid, VMCS_HOST_RSP);
  fprint_vmcs(out, vcpuid, VMCS_HOST_RIP);
  fprint_vmcs(out, vcpuid, VMCS_MAX);
}

