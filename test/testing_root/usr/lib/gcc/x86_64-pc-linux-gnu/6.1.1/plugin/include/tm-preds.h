/* Generated automatically by the program 'build/genpreds'
   from the machine description file '/build/gcc/src/gcc/gcc/config/i386/i386.md'.  */

#ifndef GCC_TM_PREDS_H
#define GCC_TM_PREDS_H

#ifdef HAVE_MACHINE_MODES
extern int general_operand (rtx, machine_mode);
extern int address_operand (rtx, machine_mode);
extern int register_operand (rtx, machine_mode);
extern int pmode_register_operand (rtx, machine_mode);
extern int scratch_operand (rtx, machine_mode);
extern int immediate_operand (rtx, machine_mode);
extern int const_int_operand (rtx, machine_mode);
extern int const_scalar_int_operand (rtx, machine_mode);
extern int const_double_operand (rtx, machine_mode);
extern int nonimmediate_operand (rtx, machine_mode);
extern int nonmemory_operand (rtx, machine_mode);
extern int push_operand (rtx, machine_mode);
extern int pop_operand (rtx, machine_mode);
extern int memory_operand (rtx, machine_mode);
extern int indirect_operand (rtx, machine_mode);
extern int ordered_comparison_operator (rtx, machine_mode);
extern int comparison_operator (rtx, machine_mode);
extern int any_fp_register_operand (rtx, machine_mode);
extern int fp_register_operand (rtx, machine_mode);
extern int register_and_not_any_fp_reg_operand (rtx, machine_mode);
extern int general_reg_operand (rtx, machine_mode);
extern int nonimmediate_gr_operand (rtx, machine_mode);
extern int register_and_not_fp_reg_operand (rtx, machine_mode);
extern int mmx_reg_operand (rtx, machine_mode);
extern int sse_reg_operand (rtx, machine_mode);
extern int ext_sse_reg_operand (rtx, machine_mode);
extern int mask_reg_operand (rtx, machine_mode);
extern int any_QIreg_operand (rtx, machine_mode);
extern int QIreg_operand (rtx, machine_mode);
extern int ext_QIreg_operand (rtx, machine_mode);
extern int ax_reg_operand (rtx, machine_mode);
extern int flags_reg_operand (rtx, machine_mode);
extern int ext_register_operand (rtx, machine_mode);
extern int nonimmediate_x64nomem_operand (rtx, machine_mode);
extern int general_x64nomem_operand (rtx, machine_mode);
extern int register_mixssei387nonimm_operand (rtx, machine_mode);
extern int register_sse4nonimm_operand (rtx, machine_mode);
extern int symbol_operand (rtx, machine_mode);
extern int x86_64_immediate_operand (rtx, machine_mode);
extern int x86_64_zext_immediate_operand (rtx, machine_mode);
extern int x86_64_immediate_size_operand (rtx, machine_mode);
extern int x86_64_general_operand (rtx, machine_mode);
extern int x86_64_sext_operand (rtx, machine_mode);
extern int sext_operand (rtx, machine_mode);
extern int x86_64_zext_operand (rtx, machine_mode);
extern int x86_64_szext_general_operand (rtx, machine_mode);
extern int x86_64_nonmemory_operand (rtx, machine_mode);
extern int x86_64_szext_nonmemory_operand (rtx, machine_mode);
extern int pic_32bit_operand (rtx, machine_mode);
extern int x86_64_movabs_operand (rtx, machine_mode);
extern int symbolic_operand (rtx, machine_mode);
extern int local_symbolic_operand (rtx, machine_mode);
extern int gotoff_operand (rtx, machine_mode);
extern int tls_symbolic_operand (rtx, machine_mode);
extern int tls_modbase_operand (rtx, machine_mode);
extern int constant_call_address_operand (rtx, machine_mode);
extern int call_register_no_elim_operand (rtx, machine_mode);
extern int register_no_elim_operand (rtx, machine_mode);
extern int index_register_operand (rtx, machine_mode);
extern int general_no_elim_operand (rtx, machine_mode);
extern int nonmemory_no_elim_operand (rtx, machine_mode);
extern int indirect_branch_operand (rtx, machine_mode);
extern int sibcall_memory_operand (rtx, machine_mode);
extern int GOT_memory_operand (rtx, machine_mode);
extern int call_insn_operand (rtx, machine_mode);
extern int sibcall_insn_operand (rtx, machine_mode);
extern int GOT32_symbol_operand (rtx, machine_mode);
extern int const0_operand (rtx, machine_mode);
extern int constm1_operand (rtx, machine_mode);
extern int const1_operand (rtx, machine_mode);
extern int const8_operand (rtx, machine_mode);
extern int const128_operand (rtx, machine_mode);
extern int const_32bit_mask (rtx, machine_mode);
extern int const248_operand (rtx, machine_mode);
extern int const2367_operand (rtx, machine_mode);
extern int const1248_operand (rtx, machine_mode);
extern int const359_operand (rtx, machine_mode);
extern int const_4_or_8_to_11_operand (rtx, machine_mode);
extern int const48_operand (rtx, machine_mode);
extern int const_0_to_1_operand (rtx, machine_mode);
extern int const_0_to_3_operand (rtx, machine_mode);
extern int const_0_to_4_operand (rtx, machine_mode);
extern int const_0_to_5_operand (rtx, machine_mode);
extern int const_0_to_7_operand (rtx, machine_mode);
extern int const_0_to_15_operand (rtx, machine_mode);
extern int const_0_to_31_operand (rtx, machine_mode);
extern int const_0_to_63_operand (rtx, machine_mode);
extern int const_0_to_255_operand (rtx, machine_mode);
extern int const_0_to_255_mul_8_operand (rtx, machine_mode);
extern int const_1_to_31_operand (rtx, machine_mode);
extern int const_1_to_63_operand (rtx, machine_mode);
extern int const_2_to_3_operand (rtx, machine_mode);
extern int const_4_to_5_operand (rtx, machine_mode);
extern int const_4_to_7_operand (rtx, machine_mode);
extern int const_6_to_7_operand (rtx, machine_mode);
extern int const_8_to_9_operand (rtx, machine_mode);
extern int const_8_to_11_operand (rtx, machine_mode);
extern int const_8_to_15_operand (rtx, machine_mode);
extern int const_10_to_11_operand (rtx, machine_mode);
extern int const_12_to_13_operand (rtx, machine_mode);
extern int const_12_to_15_operand (rtx, machine_mode);
extern int const_14_to_15_operand (rtx, machine_mode);
extern int const_16_to_19_operand (rtx, machine_mode);
extern int const_16_to_31_operand (rtx, machine_mode);
extern int const_20_to_23_operand (rtx, machine_mode);
extern int const_24_to_27_operand (rtx, machine_mode);
extern int const_28_to_31_operand (rtx, machine_mode);
extern int incdec_operand (rtx, machine_mode);
extern int reg_or_pm1_operand (rtx, machine_mode);
extern int shiftdi_operand (rtx, machine_mode);
extern int ashldi_input_operand (rtx, machine_mode);
extern int zero_extended_scalar_load_operand (rtx, machine_mode);
extern int vector_all_ones_operand (rtx, machine_mode);
extern int vector_memory_operand (rtx, machine_mode);
extern int vector_operand (rtx, machine_mode);
extern int vector_move_operand (rtx, machine_mode);
extern int nonimmediate_or_const_vector_operand (rtx, machine_mode);
extern int nonimmediate_or_sse_const_operand (rtx, machine_mode);
extern int reg_or_0_operand (rtx, machine_mode);
extern int SImode_address_operand (rtx, machine_mode);
extern int address_no_seg_operand (rtx, machine_mode);
extern int vsib_address_operand (rtx, machine_mode);
extern int address_mpx_no_base_operand (rtx, machine_mode);
extern int address_mpx_no_index_operand (rtx, machine_mode);
extern int vsib_mem_operator (rtx, machine_mode);
extern int bnd_mem_operator (rtx, machine_mode);
extern int aligned_operand (rtx, machine_mode);
extern int memory_displacement_operand (rtx, machine_mode);
extern int memory_displacement_only_operand (rtx, machine_mode);
extern int long_memory_operand (rtx, machine_mode);
extern int fcmov_comparison_operator (rtx, machine_mode);
extern int sse_comparison_operator (rtx, machine_mode);
extern int ix86_comparison_int_operator (rtx, machine_mode);
extern int ix86_comparison_uns_operator (rtx, machine_mode);
extern int bt_comparison_operator (rtx, machine_mode);
extern int ix86_comparison_operator (rtx, machine_mode);
extern int ix86_carry_flag_operator (rtx, machine_mode);
extern int ix86_trivial_fp_comparison_operator (rtx, machine_mode);
extern int ix86_fp_comparison_operator (rtx, machine_mode);
extern int ix86_swapped_fp_comparison_operator (rtx, machine_mode);
extern int cmp_fp_expander_operand (rtx, machine_mode);
extern int binary_fp_operator (rtx, machine_mode);
extern int mult_operator (rtx, machine_mode);
extern int div_operator (rtx, machine_mode);
extern int plusminuslogic_operator (rtx, machine_mode);
extern int float_operator (rtx, machine_mode);
extern int arith_or_logical_operator (rtx, machine_mode);
extern int commutative_operator (rtx, machine_mode);
extern int promotable_binary_operator (rtx, machine_mode);
extern int compare_operator (rtx, machine_mode);
extern int absneg_operator (rtx, machine_mode);
extern int misaligned_operand (rtx, machine_mode);
extern int emms_operation (rtx, machine_mode);
extern int vzeroall_operation (rtx, machine_mode);
extern int vzeroupper_operation (rtx, machine_mode);
extern int addsub_vm_operator (rtx, machine_mode);
extern int addsub_vs_operator (rtx, machine_mode);
extern int addsub_vs_parallel (rtx, machine_mode);
extern int avx_vbroadcast_operand (rtx, machine_mode);
extern int palignr_operand (rtx, machine_mode);
extern int avx2_pblendw_operand (rtx, machine_mode);
extern int general_vector_operand (rtx, machine_mode);
extern int register_or_constm1_operand (rtx, machine_mode);
#endif /* HAVE_MACHINE_MODES */

#define CONSTRAINT_NUM_DEFINED_P 1
enum constraint_num
{
  CONSTRAINT__UNKNOWN = 0,
  CONSTRAINT_r,
  CONSTRAINT_R,
  CONSTRAINT_q,
  CONSTRAINT_Q,
  CONSTRAINT_l,
  CONSTRAINT_a,
  CONSTRAINT_b,
  CONSTRAINT_c,
  CONSTRAINT_d,
  CONSTRAINT_S,
  CONSTRAINT_D,
  CONSTRAINT_A,
  CONSTRAINT_U,
  CONSTRAINT_f,
  CONSTRAINT_t,
  CONSTRAINT_u,
  CONSTRAINT_Yk,
  CONSTRAINT_k,
  CONSTRAINT_y,
  CONSTRAINT_x,
  CONSTRAINT_v,
  CONSTRAINT_w,
  CONSTRAINT_Yz,
  CONSTRAINT_Yi,
  CONSTRAINT_Yj,
  CONSTRAINT_Ym,
  CONSTRAINT_Yn,
  CONSTRAINT_Yp,
  CONSTRAINT_Ya,
  CONSTRAINT_Yf,
  CONSTRAINT_Yr,
  CONSTRAINT_I,
  CONSTRAINT_J,
  CONSTRAINT_K,
  CONSTRAINT_L,
  CONSTRAINT_M,
  CONSTRAINT_N,
  CONSTRAINT_O,
  CONSTRAINT_m,
  CONSTRAINT_o,
  CONSTRAINT_Bm,
  CONSTRAINT_p,
  CONSTRAINT_Tv,
  CONSTRAINT_Ts,
  CONSTRAINT_Ti,
  CONSTRAINT_Tb,
  CONSTRAINT_Bz,
  CONSTRAINT_G,
  CONSTRAINT_e,
  CONSTRAINT_We,
  CONSTRAINT_Wz,
  CONSTRAINT_Z,
  CONSTRAINT_Bf,
  CONSTRAINT_V,
  CONSTRAINT__l,
  CONSTRAINT__g,
  CONSTRAINT_i,
  CONSTRAINT_s,
  CONSTRAINT_n,
  CONSTRAINT_E,
  CONSTRAINT_F,
  CONSTRAINT_X,
  CONSTRAINT_Bg,
  CONSTRAINT_Bs,
  CONSTRAINT_Bw,
  CONSTRAINT_BC,
  CONSTRAINT_C,
  CONSTRAINT__LIMIT
};

extern enum constraint_num lookup_constraint_1 (const char *);
extern const unsigned char lookup_constraint_array[];

/* Return the constraint at the beginning of P, or CONSTRAINT__UNKNOWN if it
   isn't recognized.  */

static inline enum constraint_num
lookup_constraint (const char *p)
{
  unsigned int index = lookup_constraint_array[(unsigned char) *p];
  return (index == UCHAR_MAX
          ? lookup_constraint_1 (p)
          : (enum constraint_num) index);
}

extern bool (*constraint_satisfied_p_array[]) (rtx);

/* Return true if X satisfies constraint C.  */

static inline bool
constraint_satisfied_p (rtx x, enum constraint_num c)
{
  int i = (int) c - (int) CONSTRAINT_I;
  return i >= 0 && constraint_satisfied_p_array[i] (x);
}

static inline bool
insn_extra_register_constraint (enum constraint_num c)
{
  return c >= CONSTRAINT_r && c <= CONSTRAINT_Yr;
}

static inline bool
insn_extra_memory_constraint (enum constraint_num c)
{
  return c >= CONSTRAINT_m && c <= CONSTRAINT_o;
}

static inline bool
insn_extra_special_memory_constraint (enum constraint_num c)
{
  return c >= CONSTRAINT_Bm && c <= CONSTRAINT_Bm;
}

static inline bool
insn_extra_address_constraint (enum constraint_num c)
{
  return c >= CONSTRAINT_p && c <= CONSTRAINT_Tb;
}

static inline void
insn_extra_constraint_allows_reg_mem (enum constraint_num c,
				      bool *allows_reg, bool *allows_mem)
{
  if (c >= CONSTRAINT_Bz && c <= CONSTRAINT_Z)
    return;
  if (c >= CONSTRAINT_Bf && c <= CONSTRAINT_Bf)
    {
      *allows_reg = true;
      return;
    }
  if (c >= CONSTRAINT_V && c <= CONSTRAINT__g)
    {
      *allows_mem = true;
      return;
    }
  (void) c;
  *allows_reg = true;
  *allows_mem = true;
}

static inline size_t
insn_constraint_len (char fc, const char *str ATTRIBUTE_UNUSED)
{
  switch (fc)
    {
    case 'B': return 2;
    case 'T': return 2;
    case 'W': return 2;
    case 'Y': return 2;
    default: break;
    }
  return 1;
}

#define CONSTRAINT_LEN(c_,s_) insn_constraint_len (c_,s_)

extern enum reg_class reg_class_for_constraint_1 (enum constraint_num);

static inline enum reg_class
reg_class_for_constraint (enum constraint_num c)
{
  if (insn_extra_register_constraint (c))
    return reg_class_for_constraint_1 (c);
  return NO_REGS;
}

extern bool insn_const_int_ok_for_constraint (HOST_WIDE_INT, enum constraint_num);
#define CONST_OK_FOR_CONSTRAINT_P(v_,c_,s_) \
    insn_const_int_ok_for_constraint (v_, lookup_constraint (s_))

enum constraint_type
{
  CT_REGISTER,
  CT_CONST_INT,
  CT_MEMORY,
  CT_SPECIAL_MEMORY,
  CT_ADDRESS,
  CT_FIXED_FORM
};

static inline enum constraint_type
get_constraint_type (enum constraint_num c)
{
  if (c >= CONSTRAINT_Bm)
    {
      if (c >= CONSTRAINT_Bz)
        return CT_FIXED_FORM;
      if (c >= CONSTRAINT_p)
        return CT_ADDRESS;
      return CT_SPECIAL_MEMORY;
    }
  if (c >= CONSTRAINT_m)
    return CT_MEMORY;
  if (c >= CONSTRAINT_I)
    return CT_CONST_INT;
  return CT_REGISTER;
}
#endif /* tm-preds.h */
