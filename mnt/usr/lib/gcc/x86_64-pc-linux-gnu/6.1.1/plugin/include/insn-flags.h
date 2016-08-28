/* Generated automatically by the program `genflags'
   from the machine description file `md'.  */

#ifndef GCC_INSN_FLAGS_H
#define GCC_INSN_FLAGS_H

#define HAVE_x86_fnstsw_1 (TARGET_80387)
#define HAVE_x86_sahf_1 (TARGET_SAHF)
#define HAVE_kmovw (!(MEM_P (operands[0]) && MEM_P (operands[1])) && TARGET_AVX512F)
#define HAVE_insvhi_1 1
#define HAVE_insvsi_1 1
#define HAVE_insvdi_1 (TARGET_64BIT)
#define HAVE_swapxf (TARGET_80387)
#define HAVE_zero_extendqidi2 (TARGET_64BIT)
#define HAVE_zero_extendhidi2 (TARGET_64BIT)
#define HAVE_zero_extendqisi2_and (TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
#define HAVE_zero_extendhisi2_and (TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
#define HAVE_zero_extendqihi2_and (TARGET_ZERO_EXTEND_WITH_AND && optimize_function_for_speed_p (cfun))
#define HAVE_extendsidi2_1 (!TARGET_64BIT)
#define HAVE_extendqidi2 (TARGET_64BIT)
#define HAVE_extendhidi2 (TARGET_64BIT)
#define HAVE_extendhisi2 1
#define HAVE_extendqisi2 1
#define HAVE_extendqihi2 1
#define HAVE_truncxfsf2_i387_noop (TARGET_80387 && flag_unsafe_math_optimizations)
#define HAVE_truncxfdf2_i387_noop (TARGET_80387 && flag_unsafe_math_optimizations)
#define HAVE_fix_truncsfsi_sse (SSE_FLOAT_MODE_P (SFmode) \
   && (!TARGET_FISTTP || TARGET_SSE_MATH))
#define HAVE_fix_truncsfdi_sse ((SSE_FLOAT_MODE_P (SFmode) \
   && (!TARGET_FISTTP || TARGET_SSE_MATH)) && (TARGET_64BIT))
#define HAVE_fix_truncdfsi_sse (SSE_FLOAT_MODE_P (DFmode) \
   && (!TARGET_FISTTP || TARGET_SSE_MATH))
#define HAVE_fix_truncdfdi_sse ((SSE_FLOAT_MODE_P (DFmode) \
   && (!TARGET_FISTTP || TARGET_SSE_MATH)) && (TARGET_64BIT))
#define HAVE_fix_trunchi_fisttp_i387_1 (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && TARGET_FISTTP \
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1])) \
	 && (TARGET_64BIT || HImode != DImode)) \
	&& TARGET_SSE_MATH) \
   && can_create_pseudo_p ())
#define HAVE_fix_truncsi_fisttp_i387_1 (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && TARGET_FISTTP \
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1])) \
	 && (TARGET_64BIT || SImode != DImode)) \
	&& TARGET_SSE_MATH) \
   && can_create_pseudo_p ())
#define HAVE_fix_truncdi_fisttp_i387_1 (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && TARGET_FISTTP \
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1])) \
	 && (TARGET_64BIT || DImode != DImode)) \
	&& TARGET_SSE_MATH) \
   && can_create_pseudo_p ())
#define HAVE_fix_trunchi_i387_fisttp (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && TARGET_FISTTP \
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1])) \
	 && (TARGET_64BIT || HImode != DImode)) \
	&& TARGET_SSE_MATH))
#define HAVE_fix_truncsi_i387_fisttp (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && TARGET_FISTTP \
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1])) \
	 && (TARGET_64BIT || SImode != DImode)) \
	&& TARGET_SSE_MATH))
#define HAVE_fix_truncdi_i387_fisttp (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && TARGET_FISTTP \
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1])) \
	 && (TARGET_64BIT || DImode != DImode)) \
	&& TARGET_SSE_MATH))
#define HAVE_fix_trunchi_i387_fisttp_with_temp (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && TARGET_FISTTP \
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1])) \
	&& (TARGET_64BIT || HImode != DImode)) \
	&& TARGET_SSE_MATH))
#define HAVE_fix_truncsi_i387_fisttp_with_temp (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && TARGET_FISTTP \
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1])) \
	&& (TARGET_64BIT || SImode != DImode)) \
	&& TARGET_SSE_MATH))
#define HAVE_fix_truncdi_i387_fisttp_with_temp (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && TARGET_FISTTP \
   && !((SSE_FLOAT_MODE_P (GET_MODE (operands[1])) \
	&& (TARGET_64BIT || DImode != DImode)) \
	&& TARGET_SSE_MATH))
#define HAVE_fix_truncdi_i387 (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && !TARGET_FISTTP \
   && !(TARGET_64BIT && SSE_FLOAT_MODE_P (GET_MODE (operands[1]))))
#define HAVE_fix_truncdi_i387_with_temp (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && !TARGET_FISTTP \
   && !(TARGET_64BIT && SSE_FLOAT_MODE_P (GET_MODE (operands[1]))))
#define HAVE_fix_trunchi_i387 (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && !TARGET_FISTTP \
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1])))
#define HAVE_fix_truncsi_i387 (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && !TARGET_FISTTP \
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1])))
#define HAVE_fix_trunchi_i387_with_temp (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && !TARGET_FISTTP \
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1])))
#define HAVE_fix_truncsi_i387_with_temp (X87_FLOAT_MODE_P (GET_MODE (operands[1])) \
   && !TARGET_FISTTP \
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1])))
#define HAVE_x86_fnstcw_1 (TARGET_80387)
#define HAVE_x86_fldcw_1 (TARGET_80387)
#define HAVE_floathisf2 (TARGET_80387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387))
#define HAVE_floathidf2 (TARGET_80387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387))
#define HAVE_floathixf2 (TARGET_80387 \
   && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387))
#define HAVE_floatsixf2 (TARGET_80387)
#define HAVE_floatdixf2 (TARGET_80387)
#define HAVE_floatdisf2_i387_with_xmm (TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode) \
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES_TO_VEC \
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun))
#define HAVE_floatdidf2_i387_with_xmm (TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode) \
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES_TO_VEC \
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun))
#define HAVE_floatdixf2_i387_with_xmm (TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode) \
   && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES_TO_VEC \
   && !TARGET_64BIT && optimize_function_for_speed_p (cfun))
#define HAVE_addsi_1_zext (TARGET_64BIT && ix86_binary_operator_ok (PLUS, SImode, operands))
#define HAVE_addqi_ext_1 1
#define HAVE_addqi3_carry (ix86_binary_operator_ok (PLUS, QImode, operands))
#define HAVE_addhi3_carry (ix86_binary_operator_ok (PLUS, HImode, operands))
#define HAVE_addsi3_carry (ix86_binary_operator_ok (PLUS, SImode, operands))
#define HAVE_adddi3_carry ((ix86_binary_operator_ok (PLUS, DImode, operands)) && (TARGET_64BIT))
#define HAVE_addcarrysi (ix86_binary_operator_ok (PLUS, SImode, operands))
#define HAVE_addcarrydi ((ix86_binary_operator_ok (PLUS, DImode, operands)) && (TARGET_64BIT))
#define HAVE_subqi3_carry (ix86_binary_operator_ok (MINUS, QImode, operands))
#define HAVE_subhi3_carry (ix86_binary_operator_ok (MINUS, HImode, operands))
#define HAVE_subsi3_carry (ix86_binary_operator_ok (MINUS, SImode, operands))
#define HAVE_subdi3_carry ((ix86_binary_operator_ok (MINUS, DImode, operands)) && (TARGET_64BIT))
#define HAVE_subborrowsi (ix86_binary_operator_ok (MINUS, SImode, operands))
#define HAVE_subborrowdi ((ix86_binary_operator_ok (MINUS, DImode, operands)) && (TARGET_64BIT))
#define HAVE_divmodsi4_1 1
#define HAVE_divmoddi4_1 (TARGET_64BIT)
#define HAVE_divmodhiqi3 (TARGET_QIMODE_MATH)
#define HAVE_udivmodsi4_1 1
#define HAVE_udivmoddi4_1 (TARGET_64BIT)
#define HAVE_udivmodhiqi3 (TARGET_QIMODE_MATH)
#define HAVE_kandnqi (TARGET_AVX512F)
#define HAVE_kandnhi (TARGET_AVX512F)
#define HAVE_andqi_ext_0 1
#define HAVE_kxnorqi (TARGET_AVX512F)
#define HAVE_kxnorhi (TARGET_AVX512F)
#define HAVE_kxnorsi (TARGET_AVX512BW)
#define HAVE_kxnordi (TARGET_AVX512BW)
#define HAVE_kortestzhi (TARGET_AVX512F && ix86_match_ccmode (insn, CCZmode))
#define HAVE_kortestchi (TARGET_AVX512F && ix86_match_ccmode (insn, CCCmode))
#define HAVE_kunpckhi (TARGET_AVX512F)
#define HAVE_kunpcksi (TARGET_AVX512BW)
#define HAVE_kunpckdi (TARGET_AVX512BW)
#define HAVE_copysignsf3_const ((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
   || (TARGET_SSE && (SFmode == TFmode)))
#define HAVE_copysigndf3_const ((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
   || (TARGET_SSE && (DFmode == TFmode)))
#define HAVE_copysigntf3_const ((SSE_FLOAT_MODE_P (TFmode) && TARGET_SSE_MATH) \
   || (TARGET_SSE && (TFmode == TFmode)))
#define HAVE_copysignsf3_var ((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
   || (TARGET_SSE && (SFmode == TFmode)))
#define HAVE_copysigndf3_var ((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
   || (TARGET_SSE && (DFmode == TFmode)))
#define HAVE_copysigntf3_var ((SSE_FLOAT_MODE_P (TFmode) && TARGET_SSE_MATH) \
   || (TARGET_SSE && (TFmode == TFmode)))
#define HAVE_x86_64_shld (TARGET_64BIT)
#define HAVE_x86_shld 1
#define HAVE_x86_64_shrd (TARGET_64BIT)
#define HAVE_x86_shrd 1
#define HAVE_ashrdi3_cvt (TARGET_64BIT && INTVAL (operands[2]) == 63 \
   && (TARGET_USE_CLTD || optimize_function_for_size_p (cfun)) \
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands))
#define HAVE_ashrsi3_cvt (INTVAL (operands[2]) == 31 \
   && (TARGET_USE_CLTD || optimize_function_for_size_p (cfun)) \
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
#define HAVE_ix86_rotldi3_doubleword (!TARGET_64BIT)
#define HAVE_ix86_rotlti3_doubleword (TARGET_64BIT)
#define HAVE_ix86_rotrdi3_doubleword (!TARGET_64BIT)
#define HAVE_ix86_rotrti3_doubleword (TARGET_64BIT)
#define HAVE_setcc_sf_sse (SSE_FLOAT_MODE_P (SFmode))
#define HAVE_setcc_df_sse (SSE_FLOAT_MODE_P (DFmode))
#define HAVE_jump 1
#define HAVE_blockage 1
#define HAVE_prologue_use 1
#define HAVE_simple_return_internal (reload_completed)
#define HAVE_simple_return_internal_long (reload_completed)
#define HAVE_simple_return_pop_internal (reload_completed)
#define HAVE_simple_return_indirect_internal (reload_completed)
#define HAVE_nop 1
#define HAVE_nops (reload_completed)
#define HAVE_pad 1
#define HAVE_set_got_rex64 (TARGET_64BIT)
#define HAVE_set_rip_rex64 (TARGET_64BIT)
#define HAVE_set_got_offset_rex64 (TARGET_LP64)
#define HAVE_eh_return_internal 1
#define HAVE_leave (!TARGET_64BIT)
#define HAVE_leave_rex64 (TARGET_64BIT)
#define HAVE_split_stack_return 1
#define HAVE_ffssi2_no_cmove (!TARGET_CMOVE)
#define HAVE_bmi_bextr_si (TARGET_BMI)
#define HAVE_bmi_bextr_di ((TARGET_BMI) && (TARGET_64BIT))
#define HAVE_bmi2_pdep_si3 (TARGET_BMI2)
#define HAVE_bmi2_pdep_di3 ((TARGET_BMI2) && (TARGET_64BIT))
#define HAVE_bmi2_pext_si3 (TARGET_BMI2)
#define HAVE_bmi2_pext_di3 ((TARGET_BMI2) && (TARGET_64BIT))
#define HAVE_tbm_bextri_si (TARGET_TBM)
#define HAVE_tbm_bextri_di ((TARGET_TBM) && (TARGET_64BIT))
#define HAVE_bsr_rex64 (TARGET_64BIT)
#define HAVE_bsr 1
#define HAVE_bswaphi_lowpart 1
#define HAVE_paritydi2_cmp (! TARGET_POPCNT)
#define HAVE_paritysi2_cmp (! TARGET_POPCNT)
#define HAVE_truncxfsf2_i387_noop_unspec (TARGET_USE_FANCY_MATH_387)
#define HAVE_truncxfdf2_i387_noop_unspec (TARGET_USE_FANCY_MATH_387)
#define HAVE_sqrtxf2 (TARGET_USE_FANCY_MATH_387)
#define HAVE_sqrt_extendsfxf2_i387 (TARGET_USE_FANCY_MATH_387)
#define HAVE_sqrt_extenddfxf2_i387 (TARGET_USE_FANCY_MATH_387)
#define HAVE_fpremxf4_i387 (TARGET_USE_FANCY_MATH_387 \
   && flag_finite_math_only)
#define HAVE_fprem1xf4_i387 (TARGET_USE_FANCY_MATH_387 \
   && flag_finite_math_only)
#define HAVE_sincosxf3 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_sincos_extendsfxf3_i387 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_sincos_extenddfxf3_i387 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_fptanxf4_i387 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations \
   && standard_80387_constant_p (operands[3]) == 2)
#define HAVE_fptan_extendsfxf4_i387 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations \
   && standard_80387_constant_p (operands[3]) == 2)
#define HAVE_fptan_extenddfxf4_i387 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations \
   && standard_80387_constant_p (operands[3]) == 2)
#define HAVE_fpatan_extendsfxf3_i387 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_fpatan_extenddfxf3_i387 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_fyl2xxf3_i387 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fyl2x_extendsfxf3_i387 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_fyl2x_extenddfxf3_i387 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_fyl2xp1xf3_i387 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fyl2xp1_extendsfxf3_i387 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_fyl2xp1_extenddfxf3_i387 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_fxtractxf3_i387 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fxtract_extendsfxf3_i387 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_fxtract_extenddfxf3_i387 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_fscalexf4_i387 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_sse4_1_roundsf2 (TARGET_ROUND)
#define HAVE_sse4_1_rounddf2 (TARGET_ROUND)
#define HAVE_rintxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fistdi2 (TARGET_USE_FANCY_MATH_387)
#define HAVE_fistdi2_with_temp (TARGET_USE_FANCY_MATH_387)
#define HAVE_fisthi2 (TARGET_USE_FANCY_MATH_387)
#define HAVE_fistsi2 (TARGET_USE_FANCY_MATH_387)
#define HAVE_fisthi2_with_temp (TARGET_USE_FANCY_MATH_387)
#define HAVE_fistsi2_with_temp (TARGET_USE_FANCY_MATH_387)
#define HAVE_frndintxf2_floor (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations \
   && can_create_pseudo_p ())
#define HAVE_frndintxf2_ceil (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations \
   && can_create_pseudo_p ())
#define HAVE_frndintxf2_trunc (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations \
   && can_create_pseudo_p ())
#define HAVE_frndintxf2_floor_i387 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_frndintxf2_ceil_i387 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_frndintxf2_trunc_i387 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_frndintxf2_mask_pm (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations \
   && can_create_pseudo_p ())
#define HAVE_frndintxf2_mask_pm_i387 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fistdi2_floor (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fistdi2_ceil (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fistdi2_floor_with_temp (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fistdi2_ceil_with_temp (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fisthi2_floor (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fisthi2_ceil (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fistsi2_floor (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fistsi2_ceil (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fisthi2_floor_with_temp (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fisthi2_ceil_with_temp (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fistsi2_floor_with_temp (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fistsi2_ceil_with_temp (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_fxamsf2_i387 (TARGET_USE_FANCY_MATH_387)
#define HAVE_fxamdf2_i387 (TARGET_USE_FANCY_MATH_387)
#define HAVE_fxamxf2_i387 (TARGET_USE_FANCY_MATH_387)
#define HAVE_fxamsf2_i387_with_temp (TARGET_USE_FANCY_MATH_387 \
   && can_create_pseudo_p ())
#define HAVE_fxamdf2_i387_with_temp (TARGET_USE_FANCY_MATH_387 \
   && can_create_pseudo_p ())
#define HAVE_movmsk_df (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
#define HAVE_cld 1
#define HAVE_smaxsf3 (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
#define HAVE_sminsf3 (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
#define HAVE_smaxdf3 (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
#define HAVE_smindf3 (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
#define HAVE_pro_epilogue_adjust_stack_si_add (Pmode == SImode)
#define HAVE_pro_epilogue_adjust_stack_di_add (Pmode == DImode)
#define HAVE_pro_epilogue_adjust_stack_si_sub (Pmode == SImode)
#define HAVE_pro_epilogue_adjust_stack_di_sub (Pmode == DImode)
#define HAVE_allocate_stack_worker_probe_si ((ix86_target_stack_probe ()) && (Pmode == SImode))
#define HAVE_allocate_stack_worker_probe_di ((ix86_target_stack_probe ()) && (Pmode == DImode))
#define HAVE_adjust_stack_and_probesi (Pmode == SImode)
#define HAVE_adjust_stack_and_probedi (Pmode == DImode)
#define HAVE_probe_stack_rangesi (Pmode == SImode)
#define HAVE_probe_stack_rangedi (Pmode == DImode)
#define HAVE_trap 1
#define HAVE_stack_protect_set_si ((TARGET_SSP_TLS_GUARD) && (ptr_mode == SImode))
#define HAVE_stack_protect_set_di ((TARGET_SSP_TLS_GUARD) && (ptr_mode == DImode))
#define HAVE_stack_tls_protect_set_si (ptr_mode == SImode)
#define HAVE_stack_tls_protect_set_di (ptr_mode == DImode)
#define HAVE_stack_protect_test_si ((TARGET_SSP_TLS_GUARD) && (ptr_mode == SImode))
#define HAVE_stack_protect_test_di ((TARGET_SSP_TLS_GUARD) && (ptr_mode == DImode))
#define HAVE_stack_tls_protect_test_si (ptr_mode == SImode)
#define HAVE_stack_tls_protect_test_di (ptr_mode == DImode)
#define HAVE_sse4_2_crc32qi (TARGET_SSE4_2 || TARGET_CRC32)
#define HAVE_sse4_2_crc32hi (TARGET_SSE4_2 || TARGET_CRC32)
#define HAVE_sse4_2_crc32si (TARGET_SSE4_2 || TARGET_CRC32)
#define HAVE_sse4_2_crc32di (TARGET_64BIT && (TARGET_SSE4_2 || TARGET_CRC32))
#define HAVE_rdpmc (!TARGET_64BIT)
#define HAVE_rdpmc_rex64 (TARGET_64BIT)
#define HAVE_rdtsc (!TARGET_64BIT)
#define HAVE_rdtsc_rex64 (TARGET_64BIT)
#define HAVE_rdtscp (!TARGET_64BIT)
#define HAVE_rdtscp_rex64 (TARGET_64BIT)
#define HAVE_fxsave (TARGET_FXSR)
#define HAVE_fxsave64 (TARGET_64BIT && TARGET_FXSR)
#define HAVE_fxrstor (TARGET_FXSR)
#define HAVE_fxrstor64 (TARGET_64BIT && TARGET_FXSR)
#define HAVE_xsave (!TARGET_64BIT && TARGET_XSAVE)
#define HAVE_xsaveopt ((!TARGET_64BIT && TARGET_XSAVE) && (TARGET_XSAVEOPT))
#define HAVE_xsavec ((!TARGET_64BIT && TARGET_XSAVE) && (TARGET_XSAVEC))
#define HAVE_xsaves ((!TARGET_64BIT && TARGET_XSAVE) && (TARGET_XSAVES))
#define HAVE_xsave_rex64 (TARGET_64BIT && TARGET_XSAVE)
#define HAVE_xsaveopt_rex64 ((TARGET_64BIT && TARGET_XSAVE) && (TARGET_XSAVEOPT))
#define HAVE_xsavec_rex64 ((TARGET_64BIT && TARGET_XSAVE) && (TARGET_XSAVEC))
#define HAVE_xsaves_rex64 ((TARGET_64BIT && TARGET_XSAVE) && (TARGET_XSAVES))
#define HAVE_xsave64 (TARGET_64BIT && TARGET_XSAVE)
#define HAVE_xsaveopt64 ((TARGET_64BIT && TARGET_XSAVE) && (TARGET_XSAVEOPT))
#define HAVE_xsavec64 ((TARGET_64BIT && TARGET_XSAVE) && (TARGET_XSAVEC))
#define HAVE_xsaves64 ((TARGET_64BIT && TARGET_XSAVE) && (TARGET_XSAVES))
#define HAVE_xrstor (!TARGET_64BIT && TARGET_XSAVE)
#define HAVE_xrstors ((!TARGET_64BIT && TARGET_XSAVE) && (TARGET_XSAVES))
#define HAVE_xrstor_rex64 (TARGET_64BIT && TARGET_XSAVE)
#define HAVE_xrstors_rex64 ((TARGET_64BIT && TARGET_XSAVE) && (TARGET_XSAVES))
#define HAVE_xrstor64 (TARGET_64BIT && TARGET_XSAVE)
#define HAVE_xrstors64 ((TARGET_64BIT && TARGET_XSAVE) && (TARGET_XSAVES))
#define HAVE_fnstenv (TARGET_80387)
#define HAVE_fldenv (TARGET_80387)
#define HAVE_fnstsw (TARGET_80387)
#define HAVE_fnclex (TARGET_80387)
#define HAVE_lwp_slwpcbsi ((TARGET_LWP) && (Pmode == SImode))
#define HAVE_lwp_slwpcbdi ((TARGET_LWP) && (Pmode == DImode))
#define HAVE_rdfsbasesi (TARGET_64BIT && TARGET_FSGSBASE)
#define HAVE_rdgsbasesi (TARGET_64BIT && TARGET_FSGSBASE)
#define HAVE_rdfsbasedi ((TARGET_64BIT && TARGET_FSGSBASE) && (TARGET_64BIT))
#define HAVE_rdgsbasedi ((TARGET_64BIT && TARGET_FSGSBASE) && (TARGET_64BIT))
#define HAVE_wrfsbasesi (TARGET_64BIT && TARGET_FSGSBASE)
#define HAVE_wrgsbasesi (TARGET_64BIT && TARGET_FSGSBASE)
#define HAVE_wrfsbasedi ((TARGET_64BIT && TARGET_FSGSBASE) && (TARGET_64BIT))
#define HAVE_wrgsbasedi ((TARGET_64BIT && TARGET_FSGSBASE) && (TARGET_64BIT))
#define HAVE_rdrandhi_1 (TARGET_RDRND)
#define HAVE_rdrandsi_1 (TARGET_RDRND)
#define HAVE_rdranddi_1 ((TARGET_RDRND) && (TARGET_64BIT))
#define HAVE_rdseedhi_1 (TARGET_RDSEED)
#define HAVE_rdseedsi_1 (TARGET_RDSEED)
#define HAVE_rdseeddi_1 ((TARGET_RDSEED) && (TARGET_64BIT))
#define HAVE_xbegin_1 (TARGET_RTM)
#define HAVE_xend (TARGET_RTM)
#define HAVE_xabort (TARGET_RTM)
#define HAVE_xtest_1 (TARGET_RTM)
#define HAVE_pcommit (TARGET_PCOMMIT)
#define HAVE_clwb (TARGET_CLWB)
#define HAVE_clflushopt (TARGET_CLFLUSHOPT)
#define HAVE_mwaitx (TARGET_MWAITX)
#define HAVE_monitorx_si ((TARGET_MWAITX) && (Pmode == SImode))
#define HAVE_monitorx_di ((TARGET_MWAITX) && (Pmode == DImode))
#define HAVE_clzero_si ((TARGET_CLZERO) && (Pmode == SImode))
#define HAVE_clzero_di ((TARGET_CLZERO) && (Pmode == DImode))
#define HAVE_move_size_reloc_si (TARGET_MPX)
#define HAVE_move_size_reloc_di ((TARGET_MPX) && (TARGET_64BIT))
#define HAVE_sse_movntq (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_mmx_rcpv2sf2 (TARGET_3DNOW)
#define HAVE_mmx_rcpit1v2sf3 (TARGET_3DNOW)
#define HAVE_mmx_rcpit2v2sf3 (TARGET_3DNOW)
#define HAVE_mmx_rsqrtv2sf2 (TARGET_3DNOW)
#define HAVE_mmx_rsqit1v2sf3 (TARGET_3DNOW)
#define HAVE_mmx_haddv2sf3 (TARGET_3DNOW)
#define HAVE_mmx_hsubv2sf3 (TARGET_3DNOW_A)
#define HAVE_mmx_addsubv2sf3 (TARGET_3DNOW_A)
#define HAVE_mmx_gtv2sf3 (TARGET_3DNOW)
#define HAVE_mmx_gev2sf3 (TARGET_3DNOW)
#define HAVE_mmx_pf2id (TARGET_3DNOW)
#define HAVE_mmx_pf2iw (TARGET_3DNOW_A)
#define HAVE_mmx_pi2fw (TARGET_3DNOW_A)
#define HAVE_mmx_floatv2si2 (TARGET_3DNOW)
#define HAVE_mmx_pswapdv2sf2 (TARGET_3DNOW_A)
#define HAVE_mmx_ashrv4hi3 (TARGET_MMX)
#define HAVE_mmx_ashrv2si3 (TARGET_MMX)
#define HAVE_mmx_ashlv4hi3 (TARGET_MMX)
#define HAVE_mmx_lshrv4hi3 (TARGET_MMX)
#define HAVE_mmx_ashlv2si3 (TARGET_MMX)
#define HAVE_mmx_lshrv2si3 (TARGET_MMX)
#define HAVE_mmx_ashlv1di3 (TARGET_MMX)
#define HAVE_mmx_lshrv1di3 (TARGET_MMX)
#define HAVE_mmx_gtv8qi3 (TARGET_MMX)
#define HAVE_mmx_gtv4hi3 (TARGET_MMX)
#define HAVE_mmx_gtv2si3 (TARGET_MMX)
#define HAVE_mmx_andnotv8qi3 (TARGET_MMX)
#define HAVE_mmx_andnotv4hi3 (TARGET_MMX)
#define HAVE_mmx_andnotv2si3 (TARGET_MMX)
#define HAVE_mmx_packsswb (TARGET_MMX)
#define HAVE_mmx_packssdw (TARGET_MMX)
#define HAVE_mmx_packuswb (TARGET_MMX)
#define HAVE_mmx_punpckhbw (TARGET_MMX)
#define HAVE_mmx_punpcklbw (TARGET_MMX)
#define HAVE_mmx_punpckhwd (TARGET_MMX)
#define HAVE_mmx_punpcklwd (TARGET_MMX)
#define HAVE_mmx_punpckhdq (TARGET_MMX)
#define HAVE_mmx_punpckldq (TARGET_MMX)
#define HAVE_mmx_pextrw (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_mmx_pshufw_1 (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_mmx_pswapdv2si2 (TARGET_3DNOW_A)
#define HAVE_mmx_psadbw (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_mmx_pmovmskb (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_avx512f_loadv16si_mask (TARGET_AVX512F)
#define HAVE_avx512vl_loadv8si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_loadv4si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_loadv8di_mask (TARGET_AVX512F)
#define HAVE_avx512vl_loadv4di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_loadv2di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_loadv16sf_mask (TARGET_AVX512F)
#define HAVE_avx512vl_loadv8sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_loadv4sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_loadv8df_mask (TARGET_AVX512F)
#define HAVE_avx512vl_loadv4df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_loadv2df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512bw_loadv64qi_mask (TARGET_AVX512BW)
#define HAVE_avx512vl_loadv16qi_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_loadv32qi_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_loadv32hi_mask (TARGET_AVX512BW)
#define HAVE_avx512vl_loadv16hi_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_loadv8hi_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512f_blendmv16si (TARGET_AVX512F)
#define HAVE_avx512vl_blendmv8si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_blendmv4si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_blendmv8di (TARGET_AVX512F)
#define HAVE_avx512vl_blendmv4di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_blendmv2di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_blendmv16sf (TARGET_AVX512F)
#define HAVE_avx512vl_blendmv8sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_blendmv4sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_blendmv8df (TARGET_AVX512F)
#define HAVE_avx512vl_blendmv4df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_blendmv2df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512bw_blendmv64qi (TARGET_AVX512BW)
#define HAVE_avx512vl_blendmv16qi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_blendmv32qi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_blendmv32hi (TARGET_AVX512BW)
#define HAVE_avx512vl_blendmv16hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_blendmv8hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512f_storev16si_mask (TARGET_AVX512F)
#define HAVE_avx512vl_storev8si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storev4si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_storev8di_mask (TARGET_AVX512F)
#define HAVE_avx512vl_storev4di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storev2di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_storev16sf_mask (TARGET_AVX512F)
#define HAVE_avx512vl_storev8sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storev4sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_storev8df_mask (TARGET_AVX512F)
#define HAVE_avx512vl_storev4df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storev2df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512bw_storev64qi_mask (TARGET_AVX512BW)
#define HAVE_avx512vl_storev16qi_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storev32qi_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_storev32hi_mask (TARGET_AVX512BW)
#define HAVE_avx512vl_storev16hi_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storev8hi_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_sse2_movq128 (TARGET_SSE2)
#define HAVE_movdi_to_sse (!TARGET_64BIT && TARGET_SSE2 && TARGET_INTER_UNIT_MOVES_TO_VEC)
#define HAVE_avx512f_storeups512 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_avx_storeups256 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_sse_storeups (TARGET_SSE)
#define HAVE_avx512f_storeupd512 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_avx_storeupd256 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_sse2_storeupd ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_avx512f_storeups512_mask (TARGET_AVX512F)
#define HAVE_avx512vl_storeups256_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storeups_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_storeupd512_mask (TARGET_AVX512F)
#define HAVE_avx512vl_storeupd256_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storeupd_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx_storedquv32qi ((TARGET_SSE2) && (TARGET_AVX))
#define HAVE_sse2_storedquv16qi (TARGET_SSE2)
#define HAVE_avx512f_storedquv64qi (TARGET_AVX512BW)
#define HAVE_avx512bw_storedquv32hi (TARGET_AVX512BW)
#define HAVE_avx512vl_storedquv8hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storedquv16hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512f_storedquv16si (TARGET_AVX512F)
#define HAVE_avx_storedquv8si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_sse2_storedquv4si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_storedquv8di (TARGET_AVX512F)
#define HAVE_avx512vl_storedquv4di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storedquv2di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_storedquv16si_mask (TARGET_AVX512F)
#define HAVE_avx512vl_storedquv8si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storedquv4si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_storedquv8di_mask (TARGET_AVX512F)
#define HAVE_avx512vl_storedquv4di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storedquv2di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512bw_storedquv64qi_mask (TARGET_AVX512BW)
#define HAVE_avx512vl_storedquv16qi_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storedquv32qi_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_storedquv32hi_mask (TARGET_AVX512BW)
#define HAVE_avx512vl_storedquv16hi_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_storedquv8hi_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx_lddqu256 ((TARGET_SSE3) && (TARGET_AVX))
#define HAVE_sse3_lddqu (TARGET_SSE3)
#define HAVE_sse2_movntisi (TARGET_SSE2)
#define HAVE_sse2_movntidi ((TARGET_SSE2) && (TARGET_64BIT))
#define HAVE_avx512f_movntv16sf ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_avx_movntv8sf ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_sse_movntv4sf (TARGET_SSE)
#define HAVE_avx512f_movntv8df ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_avx_movntv4df ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_sse2_movntv2df ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_avx512f_movntv8di ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_avx_movntv4di ((TARGET_SSE2) && (TARGET_AVX))
#define HAVE_sse2_movntv2di (TARGET_SSE2)
#define HAVE_sse_vmaddv4sf3 (TARGET_SSE)
#define HAVE_sse_vmaddv4sf3_round ((TARGET_AVX512F) && (TARGET_SSE))
#define HAVE_sse_vmsubv4sf3 (TARGET_SSE)
#define HAVE_sse_vmsubv4sf3_round ((TARGET_AVX512F) && (TARGET_SSE))
#define HAVE_sse2_vmaddv2df3 ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_sse2_vmaddv2df3_round ((TARGET_AVX512F) && ((TARGET_SSE) && (TARGET_SSE2)))
#define HAVE_sse2_vmsubv2df3 ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_sse2_vmsubv2df3_round ((TARGET_AVX512F) && ((TARGET_SSE) && (TARGET_SSE2)))
#define HAVE_sse_vmmulv4sf3 (TARGET_SSE)
#define HAVE_sse_vmmulv4sf3_round ((TARGET_AVX512F) && (TARGET_SSE))
#define HAVE_sse_vmdivv4sf3 (TARGET_SSE)
#define HAVE_sse_vmdivv4sf3_round ((TARGET_AVX512F) && (TARGET_SSE))
#define HAVE_sse2_vmmulv2df3 ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_sse2_vmmulv2df3_round ((TARGET_AVX512F) && ((TARGET_SSE) && (TARGET_SSE2)))
#define HAVE_sse2_vmdivv2df3 ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_sse2_vmdivv2df3_round ((TARGET_AVX512F) && ((TARGET_SSE) && (TARGET_SSE2)))
#define HAVE_avx512f_divv16sf3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_divv16sf3_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_avx512f_divv16sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_avx512f_divv16sf3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_avx_divv8sf3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_avx_divv8sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_sse_divv4sf3 (TARGET_SSE && 1 && 1)
#define HAVE_sse_divv4sf3_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1))
#define HAVE_avx512f_divv8df3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_divv8df3_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_avx512f_divv8df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_avx512f_divv8df3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_avx_divv4df3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_avx_divv4df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_sse2_divv2df3 ((TARGET_SSE && 1 && 1) && (TARGET_SSE2))
#define HAVE_sse2_divv2df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_SSE2)))
#define HAVE_avx_rcpv8sf2 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_sse_rcpv4sf2 (TARGET_SSE)
#define HAVE_sse_vmrcpv4sf2 (TARGET_SSE)
#define HAVE_rcp14v16sf_mask (TARGET_AVX512F)
#define HAVE_rcp14v8sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_rcp14v4sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_rcp14v8df_mask (TARGET_AVX512F)
#define HAVE_rcp14v4df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_rcp14v2df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_srcp14v4sf (TARGET_AVX512F)
#define HAVE_srcp14v2df ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_avx512f_sqrtv16sf2 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_sqrtv16sf2_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_avx512f_sqrtv16sf2_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_avx512f_sqrtv16sf2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_avx_sqrtv8sf2 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_avx_sqrtv8sf2_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_sse_sqrtv4sf2 (TARGET_SSE && 1 && 1)
#define HAVE_sse_sqrtv4sf2_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1))
#define HAVE_avx512f_sqrtv8df2 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_sqrtv8df2_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_avx512f_sqrtv8df2_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_avx512f_sqrtv8df2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_avx_sqrtv4df2 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_avx_sqrtv4df2_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_sse2_sqrtv2df2 ((TARGET_SSE && 1 && 1) && (TARGET_SSE2))
#define HAVE_sse2_sqrtv2df2_mask ((TARGET_AVX512F) && ((TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_SSE2)))
#define HAVE_sse_vmsqrtv4sf2 (TARGET_SSE)
#define HAVE_sse_vmsqrtv4sf2_round ((TARGET_AVX512F) && (TARGET_SSE))
#define HAVE_sse2_vmsqrtv2df2 ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_sse2_vmsqrtv2df2_round ((TARGET_AVX512F) && ((TARGET_SSE) && (TARGET_SSE2)))
#define HAVE_avx_rsqrtv8sf2 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_sse_rsqrtv4sf2 (TARGET_SSE)
#define HAVE_rsqrt14v16sf_mask (TARGET_AVX512F)
#define HAVE_rsqrt14v8sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_rsqrt14v4sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_rsqrt14v8df_mask (TARGET_AVX512F)
#define HAVE_rsqrt14v4df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_rsqrt14v2df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_rsqrt14v4sf (TARGET_AVX512F)
#define HAVE_rsqrt14v2df ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_sse_vmrsqrtv4sf2 (TARGET_SSE)
#define HAVE_sse_vmsmaxv4sf3 (TARGET_SSE)
#define HAVE_sse_vmsmaxv4sf3_round ((TARGET_AVX512F) && (TARGET_SSE))
#define HAVE_sse_vmsminv4sf3 (TARGET_SSE)
#define HAVE_sse_vmsminv4sf3_round ((TARGET_AVX512F) && (TARGET_SSE))
#define HAVE_sse2_vmsmaxv2df3 ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_sse2_vmsmaxv2df3_round ((TARGET_AVX512F) && ((TARGET_SSE) && (TARGET_SSE2)))
#define HAVE_sse2_vmsminv2df3 ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_sse2_vmsminv2df3_round ((TARGET_AVX512F) && ((TARGET_SSE) && (TARGET_SSE2)))
#define HAVE_avx_addsubv4df3 (TARGET_AVX)
#define HAVE_sse3_addsubv2df3 (TARGET_SSE3)
#define HAVE_avx_addsubv8sf3 (TARGET_AVX)
#define HAVE_sse3_addsubv4sf3 (TARGET_SSE3)
#define HAVE_avx_haddv4df3 (TARGET_AVX)
#define HAVE_avx_hsubv4df3 (TARGET_AVX)
#define HAVE_sse3_hsubv2df3 (TARGET_SSE3)
#define HAVE_avx_haddv8sf3 (TARGET_AVX)
#define HAVE_avx_hsubv8sf3 (TARGET_AVX)
#define HAVE_sse3_haddv4sf3 (TARGET_SSE3)
#define HAVE_sse3_hsubv4sf3 (TARGET_SSE3)
#define HAVE_reducepv16sf_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_reducepv8sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_reducepv4sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_reducepv8df_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_reducepv4df_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_reducepv2df_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_reducesv4sf (TARGET_AVX512DQ)
#define HAVE_reducesv2df ((TARGET_AVX512DQ) && (TARGET_SSE2))
#define HAVE_avx_cmpv8sf3 (TARGET_AVX)
#define HAVE_avx_cmpv4sf3 (TARGET_AVX)
#define HAVE_avx_cmpv4df3 (TARGET_AVX)
#define HAVE_avx_cmpv2df3 ((TARGET_AVX) && (TARGET_SSE2))
#define HAVE_avx_vmcmpv4sf3 (TARGET_AVX)
#define HAVE_avx_vmcmpv2df3 ((TARGET_AVX) && (TARGET_SSE2))
#define HAVE_avx_maskcmpv8sf3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_sse_maskcmpv4sf3 (TARGET_SSE)
#define HAVE_avx_maskcmpv4df3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_sse2_maskcmpv2df3 ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_sse_vmmaskcmpv4sf3 (TARGET_SSE)
#define HAVE_sse2_vmmaskcmpv2df3 ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_avx512f_cmpv16si3 (TARGET_AVX512F && 1)
#define HAVE_avx512f_cmpv16si3_mask ((TARGET_AVX512F) && (TARGET_AVX512F && 1))
#define HAVE_avx512f_cmpv16si3_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V16SImode == V16SFmode \
									      || V16SImode == V8DFmode \
									      || V16SImode == V8DImode \
									      || V16SImode == V16SImode)))
#define HAVE_avx512f_cmpv16si3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512F && (V16SImode == V16SFmode \
									      || V16SImode == V8DFmode \
									      || V16SImode == V8DImode \
									      || V16SImode == V16SImode))))
#define HAVE_avx512vl_cmpv8si3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cmpv8si3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_cmpv4si3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cmpv4si3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512f_cmpv8di3 (TARGET_AVX512F && 1)
#define HAVE_avx512f_cmpv8di3_mask ((TARGET_AVX512F) && (TARGET_AVX512F && 1))
#define HAVE_avx512f_cmpv8di3_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V8DImode == V16SFmode \
									      || V8DImode == V8DFmode \
									      || V8DImode == V8DImode \
									      || V8DImode == V16SImode)))
#define HAVE_avx512f_cmpv8di3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512F && (V8DImode == V16SFmode \
									      || V8DImode == V8DFmode \
									      || V8DImode == V8DImode \
									      || V8DImode == V16SImode))))
#define HAVE_avx512vl_cmpv4di3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cmpv4di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_cmpv2di3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cmpv2di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512f_cmpv16sf3 (TARGET_AVX512F && 1)
#define HAVE_avx512f_cmpv16sf3_mask ((TARGET_AVX512F) && (TARGET_AVX512F && 1))
#define HAVE_avx512f_cmpv16sf3_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V16SFmode == V16SFmode \
									      || V16SFmode == V8DFmode \
									      || V16SFmode == V8DImode \
									      || V16SFmode == V16SImode)))
#define HAVE_avx512f_cmpv16sf3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512F && (V16SFmode == V16SFmode \
									      || V16SFmode == V8DFmode \
									      || V16SFmode == V8DImode \
									      || V16SFmode == V16SImode))))
#define HAVE_avx512vl_cmpv8sf3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cmpv8sf3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_cmpv4sf3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cmpv4sf3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512f_cmpv8df3 (TARGET_AVX512F && 1)
#define HAVE_avx512f_cmpv8df3_mask ((TARGET_AVX512F) && (TARGET_AVX512F && 1))
#define HAVE_avx512f_cmpv8df3_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode)))
#define HAVE_avx512f_cmpv8df3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512F && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode))))
#define HAVE_avx512vl_cmpv4df3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cmpv4df3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_cmpv2df3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cmpv2df3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_cmpv64qi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_cmpv64qi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_cmpv16qi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cmpv16qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_cmpv32qi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cmpv32qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_cmpv32hi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_cmpv32hi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_cmpv16hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cmpv16hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_cmpv8hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cmpv8hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_ucmpv64qi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_ucmpv64qi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_ucmpv16qi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_ucmpv16qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_ucmpv32qi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_ucmpv32qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_ucmpv32hi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_ucmpv32hi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_ucmpv16hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_ucmpv16hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_ucmpv8hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_ucmpv8hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512f_ucmpv16si3 (TARGET_AVX512F)
#define HAVE_avx512f_ucmpv16si3_mask (TARGET_AVX512F)
#define HAVE_avx512vl_ucmpv8si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_ucmpv8si3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_ucmpv4si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_ucmpv4si3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_ucmpv8di3 (TARGET_AVX512F)
#define HAVE_avx512f_ucmpv8di3_mask (TARGET_AVX512F)
#define HAVE_avx512vl_ucmpv4di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_ucmpv4di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_ucmpv2di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_ucmpv2di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_vmcmpv4sf3 (TARGET_AVX512F)
#define HAVE_avx512f_vmcmpv4sf3_round (TARGET_AVX512F)
#define HAVE_avx512f_vmcmpv2df3 ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_avx512f_vmcmpv2df3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_SSE2)))
#define HAVE_avx512f_vmcmpv4sf3_mask (TARGET_AVX512F)
#define HAVE_avx512f_vmcmpv4sf3_mask_round (TARGET_AVX512F)
#define HAVE_avx512f_vmcmpv2df3_mask ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_avx512f_vmcmpv2df3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_SSE2)))
#define HAVE_avx512f_maskcmpv16sf3 (TARGET_AVX512F)
#define HAVE_avx512f_maskcmpv8sf3 ((TARGET_AVX512F) && (TARGET_AVX))
#define HAVE_avx512f_maskcmpv4sf3 (TARGET_AVX512F)
#define HAVE_avx512f_maskcmpv8df3 (TARGET_AVX512F)
#define HAVE_avx512f_maskcmpv4df3 ((TARGET_AVX512F) && (TARGET_AVX))
#define HAVE_avx512f_maskcmpv2df3 ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_sse_comi (SSE_FLOAT_MODE_P (SFmode))
#define HAVE_sse_comi_round ((TARGET_AVX512F) && (SSE_FLOAT_MODE_P (SFmode)))
#define HAVE_sse2_comi (SSE_FLOAT_MODE_P (DFmode))
#define HAVE_sse2_comi_round ((TARGET_AVX512F) && (SSE_FLOAT_MODE_P (DFmode)))
#define HAVE_sse_ucomi (SSE_FLOAT_MODE_P (SFmode))
#define HAVE_sse_ucomi_round ((TARGET_AVX512F) && (SSE_FLOAT_MODE_P (SFmode)))
#define HAVE_sse2_ucomi (SSE_FLOAT_MODE_P (DFmode))
#define HAVE_sse2_ucomi_round ((TARGET_AVX512F) && (SSE_FLOAT_MODE_P (DFmode)))
#define HAVE_avx_andnotv8sf3 ((TARGET_SSE && 1) && (TARGET_AVX))
#define HAVE_avx_andnotv8sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && TARGET_AVX512VL) && (TARGET_AVX)))
#define HAVE_sse_andnotv4sf3 (TARGET_SSE && 1)
#define HAVE_sse_andnotv4sf3_mask ((TARGET_AVX512F) && (TARGET_SSE && TARGET_AVX512VL))
#define HAVE_avx_andnotv4df3 ((TARGET_SSE && 1) && (TARGET_AVX))
#define HAVE_avx_andnotv4df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && TARGET_AVX512VL) && (TARGET_AVX)))
#define HAVE_sse2_andnotv2df3 ((TARGET_SSE && 1) && (TARGET_SSE2))
#define HAVE_sse2_andnotv2df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && TARGET_AVX512VL) && (TARGET_SSE2)))
#define HAVE_avx512f_andnotv16sf3 (TARGET_AVX512F)
#define HAVE_avx512f_andnotv16sf3_mask (TARGET_AVX512F)
#define HAVE_avx512f_andnotv8df3 (TARGET_AVX512F)
#define HAVE_avx512f_andnotv8df3_mask (TARGET_AVX512F)
#define HAVE_fma_fmadd_v16sf_maskz_1 (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && 1)
#define HAVE_fma_fmadd_v16sf_maskz_1_round ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)))
#define HAVE_fma_fmadd_v8sf_maskz_1 ((TARGET_AVX512F && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fmadd_v4sf_maskz_1 ((TARGET_AVX512F && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fmadd_v8df_maskz_1 (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && 1)
#define HAVE_fma_fmadd_v8df_maskz_1_round ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)))
#define HAVE_fma_fmadd_v4df_maskz_1 ((TARGET_AVX512F && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fmadd_v2df_maskz_1 ((TARGET_AVX512F && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fmadd_v16sf_mask (TARGET_AVX512F && 1)
#define HAVE_avx512f_fmadd_v16sf_mask_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)))
#define HAVE_avx512vl_fmadd_v8sf_mask ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmadd_v4sf_mask ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fmadd_v8df_mask (TARGET_AVX512F && 1)
#define HAVE_avx512f_fmadd_v8df_mask_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)))
#define HAVE_avx512vl_fmadd_v4df_mask ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmadd_v2df_mask ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fmadd_v16sf_mask3 (TARGET_AVX512F)
#define HAVE_avx512f_fmadd_v16sf_mask3_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmadd_v8sf_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmadd_v8sf_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmadd_v4sf_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmadd_v4sf_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fmadd_v8df_mask3 (TARGET_AVX512F)
#define HAVE_avx512f_fmadd_v8df_mask3_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmadd_v4df_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmadd_v4df_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmadd_v2df_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmadd_v2df_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_fma_fmsub_v16sf_maskz_1 (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && 1)
#define HAVE_fma_fmsub_v16sf_maskz_1_round ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)))
#define HAVE_fma_fmsub_v8sf_maskz_1 ((TARGET_AVX512F && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fmsub_v4sf_maskz_1 ((TARGET_AVX512F && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fmsub_v8df_maskz_1 (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && 1)
#define HAVE_fma_fmsub_v8df_maskz_1_round ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)))
#define HAVE_fma_fmsub_v4df_maskz_1 ((TARGET_AVX512F && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fmsub_v2df_maskz_1 ((TARGET_AVX512F && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fmsub_v16sf_mask (TARGET_AVX512F)
#define HAVE_avx512f_fmsub_v16sf_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmsub_v8sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsub_v8sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmsub_v4sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsub_v4sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fmsub_v8df_mask (TARGET_AVX512F)
#define HAVE_avx512f_fmsub_v8df_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmsub_v4df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsub_v4df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmsub_v2df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsub_v2df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fmsub_v16sf_mask3 (TARGET_AVX512F && 1)
#define HAVE_avx512f_fmsub_v16sf_mask3_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)))
#define HAVE_avx512vl_fmsub_v8sf_mask3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsub_v4sf_mask3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fmsub_v8df_mask3 (TARGET_AVX512F && 1)
#define HAVE_avx512f_fmsub_v8df_mask3_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)))
#define HAVE_avx512vl_fmsub_v4df_mask3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsub_v2df_mask3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fnmadd_v16sf_maskz_1 (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && 1)
#define HAVE_fma_fnmadd_v16sf_maskz_1_round ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)))
#define HAVE_fma_fnmadd_v8sf_maskz_1 ((TARGET_AVX512F && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fnmadd_v4sf_maskz_1 ((TARGET_AVX512F && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fnmadd_v8df_maskz_1 (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && 1)
#define HAVE_fma_fnmadd_v8df_maskz_1_round ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)))
#define HAVE_fma_fnmadd_v4df_maskz_1 ((TARGET_AVX512F && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fnmadd_v2df_maskz_1 ((TARGET_AVX512F && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fnmadd_v16sf_mask (TARGET_AVX512F && 1)
#define HAVE_avx512f_fnmadd_v16sf_mask_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)))
#define HAVE_avx512vl_fnmadd_v8sf_mask ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fnmadd_v4sf_mask ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fnmadd_v8df_mask (TARGET_AVX512F && 1)
#define HAVE_avx512f_fnmadd_v8df_mask_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)))
#define HAVE_avx512vl_fnmadd_v4df_mask ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fnmadd_v2df_mask ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fnmadd_v16sf_mask3 (TARGET_AVX512F && 1)
#define HAVE_avx512f_fnmadd_v16sf_mask3_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)))
#define HAVE_avx512vl_fnmadd_v8sf_mask3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fnmadd_v4sf_mask3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fnmadd_v8df_mask3 (TARGET_AVX512F && 1)
#define HAVE_avx512f_fnmadd_v8df_mask3_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)))
#define HAVE_avx512vl_fnmadd_v4df_mask3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fnmadd_v2df_mask3 ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fnmsub_v16sf_maskz_1 (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && 1)
#define HAVE_fma_fnmsub_v16sf_maskz_1_round ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)))
#define HAVE_fma_fnmsub_v8sf_maskz_1 ((TARGET_AVX512F && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fnmsub_v4sf_maskz_1 ((TARGET_AVX512F && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fnmsub_v8df_maskz_1 (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && 1)
#define HAVE_fma_fnmsub_v8df_maskz_1_round ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)))
#define HAVE_fma_fnmsub_v4df_maskz_1 ((TARGET_AVX512F && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fnmsub_v2df_maskz_1 ((TARGET_AVX512F && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fnmsub_v16sf_mask (TARGET_AVX512F && 1)
#define HAVE_avx512f_fnmsub_v16sf_mask_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)))
#define HAVE_avx512vl_fnmsub_v8sf_mask ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fnmsub_v4sf_mask ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fnmsub_v8df_mask (TARGET_AVX512F && 1)
#define HAVE_avx512f_fnmsub_v8df_mask_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)))
#define HAVE_avx512vl_fnmsub_v4df_mask ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fnmsub_v2df_mask ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fnmsub_v16sf_mask3 (TARGET_AVX512F)
#define HAVE_avx512f_fnmsub_v16sf_mask3_round (TARGET_AVX512F)
#define HAVE_avx512vl_fnmsub_v8sf_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fnmsub_v8sf_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fnmsub_v4sf_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fnmsub_v4sf_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fnmsub_v8df_mask3 (TARGET_AVX512F)
#define HAVE_avx512f_fnmsub_v8df_mask3_round (TARGET_AVX512F)
#define HAVE_avx512vl_fnmsub_v4df_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fnmsub_v4df_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fnmsub_v2df_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fnmsub_v2df_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_fma_fmaddsub_v16sf_maskz_1 (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && 1)
#define HAVE_fma_fmaddsub_v16sf_maskz_1_round ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)))
#define HAVE_fma_fmaddsub_v8sf_maskz_1 ((TARGET_AVX512F && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fmaddsub_v4sf_maskz_1 ((TARGET_AVX512F && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fmaddsub_v8df_maskz_1 (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && 1)
#define HAVE_fma_fmaddsub_v8df_maskz_1_round ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)))
#define HAVE_fma_fmaddsub_v4df_maskz_1 ((TARGET_AVX512F && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fmaddsub_v2df_maskz_1 ((TARGET_AVX512F && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fmaddsub_v16sf_mask (TARGET_AVX512F)
#define HAVE_avx512f_fmaddsub_v16sf_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmaddsub_v8sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmaddsub_v8sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmaddsub_v4sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmaddsub_v4sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fmaddsub_v8df_mask (TARGET_AVX512F)
#define HAVE_avx512f_fmaddsub_v8df_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmaddsub_v4df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmaddsub_v4df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmaddsub_v2df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmaddsub_v2df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fmaddsub_v16sf_mask3 (TARGET_AVX512F)
#define HAVE_avx512f_fmaddsub_v16sf_mask3_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmaddsub_v8sf_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmaddsub_v8sf_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmaddsub_v4sf_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmaddsub_v4sf_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fmaddsub_v8df_mask3 (TARGET_AVX512F)
#define HAVE_avx512f_fmaddsub_v8df_mask3_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmaddsub_v4df_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmaddsub_v4df_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmaddsub_v2df_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmaddsub_v2df_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_fma_fmsubadd_v16sf_maskz_1 (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && 1)
#define HAVE_fma_fmsubadd_v16sf_maskz_1_round ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)))
#define HAVE_fma_fmsubadd_v8sf_maskz_1 ((TARGET_AVX512F && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fmsubadd_v4sf_maskz_1 ((TARGET_AVX512F && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fmsubadd_v8df_maskz_1 (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && 1)
#define HAVE_fma_fmsubadd_v8df_maskz_1_round ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)))
#define HAVE_fma_fmsubadd_v4df_maskz_1 ((TARGET_AVX512F && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_fma_fmsubadd_v2df_maskz_1 ((TARGET_AVX512F && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512VL))
#define HAVE_avx512f_fmsubadd_v16sf_mask (TARGET_AVX512F)
#define HAVE_avx512f_fmsubadd_v16sf_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmsubadd_v8sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsubadd_v8sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmsubadd_v4sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsubadd_v4sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fmsubadd_v8df_mask (TARGET_AVX512F)
#define HAVE_avx512f_fmsubadd_v8df_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmsubadd_v4df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsubadd_v4df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmsubadd_v2df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsubadd_v2df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fmsubadd_v16sf_mask3 (TARGET_AVX512F)
#define HAVE_avx512f_fmsubadd_v16sf_mask3_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmsubadd_v8sf_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsubadd_v8sf_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmsubadd_v4sf_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsubadd_v4sf_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fmsubadd_v8df_mask3 (TARGET_AVX512F)
#define HAVE_avx512f_fmsubadd_v8df_mask3_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmsubadd_v4df_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsubadd_v4df_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmsubadd_v2df_mask3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmsubadd_v2df_mask3_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_sse_cvtpi2ps (TARGET_SSE)
#define HAVE_sse_cvtps2pi (TARGET_SSE)
#define HAVE_sse_cvttps2pi (TARGET_SSE)
#define HAVE_sse_cvtsi2ss (TARGET_SSE)
#define HAVE_sse_cvtsi2ss_round ((TARGET_AVX512F) && (TARGET_SSE))
#define HAVE_sse_cvtsi2ssq (TARGET_SSE && TARGET_64BIT)
#define HAVE_sse_cvtsi2ssq_round ((TARGET_AVX512F) && (TARGET_SSE && TARGET_64BIT))
#define HAVE_sse_cvtss2si (TARGET_SSE)
#define HAVE_sse_cvtss2si_round ((TARGET_AVX512F) && (TARGET_SSE))
#define HAVE_sse_cvtss2si_2 (TARGET_SSE)
#define HAVE_sse_cvtss2siq (TARGET_SSE && TARGET_64BIT)
#define HAVE_sse_cvtss2siq_round ((TARGET_AVX512F) && (TARGET_SSE && TARGET_64BIT))
#define HAVE_sse_cvtss2siq_2 (TARGET_SSE && TARGET_64BIT)
#define HAVE_sse_cvttss2si (TARGET_SSE)
#define HAVE_sse_cvttss2si_round ((TARGET_AVX512F) && (TARGET_SSE))
#define HAVE_sse_cvttss2siq (TARGET_SSE && TARGET_64BIT)
#define HAVE_sse_cvttss2siq_round ((TARGET_AVX512F) && (TARGET_SSE && TARGET_64BIT))
#define HAVE_cvtusi2ss32 (TARGET_AVX512F && 1)
#define HAVE_cvtusi2ss32_round ((TARGET_AVX512F) && (TARGET_AVX512F && (V4SFmode == V4SFmode)))
#define HAVE_cvtusi2sd32 ((TARGET_AVX512F && 1) && (TARGET_SSE2))
#define HAVE_cvtusi2ss64 (TARGET_AVX512F && TARGET_64BIT)
#define HAVE_cvtusi2ss64_round ((TARGET_AVX512F) && (TARGET_AVX512F && TARGET_64BIT))
#define HAVE_cvtusi2sd64 ((TARGET_AVX512F && TARGET_64BIT) && (TARGET_SSE2))
#define HAVE_cvtusi2sd64_round ((TARGET_AVX512F) && ((TARGET_AVX512F && TARGET_64BIT) && (TARGET_SSE2)))
#define HAVE_floatv16siv16sf2 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512F))
#define HAVE_floatv16siv16sf2_round ((TARGET_AVX512F) && ((TARGET_SSE2 && 1 && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_floatv16siv16sf2_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_floatv16siv16sf2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_floatv8siv8sf2 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX))
#define HAVE_floatv8siv8sf2_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_floatv4siv4sf2 (TARGET_SSE2 && 1 && 1)
#define HAVE_floatv4siv4sf2_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && 1))
#define HAVE_ufloatv16siv16sf2 (TARGET_AVX512F)
#define HAVE_ufloatv16siv16sf2_round (TARGET_AVX512F)
#define HAVE_ufloatv16siv16sf2_mask (TARGET_AVX512F)
#define HAVE_ufloatv16siv16sf2_mask_round (TARGET_AVX512F)
#define HAVE_ufloatv8siv8sf2 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_ufloatv8siv8sf2_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_ufloatv8siv8sf2_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_ufloatv8siv8sf2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_ufloatv4siv4sf2 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_ufloatv4siv4sf2_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_ufloatv4siv4sf2_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_ufloatv4siv4sf2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx_fix_notruncv8sfv8si ((TARGET_SSE2 && 1) && (TARGET_AVX))
#define HAVE_avx_fix_notruncv8sfv8si_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX)))
#define HAVE_sse2_fix_notruncv4sfv4si (TARGET_SSE2 && 1)
#define HAVE_sse2_fix_notruncv4sfv4si_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_avx512f_fix_notruncv16sfv16si (TARGET_AVX512F)
#define HAVE_avx512f_fix_notruncv16sfv16si_round (TARGET_AVX512F)
#define HAVE_avx512f_fix_notruncv16sfv16si_mask (TARGET_AVX512F)
#define HAVE_avx512f_fix_notruncv16sfv16si_mask_round (TARGET_AVX512F)
#define HAVE_avx512f_ufix_notruncv16sfv16si_mask (TARGET_AVX512F)
#define HAVE_avx512f_ufix_notruncv16sfv16si_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_ufix_notruncv8sfv8si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_ufix_notruncv8sfv8si_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512vl_ufix_notruncv4sfv4si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_ufix_notruncv4sfv4si_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512dq_cvtps2qqv8di_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && 1))
#define HAVE_avx512dq_cvtps2qqv8di_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8DImode == V16SFmode \
							      || V8DImode == V8DFmode \
							      || V8DImode == V8DImode \
							      || V8DImode == V16SImode))))
#define HAVE_avx512dq_cvtps2qqv4di_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512dq_cvtps2qqv2di_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && TARGET_AVX512VL))
#define HAVE_avx512dq_cvtps2uqqv8di_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && 1))
#define HAVE_avx512dq_cvtps2uqqv8di_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8DImode == V16SFmode \
							      || V8DImode == V8DFmode \
							      || V8DImode == V8DImode \
							      || V8DImode == V16SImode))))
#define HAVE_avx512dq_cvtps2uqqv4di_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512dq_cvtps2uqqv2di_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && TARGET_AVX512VL))
#define HAVE_fix_truncv16sfv16si2 (TARGET_AVX512F)
#define HAVE_fix_truncv16sfv16si2_round (TARGET_AVX512F)
#define HAVE_fix_truncv16sfv16si2_mask (TARGET_AVX512F)
#define HAVE_fix_truncv16sfv16si2_mask_round (TARGET_AVX512F)
#define HAVE_ufix_truncv16sfv16si2 (TARGET_AVX512F)
#define HAVE_ufix_truncv16sfv16si2_round (TARGET_AVX512F)
#define HAVE_ufix_truncv16sfv16si2_mask (TARGET_AVX512F)
#define HAVE_ufix_truncv16sfv16si2_mask_round (TARGET_AVX512F)
#define HAVE_fix_truncv8sfv8si2 (TARGET_AVX && 1)
#define HAVE_fix_truncv8sfv8si2_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL))
#define HAVE_fix_truncv4sfv4si2 (TARGET_SSE2 && 1)
#define HAVE_fix_truncv4sfv4si2_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL))
#define HAVE_sse2_cvtpi2pd (TARGET_SSE2)
#define HAVE_sse2_cvtpd2pi (TARGET_SSE2)
#define HAVE_sse2_cvttpd2pi (TARGET_SSE2)
#define HAVE_sse2_cvtsi2sd (TARGET_SSE2)
#define HAVE_sse2_cvtsi2sdq (TARGET_SSE2 && TARGET_64BIT)
#define HAVE_sse2_cvtsi2sdq_round ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_64BIT))
#define HAVE_avx512f_vcvtss2usi (TARGET_AVX512F)
#define HAVE_avx512f_vcvtss2usi_round (TARGET_AVX512F)
#define HAVE_avx512f_vcvtss2usiq (TARGET_AVX512F && TARGET_64BIT)
#define HAVE_avx512f_vcvtss2usiq_round ((TARGET_AVX512F) && (TARGET_AVX512F && TARGET_64BIT))
#define HAVE_avx512f_vcvttss2usi (TARGET_AVX512F)
#define HAVE_avx512f_vcvttss2usi_round (TARGET_AVX512F)
#define HAVE_avx512f_vcvttss2usiq (TARGET_AVX512F && TARGET_64BIT)
#define HAVE_avx512f_vcvttss2usiq_round ((TARGET_AVX512F) && (TARGET_AVX512F && TARGET_64BIT))
#define HAVE_avx512f_vcvtsd2usi (TARGET_AVX512F)
#define HAVE_avx512f_vcvtsd2usi_round (TARGET_AVX512F)
#define HAVE_avx512f_vcvtsd2usiq (TARGET_AVX512F && TARGET_64BIT)
#define HAVE_avx512f_vcvtsd2usiq_round ((TARGET_AVX512F) && (TARGET_AVX512F && TARGET_64BIT))
#define HAVE_avx512f_vcvttsd2usi (TARGET_AVX512F)
#define HAVE_avx512f_vcvttsd2usi_round (TARGET_AVX512F)
#define HAVE_avx512f_vcvttsd2usiq (TARGET_AVX512F && TARGET_64BIT)
#define HAVE_avx512f_vcvttsd2usiq_round ((TARGET_AVX512F) && (TARGET_AVX512F && TARGET_64BIT))
#define HAVE_sse2_cvtsd2si (TARGET_SSE2)
#define HAVE_sse2_cvtsd2si_round ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_sse2_cvtsd2si_2 (TARGET_SSE2)
#define HAVE_sse2_cvtsd2siq (TARGET_SSE2 && TARGET_64BIT)
#define HAVE_sse2_cvtsd2siq_round ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_64BIT))
#define HAVE_sse2_cvtsd2siq_2 (TARGET_SSE2 && TARGET_64BIT)
#define HAVE_sse2_cvttsd2si (TARGET_SSE2)
#define HAVE_sse2_cvttsd2si_round ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_sse2_cvttsd2siq (TARGET_SSE2 && TARGET_64BIT)
#define HAVE_sse2_cvttsd2siq_round ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_64BIT))
#define HAVE_floatv8siv8df2 ((TARGET_AVX && 1) && (TARGET_AVX512F))
#define HAVE_floatv8siv8df2_mask ((TARGET_AVX512F) && ((TARGET_AVX && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_floatv4siv4df2 (TARGET_AVX && 1)
#define HAVE_floatv4siv4df2_mask ((TARGET_AVX512F) && (TARGET_AVX && (32 == 64 || TARGET_AVX512VL)))
#define HAVE_floatv8div8df2 (TARGET_AVX512DQ)
#define HAVE_floatv8div8df2_round ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_floatv8div8df2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_floatv8div8df2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ)))
#define HAVE_ufloatv8div8df2 (TARGET_AVX512DQ)
#define HAVE_ufloatv8div8df2_round ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_ufloatv8div8df2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_ufloatv8div8df2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ)))
#define HAVE_floatv4div4df2 ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_floatv4div4df2_round ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_floatv4div4df2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_floatv4div4df2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL))))
#define HAVE_ufloatv4div4df2 ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_ufloatv4div4df2_round ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_ufloatv4div4df2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_ufloatv4div4df2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL))))
#define HAVE_floatv2div2df2 ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_floatv2div2df2_round ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_floatv2div2df2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_floatv2div2df2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL))))
#define HAVE_ufloatv2div2df2 ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_ufloatv2div2df2_round ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_ufloatv2div2df2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_ufloatv2div2df2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL))))
#define HAVE_floatv8div8sf2 (TARGET_AVX512DQ && 1)
#define HAVE_floatv8div8sf2_round ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8SFmode == V8SFmode)))
#define HAVE_floatv8div8sf2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && 1))
#define HAVE_floatv8div8sf2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8SFmode == V8SFmode))))
#define HAVE_ufloatv8div8sf2 (TARGET_AVX512DQ && 1)
#define HAVE_ufloatv8div8sf2_round ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8SFmode == V8SFmode)))
#define HAVE_ufloatv8div8sf2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && 1))
#define HAVE_ufloatv8div8sf2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8SFmode == V8SFmode))))
#define HAVE_floatv4div4sf2 ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_floatv4div4sf2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_ufloatv4div4sf2 ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_ufloatv4div4sf2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_floatv2div2sf2_mask (TARGET_AVX512DQ && TARGET_AVX512VL)
#define HAVE_ufloatv2div2sf2_mask (TARGET_AVX512DQ && TARGET_AVX512VL)
#define HAVE_ufloatv8siv8df2 (TARGET_AVX512F)
#define HAVE_ufloatv8siv8df2_mask (TARGET_AVX512F)
#define HAVE_ufloatv4siv4df2 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_ufloatv4siv4df2_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_ufloatv2siv2df2 (TARGET_AVX512VL)
#define HAVE_ufloatv2siv2df2_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_cvtdq2pd512_2 (TARGET_AVX512F)
#define HAVE_avx_cvtdq2pd256_2 (TARGET_AVX)
#define HAVE_sse2_cvtdq2pd (TARGET_SSE2 && 1)
#define HAVE_sse2_cvtdq2pd_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL))
#define HAVE_avx512f_cvtpd2dq512 (TARGET_AVX512F)
#define HAVE_avx512f_cvtpd2dq512_round (TARGET_AVX512F)
#define HAVE_avx512f_cvtpd2dq512_mask (TARGET_AVX512F)
#define HAVE_avx512f_cvtpd2dq512_mask_round (TARGET_AVX512F)
#define HAVE_avx_cvtpd2dq256 (TARGET_AVX && 1)
#define HAVE_avx_cvtpd2dq256_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL))
#define HAVE_sse2_cvtpd2dq (TARGET_SSE2 && 1)
#define HAVE_sse2_cvtpd2dq_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL))
#define HAVE_ufix_notruncv8dfv8si2 (TARGET_AVX512F)
#define HAVE_ufix_notruncv8dfv8si2_round (TARGET_AVX512F)
#define HAVE_ufix_notruncv8dfv8si2_mask (TARGET_AVX512F)
#define HAVE_ufix_notruncv8dfv8si2_mask_round (TARGET_AVX512F)
#define HAVE_ufix_notruncv4dfv4si2 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_ufix_notruncv4dfv4si2_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_ufix_notruncv4dfv4si2_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_ufix_notruncv4dfv4si2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_ufix_notruncv2dfv2si2 (TARGET_AVX512VL)
#define HAVE_ufix_notruncv2dfv2si2_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_fix_truncv8dfv8si2 (TARGET_AVX512F)
#define HAVE_fix_truncv8dfv8si2_round (TARGET_AVX512F)
#define HAVE_fix_truncv8dfv8si2_mask (TARGET_AVX512F)
#define HAVE_fix_truncv8dfv8si2_mask_round (TARGET_AVX512F)
#define HAVE_ufix_truncv8dfv8si2 (TARGET_AVX512F)
#define HAVE_ufix_truncv8dfv8si2_round (TARGET_AVX512F)
#define HAVE_ufix_truncv8dfv8si2_mask (TARGET_AVX512F)
#define HAVE_ufix_truncv8dfv8si2_mask_round (TARGET_AVX512F)
#define HAVE_ufix_truncv2dfv2si2 (TARGET_AVX512VL)
#define HAVE_ufix_truncv2dfv2si2_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_fix_truncv4dfv4si2 (TARGET_AVX || (TARGET_AVX512VL && TARGET_AVX512F))
#define HAVE_fix_truncv4dfv4si2_mask ((TARGET_AVX512F) && (TARGET_AVX || (TARGET_AVX512VL && TARGET_AVX512F)))
#define HAVE_ufix_truncv4dfv4si2 (TARGET_AVX512VL && TARGET_AVX512F)
#define HAVE_ufix_truncv4dfv4si2_mask ((TARGET_AVX512F) && (TARGET_AVX512VL && TARGET_AVX512F))
#define HAVE_fix_truncv8dfv8di2 (TARGET_AVX512DQ && 1)
#define HAVE_fix_truncv8dfv8di2_round ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode)))
#define HAVE_fix_truncv8dfv8di2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && 1))
#define HAVE_fix_truncv8dfv8di2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode))))
#define HAVE_ufix_truncv8dfv8di2 (TARGET_AVX512DQ && 1)
#define HAVE_ufix_truncv8dfv8di2_round ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode)))
#define HAVE_ufix_truncv8dfv8di2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && 1))
#define HAVE_ufix_truncv8dfv8di2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode))))
#define HAVE_fix_truncv4dfv4di2 ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_fix_truncv4dfv4di2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_ufix_truncv4dfv4di2 ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_ufix_truncv4dfv4di2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_fix_truncv2dfv2di2 ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_fix_truncv2dfv2di2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_ufix_truncv2dfv2di2 ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_ufix_truncv2dfv2di2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_fix_notruncv8dfv8di2 (TARGET_AVX512DQ && 1)
#define HAVE_fix_notruncv8dfv8di2_round ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)))
#define HAVE_fix_notruncv8dfv8di2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && 1))
#define HAVE_fix_notruncv8dfv8di2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode))))
#define HAVE_fix_notruncv4dfv4di2 ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_fix_notruncv4dfv4di2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_fix_notruncv2dfv2di2 ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_fix_notruncv2dfv2di2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_ufix_notruncv8dfv8di2 (TARGET_AVX512DQ && 1)
#define HAVE_ufix_notruncv8dfv8di2_round ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)))
#define HAVE_ufix_notruncv8dfv8di2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && 1))
#define HAVE_ufix_notruncv8dfv8di2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode))))
#define HAVE_ufix_notruncv4dfv4di2 ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_ufix_notruncv4dfv4di2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_ufix_notruncv2dfv2di2 ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_ufix_notruncv2dfv2di2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_fix_truncv8sfv8di2 (TARGET_AVX512DQ && 1)
#define HAVE_fix_truncv8sfv8di2_round ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8SFmode == V8SFmode)))
#define HAVE_fix_truncv8sfv8di2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && 1))
#define HAVE_fix_truncv8sfv8di2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8SFmode == V8SFmode))))
#define HAVE_ufix_truncv8sfv8di2 (TARGET_AVX512DQ && 1)
#define HAVE_ufix_truncv8sfv8di2_round ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8SFmode == V8SFmode)))
#define HAVE_ufix_truncv8sfv8di2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && 1))
#define HAVE_ufix_truncv8sfv8di2_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8SFmode == V8SFmode))))
#define HAVE_fix_truncv4sfv4di2 ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_fix_truncv4sfv4di2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_ufix_truncv4sfv4di2 ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_ufix_truncv4sfv4di2_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_fix_truncv2sfv2di2 (TARGET_AVX512DQ && TARGET_AVX512VL)
#define HAVE_fix_truncv2sfv2di2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && TARGET_AVX512VL))
#define HAVE_ufix_truncv2sfv2di2 (TARGET_AVX512DQ && TARGET_AVX512VL)
#define HAVE_ufix_truncv2sfv2di2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && TARGET_AVX512VL))
#define HAVE_ufix_truncv8sfv8si2 (TARGET_AVX512VL)
#define HAVE_ufix_truncv8sfv8si2_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_ufix_truncv4sfv4si2 (TARGET_AVX512VL)
#define HAVE_ufix_truncv4sfv4si2_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_sse2_cvttpd2dq (TARGET_SSE2 && 1)
#define HAVE_sse2_cvttpd2dq_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL))
#define HAVE_sse2_cvtsd2ss (TARGET_SSE2)
#define HAVE_sse2_cvtsd2ss_round ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_sse2_cvtss2sd (TARGET_SSE2)
#define HAVE_sse2_cvtss2sd_round ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_avx512f_cvtpd2ps512_mask (TARGET_AVX512F)
#define HAVE_avx512f_cvtpd2ps512_mask_round (TARGET_AVX512F)
#define HAVE_avx_cvtpd2ps256 (TARGET_AVX && 1)
#define HAVE_avx_cvtpd2ps256_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL))
#define HAVE_avx512f_cvtps2pd512 ((TARGET_AVX && 1 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_cvtps2pd512_round ((TARGET_AVX512F) && ((TARGET_AVX && 1 && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_avx512f_cvtps2pd512_mask ((TARGET_AVX512F) && ((TARGET_AVX && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_avx512f_cvtps2pd512_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_avx_cvtps2pd256 (TARGET_AVX && 1 && 1)
#define HAVE_avx_cvtps2pd256_mask ((TARGET_AVX512F) && (TARGET_AVX && (32 == 64 || TARGET_AVX512VL) && 1))
#define HAVE_vec_unpacks_lo_v16sf (TARGET_AVX512F)
#define HAVE_avx512bw_cvtb2maskv64qi (TARGET_AVX512BW)
#define HAVE_avx512vl_cvtb2maskv16qi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cvtb2maskv32qi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_cvtw2maskv32hi (TARGET_AVX512BW)
#define HAVE_avx512vl_cvtw2maskv16hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cvtw2maskv8hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512f_cvtd2maskv16si (TARGET_AVX512DQ)
#define HAVE_avx512vl_cvtd2maskv8si ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cvtd2maskv4si ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_avx512f_cvtq2maskv8di (TARGET_AVX512DQ)
#define HAVE_avx512vl_cvtq2maskv4di ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cvtq2maskv2di ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_sse2_cvtps2pd (TARGET_SSE2 && 1)
#define HAVE_sse2_cvtps2pd_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL))
#define HAVE_sse_movhlps (TARGET_SSE && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_sse_movlhps (TARGET_SSE && ix86_binary_operator_ok (UNKNOWN, V4SFmode, operands))
#define HAVE_avx512f_unpckhps512_mask (TARGET_AVX512F)
#define HAVE_avx_unpckhps256 (TARGET_AVX && 1)
#define HAVE_avx_unpckhps256_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL))
#define HAVE_vec_interleave_highv4sf (TARGET_SSE && 1)
#define HAVE_vec_interleave_highv4sf_mask ((TARGET_AVX512F) && (TARGET_SSE && TARGET_AVX512VL))
#define HAVE_avx512f_unpcklps512_mask (TARGET_AVX512F)
#define HAVE_avx_unpcklps256 (TARGET_AVX && 1)
#define HAVE_avx_unpcklps256_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL))
#define HAVE_unpcklps128_mask (TARGET_AVX512VL)
#define HAVE_vec_interleave_lowv4sf (TARGET_SSE)
#define HAVE_avx_movshdup256 (TARGET_AVX && 1)
#define HAVE_avx_movshdup256_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL))
#define HAVE_sse3_movshdup (TARGET_SSE3 && 1)
#define HAVE_sse3_movshdup_mask ((TARGET_AVX512F) && (TARGET_SSE3 && TARGET_AVX512VL))
#define HAVE_avx512f_movshdup512_mask (TARGET_AVX512F)
#define HAVE_avx_movsldup256 (TARGET_AVX && 1)
#define HAVE_avx_movsldup256_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL))
#define HAVE_sse3_movsldup (TARGET_SSE3 && 1)
#define HAVE_sse3_movsldup_mask ((TARGET_AVX512F) && (TARGET_SSE3 && TARGET_AVX512VL))
#define HAVE_avx512f_movsldup512_mask (TARGET_AVX512F)
#define HAVE_avx_shufps256_1 (TARGET_AVX \
   && 1 \
   && (INTVAL (operands[3]) == (INTVAL (operands[7]) - 4) \
       && INTVAL (operands[4]) == (INTVAL (operands[8]) - 4) \
       && INTVAL (operands[5]) == (INTVAL (operands[9]) - 4) \
       && INTVAL (operands[6]) == (INTVAL (operands[10]) - 4)))
#define HAVE_avx_shufps256_1_mask ((TARGET_AVX512F) && (TARGET_AVX \
   && TARGET_AVX512VL \
   && (INTVAL (operands[3]) == (INTVAL (operands[7]) - 4) \
       && INTVAL (operands[4]) == (INTVAL (operands[8]) - 4) \
       && INTVAL (operands[5]) == (INTVAL (operands[9]) - 4) \
       && INTVAL (operands[6]) == (INTVAL (operands[10]) - 4))))
#define HAVE_sse_shufps_v4sf_mask (TARGET_AVX512VL)
#define HAVE_sse_shufps_v4si (TARGET_SSE)
#define HAVE_sse_shufps_v4sf (TARGET_SSE)
#define HAVE_sse_storehps (TARGET_SSE)
#define HAVE_sse_loadhps (TARGET_SSE)
#define HAVE_sse_storelps (TARGET_SSE)
#define HAVE_sse_loadlps (TARGET_SSE)
#define HAVE_sse_movss (TARGET_SSE)
#define HAVE_avx2_vec_dupv8sf ((TARGET_AVX2) && (TARGET_AVX))
#define HAVE_avx2_vec_dupv4sf (TARGET_AVX2)
#define HAVE_avx2_vec_dupv8sf_1 (TARGET_AVX2)
#define HAVE_avx512f_vec_dupv16sf_1 (TARGET_AVX512F)
#define HAVE_avx512f_vec_dupv8df_1 (TARGET_AVX512F)
#define HAVE_vec_setv4si_0 (TARGET_SSE)
#define HAVE_vec_setv4sf_0 (TARGET_SSE)
#define HAVE_sse4_1_insertps (TARGET_SSE4_1)
#define HAVE_avx512dq_vextractf64x2_1_maskm (TARGET_AVX512DQ \
   && (INTVAL (operands[2]) % 2 == 0) \
   && (INTVAL (operands[2]) == INTVAL (operands[3]) - 1) \
   && rtx_equal_p (operands[4], operands[0]))
#define HAVE_avx512dq_vextracti64x2_1_maskm (TARGET_AVX512DQ \
   && (INTVAL (operands[2]) % 2 == 0) \
   && (INTVAL (operands[2]) == INTVAL (operands[3]) - 1) \
   && rtx_equal_p (operands[4], operands[0]))
#define HAVE_avx512f_vextractf32x4_1_maskm (TARGET_AVX512F \
   && ((INTVAL (operands[2]) % 4 == 0) \
       && INTVAL (operands[2]) == (INTVAL (operands[3]) - 1) \
       && INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[4]) == (INTVAL (operands[5]) - 1)) \
   && rtx_equal_p (operands[6], operands[0]))
#define HAVE_avx512f_vextracti32x4_1_maskm (TARGET_AVX512F \
   && ((INTVAL (operands[2]) % 4 == 0) \
       && INTVAL (operands[2]) == (INTVAL (operands[3]) - 1) \
       && INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[4]) == (INTVAL (operands[5]) - 1)) \
   && rtx_equal_p (operands[6], operands[0]))
#define HAVE_avx512dq_vextractf64x2_1_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && (INTVAL (operands[2]) == INTVAL (operands[3]) - 1)))
#define HAVE_avx512dq_vextracti64x2_1_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && (INTVAL (operands[2]) == INTVAL (operands[3]) - 1)))
#define HAVE_avx512f_vextractf32x4_1_mask ((TARGET_AVX512F) && (TARGET_AVX512F \
   && (INTVAL (operands[2]) == (INTVAL (operands[3]) - 1) \
       && INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[4]) == (INTVAL (operands[5]) - 1))))
#define HAVE_avx512f_vextracti32x4_1_mask ((TARGET_AVX512F) && (TARGET_AVX512F \
   && (INTVAL (operands[2]) == (INTVAL (operands[3]) - 1) \
       && INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[4]) == (INTVAL (operands[5]) - 1))))
#define HAVE_vec_extract_lo_v8df_maskm (TARGET_AVX512F \
   && rtx_equal_p (operands[2], operands[0]))
#define HAVE_vec_extract_lo_v8di_maskm (TARGET_AVX512F \
   && rtx_equal_p (operands[2], operands[0]))
#define HAVE_vec_extract_lo_v8df (TARGET_AVX512F && !(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_vec_extract_lo_v8df_mask ((TARGET_AVX512F) && (TARGET_AVX512F && !(MEM_P (operands[0]) && MEM_P (operands[1]))))
#define HAVE_vec_extract_lo_v8di (TARGET_AVX512F && !(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_vec_extract_lo_v8di_mask ((TARGET_AVX512F) && (TARGET_AVX512F && !(MEM_P (operands[0]) && MEM_P (operands[1]))))
#define HAVE_vec_extract_hi_v8df_maskm (TARGET_AVX512F \
   && rtx_equal_p (operands[2], operands[0]))
#define HAVE_vec_extract_hi_v8di_maskm (TARGET_AVX512F \
   && rtx_equal_p (operands[2], operands[0]))
#define HAVE_vec_extract_hi_v8df (TARGET_AVX512F)
#define HAVE_vec_extract_hi_v8df_mask (TARGET_AVX512F)
#define HAVE_vec_extract_hi_v8di (TARGET_AVX512F)
#define HAVE_vec_extract_hi_v8di_mask (TARGET_AVX512F)
#define HAVE_vec_extract_hi_v16sf_maskm (TARGET_AVX512DQ \
   && rtx_equal_p (operands[2], operands[0]))
#define HAVE_vec_extract_hi_v16si_maskm (TARGET_AVX512DQ \
   && rtx_equal_p (operands[2], operands[0]))
#define HAVE_vec_extract_hi_v16sf (TARGET_AVX512F && 1)
#define HAVE_vec_extract_hi_v16sf_mask ((TARGET_AVX512F) && (TARGET_AVX512F && TARGET_AVX512DQ))
#define HAVE_vec_extract_hi_v16si (TARGET_AVX512F && 1)
#define HAVE_vec_extract_hi_v16si_mask ((TARGET_AVX512F) && (TARGET_AVX512F && TARGET_AVX512DQ))
#define HAVE_vec_extract_lo_v16sf (TARGET_AVX512F \
   && 1 \
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_vec_extract_lo_v16sf_mask ((TARGET_AVX512F) && (TARGET_AVX512F \
   && (64 == 64 || TARGET_AVX512VL) \
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))))
#define HAVE_vec_extract_lo_v16si (TARGET_AVX512F \
   && 1 \
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_vec_extract_lo_v16si_mask ((TARGET_AVX512F) && (TARGET_AVX512F \
   && (64 == 64 || TARGET_AVX512VL) \
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))))
#define HAVE_vec_extract_lo_v4di (TARGET_AVX \
   && 1 && 1 \
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_vec_extract_lo_v4di_mask ((TARGET_AVX512F) && (TARGET_AVX \
   && TARGET_AVX512VL && TARGET_AVX512DQ \
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))))
#define HAVE_vec_extract_lo_v4df (TARGET_AVX \
   && 1 && 1 \
   && !(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_vec_extract_lo_v4df_mask ((TARGET_AVX512F) && (TARGET_AVX \
   && TARGET_AVX512VL && TARGET_AVX512DQ \
   && !(MEM_P (operands[0]) && MEM_P (operands[1]))))
#define HAVE_vec_extract_hi_v4di (TARGET_AVX && 1 && 1)
#define HAVE_vec_extract_hi_v4di_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL && TARGET_AVX512DQ))
#define HAVE_vec_extract_hi_v4df (TARGET_AVX && 1 && 1)
#define HAVE_vec_extract_hi_v4df_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL && TARGET_AVX512DQ))
#define HAVE_vec_extract_lo_v8si (TARGET_AVX && 1 && 1)
#define HAVE_vec_extract_lo_v8si_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL && TARGET_AVX512DQ))
#define HAVE_vec_extract_lo_v8sf (TARGET_AVX && 1 && 1)
#define HAVE_vec_extract_lo_v8sf_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL && TARGET_AVX512DQ))
#define HAVE_vec_extract_lo_v8si_maskm (TARGET_AVX512VL && TARGET_AVX512F \
   && rtx_equal_p (operands[2], operands[0]))
#define HAVE_vec_extract_lo_v8sf_maskm (TARGET_AVX512VL && TARGET_AVX512F \
   && rtx_equal_p (operands[2], operands[0]))
#define HAVE_vec_extract_hi_v8si_maskm (TARGET_AVX512F && TARGET_AVX512VL \
   && rtx_equal_p (operands[2], operands[0]))
#define HAVE_vec_extract_hi_v8sf_maskm (TARGET_AVX512F && TARGET_AVX512VL \
   && rtx_equal_p (operands[2], operands[0]))
#define HAVE_vec_extract_hi_v8si_mask (TARGET_AVX512VL)
#define HAVE_vec_extract_hi_v8sf_mask (TARGET_AVX512VL)
#define HAVE_vec_extract_hi_v8si (TARGET_AVX)
#define HAVE_vec_extract_hi_v8sf (TARGET_AVX)
#define HAVE_vec_extract_lo_v32hi (TARGET_AVX512F && !(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_vec_extract_hi_v32hi (TARGET_AVX512F)
#define HAVE_vec_extract_lo_v16hi (TARGET_AVX && !(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_vec_extract_hi_v16hi (TARGET_AVX)
#define HAVE_vec_extract_lo_v64qi (TARGET_AVX512F && !(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_vec_extract_hi_v64qi (TARGET_AVX512F)
#define HAVE_vec_extract_lo_v32qi (TARGET_AVX && !(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_vec_extract_hi_v32qi (TARGET_AVX)
#define HAVE_avx512f_unpckhpd512_mask (TARGET_AVX512F)
#define HAVE_avx_unpckhpd256 (TARGET_AVX && 1)
#define HAVE_avx_unpckhpd256_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL))
#define HAVE_avx512vl_unpckhpd128_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_unpcklpd128_mask (TARGET_AVX512VL)
#define HAVE_avx512f_vmscalefv4sf (TARGET_AVX512F)
#define HAVE_avx512f_vmscalefv4sf_round (TARGET_AVX512F)
#define HAVE_avx512f_vmscalefv2df ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_avx512f_vmscalefv2df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_SSE2)))
#define HAVE_avx512f_scalefv16sf (TARGET_AVX512F)
#define HAVE_avx512f_scalefv16sf_round (TARGET_AVX512F)
#define HAVE_avx512f_scalefv16sf_mask (TARGET_AVX512F)
#define HAVE_avx512f_scalefv16sf_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_scalefv8sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scalefv8sf_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_scalefv8sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_scalefv8sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512vl_scalefv4sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scalefv4sf_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_scalefv4sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_scalefv4sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512f_scalefv8df (TARGET_AVX512F)
#define HAVE_avx512f_scalefv8df_round (TARGET_AVX512F)
#define HAVE_avx512f_scalefv8df_mask (TARGET_AVX512F)
#define HAVE_avx512f_scalefv8df_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_scalefv4df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scalefv4df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_scalefv4df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_scalefv4df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512vl_scalefv2df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scalefv2df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_scalefv2df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_scalefv2df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512f_vternlogv16si (TARGET_AVX512F)
#define HAVE_avx512f_vternlogv16si_maskz_1 (TARGET_AVX512F)
#define HAVE_avx512vl_vternlogv8si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vternlogv8si_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vternlogv4si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vternlogv4si_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_vternlogv8di (TARGET_AVX512F)
#define HAVE_avx512f_vternlogv8di_maskz_1 (TARGET_AVX512F)
#define HAVE_avx512vl_vternlogv4di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vternlogv4di_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vternlogv2di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vternlogv2di_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_vternlogv16si_mask (TARGET_AVX512F)
#define HAVE_avx512vl_vternlogv8si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vternlogv4si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_vternlogv8di_mask (TARGET_AVX512F)
#define HAVE_avx512vl_vternlogv4di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vternlogv2di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_getexpv16sf (TARGET_AVX512F)
#define HAVE_avx512f_getexpv16sf_round (TARGET_AVX512F)
#define HAVE_avx512f_getexpv16sf_mask (TARGET_AVX512F)
#define HAVE_avx512f_getexpv16sf_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_getexpv8sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_getexpv8sf_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getexpv8sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getexpv8sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512vl_getexpv4sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_getexpv4sf_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getexpv4sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getexpv4sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512f_getexpv8df (TARGET_AVX512F)
#define HAVE_avx512f_getexpv8df_round (TARGET_AVX512F)
#define HAVE_avx512f_getexpv8df_mask (TARGET_AVX512F)
#define HAVE_avx512f_getexpv8df_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_getexpv4df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_getexpv4df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getexpv4df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getexpv4df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512vl_getexpv2df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_getexpv2df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getexpv2df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getexpv2df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512f_sgetexpv4sf (TARGET_AVX512F)
#define HAVE_avx512f_sgetexpv4sf_round (TARGET_AVX512F)
#define HAVE_avx512f_sgetexpv2df ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_avx512f_sgetexpv2df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_SSE2)))
#define HAVE_avx512f_alignv16si_mask (TARGET_AVX512F)
#define HAVE_avx512vl_alignv8si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_alignv4si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_alignv8di_mask (TARGET_AVX512F)
#define HAVE_avx512vl_alignv4di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_alignv2di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fixupimmv16sf (TARGET_AVX512F)
#define HAVE_avx512f_fixupimmv16sf_round (TARGET_AVX512F)
#define HAVE_avx512f_fixupimmv16sf_maskz_1 (TARGET_AVX512F)
#define HAVE_avx512f_fixupimmv16sf_maskz_1_round (TARGET_AVX512F)
#define HAVE_avx512vl_fixupimmv8sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv8sf_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fixupimmv8sf_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv8sf_maskz_1_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fixupimmv4sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv4sf_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fixupimmv4sf_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv4sf_maskz_1_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fixupimmv8df (TARGET_AVX512F)
#define HAVE_avx512f_fixupimmv8df_round (TARGET_AVX512F)
#define HAVE_avx512f_fixupimmv8df_maskz_1 (TARGET_AVX512F)
#define HAVE_avx512f_fixupimmv8df_maskz_1_round (TARGET_AVX512F)
#define HAVE_avx512vl_fixupimmv4df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv4df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fixupimmv4df_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv4df_maskz_1_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fixupimmv2df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv2df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fixupimmv2df_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv2df_maskz_1_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fixupimmv16sf_mask (TARGET_AVX512F)
#define HAVE_avx512f_fixupimmv16sf_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_fixupimmv8sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv8sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fixupimmv4sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv4sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fixupimmv8df_mask (TARGET_AVX512F)
#define HAVE_avx512f_fixupimmv8df_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_fixupimmv4df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv4df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fixupimmv2df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv2df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_sfixupimmv4sf (TARGET_AVX512F)
#define HAVE_avx512f_sfixupimmv4sf_round (TARGET_AVX512F)
#define HAVE_avx512f_sfixupimmv4sf_maskz_1 (TARGET_AVX512F)
#define HAVE_avx512f_sfixupimmv4sf_maskz_1_round (TARGET_AVX512F)
#define HAVE_avx512f_sfixupimmv2df ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_avx512f_sfixupimmv2df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_SSE2)))
#define HAVE_avx512f_sfixupimmv2df_maskz_1 ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_avx512f_sfixupimmv2df_maskz_1_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_SSE2)))
#define HAVE_avx512f_sfixupimmv4sf_mask (TARGET_AVX512F)
#define HAVE_avx512f_sfixupimmv4sf_mask_round (TARGET_AVX512F)
#define HAVE_avx512f_sfixupimmv2df_mask ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_avx512f_sfixupimmv2df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_SSE2)))
#define HAVE_avx512f_rndscalev16sf (TARGET_AVX512F)
#define HAVE_avx512f_rndscalev16sf_round (TARGET_AVX512F)
#define HAVE_avx512f_rndscalev16sf_mask (TARGET_AVX512F)
#define HAVE_avx512f_rndscalev16sf_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_rndscalev8sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rndscalev8sf_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rndscalev8sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rndscalev8sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512vl_rndscalev4sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rndscalev4sf_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rndscalev4sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rndscalev4sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512f_rndscalev8df (TARGET_AVX512F)
#define HAVE_avx512f_rndscalev8df_round (TARGET_AVX512F)
#define HAVE_avx512f_rndscalev8df_mask (TARGET_AVX512F)
#define HAVE_avx512f_rndscalev8df_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_rndscalev4df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rndscalev4df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rndscalev4df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rndscalev4df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512vl_rndscalev2df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rndscalev2df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rndscalev2df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rndscalev2df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512f_rndscalev4sf (TARGET_AVX512F)
#define HAVE_avx512f_rndscalev4sf_round (TARGET_AVX512F)
#define HAVE_avx512f_rndscalev2df ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_avx512f_rndscalev2df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_SSE2)))
#define HAVE_avx512f_shufps512_1 (TARGET_AVX512F \
   && (INTVAL (operands[3]) == (INTVAL (operands[7]) - 4) \
       && INTVAL (operands[4]) == (INTVAL (operands[8]) - 4) \
       && INTVAL (operands[5]) == (INTVAL (operands[9]) - 4) \
       && INTVAL (operands[6]) == (INTVAL (operands[10]) - 4) \
       && INTVAL (operands[3]) == (INTVAL (operands[11]) - 8) \
       && INTVAL (operands[4]) == (INTVAL (operands[12]) - 8) \
       && INTVAL (operands[5]) == (INTVAL (operands[13]) - 8) \
       && INTVAL (operands[6]) == (INTVAL (operands[14]) - 8) \
       && INTVAL (operands[3]) == (INTVAL (operands[15]) - 12) \
       && INTVAL (operands[4]) == (INTVAL (operands[16]) - 12) \
       && INTVAL (operands[5]) == (INTVAL (operands[17]) - 12) \
       && INTVAL (operands[6]) == (INTVAL (operands[18]) - 12)))
#define HAVE_avx512f_shufps512_1_mask ((TARGET_AVX512F) && (TARGET_AVX512F \
   && (INTVAL (operands[3]) == (INTVAL (operands[7]) - 4) \
       && INTVAL (operands[4]) == (INTVAL (operands[8]) - 4) \
       && INTVAL (operands[5]) == (INTVAL (operands[9]) - 4) \
       && INTVAL (operands[6]) == (INTVAL (operands[10]) - 4) \
       && INTVAL (operands[3]) == (INTVAL (operands[11]) - 8) \
       && INTVAL (operands[4]) == (INTVAL (operands[12]) - 8) \
       && INTVAL (operands[5]) == (INTVAL (operands[13]) - 8) \
       && INTVAL (operands[6]) == (INTVAL (operands[14]) - 8) \
       && INTVAL (operands[3]) == (INTVAL (operands[15]) - 12) \
       && INTVAL (operands[4]) == (INTVAL (operands[16]) - 12) \
       && INTVAL (operands[5]) == (INTVAL (operands[17]) - 12) \
       && INTVAL (operands[6]) == (INTVAL (operands[18]) - 12))))
#define HAVE_avx512f_shufpd512_1 (TARGET_AVX512F)
#define HAVE_avx512f_shufpd512_1_mask (TARGET_AVX512F)
#define HAVE_avx_shufpd256_1 (TARGET_AVX && 1)
#define HAVE_avx_shufpd256_1_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL))
#define HAVE_sse2_shufpd_v2df_mask (TARGET_AVX512VL)
#define HAVE_avx2_interleave_highv4di (TARGET_AVX2 && 1)
#define HAVE_avx2_interleave_highv4di_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_avx512f_interleave_highv8di_mask (TARGET_AVX512F)
#define HAVE_vec_interleave_highv2di (TARGET_SSE2 && 1)
#define HAVE_vec_interleave_highv2di_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL))
#define HAVE_avx2_interleave_lowv4di (TARGET_AVX2 && 1)
#define HAVE_avx2_interleave_lowv4di_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_avx512f_interleave_lowv8di_mask (TARGET_AVX512F)
#define HAVE_vec_interleave_lowv2di (TARGET_SSE2 && 1)
#define HAVE_vec_interleave_lowv2di_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL))
#define HAVE_sse2_shufpd_v2di (TARGET_SSE2)
#define HAVE_sse2_shufpd_v2df (TARGET_SSE2)
#define HAVE_sse2_storehpd (TARGET_SSE2 && !(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_sse2_storelpd (TARGET_SSE2 && !(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_sse2_loadhpd (TARGET_SSE2 && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_sse2_loadlpd (TARGET_SSE2 && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_sse2_movsd (TARGET_SSE2)
#define HAVE_vec_dupv2df (TARGET_SSE2 && 1)
#define HAVE_vec_dupv2df_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL))
#define HAVE_vec_concatv2df (TARGET_SSE \
   && (!(MEM_P (operands[1]) && MEM_P (operands[2])) \
       || (TARGET_SSE3 && rtx_equal_p (operands[1], operands[2]))))
#define HAVE_avx512f_ss_truncatev16siv16qi2_mask (TARGET_AVX512F)
#define HAVE_avx512f_truncatev16siv16qi2_mask (TARGET_AVX512F)
#define HAVE_avx512f_us_truncatev16siv16qi2_mask (TARGET_AVX512F)
#define HAVE_avx512f_ss_truncatev16siv16hi2_mask (TARGET_AVX512F)
#define HAVE_avx512f_truncatev16siv16hi2_mask (TARGET_AVX512F)
#define HAVE_avx512f_us_truncatev16siv16hi2_mask (TARGET_AVX512F)
#define HAVE_avx512f_ss_truncatev8div8si2_mask (TARGET_AVX512F)
#define HAVE_avx512f_truncatev8div8si2_mask (TARGET_AVX512F)
#define HAVE_avx512f_us_truncatev8div8si2_mask (TARGET_AVX512F)
#define HAVE_avx512f_ss_truncatev8div8hi2_mask (TARGET_AVX512F)
#define HAVE_avx512f_truncatev8div8hi2_mask (TARGET_AVX512F)
#define HAVE_avx512f_us_truncatev8div8hi2_mask (TARGET_AVX512F)
#define HAVE_avx512bw_ss_truncatev32hiv32qi2 (TARGET_AVX512BW)
#define HAVE_avx512bw_truncatev32hiv32qi2 (TARGET_AVX512BW)
#define HAVE_avx512bw_us_truncatev32hiv32qi2 (TARGET_AVX512BW)
#define HAVE_avx512bw_ss_truncatev32hiv32qi2_mask (TARGET_AVX512BW)
#define HAVE_avx512bw_truncatev32hiv32qi2_mask (TARGET_AVX512BW)
#define HAVE_avx512bw_us_truncatev32hiv32qi2_mask (TARGET_AVX512BW)
#define HAVE_avx512vl_ss_truncatev4div4si2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev4div4si2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev4div4si2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev8siv8hi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev8siv8hi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev8siv8hi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev16hiv16qi2_mask ((TARGET_AVX512VL) && (TARGET_AVX512BW))
#define HAVE_avx512vl_truncatev16hiv16qi2_mask ((TARGET_AVX512VL) && (TARGET_AVX512BW))
#define HAVE_avx512vl_us_truncatev16hiv16qi2_mask ((TARGET_AVX512VL) && (TARGET_AVX512BW))
#define HAVE_avx512vl_ss_truncatev2div2qi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev2div2qi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev2div2qi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev2div2qi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev2div2qi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev2div2qi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev4siv4qi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev4siv4qi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev4siv4qi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev4div4qi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev4div4qi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev4div4qi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev4siv4qi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev4siv4qi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev4siv4qi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev4div4qi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev4div4qi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev4div4qi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev8hiv8qi2_mask ((TARGET_AVX512VL) && (TARGET_AVX512BW))
#define HAVE_avx512vl_truncatev8hiv8qi2_mask ((TARGET_AVX512VL) && (TARGET_AVX512BW))
#define HAVE_avx512vl_us_truncatev8hiv8qi2_mask ((TARGET_AVX512VL) && (TARGET_AVX512BW))
#define HAVE_avx512vl_ss_truncatev8siv8qi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev8siv8qi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev8siv8qi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev8hiv8qi2_mask_store ((TARGET_AVX512VL) && (TARGET_AVX512BW))
#define HAVE_avx512vl_truncatev8hiv8qi2_mask_store ((TARGET_AVX512VL) && (TARGET_AVX512BW))
#define HAVE_avx512vl_us_truncatev8hiv8qi2_mask_store ((TARGET_AVX512VL) && (TARGET_AVX512BW))
#define HAVE_avx512vl_ss_truncatev8siv8qi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev8siv8qi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev8siv8qi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev4siv4hi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev4siv4hi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev4siv4hi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev4div4hi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev4div4hi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev4div4hi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev4siv4hi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev4siv4hi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev4siv4hi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev4div4hi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev4div4hi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev4div4hi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev2div2hi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev2div2hi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev2div2hi2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev2div2hi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev2div2hi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev2div2hi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev2div2si2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev2div2si2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev2div2si2_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev2div2si2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev2div2si2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev2div2si2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512f_ss_truncatev8div16qi2_mask (TARGET_AVX512F)
#define HAVE_avx512f_truncatev8div16qi2_mask (TARGET_AVX512F)
#define HAVE_avx512f_us_truncatev8div16qi2_mask (TARGET_AVX512F)
#define HAVE_avx512f_ss_truncatev8div16qi2_mask_store (TARGET_AVX512F)
#define HAVE_avx512f_truncatev8div16qi2_mask_store (TARGET_AVX512F)
#define HAVE_avx512f_us_truncatev8div16qi2_mask_store (TARGET_AVX512F)
#define HAVE_avx512bw_pmaddwd512v32hi ((TARGET_AVX512BW && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_pmaddwd512v32hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512BW)))
#define HAVE_avx512bw_pmaddwd512v16hi ((TARGET_AVX512BW && 1) && (TARGET_AVX2))
#define HAVE_avx512bw_pmaddwd512v16hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX2)))
#define HAVE_avx512bw_pmaddwd512v8hi (TARGET_AVX512BW && 1)
#define HAVE_avx512bw_pmaddwd512v8hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_avx512dq_mulv8di3 ((TARGET_AVX512DQ && 1) && (TARGET_AVX512F))
#define HAVE_avx512dq_mulv8di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx512dq_mulv4di3 ((TARGET_AVX512DQ && 1) && (TARGET_AVX))
#define HAVE_avx512dq_mulv4di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX)))
#define HAVE_avx512dq_mulv2di3 (TARGET_AVX512DQ && 1)
#define HAVE_avx512dq_mulv2di3_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_ashrv16hi3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_ashrv8hi3 (TARGET_SSE2)
#define HAVE_ashrv8si3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_ashrv4si3 (TARGET_SSE2)
#define HAVE_ashrv16hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512VL) && (TARGET_AVX512BW)))
#define HAVE_ashrv8hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512VL) && (TARGET_AVX512BW)))
#define HAVE_ashrv8si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_ashrv4si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_ashrv2di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_ashrv32hi3 ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_ashrv32hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512BW)))
#define HAVE_ashrv4di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_ashrv4di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_ashrv16si3 (TARGET_AVX512F)
#define HAVE_ashrv16si3_mask (TARGET_AVX512F)
#define HAVE_ashrv8di3 (TARGET_AVX512F)
#define HAVE_ashrv8di3_mask (TARGET_AVX512F)
#define HAVE_ashlv32hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_ashlv32hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_lshrv32hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_lshrv32hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_ashlv16hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_ashlv16hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_lshrv16hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_lshrv16hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_ashlv8hi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_ashlv8hi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_lshrv8hi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_lshrv8hi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_ashlv8si3 ((TARGET_SSE2 && 1) && (TARGET_AVX2))
#define HAVE_ashlv8si3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX2)))
#define HAVE_lshrv8si3 ((TARGET_SSE2 && 1) && (TARGET_AVX2))
#define HAVE_lshrv8si3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX2)))
#define HAVE_ashlv4si3 (TARGET_SSE2 && 1)
#define HAVE_ashlv4si3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_lshrv4si3 (TARGET_SSE2 && 1)
#define HAVE_lshrv4si3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_ashlv4di3 ((TARGET_SSE2 && 1) && (TARGET_AVX2))
#define HAVE_ashlv4di3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX2)))
#define HAVE_lshrv4di3 ((TARGET_SSE2 && 1) && (TARGET_AVX2))
#define HAVE_lshrv4di3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX2)))
#define HAVE_ashlv2di3 (TARGET_SSE2 && 1)
#define HAVE_ashlv2di3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_lshrv2di3 (TARGET_SSE2 && 1)
#define HAVE_lshrv2di3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_ashlv16si3 (TARGET_AVX512F && 1)
#define HAVE_ashlv16si3_mask ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL)))
#define HAVE_lshrv16si3 (TARGET_AVX512F && 1)
#define HAVE_lshrv16si3_mask ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL)))
#define HAVE_ashlv8di3 (TARGET_AVX512F && 1)
#define HAVE_ashlv8di3_mask ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL)))
#define HAVE_lshrv8di3 (TARGET_AVX512F && 1)
#define HAVE_lshrv8di3_mask ((TARGET_AVX512F) && (TARGET_AVX512F && (64 == 64 || TARGET_AVX512VL)))
#define HAVE_avx512bw_ashlv4ti3 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_avx2_ashlv2ti3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_sse2_ashlv1ti3 (TARGET_SSE2)
#define HAVE_avx512bw_lshrv4ti3 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_avx2_lshrv2ti3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_sse2_lshrv1ti3 (TARGET_SSE2)
#define HAVE_avx512f_rolvv16si (TARGET_AVX512F)
#define HAVE_avx512f_rolvv16si_mask (TARGET_AVX512F)
#define HAVE_avx512f_rorvv16si (TARGET_AVX512F)
#define HAVE_avx512f_rorvv16si_mask (TARGET_AVX512F)
#define HAVE_avx512vl_rolvv8si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rolvv8si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rorvv8si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rorvv8si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rolvv4si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rolvv4si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rorvv4si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rorvv4si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_rolvv8di (TARGET_AVX512F)
#define HAVE_avx512f_rolvv8di_mask (TARGET_AVX512F)
#define HAVE_avx512f_rorvv8di (TARGET_AVX512F)
#define HAVE_avx512f_rorvv8di_mask (TARGET_AVX512F)
#define HAVE_avx512vl_rolvv4di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rolvv4di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rorvv4di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rorvv4di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rolvv2di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rolvv2di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rorvv2di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rorvv2di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_rolv16si (TARGET_AVX512F)
#define HAVE_avx512f_rolv16si_mask (TARGET_AVX512F)
#define HAVE_avx512f_rorv16si (TARGET_AVX512F)
#define HAVE_avx512f_rorv16si_mask (TARGET_AVX512F)
#define HAVE_avx512vl_rolv8si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rolv8si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rorv8si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rorv8si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rolv4si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rolv4si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rorv4si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rorv4si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_rolv8di (TARGET_AVX512F)
#define HAVE_avx512f_rolv8di_mask (TARGET_AVX512F)
#define HAVE_avx512f_rorv8di (TARGET_AVX512F)
#define HAVE_avx512f_rorv8di_mask (TARGET_AVX512F)
#define HAVE_avx512vl_rolv4di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rolv4di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rorv4di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rorv4di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rolv2di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rolv2di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_rorv2di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_rorv2di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_smaxv64qi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_sminv64qi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_umaxv64qi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_uminv64qi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_smaxv16qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_sminv16qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_umaxv16qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_uminv16qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_smaxv32qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_sminv32qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_umaxv32qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_uminv32qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_smaxv32hi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_sminv32hi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_umaxv32hi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_uminv32hi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_smaxv16hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_sminv16hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_umaxv16hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_uminv16hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_smaxv8hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_sminv8hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_umaxv8hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_uminv8hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_eqv64qi3_1 (TARGET_AVX512F && ix86_binary_operator_ok (EQ, V64QImode, operands))
#define HAVE_avx512bw_eqv64qi3_mask_1 ((TARGET_AVX512F) && (TARGET_AVX512F && ix86_binary_operator_ok (EQ, V64QImode, operands)))
#define HAVE_avx512vl_eqv16qi3_1 ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V16QImode, operands)) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv16qi3_mask_1 ((TARGET_AVX512F) && ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V16QImode, operands)) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_eqv32qi3_1 ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V32QImode, operands)) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv32qi3_mask_1 ((TARGET_AVX512F) && ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V32QImode, operands)) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_eqv32hi3_1 (TARGET_AVX512F && ix86_binary_operator_ok (EQ, V32HImode, operands))
#define HAVE_avx512bw_eqv32hi3_mask_1 ((TARGET_AVX512F) && (TARGET_AVX512F && ix86_binary_operator_ok (EQ, V32HImode, operands)))
#define HAVE_avx512vl_eqv16hi3_1 ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V16HImode, operands)) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv16hi3_mask_1 ((TARGET_AVX512F) && ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V16HImode, operands)) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_eqv8hi3_1 ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V8HImode, operands)) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv8hi3_mask_1 ((TARGET_AVX512F) && ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V8HImode, operands)) && (TARGET_AVX512VL)))
#define HAVE_avx512f_eqv16si3_1 (TARGET_AVX512F && ix86_binary_operator_ok (EQ, V16SImode, operands))
#define HAVE_avx512f_eqv16si3_mask_1 ((TARGET_AVX512F) && (TARGET_AVX512F && ix86_binary_operator_ok (EQ, V16SImode, operands)))
#define HAVE_avx512vl_eqv8si3_1 ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V8SImode, operands)) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv8si3_mask_1 ((TARGET_AVX512F) && ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V8SImode, operands)) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_eqv4si3_1 ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V4SImode, operands)) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv4si3_mask_1 ((TARGET_AVX512F) && ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V4SImode, operands)) && (TARGET_AVX512VL)))
#define HAVE_avx512f_eqv8di3_1 (TARGET_AVX512F && ix86_binary_operator_ok (EQ, V8DImode, operands))
#define HAVE_avx512f_eqv8di3_mask_1 ((TARGET_AVX512F) && (TARGET_AVX512F && ix86_binary_operator_ok (EQ, V8DImode, operands)))
#define HAVE_avx512vl_eqv4di3_1 ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V4DImode, operands)) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv4di3_mask_1 ((TARGET_AVX512F) && ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V4DImode, operands)) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_eqv2di3_1 ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V2DImode, operands)) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv2di3_mask_1 ((TARGET_AVX512F) && ((TARGET_AVX512F && ix86_binary_operator_ok (EQ, V2DImode, operands)) && (TARGET_AVX512VL)))
#define HAVE_sse4_2_gtv2di3 (TARGET_SSE4_2)
#define HAVE_avx2_gtv32qi3 (TARGET_AVX2)
#define HAVE_avx2_gtv16hi3 (TARGET_AVX2)
#define HAVE_avx2_gtv8si3 (TARGET_AVX2)
#define HAVE_avx2_gtv4di3 (TARGET_AVX2)
#define HAVE_avx512f_gtv16si3 (TARGET_AVX512F)
#define HAVE_avx512f_gtv16si3_mask (TARGET_AVX512F)
#define HAVE_avx512vl_gtv8si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gtv8si3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_gtv4si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gtv4si3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_gtv8di3 (TARGET_AVX512F)
#define HAVE_avx512f_gtv8di3_mask (TARGET_AVX512F)
#define HAVE_avx512vl_gtv4di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gtv4di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_gtv2di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gtv2di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_gtv64qi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_gtv64qi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_gtv16qi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gtv16qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_gtv32qi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gtv32qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_gtv32hi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_gtv32hi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_gtv16hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gtv16hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_gtv8hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gtv8hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_sse2_gtv16qi3 (TARGET_SSE2 && !TARGET_XOP)
#define HAVE_sse2_gtv8hi3 (TARGET_SSE2 && !TARGET_XOP)
#define HAVE_sse2_gtv4si3 (TARGET_SSE2 && !TARGET_XOP)
#define HAVE_andv16si3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (AND, V16SImode, operands)) && (TARGET_AVX512F)))
#define HAVE_iorv16si3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (IOR, V16SImode, operands)) && (TARGET_AVX512F)))
#define HAVE_xorv16si3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (XOR, V16SImode, operands)) && (TARGET_AVX512F)))
#define HAVE_andv8si3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (AND, V8SImode, operands)) && (TARGET_AVX)))
#define HAVE_iorv8si3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (IOR, V8SImode, operands)) && (TARGET_AVX)))
#define HAVE_xorv8si3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (XOR, V8SImode, operands)) && (TARGET_AVX)))
#define HAVE_andv4si3_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (AND, V4SImode, operands)))
#define HAVE_iorv4si3_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (IOR, V4SImode, operands)))
#define HAVE_xorv4si3_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (XOR, V4SImode, operands)))
#define HAVE_andv8di3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (AND, V8DImode, operands)) && (TARGET_AVX512F)))
#define HAVE_iorv8di3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (IOR, V8DImode, operands)) && (TARGET_AVX512F)))
#define HAVE_xorv8di3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (XOR, V8DImode, operands)) && (TARGET_AVX512F)))
#define HAVE_andv4di3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (AND, V4DImode, operands)) && (TARGET_AVX)))
#define HAVE_iorv4di3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (IOR, V4DImode, operands)) && (TARGET_AVX)))
#define HAVE_xorv4di3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (XOR, V4DImode, operands)) && (TARGET_AVX)))
#define HAVE_andv2di3_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (AND, V2DImode, operands)))
#define HAVE_iorv2di3_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (IOR, V2DImode, operands)))
#define HAVE_xorv2di3_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL) \
   && ix86_binary_operator_ok (XOR, V2DImode, operands)))
#define HAVE_avx512bw_testmv64qi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_testmv64qi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_testmv16qi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testmv16qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_testmv32qi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testmv32qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_testmv32hi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_testmv32hi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_testmv16hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testmv16hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_testmv8hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testmv8hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512f_testmv16si3 (TARGET_AVX512F)
#define HAVE_avx512f_testmv16si3_mask (TARGET_AVX512F)
#define HAVE_avx512vl_testmv8si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testmv8si3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_testmv4si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testmv4si3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_testmv8di3 (TARGET_AVX512F)
#define HAVE_avx512f_testmv8di3_mask (TARGET_AVX512F)
#define HAVE_avx512vl_testmv4di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testmv4di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_testmv2di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testmv2di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_testnmv64qi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_testnmv64qi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_testnmv16qi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testnmv16qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_testnmv32qi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testnmv32qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_testnmv32hi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_testnmv32hi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_testnmv16hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testnmv16hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_testnmv8hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testnmv8hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512f_testnmv16si3 (TARGET_AVX512F)
#define HAVE_avx512f_testnmv16si3_mask (TARGET_AVX512F)
#define HAVE_avx512vl_testnmv8si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testnmv8si3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_testnmv4si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testnmv4si3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_testnmv8di3 (TARGET_AVX512F)
#define HAVE_avx512f_testnmv8di3_mask (TARGET_AVX512F)
#define HAVE_avx512vl_testnmv4di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testnmv4di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_testnmv2di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_testnmv2di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_packsswb ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_packsswb_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx2_packsswb ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_packsswb_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_sse2_packsswb (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_packsswb_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_avx512bw_packssdw ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_packssdw_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx2_packssdw ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_packssdw_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_sse2_packssdw (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_packssdw_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_avx512bw_packuswb ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_packuswb_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx2_packuswb ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_packuswb_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_sse2_packuswb (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_packuswb_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_avx512bw_interleave_highv64qi (TARGET_AVX512BW)
#define HAVE_avx512bw_interleave_highv64qi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx2_interleave_highv32qi (TARGET_AVX2 && 1)
#define HAVE_avx2_interleave_highv32qi_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_vec_interleave_highv16qi (TARGET_SSE2 && 1)
#define HAVE_vec_interleave_highv16qi_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL))
#define HAVE_avx512bw_interleave_lowv64qi (TARGET_AVX512BW)
#define HAVE_avx512bw_interleave_lowv64qi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx2_interleave_lowv32qi (TARGET_AVX2 && 1 && 1)
#define HAVE_avx2_interleave_lowv32qi_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL && TARGET_AVX512BW))
#define HAVE_vec_interleave_lowv16qi (TARGET_SSE2 && 1 && 1)
#define HAVE_vec_interleave_lowv16qi_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL && TARGET_AVX512BW))
#define HAVE_avx512bw_interleave_highv32hi (TARGET_AVX512BW)
#define HAVE_avx512bw_interleave_highv32hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx2_interleave_highv16hi (TARGET_AVX2 && 1 && 1)
#define HAVE_avx2_interleave_highv16hi_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL && TARGET_AVX512BW))
#define HAVE_vec_interleave_highv8hi (TARGET_SSE2 && 1 && 1)
#define HAVE_vec_interleave_highv8hi_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL && TARGET_AVX512BW))
#define HAVE_avx512bw_interleave_lowv32hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx2_interleave_lowv16hi (TARGET_AVX2 && 1 && 1)
#define HAVE_avx2_interleave_lowv16hi_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL && TARGET_AVX512BW))
#define HAVE_vec_interleave_lowv8hi (TARGET_SSE2 && 1 && 1)
#define HAVE_vec_interleave_lowv8hi_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL && TARGET_AVX512BW))
#define HAVE_avx2_interleave_highv8si (TARGET_AVX2 && 1)
#define HAVE_avx2_interleave_highv8si_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_avx512f_interleave_highv16si_mask (TARGET_AVX512F)
#define HAVE_vec_interleave_highv4si (TARGET_SSE2 && 1)
#define HAVE_vec_interleave_highv4si_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL))
#define HAVE_avx2_interleave_lowv8si (TARGET_AVX2 && 1)
#define HAVE_avx2_interleave_lowv8si_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_avx512f_interleave_lowv16si_mask (TARGET_AVX512F)
#define HAVE_vec_interleave_lowv4si (TARGET_SSE2 && 1)
#define HAVE_vec_interleave_lowv4si_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL))
#define HAVE_sse4_1_pinsrb ((TARGET_SSE2 \
   && ((unsigned) exact_log2 (INTVAL (operands[3])) \
       < GET_MODE_NUNITS (V16QImode))) && (TARGET_SSE4_1))
#define HAVE_sse2_pinsrw (TARGET_SSE2 \
   && ((unsigned) exact_log2 (INTVAL (operands[3])) \
       < GET_MODE_NUNITS (V8HImode)))
#define HAVE_sse4_1_pinsrd ((TARGET_SSE2 \
   && ((unsigned) exact_log2 (INTVAL (operands[3])) \
       < GET_MODE_NUNITS (V4SImode))) && (TARGET_SSE4_1))
#define HAVE_sse4_1_pinsrq ((TARGET_SSE2 \
   && ((unsigned) exact_log2 (INTVAL (operands[3])) \
       < GET_MODE_NUNITS (V2DImode))) && (TARGET_SSE4_1 && TARGET_64BIT))
#define HAVE_avx512dq_vinsertf64x2_1_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ)))
#define HAVE_avx512dq_vinserti64x2_1_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ)))
#define HAVE_avx512f_vinsertf32x4_1_mask (TARGET_AVX512F)
#define HAVE_avx512f_vinserti32x4_1_mask (TARGET_AVX512F)
#define HAVE_vec_set_lo_v16sf (TARGET_AVX512DQ)
#define HAVE_vec_set_lo_v16sf_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_vec_set_lo_v16si (TARGET_AVX512DQ)
#define HAVE_vec_set_lo_v16si_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_vec_set_hi_v16sf (TARGET_AVX512DQ)
#define HAVE_vec_set_hi_v16sf_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_vec_set_hi_v16si (TARGET_AVX512DQ)
#define HAVE_vec_set_hi_v16si_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_vec_set_lo_v8df (TARGET_AVX512F)
#define HAVE_vec_set_lo_v8df_mask (TARGET_AVX512F)
#define HAVE_vec_set_lo_v8di (TARGET_AVX512F)
#define HAVE_vec_set_lo_v8di_mask (TARGET_AVX512F)
#define HAVE_vec_set_hi_v8df (TARGET_AVX512F)
#define HAVE_vec_set_hi_v8df_mask (TARGET_AVX512F)
#define HAVE_vec_set_hi_v8di (TARGET_AVX512F)
#define HAVE_vec_set_hi_v8di_mask (TARGET_AVX512F)
#define HAVE_avx512dq_shuf_i64x2_1_mask ((TARGET_AVX512F) && (TARGET_AVX512VL \
   && (INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[5]) == (INTVAL (operands[6]) - 1))))
#define HAVE_avx512dq_shuf_f64x2_1_mask ((TARGET_AVX512F) && (TARGET_AVX512VL \
   && (INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[5]) == (INTVAL (operands[6]) - 1))))
#define HAVE_avx512f_shuf_f64x2_1 (TARGET_AVX512F \
   && (INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[5]) == (INTVAL (operands[6]) - 1) \
       && INTVAL (operands[7]) == (INTVAL (operands[8]) - 1) \
       && INTVAL (operands[9]) == (INTVAL (operands[10]) - 1)))
#define HAVE_avx512f_shuf_f64x2_1_mask ((TARGET_AVX512F) && (TARGET_AVX512F \
   && (INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[5]) == (INTVAL (operands[6]) - 1) \
       && INTVAL (operands[7]) == (INTVAL (operands[8]) - 1) \
       && INTVAL (operands[9]) == (INTVAL (operands[10]) - 1))))
#define HAVE_avx512f_shuf_i64x2_1 (TARGET_AVX512F \
   && (INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[5]) == (INTVAL (operands[6]) - 1) \
       && INTVAL (operands[7]) == (INTVAL (operands[8]) - 1) \
       && INTVAL (operands[9]) == (INTVAL (operands[10]) - 1)))
#define HAVE_avx512f_shuf_i64x2_1_mask ((TARGET_AVX512F) && (TARGET_AVX512F \
   && (INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[5]) == (INTVAL (operands[6]) - 1) \
       && INTVAL (operands[7]) == (INTVAL (operands[8]) - 1) \
       && INTVAL (operands[9]) == (INTVAL (operands[10]) - 1))))
#define HAVE_avx512vl_shuf_i32x4_1_mask ((TARGET_AVX512F) && (TARGET_AVX512VL \
   && (INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[3]) == (INTVAL (operands[5]) - 2) \
       && INTVAL (operands[3]) == (INTVAL (operands[6]) - 3) \
       && INTVAL (operands[7]) == (INTVAL (operands[8]) - 1) \
       && INTVAL (operands[7]) == (INTVAL (operands[9]) - 2) \
       && INTVAL (operands[7]) == (INTVAL (operands[10]) - 3))))
#define HAVE_avx512vl_shuf_f32x4_1_mask ((TARGET_AVX512F) && (TARGET_AVX512VL \
   && (INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[3]) == (INTVAL (operands[5]) - 2) \
       && INTVAL (operands[3]) == (INTVAL (operands[6]) - 3) \
       && INTVAL (operands[7]) == (INTVAL (operands[8]) - 1) \
       && INTVAL (operands[7]) == (INTVAL (operands[9]) - 2) \
       && INTVAL (operands[7]) == (INTVAL (operands[10]) - 3))))
#define HAVE_avx512f_shuf_f32x4_1 (TARGET_AVX512F \
   && (INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[3]) == (INTVAL (operands[5]) - 2) \
       && INTVAL (operands[3]) == (INTVAL (operands[6]) - 3) \
       && INTVAL (operands[7]) == (INTVAL (operands[8]) - 1) \
       && INTVAL (operands[7]) == (INTVAL (operands[9]) - 2) \
       && INTVAL (operands[7]) == (INTVAL (operands[10]) - 3) \
       && INTVAL (operands[11]) == (INTVAL (operands[12]) - 1) \
       && INTVAL (operands[11]) == (INTVAL (operands[13]) - 2) \
       && INTVAL (operands[11]) == (INTVAL (operands[14]) - 3) \
       && INTVAL (operands[15]) == (INTVAL (operands[16]) - 1) \
       && INTVAL (operands[15]) == (INTVAL (operands[17]) - 2) \
       && INTVAL (operands[15]) == (INTVAL (operands[18]) - 3)))
#define HAVE_avx512f_shuf_f32x4_1_mask ((TARGET_AVX512F) && (TARGET_AVX512F \
   && (INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[3]) == (INTVAL (operands[5]) - 2) \
       && INTVAL (operands[3]) == (INTVAL (operands[6]) - 3) \
       && INTVAL (operands[7]) == (INTVAL (operands[8]) - 1) \
       && INTVAL (operands[7]) == (INTVAL (operands[9]) - 2) \
       && INTVAL (operands[7]) == (INTVAL (operands[10]) - 3) \
       && INTVAL (operands[11]) == (INTVAL (operands[12]) - 1) \
       && INTVAL (operands[11]) == (INTVAL (operands[13]) - 2) \
       && INTVAL (operands[11]) == (INTVAL (operands[14]) - 3) \
       && INTVAL (operands[15]) == (INTVAL (operands[16]) - 1) \
       && INTVAL (operands[15]) == (INTVAL (operands[17]) - 2) \
       && INTVAL (operands[15]) == (INTVAL (operands[18]) - 3))))
#define HAVE_avx512f_shuf_i32x4_1 (TARGET_AVX512F \
   && (INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[3]) == (INTVAL (operands[5]) - 2) \
       && INTVAL (operands[3]) == (INTVAL (operands[6]) - 3) \
       && INTVAL (operands[7]) == (INTVAL (operands[8]) - 1) \
       && INTVAL (operands[7]) == (INTVAL (operands[9]) - 2) \
       && INTVAL (operands[7]) == (INTVAL (operands[10]) - 3) \
       && INTVAL (operands[11]) == (INTVAL (operands[12]) - 1) \
       && INTVAL (operands[11]) == (INTVAL (operands[13]) - 2) \
       && INTVAL (operands[11]) == (INTVAL (operands[14]) - 3) \
       && INTVAL (operands[15]) == (INTVAL (operands[16]) - 1) \
       && INTVAL (operands[15]) == (INTVAL (operands[17]) - 2) \
       && INTVAL (operands[15]) == (INTVAL (operands[18]) - 3)))
#define HAVE_avx512f_shuf_i32x4_1_mask ((TARGET_AVX512F) && (TARGET_AVX512F \
   && (INTVAL (operands[3]) == (INTVAL (operands[4]) - 1) \
       && INTVAL (operands[3]) == (INTVAL (operands[5]) - 2) \
       && INTVAL (operands[3]) == (INTVAL (operands[6]) - 3) \
       && INTVAL (operands[7]) == (INTVAL (operands[8]) - 1) \
       && INTVAL (operands[7]) == (INTVAL (operands[9]) - 2) \
       && INTVAL (operands[7]) == (INTVAL (operands[10]) - 3) \
       && INTVAL (operands[11]) == (INTVAL (operands[12]) - 1) \
       && INTVAL (operands[11]) == (INTVAL (operands[13]) - 2) \
       && INTVAL (operands[11]) == (INTVAL (operands[14]) - 3) \
       && INTVAL (operands[15]) == (INTVAL (operands[16]) - 1) \
       && INTVAL (operands[15]) == (INTVAL (operands[17]) - 2) \
       && INTVAL (operands[15]) == (INTVAL (operands[18]) - 3))))
#define HAVE_avx512f_pshufd_1 (TARGET_AVX512F \
   && INTVAL (operands[2]) + 4 == INTVAL (operands[6]) \
   && INTVAL (operands[3]) + 4 == INTVAL (operands[7]) \
   && INTVAL (operands[4]) + 4 == INTVAL (operands[8]) \
   && INTVAL (operands[5]) + 4 == INTVAL (operands[9]) \
   && INTVAL (operands[2]) + 8 == INTVAL (operands[10]) \
   && INTVAL (operands[3]) + 8 == INTVAL (operands[11]) \
   && INTVAL (operands[4]) + 8 == INTVAL (operands[12]) \
   && INTVAL (operands[5]) + 8 == INTVAL (operands[13]) \
   && INTVAL (operands[2]) + 12 == INTVAL (operands[14]) \
   && INTVAL (operands[3]) + 12 == INTVAL (operands[15]) \
   && INTVAL (operands[4]) + 12 == INTVAL (operands[16]) \
   && INTVAL (operands[5]) + 12 == INTVAL (operands[17]))
#define HAVE_avx512f_pshufd_1_mask ((TARGET_AVX512F) && (TARGET_AVX512F \
   && INTVAL (operands[2]) + 4 == INTVAL (operands[6]) \
   && INTVAL (operands[3]) + 4 == INTVAL (operands[7]) \
   && INTVAL (operands[4]) + 4 == INTVAL (operands[8]) \
   && INTVAL (operands[5]) + 4 == INTVAL (operands[9]) \
   && INTVAL (operands[2]) + 8 == INTVAL (operands[10]) \
   && INTVAL (operands[3]) + 8 == INTVAL (operands[11]) \
   && INTVAL (operands[4]) + 8 == INTVAL (operands[12]) \
   && INTVAL (operands[5]) + 8 == INTVAL (operands[13]) \
   && INTVAL (operands[2]) + 12 == INTVAL (operands[14]) \
   && INTVAL (operands[3]) + 12 == INTVAL (operands[15]) \
   && INTVAL (operands[4]) + 12 == INTVAL (operands[16]) \
   && INTVAL (operands[5]) + 12 == INTVAL (operands[17])))
#define HAVE_avx2_pshufd_1 (TARGET_AVX2 \
   && 1 \
   && INTVAL (operands[2]) + 4 == INTVAL (operands[6]) \
   && INTVAL (operands[3]) + 4 == INTVAL (operands[7]) \
   && INTVAL (operands[4]) + 4 == INTVAL (operands[8]) \
   && INTVAL (operands[5]) + 4 == INTVAL (operands[9]))
#define HAVE_avx2_pshufd_1_mask ((TARGET_AVX512F) && (TARGET_AVX2 \
   && TARGET_AVX512VL \
   && INTVAL (operands[2]) + 4 == INTVAL (operands[6]) \
   && INTVAL (operands[3]) + 4 == INTVAL (operands[7]) \
   && INTVAL (operands[4]) + 4 == INTVAL (operands[8]) \
   && INTVAL (operands[5]) + 4 == INTVAL (operands[9])))
#define HAVE_sse2_pshufd_1 (TARGET_SSE2 && 1)
#define HAVE_sse2_pshufd_1_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL))
#define HAVE_avx512bw_pshuflwv32hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx2_pshuflw_1 (TARGET_AVX2 \
   && 1 && 1 \
   && INTVAL (operands[2]) + 8 == INTVAL (operands[6]) \
   && INTVAL (operands[3]) + 8 == INTVAL (operands[7]) \
   && INTVAL (operands[4]) + 8 == INTVAL (operands[8]) \
   && INTVAL (operands[5]) + 8 == INTVAL (operands[9]))
#define HAVE_avx2_pshuflw_1_mask ((TARGET_AVX512F) && (TARGET_AVX2 \
   && TARGET_AVX512BW && TARGET_AVX512VL \
   && INTVAL (operands[2]) + 8 == INTVAL (operands[6]) \
   && INTVAL (operands[3]) + 8 == INTVAL (operands[7]) \
   && INTVAL (operands[4]) + 8 == INTVAL (operands[8]) \
   && INTVAL (operands[5]) + 8 == INTVAL (operands[9])))
#define HAVE_sse2_pshuflw_1 (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_pshuflw_1_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512BW && TARGET_AVX512VL))
#define HAVE_avx512bw_pshufhwv32hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx2_pshufhw_1 (TARGET_AVX2 \
   && 1 && 1 \
   && INTVAL (operands[2]) + 8 == INTVAL (operands[6]) \
   && INTVAL (operands[3]) + 8 == INTVAL (operands[7]) \
   && INTVAL (operands[4]) + 8 == INTVAL (operands[8]) \
   && INTVAL (operands[5]) + 8 == INTVAL (operands[9]))
#define HAVE_avx2_pshufhw_1_mask ((TARGET_AVX512F) && (TARGET_AVX2 \
   && TARGET_AVX512BW && TARGET_AVX512VL \
   && INTVAL (operands[2]) + 8 == INTVAL (operands[6]) \
   && INTVAL (operands[3]) + 8 == INTVAL (operands[7]) \
   && INTVAL (operands[4]) + 8 == INTVAL (operands[8]) \
   && INTVAL (operands[5]) + 8 == INTVAL (operands[9])))
#define HAVE_sse2_pshufhw_1 (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_pshufhw_1_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512BW && TARGET_AVX512VL))
#define HAVE_sse2_loadld (TARGET_SSE)
#define HAVE_vec_concatv2di (TARGET_SSE)
#define HAVE_avx512f_psadbw ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_avx2_psadbw ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_sse2_psadbw (TARGET_SSE2)
#define HAVE_avx_movmskps256 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_sse_movmskps (TARGET_SSE)
#define HAVE_avx_movmskpd256 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_sse2_movmskpd ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_avx2_pmovmskb ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_sse2_pmovmskb (TARGET_SSE2)
#define HAVE_sse_ldmxcsr (TARGET_SSE)
#define HAVE_sse_stmxcsr (TARGET_SSE)
#define HAVE_sse2_clflush (TARGET_SSE2)
#define HAVE_sse3_mwait (TARGET_SSE3)
#define HAVE_sse3_monitor_si ((TARGET_SSE3) && (Pmode == SImode))
#define HAVE_sse3_monitor_di ((TARGET_SSE3) && (Pmode == DImode))
#define HAVE_avx2_phaddwv16hi3 (TARGET_AVX2)
#define HAVE_avx2_phaddswv16hi3 (TARGET_AVX2)
#define HAVE_avx2_phsubwv16hi3 (TARGET_AVX2)
#define HAVE_avx2_phsubswv16hi3 (TARGET_AVX2)
#define HAVE_ssse3_phaddwv8hi3 (TARGET_SSSE3)
#define HAVE_ssse3_phaddswv8hi3 (TARGET_SSSE3)
#define HAVE_ssse3_phsubwv8hi3 (TARGET_SSSE3)
#define HAVE_ssse3_phsubswv8hi3 (TARGET_SSSE3)
#define HAVE_ssse3_phaddwv4hi3 (TARGET_SSSE3)
#define HAVE_ssse3_phaddswv4hi3 (TARGET_SSSE3)
#define HAVE_ssse3_phsubwv4hi3 (TARGET_SSSE3)
#define HAVE_ssse3_phsubswv4hi3 (TARGET_SSSE3)
#define HAVE_avx2_phadddv8si3 (TARGET_AVX2)
#define HAVE_avx2_phsubdv8si3 (TARGET_AVX2)
#define HAVE_ssse3_phadddv4si3 (TARGET_SSSE3)
#define HAVE_ssse3_phsubdv4si3 (TARGET_SSSE3)
#define HAVE_ssse3_phadddv2si3 (TARGET_SSSE3)
#define HAVE_ssse3_phsubdv2si3 (TARGET_SSSE3)
#define HAVE_avx2_pmaddubsw256 (TARGET_AVX2)
#define HAVE_avx512bw_pmaddubsw512v8hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_pmaddubsw512v8hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_pmaddubsw512v16hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_pmaddubsw512v16hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_pmaddubsw512v32hi (TARGET_AVX512BW)
#define HAVE_avx512bw_pmaddubsw512v32hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512bw_umulhrswv32hi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_umulhrswv32hi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_ssse3_pmaddubsw128 (TARGET_SSSE3)
#define HAVE_ssse3_pmaddubsw (TARGET_SSSE3)
#define HAVE_avx512bw_pshufbv64qi3 ((TARGET_SSSE3 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_pshufbv64qi3_mask ((TARGET_AVX512F) && ((TARGET_SSSE3 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx2_pshufbv32qi3 ((TARGET_SSSE3 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_pshufbv32qi3_mask ((TARGET_AVX512F) && ((TARGET_SSSE3 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_ssse3_pshufbv16qi3 (TARGET_SSSE3 && 1 && 1)
#define HAVE_ssse3_pshufbv16qi3_mask ((TARGET_AVX512F) && (TARGET_SSSE3 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_ssse3_pshufbv8qi3 (TARGET_SSSE3)
#define HAVE_avx2_psignv32qi3 ((TARGET_SSSE3) && (TARGET_AVX2))
#define HAVE_ssse3_psignv16qi3 (TARGET_SSSE3)
#define HAVE_avx2_psignv16hi3 ((TARGET_SSSE3) && (TARGET_AVX2))
#define HAVE_ssse3_psignv8hi3 (TARGET_SSSE3)
#define HAVE_avx2_psignv8si3 ((TARGET_SSSE3) && (TARGET_AVX2))
#define HAVE_ssse3_psignv4si3 (TARGET_SSSE3)
#define HAVE_ssse3_psignv8qi3 (TARGET_SSSE3)
#define HAVE_ssse3_psignv4hi3 (TARGET_SSSE3)
#define HAVE_ssse3_psignv2si3 (TARGET_SSSE3)
#define HAVE_avx512bw_palignrv64qi_mask ((TARGET_AVX512BW && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512BW))
#define HAVE_avx2_palignrv32qi_mask ((TARGET_AVX512BW && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX2))
#define HAVE_ssse3_palignrv16qi_mask (TARGET_AVX512BW && (16 == 64 || TARGET_AVX512VL))
#define HAVE_avx512bw_palignrv4ti ((TARGET_SSSE3) && (TARGET_AVX512BW))
#define HAVE_avx2_palignrv2ti ((TARGET_SSSE3) && (TARGET_AVX2))
#define HAVE_ssse3_palignrti (TARGET_SSSE3)
#define HAVE_ssse3_palignrdi (TARGET_SSSE3)
#define HAVE_absv16si2_mask (TARGET_AVX512F)
#define HAVE_absv8si2_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_absv4si2_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_absv8di2_mask (TARGET_AVX512F)
#define HAVE_absv4di2_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_absv2di2_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_absv64qi2_mask (TARGET_AVX512BW)
#define HAVE_absv16qi2_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_absv32qi2_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_absv32hi2_mask (TARGET_AVX512BW)
#define HAVE_absv16hi2_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_absv8hi2_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_absv8qi2 (TARGET_SSSE3)
#define HAVE_absv4hi2 (TARGET_SSSE3)
#define HAVE_absv2si2 (TARGET_SSSE3)
#define HAVE_sse4a_movntsf (TARGET_SSE4A)
#define HAVE_sse4a_movntdf (TARGET_SSE4A)
#define HAVE_sse4a_vmmovntv4sf (TARGET_SSE4A)
#define HAVE_sse4a_vmmovntv2df ((TARGET_SSE4A) && (TARGET_SSE2))
#define HAVE_sse4a_extrqi (TARGET_SSE4A)
#define HAVE_sse4a_extrq (TARGET_SSE4A)
#define HAVE_sse4a_insertqi (TARGET_SSE4A)
#define HAVE_sse4a_insertq (TARGET_SSE4A)
#define HAVE_avx_blendps256 ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_sse4_1_blendps (TARGET_SSE4_1)
#define HAVE_avx_blendpd256 ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_sse4_1_blendpd ((TARGET_SSE4_1) && (TARGET_SSE2))
#define HAVE_avx_blendvps256 ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_sse4_1_blendvps (TARGET_SSE4_1)
#define HAVE_avx_blendvpd256 ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_sse4_1_blendvpd ((TARGET_SSE4_1) && (TARGET_SSE2))
#define HAVE_avx_dpps256 ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_sse4_1_dpps (TARGET_SSE4_1)
#define HAVE_avx_dppd256 ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_sse4_1_dppd ((TARGET_SSE4_1) && (TARGET_SSE2))
#define HAVE_avx512f_movntdqa ((TARGET_SSE4_1) && (TARGET_AVX512F))
#define HAVE_avx2_movntdqa ((TARGET_SSE4_1) && (TARGET_AVX2))
#define HAVE_sse4_1_movntdqa (TARGET_SSE4_1)
#define HAVE_avx2_mpsadbw ((TARGET_SSE4_1) && (TARGET_AVX2))
#define HAVE_sse4_1_mpsadbw (TARGET_SSE4_1)
#define HAVE_avx512bw_packusdw ((TARGET_SSE4_1 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_packusdw_mask ((TARGET_AVX512F) && ((TARGET_SSE4_1 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx2_packusdw ((TARGET_SSE4_1 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_packusdw_mask ((TARGET_AVX512F) && ((TARGET_SSE4_1 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_sse4_1_packusdw (TARGET_SSE4_1 && 1 && 1)
#define HAVE_sse4_1_packusdw_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_avx2_pblendvb ((TARGET_SSE4_1) && (TARGET_AVX2))
#define HAVE_sse4_1_pblendvb (TARGET_SSE4_1)
#define HAVE_sse4_1_pblendw (TARGET_SSE4_1)
#define HAVE_avx2_pblenddv8si (TARGET_AVX2)
#define HAVE_avx2_pblenddv4si (TARGET_AVX2)
#define HAVE_sse4_1_phminposuw (TARGET_SSE4_1)
#define HAVE_avx2_sign_extendv16qiv16hi2 (TARGET_AVX2 && 1 && 1)
#define HAVE_avx2_sign_extendv16qiv16hi2_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512BW && TARGET_AVX512VL))
#define HAVE_avx2_zero_extendv16qiv16hi2 (TARGET_AVX2 && 1 && 1)
#define HAVE_avx2_zero_extendv16qiv16hi2_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512BW && TARGET_AVX512VL))
#define HAVE_avx512bw_sign_extendv32qiv32hi2 (TARGET_AVX512BW)
#define HAVE_avx512bw_sign_extendv32qiv32hi2_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512bw_zero_extendv32qiv32hi2 (TARGET_AVX512BW)
#define HAVE_avx512bw_zero_extendv32qiv32hi2_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_sse4_1_sign_extendv8qiv8hi2 (TARGET_SSE4_1 && 1 && 1)
#define HAVE_sse4_1_sign_extendv8qiv8hi2_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && TARGET_AVX512BW && TARGET_AVX512VL))
#define HAVE_sse4_1_zero_extendv8qiv8hi2 (TARGET_SSE4_1 && 1 && 1)
#define HAVE_sse4_1_zero_extendv8qiv8hi2_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && TARGET_AVX512BW && TARGET_AVX512VL))
#define HAVE_avx512f_sign_extendv16qiv16si2_mask (TARGET_AVX512F)
#define HAVE_avx512f_zero_extendv16qiv16si2_mask (TARGET_AVX512F)
#define HAVE_avx2_sign_extendv8qiv8si2 (TARGET_AVX2 && 1)
#define HAVE_avx2_sign_extendv8qiv8si2_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_avx2_zero_extendv8qiv8si2 (TARGET_AVX2 && 1)
#define HAVE_avx2_zero_extendv8qiv8si2_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_sse4_1_sign_extendv4qiv4si2 (TARGET_SSE4_1 && 1)
#define HAVE_sse4_1_sign_extendv4qiv4si2_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && TARGET_AVX512VL))
#define HAVE_sse4_1_zero_extendv4qiv4si2 (TARGET_SSE4_1 && 1)
#define HAVE_sse4_1_zero_extendv4qiv4si2_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && TARGET_AVX512VL))
#define HAVE_avx512f_sign_extendv16hiv16si2 (TARGET_AVX512F)
#define HAVE_avx512f_sign_extendv16hiv16si2_mask (TARGET_AVX512F)
#define HAVE_avx512f_zero_extendv16hiv16si2 (TARGET_AVX512F)
#define HAVE_avx512f_zero_extendv16hiv16si2_mask (TARGET_AVX512F)
#define HAVE_avx2_sign_extendv8hiv8si2 (TARGET_AVX2 && 1)
#define HAVE_avx2_sign_extendv8hiv8si2_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_avx2_zero_extendv8hiv8si2 (TARGET_AVX2 && 1)
#define HAVE_avx2_zero_extendv8hiv8si2_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_sse4_1_sign_extendv4hiv4si2 (TARGET_SSE4_1 && 1)
#define HAVE_sse4_1_sign_extendv4hiv4si2_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && TARGET_AVX512VL))
#define HAVE_sse4_1_zero_extendv4hiv4si2 (TARGET_SSE4_1 && 1)
#define HAVE_sse4_1_zero_extendv4hiv4si2_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && TARGET_AVX512VL))
#define HAVE_avx512f_sign_extendv8qiv8di2 (TARGET_AVX512F)
#define HAVE_avx512f_sign_extendv8qiv8di2_mask (TARGET_AVX512F)
#define HAVE_avx512f_zero_extendv8qiv8di2 (TARGET_AVX512F)
#define HAVE_avx512f_zero_extendv8qiv8di2_mask (TARGET_AVX512F)
#define HAVE_avx2_sign_extendv4qiv4di2 (TARGET_AVX2 && 1)
#define HAVE_avx2_sign_extendv4qiv4di2_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_avx2_zero_extendv4qiv4di2 (TARGET_AVX2 && 1)
#define HAVE_avx2_zero_extendv4qiv4di2_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_sse4_1_sign_extendv2qiv2di2 (TARGET_SSE4_1 && 1)
#define HAVE_sse4_1_sign_extendv2qiv2di2_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && TARGET_AVX512VL))
#define HAVE_sse4_1_zero_extendv2qiv2di2 (TARGET_SSE4_1 && 1)
#define HAVE_sse4_1_zero_extendv2qiv2di2_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && TARGET_AVX512VL))
#define HAVE_avx512f_sign_extendv8hiv8di2 (TARGET_AVX512F)
#define HAVE_avx512f_sign_extendv8hiv8di2_mask (TARGET_AVX512F)
#define HAVE_avx512f_zero_extendv8hiv8di2 (TARGET_AVX512F)
#define HAVE_avx512f_zero_extendv8hiv8di2_mask (TARGET_AVX512F)
#define HAVE_avx2_sign_extendv4hiv4di2 (TARGET_AVX2 && 1)
#define HAVE_avx2_sign_extendv4hiv4di2_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_avx2_zero_extendv4hiv4di2 (TARGET_AVX2 && 1)
#define HAVE_avx2_zero_extendv4hiv4di2_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_sse4_1_sign_extendv2hiv2di2 (TARGET_SSE4_1 && 1)
#define HAVE_sse4_1_sign_extendv2hiv2di2_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && TARGET_AVX512VL))
#define HAVE_sse4_1_zero_extendv2hiv2di2 (TARGET_SSE4_1 && 1)
#define HAVE_sse4_1_zero_extendv2hiv2di2_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && TARGET_AVX512VL))
#define HAVE_avx512f_sign_extendv8siv8di2 (TARGET_AVX512F)
#define HAVE_avx512f_sign_extendv8siv8di2_mask (TARGET_AVX512F)
#define HAVE_avx512f_zero_extendv8siv8di2 (TARGET_AVX512F)
#define HAVE_avx512f_zero_extendv8siv8di2_mask (TARGET_AVX512F)
#define HAVE_avx2_sign_extendv4siv4di2 (TARGET_AVX2 && 1)
#define HAVE_avx2_sign_extendv4siv4di2_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_avx2_zero_extendv4siv4di2 (TARGET_AVX2 && 1)
#define HAVE_avx2_zero_extendv4siv4di2_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_sse4_1_sign_extendv2siv2di2 (TARGET_SSE4_1 && 1)
#define HAVE_sse4_1_sign_extendv2siv2di2_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && TARGET_AVX512VL))
#define HAVE_sse4_1_zero_extendv2siv2di2 (TARGET_SSE4_1 && 1)
#define HAVE_sse4_1_zero_extendv2siv2di2_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && TARGET_AVX512VL))
#define HAVE_avx_vtestps256 (TARGET_AVX)
#define HAVE_avx_vtestps (TARGET_AVX)
#define HAVE_avx_vtestpd256 (TARGET_AVX)
#define HAVE_avx_vtestpd ((TARGET_AVX) && (TARGET_SSE2))
#define HAVE_sse4_1_ptestv16qi (TARGET_SSE4_1)
#define HAVE_sse4_1_ptestv8hi (TARGET_SSE4_1)
#define HAVE_sse4_1_ptestv4si (TARGET_SSE4_1)
#define HAVE_sse4_1_ptestv2di (TARGET_SSE4_1)
#define HAVE_sse4_1_ptestv4sf (TARGET_SSE4_1)
#define HAVE_sse4_1_ptestv2df (TARGET_SSE4_1)
#define HAVE_avx_ptestv32qi ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_avx_ptestv16hi ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_avx_ptestv8si ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_avx_ptestv4di ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_avx_ptestv8sf ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_avx_ptestv4df ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_avx_roundps256 ((TARGET_ROUND) && (TARGET_AVX))
#define HAVE_sse4_1_roundps (TARGET_ROUND)
#define HAVE_avx_roundpd256 ((TARGET_ROUND) && (TARGET_AVX))
#define HAVE_sse4_1_roundpd ((TARGET_ROUND) && (TARGET_SSE2))
#define HAVE_sse4_1_roundss (TARGET_ROUND)
#define HAVE_sse4_1_roundsd ((TARGET_ROUND) && (TARGET_SSE2))
#define HAVE_sse4_2_pcmpestr (TARGET_SSE4_2 \
   && can_create_pseudo_p ())
#define HAVE_sse4_2_pcmpestri (TARGET_SSE4_2)
#define HAVE_sse4_2_pcmpestrm (TARGET_SSE4_2)
#define HAVE_sse4_2_pcmpestr_cconly (TARGET_SSE4_2)
#define HAVE_sse4_2_pcmpistr (TARGET_SSE4_2 \
   && can_create_pseudo_p ())
#define HAVE_sse4_2_pcmpistri (TARGET_SSE4_2)
#define HAVE_sse4_2_pcmpistrm (TARGET_SSE4_2)
#define HAVE_sse4_2_pcmpistr_cconly (TARGET_SSE4_2)
#define HAVE_avx512er_exp2v16sf (TARGET_AVX512ER)
#define HAVE_avx512er_exp2v16sf_round ((TARGET_AVX512F) && (TARGET_AVX512ER))
#define HAVE_avx512er_exp2v16sf_mask ((TARGET_AVX512F) && (TARGET_AVX512ER))
#define HAVE_avx512er_exp2v16sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512ER)))
#define HAVE_avx512er_exp2v8df (TARGET_AVX512ER)
#define HAVE_avx512er_exp2v8df_round ((TARGET_AVX512F) && (TARGET_AVX512ER))
#define HAVE_avx512er_exp2v8df_mask ((TARGET_AVX512F) && (TARGET_AVX512ER))
#define HAVE_avx512er_exp2v8df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512ER)))
#define HAVE_avx512er_rcp28v16sf_mask ((TARGET_AVX512F) && (TARGET_AVX512ER))
#define HAVE_avx512er_rcp28v16sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512ER)))
#define HAVE_avx512er_rcp28v8df_mask ((TARGET_AVX512F) && (TARGET_AVX512ER))
#define HAVE_avx512er_rcp28v8df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512ER)))
#define HAVE_avx512er_vmrcp28v4sf (TARGET_AVX512ER)
#define HAVE_avx512er_vmrcp28v4sf_round ((TARGET_AVX512F) && (TARGET_AVX512ER))
#define HAVE_avx512er_vmrcp28v2df ((TARGET_AVX512ER) && (TARGET_SSE2))
#define HAVE_avx512er_vmrcp28v2df_round ((TARGET_AVX512F) && ((TARGET_AVX512ER) && (TARGET_SSE2)))
#define HAVE_avx512er_rsqrt28v16sf_mask ((TARGET_AVX512F) && (TARGET_AVX512ER))
#define HAVE_avx512er_rsqrt28v16sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512ER)))
#define HAVE_avx512er_rsqrt28v8df_mask ((TARGET_AVX512F) && (TARGET_AVX512ER))
#define HAVE_avx512er_rsqrt28v8df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512ER)))
#define HAVE_avx512er_vmrsqrt28v4sf (TARGET_AVX512ER)
#define HAVE_avx512er_vmrsqrt28v4sf_round ((TARGET_AVX512F) && (TARGET_AVX512ER))
#define HAVE_avx512er_vmrsqrt28v2df ((TARGET_AVX512ER) && (TARGET_SSE2))
#define HAVE_avx512er_vmrsqrt28v2df_round ((TARGET_AVX512F) && ((TARGET_AVX512ER) && (TARGET_SSE2)))
#define HAVE_xop_pmacsww (TARGET_XOP)
#define HAVE_xop_pmacssww (TARGET_XOP)
#define HAVE_xop_pmacsdd (TARGET_XOP)
#define HAVE_xop_pmacssdd (TARGET_XOP)
#define HAVE_xop_pmacsdql (TARGET_XOP)
#define HAVE_xop_pmacssdql (TARGET_XOP)
#define HAVE_xop_pmacsdqh (TARGET_XOP)
#define HAVE_xop_pmacssdqh (TARGET_XOP)
#define HAVE_xop_pmacswd (TARGET_XOP)
#define HAVE_xop_pmacsswd (TARGET_XOP)
#define HAVE_xop_pmadcswd (TARGET_XOP)
#define HAVE_xop_pmadcsswd (TARGET_XOP)
#define HAVE_xop_pcmov_v32qi256 ((TARGET_XOP) && (TARGET_AVX))
#define HAVE_xop_pcmov_v16qi (TARGET_XOP)
#define HAVE_xop_pcmov_v16hi256 ((TARGET_XOP) && (TARGET_AVX))
#define HAVE_xop_pcmov_v8hi (TARGET_XOP)
#define HAVE_xop_pcmov_v16si512 ((TARGET_XOP) && (TARGET_AVX512F))
#define HAVE_xop_pcmov_v8si256 ((TARGET_XOP) && (TARGET_AVX))
#define HAVE_xop_pcmov_v4si (TARGET_XOP)
#define HAVE_xop_pcmov_v8di512 ((TARGET_XOP) && (TARGET_AVX512F))
#define HAVE_xop_pcmov_v4di256 ((TARGET_XOP) && (TARGET_AVX))
#define HAVE_xop_pcmov_v2di (TARGET_XOP)
#define HAVE_xop_pcmov_v16sf512 ((TARGET_XOP) && (TARGET_AVX512F))
#define HAVE_xop_pcmov_v8sf256 ((TARGET_XOP) && (TARGET_AVX))
#define HAVE_xop_pcmov_v4sf (TARGET_XOP)
#define HAVE_xop_pcmov_v8df512 ((TARGET_XOP) && (TARGET_AVX512F))
#define HAVE_xop_pcmov_v4df256 ((TARGET_XOP) && (TARGET_AVX))
#define HAVE_xop_pcmov_v2df ((TARGET_XOP) && (TARGET_SSE2))
#define HAVE_xop_phaddbw (TARGET_XOP)
#define HAVE_xop_phaddubw (TARGET_XOP)
#define HAVE_xop_phaddbd (TARGET_XOP)
#define HAVE_xop_phaddubd (TARGET_XOP)
#define HAVE_xop_phaddbq (TARGET_XOP)
#define HAVE_xop_phaddubq (TARGET_XOP)
#define HAVE_xop_phaddwd (TARGET_XOP)
#define HAVE_xop_phadduwd (TARGET_XOP)
#define HAVE_xop_phaddwq (TARGET_XOP)
#define HAVE_xop_phadduwq (TARGET_XOP)
#define HAVE_xop_phadddq (TARGET_XOP)
#define HAVE_xop_phaddudq (TARGET_XOP)
#define HAVE_xop_phsubbw (TARGET_XOP)
#define HAVE_xop_phsubwd (TARGET_XOP)
#define HAVE_xop_phsubdq (TARGET_XOP)
#define HAVE_xop_pperm (TARGET_XOP && !(MEM_P (operands[2]) && MEM_P (operands[3])))
#define HAVE_xop_pperm_pack_v2di_v4si (TARGET_XOP && !(MEM_P (operands[2]) && MEM_P (operands[3])))
#define HAVE_xop_pperm_pack_v4si_v8hi (TARGET_XOP && !(MEM_P (operands[2]) && MEM_P (operands[3])))
#define HAVE_xop_pperm_pack_v8hi_v16qi (TARGET_XOP && !(MEM_P (operands[2]) && MEM_P (operands[3])))
#define HAVE_xop_rotlv16qi3 (TARGET_XOP)
#define HAVE_xop_rotlv8hi3 (TARGET_XOP)
#define HAVE_xop_rotlv4si3 (TARGET_XOP)
#define HAVE_xop_rotlv2di3 (TARGET_XOP)
#define HAVE_xop_rotrv16qi3 (TARGET_XOP)
#define HAVE_xop_rotrv8hi3 (TARGET_XOP)
#define HAVE_xop_rotrv4si3 (TARGET_XOP)
#define HAVE_xop_rotrv2di3 (TARGET_XOP)
#define HAVE_xop_vrotlv16qi3 (TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_xop_vrotlv8hi3 (TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_xop_vrotlv4si3 (TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_xop_vrotlv2di3 (TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_xop_shav16qi3 (TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_xop_shav8hi3 (TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_xop_shav4si3 (TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_xop_shav2di3 (TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_xop_shlv16qi3 (TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_xop_shlv8hi3 (TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_xop_shlv4si3 (TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_xop_shlv2di3 (TARGET_XOP && !(MEM_P (operands[1]) && MEM_P (operands[2])))
#define HAVE_xop_frczsf2 (TARGET_XOP)
#define HAVE_xop_frczdf2 (TARGET_XOP)
#define HAVE_xop_frczv4sf2 (TARGET_XOP)
#define HAVE_xop_frczv2df2 (TARGET_XOP)
#define HAVE_xop_frczv8sf2 (TARGET_XOP)
#define HAVE_xop_frczv4df2 (TARGET_XOP)
#define HAVE_xop_maskcmpv16qi3 (TARGET_XOP)
#define HAVE_xop_maskcmpv8hi3 (TARGET_XOP)
#define HAVE_xop_maskcmpv4si3 (TARGET_XOP)
#define HAVE_xop_maskcmpv2di3 (TARGET_XOP)
#define HAVE_xop_maskcmp_unsv16qi3 (TARGET_XOP)
#define HAVE_xop_maskcmp_unsv8hi3 (TARGET_XOP)
#define HAVE_xop_maskcmp_unsv4si3 (TARGET_XOP)
#define HAVE_xop_maskcmp_unsv2di3 (TARGET_XOP)
#define HAVE_xop_maskcmp_uns2v16qi3 (TARGET_XOP)
#define HAVE_xop_maskcmp_uns2v8hi3 (TARGET_XOP)
#define HAVE_xop_maskcmp_uns2v4si3 (TARGET_XOP)
#define HAVE_xop_maskcmp_uns2v2di3 (TARGET_XOP)
#define HAVE_xop_pcom_tfv16qi3 (TARGET_XOP)
#define HAVE_xop_pcom_tfv8hi3 (TARGET_XOP)
#define HAVE_xop_pcom_tfv4si3 (TARGET_XOP)
#define HAVE_xop_pcom_tfv2di3 (TARGET_XOP)
#define HAVE_xop_vpermil2v8sf3 ((TARGET_XOP) && (TARGET_AVX))
#define HAVE_xop_vpermil2v4sf3 (TARGET_XOP)
#define HAVE_xop_vpermil2v4df3 ((TARGET_XOP) && (TARGET_AVX))
#define HAVE_xop_vpermil2v2df3 ((TARGET_XOP) && (TARGET_SSE2))
#define HAVE_aesenc (TARGET_AES)
#define HAVE_aesenclast (TARGET_AES)
#define HAVE_aesdec (TARGET_AES)
#define HAVE_aesdeclast (TARGET_AES)
#define HAVE_aesimc (TARGET_AES)
#define HAVE_aeskeygenassist (TARGET_AES)
#define HAVE_pclmulqdq (TARGET_PCLMUL)
#define HAVE_avx_vzeroupper (TARGET_AVX)
#define HAVE_avx2_pbroadcastv16si ((TARGET_AVX2) && (TARGET_AVX512F))
#define HAVE_avx2_pbroadcastv8di ((TARGET_AVX2) && (TARGET_AVX512F))
#define HAVE_avx2_pbroadcastv64qi ((TARGET_AVX2) && (TARGET_AVX512BW))
#define HAVE_avx2_pbroadcastv32qi ((TARGET_AVX2) && (TARGET_AVX))
#define HAVE_avx2_pbroadcastv16qi (TARGET_AVX2)
#define HAVE_avx2_pbroadcastv32hi ((TARGET_AVX2) && (TARGET_AVX512BW))
#define HAVE_avx2_pbroadcastv16hi ((TARGET_AVX2) && (TARGET_AVX))
#define HAVE_avx2_pbroadcastv8hi (TARGET_AVX2)
#define HAVE_avx2_pbroadcastv8si ((TARGET_AVX2) && (TARGET_AVX))
#define HAVE_avx2_pbroadcastv4si (TARGET_AVX2)
#define HAVE_avx2_pbroadcastv4di ((TARGET_AVX2) && (TARGET_AVX))
#define HAVE_avx2_pbroadcastv2di (TARGET_AVX2)
#define HAVE_avx2_pbroadcastv32qi_1 (TARGET_AVX2)
#define HAVE_avx2_pbroadcastv16hi_1 (TARGET_AVX2)
#define HAVE_avx2_pbroadcastv8si_1 (TARGET_AVX2)
#define HAVE_avx2_pbroadcastv4di_1 (TARGET_AVX2)
#define HAVE_avx2_permvarv8si (TARGET_AVX2 && 1)
#define HAVE_avx2_permvarv8si_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (32 == 64 || TARGET_AVX512VL)))
#define HAVE_avx2_permvarv8sf (TARGET_AVX2 && 1)
#define HAVE_avx2_permvarv8sf_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (32 == 64 || TARGET_AVX512VL)))
#define HAVE_avx512f_permvarv16si ((TARGET_AVX2 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_permvarv16si_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx512f_permvarv16sf ((TARGET_AVX2 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_permvarv16sf_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx512f_permvarv8di ((TARGET_AVX2 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_permvarv8di_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx512f_permvarv8df ((TARGET_AVX2 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_permvarv8df_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx2_permvarv4di ((TARGET_AVX2 && 1) && (TARGET_AVX512VL))
#define HAVE_avx2_permvarv4di_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512VL)))
#define HAVE_avx2_permvarv4df ((TARGET_AVX2 && 1) && (TARGET_AVX512VL))
#define HAVE_avx2_permvarv4df_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_permvarv64qi (TARGET_AVX512VBMI && 1)
#define HAVE_avx512bw_permvarv64qi_mask ((TARGET_AVX512F) && (TARGET_AVX512VBMI && (64 == 64 || TARGET_AVX512VL)))
#define HAVE_avx512vl_permvarv16qi ((TARGET_AVX512VBMI && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_permvarv16qi_mask ((TARGET_AVX512F) && ((TARGET_AVX512VBMI && (16 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_permvarv32qi ((TARGET_AVX512VBMI && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_permvarv32qi_mask ((TARGET_AVX512F) && ((TARGET_AVX512VBMI && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_permvarv8hi ((TARGET_AVX512BW && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_permvarv8hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW && (16 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_permvarv16hi ((TARGET_AVX512BW && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_permvarv16hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_permvarv32hi (TARGET_AVX512BW && 1)
#define HAVE_avx512bw_permvarv32hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW && (64 == 64 || TARGET_AVX512VL)))
#define HAVE_avx2_permv4di_1 (TARGET_AVX2 && 1)
#define HAVE_avx2_permv4di_1_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (32 == 64 || TARGET_AVX512VL)))
#define HAVE_avx2_permv4df_1 (TARGET_AVX2 && 1)
#define HAVE_avx2_permv4df_1_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (32 == 64 || TARGET_AVX512VL)))
#define HAVE_avx512f_permv8di_1 ((TARGET_AVX2 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_permv8di_1_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx512f_permv8df_1 ((TARGET_AVX2 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_permv8df_1_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx2_permv2ti (TARGET_AVX2)
#define HAVE_avx2_vec_dupv4df (TARGET_AVX2)
#define HAVE_avx512f_vec_dupv16si_1 (TARGET_AVX512F)
#define HAVE_avx512f_vec_dupv8di_1 (TARGET_AVX512F)
#define HAVE_avx512bw_vec_dupv32hi_1 ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512bw_vec_dupv64qi_1 ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512f_vec_dupv16si (TARGET_AVX512F)
#define HAVE_avx512f_vec_dupv16si_mask (TARGET_AVX512F)
#define HAVE_avx512vl_vec_dupv8si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vec_dupv8si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_vec_dupv4si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vec_dupv4si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_vec_dupv8di (TARGET_AVX512F)
#define HAVE_avx512f_vec_dupv8di_mask (TARGET_AVX512F)
#define HAVE_avx512vl_vec_dupv4di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vec_dupv4di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_vec_dupv2di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vec_dupv2di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_vec_dupv16sf (TARGET_AVX512F)
#define HAVE_avx512f_vec_dupv16sf_mask (TARGET_AVX512F)
#define HAVE_avx512vl_vec_dupv8sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vec_dupv8sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_vec_dupv4sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vec_dupv4sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_vec_dupv8df (TARGET_AVX512F)
#define HAVE_avx512f_vec_dupv8df_mask (TARGET_AVX512F)
#define HAVE_avx512vl_vec_dupv4df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vec_dupv4df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_vec_dupv2df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vec_dupv2df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_vec_dupv64qi (TARGET_AVX512BW)
#define HAVE_avx512bw_vec_dupv64qi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_vec_dupv16qi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vec_dupv16qi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_vec_dupv32qi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vec_dupv32qi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_vec_dupv32hi (TARGET_AVX512BW)
#define HAVE_avx512bw_vec_dupv32hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_vec_dupv16hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vec_dupv16hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_vec_dupv8hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vec_dupv8hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512f_broadcastv16sf_mask (TARGET_AVX512F)
#define HAVE_avx512f_broadcastv16si_mask (TARGET_AVX512F)
#define HAVE_avx512f_broadcastv8df_mask (TARGET_AVX512F)
#define HAVE_avx512f_broadcastv8di_mask (TARGET_AVX512F)
#define HAVE_avx512bw_vec_dup_gprv64qi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_vec_dup_gprv16qi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_vec_dup_gprv32qi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_vec_dup_gprv32hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_vec_dup_gprv16hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_vec_dup_gprv8hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512f_vec_dup_gprv16si_mask (TARGET_AVX512F)
#define HAVE_avx512vl_vec_dup_gprv8si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_vec_dup_gprv4si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_vec_dup_gprv8di_mask (TARGET_AVX512F)
#define HAVE_avx512vl_vec_dup_gprv4di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_vec_dup_gprv2di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_vec_dup_gprv16sf_mask (TARGET_AVX512F)
#define HAVE_avx512vl_vec_dup_gprv8sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_vec_dup_gprv4sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_vec_dup_gprv8df_mask (TARGET_AVX512F)
#define HAVE_avx512vl_vec_dup_gprv4df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_vec_dup_gprv2df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_vec_dupv4sf (TARGET_SSE)
#define HAVE_avx2_vbroadcasti128_v32qi (TARGET_AVX2)
#define HAVE_avx2_vbroadcasti128_v16hi (TARGET_AVX2)
#define HAVE_avx2_vbroadcasti128_v8si (TARGET_AVX2)
#define HAVE_avx2_vbroadcasti128_v4di (TARGET_AVX2)
#define HAVE_vec_dupv8si (TARGET_AVX)
#define HAVE_vec_dupv8sf (TARGET_AVX)
#define HAVE_vec_dupv4di (TARGET_AVX)
#define HAVE_vec_dupv4df (TARGET_AVX)
#define HAVE_avx_vbroadcastf128_v32qi (TARGET_AVX)
#define HAVE_avx_vbroadcastf128_v16hi (TARGET_AVX)
#define HAVE_avx_vbroadcastf128_v8si (TARGET_AVX)
#define HAVE_avx_vbroadcastf128_v4di (TARGET_AVX)
#define HAVE_avx_vbroadcastf128_v8sf (TARGET_AVX)
#define HAVE_avx_vbroadcastf128_v4df (TARGET_AVX)
#define HAVE_avx512dq_broadcastv16si_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512dq_broadcastv8si_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_avx512dq_broadcastv4si_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_avx512dq_broadcastv16sf_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512dq_broadcastv8sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_broadcastv8si_mask_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_broadcastv8sf_mask_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512dq_broadcastv16sf_mask_1 ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512dq_broadcastv16si_mask_1 ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512dq_broadcastv8di_mask_1 ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512dq_broadcastv8df_mask_1 ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512dq_broadcastv4di_mask_1 ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_avx512dq_broadcastv4df_mask_1 ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_avx512cd_maskb_vec_dupv8di (TARGET_AVX512CD)
#define HAVE_avx512cd_maskb_vec_dupv4di ((TARGET_AVX512CD) && (TARGET_AVX512VL))
#define HAVE_avx512cd_maskb_vec_dupv2di ((TARGET_AVX512CD) && (TARGET_AVX512VL))
#define HAVE_avx512cd_maskw_vec_dupv16si (TARGET_AVX512CD)
#define HAVE_avx512cd_maskw_vec_dupv8si ((TARGET_AVX512CD) && (TARGET_AVX512VL))
#define HAVE_avx512cd_maskw_vec_dupv4si ((TARGET_AVX512CD) && (TARGET_AVX512VL))
#define HAVE_avx512f_vpermilvarv16sf3 ((TARGET_AVX && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_vpermilvarv16sf3_mask ((TARGET_AVX512F) && ((TARGET_AVX && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx_vpermilvarv8sf3 ((TARGET_AVX && 1) && (TARGET_AVX))
#define HAVE_avx_vpermilvarv8sf3_mask ((TARGET_AVX512F) && ((TARGET_AVX && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX)))
#define HAVE_avx_vpermilvarv4sf3 (TARGET_AVX && 1)
#define HAVE_avx_vpermilvarv4sf3_mask ((TARGET_AVX512F) && (TARGET_AVX && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_avx512f_vpermilvarv8df3 ((TARGET_AVX && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_vpermilvarv8df3_mask ((TARGET_AVX512F) && ((TARGET_AVX && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx_vpermilvarv4df3 ((TARGET_AVX && 1) && (TARGET_AVX))
#define HAVE_avx_vpermilvarv4df3_mask ((TARGET_AVX512F) && ((TARGET_AVX && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX)))
#define HAVE_avx_vpermilvarv2df3 ((TARGET_AVX && 1) && (TARGET_SSE2))
#define HAVE_avx_vpermilvarv2df3_mask ((TARGET_AVX512F) && ((TARGET_AVX && (16 == 64 || TARGET_AVX512VL)) && (TARGET_SSE2)))
#define HAVE_avx512f_vpermi2varv16si3 (TARGET_AVX512F)
#define HAVE_avx512f_vpermi2varv16si3_maskz_1 (TARGET_AVX512F)
#define HAVE_avx512f_vpermi2varv16sf3 (TARGET_AVX512F)
#define HAVE_avx512f_vpermi2varv16sf3_maskz_1 (TARGET_AVX512F)
#define HAVE_avx512f_vpermi2varv8di3 (TARGET_AVX512F)
#define HAVE_avx512f_vpermi2varv8di3_maskz_1 (TARGET_AVX512F)
#define HAVE_avx512f_vpermi2varv8df3 (TARGET_AVX512F)
#define HAVE_avx512f_vpermi2varv8df3_maskz_1 (TARGET_AVX512F)
#define HAVE_avx512vl_vpermi2varv8si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv8si3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv8sf3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv8sf3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4di3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4df3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4df3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4si3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4sf3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4sf3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv2di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv2di3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv2df3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv2df3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512bw_vpermi2varv64qi3 (TARGET_AVX512VBMI)
#define HAVE_avx512bw_vpermi2varv64qi3_maskz_1 (TARGET_AVX512VBMI)
#define HAVE_avx512vl_vpermi2varv16qi3 ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv16qi3_maskz_1 ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv32qi3 ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv32qi3_maskz_1 ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv8hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv8hi3_maskz_1 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv16hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv16hi3_maskz_1 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_vpermi2varv32hi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_vpermi2varv32hi3_maskz_1 (TARGET_AVX512BW)
#define HAVE_avx512f_vpermi2varv16si3_mask (TARGET_AVX512F)
#define HAVE_avx512f_vpermi2varv16sf3_mask (TARGET_AVX512F)
#define HAVE_avx512f_vpermi2varv8di3_mask (TARGET_AVX512F)
#define HAVE_avx512f_vpermi2varv8df3_mask (TARGET_AVX512F)
#define HAVE_avx512vl_vpermi2varv8si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv8sf3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4df3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4sf3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv2di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv2df3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512bw_vpermi2varv64qi3_mask (TARGET_AVX512VBMI)
#define HAVE_avx512vl_vpermi2varv16qi3_mask ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv32qi3_mask ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv8hi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv16hi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_vpermi2varv32hi3_mask (TARGET_AVX512BW)
#define HAVE_avx512f_vpermt2varv16si3 (TARGET_AVX512F)
#define HAVE_avx512f_vpermt2varv16si3_maskz_1 (TARGET_AVX512F)
#define HAVE_avx512f_vpermt2varv16sf3 (TARGET_AVX512F)
#define HAVE_avx512f_vpermt2varv16sf3_maskz_1 (TARGET_AVX512F)
#define HAVE_avx512f_vpermt2varv8di3 (TARGET_AVX512F)
#define HAVE_avx512f_vpermt2varv8di3_maskz_1 (TARGET_AVX512F)
#define HAVE_avx512f_vpermt2varv8df3 (TARGET_AVX512F)
#define HAVE_avx512f_vpermt2varv8df3_maskz_1 (TARGET_AVX512F)
#define HAVE_avx512vl_vpermt2varv8si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv8si3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv8sf3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv8sf3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4di3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4df3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4df3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4si3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4sf3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4sf3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv2di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv2di3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv2df3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv2df3_maskz_1 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512bw_vpermt2varv64qi3 (TARGET_AVX512VBMI)
#define HAVE_avx512bw_vpermt2varv64qi3_maskz_1 (TARGET_AVX512VBMI)
#define HAVE_avx512vl_vpermt2varv16qi3 ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv16qi3_maskz_1 ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv32qi3 ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv32qi3_maskz_1 ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv8hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv8hi3_maskz_1 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv16hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv16hi3_maskz_1 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_vpermt2varv32hi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_vpermt2varv32hi3_maskz_1 (TARGET_AVX512BW)
#define HAVE_avx512f_vpermt2varv16si3_mask (TARGET_AVX512F)
#define HAVE_avx512f_vpermt2varv16sf3_mask (TARGET_AVX512F)
#define HAVE_avx512f_vpermt2varv8di3_mask (TARGET_AVX512F)
#define HAVE_avx512f_vpermt2varv8df3_mask (TARGET_AVX512F)
#define HAVE_avx512vl_vpermt2varv8si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv8sf3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4df3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4sf3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv2di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv2df3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512bw_vpermt2varv64qi3_mask (TARGET_AVX512VBMI)
#define HAVE_avx512vl_vpermt2varv16qi3_mask ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv32qi3_mask ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv8hi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv16hi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_vpermt2varv32hi3_mask (TARGET_AVX512BW)
#define HAVE_vec_set_lo_v4di (TARGET_AVX)
#define HAVE_vec_set_lo_v4di_mask ((TARGET_AVX512F) && (TARGET_AVX))
#define HAVE_vec_set_lo_v4df (TARGET_AVX)
#define HAVE_vec_set_lo_v4df_mask ((TARGET_AVX512F) && (TARGET_AVX))
#define HAVE_vec_set_hi_v4di (TARGET_AVX)
#define HAVE_vec_set_hi_v4di_mask ((TARGET_AVX512F) && (TARGET_AVX))
#define HAVE_vec_set_hi_v4df (TARGET_AVX)
#define HAVE_vec_set_hi_v4df_mask ((TARGET_AVX512F) && (TARGET_AVX))
#define HAVE_vec_set_lo_v8si (TARGET_AVX)
#define HAVE_vec_set_lo_v8si_mask ((TARGET_AVX512F) && (TARGET_AVX))
#define HAVE_vec_set_lo_v8sf (TARGET_AVX)
#define HAVE_vec_set_lo_v8sf_mask ((TARGET_AVX512F) && (TARGET_AVX))
#define HAVE_vec_set_hi_v8si (TARGET_AVX)
#define HAVE_vec_set_hi_v8si_mask ((TARGET_AVX512F) && (TARGET_AVX))
#define HAVE_vec_set_hi_v8sf (TARGET_AVX)
#define HAVE_vec_set_hi_v8sf_mask ((TARGET_AVX512F) && (TARGET_AVX))
#define HAVE_vec_set_lo_v16hi (TARGET_AVX)
#define HAVE_vec_set_hi_v16hi (TARGET_AVX)
#define HAVE_vec_set_lo_v32qi (TARGET_AVX)
#define HAVE_vec_set_hi_v32qi (TARGET_AVX)
#define HAVE_avx_maskloadps (TARGET_AVX)
#define HAVE_avx_maskloadpd (TARGET_AVX)
#define HAVE_avx_maskloadps256 (TARGET_AVX)
#define HAVE_avx_maskloadpd256 (TARGET_AVX)
#define HAVE_avx2_maskloadd ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_avx2_maskloadq ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_avx2_maskloadd256 ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_avx2_maskloadq256 ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_avx_maskstoreps (TARGET_AVX)
#define HAVE_avx_maskstorepd (TARGET_AVX)
#define HAVE_avx_maskstoreps256 (TARGET_AVX)
#define HAVE_avx_maskstorepd256 (TARGET_AVX)
#define HAVE_avx2_maskstored ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_avx2_maskstoreq ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_avx2_maskstored256 ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_avx2_maskstoreq256 ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_avx_si256_si (TARGET_AVX)
#define HAVE_avx_ps256_ps (TARGET_AVX)
#define HAVE_avx_pd256_pd (TARGET_AVX)
#define HAVE_avx2_ashrvv4si (TARGET_AVX2 && 1)
#define HAVE_avx2_ashrvv4si_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_avx2_ashrvv8si (TARGET_AVX2 && 1)
#define HAVE_avx2_ashrvv8si_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (32 == 64 || TARGET_AVX512VL)))
#define HAVE_avx512f_ashrvv16si ((TARGET_AVX2 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_ashrvv16si_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx2_ashrvv2di ((TARGET_AVX2 && 1) && (TARGET_AVX512VL))
#define HAVE_avx2_ashrvv2di_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (16 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512VL)))
#define HAVE_avx2_ashrvv4di ((TARGET_AVX2 && 1) && (TARGET_AVX512VL))
#define HAVE_avx2_ashrvv4di_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512VL)))
#define HAVE_avx512f_ashrvv8di ((TARGET_AVX2 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_ashrvv8di_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx512vl_ashrvv8hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_ashrvv8hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_ashrvv16hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_ashrvv16hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_ashrvv32hi (TARGET_AVX512BW)
#define HAVE_avx512bw_ashrvv32hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512f_ashlvv16si ((TARGET_AVX2 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_ashlvv16si_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx512f_lshrvv16si ((TARGET_AVX2 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_lshrvv16si_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx2_ashlvv8si (TARGET_AVX2 && 1)
#define HAVE_avx2_ashlvv8si_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (32 == 64 || TARGET_AVX512VL)))
#define HAVE_avx2_lshrvv8si (TARGET_AVX2 && 1)
#define HAVE_avx2_lshrvv8si_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (32 == 64 || TARGET_AVX512VL)))
#define HAVE_avx2_ashlvv4si (TARGET_AVX2 && 1)
#define HAVE_avx2_ashlvv4si_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_avx2_lshrvv4si (TARGET_AVX2 && 1)
#define HAVE_avx2_lshrvv4si_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_avx512f_ashlvv8di ((TARGET_AVX2 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_ashlvv8di_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx512f_lshrvv8di ((TARGET_AVX2 && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_lshrvv8di_mask ((TARGET_AVX512F) && ((TARGET_AVX2 && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx2_ashlvv4di (TARGET_AVX2 && 1)
#define HAVE_avx2_ashlvv4di_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (32 == 64 || TARGET_AVX512VL)))
#define HAVE_avx2_lshrvv4di (TARGET_AVX2 && 1)
#define HAVE_avx2_lshrvv4di_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (32 == 64 || TARGET_AVX512VL)))
#define HAVE_avx2_ashlvv2di (TARGET_AVX2 && 1)
#define HAVE_avx2_ashlvv2di_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_avx2_lshrvv2di (TARGET_AVX2 && 1)
#define HAVE_avx2_lshrvv2di_mask ((TARGET_AVX512F) && (TARGET_AVX2 && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_avx512vl_ashlvv8hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_ashlvv8hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_lshrvv8hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_lshrvv8hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_ashlvv16hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_ashlvv16hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_lshrvv16hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_lshrvv16hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_ashlvv32hi (TARGET_AVX512BW)
#define HAVE_avx512bw_ashlvv32hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512bw_lshrvv32hi (TARGET_AVX512BW)
#define HAVE_avx512bw_lshrvv32hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx_vec_concatv32qi (TARGET_AVX)
#define HAVE_avx_vec_concatv16hi (TARGET_AVX)
#define HAVE_avx_vec_concatv8si (TARGET_AVX)
#define HAVE_avx_vec_concatv4di (TARGET_AVX)
#define HAVE_avx_vec_concatv8sf (TARGET_AVX)
#define HAVE_avx_vec_concatv4df (TARGET_AVX)
#define HAVE_avx_vec_concatv64qi ((TARGET_AVX) && (TARGET_AVX512F))
#define HAVE_avx_vec_concatv32hi ((TARGET_AVX) && (TARGET_AVX512F))
#define HAVE_avx_vec_concatv16si ((TARGET_AVX) && (TARGET_AVX512F))
#define HAVE_avx_vec_concatv8di ((TARGET_AVX) && (TARGET_AVX512F))
#define HAVE_avx_vec_concatv16sf ((TARGET_AVX) && (TARGET_AVX512F))
#define HAVE_avx_vec_concatv8df ((TARGET_AVX) && (TARGET_AVX512F))
#define HAVE_vcvtph2ps (TARGET_F16C || TARGET_AVX512VL)
#define HAVE_vcvtph2ps_mask ((TARGET_AVX512F) && (TARGET_F16C || TARGET_AVX512VL))
#define HAVE_vcvtph2ps256 (TARGET_F16C || TARGET_AVX512VL)
#define HAVE_vcvtph2ps256_mask ((TARGET_AVX512F) && (TARGET_F16C || TARGET_AVX512VL))
#define HAVE_avx512f_vcvtph2ps512_mask (TARGET_AVX512F)
#define HAVE_avx512f_vcvtph2ps512_mask_round (TARGET_AVX512F)
#define HAVE_vcvtps2ph256 (TARGET_F16C || TARGET_AVX512VL)
#define HAVE_vcvtps2ph256_mask ((TARGET_AVX512F) && (TARGET_F16C || TARGET_AVX512VL))
#define HAVE_avx512f_vcvtps2ph512_mask (TARGET_AVX512F)
#define HAVE_avx512f_compressv16si_mask (TARGET_AVX512F)
#define HAVE_avx512f_compressv16sf_mask (TARGET_AVX512F)
#define HAVE_avx512f_compressv8di_mask (TARGET_AVX512F)
#define HAVE_avx512f_compressv8df_mask (TARGET_AVX512F)
#define HAVE_avx512vl_compressv8si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressv8sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressv4di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressv4df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressv4si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressv4sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressv2di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressv2df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_compressstorev16si_mask (TARGET_AVX512F)
#define HAVE_avx512f_compressstorev16sf_mask (TARGET_AVX512F)
#define HAVE_avx512f_compressstorev8di_mask (TARGET_AVX512F)
#define HAVE_avx512f_compressstorev8df_mask (TARGET_AVX512F)
#define HAVE_avx512vl_compressstorev8si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressstorev8sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressstorev4di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressstorev4df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressstorev4si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressstorev4sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressstorev2di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_compressstorev2df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_expandv16si_mask (TARGET_AVX512F)
#define HAVE_avx512f_expandv16sf_mask (TARGET_AVX512F)
#define HAVE_avx512f_expandv8di_mask (TARGET_AVX512F)
#define HAVE_avx512f_expandv8df_mask (TARGET_AVX512F)
#define HAVE_avx512vl_expandv8si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv8sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv4di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv4df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv4si_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv4sf_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv2di_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv2df_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512dq_rangepv16sf (TARGET_AVX512DQ && 1)
#define HAVE_avx512dq_rangepv16sf_round ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V16SFmode == V16SFmode \
									      || V16SFmode == V8DFmode \
									      || V16SFmode == V8DImode \
									      || V16SFmode == V16SImode)))
#define HAVE_avx512dq_rangepv16sf_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && 1))
#define HAVE_avx512dq_rangepv16sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V16SFmode == V16SFmode \
									      || V16SFmode == V8DFmode \
									      || V16SFmode == V8DImode \
									      || V16SFmode == V16SImode))))
#define HAVE_avx512dq_rangepv8sf ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_avx512dq_rangepv8sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512dq_rangepv4sf ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_avx512dq_rangepv4sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512dq_rangepv8df (TARGET_AVX512DQ && 1)
#define HAVE_avx512dq_rangepv8df_round ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode)))
#define HAVE_avx512dq_rangepv8df_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ && 1))
#define HAVE_avx512dq_rangepv8df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512DQ && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode))))
#define HAVE_avx512dq_rangepv4df ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_avx512dq_rangepv4df_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512dq_rangepv2df ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL))
#define HAVE_avx512dq_rangepv2df_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512dq_rangesv4sf (TARGET_AVX512DQ)
#define HAVE_avx512dq_rangesv4sf_round ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512dq_rangesv2df ((TARGET_AVX512DQ) && (TARGET_SSE2))
#define HAVE_avx512dq_rangesv2df_round ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_SSE2)))
#define HAVE_avx512dq_fpclassv16sf (TARGET_AVX512DQ)
#define HAVE_avx512dq_fpclassv16sf_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512dq_fpclassv8sf ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_avx512dq_fpclassv8sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_avx512dq_fpclassv4sf ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_avx512dq_fpclassv4sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_avx512dq_fpclassv8df (TARGET_AVX512DQ)
#define HAVE_avx512dq_fpclassv8df_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512dq_fpclassv4df ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_avx512dq_fpclassv4df_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_avx512dq_fpclassv2df ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_avx512dq_fpclassv2df_mask ((TARGET_AVX512F) && ((TARGET_AVX512DQ) && (TARGET_AVX512VL)))
#define HAVE_avx512dq_vmfpclassv4sf (TARGET_AVX512DQ)
#define HAVE_avx512dq_vmfpclassv2df ((TARGET_AVX512DQ) && (TARGET_SSE2))
#define HAVE_avx512f_getmantv16sf (TARGET_AVX512F)
#define HAVE_avx512f_getmantv16sf_round (TARGET_AVX512F)
#define HAVE_avx512f_getmantv16sf_mask (TARGET_AVX512F)
#define HAVE_avx512f_getmantv16sf_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_getmantv8sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_getmantv8sf_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getmantv8sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getmantv8sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512vl_getmantv4sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_getmantv4sf_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getmantv4sf_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getmantv4sf_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512f_getmantv8df (TARGET_AVX512F)
#define HAVE_avx512f_getmantv8df_round (TARGET_AVX512F)
#define HAVE_avx512f_getmantv8df_mask (TARGET_AVX512F)
#define HAVE_avx512f_getmantv8df_mask_round (TARGET_AVX512F)
#define HAVE_avx512vl_getmantv4df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_getmantv4df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getmantv4df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getmantv4df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512vl_getmantv2df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_getmantv2df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getmantv2df_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_getmantv2df_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL))))
#define HAVE_avx512f_vgetmantv4sf (TARGET_AVX512F)
#define HAVE_avx512f_vgetmantv4sf_round (TARGET_AVX512F)
#define HAVE_avx512f_vgetmantv2df ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_avx512f_vgetmantv2df_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_SSE2)))
#define HAVE_avx512bw_dbpsadbwv8hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_dbpsadbwv16hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_dbpsadbwv32hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_clzv16si2 (TARGET_AVX512CD)
#define HAVE_clzv16si2_mask ((TARGET_AVX512F) && (TARGET_AVX512CD))
#define HAVE_clzv8si2 ((TARGET_AVX512CD) && (TARGET_AVX512VL))
#define HAVE_clzv8si2_mask ((TARGET_AVX512F) && ((TARGET_AVX512CD) && (TARGET_AVX512VL)))
#define HAVE_clzv4si2 ((TARGET_AVX512CD) && (TARGET_AVX512VL))
#define HAVE_clzv4si2_mask ((TARGET_AVX512F) && ((TARGET_AVX512CD) && (TARGET_AVX512VL)))
#define HAVE_clzv8di2 (TARGET_AVX512CD)
#define HAVE_clzv8di2_mask ((TARGET_AVX512F) && (TARGET_AVX512CD))
#define HAVE_clzv4di2 ((TARGET_AVX512CD) && (TARGET_AVX512VL))
#define HAVE_clzv4di2_mask ((TARGET_AVX512F) && ((TARGET_AVX512CD) && (TARGET_AVX512VL)))
#define HAVE_clzv2di2 ((TARGET_AVX512CD) && (TARGET_AVX512VL))
#define HAVE_clzv2di2_mask ((TARGET_AVX512F) && ((TARGET_AVX512CD) && (TARGET_AVX512VL)))
#define HAVE_conflictv16si_mask ((TARGET_AVX512F) && (TARGET_AVX512CD))
#define HAVE_conflictv8si_mask ((TARGET_AVX512F) && ((TARGET_AVX512CD) && (TARGET_AVX512VL)))
#define HAVE_conflictv4si_mask ((TARGET_AVX512F) && ((TARGET_AVX512CD) && (TARGET_AVX512VL)))
#define HAVE_conflictv8di_mask ((TARGET_AVX512F) && (TARGET_AVX512CD))
#define HAVE_conflictv4di_mask ((TARGET_AVX512F) && ((TARGET_AVX512CD) && (TARGET_AVX512VL)))
#define HAVE_conflictv2di_mask ((TARGET_AVX512F) && ((TARGET_AVX512CD) && (TARGET_AVX512VL)))
#define HAVE_sha1msg1 (TARGET_SHA)
#define HAVE_sha1msg2 (TARGET_SHA)
#define HAVE_sha1nexte (TARGET_SHA)
#define HAVE_sha1rnds4 (TARGET_SHA)
#define HAVE_sha256msg1 (TARGET_SHA)
#define HAVE_sha256msg2 (TARGET_SHA)
#define HAVE_sha256rnds2 (TARGET_SHA)
#define HAVE_avx512f_si512_si (TARGET_AVX512F)
#define HAVE_avx512f_ps512_ps (TARGET_AVX512F)
#define HAVE_avx512f_pd512_pd (TARGET_AVX512F)
#define HAVE_avx512f_si512_256si (TARGET_AVX512F)
#define HAVE_avx512f_ps512_256ps (TARGET_AVX512F)
#define HAVE_avx512f_pd512_256pd (TARGET_AVX512F)
#define HAVE_vpamdd52luqv8di (TARGET_AVX512IFMA)
#define HAVE_vpamdd52luqv8di_maskz_1 (TARGET_AVX512IFMA)
#define HAVE_vpamdd52huqv8di (TARGET_AVX512IFMA)
#define HAVE_vpamdd52huqv8di_maskz_1 (TARGET_AVX512IFMA)
#define HAVE_vpamdd52luqv4di ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52luqv4di_maskz_1 ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52huqv4di ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52huqv4di_maskz_1 ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52luqv2di ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52luqv2di_maskz_1 ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52huqv2di ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52huqv2di_maskz_1 ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52luqv8di_mask (TARGET_AVX512IFMA)
#define HAVE_vpamdd52huqv8di_mask (TARGET_AVX512IFMA)
#define HAVE_vpamdd52luqv4di_mask ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52huqv4di_mask ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52luqv2di_mask ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52huqv2di_mask ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpmultishiftqbv64qi (TARGET_AVX512VBMI)
#define HAVE_vpmultishiftqbv64qi_mask ((TARGET_AVX512F) && (TARGET_AVX512VBMI))
#define HAVE_vpmultishiftqbv16qi ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_vpmultishiftqbv16qi_mask ((TARGET_AVX512F) && ((TARGET_AVX512VBMI) && (TARGET_AVX512VL)))
#define HAVE_vpmultishiftqbv32qi ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_vpmultishiftqbv32qi_mask ((TARGET_AVX512F) && ((TARGET_AVX512VBMI) && (TARGET_AVX512VL)))
#define HAVE_mfence_sse2 (TARGET_64BIT || TARGET_SSE2)
#define HAVE_mfence_nosse (!(TARGET_64BIT || TARGET_SSE2))
#define HAVE_atomic_loaddi_fpu (!TARGET_64BIT && (TARGET_80387 || TARGET_SSE))
#define HAVE_atomic_storeqi_1 1
#define HAVE_atomic_storehi_1 1
#define HAVE_atomic_storesi_1 1
#define HAVE_atomic_storedi_1 (TARGET_64BIT)
#define HAVE_atomic_storedi_fpu (!TARGET_64BIT && (TARGET_80387 || TARGET_SSE))
#define HAVE_loaddi_via_fpu (TARGET_80387)
#define HAVE_storedi_via_fpu (TARGET_80387)
#define HAVE_atomic_compare_and_swapdi_doubleword ((TARGET_CMPXCHG8B) && (!TARGET_64BIT))
#define HAVE_atomic_compare_and_swapti_doubleword ((TARGET_CMPXCHG16B) && (TARGET_64BIT))
#define HAVE_atomic_compare_and_swapqi_1 (TARGET_CMPXCHG)
#define HAVE_atomic_compare_and_swaphi_1 (TARGET_CMPXCHG)
#define HAVE_atomic_compare_and_swapsi_1 (TARGET_CMPXCHG)
#define HAVE_atomic_compare_and_swapdi_1 ((TARGET_CMPXCHG) && (TARGET_64BIT))
#define HAVE_atomic_fetch_addqi (TARGET_XADD)
#define HAVE_atomic_fetch_addhi (TARGET_XADD)
#define HAVE_atomic_fetch_addsi (TARGET_XADD)
#define HAVE_atomic_fetch_adddi ((TARGET_XADD) && (TARGET_64BIT))
#define HAVE_atomic_exchangeqi 1
#define HAVE_atomic_exchangehi 1
#define HAVE_atomic_exchangesi 1
#define HAVE_atomic_exchangedi (TARGET_64BIT)
#define HAVE_atomic_addqi 1
#define HAVE_atomic_addhi 1
#define HAVE_atomic_addsi 1
#define HAVE_atomic_adddi (TARGET_64BIT)
#define HAVE_atomic_subqi 1
#define HAVE_atomic_subhi 1
#define HAVE_atomic_subsi 1
#define HAVE_atomic_subdi (TARGET_64BIT)
#define HAVE_atomic_andqi 1
#define HAVE_atomic_orqi 1
#define HAVE_atomic_xorqi 1
#define HAVE_atomic_andhi 1
#define HAVE_atomic_orhi 1
#define HAVE_atomic_xorhi 1
#define HAVE_atomic_andsi 1
#define HAVE_atomic_orsi 1
#define HAVE_atomic_xorsi 1
#define HAVE_atomic_anddi (TARGET_64BIT)
#define HAVE_atomic_ordi (TARGET_64BIT)
#define HAVE_atomic_xordi (TARGET_64BIT)
#define HAVE_cbranchqi4 (TARGET_QIMODE_MATH)
#define HAVE_cbranchhi4 (TARGET_HIMODE_MATH)
#define HAVE_cbranchsi4 1
#define HAVE_cbranchdi4 1
#define HAVE_cbranchti4 (TARGET_64BIT)
#define HAVE_cstoreqi4 (TARGET_QIMODE_MATH)
#define HAVE_cstorehi4 (TARGET_HIMODE_MATH)
#define HAVE_cstoresi4 1
#define HAVE_cstoredi4 (TARGET_64BIT)
#define HAVE_cmpsi_1 1
#define HAVE_cmpdi_1 (TARGET_64BIT)
#define HAVE_cmpqi_ext_3 1
#define HAVE_cbranchxf4 (TARGET_80387)
#define HAVE_cstorexf4 (TARGET_80387)
#define HAVE_cbranchsf4 (TARGET_80387 || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
#define HAVE_cbranchdf4 (TARGET_80387 || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
#define HAVE_cstoresf4 (TARGET_80387 || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
#define HAVE_cstoredf4 (TARGET_80387 || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
#define HAVE_cbranchcc4 1
#define HAVE_cstorecc4 1
#define HAVE_reload_noff_store (TARGET_64BIT)
#define HAVE_reload_noff_load (TARGET_64BIT)
#define HAVE_movxi (TARGET_AVX512F)
#define HAVE_movoi (TARGET_AVX)
#define HAVE_movti (TARGET_64BIT || TARGET_SSE)
#define HAVE_movcdi 1
#define HAVE_movqi 1
#define HAVE_movhi 1
#define HAVE_movsi 1
#define HAVE_movdi 1
#define HAVE_movstrictqi 1
#define HAVE_movstricthi 1
#define HAVE_extvhi 1
#define HAVE_extvsi 1
#define HAVE_extzvhi 1
#define HAVE_extzvsi 1
#define HAVE_extzvdi (TARGET_64BIT)
#define HAVE_insvhi 1
#define HAVE_insvsi 1
#define HAVE_insvdi (TARGET_64BIT)
#define HAVE_movtf (TARGET_64BIT || TARGET_SSE)
#define HAVE_movsf 1
#define HAVE_movdf 1
#define HAVE_movxf 1
#define HAVE_zero_extendsidi2 1
#define HAVE_zero_extendqisi2 1
#define HAVE_zero_extendhisi2 1
#define HAVE_zero_extendqihi2 1
#define HAVE_extendsidi2 1
#define HAVE_extendsfdf2 (TARGET_80387 || (TARGET_SSE2 && TARGET_SSE_MATH))
#define HAVE_extendsfxf2 (TARGET_80387)
#define HAVE_extenddfxf2 (TARGET_80387)
#define HAVE_truncdfsf2 (TARGET_80387 || (TARGET_SSE2 && TARGET_SSE_MATH))
#define HAVE_truncdfsf2_with_temp 1
#define HAVE_truncxfsf2 (TARGET_80387)
#define HAVE_truncxfdf2 (TARGET_80387)
#define HAVE_fix_truncxfdi2 (TARGET_80387)
#define HAVE_fix_truncsfdi2 (TARGET_80387 || (TARGET_64BIT && SSE_FLOAT_MODE_P (SFmode)))
#define HAVE_fix_truncdfdi2 (TARGET_80387 || (TARGET_64BIT && SSE_FLOAT_MODE_P (DFmode)))
#define HAVE_fix_truncxfsi2 (TARGET_80387)
#define HAVE_fix_truncsfsi2 (TARGET_80387 || SSE_FLOAT_MODE_P (SFmode))
#define HAVE_fix_truncdfsi2 (TARGET_80387 || SSE_FLOAT_MODE_P (DFmode))
#define HAVE_fix_truncsfhi2 (TARGET_80387 \
   && !(SSE_FLOAT_MODE_P (SFmode) && (!TARGET_FISTTP || TARGET_SSE_MATH)))
#define HAVE_fix_truncdfhi2 (TARGET_80387 \
   && !(SSE_FLOAT_MODE_P (DFmode) && (!TARGET_FISTTP || TARGET_SSE_MATH)))
#define HAVE_fix_truncxfhi2 (TARGET_80387 \
   && !(SSE_FLOAT_MODE_P (XFmode) && (!TARGET_FISTTP || TARGET_SSE_MATH)))
#define HAVE_fixuns_truncsfsi2 (!TARGET_64BIT && TARGET_SSE2 && TARGET_SSE_MATH)
#define HAVE_fixuns_truncdfsi2 (!TARGET_64BIT && TARGET_SSE2 && TARGET_SSE_MATH)
#define HAVE_fixuns_truncsfhi2 (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
#define HAVE_fixuns_truncdfhi2 (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
#define HAVE_floatsisf2 (TARGET_80387 || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
#define HAVE_floatdisf2 ((TARGET_80387 || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)) && (TARGET_64BIT))
#define HAVE_floatsidf2 (TARGET_80387 || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
#define HAVE_floatdidf2 ((TARGET_80387 || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)) && (TARGET_64BIT))
#define HAVE_floatunsqisf2 (!TARGET_64BIT \
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
#define HAVE_floatunshisf2 (!TARGET_64BIT \
   && SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
#define HAVE_floatunsqidf2 (!TARGET_64BIT \
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
#define HAVE_floatunshidf2 (!TARGET_64BIT \
   && SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
#define HAVE_floatunssisf2 (!TARGET_64BIT \
   && ((TARGET_80387 && X87_ENABLE_FLOAT (SFmode, DImode) \
	&& TARGET_SSE2 && TARGET_INTER_UNIT_MOVES_TO_VEC) \
       || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)))
#define HAVE_floatunssidf2 (!TARGET_64BIT \
   && ((TARGET_80387 && X87_ENABLE_FLOAT (DFmode, DImode) \
	&& TARGET_SSE2 && TARGET_INTER_UNIT_MOVES_TO_VEC) \
       || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)))
#define HAVE_floatunssixf2 (!TARGET_64BIT \
   && ((TARGET_80387 && X87_ENABLE_FLOAT (XFmode, DImode) \
	&& TARGET_SSE2 && TARGET_INTER_UNIT_MOVES_TO_VEC) \
       || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH)))
#define HAVE_floatunsdisf2 (TARGET_64BIT && TARGET_SSE_MATH)
#define HAVE_floatunsdidf2 ((TARGET_64BIT || TARGET_KEEPS_VECTOR_ALIGNED_STACK) \
   && TARGET_SSE2 && TARGET_SSE_MATH)
#define HAVE_addqi3 (TARGET_QIMODE_MATH)
#define HAVE_addhi3 (TARGET_HIMODE_MATH)
#define HAVE_addsi3 1
#define HAVE_adddi3 1
#define HAVE_addti3 (TARGET_64BIT)
#define HAVE_addvqi4 1
#define HAVE_addvhi4 1
#define HAVE_addvsi4 1
#define HAVE_addvdi4 (TARGET_64BIT)
#define HAVE_uaddvqi4 1
#define HAVE_uaddvhi4 1
#define HAVE_uaddvsi4 1
#define HAVE_uaddvdi4 (TARGET_64BIT)
#define HAVE_subqi3 (TARGET_QIMODE_MATH)
#define HAVE_subhi3 (TARGET_HIMODE_MATH)
#define HAVE_subsi3 1
#define HAVE_subdi3 1
#define HAVE_subti3 (TARGET_64BIT)
#define HAVE_subvqi4 1
#define HAVE_subvhi4 1
#define HAVE_subvsi4 1
#define HAVE_subvdi4 (TARGET_64BIT)
#define HAVE_usubvqi4 1
#define HAVE_usubvhi4 1
#define HAVE_usubvsi4 1
#define HAVE_usubvdi4 (TARGET_64BIT)
#define HAVE_addqi3_cconly_overflow (!(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_addxf3 (TARGET_80387)
#define HAVE_subxf3 (TARGET_80387)
#define HAVE_addsf3 ((TARGET_80387 && X87_ENABLE_ARITH (SFmode)) \
    || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
#define HAVE_subsf3 ((TARGET_80387 && X87_ENABLE_ARITH (SFmode)) \
    || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
#define HAVE_adddf3 ((TARGET_80387 && X87_ENABLE_ARITH (DFmode)) \
    || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
#define HAVE_subdf3 ((TARGET_80387 && X87_ENABLE_ARITH (DFmode)) \
    || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
#define HAVE_mulhi3 (TARGET_HIMODE_MATH)
#define HAVE_mulsi3 1
#define HAVE_muldi3 (TARGET_64BIT)
#define HAVE_mulqi3 (TARGET_QIMODE_MATH)
#define HAVE_mulvhi4 1
#define HAVE_mulvsi4 1
#define HAVE_mulvdi4 (TARGET_64BIT)
#define HAVE_umulvhi4 1
#define HAVE_umulvsi4 1
#define HAVE_umulvdi4 (TARGET_64BIT)
#define HAVE_mulvqi4 (TARGET_QIMODE_MATH)
#define HAVE_umulvqi4 (TARGET_QIMODE_MATH)
#define HAVE_mulsidi3 (!TARGET_64BIT)
#define HAVE_umulsidi3 (!TARGET_64BIT)
#define HAVE_mulditi3 (TARGET_64BIT)
#define HAVE_umulditi3 (TARGET_64BIT)
#define HAVE_mulqihi3 (TARGET_QIMODE_MATH)
#define HAVE_umulqihi3 (TARGET_QIMODE_MATH)
#define HAVE_smulsi3_highpart 1
#define HAVE_umulsi3_highpart 1
#define HAVE_smuldi3_highpart (TARGET_64BIT)
#define HAVE_umuldi3_highpart (TARGET_64BIT)
#define HAVE_mulxf3 (TARGET_80387)
#define HAVE_mulsf3 ((TARGET_80387 && X87_ENABLE_ARITH (SFmode)) \
    || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
#define HAVE_muldf3 ((TARGET_80387 && X87_ENABLE_ARITH (DFmode)) \
    || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
#define HAVE_divxf3 (TARGET_80387)
#define HAVE_divdf3 ((TARGET_80387 && X87_ENABLE_ARITH (DFmode)) \
    || (TARGET_SSE2 && TARGET_SSE_MATH))
#define HAVE_divsf3 ((TARGET_80387 && X87_ENABLE_ARITH (SFmode)) \
    || TARGET_SSE_MATH)
#define HAVE_divmodhi4 (TARGET_HIMODE_MATH)
#define HAVE_divmodsi4 1
#define HAVE_divmoddi4 (TARGET_64BIT)
#define HAVE_divmodqi4 (TARGET_QIMODE_MATH)
#define HAVE_udivmodhi4 (TARGET_HIMODE_MATH)
#define HAVE_udivmodsi4 1
#define HAVE_udivmoddi4 (TARGET_64BIT)
#define HAVE_udivmodqi4 (TARGET_QIMODE_MATH)
#define HAVE_testsi_ccno_1 1
#define HAVE_testqi_ccz_1 1
#define HAVE_testdi_ccno_1 (TARGET_64BIT && !(MEM_P (operands[0]) && MEM_P (operands[1])))
#define HAVE_testqi_ext_ccno_0 1
#define HAVE_andqi3 (TARGET_QIMODE_MATH)
#define HAVE_andhi3 (TARGET_HIMODE_MATH)
#define HAVE_andsi3 1
#define HAVE_anddi3 ((TARGET_STV && TARGET_SSE2) || TARGET_64BIT)
#define HAVE_iorqi3 (TARGET_QIMODE_MATH)
#define HAVE_xorqi3 (TARGET_QIMODE_MATH)
#define HAVE_iorhi3 (TARGET_HIMODE_MATH)
#define HAVE_xorhi3 (TARGET_HIMODE_MATH)
#define HAVE_iorsi3 1
#define HAVE_xorsi3 1
#define HAVE_iordi3 ((TARGET_STV && TARGET_SSE2) || TARGET_64BIT)
#define HAVE_xordi3 ((TARGET_STV && TARGET_SSE2) || TARGET_64BIT)
#define HAVE_xorqi_cc_ext_1 1
#define HAVE_negqi2 (TARGET_QIMODE_MATH)
#define HAVE_neghi2 (TARGET_HIMODE_MATH)
#define HAVE_negsi2 1
#define HAVE_negdi2 1
#define HAVE_negti2 (TARGET_64BIT)
#define HAVE_negvqi3 1
#define HAVE_negvhi3 1
#define HAVE_negvsi3 1
#define HAVE_negvdi3 (TARGET_64BIT)
#define HAVE_abssf2 (TARGET_80387 || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
#define HAVE_negsf2 (TARGET_80387 || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
#define HAVE_absdf2 (TARGET_80387 || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
#define HAVE_negdf2 (TARGET_80387 || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
#define HAVE_absxf2 (TARGET_80387 || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
#define HAVE_negxf2 (TARGET_80387 || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
#define HAVE_abstf2 (TARGET_SSE)
#define HAVE_negtf2 (TARGET_SSE)
#define HAVE_copysignsf3 ((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
   || (TARGET_SSE && (SFmode == TFmode)))
#define HAVE_copysigndf3 ((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
   || (TARGET_SSE && (DFmode == TFmode)))
#define HAVE_copysigntf3 ((SSE_FLOAT_MODE_P (TFmode) && TARGET_SSE_MATH) \
   || (TARGET_SSE && (TFmode == TFmode)))
#define HAVE_one_cmplqi2 (TARGET_QIMODE_MATH)
#define HAVE_one_cmplhi2 (TARGET_HIMODE_MATH)
#define HAVE_one_cmplsi2 1
#define HAVE_one_cmpldi2 (TARGET_64BIT)
#define HAVE_ashlqi3 (TARGET_QIMODE_MATH)
#define HAVE_ashlhi3 (TARGET_HIMODE_MATH)
#define HAVE_ashlsi3 1
#define HAVE_ashldi3 1
#define HAVE_ashlti3 (TARGET_64BIT)
#define HAVE_x86_shiftsi_adj_1 (TARGET_CMOVE)
#define HAVE_x86_shiftdi_adj_1 ((TARGET_CMOVE) && (TARGET_64BIT))
#define HAVE_x86_shiftsi_adj_2 1
#define HAVE_x86_shiftdi_adj_2 (TARGET_64BIT)
#define HAVE_lshrqi3 (TARGET_QIMODE_MATH)
#define HAVE_ashrqi3 (TARGET_QIMODE_MATH)
#define HAVE_lshrhi3 (TARGET_HIMODE_MATH)
#define HAVE_ashrhi3 (TARGET_HIMODE_MATH)
#define HAVE_lshrsi3 1
#define HAVE_ashrsi3 1
#define HAVE_lshrdi3 1
#define HAVE_ashrdi3 1
#define HAVE_lshrti3 (TARGET_64BIT)
#define HAVE_ashrti3 (TARGET_64BIT)
#define HAVE_x86_shiftsi_adj_3 1
#define HAVE_x86_shiftdi_adj_3 (TARGET_64BIT)
#define HAVE_rotlti3 (TARGET_64BIT)
#define HAVE_rotrti3 (TARGET_64BIT)
#define HAVE_rotldi3 1
#define HAVE_rotrdi3 1
#define HAVE_rotlqi3 (TARGET_QIMODE_MATH)
#define HAVE_rotrqi3 (TARGET_QIMODE_MATH)
#define HAVE_rotlhi3 (TARGET_HIMODE_MATH)
#define HAVE_rotrhi3 (TARGET_HIMODE_MATH)
#define HAVE_rotlsi3 1
#define HAVE_rotrsi3 1
#define HAVE_indirect_jump 1
#define HAVE_tablejump 1
#define HAVE_call 1
#define HAVE_sibcall 1
#define HAVE_call_pop (!TARGET_64BIT)
#define HAVE_call_value 1
#define HAVE_sibcall_value 1
#define HAVE_call_value_pop (!TARGET_64BIT)
#define HAVE_untyped_call 1
#define HAVE_memory_blockage 1
#define HAVE_return (ix86_can_use_return_insn_p ())
#define HAVE_simple_return (!TARGET_SEH && !ix86_static_chain_on_stack)
#define HAVE_prologue 1
#define HAVE_set_got (!TARGET_64BIT)
#define HAVE_set_got_labelled (!TARGET_64BIT)
#define HAVE_epilogue 1
#define HAVE_sibcall_epilogue 1
#define HAVE_eh_return 1
#define HAVE_split_stack_prologue 1
#define HAVE_split_stack_space_check 1
#define HAVE_ffssi2 1
#define HAVE_ffsdi2 (TARGET_64BIT)
#define HAVE_ctzhi2 1
#define HAVE_ctzsi2 1
#define HAVE_ctzdi2 (TARGET_64BIT)
#define HAVE_clzhi2 1
#define HAVE_clzsi2 1
#define HAVE_clzdi2 (TARGET_64BIT)
#define HAVE_clzhi2_lzcnt (TARGET_LZCNT)
#define HAVE_clzsi2_lzcnt (TARGET_LZCNT)
#define HAVE_clzdi2_lzcnt ((TARGET_LZCNT) && (TARGET_64BIT))
#define HAVE_bmi2_bzhi_si3 (TARGET_BMI2)
#define HAVE_bmi2_bzhi_di3 ((TARGET_BMI2) && (TARGET_64BIT))
#define HAVE_popcounthi2 (TARGET_POPCNT)
#define HAVE_popcountsi2 (TARGET_POPCNT)
#define HAVE_popcountdi2 ((TARGET_POPCNT) && (TARGET_64BIT))
#define HAVE_bswapdi2 (TARGET_64BIT)
#define HAVE_bswapsi2 1
#define HAVE_paritydi2 (! TARGET_POPCNT)
#define HAVE_paritysi2 (! TARGET_POPCNT)
#define HAVE_tls_global_dynamic_32 1
#define HAVE_tls_global_dynamic_64_si ((TARGET_64BIT) && (Pmode == SImode))
#define HAVE_tls_global_dynamic_64_di ((TARGET_64BIT) && (Pmode == DImode))
#define HAVE_tls_local_dynamic_base_32 1
#define HAVE_tls_local_dynamic_base_64_si ((TARGET_64BIT) && (Pmode == SImode))
#define HAVE_tls_local_dynamic_base_64_di ((TARGET_64BIT) && (Pmode == DImode))
#define HAVE_tls_dynamic_gnu2_32 (!TARGET_64BIT && TARGET_GNU2_TLS)
#define HAVE_tls_dynamic_gnu2_64 (TARGET_64BIT && TARGET_GNU2_TLS)
#define HAVE_rsqrtsf2 (TARGET_SSE_MATH)
#define HAVE_sqrtsf2 ((TARGET_USE_FANCY_MATH_387 && X87_ENABLE_ARITH (SFmode)) \
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
#define HAVE_sqrtdf2 ((TARGET_USE_FANCY_MATH_387 && X87_ENABLE_ARITH (DFmode)) \
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
#define HAVE_fmodxf3 (TARGET_USE_FANCY_MATH_387 \
   && flag_finite_math_only)
#define HAVE_fmodsf3 (TARGET_USE_FANCY_MATH_387 \
   && flag_finite_math_only)
#define HAVE_fmoddf3 (TARGET_USE_FANCY_MATH_387 \
   && flag_finite_math_only)
#define HAVE_remainderxf3 (TARGET_USE_FANCY_MATH_387 \
   && flag_finite_math_only)
#define HAVE_remaindersf3 (TARGET_USE_FANCY_MATH_387 \
   && flag_finite_math_only)
#define HAVE_remainderdf3 (TARGET_USE_FANCY_MATH_387 \
   && flag_finite_math_only)
#define HAVE_sincossf3 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_sincosdf3 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_tanxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_tansf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_tandf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_atan2xf3 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_atan2sf3 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_atan2df3 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_atanxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_atansf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_atandf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_asinxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_asinsf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_asindf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_acosxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_acossf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_acosdf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_logxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_logsf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_logdf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_log10xf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_log10sf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_log10df2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_log2xf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_log2sf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_log2df2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_log1pxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_log1psf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_log1pdf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_logbxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_logbsf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_logbdf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_ilogbxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_ilogbsf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_ilogbdf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_expNcorexf3 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_expxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_expsf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_expdf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_exp10xf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_exp10sf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_exp10df2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_exp2xf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_exp2sf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_exp2df2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_expm1xf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_expm1sf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_expm1df2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_ldexpxf3 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_ldexpsf3 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_ldexpdf3 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_scalbxf3 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_scalbsf3 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_scalbdf3 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_significandxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_significandsf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_significanddf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_rintsf2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH \
       && !flag_trapping_math))
#define HAVE_rintdf2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH \
       && !flag_trapping_math))
#define HAVE_roundsf2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH \
       && !flag_trapping_math && !flag_rounding_math))
#define HAVE_rounddf2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH \
       && !flag_trapping_math && !flag_rounding_math))
#define HAVE_roundxf2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH \
       && !flag_trapping_math && !flag_rounding_math))
#define HAVE_lrintxfhi2 (TARGET_USE_FANCY_MATH_387)
#define HAVE_lrintxfsi2 (TARGET_USE_FANCY_MATH_387)
#define HAVE_lrintxfdi2 (TARGET_USE_FANCY_MATH_387)
#define HAVE_lrintsfsi2 (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH)
#define HAVE_lrintsfdi2 ((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) && (TARGET_64BIT))
#define HAVE_lrintdfsi2 (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH)
#define HAVE_lrintdfdi2 ((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) && (TARGET_64BIT))
#define HAVE_lroundsfhi2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH \
       && HImode != HImode  \
       && ((HImode != DImode) || TARGET_64BIT) \
       && !flag_trapping_math && !flag_rounding_math))
#define HAVE_lrounddfhi2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH \
       && HImode != HImode  \
       && ((HImode != DImode) || TARGET_64BIT) \
       && !flag_trapping_math && !flag_rounding_math))
#define HAVE_lroundxfhi2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH \
       && HImode != HImode  \
       && ((HImode != DImode) || TARGET_64BIT) \
       && !flag_trapping_math && !flag_rounding_math))
#define HAVE_lroundsfsi2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH \
       && SImode != HImode  \
       && ((SImode != DImode) || TARGET_64BIT) \
       && !flag_trapping_math && !flag_rounding_math))
#define HAVE_lrounddfsi2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH \
       && SImode != HImode  \
       && ((SImode != DImode) || TARGET_64BIT) \
       && !flag_trapping_math && !flag_rounding_math))
#define HAVE_lroundxfsi2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH \
       && SImode != HImode  \
       && ((SImode != DImode) || TARGET_64BIT) \
       && !flag_trapping_math && !flag_rounding_math))
#define HAVE_lroundsfdi2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH \
       && DImode != HImode  \
       && ((DImode != DImode) || TARGET_64BIT) \
       && !flag_trapping_math && !flag_rounding_math))
#define HAVE_lrounddfdi2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH \
       && DImode != HImode  \
       && ((DImode != DImode) || TARGET_64BIT) \
       && !flag_trapping_math && !flag_rounding_math))
#define HAVE_lroundxfdi2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH \
       && DImode != HImode  \
       && ((DImode != DImode) || TARGET_64BIT) \
       && !flag_trapping_math && !flag_rounding_math))
#define HAVE_floorxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_ceilxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_btruncxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_floorsf2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH \
       && !flag_trapping_math))
#define HAVE_ceilsf2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH \
       && !flag_trapping_math))
#define HAVE_btruncsf2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH \
       && !flag_trapping_math))
#define HAVE_floordf2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH \
       && !flag_trapping_math))
#define HAVE_ceildf2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH \
       && !flag_trapping_math))
#define HAVE_btruncdf2 ((TARGET_USE_FANCY_MATH_387 \
    && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
	|| TARGET_MIX_SSE_I387) \
    && flag_unsafe_math_optimizations) \
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH \
       && !flag_trapping_math))
#define HAVE_nearbyintxf2 (TARGET_USE_FANCY_MATH_387 \
   && flag_unsafe_math_optimizations)
#define HAVE_nearbyintsf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_nearbyintdf2 (TARGET_USE_FANCY_MATH_387 \
   && (!(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH) \
       || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_lfloorxfhi2 (TARGET_USE_FANCY_MATH_387 \
   && (!TARGET_SSE_MATH || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_lceilxfhi2 (TARGET_USE_FANCY_MATH_387 \
   && (!TARGET_SSE_MATH || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_lfloorxfsi2 (TARGET_USE_FANCY_MATH_387 \
   && (!TARGET_SSE_MATH || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_lceilxfsi2 (TARGET_USE_FANCY_MATH_387 \
   && (!TARGET_SSE_MATH || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_lfloorxfdi2 (TARGET_USE_FANCY_MATH_387 \
   && (!TARGET_SSE_MATH || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_lceilxfdi2 (TARGET_USE_FANCY_MATH_387 \
   && (!TARGET_SSE_MATH || TARGET_MIX_SSE_I387) \
   && flag_unsafe_math_optimizations)
#define HAVE_lfloorsfsi2 (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH \
   && !flag_trapping_math)
#define HAVE_lceilsfsi2 (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH \
   && !flag_trapping_math)
#define HAVE_lfloorsfdi2 ((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH \
   && !flag_trapping_math) && (TARGET_64BIT))
#define HAVE_lceilsfdi2 ((SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH \
   && !flag_trapping_math) && (TARGET_64BIT))
#define HAVE_lfloordfsi2 (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH \
   && !flag_trapping_math)
#define HAVE_lceildfsi2 (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH \
   && !flag_trapping_math)
#define HAVE_lfloordfdi2 ((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH \
   && !flag_trapping_math) && (TARGET_64BIT))
#define HAVE_lceildfdi2 ((SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH \
   && !flag_trapping_math) && (TARGET_64BIT))
#define HAVE_isinfxf2 (TARGET_USE_FANCY_MATH_387 \
   && ix86_libc_has_function (function_c99_misc))
#define HAVE_isinfsf2 (TARGET_USE_FANCY_MATH_387 \
   && ix86_libc_has_function (function_c99_misc) \
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
#define HAVE_isinfdf2 (TARGET_USE_FANCY_MATH_387 \
   && ix86_libc_has_function (function_c99_misc) \
   && !(SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
#define HAVE_signbitxf2 (TARGET_USE_FANCY_MATH_387)
#define HAVE_signbitdf2 (TARGET_USE_FANCY_MATH_387 \
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
#define HAVE_signbitsf2 (TARGET_USE_FANCY_MATH_387 \
   && !(SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
#define HAVE_movmemsi 1
#define HAVE_movmemdi (TARGET_64BIT)
#define HAVE_strmov 1
#define HAVE_strmov_singleop 1
#define HAVE_rep_mov 1
#define HAVE_setmemsi 1
#define HAVE_setmemdi (TARGET_64BIT)
#define HAVE_strset 1
#define HAVE_strset_singleop 1
#define HAVE_rep_stos 1
#define HAVE_cmpstrnsi 1
#define HAVE_cmpintqi 1
#define HAVE_cmpstrnqi_nz_1 1
#define HAVE_cmpstrnqi_1 1
#define HAVE_strlensi (Pmode == SImode)
#define HAVE_strlendi (Pmode == DImode)
#define HAVE_strlenqi_1 1
#define HAVE_movqicc (TARGET_QIMODE_MATH)
#define HAVE_movhicc (TARGET_HIMODE_MATH)
#define HAVE_movsicc 1
#define HAVE_movdicc (TARGET_64BIT)
#define HAVE_x86_movsicc_0_m1 1
#define HAVE_x86_movdicc_0_m1 (TARGET_64BIT)
#define HAVE_movsfcc ((TARGET_80387 && TARGET_CMOVE) \
   || (SSE_FLOAT_MODE_P (SFmode) && TARGET_SSE_MATH))
#define HAVE_movdfcc ((TARGET_80387 && TARGET_CMOVE) \
   || (SSE_FLOAT_MODE_P (DFmode) && TARGET_SSE_MATH))
#define HAVE_movxfcc ((TARGET_80387 && TARGET_CMOVE) \
   || (SSE_FLOAT_MODE_P (XFmode) && TARGET_SSE_MATH))
#define HAVE_addqicc 1
#define HAVE_addhicc 1
#define HAVE_addsicc 1
#define HAVE_adddicc (TARGET_64BIT)
#define HAVE_allocate_stack (ix86_target_stack_probe ())
#define HAVE_probe_stack 1
#define HAVE_builtin_setjmp_receiver (!TARGET_64BIT && flag_pic)
#define HAVE_prefetch (TARGET_PREFETCH_SSE || TARGET_PRFCHW || TARGET_PREFETCHWT1)
#define HAVE_stack_protect_set (TARGET_SSP_TLS_GUARD)
#define HAVE_stack_protect_test (TARGET_SSP_TLS_GUARD)
#define HAVE_lwp_llwpcb (TARGET_LWP)
#define HAVE_lwp_slwpcb (TARGET_LWP)
#define HAVE_lwp_lwpvalsi3 (TARGET_LWP)
#define HAVE_lwp_lwpvaldi3 ((TARGET_LWP) && (TARGET_64BIT))
#define HAVE_lwp_lwpinssi3 (TARGET_LWP)
#define HAVE_lwp_lwpinsdi3 ((TARGET_LWP) && (TARGET_64BIT))
#define HAVE_pause 1
#define HAVE_xbegin (TARGET_RTM)
#define HAVE_xtest (TARGET_RTM)
#define HAVE_bnd32_mk ((TARGET_MPX) && (!TARGET_LP64))
#define HAVE_bnd64_mk ((TARGET_MPX) && (TARGET_LP64))
#define HAVE_movbnd32 ((TARGET_MPX) && (!TARGET_LP64))
#define HAVE_movbnd64 ((TARGET_MPX) && (TARGET_LP64))
#define HAVE_bnd32_cl ((TARGET_MPX) && (!TARGET_LP64))
#define HAVE_bnd32_cu ((TARGET_MPX) && (!TARGET_LP64))
#define HAVE_bnd32_cn ((TARGET_MPX) && (!TARGET_LP64))
#define HAVE_bnd64_cl ((TARGET_MPX) && (TARGET_LP64))
#define HAVE_bnd64_cu ((TARGET_MPX) && (TARGET_LP64))
#define HAVE_bnd64_cn ((TARGET_MPX) && (TARGET_LP64))
#define HAVE_bnd32_ldx ((TARGET_MPX) && (!TARGET_LP64))
#define HAVE_bnd64_ldx ((TARGET_MPX) && (TARGET_LP64))
#define HAVE_bnd32_stx ((TARGET_MPX) && (!TARGET_LP64))
#define HAVE_bnd64_stx ((TARGET_MPX) && (TARGET_LP64))
#define HAVE_rdpkru (TARGET_PKU)
#define HAVE_wrpkru (TARGET_PKU)
#define HAVE_movv8qi (TARGET_MMX)
#define HAVE_movv4hi (TARGET_MMX)
#define HAVE_movv2si (TARGET_MMX)
#define HAVE_movv1di (TARGET_MMX)
#define HAVE_movv2sf (TARGET_MMX)
#define HAVE_movmisalignv8qi (TARGET_MMX)
#define HAVE_movmisalignv4hi (TARGET_MMX)
#define HAVE_movmisalignv2si (TARGET_MMX)
#define HAVE_movmisalignv1di (TARGET_MMX)
#define HAVE_movmisalignv2sf (TARGET_MMX)
#define HAVE_mmx_addv2sf3 (TARGET_3DNOW)
#define HAVE_mmx_subv2sf3 (TARGET_3DNOW)
#define HAVE_mmx_subrv2sf3 (TARGET_3DNOW)
#define HAVE_mmx_mulv2sf3 (TARGET_3DNOW)
#define HAVE_mmx_smaxv2sf3 (TARGET_3DNOW)
#define HAVE_mmx_sminv2sf3 (TARGET_3DNOW)
#define HAVE_mmx_eqv2sf3 (TARGET_3DNOW)
#define HAVE_vec_setv2sf (TARGET_MMX)
#define HAVE_vec_extractv2sf (TARGET_MMX)
#define HAVE_vec_initv2sf (TARGET_SSE)
#define HAVE_mmx_addv8qi3 (TARGET_MMX || (TARGET_SSE2 && V8QImode == V1DImode))
#define HAVE_mmx_subv8qi3 (TARGET_MMX || (TARGET_SSE2 && V8QImode == V1DImode))
#define HAVE_mmx_addv4hi3 (TARGET_MMX || (TARGET_SSE2 && V4HImode == V1DImode))
#define HAVE_mmx_subv4hi3 (TARGET_MMX || (TARGET_SSE2 && V4HImode == V1DImode))
#define HAVE_mmx_addv2si3 (TARGET_MMX || (TARGET_SSE2 && V2SImode == V1DImode))
#define HAVE_mmx_subv2si3 (TARGET_MMX || (TARGET_SSE2 && V2SImode == V1DImode))
#define HAVE_mmx_addv1di3 (TARGET_MMX || (TARGET_SSE2 && V1DImode == V1DImode))
#define HAVE_mmx_subv1di3 (TARGET_MMX || (TARGET_SSE2 && V1DImode == V1DImode))
#define HAVE_mmx_ssaddv8qi3 (TARGET_MMX)
#define HAVE_mmx_usaddv8qi3 (TARGET_MMX)
#define HAVE_mmx_sssubv8qi3 (TARGET_MMX)
#define HAVE_mmx_ussubv8qi3 (TARGET_MMX)
#define HAVE_mmx_ssaddv4hi3 (TARGET_MMX)
#define HAVE_mmx_usaddv4hi3 (TARGET_MMX)
#define HAVE_mmx_sssubv4hi3 (TARGET_MMX)
#define HAVE_mmx_ussubv4hi3 (TARGET_MMX)
#define HAVE_mmx_mulv4hi3 (TARGET_MMX)
#define HAVE_mmx_smulv4hi3_highpart (TARGET_MMX)
#define HAVE_mmx_umulv4hi3_highpart (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_mmx_pmaddwd (TARGET_MMX)
#define HAVE_mmx_pmulhrwv4hi3 (TARGET_3DNOW)
#define HAVE_sse2_umulv1siv1di3 (TARGET_SSE2)
#define HAVE_mmx_smaxv4hi3 (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_mmx_sminv4hi3 (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_mmx_umaxv8qi3 (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_mmx_uminv8qi3 (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_mmx_eqv8qi3 (TARGET_MMX)
#define HAVE_mmx_eqv4hi3 (TARGET_MMX)
#define HAVE_mmx_eqv2si3 (TARGET_MMX)
#define HAVE_mmx_andv8qi3 (TARGET_MMX)
#define HAVE_mmx_iorv8qi3 (TARGET_MMX)
#define HAVE_mmx_xorv8qi3 (TARGET_MMX)
#define HAVE_mmx_andv4hi3 (TARGET_MMX)
#define HAVE_mmx_iorv4hi3 (TARGET_MMX)
#define HAVE_mmx_xorv4hi3 (TARGET_MMX)
#define HAVE_mmx_andv2si3 (TARGET_MMX)
#define HAVE_mmx_iorv2si3 (TARGET_MMX)
#define HAVE_mmx_xorv2si3 (TARGET_MMX)
#define HAVE_mmx_pinsrw (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_mmx_pshufw (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_vec_setv2si (TARGET_MMX)
#define HAVE_vec_extractv2si (TARGET_MMX)
#define HAVE_vec_initv2si (TARGET_SSE)
#define HAVE_vec_setv4hi (TARGET_MMX)
#define HAVE_vec_extractv4hi (TARGET_MMX)
#define HAVE_vec_initv4hi (TARGET_SSE)
#define HAVE_vec_setv8qi (TARGET_MMX)
#define HAVE_vec_extractv8qi (TARGET_MMX)
#define HAVE_vec_initv8qi (TARGET_SSE)
#define HAVE_mmx_uavgv8qi3 (TARGET_SSE || TARGET_3DNOW)
#define HAVE_mmx_uavgv4hi3 (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_mmx_maskmovq (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_mmx_emms (TARGET_MMX)
#define HAVE_mmx_femms (TARGET_3DNOW)
#define HAVE_movv64qi ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_movv32qi ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movv16qi (TARGET_SSE)
#define HAVE_movv32hi ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_movv16hi ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movv8hi (TARGET_SSE)
#define HAVE_movv16si ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_movv8si ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movv4si (TARGET_SSE)
#define HAVE_movv8di ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_movv4di ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movv2di (TARGET_SSE)
#define HAVE_movv4ti ((TARGET_SSE) && (TARGET_AVX512BW))
#define HAVE_movv2ti ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movv1ti (TARGET_SSE)
#define HAVE_movv16sf ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_movv8sf ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movv4sf (TARGET_SSE)
#define HAVE_movv8df ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_movv4df ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movv2df (TARGET_SSE)
#define HAVE_movmisalignv64qi ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_movmisalignv32qi ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movmisalignv16qi (TARGET_SSE)
#define HAVE_movmisalignv32hi ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_movmisalignv16hi ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movmisalignv8hi (TARGET_SSE)
#define HAVE_movmisalignv16si ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_movmisalignv8si ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movmisalignv4si (TARGET_SSE)
#define HAVE_movmisalignv8di ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_movmisalignv4di ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movmisalignv2di (TARGET_SSE)
#define HAVE_movmisalignv4ti ((TARGET_SSE) && (TARGET_AVX512BW))
#define HAVE_movmisalignv2ti ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movmisalignv1ti (TARGET_SSE)
#define HAVE_movmisalignv16sf ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_movmisalignv8sf ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movmisalignv4sf (TARGET_SSE)
#define HAVE_movmisalignv8df ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_movmisalignv4df ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_movmisalignv2df (TARGET_SSE)
#define HAVE_avx512f_loadups512 ((TARGET_SSE && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_loadups512_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx_loadups256 ((TARGET_SSE && 1) && (TARGET_AVX))
#define HAVE_avx_loadups256_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX)))
#define HAVE_sse_loadups (TARGET_SSE && 1)
#define HAVE_sse_loadups_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_avx512f_loadupd512 ((TARGET_SSE && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_loadupd512_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx_loadupd256 ((TARGET_SSE && 1) && (TARGET_AVX))
#define HAVE_avx_loadupd256_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX)))
#define HAVE_sse2_loadupd ((TARGET_SSE && 1) && (TARGET_SSE2))
#define HAVE_sse2_loadupd_mask ((TARGET_AVX512F) && ((TARGET_SSE && (16 == 64 || TARGET_AVX512VL)) && (TARGET_SSE2)))
#define HAVE_avx_loaddquv32qi ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX))
#define HAVE_avx_loaddquv32qi_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && TARGET_AVX512VL && TARGET_AVX512BW) && (TARGET_AVX)))
#define HAVE_sse2_loaddquv16qi (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_loaddquv16qi_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL && TARGET_AVX512BW))
#define HAVE_avx512f_loaddquv64qi (TARGET_AVX512BW)
#define HAVE_avx512f_loaddquv64qi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512bw_loaddquv32hi (TARGET_AVX512BW)
#define HAVE_avx512bw_loaddquv32hi_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_loaddquv8hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_loaddquv8hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_loaddquv16hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_loaddquv16hi_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512f_loaddquv16si (TARGET_AVX512F)
#define HAVE_avx512f_loaddquv16si_mask (TARGET_AVX512F)
#define HAVE_avx_loaddquv8si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx_loaddquv8si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_sse2_loaddquv4si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_sse2_loaddquv4si_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_loaddquv8di (TARGET_AVX512F)
#define HAVE_avx512f_loaddquv8di_mask (TARGET_AVX512F)
#define HAVE_avx512vl_loaddquv4di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_loaddquv4di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_loaddquv2di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_loaddquv2di_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_storentdi ((TARGET_SSE) && (TARGET_SSE2 && TARGET_64BIT))
#define HAVE_storentsi ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_storentsf ((TARGET_SSE) && (TARGET_SSE4A))
#define HAVE_storentdf ((TARGET_SSE) && (TARGET_SSE4A))
#define HAVE_storentv8di ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_storentv4di ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_storentv2di ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_storentv16sf ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_storentv8sf ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_storentv4sf (TARGET_SSE)
#define HAVE_storentv8df ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_storentv4df ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_storentv2df ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_absv16sf2 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_negv16sf2 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_absv8sf2 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_negv8sf2 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_absv4sf2 (TARGET_SSE)
#define HAVE_negv4sf2 (TARGET_SSE)
#define HAVE_absv8df2 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_negv8df2 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_absv4df2 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_negv4df2 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_absv2df2 ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_negv2df2 ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_addv16sf3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_addv16sf3_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_addv16sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_addv16sf3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_subv16sf3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_subv16sf3_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_subv16sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_subv16sf3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_addv8sf3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_addv8sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_subv8sf3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_subv8sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_addv4sf3 (TARGET_SSE && 1 && 1)
#define HAVE_addv4sf3_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1))
#define HAVE_subv4sf3 (TARGET_SSE && 1 && 1)
#define HAVE_subv4sf3_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1))
#define HAVE_addv8df3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_addv8df3_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_addv8df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_addv8df3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_subv8df3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_subv8df3_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_subv8df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_subv8df3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_addv4df3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_addv4df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_subv4df3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_subv4df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_addv2df3 ((TARGET_SSE && 1 && 1) && (TARGET_SSE2))
#define HAVE_addv2df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_SSE2)))
#define HAVE_subv2df3 ((TARGET_SSE && 1 && 1) && (TARGET_SSE2))
#define HAVE_subv2df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_SSE2)))
#define HAVE_mulv16sf3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_mulv16sf3_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_mulv16sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_mulv16sf3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
							      || V16SFmode == V8DFmode \
							      || V16SFmode == V8DImode \
							      || V16SFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_mulv8sf3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_mulv8sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_mulv4sf3 (TARGET_SSE && 1 && 1)
#define HAVE_mulv4sf3_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1))
#define HAVE_mulv8df3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_mulv8df3_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_mulv8df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_mulv8df3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
							      || V8DFmode == V8DFmode \
							      || V8DFmode == V8DImode \
							      || V8DFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_mulv4df3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_mulv4df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_mulv2df3 ((TARGET_SSE && 1 && 1) && (TARGET_SSE2))
#define HAVE_mulv2df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_SSE2)))
#define HAVE_divv8df3 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_divv4df3 ((TARGET_SSE2) && (TARGET_AVX))
#define HAVE_divv2df3 (TARGET_SSE2)
#define HAVE_divv16sf3 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_divv8sf3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_divv4sf3 (TARGET_SSE)
#define HAVE_sqrtv8df2 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_sqrtv4df2 ((TARGET_SSE2) && (TARGET_AVX))
#define HAVE_sqrtv2df2 (TARGET_SSE2)
#define HAVE_sqrtv16sf2 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_sqrtv8sf2 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_sqrtv4sf2 (TARGET_SSE)
#define HAVE_rsqrtv8sf2 ((TARGET_SSE_MATH) && (TARGET_AVX))
#define HAVE_rsqrtv4sf2 (TARGET_SSE_MATH)
#define HAVE_smaxv16sf3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_smaxv16sf3_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V16SFmode == V16SFmode \
									      || V16SFmode == V8DFmode \
									      || V16SFmode == V8DImode \
									      || V16SFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_smaxv16sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_smaxv16sf3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
									      || V16SFmode == V8DFmode \
									      || V16SFmode == V8DImode \
									      || V16SFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_sminv16sf3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_sminv16sf3_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V16SFmode == V16SFmode \
									      || V16SFmode == V8DFmode \
									      || V16SFmode == V8DImode \
									      || V16SFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_sminv16sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_sminv16sf3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V16SFmode == V16SFmode \
									      || V16SFmode == V8DFmode \
									      || V16SFmode == V8DImode \
									      || V16SFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_smaxv8sf3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_smaxv8sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_sminv8sf3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_sminv8sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_smaxv4sf3 (TARGET_SSE && 1 && 1)
#define HAVE_smaxv4sf3_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1))
#define HAVE_sminv4sf3 (TARGET_SSE && 1 && 1)
#define HAVE_sminv4sf3_mask ((TARGET_AVX512F) && (TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1))
#define HAVE_smaxv8df3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_smaxv8df3_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_smaxv8df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_smaxv8df3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_sminv8df3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX512F))
#define HAVE_sminv8df3_round ((TARGET_AVX512F) && ((TARGET_SSE && 1 && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode)) && (TARGET_AVX512F)))
#define HAVE_sminv8df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX512F)))
#define HAVE_sminv8df3_mask_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && ((TARGET_SSE && (64 == 64 || TARGET_AVX512VL) && (V8DFmode == V16SFmode \
									      || V8DFmode == V8DFmode \
									      || V8DFmode == V8DImode \
									      || V8DFmode == V16SImode)) && (TARGET_AVX512F))))
#define HAVE_smaxv4df3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_smaxv4df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_sminv4df3 ((TARGET_SSE && 1 && 1) && (TARGET_AVX))
#define HAVE_sminv4df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (32 == 64 || TARGET_AVX512VL) && 1) && (TARGET_AVX)))
#define HAVE_smaxv2df3 ((TARGET_SSE && 1 && 1) && (TARGET_SSE2))
#define HAVE_smaxv2df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_SSE2)))
#define HAVE_sminv2df3 ((TARGET_SSE && 1 && 1) && (TARGET_SSE2))
#define HAVE_sminv2df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && (16 == 64 || TARGET_AVX512VL) && 1) && (TARGET_SSE2)))
#define HAVE_sse3_haddv2df3 (TARGET_SSE3)
#define HAVE_reduc_plus_scal_v8df (TARGET_AVX512F)
#define HAVE_reduc_plus_scal_v4df (TARGET_AVX)
#define HAVE_reduc_plus_scal_v2df (TARGET_SSE3)
#define HAVE_reduc_plus_scal_v16sf (TARGET_AVX512F)
#define HAVE_reduc_plus_scal_v8sf (TARGET_AVX)
#define HAVE_reduc_plus_scal_v4sf (TARGET_SSE)
#define HAVE_reduc_smax_scal_v32qi (TARGET_AVX2)
#define HAVE_reduc_smin_scal_v32qi (TARGET_AVX2)
#define HAVE_reduc_smax_scal_v16hi (TARGET_AVX2)
#define HAVE_reduc_smin_scal_v16hi (TARGET_AVX2)
#define HAVE_reduc_smax_scal_v8si (TARGET_AVX2)
#define HAVE_reduc_smin_scal_v8si (TARGET_AVX2)
#define HAVE_reduc_smax_scal_v4di (TARGET_AVX2)
#define HAVE_reduc_smin_scal_v4di (TARGET_AVX2)
#define HAVE_reduc_smax_scal_v8sf (TARGET_AVX)
#define HAVE_reduc_smin_scal_v8sf (TARGET_AVX)
#define HAVE_reduc_smax_scal_v4df (TARGET_AVX)
#define HAVE_reduc_smin_scal_v4df (TARGET_AVX)
#define HAVE_reduc_smax_scal_v4sf (TARGET_SSE)
#define HAVE_reduc_smin_scal_v4sf (TARGET_SSE)
#define HAVE_reduc_smax_scal_v64qi (TARGET_AVX512BW)
#define HAVE_reduc_smin_scal_v64qi (TARGET_AVX512BW)
#define HAVE_reduc_smax_scal_v32hi (TARGET_AVX512BW)
#define HAVE_reduc_smin_scal_v32hi (TARGET_AVX512BW)
#define HAVE_reduc_smax_scal_v16si (TARGET_AVX512F)
#define HAVE_reduc_smin_scal_v16si (TARGET_AVX512F)
#define HAVE_reduc_smax_scal_v8di (TARGET_AVX512F)
#define HAVE_reduc_smin_scal_v8di (TARGET_AVX512F)
#define HAVE_reduc_smax_scal_v16sf (TARGET_AVX512F)
#define HAVE_reduc_smin_scal_v16sf (TARGET_AVX512F)
#define HAVE_reduc_smax_scal_v8df (TARGET_AVX512F)
#define HAVE_reduc_smin_scal_v8df (TARGET_AVX512F)
#define HAVE_reduc_umax_scal_v16si (TARGET_AVX512F)
#define HAVE_reduc_umin_scal_v16si (TARGET_AVX512F)
#define HAVE_reduc_umax_scal_v8di (TARGET_AVX512F)
#define HAVE_reduc_umin_scal_v8di (TARGET_AVX512F)
#define HAVE_reduc_umax_scal_v32hi ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_reduc_umin_scal_v32hi ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_reduc_umax_scal_v64qi ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_reduc_umin_scal_v64qi ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_reduc_umax_scal_v32qi (TARGET_AVX2)
#define HAVE_reduc_umin_scal_v32qi (TARGET_AVX2)
#define HAVE_reduc_umax_scal_v16hi (TARGET_AVX2)
#define HAVE_reduc_umin_scal_v16hi (TARGET_AVX2)
#define HAVE_reduc_umax_scal_v8si (TARGET_AVX2)
#define HAVE_reduc_umin_scal_v8si (TARGET_AVX2)
#define HAVE_reduc_umax_scal_v4di (TARGET_AVX2)
#define HAVE_reduc_umin_scal_v4di (TARGET_AVX2)
#define HAVE_reduc_umin_scal_v8hi (TARGET_SSE4_1)
#define HAVE_vec_cmpv16sihi (TARGET_AVX512F)
#define HAVE_vec_cmpv8siqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vec_cmpv4siqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vec_cmpv8diqi (TARGET_AVX512F)
#define HAVE_vec_cmpv4diqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vec_cmpv2diqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vec_cmpv16sfhi (TARGET_AVX512F)
#define HAVE_vec_cmpv8sfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vec_cmpv4sfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vec_cmpv8dfqi (TARGET_AVX512F)
#define HAVE_vec_cmpv4dfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vec_cmpv2dfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vec_cmpv64qidi (TARGET_AVX512BW)
#define HAVE_vec_cmpv16qihi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_vec_cmpv32qisi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_vec_cmpv32hisi (TARGET_AVX512BW)
#define HAVE_vec_cmpv16hihi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_vec_cmpv8hiqi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_vec_cmpv32qiv32qi (TARGET_AVX2)
#define HAVE_vec_cmpv16hiv16hi (TARGET_AVX2)
#define HAVE_vec_cmpv8siv8si (TARGET_AVX2)
#define HAVE_vec_cmpv4div4di (TARGET_AVX2)
#define HAVE_vec_cmpv16qiv16qi (TARGET_SSE2)
#define HAVE_vec_cmpv8hiv8hi (TARGET_SSE2)
#define HAVE_vec_cmpv4siv4si (TARGET_SSE2)
#define HAVE_vec_cmpv2div2di (TARGET_SSE4_2)
#define HAVE_vec_cmpv8sfv8si (TARGET_AVX)
#define HAVE_vec_cmpv4dfv4di (TARGET_AVX)
#define HAVE_vec_cmpv4sfv4si (TARGET_SSE)
#define HAVE_vec_cmpv2dfv2di ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_vec_cmpuv16sihi (TARGET_AVX512F)
#define HAVE_vec_cmpuv8siqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vec_cmpuv4siqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vec_cmpuv8diqi (TARGET_AVX512F)
#define HAVE_vec_cmpuv4diqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vec_cmpuv2diqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vec_cmpuv64qidi (TARGET_AVX512BW)
#define HAVE_vec_cmpuv16qihi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_vec_cmpuv32qisi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_vec_cmpuv32hisi (TARGET_AVX512BW)
#define HAVE_vec_cmpuv16hihi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_vec_cmpuv8hiqi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_vec_cmpuv32qiv32qi (TARGET_AVX2)
#define HAVE_vec_cmpuv16hiv16hi (TARGET_AVX2)
#define HAVE_vec_cmpuv8siv8si (TARGET_AVX2)
#define HAVE_vec_cmpuv4div4di (TARGET_AVX2)
#define HAVE_vec_cmpuv16qiv16qi (TARGET_SSE2)
#define HAVE_vec_cmpuv8hiv8hi (TARGET_SSE2)
#define HAVE_vec_cmpuv4siv4si (TARGET_SSE2)
#define HAVE_vec_cmpuv2div2di (TARGET_SSE4_2)
#define HAVE_vcondv64qiv16sf (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V64QImode) \
       == GET_MODE_NUNITS (V16SFmode)))
#define HAVE_vcondv32hiv16sf (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V32HImode) \
       == GET_MODE_NUNITS (V16SFmode)))
#define HAVE_vcondv16siv16sf (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SImode) \
       == GET_MODE_NUNITS (V16SFmode)))
#define HAVE_vcondv8div16sf (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DImode) \
       == GET_MODE_NUNITS (V16SFmode)))
#define HAVE_vcondv16sfv16sf (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SFmode) \
       == GET_MODE_NUNITS (V16SFmode)))
#define HAVE_vcondv8dfv16sf (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DFmode) \
       == GET_MODE_NUNITS (V16SFmode)))
#define HAVE_vcondv64qiv8df (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V64QImode) \
       == GET_MODE_NUNITS (V8DFmode)))
#define HAVE_vcondv32hiv8df (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V32HImode) \
       == GET_MODE_NUNITS (V8DFmode)))
#define HAVE_vcondv16siv8df (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SImode) \
       == GET_MODE_NUNITS (V8DFmode)))
#define HAVE_vcondv8div8df (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DImode) \
       == GET_MODE_NUNITS (V8DFmode)))
#define HAVE_vcondv16sfv8df (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SFmode) \
       == GET_MODE_NUNITS (V8DFmode)))
#define HAVE_vcondv8dfv8df (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DFmode) \
       == GET_MODE_NUNITS (V8DFmode)))
#define HAVE_vcondv32qiv8sf (TARGET_AVX \
   && (GET_MODE_NUNITS (V32QImode) \
       == GET_MODE_NUNITS (V8SFmode)))
#define HAVE_vcondv32qiv4df (TARGET_AVX \
   && (GET_MODE_NUNITS (V32QImode) \
       == GET_MODE_NUNITS (V4DFmode)))
#define HAVE_vcondv16hiv8sf (TARGET_AVX \
   && (GET_MODE_NUNITS (V16HImode) \
       == GET_MODE_NUNITS (V8SFmode)))
#define HAVE_vcondv16hiv4df (TARGET_AVX \
   && (GET_MODE_NUNITS (V16HImode) \
       == GET_MODE_NUNITS (V4DFmode)))
#define HAVE_vcondv8siv8sf (TARGET_AVX \
   && (GET_MODE_NUNITS (V8SImode) \
       == GET_MODE_NUNITS (V8SFmode)))
#define HAVE_vcondv8siv4df (TARGET_AVX \
   && (GET_MODE_NUNITS (V8SImode) \
       == GET_MODE_NUNITS (V4DFmode)))
#define HAVE_vcondv4div8sf (TARGET_AVX \
   && (GET_MODE_NUNITS (V4DImode) \
       == GET_MODE_NUNITS (V8SFmode)))
#define HAVE_vcondv4div4df (TARGET_AVX \
   && (GET_MODE_NUNITS (V4DImode) \
       == GET_MODE_NUNITS (V4DFmode)))
#define HAVE_vcondv8sfv8sf (TARGET_AVX \
   && (GET_MODE_NUNITS (V8SFmode) \
       == GET_MODE_NUNITS (V8SFmode)))
#define HAVE_vcondv8sfv4df (TARGET_AVX \
   && (GET_MODE_NUNITS (V8SFmode) \
       == GET_MODE_NUNITS (V4DFmode)))
#define HAVE_vcondv4dfv8sf (TARGET_AVX \
   && (GET_MODE_NUNITS (V4DFmode) \
       == GET_MODE_NUNITS (V8SFmode)))
#define HAVE_vcondv4dfv4df (TARGET_AVX \
   && (GET_MODE_NUNITS (V4DFmode) \
       == GET_MODE_NUNITS (V4DFmode)))
#define HAVE_vcondv16qiv4sf (TARGET_SSE \
   && (GET_MODE_NUNITS (V16QImode) \
       == GET_MODE_NUNITS (V4SFmode)))
#define HAVE_vcondv16qiv2df ((TARGET_SSE \
   && (GET_MODE_NUNITS (V16QImode) \
       == GET_MODE_NUNITS (V2DFmode))) && (TARGET_SSE2))
#define HAVE_vcondv8hiv4sf (TARGET_SSE \
   && (GET_MODE_NUNITS (V8HImode) \
       == GET_MODE_NUNITS (V4SFmode)))
#define HAVE_vcondv8hiv2df ((TARGET_SSE \
   && (GET_MODE_NUNITS (V8HImode) \
       == GET_MODE_NUNITS (V2DFmode))) && (TARGET_SSE2))
#define HAVE_vcondv4siv4sf (TARGET_SSE \
   && (GET_MODE_NUNITS (V4SImode) \
       == GET_MODE_NUNITS (V4SFmode)))
#define HAVE_vcondv4siv2df ((TARGET_SSE \
   && (GET_MODE_NUNITS (V4SImode) \
       == GET_MODE_NUNITS (V2DFmode))) && (TARGET_SSE2))
#define HAVE_vcondv2div4sf (TARGET_SSE \
   && (GET_MODE_NUNITS (V2DImode) \
       == GET_MODE_NUNITS (V4SFmode)))
#define HAVE_vcondv2div2df ((TARGET_SSE \
   && (GET_MODE_NUNITS (V2DImode) \
       == GET_MODE_NUNITS (V2DFmode))) && (TARGET_SSE2))
#define HAVE_vcondv4sfv4sf (TARGET_SSE \
   && (GET_MODE_NUNITS (V4SFmode) \
       == GET_MODE_NUNITS (V4SFmode)))
#define HAVE_vcondv4sfv2df ((TARGET_SSE \
   && (GET_MODE_NUNITS (V4SFmode) \
       == GET_MODE_NUNITS (V2DFmode))) && (TARGET_SSE2))
#define HAVE_vcondv2dfv4sf ((TARGET_SSE \
   && (GET_MODE_NUNITS (V2DFmode) \
       == GET_MODE_NUNITS (V4SFmode))) && (TARGET_SSE2))
#define HAVE_vcondv2dfv2df ((TARGET_SSE \
   && (GET_MODE_NUNITS (V2DFmode) \
       == GET_MODE_NUNITS (V2DFmode))) && (TARGET_SSE2))
#define HAVE_vcond_mask_v16sihi (TARGET_AVX512F)
#define HAVE_vcond_mask_v8siqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vcond_mask_v4siqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vcond_mask_v8diqi (TARGET_AVX512F)
#define HAVE_vcond_mask_v4diqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vcond_mask_v2diqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vcond_mask_v16sfhi (TARGET_AVX512F)
#define HAVE_vcond_mask_v8sfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vcond_mask_v4sfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vcond_mask_v8dfqi (TARGET_AVX512F)
#define HAVE_vcond_mask_v4dfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vcond_mask_v2dfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vcond_mask_v64qidi (TARGET_AVX512BW)
#define HAVE_vcond_mask_v16qihi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_vcond_mask_v32qisi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_vcond_mask_v32hisi (TARGET_AVX512BW)
#define HAVE_vcond_mask_v16hihi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_vcond_mask_v8hiqi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_vcond_mask_v32qiv32qi (TARGET_AVX2)
#define HAVE_vcond_mask_v16hiv16hi (TARGET_AVX2)
#define HAVE_vcond_mask_v8siv8si (TARGET_AVX2)
#define HAVE_vcond_mask_v4div4di (TARGET_AVX2)
#define HAVE_vcond_mask_v16qiv16qi (TARGET_SSE2)
#define HAVE_vcond_mask_v8hiv8hi (TARGET_SSE2)
#define HAVE_vcond_mask_v4siv4si (TARGET_SSE2)
#define HAVE_vcond_mask_v2div2di (TARGET_SSE4_2)
#define HAVE_vcond_mask_v8sfv8si (TARGET_AVX)
#define HAVE_vcond_mask_v4dfv4di (TARGET_AVX)
#define HAVE_vcond_mask_v4sfv4si (TARGET_SSE)
#define HAVE_vcond_mask_v2dfv2di ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_andv8sf3 ((TARGET_SSE && 1) && (TARGET_AVX))
#define HAVE_andv8sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && TARGET_AVX512VL) && (TARGET_AVX)))
#define HAVE_iorv8sf3 ((TARGET_SSE && 1) && (TARGET_AVX))
#define HAVE_iorv8sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && TARGET_AVX512VL) && (TARGET_AVX)))
#define HAVE_xorv8sf3 ((TARGET_SSE && 1) && (TARGET_AVX))
#define HAVE_xorv8sf3_mask ((TARGET_AVX512F) && ((TARGET_SSE && TARGET_AVX512VL) && (TARGET_AVX)))
#define HAVE_andv4sf3 (TARGET_SSE && 1)
#define HAVE_andv4sf3_mask ((TARGET_AVX512F) && (TARGET_SSE && TARGET_AVX512VL))
#define HAVE_iorv4sf3 (TARGET_SSE && 1)
#define HAVE_iorv4sf3_mask ((TARGET_AVX512F) && (TARGET_SSE && TARGET_AVX512VL))
#define HAVE_xorv4sf3 (TARGET_SSE && 1)
#define HAVE_xorv4sf3_mask ((TARGET_AVX512F) && (TARGET_SSE && TARGET_AVX512VL))
#define HAVE_andv4df3 ((TARGET_SSE && 1) && (TARGET_AVX))
#define HAVE_andv4df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && TARGET_AVX512VL) && (TARGET_AVX)))
#define HAVE_iorv4df3 ((TARGET_SSE && 1) && (TARGET_AVX))
#define HAVE_iorv4df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && TARGET_AVX512VL) && (TARGET_AVX)))
#define HAVE_xorv4df3 ((TARGET_SSE && 1) && (TARGET_AVX))
#define HAVE_xorv4df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && TARGET_AVX512VL) && (TARGET_AVX)))
#define HAVE_andv2df3 ((TARGET_SSE && 1) && (TARGET_SSE2))
#define HAVE_andv2df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && TARGET_AVX512VL) && (TARGET_SSE2)))
#define HAVE_iorv2df3 ((TARGET_SSE && 1) && (TARGET_SSE2))
#define HAVE_iorv2df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && TARGET_AVX512VL) && (TARGET_SSE2)))
#define HAVE_xorv2df3 ((TARGET_SSE && 1) && (TARGET_SSE2))
#define HAVE_xorv2df3_mask ((TARGET_AVX512F) && ((TARGET_SSE && TARGET_AVX512VL) && (TARGET_SSE2)))
#define HAVE_andv16sf3 (TARGET_AVX512F)
#define HAVE_andv16sf3_mask (TARGET_AVX512F)
#define HAVE_iorv16sf3 (TARGET_AVX512F)
#define HAVE_iorv16sf3_mask (TARGET_AVX512F)
#define HAVE_xorv16sf3 (TARGET_AVX512F)
#define HAVE_xorv16sf3_mask (TARGET_AVX512F)
#define HAVE_andv8df3 (TARGET_AVX512F)
#define HAVE_andv8df3_mask (TARGET_AVX512F)
#define HAVE_iorv8df3 (TARGET_AVX512F)
#define HAVE_iorv8df3_mask (TARGET_AVX512F)
#define HAVE_xorv8df3 (TARGET_AVX512F)
#define HAVE_xorv8df3_mask (TARGET_AVX512F)
#define HAVE_copysignv16sf3 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_copysignv8sf3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_copysignv4sf3 (TARGET_SSE)
#define HAVE_copysignv8df3 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_copysignv4df3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_copysignv2df3 ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_andtf3 (TARGET_SSE)
#define HAVE_iortf3 (TARGET_SSE)
#define HAVE_xortf3 (TARGET_SSE)
#define HAVE_fmasf4 (TARGET_SSE_MATH && (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F))
#define HAVE_fmadf4 (TARGET_SSE_MATH && (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F))
#define HAVE_fmav4sf4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fmav2df4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fmav8sf4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fmav4df4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fmav16sf4 (TARGET_AVX512F)
#define HAVE_fmav8df4 (TARGET_AVX512F)
#define HAVE_fmssf4 (TARGET_SSE_MATH && (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F))
#define HAVE_fmsdf4 (TARGET_SSE_MATH && (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F))
#define HAVE_fmsv4sf4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fmsv2df4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fmsv8sf4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fmsv4df4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fmsv16sf4 (TARGET_AVX512F)
#define HAVE_fmsv8df4 (TARGET_AVX512F)
#define HAVE_fnmasf4 (TARGET_SSE_MATH && (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F))
#define HAVE_fnmadf4 (TARGET_SSE_MATH && (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F))
#define HAVE_fnmav4sf4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fnmav2df4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fnmav8sf4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fnmav4df4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fnmav16sf4 (TARGET_AVX512F)
#define HAVE_fnmav8df4 (TARGET_AVX512F)
#define HAVE_fnmssf4 (TARGET_SSE_MATH && (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F))
#define HAVE_fnmsdf4 (TARGET_SSE_MATH && (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F))
#define HAVE_fnmsv4sf4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fnmsv2df4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fnmsv8sf4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fnmsv4df4 (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fnmsv16sf4 (TARGET_AVX512F)
#define HAVE_fnmsv8df4 (TARGET_AVX512F)
#define HAVE_fma4i_fmadd_sf (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F)
#define HAVE_fma4i_fmadd_df (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F)
#define HAVE_fma4i_fmadd_v4sf (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fma4i_fmadd_v2df (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fma4i_fmadd_v8sf (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fma4i_fmadd_v4df (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512VL)
#define HAVE_fma4i_fmadd_v16sf (TARGET_AVX512F)
#define HAVE_fma4i_fmadd_v8df (TARGET_AVX512F)
#define HAVE_avx512f_fmadd_v16sf_maskz (TARGET_AVX512F && 1)
#define HAVE_avx512f_fmadd_v16sf_maskz_round ((TARGET_AVX512F) && (TARGET_AVX512F && 1))
#define HAVE_avx512vl_fmadd_v8sf_maskz ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmadd_v8sf_maskz_round ((TARGET_AVX512F) && ((TARGET_AVX512F && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmadd_v4sf_maskz ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmadd_v4sf_maskz_round ((TARGET_AVX512F) && ((TARGET_AVX512F && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fmadd_v8df_maskz (TARGET_AVX512F && 1)
#define HAVE_avx512f_fmadd_v8df_maskz_round ((TARGET_AVX512F) && (TARGET_AVX512F && 1))
#define HAVE_avx512vl_fmadd_v4df_maskz ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmadd_v4df_maskz_round ((TARGET_AVX512F) && ((TARGET_AVX512F && 1) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmadd_v2df_maskz ((TARGET_AVX512F && 1) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmadd_v2df_maskz_round ((TARGET_AVX512F) && ((TARGET_AVX512F && 1) && (TARGET_AVX512VL)))
#define HAVE_fmaddsub_v16sf ((TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F) && (TARGET_AVX512F))
#define HAVE_fmaddsub_v8sf ((TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F) && (TARGET_AVX))
#define HAVE_fmaddsub_v4sf (TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F)
#define HAVE_fmaddsub_v8df ((TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F) && (TARGET_AVX512F))
#define HAVE_fmaddsub_v4df ((TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F) && (TARGET_AVX))
#define HAVE_fmaddsub_v2df ((TARGET_FMA || TARGET_FMA4 || TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_avx512f_fmaddsub_v16sf_maskz (TARGET_AVX512F)
#define HAVE_avx512f_fmaddsub_v16sf_maskz_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmaddsub_v8sf_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmaddsub_v8sf_maskz_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmaddsub_v4sf_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmaddsub_v4sf_maskz_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fmaddsub_v8df_maskz (TARGET_AVX512F)
#define HAVE_avx512f_fmaddsub_v8df_maskz_round (TARGET_AVX512F)
#define HAVE_avx512vl_fmaddsub_v4df_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmaddsub_v4df_maskz_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fmaddsub_v2df_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fmaddsub_v2df_maskz_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_fmai_vmfmadd_v4sf (TARGET_FMA)
#define HAVE_fmai_vmfmadd_v4sf_round ((TARGET_AVX512F) && (TARGET_FMA))
#define HAVE_fmai_vmfmadd_v2df ((TARGET_FMA) && (TARGET_SSE2))
#define HAVE_fmai_vmfmadd_v2df_round ((TARGET_AVX512F) && ((TARGET_FMA) && (TARGET_SSE2)))
#define HAVE_fma4i_vmfmadd_v4sf (TARGET_FMA4)
#define HAVE_fma4i_vmfmadd_v2df ((TARGET_FMA4) && (TARGET_SSE2))
#define HAVE_floatunsv16siv16sf2 ((TARGET_SSE2 && (V16SFmode == V4SFmode || TARGET_AVX2)) && (TARGET_AVX512F))
#define HAVE_floatunsv8siv8sf2 ((TARGET_SSE2 && (V8SFmode == V4SFmode || TARGET_AVX2)) && (TARGET_AVX))
#define HAVE_floatunsv4siv4sf2 (TARGET_SSE2 && (V4SFmode == V4SFmode || TARGET_AVX2))
#define HAVE_fixuns_truncv16sfv16si2 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_fixuns_truncv8sfv8si2 ((TARGET_SSE2) && (TARGET_AVX))
#define HAVE_fixuns_truncv4sfv4si2 (TARGET_SSE2)
#define HAVE_avx_cvtpd2dq256_2 (TARGET_AVX)
#define HAVE_avx_cvttpd2dq256_2 (TARGET_AVX)
#define HAVE_sse2_cvtpd2ps (TARGET_SSE2)
#define HAVE_sse2_cvtpd2ps_mask (TARGET_SSE2)
#define HAVE_avx512bw_cvtmask2bv64qi (TARGET_AVX512BW)
#define HAVE_avx512vl_cvtmask2bv16qi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cvtmask2bv32qi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_cvtmask2wv32hi (TARGET_AVX512BW)
#define HAVE_avx512vl_cvtmask2wv16hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cvtmask2wv8hi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512f_cvtmask2dv16si (TARGET_AVX512DQ)
#define HAVE_avx512vl_cvtmask2dv8si ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cvtmask2dv4si ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_avx512f_cvtmask2qv8di (TARGET_AVX512DQ)
#define HAVE_avx512vl_cvtmask2qv4di ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_avx512vl_cvtmask2qv2di ((TARGET_AVX512DQ) && (TARGET_AVX512VL))
#define HAVE_vec_unpacks_hi_v4sf (TARGET_SSE2)
#define HAVE_vec_unpacks_hi_v8sf (TARGET_AVX)
#define HAVE_vec_unpacks_hi_v16sf (TARGET_AVX512F)
#define HAVE_vec_unpacks_lo_v4sf (TARGET_SSE2)
#define HAVE_vec_unpacks_lo_v8sf (TARGET_AVX)
#define HAVE_vec_unpacks_float_hi_v32hi ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_unpacks_float_hi_v16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacks_float_hi_v8hi (TARGET_SSE2)
#define HAVE_vec_unpacks_float_lo_v32hi ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_unpacks_float_lo_v16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacks_float_lo_v8hi (TARGET_SSE2)
#define HAVE_vec_unpacku_float_hi_v32hi ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_unpacku_float_hi_v16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacku_float_hi_v8hi (TARGET_SSE2)
#define HAVE_vec_unpacku_float_lo_v32hi ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_unpacku_float_lo_v16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacku_float_lo_v8hi (TARGET_SSE2)
#define HAVE_vec_unpacks_float_hi_v4si (TARGET_SSE2)
#define HAVE_vec_unpacks_float_lo_v4si (TARGET_SSE2)
#define HAVE_vec_unpacks_float_hi_v8si (TARGET_AVX)
#define HAVE_vec_unpacks_float_lo_v8si (TARGET_AVX)
#define HAVE_vec_unpacks_float_hi_v16si (TARGET_AVX512F)
#define HAVE_vec_unpacks_float_lo_v16si (TARGET_AVX512F)
#define HAVE_vec_unpacku_float_hi_v4si (TARGET_SSE2)
#define HAVE_vec_unpacku_float_lo_v4si (TARGET_SSE2)
#define HAVE_vec_unpacku_float_hi_v8si (TARGET_AVX)
#define HAVE_vec_unpacku_float_hi_v16si (TARGET_AVX512F)
#define HAVE_vec_unpacku_float_lo_v8si (TARGET_AVX)
#define HAVE_vec_unpacku_float_lo_v16si (TARGET_AVX512F)
#define HAVE_vec_pack_trunc_v8df ((TARGET_AVX) && (TARGET_AVX512F))
#define HAVE_vec_pack_trunc_v4df (TARGET_AVX)
#define HAVE_vec_pack_trunc_v2df (TARGET_SSE2)
#define HAVE_vec_pack_sfix_trunc_v8df (TARGET_AVX512F)
#define HAVE_vec_pack_sfix_trunc_v4df (TARGET_AVX)
#define HAVE_vec_pack_sfix_trunc_v2df (TARGET_SSE2)
#define HAVE_vec_pack_ufix_trunc_v8df ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_pack_ufix_trunc_v4df ((TARGET_SSE2) && (TARGET_AVX))
#define HAVE_vec_pack_ufix_trunc_v2df (TARGET_SSE2)
#define HAVE_avx512f_vec_pack_sfix_v8df (TARGET_AVX512F)
#define HAVE_vec_pack_sfix_v4df (TARGET_AVX)
#define HAVE_vec_pack_sfix_v2df (TARGET_SSE2)
#define HAVE_sse_movhlps_exp (TARGET_SSE)
#define HAVE_sse_movlhps_exp (TARGET_SSE)
#define HAVE_vec_interleave_highv8sf (TARGET_AVX)
#define HAVE_vec_interleave_lowv8sf (TARGET_AVX)
#define HAVE_avx_shufps256 (TARGET_AVX)
#define HAVE_avx_shufps256_mask ((TARGET_AVX512VL) && (TARGET_AVX))
#define HAVE_sse_shufps (TARGET_SSE)
#define HAVE_sse_shufps_mask ((TARGET_AVX512VL) && (TARGET_SSE))
#define HAVE_sse_loadhps_exp (TARGET_SSE)
#define HAVE_sse_loadlps_exp (TARGET_SSE)
#define HAVE_vec_initv16qi (TARGET_SSE)
#define HAVE_vec_initv8hi (TARGET_SSE)
#define HAVE_vec_initv4si (TARGET_SSE)
#define HAVE_vec_initv2di (TARGET_SSE)
#define HAVE_vec_initv4sf (TARGET_SSE)
#define HAVE_vec_initv2df ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_vec_setv32qi ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_vec_setv16qi (TARGET_SSE)
#define HAVE_vec_setv16hi ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_vec_setv8hi (TARGET_SSE)
#define HAVE_vec_setv16si ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_vec_setv8si ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_vec_setv4si (TARGET_SSE)
#define HAVE_vec_setv8di ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_vec_setv4di ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_vec_setv2di (TARGET_SSE)
#define HAVE_vec_setv16sf ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_vec_setv8sf ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_vec_setv4sf (TARGET_SSE)
#define HAVE_vec_setv8df ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_vec_setv4df ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_vec_setv2df ((TARGET_SSE) && (TARGET_SSE2))
#define HAVE_avx512dq_vextractf64x2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512dq_vextracti64x2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512f_vextractf32x4_mask (TARGET_AVX512F)
#define HAVE_avx512f_vextracti32x4_mask (TARGET_AVX512F)
#define HAVE_avx512dq_vextractf32x8_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512dq_vextracti32x8_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512f_vextractf64x4_mask (TARGET_AVX512F)
#define HAVE_avx512f_vextracti64x4_mask (TARGET_AVX512F)
#define HAVE_avx512vl_vextractf128v8si (TARGET_AVX512DQ && TARGET_AVX512VL)
#define HAVE_avx512vl_vextractf128v8sf (TARGET_AVX512DQ && TARGET_AVX512VL)
#define HAVE_avx512vl_vextractf128v4di (TARGET_AVX512DQ && TARGET_AVX512VL)
#define HAVE_avx512vl_vextractf128v4df (TARGET_AVX512DQ && TARGET_AVX512VL)
#define HAVE_avx_vextractf128v32qi (TARGET_AVX)
#define HAVE_avx_vextractf128v16hi (TARGET_AVX)
#define HAVE_avx_vextractf128v8si (TARGET_AVX)
#define HAVE_avx_vextractf128v4di (TARGET_AVX)
#define HAVE_avx_vextractf128v8sf (TARGET_AVX)
#define HAVE_avx_vextractf128v4df (TARGET_AVX)
#define HAVE_vec_extractv64qi ((TARGET_SSE) && (TARGET_AVX512BW))
#define HAVE_vec_extractv32qi ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_vec_extractv16qi (TARGET_SSE)
#define HAVE_vec_extractv32hi ((TARGET_SSE) && (TARGET_AVX512BW))
#define HAVE_vec_extractv16hi ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_vec_extractv8hi (TARGET_SSE)
#define HAVE_vec_extractv16si ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_vec_extractv8si ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_vec_extractv4si (TARGET_SSE)
#define HAVE_vec_extractv8di ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_vec_extractv4di ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_vec_extractv2di (TARGET_SSE)
#define HAVE_vec_extractv16sf ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_vec_extractv8sf ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_vec_extractv4sf (TARGET_SSE)
#define HAVE_vec_extractv8df ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_vec_extractv4df ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_vec_extractv2df (TARGET_SSE)
#define HAVE_vec_interleave_highv4df (TARGET_AVX)
#define HAVE_vec_interleave_highv2df (TARGET_SSE2)
#define HAVE_avx512f_movddup512 (TARGET_AVX512F)
#define HAVE_avx512f_movddup512_mask (TARGET_AVX512F)
#define HAVE_avx512f_unpcklpd512 (TARGET_AVX512F)
#define HAVE_avx512f_unpcklpd512_mask (TARGET_AVX512F)
#define HAVE_avx_movddup256 (TARGET_AVX && 1)
#define HAVE_avx_movddup256_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL))
#define HAVE_avx_unpcklpd256 (TARGET_AVX && 1)
#define HAVE_avx_unpcklpd256_mask ((TARGET_AVX512F) && (TARGET_AVX && TARGET_AVX512VL))
#define HAVE_vec_interleave_lowv4df (TARGET_AVX)
#define HAVE_vec_interleave_lowv2df (TARGET_SSE2)
#define HAVE_avx512f_vternlogv16si_maskz (TARGET_AVX512F)
#define HAVE_avx512vl_vternlogv8si_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vternlogv4si_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_vternlogv8di_maskz (TARGET_AVX512F)
#define HAVE_avx512vl_vternlogv4di_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vternlogv2di_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_shufps512_mask (TARGET_AVX512F)
#define HAVE_avx512f_fixupimmv16sf_maskz (TARGET_AVX512F)
#define HAVE_avx512f_fixupimmv16sf_maskz_round (TARGET_AVX512F)
#define HAVE_avx512vl_fixupimmv8sf_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv8sf_maskz_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fixupimmv4sf_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv4sf_maskz_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_fixupimmv8df_maskz (TARGET_AVX512F)
#define HAVE_avx512f_fixupimmv8df_maskz_round (TARGET_AVX512F)
#define HAVE_avx512vl_fixupimmv4df_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv4df_maskz_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_fixupimmv2df_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_fixupimmv2df_maskz_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_sfixupimmv4sf_maskz (TARGET_AVX512F)
#define HAVE_avx512f_sfixupimmv4sf_maskz_round (TARGET_AVX512F)
#define HAVE_avx512f_sfixupimmv2df_maskz ((TARGET_AVX512F) && (TARGET_SSE2))
#define HAVE_avx512f_sfixupimmv2df_maskz_round ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_SSE2)))
#define HAVE_avx512f_shufpd512_mask (TARGET_AVX512F)
#define HAVE_avx_shufpd256 (TARGET_AVX)
#define HAVE_avx_shufpd256_mask ((TARGET_AVX512VL) && (TARGET_AVX))
#define HAVE_sse2_shufpd (TARGET_SSE2)
#define HAVE_sse2_shufpd_mask ((TARGET_AVX512VL) && (TARGET_SSE2))
#define HAVE_sse2_loadhpd_exp (TARGET_SSE2)
#define HAVE_sse2_loadlpd_exp (TARGET_SSE2)
#define HAVE_avx512f_ss_truncatev16siv16qi2_mask_store (TARGET_AVX512F)
#define HAVE_avx512f_truncatev16siv16qi2_mask_store (TARGET_AVX512F)
#define HAVE_avx512f_us_truncatev16siv16qi2_mask_store (TARGET_AVX512F)
#define HAVE_avx512f_ss_truncatev16siv16hi2_mask_store (TARGET_AVX512F)
#define HAVE_avx512f_truncatev16siv16hi2_mask_store (TARGET_AVX512F)
#define HAVE_avx512f_us_truncatev16siv16hi2_mask_store (TARGET_AVX512F)
#define HAVE_avx512f_ss_truncatev8div8si2_mask_store (TARGET_AVX512F)
#define HAVE_avx512f_truncatev8div8si2_mask_store (TARGET_AVX512F)
#define HAVE_avx512f_us_truncatev8div8si2_mask_store (TARGET_AVX512F)
#define HAVE_avx512f_ss_truncatev8div8hi2_mask_store (TARGET_AVX512F)
#define HAVE_avx512f_truncatev8div8hi2_mask_store (TARGET_AVX512F)
#define HAVE_avx512f_us_truncatev8div8hi2_mask_store (TARGET_AVX512F)
#define HAVE_avx512bw_ss_truncatev32hiv32qi2_mask_store (TARGET_AVX512BW)
#define HAVE_avx512bw_truncatev32hiv32qi2_mask_store (TARGET_AVX512BW)
#define HAVE_avx512bw_us_truncatev32hiv32qi2_mask_store (TARGET_AVX512BW)
#define HAVE_avx512vl_ss_truncatev4div4si2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev4div4si2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev4div4si2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev8siv8hi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_truncatev8siv8hi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_us_truncatev8siv8hi2_mask_store (TARGET_AVX512VL)
#define HAVE_avx512vl_ss_truncatev16hiv16qi2_mask_store ((TARGET_AVX512VL) && (TARGET_AVX512BW))
#define HAVE_avx512vl_truncatev16hiv16qi2_mask_store ((TARGET_AVX512VL) && (TARGET_AVX512BW))
#define HAVE_avx512vl_us_truncatev16hiv16qi2_mask_store ((TARGET_AVX512VL) && (TARGET_AVX512BW))
#define HAVE_negv64qi2 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_negv32qi2 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_negv16qi2 (TARGET_SSE2)
#define HAVE_negv32hi2 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_negv16hi2 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_negv8hi2 (TARGET_SSE2)
#define HAVE_negv16si2 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_negv8si2 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_negv4si2 (TARGET_SSE2)
#define HAVE_negv8di2 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_negv4di2 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_negv2di2 (TARGET_SSE2)
#define HAVE_addv64qi3 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_subv64qi3 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_addv32qi3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_subv32qi3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_addv16qi3 (TARGET_SSE2)
#define HAVE_subv16qi3 (TARGET_SSE2)
#define HAVE_addv32hi3 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_subv32hi3 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_addv16hi3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_subv16hi3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_addv8hi3 (TARGET_SSE2)
#define HAVE_subv8hi3 (TARGET_SSE2)
#define HAVE_addv16si3 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_subv16si3 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_addv8si3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_subv8si3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_addv4si3 (TARGET_SSE2)
#define HAVE_subv4si3 (TARGET_SSE2)
#define HAVE_addv8di3 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_subv8di3 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_addv4di3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_subv4di3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_addv2di3 (TARGET_SSE2)
#define HAVE_subv2di3 (TARGET_SSE2)
#define HAVE_addv16si3_mask (TARGET_AVX512F)
#define HAVE_subv16si3_mask (TARGET_AVX512F)
#define HAVE_addv8si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_subv8si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_addv4si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_subv4si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_addv8di3_mask (TARGET_AVX512F)
#define HAVE_subv8di3_mask (TARGET_AVX512F)
#define HAVE_addv4di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_subv4di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_addv2di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_subv2di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_addv64qi3_mask (TARGET_AVX512BW)
#define HAVE_subv64qi3_mask (TARGET_AVX512BW)
#define HAVE_addv16qi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_subv16qi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_addv32qi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_subv32qi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_addv32hi3_mask (TARGET_AVX512BW)
#define HAVE_subv32hi3_mask (TARGET_AVX512BW)
#define HAVE_addv16hi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_subv16hi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_addv8hi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_subv8hi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_ssaddv64qi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_ssaddv64qi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx512bw_usaddv64qi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_usaddv64qi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx512bw_sssubv64qi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_sssubv64qi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx512bw_ussubv64qi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_ussubv64qi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx2_ssaddv32qi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_ssaddv32qi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_avx2_usaddv32qi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_usaddv32qi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_avx2_sssubv32qi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_sssubv32qi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_avx2_ussubv32qi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_ussubv32qi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_sse2_ssaddv16qi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_ssaddv16qi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_sse2_usaddv16qi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_usaddv16qi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_sse2_sssubv16qi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_sssubv16qi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_sse2_ussubv16qi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_ussubv16qi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_avx512bw_ssaddv32hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_ssaddv32hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx512bw_usaddv32hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_usaddv32hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx512bw_sssubv32hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_sssubv32hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx512bw_ussubv32hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_ussubv32hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx2_ssaddv16hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_ssaddv16hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_avx2_usaddv16hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_usaddv16hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_avx2_sssubv16hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_sssubv16hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_avx2_ussubv16hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_ussubv16hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_sse2_ssaddv8hi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_ssaddv8hi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_sse2_usaddv8hi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_usaddv8hi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_sse2_sssubv8hi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_sssubv8hi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_sse2_ussubv8hi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_ussubv8hi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_mulv64qi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_mulv64qi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_mulv32qi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_mulv32qi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_mulv16qi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_mulv16qi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_mulv32hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_mulv32hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_mulv16hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_mulv16hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_mulv8hi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_mulv8hi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_smulv32hi3_highpart ((TARGET_SSE2 \
   && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_smulv32hi3_highpart_mask ((TARGET_AVX512F) && ((TARGET_SSE2 \
   && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_umulv32hi3_highpart ((TARGET_SSE2 \
   && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_umulv32hi3_highpart_mask ((TARGET_AVX512F) && ((TARGET_SSE2 \
   && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_smulv16hi3_highpart ((TARGET_SSE2 \
   && 1 && 1) && (TARGET_AVX2))
#define HAVE_smulv16hi3_highpart_mask ((TARGET_AVX512F) && ((TARGET_SSE2 \
   && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_umulv16hi3_highpart ((TARGET_SSE2 \
   && 1 && 1) && (TARGET_AVX2))
#define HAVE_umulv16hi3_highpart_mask ((TARGET_AVX512F) && ((TARGET_SSE2 \
   && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_smulv8hi3_highpart (TARGET_SSE2 \
   && 1 && 1)
#define HAVE_smulv8hi3_highpart_mask ((TARGET_AVX512F) && (TARGET_SSE2 \
   && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_umulv8hi3_highpart (TARGET_SSE2 \
   && 1 && 1)
#define HAVE_umulv8hi3_highpart_mask ((TARGET_AVX512F) && (TARGET_SSE2 \
   && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_vec_widen_umult_even_v16si (TARGET_AVX512F)
#define HAVE_vec_widen_umult_even_v16si_mask (TARGET_AVX512F)
#define HAVE_vec_widen_umult_even_v8si (TARGET_AVX2 && 1)
#define HAVE_vec_widen_umult_even_v8si_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_vec_widen_umult_even_v4si (TARGET_SSE2 && 1)
#define HAVE_vec_widen_umult_even_v4si_mask ((TARGET_AVX512F) && (TARGET_SSE2 && TARGET_AVX512VL))
#define HAVE_vec_widen_smult_even_v16si (TARGET_AVX512F)
#define HAVE_vec_widen_smult_even_v16si_mask (TARGET_AVX512F)
#define HAVE_vec_widen_smult_even_v8si (TARGET_AVX2 && 1)
#define HAVE_vec_widen_smult_even_v8si_mask ((TARGET_AVX512F) && (TARGET_AVX2 && TARGET_AVX512VL))
#define HAVE_sse4_1_mulv2siv2di3 (TARGET_SSE4_1 && 1)
#define HAVE_sse4_1_mulv2siv2di3_mask ((TARGET_AVX512F) && (TARGET_SSE4_1 && TARGET_AVX512VL))
#define HAVE_avx2_pmaddwd (TARGET_AVX2)
#define HAVE_sse2_pmaddwd (TARGET_SSE2)
#define HAVE_mulv16si3 ((TARGET_SSE2 && 1) && (TARGET_AVX512F))
#define HAVE_mulv16si3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_mulv8si3 ((TARGET_SSE2 && 1) && (TARGET_AVX2))
#define HAVE_mulv8si3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX2)))
#define HAVE_mulv4si3 (TARGET_SSE2 && 1)
#define HAVE_mulv4si3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_mulv8di3 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_mulv4di3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_mulv2di3 (TARGET_SSE2)
#define HAVE_vec_widen_smult_hi_v32qi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_umult_hi_v32qi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_smult_hi_v16qi (TARGET_SSE2)
#define HAVE_vec_widen_umult_hi_v16qi (TARGET_SSE2)
#define HAVE_vec_widen_smult_hi_v16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_umult_hi_v16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_smult_hi_v8hi (TARGET_SSE2)
#define HAVE_vec_widen_umult_hi_v8hi (TARGET_SSE2)
#define HAVE_vec_widen_smult_hi_v8si ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_umult_hi_v8si ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_smult_hi_v4si (TARGET_SSE2)
#define HAVE_vec_widen_umult_hi_v4si (TARGET_SSE2)
#define HAVE_vec_widen_smult_lo_v32qi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_umult_lo_v32qi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_smult_lo_v16qi (TARGET_SSE2)
#define HAVE_vec_widen_umult_lo_v16qi (TARGET_SSE2)
#define HAVE_vec_widen_smult_lo_v16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_umult_lo_v16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_smult_lo_v8hi (TARGET_SSE2)
#define HAVE_vec_widen_umult_lo_v8hi (TARGET_SSE2)
#define HAVE_vec_widen_smult_lo_v8si ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_umult_lo_v8si ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_smult_lo_v4si (TARGET_SSE2)
#define HAVE_vec_widen_umult_lo_v4si (TARGET_SSE2)
#define HAVE_vec_widen_smult_even_v4si (TARGET_SSE2)
#define HAVE_vec_widen_smult_odd_v16si ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_widen_umult_odd_v16si ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_widen_smult_odd_v8si ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_umult_odd_v8si ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_widen_smult_odd_v4si (TARGET_SSE2)
#define HAVE_vec_widen_umult_odd_v4si (TARGET_SSE2)
#define HAVE_sdot_prodv32hi ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_sdot_prodv16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_sdot_prodv8hi (TARGET_SSE2)
#define HAVE_sdot_prodv4si (TARGET_XOP)
#define HAVE_usadv16qi (TARGET_SSE2)
#define HAVE_usadv32qi (TARGET_AVX2)
#define HAVE_vec_shl_v16qi (TARGET_SSE2)
#define HAVE_vec_shl_v8hi (TARGET_SSE2)
#define HAVE_vec_shl_v4si (TARGET_SSE2)
#define HAVE_vec_shl_v2di (TARGET_SSE2)
#define HAVE_vec_shr_v16qi (TARGET_SSE2)
#define HAVE_vec_shr_v8hi (TARGET_SSE2)
#define HAVE_vec_shr_v4si (TARGET_SSE2)
#define HAVE_vec_shr_v2di (TARGET_SSE2)
#define HAVE_smaxv32qi3 (TARGET_AVX2)
#define HAVE_sminv32qi3 (TARGET_AVX2)
#define HAVE_umaxv32qi3 (TARGET_AVX2)
#define HAVE_uminv32qi3 (TARGET_AVX2)
#define HAVE_smaxv16hi3 (TARGET_AVX2)
#define HAVE_sminv16hi3 (TARGET_AVX2)
#define HAVE_umaxv16hi3 (TARGET_AVX2)
#define HAVE_uminv16hi3 (TARGET_AVX2)
#define HAVE_smaxv8si3 (TARGET_AVX2)
#define HAVE_sminv8si3 (TARGET_AVX2)
#define HAVE_umaxv8si3 (TARGET_AVX2)
#define HAVE_uminv8si3 (TARGET_AVX2)
#define HAVE_smaxv64qi3 ((TARGET_AVX2) && (TARGET_AVX512BW))
#define HAVE_sminv64qi3 ((TARGET_AVX2) && (TARGET_AVX512BW))
#define HAVE_umaxv64qi3 ((TARGET_AVX2) && (TARGET_AVX512BW))
#define HAVE_uminv64qi3 ((TARGET_AVX2) && (TARGET_AVX512BW))
#define HAVE_smaxv32hi3 ((TARGET_AVX2) && (TARGET_AVX512BW))
#define HAVE_sminv32hi3 ((TARGET_AVX2) && (TARGET_AVX512BW))
#define HAVE_umaxv32hi3 ((TARGET_AVX2) && (TARGET_AVX512BW))
#define HAVE_uminv32hi3 ((TARGET_AVX2) && (TARGET_AVX512BW))
#define HAVE_smaxv16si3 ((TARGET_AVX2) && (TARGET_AVX512F))
#define HAVE_sminv16si3 ((TARGET_AVX2) && (TARGET_AVX512F))
#define HAVE_umaxv16si3 ((TARGET_AVX2) && (TARGET_AVX512F))
#define HAVE_uminv16si3 ((TARGET_AVX2) && (TARGET_AVX512F))
#define HAVE_smaxv16si3_mask (TARGET_AVX512F)
#define HAVE_sminv16si3_mask (TARGET_AVX512F)
#define HAVE_umaxv16si3_mask (TARGET_AVX512F)
#define HAVE_uminv16si3_mask (TARGET_AVX512F)
#define HAVE_smaxv8si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_sminv8si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_umaxv8si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_uminv8si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_smaxv4si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_sminv4si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_umaxv4si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_uminv4si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_smaxv8di3_mask (TARGET_AVX512F)
#define HAVE_sminv8di3_mask (TARGET_AVX512F)
#define HAVE_umaxv8di3_mask (TARGET_AVX512F)
#define HAVE_uminv8di3_mask (TARGET_AVX512F)
#define HAVE_smaxv4di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_sminv4di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_umaxv4di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_uminv4di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_smaxv2di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_sminv2di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_umaxv2di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_uminv2di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_smaxv8di3 ((TARGET_SSE4_2) && (TARGET_AVX512BW))
#define HAVE_sminv8di3 ((TARGET_SSE4_2) && (TARGET_AVX512BW))
#define HAVE_umaxv8di3 ((TARGET_SSE4_2) && (TARGET_AVX512BW))
#define HAVE_uminv8di3 ((TARGET_SSE4_2) && (TARGET_AVX512BW))
#define HAVE_smaxv4di3 ((TARGET_SSE4_2) && (TARGET_AVX2))
#define HAVE_sminv4di3 ((TARGET_SSE4_2) && (TARGET_AVX2))
#define HAVE_umaxv4di3 ((TARGET_SSE4_2) && (TARGET_AVX2))
#define HAVE_uminv4di3 ((TARGET_SSE4_2) && (TARGET_AVX2))
#define HAVE_smaxv2di3 (TARGET_SSE4_2)
#define HAVE_sminv2di3 (TARGET_SSE4_2)
#define HAVE_umaxv2di3 (TARGET_SSE4_2)
#define HAVE_uminv2di3 (TARGET_SSE4_2)
#define HAVE_smaxv16qi3 (TARGET_SSE2)
#define HAVE_sminv16qi3 (TARGET_SSE2)
#define HAVE_smaxv8hi3 (TARGET_SSE2)
#define HAVE_sminv8hi3 (TARGET_SSE2)
#define HAVE_smaxv4si3 (TARGET_SSE2)
#define HAVE_sminv4si3 (TARGET_SSE2)
#define HAVE_umaxv16qi3 (TARGET_SSE2)
#define HAVE_uminv16qi3 (TARGET_SSE2)
#define HAVE_umaxv8hi3 (TARGET_SSE2)
#define HAVE_uminv8hi3 (TARGET_SSE2)
#define HAVE_umaxv4si3 (TARGET_SSE2)
#define HAVE_uminv4si3 (TARGET_SSE2)
#define HAVE_avx2_eqv32qi3 (TARGET_AVX2)
#define HAVE_avx2_eqv16hi3 (TARGET_AVX2)
#define HAVE_avx2_eqv8si3 (TARGET_AVX2)
#define HAVE_avx2_eqv4di3 (TARGET_AVX2)
#define HAVE_avx512bw_eqv64qi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_eqv64qi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_eqv16qi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv16qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_eqv32qi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv32qi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512bw_eqv32hi3 (TARGET_AVX512BW)
#define HAVE_avx512bw_eqv32hi3_mask ((TARGET_AVX512F) && (TARGET_AVX512BW))
#define HAVE_avx512vl_eqv16hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv16hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_eqv8hi3 ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv8hi3_mask ((TARGET_AVX512F) && ((TARGET_AVX512BW) && (TARGET_AVX512VL)))
#define HAVE_avx512f_eqv16si3 (TARGET_AVX512F)
#define HAVE_avx512f_eqv16si3_mask (TARGET_AVX512F)
#define HAVE_avx512vl_eqv8si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv8si3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_eqv4si3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv4si3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512f_eqv8di3 (TARGET_AVX512F)
#define HAVE_avx512f_eqv8di3_mask (TARGET_AVX512F)
#define HAVE_avx512vl_eqv4di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv4di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_avx512vl_eqv2di3 ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_eqv2di3_mask ((TARGET_AVX512F) && ((TARGET_AVX512F) && (TARGET_AVX512VL)))
#define HAVE_sse2_eqv16qi3 (TARGET_SSE2 && !TARGET_XOP )
#define HAVE_sse2_eqv8hi3 (TARGET_SSE2 && !TARGET_XOP )
#define HAVE_sse2_eqv4si3 (TARGET_SSE2 && !TARGET_XOP )
#define HAVE_sse4_1_eqv2di3 (TARGET_SSE4_1)
#define HAVE_vcondv64qiv64qi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V64QImode) \
       == GET_MODE_NUNITS (V64QImode))) && (TARGET_AVX512BW))
#define HAVE_vcondv32hiv64qi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V32HImode) \
       == GET_MODE_NUNITS (V64QImode))) && (TARGET_AVX512BW))
#define HAVE_vcondv16siv64qi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SImode) \
       == GET_MODE_NUNITS (V64QImode))) && (TARGET_AVX512BW))
#define HAVE_vcondv8div64qi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DImode) \
       == GET_MODE_NUNITS (V64QImode))) && (TARGET_AVX512BW))
#define HAVE_vcondv16sfv64qi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SFmode) \
       == GET_MODE_NUNITS (V64QImode))) && (TARGET_AVX512BW))
#define HAVE_vcondv8dfv64qi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DFmode) \
       == GET_MODE_NUNITS (V64QImode))) && (TARGET_AVX512BW))
#define HAVE_vcondv64qiv32hi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V64QImode) \
       == GET_MODE_NUNITS (V32HImode))) && (TARGET_AVX512BW))
#define HAVE_vcondv32hiv32hi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V32HImode) \
       == GET_MODE_NUNITS (V32HImode))) && (TARGET_AVX512BW))
#define HAVE_vcondv16siv32hi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SImode) \
       == GET_MODE_NUNITS (V32HImode))) && (TARGET_AVX512BW))
#define HAVE_vcondv8div32hi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DImode) \
       == GET_MODE_NUNITS (V32HImode))) && (TARGET_AVX512BW))
#define HAVE_vcondv16sfv32hi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SFmode) \
       == GET_MODE_NUNITS (V32HImode))) && (TARGET_AVX512BW))
#define HAVE_vcondv8dfv32hi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DFmode) \
       == GET_MODE_NUNITS (V32HImode))) && (TARGET_AVX512BW))
#define HAVE_vcondv64qiv16si (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V64QImode) \
       == GET_MODE_NUNITS (V16SImode)))
#define HAVE_vcondv32hiv16si (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V32HImode) \
       == GET_MODE_NUNITS (V16SImode)))
#define HAVE_vcondv16siv16si (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SImode) \
       == GET_MODE_NUNITS (V16SImode)))
#define HAVE_vcondv8div16si (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DImode) \
       == GET_MODE_NUNITS (V16SImode)))
#define HAVE_vcondv16sfv16si (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SFmode) \
       == GET_MODE_NUNITS (V16SImode)))
#define HAVE_vcondv8dfv16si (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DFmode) \
       == GET_MODE_NUNITS (V16SImode)))
#define HAVE_vcondv64qiv8di (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V64QImode) \
       == GET_MODE_NUNITS (V8DImode)))
#define HAVE_vcondv32hiv8di (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V32HImode) \
       == GET_MODE_NUNITS (V8DImode)))
#define HAVE_vcondv16siv8di (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SImode) \
       == GET_MODE_NUNITS (V8DImode)))
#define HAVE_vcondv8div8di (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DImode) \
       == GET_MODE_NUNITS (V8DImode)))
#define HAVE_vcondv16sfv8di (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SFmode) \
       == GET_MODE_NUNITS (V8DImode)))
#define HAVE_vcondv8dfv8di (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DFmode) \
       == GET_MODE_NUNITS (V8DImode)))
#define HAVE_vcondv32qiv32qi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V32QImode) \
       == GET_MODE_NUNITS (V32QImode)))
#define HAVE_vcondv16hiv32qi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V16HImode) \
       == GET_MODE_NUNITS (V32QImode)))
#define HAVE_vcondv8siv32qi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SImode) \
       == GET_MODE_NUNITS (V32QImode)))
#define HAVE_vcondv4div32qi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DImode) \
       == GET_MODE_NUNITS (V32QImode)))
#define HAVE_vcondv8sfv32qi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SFmode) \
       == GET_MODE_NUNITS (V32QImode)))
#define HAVE_vcondv4dfv32qi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DFmode) \
       == GET_MODE_NUNITS (V32QImode)))
#define HAVE_vcondv32qiv16hi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V32QImode) \
       == GET_MODE_NUNITS (V16HImode)))
#define HAVE_vcondv16hiv16hi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V16HImode) \
       == GET_MODE_NUNITS (V16HImode)))
#define HAVE_vcondv8siv16hi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SImode) \
       == GET_MODE_NUNITS (V16HImode)))
#define HAVE_vcondv4div16hi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DImode) \
       == GET_MODE_NUNITS (V16HImode)))
#define HAVE_vcondv8sfv16hi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SFmode) \
       == GET_MODE_NUNITS (V16HImode)))
#define HAVE_vcondv4dfv16hi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DFmode) \
       == GET_MODE_NUNITS (V16HImode)))
#define HAVE_vcondv32qiv8si (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V32QImode) \
       == GET_MODE_NUNITS (V8SImode)))
#define HAVE_vcondv16hiv8si (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V16HImode) \
       == GET_MODE_NUNITS (V8SImode)))
#define HAVE_vcondv8siv8si (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SImode) \
       == GET_MODE_NUNITS (V8SImode)))
#define HAVE_vcondv4div8si (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DImode) \
       == GET_MODE_NUNITS (V8SImode)))
#define HAVE_vcondv8sfv8si (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SFmode) \
       == GET_MODE_NUNITS (V8SImode)))
#define HAVE_vcondv4dfv8si (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DFmode) \
       == GET_MODE_NUNITS (V8SImode)))
#define HAVE_vcondv32qiv4di (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V32QImode) \
       == GET_MODE_NUNITS (V4DImode)))
#define HAVE_vcondv16hiv4di (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V16HImode) \
       == GET_MODE_NUNITS (V4DImode)))
#define HAVE_vcondv8siv4di (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SImode) \
       == GET_MODE_NUNITS (V4DImode)))
#define HAVE_vcondv4div4di (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DImode) \
       == GET_MODE_NUNITS (V4DImode)))
#define HAVE_vcondv8sfv4di (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SFmode) \
       == GET_MODE_NUNITS (V4DImode)))
#define HAVE_vcondv4dfv4di (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DFmode) \
       == GET_MODE_NUNITS (V4DImode)))
#define HAVE_vcondv16qiv16qi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V16QImode) \
       == GET_MODE_NUNITS (V16QImode)))
#define HAVE_vcondv8hiv16qi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V8HImode) \
       == GET_MODE_NUNITS (V16QImode)))
#define HAVE_vcondv4siv16qi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V4SImode) \
       == GET_MODE_NUNITS (V16QImode)))
#define HAVE_vcondv2div16qi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V2DImode) \
       == GET_MODE_NUNITS (V16QImode)))
#define HAVE_vcondv4sfv16qi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V4SFmode) \
       == GET_MODE_NUNITS (V16QImode)))
#define HAVE_vcondv2dfv16qi ((TARGET_SSE2 \
   && (GET_MODE_NUNITS (V2DFmode) \
       == GET_MODE_NUNITS (V16QImode))) && (TARGET_SSE2))
#define HAVE_vcondv16qiv8hi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V16QImode) \
       == GET_MODE_NUNITS (V8HImode)))
#define HAVE_vcondv8hiv8hi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V8HImode) \
       == GET_MODE_NUNITS (V8HImode)))
#define HAVE_vcondv4siv8hi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V4SImode) \
       == GET_MODE_NUNITS (V8HImode)))
#define HAVE_vcondv2div8hi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V2DImode) \
       == GET_MODE_NUNITS (V8HImode)))
#define HAVE_vcondv4sfv8hi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V4SFmode) \
       == GET_MODE_NUNITS (V8HImode)))
#define HAVE_vcondv2dfv8hi ((TARGET_SSE2 \
   && (GET_MODE_NUNITS (V2DFmode) \
       == GET_MODE_NUNITS (V8HImode))) && (TARGET_SSE2))
#define HAVE_vcondv16qiv4si (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V16QImode) \
       == GET_MODE_NUNITS (V4SImode)))
#define HAVE_vcondv8hiv4si (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V8HImode) \
       == GET_MODE_NUNITS (V4SImode)))
#define HAVE_vcondv4siv4si (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V4SImode) \
       == GET_MODE_NUNITS (V4SImode)))
#define HAVE_vcondv2div4si (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V2DImode) \
       == GET_MODE_NUNITS (V4SImode)))
#define HAVE_vcondv4sfv4si (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V4SFmode) \
       == GET_MODE_NUNITS (V4SImode)))
#define HAVE_vcondv2dfv4si ((TARGET_SSE2 \
   && (GET_MODE_NUNITS (V2DFmode) \
       == GET_MODE_NUNITS (V4SImode))) && (TARGET_SSE2))
#define HAVE_vcondv2div2di (TARGET_SSE4_2)
#define HAVE_vcondv2dfv2di (TARGET_SSE4_2)
#define HAVE_vconduv64qiv64qi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V64QImode) \
       == GET_MODE_NUNITS (V64QImode))) && (TARGET_AVX512BW))
#define HAVE_vconduv32hiv64qi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V32HImode) \
       == GET_MODE_NUNITS (V64QImode))) && (TARGET_AVX512BW))
#define HAVE_vconduv16siv64qi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SImode) \
       == GET_MODE_NUNITS (V64QImode))) && (TARGET_AVX512BW))
#define HAVE_vconduv8div64qi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DImode) \
       == GET_MODE_NUNITS (V64QImode))) && (TARGET_AVX512BW))
#define HAVE_vconduv16sfv64qi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SFmode) \
       == GET_MODE_NUNITS (V64QImode))) && (TARGET_AVX512BW))
#define HAVE_vconduv8dfv64qi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DFmode) \
       == GET_MODE_NUNITS (V64QImode))) && (TARGET_AVX512BW))
#define HAVE_vconduv64qiv32hi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V64QImode) \
       == GET_MODE_NUNITS (V32HImode))) && (TARGET_AVX512BW))
#define HAVE_vconduv32hiv32hi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V32HImode) \
       == GET_MODE_NUNITS (V32HImode))) && (TARGET_AVX512BW))
#define HAVE_vconduv16siv32hi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SImode) \
       == GET_MODE_NUNITS (V32HImode))) && (TARGET_AVX512BW))
#define HAVE_vconduv8div32hi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DImode) \
       == GET_MODE_NUNITS (V32HImode))) && (TARGET_AVX512BW))
#define HAVE_vconduv16sfv32hi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SFmode) \
       == GET_MODE_NUNITS (V32HImode))) && (TARGET_AVX512BW))
#define HAVE_vconduv8dfv32hi ((TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DFmode) \
       == GET_MODE_NUNITS (V32HImode))) && (TARGET_AVX512BW))
#define HAVE_vconduv64qiv16si (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V64QImode) \
       == GET_MODE_NUNITS (V16SImode)))
#define HAVE_vconduv32hiv16si (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V32HImode) \
       == GET_MODE_NUNITS (V16SImode)))
#define HAVE_vconduv16siv16si (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SImode) \
       == GET_MODE_NUNITS (V16SImode)))
#define HAVE_vconduv8div16si (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DImode) \
       == GET_MODE_NUNITS (V16SImode)))
#define HAVE_vconduv16sfv16si (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SFmode) \
       == GET_MODE_NUNITS (V16SImode)))
#define HAVE_vconduv8dfv16si (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DFmode) \
       == GET_MODE_NUNITS (V16SImode)))
#define HAVE_vconduv64qiv8di (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V64QImode) \
       == GET_MODE_NUNITS (V8DImode)))
#define HAVE_vconduv32hiv8di (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V32HImode) \
       == GET_MODE_NUNITS (V8DImode)))
#define HAVE_vconduv16siv8di (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SImode) \
       == GET_MODE_NUNITS (V8DImode)))
#define HAVE_vconduv8div8di (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DImode) \
       == GET_MODE_NUNITS (V8DImode)))
#define HAVE_vconduv16sfv8di (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V16SFmode) \
       == GET_MODE_NUNITS (V8DImode)))
#define HAVE_vconduv8dfv8di (TARGET_AVX512F \
   && (GET_MODE_NUNITS (V8DFmode) \
       == GET_MODE_NUNITS (V8DImode)))
#define HAVE_vconduv32qiv32qi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V32QImode) \
       == GET_MODE_NUNITS (V32QImode)))
#define HAVE_vconduv16hiv32qi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V16HImode) \
       == GET_MODE_NUNITS (V32QImode)))
#define HAVE_vconduv8siv32qi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SImode) \
       == GET_MODE_NUNITS (V32QImode)))
#define HAVE_vconduv4div32qi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DImode) \
       == GET_MODE_NUNITS (V32QImode)))
#define HAVE_vconduv8sfv32qi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SFmode) \
       == GET_MODE_NUNITS (V32QImode)))
#define HAVE_vconduv4dfv32qi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DFmode) \
       == GET_MODE_NUNITS (V32QImode)))
#define HAVE_vconduv32qiv16hi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V32QImode) \
       == GET_MODE_NUNITS (V16HImode)))
#define HAVE_vconduv16hiv16hi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V16HImode) \
       == GET_MODE_NUNITS (V16HImode)))
#define HAVE_vconduv8siv16hi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SImode) \
       == GET_MODE_NUNITS (V16HImode)))
#define HAVE_vconduv4div16hi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DImode) \
       == GET_MODE_NUNITS (V16HImode)))
#define HAVE_vconduv8sfv16hi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SFmode) \
       == GET_MODE_NUNITS (V16HImode)))
#define HAVE_vconduv4dfv16hi (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DFmode) \
       == GET_MODE_NUNITS (V16HImode)))
#define HAVE_vconduv32qiv8si (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V32QImode) \
       == GET_MODE_NUNITS (V8SImode)))
#define HAVE_vconduv16hiv8si (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V16HImode) \
       == GET_MODE_NUNITS (V8SImode)))
#define HAVE_vconduv8siv8si (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SImode) \
       == GET_MODE_NUNITS (V8SImode)))
#define HAVE_vconduv4div8si (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DImode) \
       == GET_MODE_NUNITS (V8SImode)))
#define HAVE_vconduv8sfv8si (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SFmode) \
       == GET_MODE_NUNITS (V8SImode)))
#define HAVE_vconduv4dfv8si (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DFmode) \
       == GET_MODE_NUNITS (V8SImode)))
#define HAVE_vconduv32qiv4di (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V32QImode) \
       == GET_MODE_NUNITS (V4DImode)))
#define HAVE_vconduv16hiv4di (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V16HImode) \
       == GET_MODE_NUNITS (V4DImode)))
#define HAVE_vconduv8siv4di (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SImode) \
       == GET_MODE_NUNITS (V4DImode)))
#define HAVE_vconduv4div4di (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DImode) \
       == GET_MODE_NUNITS (V4DImode)))
#define HAVE_vconduv8sfv4di (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V8SFmode) \
       == GET_MODE_NUNITS (V4DImode)))
#define HAVE_vconduv4dfv4di (TARGET_AVX2 \
   && (GET_MODE_NUNITS (V4DFmode) \
       == GET_MODE_NUNITS (V4DImode)))
#define HAVE_vconduv16qiv16qi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V16QImode) \
       == GET_MODE_NUNITS (V16QImode)))
#define HAVE_vconduv8hiv16qi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V8HImode) \
       == GET_MODE_NUNITS (V16QImode)))
#define HAVE_vconduv4siv16qi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V4SImode) \
       == GET_MODE_NUNITS (V16QImode)))
#define HAVE_vconduv2div16qi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V2DImode) \
       == GET_MODE_NUNITS (V16QImode)))
#define HAVE_vconduv4sfv16qi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V4SFmode) \
       == GET_MODE_NUNITS (V16QImode)))
#define HAVE_vconduv2dfv16qi ((TARGET_SSE2 \
   && (GET_MODE_NUNITS (V2DFmode) \
       == GET_MODE_NUNITS (V16QImode))) && (TARGET_SSE2))
#define HAVE_vconduv16qiv8hi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V16QImode) \
       == GET_MODE_NUNITS (V8HImode)))
#define HAVE_vconduv8hiv8hi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V8HImode) \
       == GET_MODE_NUNITS (V8HImode)))
#define HAVE_vconduv4siv8hi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V4SImode) \
       == GET_MODE_NUNITS (V8HImode)))
#define HAVE_vconduv2div8hi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V2DImode) \
       == GET_MODE_NUNITS (V8HImode)))
#define HAVE_vconduv4sfv8hi (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V4SFmode) \
       == GET_MODE_NUNITS (V8HImode)))
#define HAVE_vconduv2dfv8hi ((TARGET_SSE2 \
   && (GET_MODE_NUNITS (V2DFmode) \
       == GET_MODE_NUNITS (V8HImode))) && (TARGET_SSE2))
#define HAVE_vconduv16qiv4si (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V16QImode) \
       == GET_MODE_NUNITS (V4SImode)))
#define HAVE_vconduv8hiv4si (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V8HImode) \
       == GET_MODE_NUNITS (V4SImode)))
#define HAVE_vconduv4siv4si (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V4SImode) \
       == GET_MODE_NUNITS (V4SImode)))
#define HAVE_vconduv2div4si (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V2DImode) \
       == GET_MODE_NUNITS (V4SImode)))
#define HAVE_vconduv4sfv4si (TARGET_SSE2 \
   && (GET_MODE_NUNITS (V4SFmode) \
       == GET_MODE_NUNITS (V4SImode)))
#define HAVE_vconduv2dfv4si ((TARGET_SSE2 \
   && (GET_MODE_NUNITS (V2DFmode) \
       == GET_MODE_NUNITS (V4SImode))) && (TARGET_SSE2))
#define HAVE_vconduv2div2di (TARGET_SSE4_2)
#define HAVE_vconduv2dfv2di (TARGET_SSE4_2)
#define HAVE_vec_permv16qi (TARGET_SSSE3 || TARGET_AVX || TARGET_XOP)
#define HAVE_vec_permv8hi (TARGET_SSSE3 || TARGET_AVX || TARGET_XOP)
#define HAVE_vec_permv4si (TARGET_SSSE3 || TARGET_AVX || TARGET_XOP)
#define HAVE_vec_permv2di (TARGET_SSSE3 || TARGET_AVX || TARGET_XOP)
#define HAVE_vec_permv4sf (TARGET_SSSE3 || TARGET_AVX || TARGET_XOP)
#define HAVE_vec_permv2df (TARGET_SSSE3 || TARGET_AVX || TARGET_XOP)
#define HAVE_vec_permv32qi ((TARGET_SSSE3 || TARGET_AVX || TARGET_XOP) && (TARGET_AVX2))
#define HAVE_vec_permv16hi ((TARGET_SSSE3 || TARGET_AVX || TARGET_XOP) && (TARGET_AVX2))
#define HAVE_vec_permv8si ((TARGET_SSSE3 || TARGET_AVX || TARGET_XOP) && (TARGET_AVX2))
#define HAVE_vec_permv4di ((TARGET_SSSE3 || TARGET_AVX || TARGET_XOP) && (TARGET_AVX2))
#define HAVE_vec_permv8sf ((TARGET_SSSE3 || TARGET_AVX || TARGET_XOP) && (TARGET_AVX2))
#define HAVE_vec_permv4df ((TARGET_SSSE3 || TARGET_AVX || TARGET_XOP) && (TARGET_AVX2))
#define HAVE_vec_permv16sf ((TARGET_SSSE3 || TARGET_AVX || TARGET_XOP) && (TARGET_AVX512F))
#define HAVE_vec_permv8df ((TARGET_SSSE3 || TARGET_AVX || TARGET_XOP) && (TARGET_AVX512F))
#define HAVE_vec_permv16si ((TARGET_SSSE3 || TARGET_AVX || TARGET_XOP) && (TARGET_AVX512F))
#define HAVE_vec_permv8di ((TARGET_SSSE3 || TARGET_AVX || TARGET_XOP) && (TARGET_AVX512F))
#define HAVE_vec_permv32hi ((TARGET_SSSE3 || TARGET_AVX || TARGET_XOP) && (TARGET_AVX512BW))
#define HAVE_vec_permv64qi ((TARGET_SSSE3 || TARGET_AVX || TARGET_XOP) && (TARGET_AVX512VBMI))
#define HAVE_vec_perm_constv4sf (TARGET_SSE)
#define HAVE_vec_perm_constv4si (TARGET_SSE)
#define HAVE_vec_perm_constv2df (TARGET_SSE)
#define HAVE_vec_perm_constv2di (TARGET_SSE)
#define HAVE_vec_perm_constv16qi (TARGET_SSE2)
#define HAVE_vec_perm_constv8hi (TARGET_SSE2)
#define HAVE_vec_perm_constv8sf (TARGET_AVX)
#define HAVE_vec_perm_constv4df (TARGET_AVX)
#define HAVE_vec_perm_constv8si (TARGET_AVX)
#define HAVE_vec_perm_constv4di (TARGET_AVX)
#define HAVE_vec_perm_constv32qi (TARGET_AVX2)
#define HAVE_vec_perm_constv16hi (TARGET_AVX2)
#define HAVE_vec_perm_constv16si (TARGET_AVX512F)
#define HAVE_vec_perm_constv8di (TARGET_AVX512F)
#define HAVE_vec_perm_constv16sf (TARGET_AVX512F)
#define HAVE_vec_perm_constv8df (TARGET_AVX512F)
#define HAVE_vec_perm_constv32hi (TARGET_AVX512BW)
#define HAVE_vec_perm_constv64qi (TARGET_AVX512BW)
#define HAVE_one_cmplv16si2 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_one_cmplv8di2 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_one_cmplv64qi2 ((TARGET_SSE) && (TARGET_AVX512BW))
#define HAVE_one_cmplv32qi2 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_one_cmplv16qi2 (TARGET_SSE)
#define HAVE_one_cmplv32hi2 ((TARGET_SSE) && (TARGET_AVX512BW))
#define HAVE_one_cmplv16hi2 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_one_cmplv8hi2 (TARGET_SSE)
#define HAVE_one_cmplv8si2 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_one_cmplv4si2 (TARGET_SSE)
#define HAVE_one_cmplv4di2 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_one_cmplv2di2 (TARGET_SSE)
#define HAVE_avx512bw_andnotv64qi3 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_avx2_andnotv32qi3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_sse2_andnotv16qi3 (TARGET_SSE2)
#define HAVE_avx512bw_andnotv32hi3 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_avx2_andnotv16hi3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_sse2_andnotv8hi3 (TARGET_SSE2)
#define HAVE_avx512f_andnotv16si3 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_avx2_andnotv8si3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_sse2_andnotv4si3 (TARGET_SSE2)
#define HAVE_avx512f_andnotv8di3 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_avx2_andnotv4di3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_sse2_andnotv2di3 (TARGET_SSE2)
#define HAVE_avx512f_andnotv16si3_mask (TARGET_AVX512F)
#define HAVE_avx2_andnotv8si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_sse2_andnotv4si3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_andnotv8di3_mask (TARGET_AVX512F)
#define HAVE_avx2_andnotv4di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_sse2_andnotv2di3_mask ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512bw_andnotv64qi3_mask (TARGET_AVX512BW)
#define HAVE_sse2_andnotv16qi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx2_andnotv32qi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_andnotv32hi3_mask (TARGET_AVX512BW)
#define HAVE_avx2_andnotv16hi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_sse2_andnotv8hi3_mask ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_andv16si3 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_iorv16si3 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_xorv16si3 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_andv8di3 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_iorv8di3 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_xorv8di3 ((TARGET_SSE) && (TARGET_AVX512F))
#define HAVE_andv64qi3 ((TARGET_SSE) && (TARGET_AVX512BW))
#define HAVE_iorv64qi3 ((TARGET_SSE) && (TARGET_AVX512BW))
#define HAVE_xorv64qi3 ((TARGET_SSE) && (TARGET_AVX512BW))
#define HAVE_andv32qi3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_iorv32qi3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_xorv32qi3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_andv16qi3 (TARGET_SSE)
#define HAVE_iorv16qi3 (TARGET_SSE)
#define HAVE_xorv16qi3 (TARGET_SSE)
#define HAVE_andv32hi3 ((TARGET_SSE) && (TARGET_AVX512BW))
#define HAVE_iorv32hi3 ((TARGET_SSE) && (TARGET_AVX512BW))
#define HAVE_xorv32hi3 ((TARGET_SSE) && (TARGET_AVX512BW))
#define HAVE_andv16hi3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_iorv16hi3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_xorv16hi3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_andv8hi3 (TARGET_SSE)
#define HAVE_iorv8hi3 (TARGET_SSE)
#define HAVE_xorv8hi3 (TARGET_SSE)
#define HAVE_andv8si3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_iorv8si3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_xorv8si3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_andv4si3 (TARGET_SSE)
#define HAVE_iorv4si3 (TARGET_SSE)
#define HAVE_xorv4si3 (TARGET_SSE)
#define HAVE_andv4di3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_iorv4di3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_xorv4di3 ((TARGET_SSE) && (TARGET_AVX))
#define HAVE_andv2di3 (TARGET_SSE)
#define HAVE_iorv2di3 (TARGET_SSE)
#define HAVE_xorv2di3 (TARGET_SSE)
#define HAVE_vec_pack_trunc_v32hi ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_vec_pack_trunc_v16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_pack_trunc_v8hi (TARGET_SSE2)
#define HAVE_vec_pack_trunc_v16si ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_vec_pack_trunc_v8si ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_pack_trunc_v4si (TARGET_SSE2)
#define HAVE_vec_pack_trunc_v8di ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_pack_trunc_v4di ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_pack_trunc_v2di (TARGET_SSE2)
#define HAVE_vec_pack_trunc_qi (TARGET_AVX512F)
#define HAVE_vec_pack_trunc_hi (TARGET_AVX512BW)
#define HAVE_vec_pack_trunc_si (TARGET_AVX512BW)
#define HAVE_vec_interleave_highv32qi (TARGET_AVX2)
#define HAVE_vec_interleave_highv16hi (TARGET_AVX2)
#define HAVE_vec_interleave_highv8si (TARGET_AVX2)
#define HAVE_vec_interleave_highv4di (TARGET_AVX2)
#define HAVE_vec_interleave_lowv32qi (TARGET_AVX2)
#define HAVE_vec_interleave_lowv16hi (TARGET_AVX2)
#define HAVE_vec_interleave_lowv8si (TARGET_AVX2)
#define HAVE_vec_interleave_lowv4di (TARGET_AVX2)
#define HAVE_avx512dq_vinsertf64x2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512dq_vinserti64x2_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512f_vinsertf32x4_mask (TARGET_AVX512F)
#define HAVE_avx512f_vinserti32x4_mask (TARGET_AVX512F)
#define HAVE_avx512dq_vinsertf32x8_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512dq_vinserti32x8_mask ((TARGET_AVX512F) && (TARGET_AVX512DQ))
#define HAVE_avx512f_vinsertf64x4_mask (TARGET_AVX512F)
#define HAVE_avx512f_vinserti64x4_mask (TARGET_AVX512F)
#define HAVE_avx512dq_shuf_i64x2_mask (TARGET_AVX512DQ)
#define HAVE_avx512dq_shuf_f64x2_mask (TARGET_AVX512DQ)
#define HAVE_avx512f_shuf_f64x2_mask (TARGET_AVX512F)
#define HAVE_avx512f_shuf_i64x2_mask (TARGET_AVX512F)
#define HAVE_avx512vl_shuf_i32x4_mask (TARGET_AVX512VL)
#define HAVE_avx512vl_shuf_f32x4_mask (TARGET_AVX512VL)
#define HAVE_avx512f_shuf_f32x4_mask (TARGET_AVX512F)
#define HAVE_avx512f_shuf_i32x4_mask (TARGET_AVX512F)
#define HAVE_avx512f_pshufdv3_mask (TARGET_AVX512F)
#define HAVE_avx512vl_pshufdv3_mask (TARGET_AVX512VL)
#define HAVE_avx2_pshufdv3 (TARGET_AVX2)
#define HAVE_avx512vl_pshufd_mask (TARGET_AVX512VL)
#define HAVE_sse2_pshufd (TARGET_SSE2)
#define HAVE_avx512vl_pshuflwv3_mask (TARGET_AVX512VL && TARGET_AVX512BW)
#define HAVE_avx2_pshuflwv3 (TARGET_AVX2)
#define HAVE_avx512vl_pshuflw_mask (TARGET_AVX512VL && TARGET_AVX512BW)
#define HAVE_sse2_pshuflw (TARGET_SSE2)
#define HAVE_avx2_pshufhwv3 (TARGET_AVX2)
#define HAVE_avx512vl_pshufhwv3_mask (TARGET_AVX512VL && TARGET_AVX512BW)
#define HAVE_avx512vl_pshufhw_mask (TARGET_AVX512VL && TARGET_AVX512BW)
#define HAVE_sse2_pshufhw (TARGET_SSE2)
#define HAVE_sse2_loadd (TARGET_SSE)
#define HAVE_vec_unpacks_lo_v64qi ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_vec_unpacks_lo_v32qi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacks_lo_v16qi (TARGET_SSE2)
#define HAVE_vec_unpacks_lo_v32hi ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_unpacks_lo_v16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacks_lo_v8hi (TARGET_SSE2)
#define HAVE_vec_unpacks_lo_v16si ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_unpacks_lo_v8si ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacks_lo_v4si (TARGET_SSE2)
#define HAVE_vec_unpacks_hi_v64qi ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_vec_unpacks_hi_v32qi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacks_hi_v16qi (TARGET_SSE2)
#define HAVE_vec_unpacks_hi_v32hi ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_unpacks_hi_v16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacks_hi_v8hi (TARGET_SSE2)
#define HAVE_vec_unpacks_hi_v16si ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_unpacks_hi_v8si ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacks_hi_v4si (TARGET_SSE2)
#define HAVE_vec_unpacku_lo_v64qi ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_vec_unpacku_lo_v32qi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacku_lo_v16qi (TARGET_SSE2)
#define HAVE_vec_unpacku_lo_v32hi ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_unpacku_lo_v16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacku_lo_v8hi (TARGET_SSE2)
#define HAVE_vec_unpacku_lo_v16si ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_unpacku_lo_v8si ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacku_lo_v4si (TARGET_SSE2)
#define HAVE_vec_unpacks_lo_hi (TARGET_AVX512DQ)
#define HAVE_vec_unpacks_lo_si (TARGET_AVX512F)
#define HAVE_vec_unpacks_lo_di (TARGET_AVX512BW)
#define HAVE_vec_unpacku_hi_v64qi ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_vec_unpacku_hi_v32qi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacku_hi_v16qi (TARGET_SSE2)
#define HAVE_vec_unpacku_hi_v32hi ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_unpacku_hi_v16hi ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacku_hi_v8hi (TARGET_SSE2)
#define HAVE_vec_unpacku_hi_v16si ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_vec_unpacku_hi_v8si ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_vec_unpacku_hi_v4si (TARGET_SSE2)
#define HAVE_vec_unpacks_hi_hi (TARGET_AVX512F)
#define HAVE_vec_unpacks_hi_si (TARGET_AVX512BW)
#define HAVE_vec_unpacks_hi_di (TARGET_AVX512BW)
#define HAVE_avx512bw_uavgv64qi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_uavgv64qi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx2_uavgv32qi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_uavgv32qi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_sse2_uavgv16qi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_uavgv16qi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_avx512bw_uavgv32hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX512BW))
#define HAVE_avx512bw_uavgv32hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (64 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX512BW)))
#define HAVE_avx2_uavgv16hi3 ((TARGET_SSE2 && 1 && 1) && (TARGET_AVX2))
#define HAVE_avx2_uavgv16hi3_mask ((TARGET_AVX512F) && ((TARGET_SSE2 && (32 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW) && (TARGET_AVX2)))
#define HAVE_sse2_uavgv8hi3 (TARGET_SSE2 && 1 && 1)
#define HAVE_sse2_uavgv8hi3_mask ((TARGET_AVX512F) && (TARGET_SSE2 && (16 == 64 || TARGET_AVX512VL) && TARGET_AVX512BW))
#define HAVE_sse2_maskmovdqu (TARGET_SSE2)
#define HAVE_ssse3_pmulhrswv4hi3_mask (TARGET_AVX512BW && TARGET_AVX512VL)
#define HAVE_ssse3_pmulhrswv8hi3_mask (TARGET_AVX512BW && TARGET_AVX512VL)
#define HAVE_avx2_pmulhrswv16hi3_mask ((TARGET_AVX512BW && TARGET_AVX512VL) && (TARGET_AVX2))
#define HAVE_ssse3_pmulhrswv4hi3 (TARGET_AVX2)
#define HAVE_ssse3_pmulhrswv8hi3 (TARGET_AVX2)
#define HAVE_avx2_pmulhrswv16hi3 (TARGET_AVX2)
#define HAVE_absv64qi2 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_absv32qi2 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_absv16qi2 (TARGET_SSE2)
#define HAVE_absv32hi2 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_absv16hi2 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_absv8hi2 (TARGET_SSE2)
#define HAVE_absv16si2 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_absv8si2 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_absv4si2 (TARGET_SSE2)
#define HAVE_absv8di2 ((TARGET_SSE2) && (TARGET_AVX512F))
#define HAVE_absv4di2 ((TARGET_SSE2) && (TARGET_AVX512VL))
#define HAVE_absv2di2 ((TARGET_SSE2) && (TARGET_AVX512VL))
#define HAVE_avx2_pblendw (TARGET_AVX2)
#define HAVE_avx_roundps_sfix256 ((TARGET_ROUND) && (TARGET_AVX))
#define HAVE_sse4_1_roundps_sfix (TARGET_ROUND)
#define HAVE_avx512f_roundps512 (TARGET_AVX512F)
#define HAVE_avx512f_roundpd512 (TARGET_AVX512F)
#define HAVE_avx512f_roundps512_sfix (TARGET_AVX512F)
#define HAVE_avx512f_roundpd_vec_pack_sfix512 ((TARGET_ROUND) && (TARGET_AVX512F))
#define HAVE_avx_roundpd_vec_pack_sfix256 ((TARGET_ROUND) && (TARGET_AVX))
#define HAVE_sse4_1_roundpd_vec_pack_sfix (TARGET_ROUND)
#define HAVE_roundv16sf2 ((TARGET_ROUND && !flag_trapping_math) && (TARGET_AVX512F))
#define HAVE_roundv8sf2 ((TARGET_ROUND && !flag_trapping_math) && (TARGET_AVX))
#define HAVE_roundv4sf2 (TARGET_ROUND && !flag_trapping_math)
#define HAVE_roundv8df2 ((TARGET_ROUND && !flag_trapping_math) && (TARGET_AVX512F))
#define HAVE_roundv4df2 ((TARGET_ROUND && !flag_trapping_math) && (TARGET_AVX))
#define HAVE_roundv2df2 ((TARGET_ROUND && !flag_trapping_math) && (TARGET_SSE2))
#define HAVE_roundv16sf2_sfix ((TARGET_ROUND && !flag_trapping_math) && (TARGET_AVX512F))
#define HAVE_roundv8sf2_sfix ((TARGET_ROUND && !flag_trapping_math) && (TARGET_AVX))
#define HAVE_roundv4sf2_sfix (TARGET_ROUND && !flag_trapping_math)
#define HAVE_roundv8df2_vec_pack_sfix ((TARGET_ROUND && !flag_trapping_math) && (TARGET_AVX512F))
#define HAVE_roundv4df2_vec_pack_sfix ((TARGET_ROUND && !flag_trapping_math) && (TARGET_AVX))
#define HAVE_roundv2df2_vec_pack_sfix (TARGET_ROUND && !flag_trapping_math)
#define HAVE_avx512pf_gatherpfv16sisf (TARGET_AVX512PF)
#define HAVE_avx512pf_gatherpfv8disf (TARGET_AVX512PF)
#define HAVE_avx512pf_gatherpfv8sidf (TARGET_AVX512PF)
#define HAVE_avx512pf_gatherpfv8didf (TARGET_AVX512PF)
#define HAVE_avx512pf_scatterpfv16sisf (TARGET_AVX512PF)
#define HAVE_avx512pf_scatterpfv8disf (TARGET_AVX512PF)
#define HAVE_avx512pf_scatterpfv8sidf (TARGET_AVX512PF)
#define HAVE_avx512pf_scatterpfv8didf (TARGET_AVX512PF)
#define HAVE_rotlv16qi3 (TARGET_XOP)
#define HAVE_rotlv8hi3 (TARGET_XOP)
#define HAVE_rotlv4si3 (TARGET_XOP)
#define HAVE_rotlv2di3 (TARGET_XOP)
#define HAVE_rotrv16qi3 (TARGET_XOP)
#define HAVE_rotrv8hi3 (TARGET_XOP)
#define HAVE_rotrv4si3 (TARGET_XOP)
#define HAVE_rotrv2di3 (TARGET_XOP)
#define HAVE_vrotrv16qi3 (TARGET_XOP)
#define HAVE_vrotrv8hi3 (TARGET_XOP)
#define HAVE_vrotrv4si3 (TARGET_XOP)
#define HAVE_vrotrv2di3 (TARGET_XOP)
#define HAVE_vrotlv16qi3 (TARGET_XOP)
#define HAVE_vrotlv8hi3 (TARGET_XOP)
#define HAVE_vrotlv4si3 (TARGET_XOP)
#define HAVE_vrotlv2di3 (TARGET_XOP)
#define HAVE_vlshrv16qi3 (TARGET_XOP)
#define HAVE_vlshrv8hi3 (TARGET_XOP)
#define HAVE_vlshrv4si3 (TARGET_AVX2 || TARGET_XOP)
#define HAVE_vlshrv2di3 (TARGET_AVX2 || TARGET_XOP)
#define HAVE_vlshrv16si3 (TARGET_AVX512F)
#define HAVE_vlshrv8di3 (TARGET_AVX512F)
#define HAVE_vlshrv8si3 (TARGET_AVX2)
#define HAVE_vlshrv4di3 (TARGET_AVX2)
#define HAVE_vashrv8hi3 (TARGET_XOP || (TARGET_AVX512BW && TARGET_AVX512VL))
#define HAVE_vashrv8hi3_mask ((TARGET_AVX512F) && (TARGET_XOP || (TARGET_AVX512BW && TARGET_AVX512VL)))
#define HAVE_vashrv16qi3 (TARGET_XOP)
#define HAVE_vashrv2di3 (TARGET_XOP || TARGET_AVX512VL)
#define HAVE_vashrv2di3_mask ((TARGET_AVX512F) && (TARGET_XOP || TARGET_AVX512VL))
#define HAVE_vashrv4si3 (TARGET_AVX2 || TARGET_XOP)
#define HAVE_vashrv16si3 (TARGET_AVX512F)
#define HAVE_vashrv8si3 (TARGET_AVX2)
#define HAVE_vashlv16qi3 (TARGET_XOP)
#define HAVE_vashlv8hi3 (TARGET_XOP)
#define HAVE_vashlv4si3 (TARGET_AVX2 || TARGET_XOP)
#define HAVE_vashlv2di3 (TARGET_AVX2 || TARGET_XOP)
#define HAVE_vashlv16si3 (TARGET_AVX512F)
#define HAVE_vashlv8di3 (TARGET_AVX512F)
#define HAVE_vashlv8si3 (TARGET_AVX2)
#define HAVE_vashlv4di3 (TARGET_AVX2)
#define HAVE_ashlv64qi3 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_lshrv64qi3 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_ashrv64qi3 ((TARGET_SSE2) && (TARGET_AVX512BW))
#define HAVE_ashlv32qi3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_lshrv32qi3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_ashrv32qi3 ((TARGET_SSE2) && (TARGET_AVX2))
#define HAVE_ashlv16qi3 (TARGET_SSE2)
#define HAVE_lshrv16qi3 (TARGET_SSE2)
#define HAVE_ashrv16qi3 (TARGET_SSE2)
#define HAVE_ashrv2di3 (TARGET_XOP || TARGET_AVX512VL)
#define HAVE_xop_vmfrczv4sf2 (TARGET_XOP)
#define HAVE_xop_vmfrczv2df2 ((TARGET_XOP) && (TARGET_SSE2))
#define HAVE_avx_vzeroall (TARGET_AVX)
#define HAVE_avx2_permv4di (TARGET_AVX2)
#define HAVE_avx2_permv4df (TARGET_AVX2)
#define HAVE_avx512f_permv8di ((TARGET_AVX2) && (TARGET_AVX512F))
#define HAVE_avx512f_permv8df ((TARGET_AVX2) && (TARGET_AVX512F))
#define HAVE_avx512vl_permv4di_mask (TARGET_AVX512F)
#define HAVE_avx512vl_permv4df_mask (TARGET_AVX512F)
#define HAVE_avx512f_permv8di_mask (TARGET_AVX512F)
#define HAVE_avx512f_permv8df_mask (TARGET_AVX512F)
#define HAVE_avx512f_vpermilv8df ((TARGET_AVX && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_vpermilv8df_mask ((TARGET_AVX512F) && ((TARGET_AVX && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx_vpermilv4df ((TARGET_AVX && 1) && (TARGET_AVX))
#define HAVE_avx_vpermilv4df_mask ((TARGET_AVX512F) && ((TARGET_AVX && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX)))
#define HAVE_avx_vpermilv2df (TARGET_AVX && 1)
#define HAVE_avx_vpermilv2df_mask ((TARGET_AVX512F) && (TARGET_AVX && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_avx512f_vpermilv16sf ((TARGET_AVX && 1) && (TARGET_AVX512F))
#define HAVE_avx512f_vpermilv16sf_mask ((TARGET_AVX512F) && ((TARGET_AVX && (64 == 64 || TARGET_AVX512VL)) && (TARGET_AVX512F)))
#define HAVE_avx_vpermilv8sf ((TARGET_AVX && 1) && (TARGET_AVX))
#define HAVE_avx_vpermilv8sf_mask ((TARGET_AVX512F) && ((TARGET_AVX && (32 == 64 || TARGET_AVX512VL)) && (TARGET_AVX)))
#define HAVE_avx_vpermilv4sf (TARGET_AVX && 1)
#define HAVE_avx_vpermilv4sf_mask ((TARGET_AVX512F) && (TARGET_AVX && (16 == 64 || TARGET_AVX512VL)))
#define HAVE_avx512f_vpermi2varv16si3_maskz (TARGET_AVX512F)
#define HAVE_avx512f_vpermi2varv16sf3_maskz (TARGET_AVX512F)
#define HAVE_avx512f_vpermi2varv8di3_maskz (TARGET_AVX512F)
#define HAVE_avx512f_vpermi2varv8df3_maskz (TARGET_AVX512F)
#define HAVE_avx512vl_vpermi2varv8si3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv8sf3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4di3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4df3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4si3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv4sf3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv2di3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv2df3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512bw_vpermi2varv64qi3_maskz (TARGET_AVX512VBMI)
#define HAVE_avx512vl_vpermi2varv16qi3_maskz ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv32qi3_maskz ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv8hi3_maskz ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermi2varv16hi3_maskz ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_vpermi2varv32hi3_maskz (TARGET_AVX512BW)
#define HAVE_avx512f_vpermt2varv16si3_maskz (TARGET_AVX512F)
#define HAVE_avx512f_vpermt2varv16sf3_maskz (TARGET_AVX512F)
#define HAVE_avx512f_vpermt2varv8di3_maskz (TARGET_AVX512F)
#define HAVE_avx512f_vpermt2varv8df3_maskz (TARGET_AVX512F)
#define HAVE_avx512vl_vpermt2varv8si3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv8sf3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4di3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4df3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4si3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv4sf3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv2di3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv2df3_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512bw_vpermt2varv64qi3_maskz (TARGET_AVX512VBMI)
#define HAVE_avx512vl_vpermt2varv16qi3_maskz ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv32qi3_maskz ((TARGET_AVX512VBMI) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv8hi3_maskz ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512vl_vpermt2varv16hi3_maskz ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_avx512bw_vpermt2varv32hi3_maskz (TARGET_AVX512BW)
#define HAVE_avx_vperm2f128v8si3 (TARGET_AVX)
#define HAVE_avx_vperm2f128v8sf3 (TARGET_AVX)
#define HAVE_avx_vperm2f128v4df3 (TARGET_AVX)
#define HAVE_avx512vl_vinsertv8si (TARGET_AVX512VL)
#define HAVE_avx512vl_vinsertv8sf (TARGET_AVX512VL)
#define HAVE_avx512vl_vinsertv4di (TARGET_AVX512VL)
#define HAVE_avx512vl_vinsertv4df (TARGET_AVX512VL)
#define HAVE_avx_vinsertf128v32qi (TARGET_AVX)
#define HAVE_avx_vinsertf128v16hi (TARGET_AVX)
#define HAVE_avx_vinsertf128v8si (TARGET_AVX)
#define HAVE_avx_vinsertf128v4di (TARGET_AVX)
#define HAVE_avx_vinsertf128v8sf (TARGET_AVX)
#define HAVE_avx_vinsertf128v4df (TARGET_AVX)
#define HAVE_maskloadv4sfv4si (TARGET_AVX)
#define HAVE_maskloadv2dfv2di (TARGET_AVX)
#define HAVE_maskloadv8sfv8si (TARGET_AVX)
#define HAVE_maskloadv4dfv4di (TARGET_AVX)
#define HAVE_maskloadv4siv4si ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_maskloadv2div2di ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_maskloadv8siv8si ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_maskloadv4div4di ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_maskloadv16sihi (TARGET_AVX512F)
#define HAVE_maskloadv8siqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskloadv4siqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskloadv8diqi (TARGET_AVX512F)
#define HAVE_maskloadv4diqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskloadv2diqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskloadv16sfhi (TARGET_AVX512F)
#define HAVE_maskloadv8sfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskloadv4sfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskloadv8dfqi (TARGET_AVX512F)
#define HAVE_maskloadv4dfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskloadv2dfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskloadv64qidi (TARGET_AVX512BW)
#define HAVE_maskloadv16qihi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_maskloadv32qisi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_maskloadv32hisi (TARGET_AVX512BW)
#define HAVE_maskloadv16hihi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_maskloadv8hiqi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_maskstorev4sfv4si (TARGET_AVX)
#define HAVE_maskstorev2dfv2di (TARGET_AVX)
#define HAVE_maskstorev8sfv8si (TARGET_AVX)
#define HAVE_maskstorev4dfv4di (TARGET_AVX)
#define HAVE_maskstorev4siv4si ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_maskstorev2div2di ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_maskstorev8siv8si ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_maskstorev4div4di ((TARGET_AVX) && (TARGET_AVX2))
#define HAVE_maskstorev16sihi (TARGET_AVX512F)
#define HAVE_maskstorev8siqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskstorev4siqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskstorev8diqi (TARGET_AVX512F)
#define HAVE_maskstorev4diqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskstorev2diqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskstorev16sfhi (TARGET_AVX512F)
#define HAVE_maskstorev8sfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskstorev4sfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskstorev8dfqi (TARGET_AVX512F)
#define HAVE_maskstorev4dfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskstorev2dfqi ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_maskstorev64qidi (TARGET_AVX512BW)
#define HAVE_maskstorev16qihi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_maskstorev32qisi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_maskstorev32hisi (TARGET_AVX512BW)
#define HAVE_maskstorev16hihi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_maskstorev8hiqi ((TARGET_AVX512BW) && (TARGET_AVX512VL))
#define HAVE_cbranchv4si4 (TARGET_SSE4_1)
#define HAVE_cbranchv2di4 (TARGET_SSE4_1)
#define HAVE_cbranchv8si4 ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_cbranchv4di4 ((TARGET_SSE4_1) && (TARGET_AVX))
#define HAVE_vec_initv32qi (TARGET_AVX)
#define HAVE_vec_initv16hi (TARGET_AVX)
#define HAVE_vec_initv8si (TARGET_AVX)
#define HAVE_vec_initv4di (TARGET_AVX)
#define HAVE_vec_initv8sf (TARGET_AVX)
#define HAVE_vec_initv4df (TARGET_AVX)
#define HAVE_vec_initv16si (TARGET_AVX512F)
#define HAVE_vec_initv16sf (TARGET_AVX512F)
#define HAVE_vec_initv8di (TARGET_AVX512F)
#define HAVE_vec_initv8df (TARGET_AVX512F)
#define HAVE_vec_initv32hi (TARGET_AVX512F)
#define HAVE_vec_initv64qi (TARGET_AVX512F)
#define HAVE_vcvtps2ph_mask (TARGET_AVX512VL)
#define HAVE_vcvtps2ph (TARGET_F16C)
#define HAVE_avx2_gathersiv2di (TARGET_AVX2)
#define HAVE_avx2_gathersiv2df (TARGET_AVX2)
#define HAVE_avx2_gathersiv4di (TARGET_AVX2)
#define HAVE_avx2_gathersiv4df (TARGET_AVX2)
#define HAVE_avx2_gathersiv4si (TARGET_AVX2)
#define HAVE_avx2_gathersiv4sf (TARGET_AVX2)
#define HAVE_avx2_gathersiv8si (TARGET_AVX2)
#define HAVE_avx2_gathersiv8sf (TARGET_AVX2)
#define HAVE_avx2_gatherdiv2di (TARGET_AVX2)
#define HAVE_avx2_gatherdiv2df (TARGET_AVX2)
#define HAVE_avx2_gatherdiv4di (TARGET_AVX2)
#define HAVE_avx2_gatherdiv4df (TARGET_AVX2)
#define HAVE_avx2_gatherdiv4si (TARGET_AVX2)
#define HAVE_avx2_gatherdiv4sf (TARGET_AVX2)
#define HAVE_avx2_gatherdiv8si (TARGET_AVX2)
#define HAVE_avx2_gatherdiv8sf (TARGET_AVX2)
#define HAVE_avx512f_gathersiv16si (TARGET_AVX512F)
#define HAVE_avx512f_gathersiv16sf (TARGET_AVX512F)
#define HAVE_avx512f_gathersiv8di (TARGET_AVX512F)
#define HAVE_avx512f_gathersiv8df (TARGET_AVX512F)
#define HAVE_avx512vl_gathersiv8si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gathersiv8sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gathersiv4di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gathersiv4df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gathersiv4si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gathersiv4sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gathersiv2di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gathersiv2df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_gatherdiv16si (TARGET_AVX512F)
#define HAVE_avx512f_gatherdiv16sf (TARGET_AVX512F)
#define HAVE_avx512f_gatherdiv8di (TARGET_AVX512F)
#define HAVE_avx512f_gatherdiv8df (TARGET_AVX512F)
#define HAVE_avx512vl_gatherdiv8si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gatherdiv8sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gatherdiv4di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gatherdiv4df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gatherdiv4si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gatherdiv4sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gatherdiv2di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_gatherdiv2df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_scattersiv16si (TARGET_AVX512F)
#define HAVE_avx512f_scattersiv16sf (TARGET_AVX512F)
#define HAVE_avx512f_scattersiv8di (TARGET_AVX512F)
#define HAVE_avx512f_scattersiv8df (TARGET_AVX512F)
#define HAVE_avx512vl_scattersiv8si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scattersiv8sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scattersiv4di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scattersiv4df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scattersiv4si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scattersiv4sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scattersiv2di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scattersiv2df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_scatterdiv16si (TARGET_AVX512F)
#define HAVE_avx512f_scatterdiv16sf (TARGET_AVX512F)
#define HAVE_avx512f_scatterdiv8di (TARGET_AVX512F)
#define HAVE_avx512f_scatterdiv8df (TARGET_AVX512F)
#define HAVE_avx512vl_scatterdiv8si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scatterdiv8sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scatterdiv4di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scatterdiv4df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scatterdiv4si ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scatterdiv4sf ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scatterdiv2di ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_scatterdiv2df ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512f_expandv16si_maskz (TARGET_AVX512F)
#define HAVE_avx512f_expandv16sf_maskz (TARGET_AVX512F)
#define HAVE_avx512f_expandv8di_maskz (TARGET_AVX512F)
#define HAVE_avx512f_expandv8df_maskz (TARGET_AVX512F)
#define HAVE_avx512vl_expandv8si_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv8sf_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv4di_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv4df_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv4si_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv4sf_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv2di_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_avx512vl_expandv2df_maskz ((TARGET_AVX512F) && (TARGET_AVX512VL))
#define HAVE_vpamdd52huqv8di_maskz (TARGET_AVX512IFMA)
#define HAVE_vpamdd52huqv4di_maskz ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52huqv2di_maskz ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52luqv8di_maskz (TARGET_AVX512IFMA)
#define HAVE_vpamdd52luqv4di_maskz ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_vpamdd52luqv2di_maskz ((TARGET_AVX512IFMA) && (TARGET_AVX512VL))
#define HAVE_sse2_lfence (TARGET_SSE2)
#define HAVE_sse_sfence (TARGET_SSE || TARGET_3DNOW_A)
#define HAVE_sse2_mfence (TARGET_SSE2)
#define HAVE_mem_thread_fence 1
#define HAVE_atomic_loadqi 1
#define HAVE_atomic_loadhi 1
#define HAVE_atomic_loadsi 1
#define HAVE_atomic_loaddi (TARGET_64BIT || (TARGET_CMPXCHG8B && (TARGET_80387 || TARGET_SSE)))
#define HAVE_atomic_storeqi 1
#define HAVE_atomic_storehi 1
#define HAVE_atomic_storesi 1
#define HAVE_atomic_storedi (TARGET_64BIT || (TARGET_CMPXCHG8B && (TARGET_80387 || TARGET_SSE)))
#define HAVE_atomic_compare_and_swapqi (TARGET_CMPXCHG)
#define HAVE_atomic_compare_and_swaphi (TARGET_CMPXCHG)
#define HAVE_atomic_compare_and_swapsi (TARGET_CMPXCHG)
#define HAVE_atomic_compare_and_swapdi ((TARGET_CMPXCHG) && (TARGET_64BIT || TARGET_CMPXCHG8B))
#define HAVE_atomic_compare_and_swapti ((TARGET_CMPXCHG) && (TARGET_64BIT && TARGET_CMPXCHG16B))
extern rtx        gen_x86_fnstsw_1                               (rtx);
extern rtx        gen_x86_sahf_1                                 (rtx);
extern rtx        gen_kmovw                                      (rtx, rtx);
extern rtx        gen_insvhi_1                                   (rtx, rtx);
extern rtx        gen_insvsi_1                                   (rtx, rtx);
extern rtx        gen_insvdi_1                                   (rtx, rtx);
extern rtx        gen_swapxf                                     (rtx, rtx);
extern rtx        gen_zero_extendqidi2                           (rtx, rtx);
extern rtx        gen_zero_extendhidi2                           (rtx, rtx);
extern rtx        gen_zero_extendqisi2_and                       (rtx, rtx);
extern rtx        gen_zero_extendhisi2_and                       (rtx, rtx);
extern rtx        gen_zero_extendqihi2_and                       (rtx, rtx);
extern rtx        gen_extendsidi2_1                              (rtx, rtx);
extern rtx        gen_extendqidi2                                (rtx, rtx);
extern rtx        gen_extendhidi2                                (rtx, rtx);
extern rtx        gen_extendhisi2                                (rtx, rtx);
extern rtx        gen_extendqisi2                                (rtx, rtx);
extern rtx        gen_extendqihi2                                (rtx, rtx);
extern rtx        gen_truncxfsf2_i387_noop                       (rtx, rtx);
extern rtx        gen_truncxfdf2_i387_noop                       (rtx, rtx);
extern rtx        gen_fix_truncsfsi_sse                          (rtx, rtx);
extern rtx        gen_fix_truncsfdi_sse                          (rtx, rtx);
extern rtx        gen_fix_truncdfsi_sse                          (rtx, rtx);
extern rtx        gen_fix_truncdfdi_sse                          (rtx, rtx);
extern rtx        gen_fix_trunchi_fisttp_i387_1                  (rtx, rtx);
extern rtx        gen_fix_truncsi_fisttp_i387_1                  (rtx, rtx);
extern rtx        gen_fix_truncdi_fisttp_i387_1                  (rtx, rtx);
extern rtx        gen_fix_trunchi_i387_fisttp                    (rtx, rtx);
extern rtx        gen_fix_truncsi_i387_fisttp                    (rtx, rtx);
extern rtx        gen_fix_truncdi_i387_fisttp                    (rtx, rtx);
extern rtx        gen_fix_trunchi_i387_fisttp_with_temp          (rtx, rtx, rtx);
extern rtx        gen_fix_truncsi_i387_fisttp_with_temp          (rtx, rtx, rtx);
extern rtx        gen_fix_truncdi_i387_fisttp_with_temp          (rtx, rtx, rtx);
extern rtx        gen_fix_truncdi_i387                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncdi_i387_with_temp                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fix_trunchi_i387                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncsi_i387                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_trunchi_i387_with_temp                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncsi_i387_with_temp                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_x86_fnstcw_1                               (rtx);
extern rtx        gen_x86_fldcw_1                                (rtx);
extern rtx        gen_floathisf2                                 (rtx, rtx);
extern rtx        gen_floathidf2                                 (rtx, rtx);
extern rtx        gen_floathixf2                                 (rtx, rtx);
extern rtx        gen_floatsixf2                                 (rtx, rtx);
extern rtx        gen_floatdixf2                                 (rtx, rtx);
extern rtx        gen_floatdisf2_i387_with_xmm                   (rtx, rtx, rtx);
extern rtx        gen_floatdidf2_i387_with_xmm                   (rtx, rtx, rtx);
extern rtx        gen_floatdixf2_i387_with_xmm                   (rtx, rtx, rtx);
extern rtx        gen_addsi_1_zext                               (rtx, rtx, rtx);
extern rtx        gen_addqi_ext_1                                (rtx, rtx, rtx);
extern rtx        gen_addqi3_carry                               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addhi3_carry                               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addsi3_carry                               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_adddi3_carry                               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addcarrysi                                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addcarrydi                                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subqi3_carry                               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subhi3_carry                               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subsi3_carry                               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subdi3_carry                               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subborrowsi                                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subborrowdi                                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_divmodsi4_1                                (rtx, rtx, rtx, rtx);
extern rtx        gen_divmoddi4_1                                (rtx, rtx, rtx, rtx);
extern rtx        gen_divmodhiqi3                                (rtx, rtx, rtx);
extern rtx        gen_udivmodsi4_1                               (rtx, rtx, rtx, rtx);
extern rtx        gen_udivmoddi4_1                               (rtx, rtx, rtx, rtx);
extern rtx        gen_udivmodhiqi3                               (rtx, rtx, rtx);
extern rtx        gen_kandnqi                                    (rtx, rtx, rtx);
extern rtx        gen_kandnhi                                    (rtx, rtx, rtx);
extern rtx        gen_andqi_ext_0                                (rtx, rtx, rtx);
extern rtx        gen_kxnorqi                                    (rtx, rtx, rtx);
extern rtx        gen_kxnorhi                                    (rtx, rtx, rtx);
extern rtx        gen_kxnorsi                                    (rtx, rtx, rtx);
extern rtx        gen_kxnordi                                    (rtx, rtx, rtx);
extern rtx        gen_kortestzhi                                 (rtx, rtx);
extern rtx        gen_kortestchi                                 (rtx, rtx);
extern rtx        gen_kunpckhi                                   (rtx, rtx, rtx);
extern rtx        gen_kunpcksi                                   (rtx, rtx, rtx);
extern rtx        gen_kunpckdi                                   (rtx, rtx, rtx);
extern rtx        gen_copysignsf3_const                          (rtx, rtx, rtx, rtx);
extern rtx        gen_copysigndf3_const                          (rtx, rtx, rtx, rtx);
extern rtx        gen_copysigntf3_const                          (rtx, rtx, rtx, rtx);
extern rtx        gen_copysignsf3_var                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_copysigndf3_var                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_copysigntf3_var                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_x86_64_shld                                (rtx, rtx, rtx);
extern rtx        gen_x86_shld                                   (rtx, rtx, rtx);
extern rtx        gen_x86_64_shrd                                (rtx, rtx, rtx);
extern rtx        gen_x86_shrd                                   (rtx, rtx, rtx);
extern rtx        gen_ashrdi3_cvt                                (rtx, rtx, rtx);
extern rtx        gen_ashrsi3_cvt                                (rtx, rtx, rtx);
extern rtx        gen_ix86_rotldi3_doubleword                    (rtx, rtx, rtx);
extern rtx        gen_ix86_rotlti3_doubleword                    (rtx, rtx, rtx);
extern rtx        gen_ix86_rotrdi3_doubleword                    (rtx, rtx, rtx);
extern rtx        gen_ix86_rotrti3_doubleword                    (rtx, rtx, rtx);
extern rtx        gen_setcc_sf_sse                               (rtx, rtx, rtx, rtx);
extern rtx        gen_setcc_df_sse                               (rtx, rtx, rtx, rtx);
extern rtx        gen_jump                                       (rtx);
extern rtx        gen_blockage                                   (void);
extern rtx        gen_prologue_use                               (rtx);
extern rtx        gen_simple_return_internal                     (void);
extern rtx        gen_simple_return_internal_long                (void);
extern rtx        gen_simple_return_pop_internal                 (rtx);
extern rtx        gen_simple_return_indirect_internal            (rtx);
extern rtx        gen_nop                                        (void);
extern rtx        gen_nops                                       (rtx);
extern rtx        gen_pad                                        (rtx);
extern rtx        gen_set_got_rex64                              (rtx);
extern rtx        gen_set_rip_rex64                              (rtx, rtx);
extern rtx        gen_set_got_offset_rex64                       (rtx, rtx);
extern rtx        gen_eh_return_internal                         (void);
extern rtx        gen_leave                                      (void);
extern rtx        gen_leave_rex64                                (void);
extern rtx        gen_split_stack_return                         (rtx);
extern rtx        gen_ffssi2_no_cmove                            (rtx, rtx);
extern rtx        gen_bmi_bextr_si                               (rtx, rtx, rtx);
extern rtx        gen_bmi_bextr_di                               (rtx, rtx, rtx);
extern rtx        gen_bmi2_pdep_si3                              (rtx, rtx, rtx);
extern rtx        gen_bmi2_pdep_di3                              (rtx, rtx, rtx);
extern rtx        gen_bmi2_pext_si3                              (rtx, rtx, rtx);
extern rtx        gen_bmi2_pext_di3                              (rtx, rtx, rtx);
extern rtx        gen_tbm_bextri_si                              (rtx, rtx, rtx, rtx);
extern rtx        gen_tbm_bextri_di                              (rtx, rtx, rtx, rtx);
extern rtx        gen_bsr_rex64                                  (rtx, rtx);
extern rtx        gen_bsr                                        (rtx, rtx);
extern rtx        gen_bswaphi_lowpart                            (rtx);
extern rtx        gen_paritydi2_cmp                              (rtx, rtx, rtx, rtx);
extern rtx        gen_paritysi2_cmp                              (rtx, rtx, rtx);
static inline rtx gen_tls_initial_exec_64_sun                    (rtx, rtx);
static inline rtx
gen_tls_initial_exec_64_sun(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_truncxfsf2_i387_noop_unspec                (rtx, rtx);
extern rtx        gen_truncxfdf2_i387_noop_unspec                (rtx, rtx);
extern rtx        gen_sqrtxf2                                    (rtx, rtx);
extern rtx        gen_sqrt_extendsfxf2_i387                      (rtx, rtx);
extern rtx        gen_sqrt_extenddfxf2_i387                      (rtx, rtx);
extern rtx        gen_fpremxf4_i387                              (rtx, rtx, rtx, rtx);
extern rtx        gen_fprem1xf4_i387                             (rtx, rtx, rtx, rtx);
extern rtx        gen_sincosxf3                                  (rtx, rtx, rtx);
extern rtx        gen_sincos_extendsfxf3_i387                    (rtx, rtx, rtx);
extern rtx        gen_sincos_extenddfxf3_i387                    (rtx, rtx, rtx);
extern rtx        gen_fptanxf4_i387                              (rtx, rtx, rtx, rtx);
extern rtx        gen_fptan_extendsfxf4_i387                     (rtx, rtx, rtx, rtx);
extern rtx        gen_fptan_extenddfxf4_i387                     (rtx, rtx, rtx, rtx);
extern rtx        gen_fpatan_extendsfxf3_i387                    (rtx, rtx, rtx);
extern rtx        gen_fpatan_extenddfxf3_i387                    (rtx, rtx, rtx);
extern rtx        gen_fyl2xxf3_i387                              (rtx, rtx, rtx);
extern rtx        gen_fyl2x_extendsfxf3_i387                     (rtx, rtx, rtx);
extern rtx        gen_fyl2x_extenddfxf3_i387                     (rtx, rtx, rtx);
extern rtx        gen_fyl2xp1xf3_i387                            (rtx, rtx, rtx);
extern rtx        gen_fyl2xp1_extendsfxf3_i387                   (rtx, rtx, rtx);
extern rtx        gen_fyl2xp1_extenddfxf3_i387                   (rtx, rtx, rtx);
extern rtx        gen_fxtractxf3_i387                            (rtx, rtx, rtx);
extern rtx        gen_fxtract_extendsfxf3_i387                   (rtx, rtx, rtx);
extern rtx        gen_fxtract_extenddfxf3_i387                   (rtx, rtx, rtx);
extern rtx        gen_fscalexf4_i387                             (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_roundsf2                            (rtx, rtx, rtx);
extern rtx        gen_sse4_1_rounddf2                            (rtx, rtx, rtx);
extern rtx        gen_rintxf2                                    (rtx, rtx);
extern rtx        gen_fistdi2                                    (rtx, rtx);
extern rtx        gen_fistdi2_with_temp                          (rtx, rtx, rtx);
extern rtx        gen_fisthi2                                    (rtx, rtx);
extern rtx        gen_fistsi2                                    (rtx, rtx);
extern rtx        gen_fisthi2_with_temp                          (rtx, rtx, rtx);
extern rtx        gen_fistsi2_with_temp                          (rtx, rtx, rtx);
extern rtx        gen_frndintxf2_floor                           (rtx, rtx);
extern rtx        gen_frndintxf2_ceil                            (rtx, rtx);
extern rtx        gen_frndintxf2_trunc                           (rtx, rtx);
extern rtx        gen_frndintxf2_floor_i387                      (rtx, rtx, rtx, rtx);
extern rtx        gen_frndintxf2_ceil_i387                       (rtx, rtx, rtx, rtx);
extern rtx        gen_frndintxf2_trunc_i387                      (rtx, rtx, rtx, rtx);
extern rtx        gen_frndintxf2_mask_pm                         (rtx, rtx);
extern rtx        gen_frndintxf2_mask_pm_i387                    (rtx, rtx, rtx, rtx);
extern rtx        gen_fistdi2_floor                              (rtx, rtx, rtx, rtx);
extern rtx        gen_fistdi2_ceil                               (rtx, rtx, rtx, rtx);
extern rtx        gen_fistdi2_floor_with_temp                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fistdi2_ceil_with_temp                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fisthi2_floor                              (rtx, rtx, rtx, rtx);
extern rtx        gen_fisthi2_ceil                               (rtx, rtx, rtx, rtx);
extern rtx        gen_fistsi2_floor                              (rtx, rtx, rtx, rtx);
extern rtx        gen_fistsi2_ceil                               (rtx, rtx, rtx, rtx);
extern rtx        gen_fisthi2_floor_with_temp                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fisthi2_ceil_with_temp                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fistsi2_floor_with_temp                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fistsi2_ceil_with_temp                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fxamsf2_i387                               (rtx, rtx);
extern rtx        gen_fxamdf2_i387                               (rtx, rtx);
extern rtx        gen_fxamxf2_i387                               (rtx, rtx);
extern rtx        gen_fxamsf2_i387_with_temp                     (rtx, rtx);
extern rtx        gen_fxamdf2_i387_with_temp                     (rtx, rtx);
extern rtx        gen_movmsk_df                                  (rtx, rtx);
extern rtx        gen_cld                                        (void);
extern rtx        gen_smaxsf3                                    (rtx, rtx, rtx);
extern rtx        gen_sminsf3                                    (rtx, rtx, rtx);
extern rtx        gen_smaxdf3                                    (rtx, rtx, rtx);
extern rtx        gen_smindf3                                    (rtx, rtx, rtx);
extern rtx        gen_pro_epilogue_adjust_stack_si_add           (rtx, rtx, rtx);
extern rtx        gen_pro_epilogue_adjust_stack_di_add           (rtx, rtx, rtx);
extern rtx        gen_pro_epilogue_adjust_stack_si_sub           (rtx, rtx, rtx);
extern rtx        gen_pro_epilogue_adjust_stack_di_sub           (rtx, rtx, rtx);
extern rtx        gen_allocate_stack_worker_probe_si             (rtx, rtx);
extern rtx        gen_allocate_stack_worker_probe_di             (rtx, rtx);
extern rtx        gen_adjust_stack_and_probesi                   (rtx, rtx, rtx);
extern rtx        gen_adjust_stack_and_probedi                   (rtx, rtx, rtx);
extern rtx        gen_probe_stack_rangesi                        (rtx, rtx, rtx);
extern rtx        gen_probe_stack_rangedi                        (rtx, rtx, rtx);
extern rtx        gen_trap                                       (void);
extern rtx        gen_stack_protect_set_si                       (rtx, rtx);
extern rtx        gen_stack_protect_set_di                       (rtx, rtx);
extern rtx        gen_stack_tls_protect_set_si                   (rtx, rtx);
extern rtx        gen_stack_tls_protect_set_di                   (rtx, rtx);
extern rtx        gen_stack_protect_test_si                      (rtx, rtx, rtx);
extern rtx        gen_stack_protect_test_di                      (rtx, rtx, rtx);
extern rtx        gen_stack_tls_protect_test_si                  (rtx, rtx, rtx);
extern rtx        gen_stack_tls_protect_test_di                  (rtx, rtx, rtx);
extern rtx        gen_sse4_2_crc32qi                             (rtx, rtx, rtx);
extern rtx        gen_sse4_2_crc32hi                             (rtx, rtx, rtx);
extern rtx        gen_sse4_2_crc32si                             (rtx, rtx, rtx);
extern rtx        gen_sse4_2_crc32di                             (rtx, rtx, rtx);
extern rtx        gen_rdpmc                                      (rtx, rtx);
extern rtx        gen_rdpmc_rex64                                (rtx, rtx, rtx);
extern rtx        gen_rdtsc                                      (rtx);
extern rtx        gen_rdtsc_rex64                                (rtx, rtx);
extern rtx        gen_rdtscp                                     (rtx, rtx);
extern rtx        gen_rdtscp_rex64                               (rtx, rtx, rtx);
extern rtx        gen_fxsave                                     (rtx);
extern rtx        gen_fxsave64                                   (rtx);
extern rtx        gen_fxrstor                                    (rtx);
extern rtx        gen_fxrstor64                                  (rtx);
extern rtx        gen_xsave                                      (rtx, rtx);
extern rtx        gen_xsaveopt                                   (rtx, rtx);
extern rtx        gen_xsavec                                     (rtx, rtx);
extern rtx        gen_xsaves                                     (rtx, rtx);
extern rtx        gen_xsave_rex64                                (rtx, rtx, rtx);
extern rtx        gen_xsaveopt_rex64                             (rtx, rtx, rtx);
extern rtx        gen_xsavec_rex64                               (rtx, rtx, rtx);
extern rtx        gen_xsaves_rex64                               (rtx, rtx, rtx);
extern rtx        gen_xsave64                                    (rtx, rtx, rtx);
extern rtx        gen_xsaveopt64                                 (rtx, rtx, rtx);
extern rtx        gen_xsavec64                                   (rtx, rtx, rtx);
extern rtx        gen_xsaves64                                   (rtx, rtx, rtx);
extern rtx        gen_xrstor                                     (rtx, rtx);
extern rtx        gen_xrstors                                    (rtx, rtx);
extern rtx        gen_xrstor_rex64                               (rtx, rtx, rtx);
extern rtx        gen_xrstors_rex64                              (rtx, rtx, rtx);
extern rtx        gen_xrstor64                                   (rtx, rtx, rtx);
extern rtx        gen_xrstors64                                  (rtx, rtx, rtx);
extern rtx        gen_fnstenv                                    (rtx);
extern rtx        gen_fldenv                                     (rtx);
extern rtx        gen_fnstsw                                     (rtx);
extern rtx        gen_fnclex                                     (void);
extern rtx        gen_lwp_slwpcbsi                               (rtx);
extern rtx        gen_lwp_slwpcbdi                               (rtx);
extern rtx        gen_rdfsbasesi                                 (rtx);
extern rtx        gen_rdgsbasesi                                 (rtx);
extern rtx        gen_rdfsbasedi                                 (rtx);
extern rtx        gen_rdgsbasedi                                 (rtx);
extern rtx        gen_wrfsbasesi                                 (rtx);
extern rtx        gen_wrgsbasesi                                 (rtx);
extern rtx        gen_wrfsbasedi                                 (rtx);
extern rtx        gen_wrgsbasedi                                 (rtx);
extern rtx        gen_rdrandhi_1                                 (rtx);
extern rtx        gen_rdrandsi_1                                 (rtx);
extern rtx        gen_rdranddi_1                                 (rtx);
extern rtx        gen_rdseedhi_1                                 (rtx);
extern rtx        gen_rdseedsi_1                                 (rtx);
extern rtx        gen_rdseeddi_1                                 (rtx);
extern rtx        gen_xbegin_1                                   (rtx, rtx);
extern rtx        gen_xend                                       (void);
extern rtx        gen_xabort                                     (rtx);
extern rtx        gen_xtest_1                                    (void);
extern rtx        gen_pcommit                                    (void);
extern rtx        gen_clwb                                       (rtx);
extern rtx        gen_clflushopt                                 (rtx);
extern rtx        gen_mwaitx                                     (rtx, rtx, rtx);
extern rtx        gen_monitorx_si                                (rtx, rtx, rtx);
extern rtx        gen_monitorx_di                                (rtx, rtx, rtx);
extern rtx        gen_clzero_si                                  (rtx);
extern rtx        gen_clzero_di                                  (rtx);
extern rtx        gen_move_size_reloc_si                         (rtx, rtx);
extern rtx        gen_move_size_reloc_di                         (rtx, rtx);
extern rtx        gen_sse_movntq                                 (rtx, rtx);
extern rtx        gen_mmx_rcpv2sf2                               (rtx, rtx);
extern rtx        gen_mmx_rcpit1v2sf3                            (rtx, rtx, rtx);
extern rtx        gen_mmx_rcpit2v2sf3                            (rtx, rtx, rtx);
extern rtx        gen_mmx_rsqrtv2sf2                             (rtx, rtx);
extern rtx        gen_mmx_rsqit1v2sf3                            (rtx, rtx, rtx);
extern rtx        gen_mmx_haddv2sf3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_hsubv2sf3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_addsubv2sf3                            (rtx, rtx, rtx);
extern rtx        gen_mmx_gtv2sf3                                (rtx, rtx, rtx);
extern rtx        gen_mmx_gev2sf3                                (rtx, rtx, rtx);
extern rtx        gen_mmx_pf2id                                  (rtx, rtx);
extern rtx        gen_mmx_pf2iw                                  (rtx, rtx);
extern rtx        gen_mmx_pi2fw                                  (rtx, rtx);
extern rtx        gen_mmx_floatv2si2                             (rtx, rtx);
extern rtx        gen_mmx_pswapdv2sf2                            (rtx, rtx);
extern rtx        gen_mmx_ashrv4hi3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_ashrv2si3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_ashlv4hi3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_lshrv4hi3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_ashlv2si3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_lshrv2si3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_ashlv1di3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_lshrv1di3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_gtv8qi3                                (rtx, rtx, rtx);
extern rtx        gen_mmx_gtv4hi3                                (rtx, rtx, rtx);
extern rtx        gen_mmx_gtv2si3                                (rtx, rtx, rtx);
extern rtx        gen_mmx_andnotv8qi3                            (rtx, rtx, rtx);
extern rtx        gen_mmx_andnotv4hi3                            (rtx, rtx, rtx);
extern rtx        gen_mmx_andnotv2si3                            (rtx, rtx, rtx);
extern rtx        gen_mmx_packsswb                               (rtx, rtx, rtx);
extern rtx        gen_mmx_packssdw                               (rtx, rtx, rtx);
extern rtx        gen_mmx_packuswb                               (rtx, rtx, rtx);
extern rtx        gen_mmx_punpckhbw                              (rtx, rtx, rtx);
extern rtx        gen_mmx_punpcklbw                              (rtx, rtx, rtx);
extern rtx        gen_mmx_punpckhwd                              (rtx, rtx, rtx);
extern rtx        gen_mmx_punpcklwd                              (rtx, rtx, rtx);
extern rtx        gen_mmx_punpckhdq                              (rtx, rtx, rtx);
extern rtx        gen_mmx_punpckldq                              (rtx, rtx, rtx);
extern rtx        gen_mmx_pextrw                                 (rtx, rtx, rtx);
extern rtx        gen_mmx_pshufw_1                               (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mmx_pswapdv2si2                            (rtx, rtx);
extern rtx        gen_mmx_psadbw                                 (rtx, rtx, rtx);
extern rtx        gen_mmx_pmovmskb                               (rtx, rtx);
extern rtx        gen_avx512f_loadv16si_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loadv8si_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loadv4si_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_loadv8di_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loadv4di_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loadv2di_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_loadv16sf_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loadv8sf_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loadv4sf_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_loadv8df_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loadv4df_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loadv2df_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_loadv64qi_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loadv16qi_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loadv32qi_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_loadv32hi_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loadv16hi_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loadv8hi_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_blendmv16si                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_blendmv8si                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_blendmv4si                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_blendmv8di                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_blendmv4di                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_blendmv2di                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_blendmv16sf                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_blendmv8sf                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_blendmv4sf                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_blendmv8df                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_blendmv4df                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_blendmv2df                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_blendmv64qi                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_blendmv16qi                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_blendmv32qi                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_blendmv32hi                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_blendmv16hi                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_blendmv8hi                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_storev16si_mask                    (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storev8si_mask                    (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storev4si_mask                    (rtx, rtx, rtx);
extern rtx        gen_avx512f_storev8di_mask                     (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storev4di_mask                    (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storev2di_mask                    (rtx, rtx, rtx);
extern rtx        gen_avx512f_storev16sf_mask                    (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storev8sf_mask                    (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storev4sf_mask                    (rtx, rtx, rtx);
extern rtx        gen_avx512f_storev8df_mask                     (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storev4df_mask                    (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storev2df_mask                    (rtx, rtx, rtx);
extern rtx        gen_avx512bw_storev64qi_mask                   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storev16qi_mask                   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storev32qi_mask                   (rtx, rtx, rtx);
extern rtx        gen_avx512bw_storev32hi_mask                   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storev16hi_mask                   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storev8hi_mask                    (rtx, rtx, rtx);
extern rtx        gen_sse2_movq128                               (rtx, rtx);
extern rtx        gen_movdi_to_sse                               (rtx, rtx);
extern rtx        gen_avx512f_storeups512                        (rtx, rtx);
extern rtx        gen_avx_storeups256                            (rtx, rtx);
extern rtx        gen_sse_storeups                               (rtx, rtx);
extern rtx        gen_avx512f_storeupd512                        (rtx, rtx);
extern rtx        gen_avx_storeupd256                            (rtx, rtx);
extern rtx        gen_sse2_storeupd                              (rtx, rtx);
extern rtx        gen_avx512f_storeups512_mask                   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storeups256_mask                  (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storeups_mask                     (rtx, rtx, rtx);
extern rtx        gen_avx512f_storeupd512_mask                   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storeupd256_mask                  (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storeupd_mask                     (rtx, rtx, rtx);
extern rtx        gen_avx_storedquv32qi                          (rtx, rtx);
extern rtx        gen_sse2_storedquv16qi                         (rtx, rtx);
extern rtx        gen_avx512f_storedquv64qi                      (rtx, rtx);
extern rtx        gen_avx512bw_storedquv32hi                     (rtx, rtx);
extern rtx        gen_avx512vl_storedquv8hi                      (rtx, rtx);
extern rtx        gen_avx512vl_storedquv16hi                     (rtx, rtx);
extern rtx        gen_avx512f_storedquv16si                      (rtx, rtx);
extern rtx        gen_avx_storedquv8si                           (rtx, rtx);
extern rtx        gen_sse2_storedquv4si                          (rtx, rtx);
extern rtx        gen_avx512f_storedquv8di                       (rtx, rtx);
extern rtx        gen_avx512vl_storedquv4di                      (rtx, rtx);
extern rtx        gen_avx512vl_storedquv2di                      (rtx, rtx);
extern rtx        gen_avx512f_storedquv16si_mask                 (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storedquv8si_mask                 (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storedquv4si_mask                 (rtx, rtx, rtx);
extern rtx        gen_avx512f_storedquv8di_mask                  (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storedquv4di_mask                 (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storedquv2di_mask                 (rtx, rtx, rtx);
extern rtx        gen_avx512bw_storedquv64qi_mask                (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storedquv16qi_mask                (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storedquv32qi_mask                (rtx, rtx, rtx);
extern rtx        gen_avx512bw_storedquv32hi_mask                (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storedquv16hi_mask                (rtx, rtx, rtx);
extern rtx        gen_avx512vl_storedquv8hi_mask                 (rtx, rtx, rtx);
extern rtx        gen_avx_lddqu256                               (rtx, rtx);
extern rtx        gen_sse3_lddqu                                 (rtx, rtx);
extern rtx        gen_sse2_movntisi                              (rtx, rtx);
extern rtx        gen_sse2_movntidi                              (rtx, rtx);
extern rtx        gen_avx512f_movntv16sf                         (rtx, rtx);
extern rtx        gen_avx_movntv8sf                              (rtx, rtx);
extern rtx        gen_sse_movntv4sf                              (rtx, rtx);
extern rtx        gen_avx512f_movntv8df                          (rtx, rtx);
extern rtx        gen_avx_movntv4df                              (rtx, rtx);
extern rtx        gen_sse2_movntv2df                             (rtx, rtx);
extern rtx        gen_avx512f_movntv8di                          (rtx, rtx);
extern rtx        gen_avx_movntv4di                              (rtx, rtx);
extern rtx        gen_sse2_movntv2di                             (rtx, rtx);
extern rtx        gen_sse_vmaddv4sf3                             (rtx, rtx, rtx);
extern rtx        gen_sse_vmaddv4sf3_round                       (rtx, rtx, rtx, rtx);
extern rtx        gen_sse_vmsubv4sf3                             (rtx, rtx, rtx);
extern rtx        gen_sse_vmsubv4sf3_round                       (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_vmaddv2df3                            (rtx, rtx, rtx);
extern rtx        gen_sse2_vmaddv2df3_round                      (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_vmsubv2df3                            (rtx, rtx, rtx);
extern rtx        gen_sse2_vmsubv2df3_round                      (rtx, rtx, rtx, rtx);
extern rtx        gen_sse_vmmulv4sf3                             (rtx, rtx, rtx);
extern rtx        gen_sse_vmmulv4sf3_round                       (rtx, rtx, rtx, rtx);
extern rtx        gen_sse_vmdivv4sf3                             (rtx, rtx, rtx);
extern rtx        gen_sse_vmdivv4sf3_round                       (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_vmmulv2df3                            (rtx, rtx, rtx);
extern rtx        gen_sse2_vmmulv2df3_round                      (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_vmdivv2df3                            (rtx, rtx, rtx);
extern rtx        gen_sse2_vmdivv2df3_round                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_divv16sf3                          (rtx, rtx, rtx);
extern rtx        gen_avx512f_divv16sf3_round                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_divv16sf3_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_divv16sf3_mask_round               (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_divv8sf3                               (rtx, rtx, rtx);
static inline rtx gen_avx_divv8sf3_round                         (rtx, rtx, rtx, rtx);
static inline rtx
gen_avx_divv8sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_avx_divv8sf3_mask                          (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx_divv8sf3_mask_round                    (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx_divv8sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_sse_divv4sf3                               (rtx, rtx, rtx);
static inline rtx gen_sse_divv4sf3_round                         (rtx, rtx, rtx, rtx);
static inline rtx
gen_sse_divv4sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_sse_divv4sf3_mask                          (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_sse_divv4sf3_mask_round                    (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_sse_divv4sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512f_divv8df3                           (rtx, rtx, rtx);
extern rtx        gen_avx512f_divv8df3_round                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_divv8df3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_divv8df3_mask_round                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_divv4df3                               (rtx, rtx, rtx);
static inline rtx gen_avx_divv4df3_round                         (rtx, rtx, rtx, rtx);
static inline rtx
gen_avx_divv4df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_avx_divv4df3_mask                          (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx_divv4df3_mask_round                    (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx_divv4df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_sse2_divv2df3                              (rtx, rtx, rtx);
static inline rtx gen_sse2_divv2df3_round                        (rtx, rtx, rtx, rtx);
static inline rtx
gen_sse2_divv2df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_sse2_divv2df3_mask                         (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_sse2_divv2df3_mask_round                   (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_sse2_divv2df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx_rcpv8sf2                               (rtx, rtx);
extern rtx        gen_sse_rcpv4sf2                               (rtx, rtx);
extern rtx        gen_sse_vmrcpv4sf2                             (rtx, rtx, rtx);
extern rtx        gen_rcp14v16sf_mask                            (rtx, rtx, rtx, rtx);
extern rtx        gen_rcp14v8sf_mask                             (rtx, rtx, rtx, rtx);
extern rtx        gen_rcp14v4sf_mask                             (rtx, rtx, rtx, rtx);
extern rtx        gen_rcp14v8df_mask                             (rtx, rtx, rtx, rtx);
extern rtx        gen_rcp14v4df_mask                             (rtx, rtx, rtx, rtx);
extern rtx        gen_rcp14v2df_mask                             (rtx, rtx, rtx, rtx);
extern rtx        gen_srcp14v4sf                                 (rtx, rtx, rtx);
extern rtx        gen_srcp14v2df                                 (rtx, rtx, rtx);
extern rtx        gen_avx512f_sqrtv16sf2                         (rtx, rtx);
extern rtx        gen_avx512f_sqrtv16sf2_round                   (rtx, rtx, rtx);
extern rtx        gen_avx512f_sqrtv16sf2_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sqrtv16sf2_mask_round              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_sqrtv8sf2                              (rtx, rtx);
static inline rtx gen_avx_sqrtv8sf2_round                        (rtx, rtx, rtx);
static inline rtx
gen_avx_sqrtv8sf2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_avx_sqrtv8sf2_mask                         (rtx, rtx, rtx, rtx);
static inline rtx gen_avx_sqrtv8sf2_mask_round                   (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx_sqrtv8sf2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_sse_sqrtv4sf2                              (rtx, rtx);
static inline rtx gen_sse_sqrtv4sf2_round                        (rtx, rtx, rtx);
static inline rtx
gen_sse_sqrtv4sf2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_sse_sqrtv4sf2_mask                         (rtx, rtx, rtx, rtx);
static inline rtx gen_sse_sqrtv4sf2_mask_round                   (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_sse_sqrtv4sf2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_avx512f_sqrtv8df2                          (rtx, rtx);
extern rtx        gen_avx512f_sqrtv8df2_round                    (rtx, rtx, rtx);
extern rtx        gen_avx512f_sqrtv8df2_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sqrtv8df2_mask_round               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_sqrtv4df2                              (rtx, rtx);
static inline rtx gen_avx_sqrtv4df2_round                        (rtx, rtx, rtx);
static inline rtx
gen_avx_sqrtv4df2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_avx_sqrtv4df2_mask                         (rtx, rtx, rtx, rtx);
static inline rtx gen_avx_sqrtv4df2_mask_round                   (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx_sqrtv4df2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_sse2_sqrtv2df2                             (rtx, rtx);
static inline rtx gen_sse2_sqrtv2df2_round                       (rtx, rtx, rtx);
static inline rtx
gen_sse2_sqrtv2df2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_sse2_sqrtv2df2_mask                        (rtx, rtx, rtx, rtx);
static inline rtx gen_sse2_sqrtv2df2_mask_round                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_sse2_sqrtv2df2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_sse_vmsqrtv4sf2                            (rtx, rtx, rtx);
extern rtx        gen_sse_vmsqrtv4sf2_round                      (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_vmsqrtv2df2                           (rtx, rtx, rtx);
extern rtx        gen_sse2_vmsqrtv2df2_round                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_rsqrtv8sf2                             (rtx, rtx);
extern rtx        gen_sse_rsqrtv4sf2                             (rtx, rtx);
extern rtx        gen_rsqrt14v16sf_mask                          (rtx, rtx, rtx, rtx);
extern rtx        gen_rsqrt14v8sf_mask                           (rtx, rtx, rtx, rtx);
extern rtx        gen_rsqrt14v4sf_mask                           (rtx, rtx, rtx, rtx);
extern rtx        gen_rsqrt14v8df_mask                           (rtx, rtx, rtx, rtx);
extern rtx        gen_rsqrt14v4df_mask                           (rtx, rtx, rtx, rtx);
extern rtx        gen_rsqrt14v2df_mask                           (rtx, rtx, rtx, rtx);
extern rtx        gen_rsqrt14v4sf                                (rtx, rtx, rtx);
extern rtx        gen_rsqrt14v2df                                (rtx, rtx, rtx);
extern rtx        gen_sse_vmrsqrtv4sf2                           (rtx, rtx, rtx);
extern rtx        gen_sse_vmsmaxv4sf3                            (rtx, rtx, rtx);
extern rtx        gen_sse_vmsmaxv4sf3_round                      (rtx, rtx, rtx, rtx);
extern rtx        gen_sse_vmsminv4sf3                            (rtx, rtx, rtx);
extern rtx        gen_sse_vmsminv4sf3_round                      (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_vmsmaxv2df3                           (rtx, rtx, rtx);
extern rtx        gen_sse2_vmsmaxv2df3_round                     (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_vmsminv2df3                           (rtx, rtx, rtx);
extern rtx        gen_sse2_vmsminv2df3_round                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_addsubv4df3                            (rtx, rtx, rtx);
extern rtx        gen_sse3_addsubv2df3                           (rtx, rtx, rtx);
extern rtx        gen_avx_addsubv8sf3                            (rtx, rtx, rtx);
extern rtx        gen_sse3_addsubv4sf3                           (rtx, rtx, rtx);
extern rtx        gen_avx_haddv4df3                              (rtx, rtx, rtx);
extern rtx        gen_avx_hsubv4df3                              (rtx, rtx, rtx);
extern rtx        gen_sse3_hsubv2df3                             (rtx, rtx, rtx);
extern rtx        gen_avx_haddv8sf3                              (rtx, rtx, rtx);
extern rtx        gen_avx_hsubv8sf3                              (rtx, rtx, rtx);
extern rtx        gen_sse3_haddv4sf3                             (rtx, rtx, rtx);
extern rtx        gen_sse3_hsubv4sf3                             (rtx, rtx, rtx);
extern rtx        gen_reducepv16sf_mask                          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_reducepv8sf_mask                           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_reducepv4sf_mask                           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_reducepv8df_mask                           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_reducepv4df_mask                           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_reducepv2df_mask                           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_reducesv4sf                                (rtx, rtx, rtx, rtx);
extern rtx        gen_reducesv2df                                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_cmpv8sf3                               (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_cmpv4sf3                               (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_cmpv4df3                               (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_cmpv2df3                               (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vmcmpv4sf3                             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vmcmpv2df3                             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_maskcmpv8sf3                           (rtx, rtx, rtx, rtx);
extern rtx        gen_sse_maskcmpv4sf3                           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_maskcmpv4df3                           (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_maskcmpv2df3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_sse_vmmaskcmpv4sf3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_vmmaskcmpv2df3                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cmpv16si3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cmpv16si3_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cmpv16si3_round                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cmpv16si3_mask_round               (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv8si3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv8si3_mask                     (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_cmpv8si3_round                    (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv8si3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
static inline rtx gen_avx512vl_cmpv8si3_mask_round               (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv8si3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_cmpv4si3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv4si3_mask                     (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_cmpv4si3_round                    (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv4si3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
static inline rtx gen_avx512vl_cmpv4si3_mask_round               (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv4si3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512f_cmpv8di3                           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cmpv8di3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cmpv8di3_round                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cmpv8di3_mask_round                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv4di3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv4di3_mask                     (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_cmpv4di3_round                    (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv4di3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
static inline rtx gen_avx512vl_cmpv4di3_mask_round               (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv4di3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_cmpv2di3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv2di3_mask                     (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_cmpv2di3_round                    (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv2di3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
static inline rtx gen_avx512vl_cmpv2di3_mask_round               (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv2di3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512f_cmpv16sf3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cmpv16sf3_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cmpv16sf3_round                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cmpv16sf3_mask_round               (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv8sf3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv8sf3_mask                     (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_cmpv8sf3_round                    (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv8sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
static inline rtx gen_avx512vl_cmpv8sf3_mask_round               (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv8sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_cmpv4sf3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv4sf3_mask                     (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_cmpv4sf3_round                    (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv4sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
static inline rtx gen_avx512vl_cmpv4sf3_mask_round               (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv4sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512f_cmpv8df3                           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cmpv8df3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cmpv8df3_round                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cmpv8df3_mask_round                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv4df3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv4df3_mask                     (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_cmpv4df3_round                    (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv4df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
static inline rtx gen_avx512vl_cmpv4df3_mask_round               (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv4df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_cmpv2df3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv2df3_mask                     (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_cmpv2df3_round                    (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv2df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
static inline rtx gen_avx512vl_cmpv2df3_mask_round               (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_cmpv2df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512bw_cmpv64qi3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_cmpv64qi3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv16qi3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv16qi3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv32qi3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv32qi3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_cmpv32hi3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_cmpv32hi3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv16hi3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv16hi3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv8hi3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_cmpv8hi3_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_ucmpv64qi3                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_ucmpv64qi3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv16qi3                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv16qi3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv32qi3                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv32qi3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_ucmpv32hi3                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_ucmpv32hi3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv16hi3                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv16hi3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv8hi3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv8hi3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ucmpv16si3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ucmpv16si3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv8si3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv8si3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv4si3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv4si3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ucmpv8di3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ucmpv8di3_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv4di3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv4di3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv2di3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ucmpv2di3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vmcmpv4sf3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vmcmpv4sf3_round                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vmcmpv2df3                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vmcmpv2df3_round                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vmcmpv4sf3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vmcmpv4sf3_mask_round              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vmcmpv2df3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vmcmpv2df3_mask_round              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_maskcmpv16sf3                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_maskcmpv8sf3                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_maskcmpv4sf3                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_maskcmpv8df3                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_maskcmpv4df3                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_maskcmpv2df3                       (rtx, rtx, rtx, rtx);
extern rtx        gen_sse_comi                                   (rtx, rtx);
extern rtx        gen_sse_comi_round                             (rtx, rtx, rtx);
extern rtx        gen_sse2_comi                                  (rtx, rtx);
extern rtx        gen_sse2_comi_round                            (rtx, rtx, rtx);
extern rtx        gen_sse_ucomi                                  (rtx, rtx);
extern rtx        gen_sse_ucomi_round                            (rtx, rtx, rtx);
extern rtx        gen_sse2_ucomi                                 (rtx, rtx);
extern rtx        gen_sse2_ucomi_round                           (rtx, rtx, rtx);
extern rtx        gen_avx_andnotv8sf3                            (rtx, rtx, rtx);
extern rtx        gen_avx_andnotv8sf3_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse_andnotv4sf3                            (rtx, rtx, rtx);
extern rtx        gen_sse_andnotv4sf3_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_andnotv4df3                            (rtx, rtx, rtx);
extern rtx        gen_avx_andnotv4df3_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_andnotv2df3                           (rtx, rtx, rtx);
extern rtx        gen_sse2_andnotv2df3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_andnotv16sf3                       (rtx, rtx, rtx);
extern rtx        gen_avx512f_andnotv16sf3_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_andnotv8df3                        (rtx, rtx, rtx);
extern rtx        gen_avx512f_andnotv8df3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmadd_v16sf_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmadd_v16sf_maskz_1_round              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmadd_v8sf_maskz_1                     (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmadd_v8sf_maskz_1_round               (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmadd_v8sf_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fmadd_v4sf_maskz_1                     (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmadd_v4sf_maskz_1_round               (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmadd_v4sf_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fmadd_v8df_maskz_1                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmadd_v8df_maskz_1_round               (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmadd_v4df_maskz_1                     (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmadd_v4df_maskz_1_round               (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmadd_v4df_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fmadd_v2df_maskz_1                     (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmadd_v2df_maskz_1_round               (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmadd_v2df_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_avx512f_fmadd_v16sf_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmadd_v16sf_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v8sf_mask                   (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fmadd_v8sf_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fmadd_v8sf_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_fmadd_v4sf_mask                   (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fmadd_v4sf_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fmadd_v4sf_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512f_fmadd_v8df_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmadd_v8df_mask_round              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v4df_mask                   (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fmadd_v4df_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fmadd_v4df_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_fmadd_v2df_mask                   (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fmadd_v2df_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fmadd_v2df_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512f_fmadd_v16sf_mask3                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmadd_v16sf_mask3_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v8sf_mask3                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v8sf_mask3_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v4sf_mask3                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v4sf_mask3_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmadd_v8df_mask3                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmadd_v8df_mask3_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v4df_mask3                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v4df_mask3_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v2df_mask3                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v2df_mask3_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmsub_v16sf_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmsub_v16sf_maskz_1_round              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmsub_v8sf_maskz_1                     (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmsub_v8sf_maskz_1_round               (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmsub_v8sf_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fmsub_v4sf_maskz_1                     (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmsub_v4sf_maskz_1_round               (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmsub_v4sf_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fmsub_v8df_maskz_1                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmsub_v8df_maskz_1_round               (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmsub_v4df_maskz_1                     (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmsub_v4df_maskz_1_round               (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmsub_v4df_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fmsub_v2df_maskz_1                     (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmsub_v2df_maskz_1_round               (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmsub_v2df_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_avx512f_fmsub_v16sf_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmsub_v16sf_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsub_v8sf_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsub_v8sf_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsub_v4sf_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsub_v4sf_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmsub_v8df_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmsub_v8df_mask_round              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsub_v4df_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsub_v4df_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsub_v2df_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsub_v2df_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmsub_v16sf_mask3                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmsub_v16sf_mask3_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsub_v8sf_mask3                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fmsub_v8sf_mask3_round            (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fmsub_v8sf_mask3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_fmsub_v4sf_mask3                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fmsub_v4sf_mask3_round            (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fmsub_v4sf_mask3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512f_fmsub_v8df_mask3                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmsub_v8df_mask3_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsub_v4df_mask3                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fmsub_v4df_mask3_round            (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fmsub_v4df_mask3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_fmsub_v2df_mask3                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fmsub_v2df_mask3_round            (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fmsub_v2df_mask3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_fma_fnmadd_v16sf_maskz_1                   (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fnmadd_v16sf_maskz_1_round             (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fnmadd_v8sf_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fnmadd_v8sf_maskz_1_round              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fnmadd_v8sf_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fnmadd_v4sf_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fnmadd_v4sf_maskz_1_round              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fnmadd_v4sf_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fnmadd_v8df_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fnmadd_v8df_maskz_1_round              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fnmadd_v4df_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fnmadd_v4df_maskz_1_round              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fnmadd_v4df_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fnmadd_v2df_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fnmadd_v2df_maskz_1_round              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fnmadd_v2df_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_avx512f_fnmadd_v16sf_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fnmadd_v16sf_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmadd_v8sf_mask                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fnmadd_v8sf_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fnmadd_v8sf_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_fnmadd_v4sf_mask                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fnmadd_v4sf_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fnmadd_v4sf_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512f_fnmadd_v8df_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fnmadd_v8df_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmadd_v4df_mask                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fnmadd_v4df_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fnmadd_v4df_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_fnmadd_v2df_mask                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fnmadd_v2df_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fnmadd_v2df_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512f_fnmadd_v16sf_mask3                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fnmadd_v16sf_mask3_round           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmadd_v8sf_mask3                 (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fnmadd_v8sf_mask3_round           (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fnmadd_v8sf_mask3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_fnmadd_v4sf_mask3                 (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fnmadd_v4sf_mask3_round           (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fnmadd_v4sf_mask3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512f_fnmadd_v8df_mask3                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fnmadd_v8df_mask3_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmadd_v4df_mask3                 (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fnmadd_v4df_mask3_round           (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fnmadd_v4df_mask3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_fnmadd_v2df_mask3                 (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fnmadd_v2df_mask3_round           (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fnmadd_v2df_mask3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_fma_fnmsub_v16sf_maskz_1                   (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fnmsub_v16sf_maskz_1_round             (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fnmsub_v8sf_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fnmsub_v8sf_maskz_1_round              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fnmsub_v8sf_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fnmsub_v4sf_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fnmsub_v4sf_maskz_1_round              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fnmsub_v4sf_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fnmsub_v8df_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fnmsub_v8df_maskz_1_round              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fnmsub_v4df_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fnmsub_v4df_maskz_1_round              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fnmsub_v4df_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fnmsub_v2df_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fnmsub_v2df_maskz_1_round              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fnmsub_v2df_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_avx512f_fnmsub_v16sf_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fnmsub_v16sf_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmsub_v8sf_mask                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fnmsub_v8sf_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fnmsub_v8sf_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_fnmsub_v4sf_mask                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fnmsub_v4sf_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fnmsub_v4sf_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512f_fnmsub_v8df_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fnmsub_v8df_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmsub_v4df_mask                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fnmsub_v4df_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fnmsub_v4df_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512vl_fnmsub_v2df_mask                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512vl_fnmsub_v2df_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512vl_fnmsub_v2df_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_avx512f_fnmsub_v16sf_mask3                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fnmsub_v16sf_mask3_round           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmsub_v8sf_mask3                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmsub_v8sf_mask3_round           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmsub_v4sf_mask3                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmsub_v4sf_mask3_round           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fnmsub_v8df_mask3                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fnmsub_v8df_mask3_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmsub_v4df_mask3                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmsub_v4df_mask3_round           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmsub_v2df_mask3                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fnmsub_v2df_mask3_round           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmaddsub_v16sf_maskz_1                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmaddsub_v16sf_maskz_1_round           (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmaddsub_v8sf_maskz_1                  (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmaddsub_v8sf_maskz_1_round            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmaddsub_v8sf_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fmaddsub_v4sf_maskz_1                  (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmaddsub_v4sf_maskz_1_round            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmaddsub_v4sf_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fmaddsub_v8df_maskz_1                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmaddsub_v8df_maskz_1_round            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmaddsub_v4df_maskz_1                  (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmaddsub_v4df_maskz_1_round            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmaddsub_v4df_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fmaddsub_v2df_maskz_1                  (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmaddsub_v2df_maskz_1_round            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmaddsub_v2df_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_avx512f_fmaddsub_v16sf_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmaddsub_v16sf_mask_round          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v8sf_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v8sf_mask_round          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v4sf_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v4sf_mask_round          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmaddsub_v8df_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmaddsub_v8df_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v4df_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v4df_mask_round          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v2df_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v2df_mask_round          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmaddsub_v16sf_mask3               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmaddsub_v16sf_mask3_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v8sf_mask3               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v8sf_mask3_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v4sf_mask3               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v4sf_mask3_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmaddsub_v8df_mask3                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmaddsub_v8df_mask3_round          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v4df_mask3               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v4df_mask3_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v2df_mask3               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v2df_mask3_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmsubadd_v16sf_maskz_1                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmsubadd_v16sf_maskz_1_round           (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmsubadd_v8sf_maskz_1                  (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmsubadd_v8sf_maskz_1_round            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmsubadd_v8sf_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fmsubadd_v4sf_maskz_1                  (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmsubadd_v4sf_maskz_1_round            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmsubadd_v4sf_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fmsubadd_v8df_maskz_1                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmsubadd_v8df_maskz_1_round            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma_fmsubadd_v4df_maskz_1                  (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmsubadd_v4df_maskz_1_round            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmsubadd_v4df_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_fma_fmsubadd_v2df_maskz_1                  (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_fma_fmsubadd_v2df_maskz_1_round            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fma_fmsubadd_v2df_maskz_1_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_avx512f_fmsubadd_v16sf_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmsubadd_v16sf_mask_round          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v8sf_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v8sf_mask_round          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v4sf_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v4sf_mask_round          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmsubadd_v8df_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmsubadd_v8df_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v4df_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v4df_mask_round          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v2df_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v2df_mask_round          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmsubadd_v16sf_mask3               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmsubadd_v16sf_mask3_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v8sf_mask3               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v8sf_mask3_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v4sf_mask3               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v4sf_mask3_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmsubadd_v8df_mask3                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmsubadd_v8df_mask3_round          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v4df_mask3               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v4df_mask3_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v2df_mask3               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmsubadd_v2df_mask3_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse_cvtpi2ps                               (rtx, rtx, rtx);
extern rtx        gen_sse_cvtps2pi                               (rtx, rtx);
extern rtx        gen_sse_cvttps2pi                              (rtx, rtx);
extern rtx        gen_sse_cvtsi2ss                               (rtx, rtx, rtx);
extern rtx        gen_sse_cvtsi2ss_round                         (rtx, rtx, rtx, rtx);
extern rtx        gen_sse_cvtsi2ssq                              (rtx, rtx, rtx);
extern rtx        gen_sse_cvtsi2ssq_round                        (rtx, rtx, rtx, rtx);
extern rtx        gen_sse_cvtss2si                               (rtx, rtx);
extern rtx        gen_sse_cvtss2si_round                         (rtx, rtx, rtx);
extern rtx        gen_sse_cvtss2si_2                             (rtx, rtx);
extern rtx        gen_sse_cvtss2siq                              (rtx, rtx);
extern rtx        gen_sse_cvtss2siq_round                        (rtx, rtx, rtx);
extern rtx        gen_sse_cvtss2siq_2                            (rtx, rtx);
extern rtx        gen_sse_cvttss2si                              (rtx, rtx);
extern rtx        gen_sse_cvttss2si_round                        (rtx, rtx, rtx);
extern rtx        gen_sse_cvttss2siq                             (rtx, rtx);
extern rtx        gen_sse_cvttss2siq_round                       (rtx, rtx, rtx);
extern rtx        gen_cvtusi2ss32                                (rtx, rtx, rtx);
extern rtx        gen_cvtusi2ss32_round                          (rtx, rtx, rtx, rtx);
extern rtx        gen_cvtusi2sd32                                (rtx, rtx, rtx);
static inline rtx gen_cvtusi2sd32_round                          (rtx, rtx, rtx, rtx);
static inline rtx
gen_cvtusi2sd32_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_cvtusi2ss64                                (rtx, rtx, rtx);
extern rtx        gen_cvtusi2ss64_round                          (rtx, rtx, rtx, rtx);
extern rtx        gen_cvtusi2sd64                                (rtx, rtx, rtx);
extern rtx        gen_cvtusi2sd64_round                          (rtx, rtx, rtx, rtx);
extern rtx        gen_floatv16siv16sf2                           (rtx, rtx);
extern rtx        gen_floatv16siv16sf2_round                     (rtx, rtx, rtx);
extern rtx        gen_floatv16siv16sf2_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_floatv16siv16sf2_mask_round                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_floatv8siv8sf2                             (rtx, rtx);
static inline rtx gen_floatv8siv8sf2_round                       (rtx, rtx, rtx);
static inline rtx
gen_floatv8siv8sf2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_floatv8siv8sf2_mask                        (rtx, rtx, rtx, rtx);
static inline rtx gen_floatv8siv8sf2_mask_round                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_floatv8siv8sf2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_floatv4siv4sf2                             (rtx, rtx);
static inline rtx gen_floatv4siv4sf2_round                       (rtx, rtx, rtx);
static inline rtx
gen_floatv4siv4sf2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_floatv4siv4sf2_mask                        (rtx, rtx, rtx, rtx);
static inline rtx gen_floatv4siv4sf2_mask_round                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_floatv4siv4sf2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_ufloatv16siv16sf2                          (rtx, rtx);
extern rtx        gen_ufloatv16siv16sf2_round                    (rtx, rtx, rtx);
extern rtx        gen_ufloatv16siv16sf2_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv16siv16sf2_mask_round               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv8siv8sf2                            (rtx, rtx);
extern rtx        gen_ufloatv8siv8sf2_round                      (rtx, rtx, rtx);
extern rtx        gen_ufloatv8siv8sf2_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv8siv8sf2_mask_round                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv4siv4sf2                            (rtx, rtx);
extern rtx        gen_ufloatv4siv4sf2_round                      (rtx, rtx, rtx);
extern rtx        gen_ufloatv4siv4sf2_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv4siv4sf2_mask_round                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_fix_notruncv8sfv8si                    (rtx, rtx);
extern rtx        gen_avx_fix_notruncv8sfv8si_mask               (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_fix_notruncv4sfv4si                   (rtx, rtx);
extern rtx        gen_sse2_fix_notruncv4sfv4si_mask              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fix_notruncv16sfv16si              (rtx, rtx);
extern rtx        gen_avx512f_fix_notruncv16sfv16si_round        (rtx, rtx, rtx);
extern rtx        gen_avx512f_fix_notruncv16sfv16si_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fix_notruncv16sfv16si_mask_round   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ufix_notruncv16sfv16si_mask        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ufix_notruncv16sfv16si_mask_round  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ufix_notruncv8sfv8si_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ufix_notruncv8sfv8si_mask_round   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ufix_notruncv4sfv4si_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ufix_notruncv4sfv4si_mask_round   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_cvtps2qqv8di_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_cvtps2qqv8di_mask_round           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_cvtps2qqv4di_mask                 (rtx, rtx, rtx, rtx);
static inline rtx gen_avx512dq_cvtps2qqv4di_mask_round           (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512dq_cvtps2qqv4di_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_avx512dq_cvtps2qqv2di_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_cvtps2uqqv8di_mask                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_cvtps2uqqv8di_mask_round          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_cvtps2uqqv4di_mask                (rtx, rtx, rtx, rtx);
static inline rtx gen_avx512dq_cvtps2uqqv4di_mask_round          (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512dq_cvtps2uqqv4di_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_avx512dq_cvtps2uqqv2di_mask                (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncv16sfv16si2                       (rtx, rtx);
extern rtx        gen_fix_truncv16sfv16si2_round                 (rtx, rtx, rtx);
extern rtx        gen_fix_truncv16sfv16si2_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncv16sfv16si2_mask_round            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_truncv16sfv16si2                      (rtx, rtx);
extern rtx        gen_ufix_truncv16sfv16si2_round                (rtx, rtx, rtx);
extern rtx        gen_ufix_truncv16sfv16si2_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_truncv16sfv16si2_mask_round           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncv8sfv8si2                         (rtx, rtx);
extern rtx        gen_fix_truncv8sfv8si2_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncv4sfv4si2                         (rtx, rtx);
extern rtx        gen_fix_truncv4sfv4si2_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_cvtpi2pd                              (rtx, rtx);
extern rtx        gen_sse2_cvtpd2pi                              (rtx, rtx);
extern rtx        gen_sse2_cvttpd2pi                             (rtx, rtx);
extern rtx        gen_sse2_cvtsi2sd                              (rtx, rtx, rtx);
extern rtx        gen_sse2_cvtsi2sdq                             (rtx, rtx, rtx);
extern rtx        gen_sse2_cvtsi2sdq_round                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vcvtss2usi                         (rtx, rtx);
extern rtx        gen_avx512f_vcvtss2usi_round                   (rtx, rtx, rtx);
extern rtx        gen_avx512f_vcvtss2usiq                        (rtx, rtx);
extern rtx        gen_avx512f_vcvtss2usiq_round                  (rtx, rtx, rtx);
extern rtx        gen_avx512f_vcvttss2usi                        (rtx, rtx);
extern rtx        gen_avx512f_vcvttss2usi_round                  (rtx, rtx, rtx);
extern rtx        gen_avx512f_vcvttss2usiq                       (rtx, rtx);
extern rtx        gen_avx512f_vcvttss2usiq_round                 (rtx, rtx, rtx);
extern rtx        gen_avx512f_vcvtsd2usi                         (rtx, rtx);
extern rtx        gen_avx512f_vcvtsd2usi_round                   (rtx, rtx, rtx);
extern rtx        gen_avx512f_vcvtsd2usiq                        (rtx, rtx);
extern rtx        gen_avx512f_vcvtsd2usiq_round                  (rtx, rtx, rtx);
extern rtx        gen_avx512f_vcvttsd2usi                        (rtx, rtx);
extern rtx        gen_avx512f_vcvttsd2usi_round                  (rtx, rtx, rtx);
extern rtx        gen_avx512f_vcvttsd2usiq                       (rtx, rtx);
extern rtx        gen_avx512f_vcvttsd2usiq_round                 (rtx, rtx, rtx);
extern rtx        gen_sse2_cvtsd2si                              (rtx, rtx);
extern rtx        gen_sse2_cvtsd2si_round                        (rtx, rtx, rtx);
extern rtx        gen_sse2_cvtsd2si_2                            (rtx, rtx);
extern rtx        gen_sse2_cvtsd2siq                             (rtx, rtx);
extern rtx        gen_sse2_cvtsd2siq_round                       (rtx, rtx, rtx);
extern rtx        gen_sse2_cvtsd2siq_2                           (rtx, rtx);
extern rtx        gen_sse2_cvttsd2si                             (rtx, rtx);
extern rtx        gen_sse2_cvttsd2si_round                       (rtx, rtx, rtx);
extern rtx        gen_sse2_cvttsd2siq                            (rtx, rtx);
extern rtx        gen_sse2_cvttsd2siq_round                      (rtx, rtx, rtx);
extern rtx        gen_floatv8siv8df2                             (rtx, rtx);
extern rtx        gen_floatv8siv8df2_mask                        (rtx, rtx, rtx, rtx);
extern rtx        gen_floatv4siv4df2                             (rtx, rtx);
extern rtx        gen_floatv4siv4df2_mask                        (rtx, rtx, rtx, rtx);
extern rtx        gen_floatv8div8df2                             (rtx, rtx);
extern rtx        gen_floatv8div8df2_round                       (rtx, rtx, rtx);
extern rtx        gen_floatv8div8df2_mask                        (rtx, rtx, rtx, rtx);
extern rtx        gen_floatv8div8df2_mask_round                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv8div8df2                            (rtx, rtx);
extern rtx        gen_ufloatv8div8df2_round                      (rtx, rtx, rtx);
extern rtx        gen_ufloatv8div8df2_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv8div8df2_mask_round                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_floatv4div4df2                             (rtx, rtx);
extern rtx        gen_floatv4div4df2_round                       (rtx, rtx, rtx);
extern rtx        gen_floatv4div4df2_mask                        (rtx, rtx, rtx, rtx);
extern rtx        gen_floatv4div4df2_mask_round                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv4div4df2                            (rtx, rtx);
extern rtx        gen_ufloatv4div4df2_round                      (rtx, rtx, rtx);
extern rtx        gen_ufloatv4div4df2_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv4div4df2_mask_round                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_floatv2div2df2                             (rtx, rtx);
extern rtx        gen_floatv2div2df2_round                       (rtx, rtx, rtx);
extern rtx        gen_floatv2div2df2_mask                        (rtx, rtx, rtx, rtx);
extern rtx        gen_floatv2div2df2_mask_round                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv2div2df2                            (rtx, rtx);
extern rtx        gen_ufloatv2div2df2_round                      (rtx, rtx, rtx);
extern rtx        gen_ufloatv2div2df2_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv2div2df2_mask_round                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_floatv8div8sf2                             (rtx, rtx);
extern rtx        gen_floatv8div8sf2_round                       (rtx, rtx, rtx);
extern rtx        gen_floatv8div8sf2_mask                        (rtx, rtx, rtx, rtx);
extern rtx        gen_floatv8div8sf2_mask_round                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv8div8sf2                            (rtx, rtx);
extern rtx        gen_ufloatv8div8sf2_round                      (rtx, rtx, rtx);
extern rtx        gen_ufloatv8div8sf2_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv8div8sf2_mask_round                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_floatv4div4sf2                             (rtx, rtx);
static inline rtx gen_floatv4div4sf2_round                       (rtx, rtx, rtx);
static inline rtx
gen_floatv4div4sf2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_floatv4div4sf2_mask                        (rtx, rtx, rtx, rtx);
static inline rtx gen_floatv4div4sf2_mask_round                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_floatv4div4sf2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_ufloatv4div4sf2                            (rtx, rtx);
static inline rtx gen_ufloatv4div4sf2_round                      (rtx, rtx, rtx);
static inline rtx
gen_ufloatv4div4sf2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_ufloatv4div4sf2_mask                       (rtx, rtx, rtx, rtx);
static inline rtx gen_ufloatv4div4sf2_mask_round                 (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_ufloatv4div4sf2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_floatv2div2sf2_mask                        (rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv2div2sf2_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv8siv8df2                            (rtx, rtx);
extern rtx        gen_ufloatv8siv8df2_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv4siv4df2                            (rtx, rtx);
extern rtx        gen_ufloatv4siv4df2_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_ufloatv2siv2df2                            (rtx, rtx);
extern rtx        gen_ufloatv2siv2df2_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cvtdq2pd512_2                      (rtx, rtx);
extern rtx        gen_avx_cvtdq2pd256_2                          (rtx, rtx);
extern rtx        gen_sse2_cvtdq2pd                              (rtx, rtx);
extern rtx        gen_sse2_cvtdq2pd_mask                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cvtpd2dq512                        (rtx, rtx);
extern rtx        gen_avx512f_cvtpd2dq512_round                  (rtx, rtx, rtx);
extern rtx        gen_avx512f_cvtpd2dq512_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cvtpd2dq512_mask_round             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_cvtpd2dq256                            (rtx, rtx);
extern rtx        gen_avx_cvtpd2dq256_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_cvtpd2dq                              (rtx, rtx);
extern rtx        gen_sse2_cvtpd2dq_mask                         (rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_notruncv8dfv8si2                      (rtx, rtx);
extern rtx        gen_ufix_notruncv8dfv8si2_round                (rtx, rtx, rtx);
extern rtx        gen_ufix_notruncv8dfv8si2_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_notruncv8dfv8si2_mask_round           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_notruncv4dfv4si2                      (rtx, rtx);
extern rtx        gen_ufix_notruncv4dfv4si2_round                (rtx, rtx, rtx);
extern rtx        gen_ufix_notruncv4dfv4si2_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_notruncv4dfv4si2_mask_round           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_notruncv2dfv2si2                      (rtx, rtx);
extern rtx        gen_ufix_notruncv2dfv2si2_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncv8dfv8si2                         (rtx, rtx);
extern rtx        gen_fix_truncv8dfv8si2_round                   (rtx, rtx, rtx);
extern rtx        gen_fix_truncv8dfv8si2_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncv8dfv8si2_mask_round              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_truncv8dfv8si2                        (rtx, rtx);
extern rtx        gen_ufix_truncv8dfv8si2_round                  (rtx, rtx, rtx);
extern rtx        gen_ufix_truncv8dfv8si2_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_truncv8dfv8si2_mask_round             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_truncv2dfv2si2                        (rtx, rtx);
extern rtx        gen_ufix_truncv2dfv2si2_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncv4dfv4si2                         (rtx, rtx);
extern rtx        gen_fix_truncv4dfv4si2_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_truncv4dfv4si2                        (rtx, rtx);
extern rtx        gen_ufix_truncv4dfv4si2_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncv8dfv8di2                         (rtx, rtx);
extern rtx        gen_fix_truncv8dfv8di2_round                   (rtx, rtx, rtx);
extern rtx        gen_fix_truncv8dfv8di2_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncv8dfv8di2_mask_round              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_truncv8dfv8di2                        (rtx, rtx);
extern rtx        gen_ufix_truncv8dfv8di2_round                  (rtx, rtx, rtx);
extern rtx        gen_ufix_truncv8dfv8di2_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_truncv8dfv8di2_mask_round             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncv4dfv4di2                         (rtx, rtx);
static inline rtx gen_fix_truncv4dfv4di2_round                   (rtx, rtx, rtx);
static inline rtx
gen_fix_truncv4dfv4di2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_fix_truncv4dfv4di2_mask                    (rtx, rtx, rtx, rtx);
static inline rtx gen_fix_truncv4dfv4di2_mask_round              (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fix_truncv4dfv4di2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_ufix_truncv4dfv4di2                        (rtx, rtx);
static inline rtx gen_ufix_truncv4dfv4di2_round                  (rtx, rtx, rtx);
static inline rtx
gen_ufix_truncv4dfv4di2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_ufix_truncv4dfv4di2_mask                   (rtx, rtx, rtx, rtx);
static inline rtx gen_ufix_truncv4dfv4di2_mask_round             (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_ufix_truncv4dfv4di2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_fix_truncv2dfv2di2                         (rtx, rtx);
static inline rtx gen_fix_truncv2dfv2di2_round                   (rtx, rtx, rtx);
static inline rtx
gen_fix_truncv2dfv2di2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_fix_truncv2dfv2di2_mask                    (rtx, rtx, rtx, rtx);
static inline rtx gen_fix_truncv2dfv2di2_mask_round              (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fix_truncv2dfv2di2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_ufix_truncv2dfv2di2                        (rtx, rtx);
static inline rtx gen_ufix_truncv2dfv2di2_round                  (rtx, rtx, rtx);
static inline rtx
gen_ufix_truncv2dfv2di2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_ufix_truncv2dfv2di2_mask                   (rtx, rtx, rtx, rtx);
static inline rtx gen_ufix_truncv2dfv2di2_mask_round             (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_ufix_truncv2dfv2di2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_fix_notruncv8dfv8di2                       (rtx, rtx);
extern rtx        gen_fix_notruncv8dfv8di2_round                 (rtx, rtx, rtx);
extern rtx        gen_fix_notruncv8dfv8di2_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_notruncv8dfv8di2_mask_round            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fix_notruncv4dfv4di2                       (rtx, rtx);
static inline rtx gen_fix_notruncv4dfv4di2_round                 (rtx, rtx, rtx);
static inline rtx
gen_fix_notruncv4dfv4di2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_fix_notruncv4dfv4di2_mask                  (rtx, rtx, rtx, rtx);
static inline rtx gen_fix_notruncv4dfv4di2_mask_round            (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fix_notruncv4dfv4di2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_fix_notruncv2dfv2di2                       (rtx, rtx);
static inline rtx gen_fix_notruncv2dfv2di2_round                 (rtx, rtx, rtx);
static inline rtx
gen_fix_notruncv2dfv2di2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_fix_notruncv2dfv2di2_mask                  (rtx, rtx, rtx, rtx);
static inline rtx gen_fix_notruncv2dfv2di2_mask_round            (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fix_notruncv2dfv2di2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_ufix_notruncv8dfv8di2                      (rtx, rtx);
extern rtx        gen_ufix_notruncv8dfv8di2_round                (rtx, rtx, rtx);
extern rtx        gen_ufix_notruncv8dfv8di2_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_notruncv8dfv8di2_mask_round           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_notruncv4dfv4di2                      (rtx, rtx);
static inline rtx gen_ufix_notruncv4dfv4di2_round                (rtx, rtx, rtx);
static inline rtx
gen_ufix_notruncv4dfv4di2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_ufix_notruncv4dfv4di2_mask                 (rtx, rtx, rtx, rtx);
static inline rtx gen_ufix_notruncv4dfv4di2_mask_round           (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_ufix_notruncv4dfv4di2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_ufix_notruncv2dfv2di2                      (rtx, rtx);
static inline rtx gen_ufix_notruncv2dfv2di2_round                (rtx, rtx, rtx);
static inline rtx
gen_ufix_notruncv2dfv2di2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_ufix_notruncv2dfv2di2_mask                 (rtx, rtx, rtx, rtx);
static inline rtx gen_ufix_notruncv2dfv2di2_mask_round           (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_ufix_notruncv2dfv2di2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_fix_truncv8sfv8di2                         (rtx, rtx);
extern rtx        gen_fix_truncv8sfv8di2_round                   (rtx, rtx, rtx);
extern rtx        gen_fix_truncv8sfv8di2_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncv8sfv8di2_mask_round              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_truncv8sfv8di2                        (rtx, rtx);
extern rtx        gen_ufix_truncv8sfv8di2_round                  (rtx, rtx, rtx);
extern rtx        gen_ufix_truncv8sfv8di2_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_truncv8sfv8di2_mask_round             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fix_truncv4sfv4di2                         (rtx, rtx);
static inline rtx gen_fix_truncv4sfv4di2_round                   (rtx, rtx, rtx);
static inline rtx
gen_fix_truncv4sfv4di2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_fix_truncv4sfv4di2_mask                    (rtx, rtx, rtx, rtx);
static inline rtx gen_fix_truncv4sfv4di2_mask_round              (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_fix_truncv4sfv4di2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_ufix_truncv4sfv4di2                        (rtx, rtx);
static inline rtx gen_ufix_truncv4sfv4di2_round                  (rtx, rtx, rtx);
static inline rtx
gen_ufix_truncv4sfv4di2_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_ufix_truncv4sfv4di2_mask                   (rtx, rtx, rtx, rtx);
static inline rtx gen_ufix_truncv4sfv4di2_mask_round             (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_ufix_truncv4sfv4di2_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_fix_truncv2sfv2di2                         (rtx, rtx);
extern rtx        gen_fix_truncv2sfv2di2_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_truncv2sfv2di2                        (rtx, rtx);
extern rtx        gen_ufix_truncv2sfv2di2_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_truncv8sfv8si2                        (rtx, rtx);
extern rtx        gen_ufix_truncv8sfv8si2_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_ufix_truncv4sfv4si2                        (rtx, rtx);
extern rtx        gen_ufix_truncv4sfv4si2_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_cvttpd2dq                             (rtx, rtx);
extern rtx        gen_sse2_cvttpd2dq_mask                        (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_cvtsd2ss                              (rtx, rtx, rtx);
extern rtx        gen_sse2_cvtsd2ss_round                        (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_cvtss2sd                              (rtx, rtx, rtx);
extern rtx        gen_sse2_cvtss2sd_round                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cvtpd2ps512_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cvtpd2ps512_mask_round             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_cvtpd2ps256                            (rtx, rtx);
extern rtx        gen_avx_cvtpd2ps256_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cvtps2pd512                        (rtx, rtx);
extern rtx        gen_avx512f_cvtps2pd512_round                  (rtx, rtx, rtx);
extern rtx        gen_avx512f_cvtps2pd512_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_cvtps2pd512_mask_round             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_cvtps2pd256                            (rtx, rtx);
static inline rtx gen_avx_cvtps2pd256_round                      (rtx, rtx, rtx);
static inline rtx
gen_avx_cvtps2pd256_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c))
{
  return 0;
}
extern rtx        gen_avx_cvtps2pd256_mask                       (rtx, rtx, rtx, rtx);
static inline rtx gen_avx_cvtps2pd256_mask_round                 (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx_cvtps2pd256_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_vec_unpacks_lo_v16sf                       (rtx, rtx);
extern rtx        gen_avx512bw_cvtb2maskv64qi                    (rtx, rtx);
extern rtx        gen_avx512vl_cvtb2maskv16qi                    (rtx, rtx);
extern rtx        gen_avx512vl_cvtb2maskv32qi                    (rtx, rtx);
extern rtx        gen_avx512bw_cvtw2maskv32hi                    (rtx, rtx);
extern rtx        gen_avx512vl_cvtw2maskv16hi                    (rtx, rtx);
extern rtx        gen_avx512vl_cvtw2maskv8hi                     (rtx, rtx);
extern rtx        gen_avx512f_cvtd2maskv16si                     (rtx, rtx);
extern rtx        gen_avx512vl_cvtd2maskv8si                     (rtx, rtx);
extern rtx        gen_avx512vl_cvtd2maskv4si                     (rtx, rtx);
extern rtx        gen_avx512f_cvtq2maskv8di                      (rtx, rtx);
extern rtx        gen_avx512vl_cvtq2maskv4di                     (rtx, rtx);
extern rtx        gen_avx512vl_cvtq2maskv2di                     (rtx, rtx);
extern rtx        gen_sse2_cvtps2pd                              (rtx, rtx);
extern rtx        gen_sse2_cvtps2pd_mask                         (rtx, rtx, rtx, rtx);
extern rtx        gen_sse_movhlps                                (rtx, rtx, rtx);
extern rtx        gen_sse_movlhps                                (rtx, rtx, rtx);
extern rtx        gen_avx512f_unpckhps512_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_unpckhps256                            (rtx, rtx, rtx);
extern rtx        gen_avx_unpckhps256_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv4sf                    (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv4sf_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_unpcklps512_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_unpcklps256                            (rtx, rtx, rtx);
extern rtx        gen_avx_unpcklps256_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_unpcklps128_mask                           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv4sf                     (rtx, rtx, rtx);
extern rtx        gen_avx_movshdup256                            (rtx, rtx);
extern rtx        gen_avx_movshdup256_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_sse3_movshdup                              (rtx, rtx);
extern rtx        gen_sse3_movshdup_mask                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_movshdup512_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_movsldup256                            (rtx, rtx);
extern rtx        gen_avx_movsldup256_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_sse3_movsldup                              (rtx, rtx);
extern rtx        gen_sse3_movsldup_mask                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_movsldup512_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_shufps256_1                            (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_shufps256_1_mask                       (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse_shufps_v4sf_mask                       (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse_shufps_v4si                            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse_shufps_v4sf                            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse_storehps                               (rtx, rtx);
extern rtx        gen_sse_loadhps                                (rtx, rtx, rtx);
extern rtx        gen_sse_storelps                               (rtx, rtx);
extern rtx        gen_sse_loadlps                                (rtx, rtx, rtx);
extern rtx        gen_sse_movss                                  (rtx, rtx, rtx);
extern rtx        gen_avx2_vec_dupv8sf                           (rtx, rtx);
extern rtx        gen_avx2_vec_dupv4sf                           (rtx, rtx);
extern rtx        gen_avx2_vec_dupv8sf_1                         (rtx, rtx);
extern rtx        gen_avx512f_vec_dupv16sf_1                     (rtx, rtx);
extern rtx        gen_avx512f_vec_dupv8df_1                      (rtx, rtx);
extern rtx        gen_vec_setv4si_0                              (rtx, rtx, rtx);
extern rtx        gen_vec_setv4sf_0                              (rtx, rtx, rtx);
extern rtx        gen_sse4_1_insertps                            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_vextractf64x2_1_maskm             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_vextracti64x2_1_maskm             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vextractf32x4_1_maskm              (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vextracti32x4_1_maskm              (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_vextractf64x2_1_mask              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_vextracti64x2_1_mask              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vextractf32x4_1_mask               (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vextracti32x4_1_mask               (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_lo_v8df_maskm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_lo_v8di_maskm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_lo_v8df                        (rtx, rtx);
extern rtx        gen_vec_extract_lo_v8df_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_lo_v8di                        (rtx, rtx);
extern rtx        gen_vec_extract_lo_v8di_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v8df_maskm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v8di_maskm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v8df                        (rtx, rtx);
extern rtx        gen_vec_extract_hi_v8df_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v8di                        (rtx, rtx);
extern rtx        gen_vec_extract_hi_v8di_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v16sf_maskm                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v16si_maskm                 (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v16sf                       (rtx, rtx);
extern rtx        gen_vec_extract_hi_v16sf_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v16si                       (rtx, rtx);
extern rtx        gen_vec_extract_hi_v16si_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_lo_v16sf                       (rtx, rtx);
extern rtx        gen_vec_extract_lo_v16sf_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_lo_v16si                       (rtx, rtx);
extern rtx        gen_vec_extract_lo_v16si_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_lo_v4di                        (rtx, rtx);
extern rtx        gen_vec_extract_lo_v4di_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_lo_v4df                        (rtx, rtx);
extern rtx        gen_vec_extract_lo_v4df_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v4di                        (rtx, rtx);
extern rtx        gen_vec_extract_hi_v4di_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v4df                        (rtx, rtx);
extern rtx        gen_vec_extract_hi_v4df_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_lo_v8si                        (rtx, rtx);
extern rtx        gen_vec_extract_lo_v8si_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_lo_v8sf                        (rtx, rtx);
extern rtx        gen_vec_extract_lo_v8sf_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_lo_v8si_maskm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_lo_v8sf_maskm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v8si_maskm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v8sf_maskm                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v8si_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v8sf_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_extract_hi_v8si                        (rtx, rtx);
extern rtx        gen_vec_extract_hi_v8sf                        (rtx, rtx);
extern rtx        gen_vec_extract_lo_v32hi                       (rtx, rtx);
extern rtx        gen_vec_extract_hi_v32hi                       (rtx, rtx);
extern rtx        gen_vec_extract_lo_v16hi                       (rtx, rtx);
extern rtx        gen_vec_extract_hi_v16hi                       (rtx, rtx);
extern rtx        gen_vec_extract_lo_v64qi                       (rtx, rtx);
extern rtx        gen_vec_extract_hi_v64qi                       (rtx, rtx);
extern rtx        gen_vec_extract_lo_v32qi                       (rtx, rtx);
extern rtx        gen_vec_extract_hi_v32qi                       (rtx, rtx);
extern rtx        gen_avx512f_unpckhpd512_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_unpckhpd256                            (rtx, rtx, rtx);
extern rtx        gen_avx_unpckhpd256_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_unpckhpd128_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_unpcklpd128_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vmscalefv4sf                       (rtx, rtx, rtx);
extern rtx        gen_avx512f_vmscalefv4sf_round                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vmscalefv2df                       (rtx, rtx, rtx);
extern rtx        gen_avx512f_vmscalefv2df_round                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scalefv16sf                        (rtx, rtx, rtx);
extern rtx        gen_avx512f_scalefv16sf_round                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scalefv16sf_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scalefv16sf_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv8sf                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv8sf_round                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv8sf_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv8sf_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv4sf                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv4sf_round                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv4sf_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv4sf_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scalefv8df                         (rtx, rtx, rtx);
extern rtx        gen_avx512f_scalefv8df_round                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scalefv8df_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scalefv8df_mask_round              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv4df                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv4df_round                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv4df_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv4df_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv2df                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv2df_round                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv2df_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scalefv2df_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vternlogv16si                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vternlogv16si_maskz_1              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv8si                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv8si_maskz_1              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv4si                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv4si_maskz_1              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vternlogv8di                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vternlogv8di_maskz_1               (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv4di                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv4di_maskz_1              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv2di                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv2di_maskz_1              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vternlogv16si_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv8si_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv4si_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vternlogv8di_mask                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv4di_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv2di_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_getexpv16sf                        (rtx, rtx);
extern rtx        gen_avx512f_getexpv16sf_round                  (rtx, rtx, rtx);
extern rtx        gen_avx512f_getexpv16sf_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_getexpv16sf_mask_round             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getexpv8sf                        (rtx, rtx);
extern rtx        gen_avx512vl_getexpv8sf_round                  (rtx, rtx, rtx);
extern rtx        gen_avx512vl_getexpv8sf_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getexpv8sf_mask_round             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getexpv4sf                        (rtx, rtx);
extern rtx        gen_avx512vl_getexpv4sf_round                  (rtx, rtx, rtx);
extern rtx        gen_avx512vl_getexpv4sf_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getexpv4sf_mask_round             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_getexpv8df                         (rtx, rtx);
extern rtx        gen_avx512f_getexpv8df_round                   (rtx, rtx, rtx);
extern rtx        gen_avx512f_getexpv8df_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_getexpv8df_mask_round              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getexpv4df                        (rtx, rtx);
extern rtx        gen_avx512vl_getexpv4df_round                  (rtx, rtx, rtx);
extern rtx        gen_avx512vl_getexpv4df_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getexpv4df_mask_round             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getexpv2df                        (rtx, rtx);
extern rtx        gen_avx512vl_getexpv2df_round                  (rtx, rtx, rtx);
extern rtx        gen_avx512vl_getexpv2df_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getexpv2df_mask_round             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sgetexpv4sf                        (rtx, rtx, rtx);
extern rtx        gen_avx512f_sgetexpv4sf_round                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sgetexpv2df                        (rtx, rtx, rtx);
extern rtx        gen_avx512f_sgetexpv2df_round                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_alignv16si_mask                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_alignv8si_mask                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_alignv4si_mask                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_alignv8di_mask                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_alignv4di_mask                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_alignv2di_mask                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv16sf                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv16sf_round                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv16sf_maskz_1              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv16sf_maskz_1_round        (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv8sf                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv8sf_round                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv8sf_maskz_1              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv8sf_maskz_1_round        (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4sf                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4sf_round                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4sf_maskz_1              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4sf_maskz_1_round        (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv8df                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv8df_round                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv8df_maskz_1               (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv8df_maskz_1_round         (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4df                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4df_round                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4df_maskz_1              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4df_maskz_1_round        (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv2df                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv2df_round                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv2df_maskz_1              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv2df_maskz_1_round        (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv16sf_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv16sf_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv8sf_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv8sf_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4sf_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4sf_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv8df_mask                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv8df_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4df_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4df_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv2df_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv2df_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv4sf                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv4sf_round                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv4sf_maskz_1              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv4sf_maskz_1_round        (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv2df                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv2df_round                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv2df_maskz_1              (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv2df_maskz_1_round        (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv4sf_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv4sf_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv2df_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv2df_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rndscalev16sf                      (rtx, rtx, rtx);
extern rtx        gen_avx512f_rndscalev16sf_round                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rndscalev16sf_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rndscalev16sf_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev8sf                      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev8sf_round                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev8sf_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev8sf_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev4sf                      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev4sf_round                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev4sf_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev4sf_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rndscalev8df                       (rtx, rtx, rtx);
extern rtx        gen_avx512f_rndscalev8df_round                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rndscalev8df_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rndscalev8df_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev4df                      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev4df_round                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev4df_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev4df_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev2df                      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev2df_round                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev2df_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rndscalev2df_mask_round           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rndscalev4sf                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rndscalev4sf_round                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rndscalev2df                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rndscalev2df_round                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shufps512_1                        (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shufps512_1_mask                   (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shufpd512_1                        (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shufpd512_1_mask                   (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_shufpd256_1                            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_shufpd256_1_mask                       (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_shufpd_v2df_mask                      (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_highv4di                   (rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_highv4di_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_interleave_highv8di_mask           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv2di                    (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv2di_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_lowv4di                    (rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_lowv4di_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_interleave_lowv8di_mask            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv2di                     (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv2di_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_shufpd_v2di                           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_shufpd_v2df                           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_storehpd                              (rtx, rtx);
extern rtx        gen_sse2_storelpd                              (rtx, rtx);
extern rtx        gen_sse2_loadhpd                               (rtx, rtx, rtx);
extern rtx        gen_sse2_loadlpd                               (rtx, rtx, rtx);
extern rtx        gen_sse2_movsd                                 (rtx, rtx, rtx);
extern rtx        gen_vec_dupv2df                                (rtx, rtx);
extern rtx        gen_vec_dupv2df_mask                           (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_concatv2df                             (rtx, rtx, rtx);
extern rtx        gen_avx512f_ss_truncatev16siv16qi2_mask        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_truncatev16siv16qi2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_us_truncatev16siv16qi2_mask        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ss_truncatev16siv16hi2_mask        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_truncatev16siv16hi2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_us_truncatev16siv16hi2_mask        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ss_truncatev8div8si2_mask          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_truncatev8div8si2_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_us_truncatev8div8si2_mask          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ss_truncatev8div8hi2_mask          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_truncatev8div8hi2_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_us_truncatev8div8hi2_mask          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_ss_truncatev32hiv32qi2            (rtx, rtx);
extern rtx        gen_avx512bw_truncatev32hiv32qi2               (rtx, rtx);
extern rtx        gen_avx512bw_us_truncatev32hiv32qi2            (rtx, rtx);
extern rtx        gen_avx512bw_ss_truncatev32hiv32qi2_mask       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_truncatev32hiv32qi2_mask          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_us_truncatev32hiv32qi2_mask       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev4div4si2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev4div4si2_mask            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev4div4si2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev8siv8hi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev8siv8hi2_mask            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev8siv8hi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev16hiv16qi2_mask       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev16hiv16qi2_mask          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev16hiv16qi2_mask       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev2div2qi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev2div2qi2_mask            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev2div2qi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev2div2qi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev2div2qi2_mask_store      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev2div2qi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev4siv4qi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev4siv4qi2_mask            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev4siv4qi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev4div4qi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev4div4qi2_mask            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev4div4qi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev4siv4qi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev4siv4qi2_mask_store      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev4siv4qi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev4div4qi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev4div4qi2_mask_store      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev4div4qi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev8hiv8qi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev8hiv8qi2_mask            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev8hiv8qi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev8siv8qi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev8siv8qi2_mask            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev8siv8qi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev8hiv8qi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev8hiv8qi2_mask_store      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev8hiv8qi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev8siv8qi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev8siv8qi2_mask_store      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev8siv8qi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev4siv4hi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev4siv4hi2_mask            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev4siv4hi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev4div4hi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev4div4hi2_mask            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev4div4hi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev4siv4hi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev4siv4hi2_mask_store      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev4siv4hi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev4div4hi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev4div4hi2_mask_store      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev4div4hi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev2div2hi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev2div2hi2_mask            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev2div2hi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev2div2hi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev2div2hi2_mask_store      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev2div2hi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev2div2si2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev2div2si2_mask            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev2div2si2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev2div2si2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev2div2si2_mask_store      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev2div2si2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512f_ss_truncatev8div16qi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_truncatev8div16qi2_mask            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_us_truncatev8div16qi2_mask         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ss_truncatev8div16qi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512f_truncatev8div16qi2_mask_store      (rtx, rtx, rtx);
extern rtx        gen_avx512f_us_truncatev8div16qi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512bw_pmaddwd512v32hi                   (rtx, rtx, rtx);
extern rtx        gen_avx512bw_pmaddwd512v32hi_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_pmaddwd512v16hi                   (rtx, rtx, rtx);
extern rtx        gen_avx512bw_pmaddwd512v16hi_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_pmaddwd512v8hi                    (rtx, rtx, rtx);
extern rtx        gen_avx512bw_pmaddwd512v8hi_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_mulv8di3                          (rtx, rtx, rtx);
extern rtx        gen_avx512dq_mulv8di3_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_mulv4di3                          (rtx, rtx, rtx);
extern rtx        gen_avx512dq_mulv4di3_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_mulv2di3                          (rtx, rtx, rtx);
extern rtx        gen_avx512dq_mulv2di3_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashrv16hi3                                 (rtx, rtx, rtx);
extern rtx        gen_ashrv8hi3                                  (rtx, rtx, rtx);
extern rtx        gen_ashrv8si3                                  (rtx, rtx, rtx);
extern rtx        gen_ashrv4si3                                  (rtx, rtx, rtx);
extern rtx        gen_ashrv16hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashrv8hi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashrv8si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashrv4si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashrv2di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashrv32hi3                                 (rtx, rtx, rtx);
extern rtx        gen_ashrv32hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashrv4di3                                  (rtx, rtx, rtx);
extern rtx        gen_ashrv4di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashrv16si3                                 (rtx, rtx, rtx);
extern rtx        gen_ashrv16si3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashrv8di3                                  (rtx, rtx, rtx);
extern rtx        gen_ashrv8di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashlv32hi3                                 (rtx, rtx, rtx);
extern rtx        gen_ashlv32hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_lshrv32hi3                                 (rtx, rtx, rtx);
extern rtx        gen_lshrv32hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashlv16hi3                                 (rtx, rtx, rtx);
extern rtx        gen_ashlv16hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_lshrv16hi3                                 (rtx, rtx, rtx);
extern rtx        gen_lshrv16hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashlv8hi3                                  (rtx, rtx, rtx);
extern rtx        gen_ashlv8hi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_lshrv8hi3                                  (rtx, rtx, rtx);
extern rtx        gen_lshrv8hi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashlv8si3                                  (rtx, rtx, rtx);
extern rtx        gen_ashlv8si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_lshrv8si3                                  (rtx, rtx, rtx);
extern rtx        gen_lshrv8si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashlv4si3                                  (rtx, rtx, rtx);
extern rtx        gen_ashlv4si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_lshrv4si3                                  (rtx, rtx, rtx);
extern rtx        gen_lshrv4si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashlv4di3                                  (rtx, rtx, rtx);
extern rtx        gen_ashlv4di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_lshrv4di3                                  (rtx, rtx, rtx);
extern rtx        gen_lshrv4di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashlv2di3                                  (rtx, rtx, rtx);
extern rtx        gen_ashlv2di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_lshrv2di3                                  (rtx, rtx, rtx);
extern rtx        gen_lshrv2di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashlv16si3                                 (rtx, rtx, rtx);
extern rtx        gen_ashlv16si3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_lshrv16si3                                 (rtx, rtx, rtx);
extern rtx        gen_lshrv16si3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ashlv8di3                                  (rtx, rtx, rtx);
extern rtx        gen_ashlv8di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_lshrv8di3                                  (rtx, rtx, rtx);
extern rtx        gen_lshrv8di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_ashlv4ti3                         (rtx, rtx, rtx);
extern rtx        gen_avx2_ashlv2ti3                             (rtx, rtx, rtx);
extern rtx        gen_sse2_ashlv1ti3                             (rtx, rtx, rtx);
extern rtx        gen_avx512bw_lshrv4ti3                         (rtx, rtx, rtx);
extern rtx        gen_avx2_lshrv2ti3                             (rtx, rtx, rtx);
extern rtx        gen_sse2_lshrv1ti3                             (rtx, rtx, rtx);
extern rtx        gen_avx512f_rolvv16si                          (rtx, rtx, rtx);
extern rtx        gen_avx512f_rolvv16si_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rorvv16si                          (rtx, rtx, rtx);
extern rtx        gen_avx512f_rorvv16si_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolvv8si                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolvv8si_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorvv8si                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorvv8si_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolvv4si                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolvv4si_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorvv4si                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorvv4si_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rolvv8di                           (rtx, rtx, rtx);
extern rtx        gen_avx512f_rolvv8di_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rorvv8di                           (rtx, rtx, rtx);
extern rtx        gen_avx512f_rorvv8di_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolvv4di                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolvv4di_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorvv4di                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorvv4di_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolvv2di                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolvv2di_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorvv2di                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorvv2di_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rolv16si                           (rtx, rtx, rtx);
extern rtx        gen_avx512f_rolv16si_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rorv16si                           (rtx, rtx, rtx);
extern rtx        gen_avx512f_rorv16si_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolv8si                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolv8si_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorv8si                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorv8si_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolv4si                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolv4si_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorv4si                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorv4si_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rolv8di                            (rtx, rtx, rtx);
extern rtx        gen_avx512f_rolv8di_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_rorv8di                            (rtx, rtx, rtx);
extern rtx        gen_avx512f_rorv8di_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolv4di                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolv4di_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorv4di                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorv4di_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolv2di                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rolv2di_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorv2di                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_rorv2di_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv64qi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv64qi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umaxv64qi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_uminv64qi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv16qi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv16qi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umaxv16qi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_uminv16qi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv32qi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv32qi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umaxv32qi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_uminv32qi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv32hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv32hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umaxv32hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_uminv32hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv16hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv16hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umaxv16hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_uminv16hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv8hi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv8hi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umaxv8hi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_uminv8hi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_eqv64qi3_1                        (rtx, rtx, rtx);
extern rtx        gen_avx512bw_eqv64qi3_mask_1                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv16qi3_1                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv16qi3_mask_1                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv32qi3_1                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv32qi3_mask_1                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_eqv32hi3_1                        (rtx, rtx, rtx);
extern rtx        gen_avx512bw_eqv32hi3_mask_1                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv16hi3_1                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv16hi3_mask_1                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv8hi3_1                         (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv8hi3_mask_1                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_eqv16si3_1                         (rtx, rtx, rtx);
extern rtx        gen_avx512f_eqv16si3_mask_1                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv8si3_1                         (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv8si3_mask_1                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv4si3_1                         (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv4si3_mask_1                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_eqv8di3_1                          (rtx, rtx, rtx);
extern rtx        gen_avx512f_eqv8di3_mask_1                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv4di3_1                         (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv4di3_mask_1                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv2di3_1                         (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv2di3_mask_1                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_2_gtv2di3                             (rtx, rtx, rtx);
extern rtx        gen_avx2_gtv32qi3                              (rtx, rtx, rtx);
extern rtx        gen_avx2_gtv16hi3                              (rtx, rtx, rtx);
extern rtx        gen_avx2_gtv8si3                               (rtx, rtx, rtx);
extern rtx        gen_avx2_gtv4di3                               (rtx, rtx, rtx);
extern rtx        gen_avx512f_gtv16si3                           (rtx, rtx, rtx);
extern rtx        gen_avx512f_gtv16si3_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv8si3                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv8si3_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv4si3                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv4si3_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_gtv8di3                            (rtx, rtx, rtx);
extern rtx        gen_avx512f_gtv8di3_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv4di3                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv4di3_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv2di3                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv2di3_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_gtv64qi3                          (rtx, rtx, rtx);
extern rtx        gen_avx512bw_gtv64qi3_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv16qi3                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv16qi3_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv32qi3                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv32qi3_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_gtv32hi3                          (rtx, rtx, rtx);
extern rtx        gen_avx512bw_gtv32hi3_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv16hi3                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv16hi3_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv8hi3                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_gtv8hi3_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_gtv16qi3                              (rtx, rtx, rtx);
extern rtx        gen_sse2_gtv8hi3                               (rtx, rtx, rtx);
extern rtx        gen_sse2_gtv4si3                               (rtx, rtx, rtx);
extern rtx        gen_andv16si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_iorv16si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xorv16si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_andv8si3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_iorv8si3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xorv8si3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_andv4si3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_iorv4si3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xorv4si3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_andv8di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_iorv8di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xorv8di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_andv4di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_iorv4di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xorv4di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_andv2di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_iorv2di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xorv2di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_testmv64qi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512bw_testmv64qi3_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv16qi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv16qi3_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv32qi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv32qi3_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_testmv32hi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512bw_testmv32hi3_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv16hi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv16hi3_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv8hi3                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv8hi3_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_testmv16si3                        (rtx, rtx, rtx);
extern rtx        gen_avx512f_testmv16si3_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv8si3                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv8si3_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv4si3                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv4si3_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_testmv8di3                         (rtx, rtx, rtx);
extern rtx        gen_avx512f_testmv8di3_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv4di3                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv4di3_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv2di3                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testmv2di3_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_testnmv64qi3                      (rtx, rtx, rtx);
extern rtx        gen_avx512bw_testnmv64qi3_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv16qi3                      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv16qi3_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv32qi3                      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv32qi3_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_testnmv32hi3                      (rtx, rtx, rtx);
extern rtx        gen_avx512bw_testnmv32hi3_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv16hi3                      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv16hi3_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv8hi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv8hi3_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_testnmv16si3                       (rtx, rtx, rtx);
extern rtx        gen_avx512f_testnmv16si3_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv8si3                       (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv8si3_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv4si3                       (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv4si3_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_testnmv8di3                        (rtx, rtx, rtx);
extern rtx        gen_avx512f_testnmv8di3_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv4di3                       (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv4di3_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv2di3                       (rtx, rtx, rtx);
extern rtx        gen_avx512vl_testnmv2di3_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_packsswb                          (rtx, rtx, rtx);
extern rtx        gen_avx512bw_packsswb_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_packsswb                              (rtx, rtx, rtx);
extern rtx        gen_avx2_packsswb_mask                         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_packsswb                              (rtx, rtx, rtx);
extern rtx        gen_sse2_packsswb_mask                         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_packssdw                          (rtx, rtx, rtx);
extern rtx        gen_avx512bw_packssdw_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_packssdw                              (rtx, rtx, rtx);
extern rtx        gen_avx2_packssdw_mask                         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_packssdw                              (rtx, rtx, rtx);
extern rtx        gen_sse2_packssdw_mask                         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_packuswb                          (rtx, rtx, rtx);
extern rtx        gen_avx512bw_packuswb_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_packuswb                              (rtx, rtx, rtx);
extern rtx        gen_avx2_packuswb_mask                         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_packuswb                              (rtx, rtx, rtx);
extern rtx        gen_sse2_packuswb_mask                         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_interleave_highv64qi              (rtx, rtx, rtx);
extern rtx        gen_avx512bw_interleave_highv64qi_mask         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_highv32qi                  (rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_highv32qi_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv16qi                   (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv16qi_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_interleave_lowv64qi               (rtx, rtx, rtx);
extern rtx        gen_avx512bw_interleave_lowv64qi_mask          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_lowv32qi                   (rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_lowv32qi_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv16qi                    (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv16qi_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_interleave_highv32hi              (rtx, rtx, rtx);
extern rtx        gen_avx512bw_interleave_highv32hi_mask         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_highv16hi                  (rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_highv16hi_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv8hi                    (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv8hi_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_interleave_lowv32hi_mask          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_lowv16hi                   (rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_lowv16hi_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv8hi                     (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv8hi_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_highv8si                   (rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_highv8si_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_interleave_highv16si_mask          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv4si                    (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv4si_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_lowv8si                    (rtx, rtx, rtx);
extern rtx        gen_avx2_interleave_lowv8si_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_interleave_lowv16si_mask           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv4si                     (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv4si_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_pinsrb                              (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_pinsrw                                (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_pinsrd                              (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_pinsrq                              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_vinsertf64x2_1_mask               (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_vinserti64x2_1_mask               (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vinsertf32x4_1_mask                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vinserti32x4_1_mask                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v16sf                           (rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v16sf_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v16si                           (rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v16si_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v16sf                           (rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v16sf_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v16si                           (rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v16si_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v8df                            (rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v8df_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v8di                            (rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v8di_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v8df                            (rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v8df_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v8di                            (rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v8di_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_shuf_i64x2_1_mask                 (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_shuf_f64x2_1_mask                 (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shuf_f64x2_1                       (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shuf_f64x2_1_mask                  (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shuf_i64x2_1                       (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shuf_i64x2_1_mask                  (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_shuf_i32x4_1_mask                 (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_shuf_f32x4_1_mask                 (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shuf_f32x4_1                       (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shuf_f32x4_1_mask                  (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shuf_i32x4_1                       (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shuf_i32x4_1_mask                  (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_pshufd_1                           (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_pshufd_1_mask                      (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pshufd_1                              (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pshufd_1_mask                         (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_pshufd_1                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_pshufd_1_mask                         (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_pshuflwv32hi_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pshuflw_1                             (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pshuflw_1_mask                        (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_pshuflw_1                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_pshuflw_1_mask                        (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_pshufhwv32hi_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pshufhw_1                             (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pshufhw_1_mask                        (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_pshufhw_1                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_pshufhw_1_mask                        (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_loadld                                (rtx, rtx, rtx);
extern rtx        gen_vec_concatv2di                             (rtx, rtx, rtx);
extern rtx        gen_avx512f_psadbw                             (rtx, rtx, rtx);
extern rtx        gen_avx2_psadbw                                (rtx, rtx, rtx);
extern rtx        gen_sse2_psadbw                                (rtx, rtx, rtx);
extern rtx        gen_avx_movmskps256                            (rtx, rtx);
extern rtx        gen_sse_movmskps                               (rtx, rtx);
extern rtx        gen_avx_movmskpd256                            (rtx, rtx);
extern rtx        gen_sse2_movmskpd                              (rtx, rtx);
extern rtx        gen_avx2_pmovmskb                              (rtx, rtx);
extern rtx        gen_sse2_pmovmskb                              (rtx, rtx);
extern rtx        gen_sse_ldmxcsr                                (rtx);
extern rtx        gen_sse_stmxcsr                                (rtx);
extern rtx        gen_sse2_clflush                               (rtx);
extern rtx        gen_sse3_mwait                                 (rtx, rtx);
extern rtx        gen_sse3_monitor_si                            (rtx, rtx, rtx);
extern rtx        gen_sse3_monitor_di                            (rtx, rtx, rtx);
extern rtx        gen_avx2_phaddwv16hi3                          (rtx, rtx, rtx);
extern rtx        gen_avx2_phaddswv16hi3                         (rtx, rtx, rtx);
extern rtx        gen_avx2_phsubwv16hi3                          (rtx, rtx, rtx);
extern rtx        gen_avx2_phsubswv16hi3                         (rtx, rtx, rtx);
extern rtx        gen_ssse3_phaddwv8hi3                          (rtx, rtx, rtx);
extern rtx        gen_ssse3_phaddswv8hi3                         (rtx, rtx, rtx);
extern rtx        gen_ssse3_phsubwv8hi3                          (rtx, rtx, rtx);
extern rtx        gen_ssse3_phsubswv8hi3                         (rtx, rtx, rtx);
extern rtx        gen_ssse3_phaddwv4hi3                          (rtx, rtx, rtx);
extern rtx        gen_ssse3_phaddswv4hi3                         (rtx, rtx, rtx);
extern rtx        gen_ssse3_phsubwv4hi3                          (rtx, rtx, rtx);
extern rtx        gen_ssse3_phsubswv4hi3                         (rtx, rtx, rtx);
extern rtx        gen_avx2_phadddv8si3                           (rtx, rtx, rtx);
extern rtx        gen_avx2_phsubdv8si3                           (rtx, rtx, rtx);
extern rtx        gen_ssse3_phadddv4si3                          (rtx, rtx, rtx);
extern rtx        gen_ssse3_phsubdv4si3                          (rtx, rtx, rtx);
extern rtx        gen_ssse3_phadddv2si3                          (rtx, rtx, rtx);
extern rtx        gen_ssse3_phsubdv2si3                          (rtx, rtx, rtx);
extern rtx        gen_avx2_pmaddubsw256                          (rtx, rtx, rtx);
extern rtx        gen_avx512bw_pmaddubsw512v8hi                  (rtx, rtx, rtx);
extern rtx        gen_avx512bw_pmaddubsw512v8hi_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_pmaddubsw512v16hi                 (rtx, rtx, rtx);
extern rtx        gen_avx512bw_pmaddubsw512v16hi_mask            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_pmaddubsw512v32hi                 (rtx, rtx, rtx);
extern rtx        gen_avx512bw_pmaddubsw512v32hi_mask            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_umulhrswv32hi3                    (rtx, rtx, rtx);
extern rtx        gen_avx512bw_umulhrswv32hi3_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ssse3_pmaddubsw128                         (rtx, rtx, rtx);
extern rtx        gen_ssse3_pmaddubsw                            (rtx, rtx, rtx);
extern rtx        gen_avx512bw_pshufbv64qi3                      (rtx, rtx, rtx);
extern rtx        gen_avx512bw_pshufbv64qi3_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pshufbv32qi3                          (rtx, rtx, rtx);
extern rtx        gen_avx2_pshufbv32qi3_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ssse3_pshufbv16qi3                         (rtx, rtx, rtx);
extern rtx        gen_ssse3_pshufbv16qi3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ssse3_pshufbv8qi3                          (rtx, rtx, rtx);
extern rtx        gen_avx2_psignv32qi3                           (rtx, rtx, rtx);
extern rtx        gen_ssse3_psignv16qi3                          (rtx, rtx, rtx);
extern rtx        gen_avx2_psignv16hi3                           (rtx, rtx, rtx);
extern rtx        gen_ssse3_psignv8hi3                           (rtx, rtx, rtx);
extern rtx        gen_avx2_psignv8si3                            (rtx, rtx, rtx);
extern rtx        gen_ssse3_psignv4si3                           (rtx, rtx, rtx);
extern rtx        gen_ssse3_psignv8qi3                           (rtx, rtx, rtx);
extern rtx        gen_ssse3_psignv4hi3                           (rtx, rtx, rtx);
extern rtx        gen_ssse3_psignv2si3                           (rtx, rtx, rtx);
extern rtx        gen_avx512bw_palignrv64qi_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_palignrv32qi_mask                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ssse3_palignrv16qi_mask                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_palignrv4ti                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_palignrv2ti                           (rtx, rtx, rtx, rtx);
extern rtx        gen_ssse3_palignrti                            (rtx, rtx, rtx, rtx);
extern rtx        gen_ssse3_palignrdi                            (rtx, rtx, rtx, rtx);
extern rtx        gen_absv16si2_mask                             (rtx, rtx, rtx, rtx);
extern rtx        gen_absv8si2_mask                              (rtx, rtx, rtx, rtx);
extern rtx        gen_absv4si2_mask                              (rtx, rtx, rtx, rtx);
extern rtx        gen_absv8di2_mask                              (rtx, rtx, rtx, rtx);
extern rtx        gen_absv4di2_mask                              (rtx, rtx, rtx, rtx);
extern rtx        gen_absv2di2_mask                              (rtx, rtx, rtx, rtx);
extern rtx        gen_absv64qi2_mask                             (rtx, rtx, rtx, rtx);
extern rtx        gen_absv16qi2_mask                             (rtx, rtx, rtx, rtx);
extern rtx        gen_absv32qi2_mask                             (rtx, rtx, rtx, rtx);
extern rtx        gen_absv32hi2_mask                             (rtx, rtx, rtx, rtx);
extern rtx        gen_absv16hi2_mask                             (rtx, rtx, rtx, rtx);
extern rtx        gen_absv8hi2_mask                              (rtx, rtx, rtx, rtx);
extern rtx        gen_absv8qi2                                   (rtx, rtx);
extern rtx        gen_absv4hi2                                   (rtx, rtx);
extern rtx        gen_absv2si2                                   (rtx, rtx);
extern rtx        gen_sse4a_movntsf                              (rtx, rtx);
extern rtx        gen_sse4a_movntdf                              (rtx, rtx);
extern rtx        gen_sse4a_vmmovntv4sf                          (rtx, rtx);
extern rtx        gen_sse4a_vmmovntv2df                          (rtx, rtx);
extern rtx        gen_sse4a_extrqi                               (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4a_extrq                                (rtx, rtx, rtx);
extern rtx        gen_sse4a_insertqi                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse4a_insertq                              (rtx, rtx, rtx);
extern rtx        gen_avx_blendps256                             (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_blendps                             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_blendpd256                             (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_blendpd                             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_blendvps256                            (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_blendvps                            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_blendvpd256                            (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_blendvpd                            (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_dpps256                                (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_dpps                                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_dppd256                                (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_dppd                                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_movntdqa                           (rtx, rtx);
extern rtx        gen_avx2_movntdqa                              (rtx, rtx);
extern rtx        gen_sse4_1_movntdqa                            (rtx, rtx);
extern rtx        gen_avx2_mpsadbw                               (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_mpsadbw                             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_packusdw                          (rtx, rtx, rtx);
extern rtx        gen_avx512bw_packusdw_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_packusdw                              (rtx, rtx, rtx);
extern rtx        gen_avx2_packusdw_mask                         (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_packusdw                            (rtx, rtx, rtx);
extern rtx        gen_sse4_1_packusdw_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pblendvb                              (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_pblendvb                            (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_pblendw                             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pblenddv8si                           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pblenddv4si                           (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_phminposuw                          (rtx, rtx);
extern rtx        gen_avx2_sign_extendv16qiv16hi2                (rtx, rtx);
extern rtx        gen_avx2_sign_extendv16qiv16hi2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_zero_extendv16qiv16hi2                (rtx, rtx);
extern rtx        gen_avx2_zero_extendv16qiv16hi2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_sign_extendv32qiv32hi2            (rtx, rtx);
extern rtx        gen_avx512bw_sign_extendv32qiv32hi2_mask       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_zero_extendv32qiv32hi2            (rtx, rtx);
extern rtx        gen_avx512bw_zero_extendv32qiv32hi2_mask       (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_sign_extendv8qiv8hi2                (rtx, rtx);
extern rtx        gen_sse4_1_sign_extendv8qiv8hi2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_zero_extendv8qiv8hi2                (rtx, rtx);
extern rtx        gen_sse4_1_zero_extendv8qiv8hi2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sign_extendv16qiv16si2_mask        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_zero_extendv16qiv16si2_mask        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_sign_extendv8qiv8si2                  (rtx, rtx);
extern rtx        gen_avx2_sign_extendv8qiv8si2_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_zero_extendv8qiv8si2                  (rtx, rtx);
extern rtx        gen_avx2_zero_extendv8qiv8si2_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_sign_extendv4qiv4si2                (rtx, rtx);
extern rtx        gen_sse4_1_sign_extendv4qiv4si2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_zero_extendv4qiv4si2                (rtx, rtx);
extern rtx        gen_sse4_1_zero_extendv4qiv4si2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sign_extendv16hiv16si2             (rtx, rtx);
extern rtx        gen_avx512f_sign_extendv16hiv16si2_mask        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_zero_extendv16hiv16si2             (rtx, rtx);
extern rtx        gen_avx512f_zero_extendv16hiv16si2_mask        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_sign_extendv8hiv8si2                  (rtx, rtx);
extern rtx        gen_avx2_sign_extendv8hiv8si2_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_zero_extendv8hiv8si2                  (rtx, rtx);
extern rtx        gen_avx2_zero_extendv8hiv8si2_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_sign_extendv4hiv4si2                (rtx, rtx);
extern rtx        gen_sse4_1_sign_extendv4hiv4si2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_zero_extendv4hiv4si2                (rtx, rtx);
extern rtx        gen_sse4_1_zero_extendv4hiv4si2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sign_extendv8qiv8di2               (rtx, rtx);
extern rtx        gen_avx512f_sign_extendv8qiv8di2_mask          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_zero_extendv8qiv8di2               (rtx, rtx);
extern rtx        gen_avx512f_zero_extendv8qiv8di2_mask          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_sign_extendv4qiv4di2                  (rtx, rtx);
extern rtx        gen_avx2_sign_extendv4qiv4di2_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_zero_extendv4qiv4di2                  (rtx, rtx);
extern rtx        gen_avx2_zero_extendv4qiv4di2_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_sign_extendv2qiv2di2                (rtx, rtx);
extern rtx        gen_sse4_1_sign_extendv2qiv2di2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_zero_extendv2qiv2di2                (rtx, rtx);
extern rtx        gen_sse4_1_zero_extendv2qiv2di2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sign_extendv8hiv8di2               (rtx, rtx);
extern rtx        gen_avx512f_sign_extendv8hiv8di2_mask          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_zero_extendv8hiv8di2               (rtx, rtx);
extern rtx        gen_avx512f_zero_extendv8hiv8di2_mask          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_sign_extendv4hiv4di2                  (rtx, rtx);
extern rtx        gen_avx2_sign_extendv4hiv4di2_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_zero_extendv4hiv4di2                  (rtx, rtx);
extern rtx        gen_avx2_zero_extendv4hiv4di2_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_sign_extendv2hiv2di2                (rtx, rtx);
extern rtx        gen_sse4_1_sign_extendv2hiv2di2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_zero_extendv2hiv2di2                (rtx, rtx);
extern rtx        gen_sse4_1_zero_extendv2hiv2di2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sign_extendv8siv8di2               (rtx, rtx);
extern rtx        gen_avx512f_sign_extendv8siv8di2_mask          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_zero_extendv8siv8di2               (rtx, rtx);
extern rtx        gen_avx512f_zero_extendv8siv8di2_mask          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_sign_extendv4siv4di2                  (rtx, rtx);
extern rtx        gen_avx2_sign_extendv4siv4di2_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_zero_extendv4siv4di2                  (rtx, rtx);
extern rtx        gen_avx2_zero_extendv4siv4di2_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_sign_extendv2siv2di2                (rtx, rtx);
extern rtx        gen_sse4_1_sign_extendv2siv2di2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_zero_extendv2siv2di2                (rtx, rtx);
extern rtx        gen_sse4_1_zero_extendv2siv2di2_mask           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vtestps256                             (rtx, rtx);
extern rtx        gen_avx_vtestps                                (rtx, rtx);
extern rtx        gen_avx_vtestpd256                             (rtx, rtx);
extern rtx        gen_avx_vtestpd                                (rtx, rtx);
extern rtx        gen_sse4_1_ptestv16qi                          (rtx, rtx);
extern rtx        gen_sse4_1_ptestv8hi                           (rtx, rtx);
extern rtx        gen_sse4_1_ptestv4si                           (rtx, rtx);
extern rtx        gen_sse4_1_ptestv2di                           (rtx, rtx);
extern rtx        gen_sse4_1_ptestv4sf                           (rtx, rtx);
extern rtx        gen_sse4_1_ptestv2df                           (rtx, rtx);
extern rtx        gen_avx_ptestv32qi                             (rtx, rtx);
extern rtx        gen_avx_ptestv16hi                             (rtx, rtx);
extern rtx        gen_avx_ptestv8si                              (rtx, rtx);
extern rtx        gen_avx_ptestv4di                              (rtx, rtx);
extern rtx        gen_avx_ptestv8sf                              (rtx, rtx);
extern rtx        gen_avx_ptestv4df                              (rtx, rtx);
extern rtx        gen_avx_roundps256                             (rtx, rtx, rtx);
extern rtx        gen_sse4_1_roundps                             (rtx, rtx, rtx);
extern rtx        gen_avx_roundpd256                             (rtx, rtx, rtx);
extern rtx        gen_sse4_1_roundpd                             (rtx, rtx, rtx);
extern rtx        gen_sse4_1_roundss                             (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_roundsd                             (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_2_pcmpestr                            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_2_pcmpestri                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_2_pcmpestrm                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_2_pcmpestr_cconly                     (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_2_pcmpistr                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_2_pcmpistri                           (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_2_pcmpistrm                           (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_2_pcmpistr_cconly                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_exp2v16sf                         (rtx, rtx);
extern rtx        gen_avx512er_exp2v16sf_round                   (rtx, rtx, rtx);
extern rtx        gen_avx512er_exp2v16sf_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_exp2v16sf_mask_round              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_exp2v8df                          (rtx, rtx);
extern rtx        gen_avx512er_exp2v8df_round                    (rtx, rtx, rtx);
extern rtx        gen_avx512er_exp2v8df_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_exp2v8df_mask_round               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_rcp28v16sf_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_rcp28v16sf_mask_round             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_rcp28v8df_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_rcp28v8df_mask_round              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_vmrcp28v4sf                       (rtx, rtx, rtx);
extern rtx        gen_avx512er_vmrcp28v4sf_round                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_vmrcp28v2df                       (rtx, rtx, rtx);
extern rtx        gen_avx512er_vmrcp28v2df_round                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_rsqrt28v16sf_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_rsqrt28v16sf_mask_round           (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_rsqrt28v8df_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_rsqrt28v8df_mask_round            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_vmrsqrt28v4sf                     (rtx, rtx, rtx);
extern rtx        gen_avx512er_vmrsqrt28v4sf_round               (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512er_vmrsqrt28v2df                     (rtx, rtx, rtx);
extern rtx        gen_avx512er_vmrsqrt28v2df_round               (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pmacsww                                (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pmacssww                               (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pmacsdd                                (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pmacssdd                               (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pmacsdql                               (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pmacssdql                              (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pmacsdqh                               (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pmacssdqh                              (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pmacswd                                (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pmacsswd                               (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pmadcswd                               (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pmadcsswd                              (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v32qi256                         (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v16qi                            (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v16hi256                         (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v8hi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v16si512                         (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v8si256                          (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v4si                             (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v8di512                          (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v4di256                          (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v2di                             (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v16sf512                         (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v8sf256                          (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v4sf                             (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v8df512                          (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v4df256                          (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcmov_v2df                             (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_phaddbw                                (rtx, rtx);
extern rtx        gen_xop_phaddubw                               (rtx, rtx);
extern rtx        gen_xop_phaddbd                                (rtx, rtx);
extern rtx        gen_xop_phaddubd                               (rtx, rtx);
extern rtx        gen_xop_phaddbq                                (rtx, rtx);
extern rtx        gen_xop_phaddubq                               (rtx, rtx);
extern rtx        gen_xop_phaddwd                                (rtx, rtx);
extern rtx        gen_xop_phadduwd                               (rtx, rtx);
extern rtx        gen_xop_phaddwq                                (rtx, rtx);
extern rtx        gen_xop_phadduwq                               (rtx, rtx);
extern rtx        gen_xop_phadddq                                (rtx, rtx);
extern rtx        gen_xop_phaddudq                               (rtx, rtx);
extern rtx        gen_xop_phsubbw                                (rtx, rtx);
extern rtx        gen_xop_phsubwd                                (rtx, rtx);
extern rtx        gen_xop_phsubdq                                (rtx, rtx);
extern rtx        gen_xop_pperm                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pperm_pack_v2di_v4si                   (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pperm_pack_v4si_v8hi                   (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pperm_pack_v8hi_v16qi                  (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_rotlv16qi3                             (rtx, rtx, rtx);
extern rtx        gen_xop_rotlv8hi3                              (rtx, rtx, rtx);
extern rtx        gen_xop_rotlv4si3                              (rtx, rtx, rtx);
extern rtx        gen_xop_rotlv2di3                              (rtx, rtx, rtx);
extern rtx        gen_xop_rotrv16qi3                             (rtx, rtx, rtx);
extern rtx        gen_xop_rotrv8hi3                              (rtx, rtx, rtx);
extern rtx        gen_xop_rotrv4si3                              (rtx, rtx, rtx);
extern rtx        gen_xop_rotrv2di3                              (rtx, rtx, rtx);
extern rtx        gen_xop_vrotlv16qi3                            (rtx, rtx, rtx);
extern rtx        gen_xop_vrotlv8hi3                             (rtx, rtx, rtx);
extern rtx        gen_xop_vrotlv4si3                             (rtx, rtx, rtx);
extern rtx        gen_xop_vrotlv2di3                             (rtx, rtx, rtx);
extern rtx        gen_xop_shav16qi3                              (rtx, rtx, rtx);
extern rtx        gen_xop_shav8hi3                               (rtx, rtx, rtx);
extern rtx        gen_xop_shav4si3                               (rtx, rtx, rtx);
extern rtx        gen_xop_shav2di3                               (rtx, rtx, rtx);
extern rtx        gen_xop_shlv16qi3                              (rtx, rtx, rtx);
extern rtx        gen_xop_shlv8hi3                               (rtx, rtx, rtx);
extern rtx        gen_xop_shlv4si3                               (rtx, rtx, rtx);
extern rtx        gen_xop_shlv2di3                               (rtx, rtx, rtx);
extern rtx        gen_xop_frczsf2                                (rtx, rtx);
extern rtx        gen_xop_frczdf2                                (rtx, rtx);
extern rtx        gen_xop_frczv4sf2                              (rtx, rtx);
extern rtx        gen_xop_frczv2df2                              (rtx, rtx);
extern rtx        gen_xop_frczv8sf2                              (rtx, rtx);
extern rtx        gen_xop_frczv4df2                              (rtx, rtx);
extern rtx        gen_xop_maskcmpv16qi3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_maskcmpv8hi3                           (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_maskcmpv4si3                           (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_maskcmpv2di3                           (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_maskcmp_unsv16qi3                      (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_maskcmp_unsv8hi3                       (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_maskcmp_unsv4si3                       (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_maskcmp_unsv2di3                       (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_maskcmp_uns2v16qi3                     (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_maskcmp_uns2v8hi3                      (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_maskcmp_uns2v4si3                      (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_maskcmp_uns2v2di3                      (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcom_tfv16qi3                          (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcom_tfv8hi3                           (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcom_tfv4si3                           (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_pcom_tfv2di3                           (rtx, rtx, rtx, rtx);
extern rtx        gen_xop_vpermil2v8sf3                          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xop_vpermil2v4sf3                          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xop_vpermil2v4df3                          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xop_vpermil2v2df3                          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_aesenc                                     (rtx, rtx, rtx);
extern rtx        gen_aesenclast                                 (rtx, rtx, rtx);
extern rtx        gen_aesdec                                     (rtx, rtx, rtx);
extern rtx        gen_aesdeclast                                 (rtx, rtx, rtx);
extern rtx        gen_aesimc                                     (rtx, rtx);
extern rtx        gen_aeskeygenassist                            (rtx, rtx, rtx);
extern rtx        gen_pclmulqdq                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vzeroupper                             (void);
extern rtx        gen_avx2_pbroadcastv16si                       (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv8di                        (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv64qi                       (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv32qi                       (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv16qi                       (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv32hi                       (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv16hi                       (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv8hi                        (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv8si                        (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv4si                        (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv4di                        (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv2di                        (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv32qi_1                     (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv16hi_1                     (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv8si_1                      (rtx, rtx);
extern rtx        gen_avx2_pbroadcastv4di_1                      (rtx, rtx);
extern rtx        gen_avx2_permvarv8si                           (rtx, rtx, rtx);
extern rtx        gen_avx2_permvarv8si_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_permvarv8sf                           (rtx, rtx, rtx);
extern rtx        gen_avx2_permvarv8sf_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_permvarv16si                       (rtx, rtx, rtx);
extern rtx        gen_avx512f_permvarv16si_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_permvarv16sf                       (rtx, rtx, rtx);
extern rtx        gen_avx512f_permvarv16sf_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_permvarv8di                        (rtx, rtx, rtx);
extern rtx        gen_avx512f_permvarv8di_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_permvarv8df                        (rtx, rtx, rtx);
extern rtx        gen_avx512f_permvarv8df_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_permvarv4di                           (rtx, rtx, rtx);
extern rtx        gen_avx2_permvarv4di_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_permvarv4df                           (rtx, rtx, rtx);
extern rtx        gen_avx2_permvarv4df_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_permvarv64qi                      (rtx, rtx, rtx);
extern rtx        gen_avx512bw_permvarv64qi_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_permvarv16qi                      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_permvarv16qi_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_permvarv32qi                      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_permvarv32qi_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_permvarv8hi                       (rtx, rtx, rtx);
extern rtx        gen_avx512vl_permvarv8hi_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_permvarv16hi                      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_permvarv16hi_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_permvarv32hi                      (rtx, rtx, rtx);
extern rtx        gen_avx512bw_permvarv32hi_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_permv4di_1                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_permv4di_1_mask                       (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_permv4df_1                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_permv4df_1_mask                       (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_permv8di_1                         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_permv8di_1_mask                    (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_permv8df_1                         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_permv8df_1_mask                    (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_permv2ti                              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_vec_dupv4df                           (rtx, rtx);
extern rtx        gen_avx512f_vec_dupv16si_1                     (rtx, rtx);
extern rtx        gen_avx512f_vec_dupv8di_1                      (rtx, rtx);
extern rtx        gen_avx512bw_vec_dupv32hi_1                    (rtx, rtx);
extern rtx        gen_avx512bw_vec_dupv64qi_1                    (rtx, rtx);
extern rtx        gen_avx512f_vec_dupv16si                       (rtx, rtx);
extern rtx        gen_avx512f_vec_dupv16si_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv8si                       (rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv8si_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv4si                       (rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv4si_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vec_dupv8di                        (rtx, rtx);
extern rtx        gen_avx512f_vec_dupv8di_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv4di                       (rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv4di_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv2di                       (rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv2di_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vec_dupv16sf                       (rtx, rtx);
extern rtx        gen_avx512f_vec_dupv16sf_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv8sf                       (rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv8sf_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv4sf                       (rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv4sf_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vec_dupv8df                        (rtx, rtx);
extern rtx        gen_avx512f_vec_dupv8df_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv4df                       (rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv4df_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv2df                       (rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv2df_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vec_dupv64qi                      (rtx, rtx);
extern rtx        gen_avx512bw_vec_dupv64qi_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv16qi                      (rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv16qi_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv32qi                      (rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv32qi_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vec_dupv32hi                      (rtx, rtx);
extern rtx        gen_avx512bw_vec_dupv32hi_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv16hi                      (rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv16hi_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv8hi                       (rtx, rtx);
extern rtx        gen_avx512vl_vec_dupv8hi_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_broadcastv16sf_mask                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_broadcastv16si_mask                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_broadcastv8df_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_broadcastv8di_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vec_dup_gprv64qi_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dup_gprv16qi_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dup_gprv32qi_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vec_dup_gprv32hi_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dup_gprv16hi_mask             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dup_gprv8hi_mask              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vec_dup_gprv16si_mask              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dup_gprv8si_mask              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dup_gprv4si_mask              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vec_dup_gprv8di_mask               (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dup_gprv4di_mask              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dup_gprv2di_mask              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vec_dup_gprv16sf_mask              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dup_gprv8sf_mask              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dup_gprv4sf_mask              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vec_dup_gprv8df_mask               (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dup_gprv4df_mask              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vec_dup_gprv2df_mask              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_dupv4sf                                (rtx, rtx);
extern rtx        gen_avx2_vbroadcasti128_v32qi                  (rtx, rtx);
extern rtx        gen_avx2_vbroadcasti128_v16hi                  (rtx, rtx);
extern rtx        gen_avx2_vbroadcasti128_v8si                   (rtx, rtx);
extern rtx        gen_avx2_vbroadcasti128_v4di                   (rtx, rtx);
extern rtx        gen_vec_dupv8si                                (rtx, rtx);
extern rtx        gen_vec_dupv8sf                                (rtx, rtx);
extern rtx        gen_vec_dupv4di                                (rtx, rtx);
extern rtx        gen_vec_dupv4df                                (rtx, rtx);
extern rtx        gen_avx_vbroadcastf128_v32qi                   (rtx, rtx);
extern rtx        gen_avx_vbroadcastf128_v16hi                   (rtx, rtx);
extern rtx        gen_avx_vbroadcastf128_v8si                    (rtx, rtx);
extern rtx        gen_avx_vbroadcastf128_v4di                    (rtx, rtx);
extern rtx        gen_avx_vbroadcastf128_v8sf                    (rtx, rtx);
extern rtx        gen_avx_vbroadcastf128_v4df                    (rtx, rtx);
extern rtx        gen_avx512dq_broadcastv16si_mask               (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_broadcastv8si_mask                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_broadcastv4si_mask                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_broadcastv16sf_mask               (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_broadcastv8sf_mask                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_broadcastv8si_mask_1              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_broadcastv8sf_mask_1              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_broadcastv16sf_mask_1             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_broadcastv16si_mask_1             (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_broadcastv8di_mask_1              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_broadcastv8df_mask_1              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_broadcastv4di_mask_1              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_broadcastv4df_mask_1              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512cd_maskb_vec_dupv8di                 (rtx, rtx);
extern rtx        gen_avx512cd_maskb_vec_dupv4di                 (rtx, rtx);
extern rtx        gen_avx512cd_maskb_vec_dupv2di                 (rtx, rtx);
extern rtx        gen_avx512cd_maskw_vec_dupv16si                (rtx, rtx);
extern rtx        gen_avx512cd_maskw_vec_dupv8si                 (rtx, rtx);
extern rtx        gen_avx512cd_maskw_vec_dupv4si                 (rtx, rtx);
extern rtx        gen_avx512f_vpermilvarv16sf3                   (rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermilvarv16sf3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vpermilvarv8sf3                        (rtx, rtx, rtx);
extern rtx        gen_avx_vpermilvarv8sf3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vpermilvarv4sf3                        (rtx, rtx, rtx);
extern rtx        gen_avx_vpermilvarv4sf3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermilvarv8df3                    (rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermilvarv8df3_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vpermilvarv4df3                        (rtx, rtx, rtx);
extern rtx        gen_avx_vpermilvarv4df3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vpermilvarv2df3                        (rtx, rtx, rtx);
extern rtx        gen_avx_vpermilvarv2df3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv16si3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv16si3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv16sf3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv16sf3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv8di3                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv8di3_maskz_1            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv8df3                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv8df3_maskz_1            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv8si3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv8si3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv8sf3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv8sf3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4di3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4di3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4df3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4df3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4si3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4si3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4sf3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4sf3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv2di3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv2di3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv2df3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv2df3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermi2varv64qi3                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermi2varv64qi3_maskz_1          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv16qi3                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv16qi3_maskz_1          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv32qi3                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv32qi3_maskz_1          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv8hi3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv8hi3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv16hi3                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv16hi3_maskz_1          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermi2varv32hi3                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermi2varv32hi3_maskz_1          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv16si3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv16sf3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv8di3_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv8df3_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv8si3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv8sf3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4di3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4df3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4si3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4sf3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv2di3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv2df3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermi2varv64qi3_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv16qi3_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv32qi3_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv8hi3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv16hi3_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermi2varv32hi3_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv16si3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv16si3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv16sf3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv16sf3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv8di3                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv8di3_maskz_1            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv8df3                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv8df3_maskz_1            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv8si3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv8si3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv8sf3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv8sf3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4di3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4di3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4df3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4df3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4si3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4si3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4sf3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4sf3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv2di3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv2di3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv2df3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv2df3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermt2varv64qi3                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermt2varv64qi3_maskz_1          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv16qi3                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv16qi3_maskz_1          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv32qi3                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv32qi3_maskz_1          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv8hi3                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv8hi3_maskz_1           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv16hi3                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv16hi3_maskz_1          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermt2varv32hi3                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermt2varv32hi3_maskz_1          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv16si3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv16sf3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv8di3_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv8df3_mask               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv8si3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv8sf3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4di3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4df3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4si3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4sf3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv2di3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv2df3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermt2varv64qi3_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv16qi3_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv32qi3_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv8hi3_mask              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv16hi3_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermt2varv32hi3_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v4di                            (rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v4di_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v4df                            (rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v4df_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v4di                            (rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v4di_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v4df                            (rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v4df_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v8si                            (rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v8si_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v8sf                            (rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v8sf_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v8si                            (rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v8si_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v8sf                            (rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v8sf_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v16hi                           (rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v16hi                           (rtx, rtx, rtx);
extern rtx        gen_vec_set_lo_v32qi                           (rtx, rtx, rtx);
extern rtx        gen_vec_set_hi_v32qi                           (rtx, rtx, rtx);
extern rtx        gen_avx_maskloadps                             (rtx, rtx, rtx);
extern rtx        gen_avx_maskloadpd                             (rtx, rtx, rtx);
extern rtx        gen_avx_maskloadps256                          (rtx, rtx, rtx);
extern rtx        gen_avx_maskloadpd256                          (rtx, rtx, rtx);
extern rtx        gen_avx2_maskloadd                             (rtx, rtx, rtx);
extern rtx        gen_avx2_maskloadq                             (rtx, rtx, rtx);
extern rtx        gen_avx2_maskloadd256                          (rtx, rtx, rtx);
extern rtx        gen_avx2_maskloadq256                          (rtx, rtx, rtx);
extern rtx        gen_avx_maskstoreps                            (rtx, rtx, rtx);
extern rtx        gen_avx_maskstorepd                            (rtx, rtx, rtx);
extern rtx        gen_avx_maskstoreps256                         (rtx, rtx, rtx);
extern rtx        gen_avx_maskstorepd256                         (rtx, rtx, rtx);
extern rtx        gen_avx2_maskstored                            (rtx, rtx, rtx);
extern rtx        gen_avx2_maskstoreq                            (rtx, rtx, rtx);
extern rtx        gen_avx2_maskstored256                         (rtx, rtx, rtx);
extern rtx        gen_avx2_maskstoreq256                         (rtx, rtx, rtx);
extern rtx        gen_avx_si256_si                               (rtx, rtx);
extern rtx        gen_avx_ps256_ps                               (rtx, rtx);
extern rtx        gen_avx_pd256_pd                               (rtx, rtx);
extern rtx        gen_avx2_ashrvv4si                             (rtx, rtx, rtx);
extern rtx        gen_avx2_ashrvv4si_mask                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_ashrvv8si                             (rtx, rtx, rtx);
extern rtx        gen_avx2_ashrvv8si_mask                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ashrvv16si                         (rtx, rtx, rtx);
extern rtx        gen_avx512f_ashrvv16si_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_ashrvv2di                             (rtx, rtx, rtx);
extern rtx        gen_avx2_ashrvv2di_mask                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_ashrvv4di                             (rtx, rtx, rtx);
extern rtx        gen_avx2_ashrvv4di_mask                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ashrvv8di                          (rtx, rtx, rtx);
extern rtx        gen_avx512f_ashrvv8di_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ashrvv8hi                         (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ashrvv8hi_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ashrvv16hi                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ashrvv16hi_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_ashrvv32hi                        (rtx, rtx, rtx);
extern rtx        gen_avx512bw_ashrvv32hi_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ashlvv16si                         (rtx, rtx, rtx);
extern rtx        gen_avx512f_ashlvv16si_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_lshrvv16si                         (rtx, rtx, rtx);
extern rtx        gen_avx512f_lshrvv16si_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_ashlvv8si                             (rtx, rtx, rtx);
extern rtx        gen_avx2_ashlvv8si_mask                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_lshrvv8si                             (rtx, rtx, rtx);
extern rtx        gen_avx2_lshrvv8si_mask                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_ashlvv4si                             (rtx, rtx, rtx);
extern rtx        gen_avx2_ashlvv4si_mask                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_lshrvv4si                             (rtx, rtx, rtx);
extern rtx        gen_avx2_lshrvv4si_mask                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_ashlvv8di                          (rtx, rtx, rtx);
extern rtx        gen_avx512f_ashlvv8di_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_lshrvv8di                          (rtx, rtx, rtx);
extern rtx        gen_avx512f_lshrvv8di_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_ashlvv4di                             (rtx, rtx, rtx);
extern rtx        gen_avx2_ashlvv4di_mask                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_lshrvv4di                             (rtx, rtx, rtx);
extern rtx        gen_avx2_lshrvv4di_mask                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_ashlvv2di                             (rtx, rtx, rtx);
extern rtx        gen_avx2_ashlvv2di_mask                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_lshrvv2di                             (rtx, rtx, rtx);
extern rtx        gen_avx2_lshrvv2di_mask                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ashlvv8hi                         (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ashlvv8hi_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_lshrvv8hi                         (rtx, rtx, rtx);
extern rtx        gen_avx512vl_lshrvv8hi_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_ashlvv16hi                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ashlvv16hi_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_lshrvv16hi                        (rtx, rtx, rtx);
extern rtx        gen_avx512vl_lshrvv16hi_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_ashlvv32hi                        (rtx, rtx, rtx);
extern rtx        gen_avx512bw_ashlvv32hi_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_lshrvv32hi                        (rtx, rtx, rtx);
extern rtx        gen_avx512bw_lshrvv32hi_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vec_concatv32qi                        (rtx, rtx, rtx);
extern rtx        gen_avx_vec_concatv16hi                        (rtx, rtx, rtx);
extern rtx        gen_avx_vec_concatv8si                         (rtx, rtx, rtx);
extern rtx        gen_avx_vec_concatv4di                         (rtx, rtx, rtx);
extern rtx        gen_avx_vec_concatv8sf                         (rtx, rtx, rtx);
extern rtx        gen_avx_vec_concatv4df                         (rtx, rtx, rtx);
extern rtx        gen_avx_vec_concatv64qi                        (rtx, rtx, rtx);
extern rtx        gen_avx_vec_concatv32hi                        (rtx, rtx, rtx);
extern rtx        gen_avx_vec_concatv16si                        (rtx, rtx, rtx);
extern rtx        gen_avx_vec_concatv8di                         (rtx, rtx, rtx);
extern rtx        gen_avx_vec_concatv16sf                        (rtx, rtx, rtx);
extern rtx        gen_avx_vec_concatv8df                         (rtx, rtx, rtx);
extern rtx        gen_vcvtph2ps                                  (rtx, rtx);
extern rtx        gen_vcvtph2ps_mask                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vcvtph2ps256                               (rtx, rtx);
extern rtx        gen_vcvtph2ps256_mask                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vcvtph2ps512_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vcvtph2ps512_mask_round            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcvtps2ph256                               (rtx, rtx, rtx);
extern rtx        gen_vcvtps2ph256_mask                          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vcvtps2ph512_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_compressv16si_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_compressv16sf_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_compressv8di_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_compressv8df_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressv8si_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressv8sf_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressv4di_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressv4df_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressv4si_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressv4sf_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressv2di_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressv2df_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_compressstorev16si_mask            (rtx, rtx, rtx);
extern rtx        gen_avx512f_compressstorev16sf_mask            (rtx, rtx, rtx);
extern rtx        gen_avx512f_compressstorev8di_mask             (rtx, rtx, rtx);
extern rtx        gen_avx512f_compressstorev8df_mask             (rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressstorev8si_mask            (rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressstorev8sf_mask            (rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressstorev4di_mask            (rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressstorev4df_mask            (rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressstorev4si_mask            (rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressstorev4sf_mask            (rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressstorev2di_mask            (rtx, rtx, rtx);
extern rtx        gen_avx512vl_compressstorev2df_mask            (rtx, rtx, rtx);
extern rtx        gen_avx512f_expandv16si_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_expandv16sf_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_expandv8di_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_expandv8df_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv8si_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv8sf_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv4di_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv4df_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv4si_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv4sf_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv2di_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv2df_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_rangepv16sf                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_rangepv16sf_round                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_rangepv16sf_mask                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_rangepv16sf_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_rangepv8sf                        (rtx, rtx, rtx, rtx);
static inline rtx gen_avx512dq_rangepv8sf_round                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512dq_rangepv8sf_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_avx512dq_rangepv8sf_mask                   (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512dq_rangepv8sf_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512dq_rangepv8sf_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_avx512dq_rangepv4sf                        (rtx, rtx, rtx, rtx);
static inline rtx gen_avx512dq_rangepv4sf_round                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512dq_rangepv4sf_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_avx512dq_rangepv4sf_mask                   (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512dq_rangepv4sf_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512dq_rangepv4sf_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_avx512dq_rangepv8df                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_rangepv8df_round                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_rangepv8df_mask                   (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_rangepv8df_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_rangepv4df                        (rtx, rtx, rtx, rtx);
static inline rtx gen_avx512dq_rangepv4df_round                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512dq_rangepv4df_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_avx512dq_rangepv4df_mask                   (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512dq_rangepv4df_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512dq_rangepv4df_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_avx512dq_rangepv2df                        (rtx, rtx, rtx, rtx);
static inline rtx gen_avx512dq_rangepv2df_round                  (rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512dq_rangepv2df_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e))
{
  return 0;
}
extern rtx        gen_avx512dq_rangepv2df_mask                   (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_avx512dq_rangepv2df_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_avx512dq_rangepv2df_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f), rtx ARG_UNUSED (g))
{
  return 0;
}
extern rtx        gen_avx512dq_rangesv4sf                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_rangesv4sf_round                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_rangesv2df                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_rangesv2df_round                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_fpclassv16sf                      (rtx, rtx, rtx);
extern rtx        gen_avx512dq_fpclassv16sf_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_fpclassv8sf                       (rtx, rtx, rtx);
extern rtx        gen_avx512dq_fpclassv8sf_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_fpclassv4sf                       (rtx, rtx, rtx);
extern rtx        gen_avx512dq_fpclassv4sf_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_fpclassv8df                       (rtx, rtx, rtx);
extern rtx        gen_avx512dq_fpclassv8df_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_fpclassv4df                       (rtx, rtx, rtx);
extern rtx        gen_avx512dq_fpclassv4df_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_fpclassv2df                       (rtx, rtx, rtx);
extern rtx        gen_avx512dq_fpclassv2df_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_vmfpclassv4sf                     (rtx, rtx, rtx);
extern rtx        gen_avx512dq_vmfpclassv2df                     (rtx, rtx, rtx);
extern rtx        gen_avx512f_getmantv16sf                       (rtx, rtx, rtx);
extern rtx        gen_avx512f_getmantv16sf_round                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_getmantv16sf_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_getmantv16sf_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv8sf                       (rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv8sf_round                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv8sf_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv8sf_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv4sf                       (rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv4sf_round                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv4sf_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv4sf_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_getmantv8df                        (rtx, rtx, rtx);
extern rtx        gen_avx512f_getmantv8df_round                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_getmantv8df_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_getmantv8df_mask_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv4df                       (rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv4df_round                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv4df_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv4df_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv2df                       (rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv2df_round                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv2df_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_getmantv2df_mask_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vgetmantv4sf                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vgetmantv4sf_round                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vgetmantv2df                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vgetmantv2df_round                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_dbpsadbwv8hi_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_dbpsadbwv16hi_mask                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_dbpsadbwv32hi_mask                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_clzv16si2                                  (rtx, rtx);
extern rtx        gen_clzv16si2_mask                             (rtx, rtx, rtx, rtx);
extern rtx        gen_clzv8si2                                   (rtx, rtx);
extern rtx        gen_clzv8si2_mask                              (rtx, rtx, rtx, rtx);
extern rtx        gen_clzv4si2                                   (rtx, rtx);
extern rtx        gen_clzv4si2_mask                              (rtx, rtx, rtx, rtx);
extern rtx        gen_clzv8di2                                   (rtx, rtx);
extern rtx        gen_clzv8di2_mask                              (rtx, rtx, rtx, rtx);
extern rtx        gen_clzv4di2                                   (rtx, rtx);
extern rtx        gen_clzv4di2_mask                              (rtx, rtx, rtx, rtx);
extern rtx        gen_clzv2di2                                   (rtx, rtx);
extern rtx        gen_clzv2di2_mask                              (rtx, rtx, rtx, rtx);
extern rtx        gen_conflictv16si_mask                         (rtx, rtx, rtx, rtx);
extern rtx        gen_conflictv8si_mask                          (rtx, rtx, rtx, rtx);
extern rtx        gen_conflictv4si_mask                          (rtx, rtx, rtx, rtx);
extern rtx        gen_conflictv8di_mask                          (rtx, rtx, rtx, rtx);
extern rtx        gen_conflictv4di_mask                          (rtx, rtx, rtx, rtx);
extern rtx        gen_conflictv2di_mask                          (rtx, rtx, rtx, rtx);
extern rtx        gen_sha1msg1                                   (rtx, rtx, rtx);
extern rtx        gen_sha1msg2                                   (rtx, rtx, rtx);
extern rtx        gen_sha1nexte                                  (rtx, rtx, rtx);
extern rtx        gen_sha1rnds4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_sha256msg1                                 (rtx, rtx, rtx);
extern rtx        gen_sha256msg2                                 (rtx, rtx, rtx);
extern rtx        gen_sha256rnds2                                (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_si512_si                           (rtx, rtx);
extern rtx        gen_avx512f_ps512_ps                           (rtx, rtx);
extern rtx        gen_avx512f_pd512_pd                           (rtx, rtx);
extern rtx        gen_avx512f_si512_256si                        (rtx, rtx);
extern rtx        gen_avx512f_ps512_256ps                        (rtx, rtx);
extern rtx        gen_avx512f_pd512_256pd                        (rtx, rtx);
extern rtx        gen_vpamdd52luqv8di                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52luqv8di_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52huqv8di                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52huqv8di_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52luqv4di                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52luqv4di_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52huqv4di                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52huqv4di_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52luqv2di                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52luqv2di_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52huqv2di                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52huqv2di_maskz_1                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52luqv8di_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52huqv8di_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52luqv4di_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52huqv4di_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52luqv2di_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52huqv2di_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpmultishiftqbv64qi                        (rtx, rtx, rtx);
extern rtx        gen_vpmultishiftqbv64qi_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpmultishiftqbv16qi                        (rtx, rtx, rtx);
extern rtx        gen_vpmultishiftqbv16qi_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpmultishiftqbv32qi                        (rtx, rtx, rtx);
extern rtx        gen_vpmultishiftqbv32qi_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mfence_sse2                                (rtx);
extern rtx        gen_mfence_nosse                               (rtx);
extern rtx        gen_atomic_loaddi_fpu                          (rtx, rtx, rtx);
extern rtx        gen_atomic_storeqi_1                           (rtx, rtx, rtx);
extern rtx        gen_atomic_storehi_1                           (rtx, rtx, rtx);
extern rtx        gen_atomic_storesi_1                           (rtx, rtx, rtx);
extern rtx        gen_atomic_storedi_1                           (rtx, rtx, rtx);
extern rtx        gen_atomic_storedi_fpu                         (rtx, rtx, rtx);
extern rtx        gen_loaddi_via_fpu                             (rtx, rtx);
extern rtx        gen_storedi_via_fpu                            (rtx, rtx);
extern rtx        gen_atomic_compare_and_swapdi_doubleword       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapti_doubleword       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapqi_1                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swaphi_1                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapsi_1                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapdi_1                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_addqi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_addhi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_addsi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_adddi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_exchangeqi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_exchangehi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_exchangesi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_exchangedi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_addqi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_addhi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_addsi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_adddi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_subqi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_subhi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_subsi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_subdi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_andqi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_orqi                                (rtx, rtx, rtx);
extern rtx        gen_atomic_xorqi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_andhi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_orhi                                (rtx, rtx, rtx);
extern rtx        gen_atomic_xorhi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_andsi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_orsi                                (rtx, rtx, rtx);
extern rtx        gen_atomic_xorsi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_anddi                               (rtx, rtx, rtx);
extern rtx        gen_atomic_ordi                                (rtx, rtx, rtx);
extern rtx        gen_atomic_xordi                               (rtx, rtx, rtx);
extern rtx        gen_cbranchqi4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchhi4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchsi4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchdi4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchti4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoreqi4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_cstorehi4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoresi4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoredi4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_cmpsi_1                                    (rtx, rtx);
extern rtx        gen_cmpdi_1                                    (rtx, rtx);
extern rtx        gen_cmpqi_ext_3                                (rtx, rtx);
extern rtx        gen_cbranchxf4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cstorexf4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchsf4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchdf4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoresf4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoredf4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchcc4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cstorecc4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_reload_noff_store                          (rtx, rtx, rtx);
extern rtx        gen_reload_noff_load                           (rtx, rtx, rtx);
extern rtx        gen_movxi                                      (rtx, rtx);
extern rtx        gen_movoi                                      (rtx, rtx);
extern rtx        gen_movti                                      (rtx, rtx);
extern rtx        gen_movcdi                                     (rtx, rtx);
extern rtx        gen_movqi                                      (rtx, rtx);
extern rtx        gen_movhi                                      (rtx, rtx);
extern rtx        gen_movsi                                      (rtx, rtx);
extern rtx        gen_movdi                                      (rtx, rtx);
extern rtx        gen_movstrictqi                                (rtx, rtx);
extern rtx        gen_movstricthi                                (rtx, rtx);
extern rtx        gen_extvhi                                     (rtx, rtx, rtx, rtx);
extern rtx        gen_extvsi                                     (rtx, rtx, rtx, rtx);
extern rtx        gen_extzvhi                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_extzvsi                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_extzvdi                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_insvhi                                     (rtx, rtx, rtx, rtx);
extern rtx        gen_insvsi                                     (rtx, rtx, rtx, rtx);
extern rtx        gen_insvdi                                     (rtx, rtx, rtx, rtx);
extern rtx        gen_movtf                                      (rtx, rtx);
extern rtx        gen_movsf                                      (rtx, rtx);
extern rtx        gen_movdf                                      (rtx, rtx);
extern rtx        gen_movxf                                      (rtx, rtx);
extern rtx        gen_zero_extendsidi2                           (rtx, rtx);
extern rtx        gen_zero_extendqisi2                           (rtx, rtx);
extern rtx        gen_zero_extendhisi2                           (rtx, rtx);
extern rtx        gen_zero_extendqihi2                           (rtx, rtx);
extern rtx        gen_extendsidi2                                (rtx, rtx);
extern rtx        gen_extendsfdf2                                (rtx, rtx);
extern rtx        gen_extendsfxf2                                (rtx, rtx);
extern rtx        gen_extenddfxf2                                (rtx, rtx);
extern rtx        gen_truncdfsf2                                 (rtx, rtx);
extern rtx        gen_truncdfsf2_with_temp                       (rtx, rtx, rtx);
extern rtx        gen_truncxfsf2                                 (rtx, rtx);
extern rtx        gen_truncxfdf2                                 (rtx, rtx);
extern rtx        gen_fix_truncxfdi2                             (rtx, rtx);
extern rtx        gen_fix_truncsfdi2                             (rtx, rtx);
extern rtx        gen_fix_truncdfdi2                             (rtx, rtx);
extern rtx        gen_fix_truncxfsi2                             (rtx, rtx);
extern rtx        gen_fix_truncsfsi2                             (rtx, rtx);
extern rtx        gen_fix_truncdfsi2                             (rtx, rtx);
extern rtx        gen_fix_truncsfhi2                             (rtx, rtx);
extern rtx        gen_fix_truncdfhi2                             (rtx, rtx);
extern rtx        gen_fix_truncxfhi2                             (rtx, rtx);
extern rtx        gen_fixuns_truncsfsi2                          (rtx, rtx);
extern rtx        gen_fixuns_truncdfsi2                          (rtx, rtx);
extern rtx        gen_fixuns_truncsfhi2                          (rtx, rtx);
extern rtx        gen_fixuns_truncdfhi2                          (rtx, rtx);
extern rtx        gen_floatsisf2                                 (rtx, rtx);
extern rtx        gen_floatdisf2                                 (rtx, rtx);
extern rtx        gen_floatsidf2                                 (rtx, rtx);
extern rtx        gen_floatdidf2                                 (rtx, rtx);
extern rtx        gen_floatunsqisf2                              (rtx, rtx);
extern rtx        gen_floatunshisf2                              (rtx, rtx);
extern rtx        gen_floatunsqidf2                              (rtx, rtx);
extern rtx        gen_floatunshidf2                              (rtx, rtx);
extern rtx        gen_floatunssisf2                              (rtx, rtx);
extern rtx        gen_floatunssidf2                              (rtx, rtx);
extern rtx        gen_floatunssixf2                              (rtx, rtx);
extern rtx        gen_floatunsdisf2                              (rtx, rtx);
extern rtx        gen_floatunsdidf2                              (rtx, rtx);
extern rtx        gen_addqi3                                     (rtx, rtx, rtx);
extern rtx        gen_addhi3                                     (rtx, rtx, rtx);
extern rtx        gen_addsi3                                     (rtx, rtx, rtx);
extern rtx        gen_adddi3                                     (rtx, rtx, rtx);
extern rtx        gen_addti3                                     (rtx, rtx, rtx);
extern rtx        gen_addvqi4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_addvhi4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_addvsi4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_addvdi4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_uaddvqi4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_uaddvhi4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_uaddvsi4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_uaddvdi4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_subqi3                                     (rtx, rtx, rtx);
extern rtx        gen_subhi3                                     (rtx, rtx, rtx);
extern rtx        gen_subsi3                                     (rtx, rtx, rtx);
extern rtx        gen_subdi3                                     (rtx, rtx, rtx);
extern rtx        gen_subti3                                     (rtx, rtx, rtx);
extern rtx        gen_subvqi4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_subvhi4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_subvsi4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_subvdi4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_usubvqi4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_usubvhi4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_usubvsi4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_usubvdi4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_addqi3_cconly_overflow                     (rtx, rtx);
extern rtx        gen_addxf3                                     (rtx, rtx, rtx);
extern rtx        gen_subxf3                                     (rtx, rtx, rtx);
extern rtx        gen_addsf3                                     (rtx, rtx, rtx);
extern rtx        gen_subsf3                                     (rtx, rtx, rtx);
extern rtx        gen_adddf3                                     (rtx, rtx, rtx);
extern rtx        gen_subdf3                                     (rtx, rtx, rtx);
extern rtx        gen_mulhi3                                     (rtx, rtx, rtx);
extern rtx        gen_mulsi3                                     (rtx, rtx, rtx);
extern rtx        gen_muldi3                                     (rtx, rtx, rtx);
extern rtx        gen_mulqi3                                     (rtx, rtx, rtx);
extern rtx        gen_mulvhi4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_mulvsi4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_mulvdi4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_umulvhi4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_umulvsi4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_umulvdi4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_mulvqi4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_umulvqi4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_mulsidi3                                   (rtx, rtx, rtx);
extern rtx        gen_umulsidi3                                  (rtx, rtx, rtx);
extern rtx        gen_mulditi3                                   (rtx, rtx, rtx);
extern rtx        gen_umulditi3                                  (rtx, rtx, rtx);
extern rtx        gen_mulqihi3                                   (rtx, rtx, rtx);
extern rtx        gen_umulqihi3                                  (rtx, rtx, rtx);
extern rtx        gen_smulsi3_highpart                           (rtx, rtx, rtx);
extern rtx        gen_umulsi3_highpart                           (rtx, rtx, rtx);
extern rtx        gen_smuldi3_highpart                           (rtx, rtx, rtx);
extern rtx        gen_umuldi3_highpart                           (rtx, rtx, rtx);
extern rtx        gen_mulxf3                                     (rtx, rtx, rtx);
extern rtx        gen_mulsf3                                     (rtx, rtx, rtx);
extern rtx        gen_muldf3                                     (rtx, rtx, rtx);
extern rtx        gen_divxf3                                     (rtx, rtx, rtx);
extern rtx        gen_divdf3                                     (rtx, rtx, rtx);
extern rtx        gen_divsf3                                     (rtx, rtx, rtx);
extern rtx        gen_divmodhi4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_divmodsi4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_divmoddi4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_divmodqi4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_udivmodhi4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_udivmodsi4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_udivmoddi4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_udivmodqi4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_testsi_ccno_1                              (rtx, rtx);
extern rtx        gen_testqi_ccz_1                               (rtx, rtx);
extern rtx        gen_testdi_ccno_1                              (rtx, rtx);
extern rtx        gen_testqi_ext_ccno_0                          (rtx, rtx);
extern rtx        gen_andqi3                                     (rtx, rtx, rtx);
extern rtx        gen_andhi3                                     (rtx, rtx, rtx);
extern rtx        gen_andsi3                                     (rtx, rtx, rtx);
extern rtx        gen_anddi3                                     (rtx, rtx, rtx);
extern rtx        gen_iorqi3                                     (rtx, rtx, rtx);
extern rtx        gen_xorqi3                                     (rtx, rtx, rtx);
extern rtx        gen_iorhi3                                     (rtx, rtx, rtx);
extern rtx        gen_xorhi3                                     (rtx, rtx, rtx);
extern rtx        gen_iorsi3                                     (rtx, rtx, rtx);
extern rtx        gen_xorsi3                                     (rtx, rtx, rtx);
extern rtx        gen_iordi3                                     (rtx, rtx, rtx);
extern rtx        gen_xordi3                                     (rtx, rtx, rtx);
extern rtx        gen_xorqi_cc_ext_1                             (rtx, rtx, rtx);
extern rtx        gen_negqi2                                     (rtx, rtx);
extern rtx        gen_neghi2                                     (rtx, rtx);
extern rtx        gen_negsi2                                     (rtx, rtx);
extern rtx        gen_negdi2                                     (rtx, rtx);
extern rtx        gen_negti2                                     (rtx, rtx);
extern rtx        gen_negvqi3                                    (rtx, rtx, rtx);
extern rtx        gen_negvhi3                                    (rtx, rtx, rtx);
extern rtx        gen_negvsi3                                    (rtx, rtx, rtx);
extern rtx        gen_negvdi3                                    (rtx, rtx, rtx);
extern rtx        gen_abssf2                                     (rtx, rtx);
extern rtx        gen_negsf2                                     (rtx, rtx);
extern rtx        gen_absdf2                                     (rtx, rtx);
extern rtx        gen_negdf2                                     (rtx, rtx);
extern rtx        gen_absxf2                                     (rtx, rtx);
extern rtx        gen_negxf2                                     (rtx, rtx);
extern rtx        gen_abstf2                                     (rtx, rtx);
extern rtx        gen_negtf2                                     (rtx, rtx);
extern rtx        gen_copysignsf3                                (rtx, rtx, rtx);
extern rtx        gen_copysigndf3                                (rtx, rtx, rtx);
extern rtx        gen_copysigntf3                                (rtx, rtx, rtx);
extern rtx        gen_one_cmplqi2                                (rtx, rtx);
extern rtx        gen_one_cmplhi2                                (rtx, rtx);
extern rtx        gen_one_cmplsi2                                (rtx, rtx);
extern rtx        gen_one_cmpldi2                                (rtx, rtx);
extern rtx        gen_ashlqi3                                    (rtx, rtx, rtx);
extern rtx        gen_ashlhi3                                    (rtx, rtx, rtx);
extern rtx        gen_ashlsi3                                    (rtx, rtx, rtx);
extern rtx        gen_ashldi3                                    (rtx, rtx, rtx);
extern rtx        gen_ashlti3                                    (rtx, rtx, rtx);
extern rtx        gen_x86_shiftsi_adj_1                          (rtx, rtx, rtx, rtx);
extern rtx        gen_x86_shiftdi_adj_1                          (rtx, rtx, rtx, rtx);
extern rtx        gen_x86_shiftsi_adj_2                          (rtx, rtx, rtx);
extern rtx        gen_x86_shiftdi_adj_2                          (rtx, rtx, rtx);
extern rtx        gen_lshrqi3                                    (rtx, rtx, rtx);
extern rtx        gen_ashrqi3                                    (rtx, rtx, rtx);
extern rtx        gen_lshrhi3                                    (rtx, rtx, rtx);
extern rtx        gen_ashrhi3                                    (rtx, rtx, rtx);
extern rtx        gen_lshrsi3                                    (rtx, rtx, rtx);
extern rtx        gen_ashrsi3                                    (rtx, rtx, rtx);
extern rtx        gen_lshrdi3                                    (rtx, rtx, rtx);
extern rtx        gen_ashrdi3                                    (rtx, rtx, rtx);
extern rtx        gen_lshrti3                                    (rtx, rtx, rtx);
extern rtx        gen_ashrti3                                    (rtx, rtx, rtx);
extern rtx        gen_x86_shiftsi_adj_3                          (rtx, rtx, rtx);
extern rtx        gen_x86_shiftdi_adj_3                          (rtx, rtx, rtx);
extern rtx        gen_rotlti3                                    (rtx, rtx, rtx);
extern rtx        gen_rotrti3                                    (rtx, rtx, rtx);
extern rtx        gen_rotldi3                                    (rtx, rtx, rtx);
extern rtx        gen_rotrdi3                                    (rtx, rtx, rtx);
extern rtx        gen_rotlqi3                                    (rtx, rtx, rtx);
extern rtx        gen_rotrqi3                                    (rtx, rtx, rtx);
extern rtx        gen_rotlhi3                                    (rtx, rtx, rtx);
extern rtx        gen_rotrhi3                                    (rtx, rtx, rtx);
extern rtx        gen_rotlsi3                                    (rtx, rtx, rtx);
extern rtx        gen_rotrsi3                                    (rtx, rtx, rtx);
extern rtx        gen_indirect_jump                              (rtx);
extern rtx        gen_tablejump                                  (rtx, rtx);
extern rtx        gen_call                                       (rtx, rtx, rtx);
extern rtx        gen_sibcall                                    (rtx, rtx, rtx);
extern rtx        gen_call_pop                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_call_value                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_sibcall_value                              (rtx, rtx, rtx, rtx);
extern rtx        gen_call_value_pop                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_untyped_call                               (rtx, rtx, rtx);
extern rtx        gen_memory_blockage                            (void);
extern rtx        gen_return                                     (void);
extern rtx        gen_simple_return                              (void);
extern rtx        gen_prologue                                   (void);
extern rtx        gen_set_got                                    (rtx);
extern rtx        gen_set_got_labelled                           (rtx, rtx);
extern rtx        gen_epilogue                                   (void);
extern rtx        gen_sibcall_epilogue                           (void);
extern rtx        gen_eh_return                                  (rtx);
extern rtx        gen_split_stack_prologue                       (void);
extern rtx        gen_split_stack_space_check                    (rtx, rtx);
extern rtx        gen_ffssi2                                     (rtx, rtx);
extern rtx        gen_ffsdi2                                     (rtx, rtx);
extern rtx        gen_ctzhi2                                     (rtx, rtx);
extern rtx        gen_ctzsi2                                     (rtx, rtx);
extern rtx        gen_ctzdi2                                     (rtx, rtx);
extern rtx        gen_clzhi2                                     (rtx, rtx);
extern rtx        gen_clzsi2                                     (rtx, rtx);
extern rtx        gen_clzdi2                                     (rtx, rtx);
extern rtx        gen_clzhi2_lzcnt                               (rtx, rtx);
extern rtx        gen_clzsi2_lzcnt                               (rtx, rtx);
extern rtx        gen_clzdi2_lzcnt                               (rtx, rtx);
extern rtx        gen_bmi2_bzhi_si3                              (rtx, rtx, rtx);
extern rtx        gen_bmi2_bzhi_di3                              (rtx, rtx, rtx);
extern rtx        gen_popcounthi2                                (rtx, rtx);
extern rtx        gen_popcountsi2                                (rtx, rtx);
extern rtx        gen_popcountdi2                                (rtx, rtx);
extern rtx        gen_bswapdi2                                   (rtx, rtx);
extern rtx        gen_bswapsi2                                   (rtx, rtx);
extern rtx        gen_paritydi2                                  (rtx, rtx);
extern rtx        gen_paritysi2                                  (rtx, rtx);
extern rtx        gen_tls_global_dynamic_32                      (rtx, rtx, rtx, rtx);
extern rtx        gen_tls_global_dynamic_64_si                   (rtx, rtx, rtx);
extern rtx        gen_tls_global_dynamic_64_di                   (rtx, rtx, rtx);
extern rtx        gen_tls_local_dynamic_base_32                  (rtx, rtx, rtx);
extern rtx        gen_tls_local_dynamic_base_64_si               (rtx, rtx);
extern rtx        gen_tls_local_dynamic_base_64_di               (rtx, rtx);
extern rtx        gen_tls_dynamic_gnu2_32                        (rtx, rtx, rtx);
extern rtx        gen_tls_dynamic_gnu2_64                        (rtx, rtx);
extern rtx        gen_rsqrtsf2                                   (rtx, rtx);
extern rtx        gen_sqrtsf2                                    (rtx, rtx);
extern rtx        gen_sqrtdf2                                    (rtx, rtx);
extern rtx        gen_fmodxf3                                    (rtx, rtx, rtx);
extern rtx        gen_fmodsf3                                    (rtx, rtx, rtx);
extern rtx        gen_fmoddf3                                    (rtx, rtx, rtx);
extern rtx        gen_remainderxf3                               (rtx, rtx, rtx);
extern rtx        gen_remaindersf3                               (rtx, rtx, rtx);
extern rtx        gen_remainderdf3                               (rtx, rtx, rtx);
extern rtx        gen_sincossf3                                  (rtx, rtx, rtx);
extern rtx        gen_sincosdf3                                  (rtx, rtx, rtx);
extern rtx        gen_tanxf2                                     (rtx, rtx);
extern rtx        gen_tansf2                                     (rtx, rtx);
extern rtx        gen_tandf2                                     (rtx, rtx);
extern rtx        gen_atan2xf3                                   (rtx, rtx, rtx);
extern rtx        gen_atan2sf3                                   (rtx, rtx, rtx);
extern rtx        gen_atan2df3                                   (rtx, rtx, rtx);
extern rtx        gen_atanxf2                                    (rtx, rtx);
extern rtx        gen_atansf2                                    (rtx, rtx);
extern rtx        gen_atandf2                                    (rtx, rtx);
extern rtx        gen_asinxf2                                    (rtx, rtx);
extern rtx        gen_asinsf2                                    (rtx, rtx);
extern rtx        gen_asindf2                                    (rtx, rtx);
extern rtx        gen_acosxf2                                    (rtx, rtx);
extern rtx        gen_acossf2                                    (rtx, rtx);
extern rtx        gen_acosdf2                                    (rtx, rtx);
extern rtx        gen_logxf2                                     (rtx, rtx);
extern rtx        gen_logsf2                                     (rtx, rtx);
extern rtx        gen_logdf2                                     (rtx, rtx);
extern rtx        gen_log10xf2                                   (rtx, rtx);
extern rtx        gen_log10sf2                                   (rtx, rtx);
extern rtx        gen_log10df2                                   (rtx, rtx);
extern rtx        gen_log2xf2                                    (rtx, rtx);
extern rtx        gen_log2sf2                                    (rtx, rtx);
extern rtx        gen_log2df2                                    (rtx, rtx);
extern rtx        gen_log1pxf2                                   (rtx, rtx);
extern rtx        gen_log1psf2                                   (rtx, rtx);
extern rtx        gen_log1pdf2                                   (rtx, rtx);
extern rtx        gen_logbxf2                                    (rtx, rtx);
extern rtx        gen_logbsf2                                    (rtx, rtx);
extern rtx        gen_logbdf2                                    (rtx, rtx);
extern rtx        gen_ilogbxf2                                   (rtx, rtx);
extern rtx        gen_ilogbsf2                                   (rtx, rtx);
extern rtx        gen_ilogbdf2                                   (rtx, rtx);
extern rtx        gen_expNcorexf3                                (rtx, rtx, rtx);
extern rtx        gen_expxf2                                     (rtx, rtx);
extern rtx        gen_expsf2                                     (rtx, rtx);
extern rtx        gen_expdf2                                     (rtx, rtx);
extern rtx        gen_exp10xf2                                   (rtx, rtx);
extern rtx        gen_exp10sf2                                   (rtx, rtx);
extern rtx        gen_exp10df2                                   (rtx, rtx);
extern rtx        gen_exp2xf2                                    (rtx, rtx);
extern rtx        gen_exp2sf2                                    (rtx, rtx);
extern rtx        gen_exp2df2                                    (rtx, rtx);
extern rtx        gen_expm1xf2                                   (rtx, rtx);
extern rtx        gen_expm1sf2                                   (rtx, rtx);
extern rtx        gen_expm1df2                                   (rtx, rtx);
extern rtx        gen_ldexpxf3                                   (rtx, rtx, rtx);
extern rtx        gen_ldexpsf3                                   (rtx, rtx, rtx);
extern rtx        gen_ldexpdf3                                   (rtx, rtx, rtx);
extern rtx        gen_scalbxf3                                   (rtx, rtx, rtx);
extern rtx        gen_scalbsf3                                   (rtx, rtx, rtx);
extern rtx        gen_scalbdf3                                   (rtx, rtx, rtx);
extern rtx        gen_significandxf2                             (rtx, rtx);
extern rtx        gen_significandsf2                             (rtx, rtx);
extern rtx        gen_significanddf2                             (rtx, rtx);
extern rtx        gen_rintsf2                                    (rtx, rtx);
extern rtx        gen_rintdf2                                    (rtx, rtx);
extern rtx        gen_roundsf2                                   (rtx, rtx);
extern rtx        gen_rounddf2                                   (rtx, rtx);
extern rtx        gen_roundxf2                                   (rtx, rtx);
extern rtx        gen_lrintxfhi2                                 (rtx, rtx);
extern rtx        gen_lrintxfsi2                                 (rtx, rtx);
extern rtx        gen_lrintxfdi2                                 (rtx, rtx);
extern rtx        gen_lrintsfsi2                                 (rtx, rtx);
extern rtx        gen_lrintsfdi2                                 (rtx, rtx);
extern rtx        gen_lrintdfsi2                                 (rtx, rtx);
extern rtx        gen_lrintdfdi2                                 (rtx, rtx);
extern rtx        gen_lroundsfhi2                                (rtx, rtx);
extern rtx        gen_lrounddfhi2                                (rtx, rtx);
extern rtx        gen_lroundxfhi2                                (rtx, rtx);
extern rtx        gen_lroundsfsi2                                (rtx, rtx);
extern rtx        gen_lrounddfsi2                                (rtx, rtx);
extern rtx        gen_lroundxfsi2                                (rtx, rtx);
extern rtx        gen_lroundsfdi2                                (rtx, rtx);
extern rtx        gen_lrounddfdi2                                (rtx, rtx);
extern rtx        gen_lroundxfdi2                                (rtx, rtx);
extern rtx        gen_floorxf2                                   (rtx, rtx);
extern rtx        gen_ceilxf2                                    (rtx, rtx);
extern rtx        gen_btruncxf2                                  (rtx, rtx);
extern rtx        gen_floorsf2                                   (rtx, rtx);
extern rtx        gen_ceilsf2                                    (rtx, rtx);
extern rtx        gen_btruncsf2                                  (rtx, rtx);
extern rtx        gen_floordf2                                   (rtx, rtx);
extern rtx        gen_ceildf2                                    (rtx, rtx);
extern rtx        gen_btruncdf2                                  (rtx, rtx);
extern rtx        gen_nearbyintxf2                               (rtx, rtx);
extern rtx        gen_nearbyintsf2                               (rtx, rtx);
extern rtx        gen_nearbyintdf2                               (rtx, rtx);
extern rtx        gen_lfloorxfhi2                                (rtx, rtx);
extern rtx        gen_lceilxfhi2                                 (rtx, rtx);
extern rtx        gen_lfloorxfsi2                                (rtx, rtx);
extern rtx        gen_lceilxfsi2                                 (rtx, rtx);
extern rtx        gen_lfloorxfdi2                                (rtx, rtx);
extern rtx        gen_lceilxfdi2                                 (rtx, rtx);
extern rtx        gen_lfloorsfsi2                                (rtx, rtx);
extern rtx        gen_lceilsfsi2                                 (rtx, rtx);
extern rtx        gen_lfloorsfdi2                                (rtx, rtx);
extern rtx        gen_lceilsfdi2                                 (rtx, rtx);
extern rtx        gen_lfloordfsi2                                (rtx, rtx);
extern rtx        gen_lceildfsi2                                 (rtx, rtx);
extern rtx        gen_lfloordfdi2                                (rtx, rtx);
extern rtx        gen_lceildfdi2                                 (rtx, rtx);
extern rtx        gen_isinfxf2                                   (rtx, rtx);
extern rtx        gen_isinfsf2                                   (rtx, rtx);
extern rtx        gen_isinfdf2                                   (rtx, rtx);
extern rtx        gen_signbitxf2                                 (rtx, rtx);
extern rtx        gen_signbitdf2                                 (rtx, rtx);
extern rtx        gen_signbitsf2                                 (rtx, rtx);
extern rtx        gen_movmemsi                                   (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_movmemdi                                   (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_strmov                                     (rtx, rtx, rtx, rtx);
extern rtx        gen_strmov_singleop                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_rep_mov                                    (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_setmemsi                                   (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_setmemdi                                   (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_strset                                     (rtx, rtx, rtx);
extern rtx        gen_strset_singleop                            (rtx, rtx, rtx, rtx);
extern rtx        gen_rep_stos                                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_cmpstrnsi                                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_cmpintqi                                   (rtx);
extern rtx        gen_cmpstrnqi_nz_1                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_cmpstrnqi_1                                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_strlensi                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_strlendi                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_strlenqi_1                                 (rtx, rtx, rtx);
extern rtx        gen_movqicc                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_movhicc                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_movsicc                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_movdicc                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_x86_movsicc_0_m1                           (rtx, rtx, rtx);
extern rtx        gen_x86_movdicc_0_m1                           (rtx, rtx, rtx);
extern rtx        gen_movsfcc                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_movdfcc                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_movxfcc                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_addqicc                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_addhicc                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_addsicc                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_adddicc                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_allocate_stack                             (rtx, rtx);
extern rtx        gen_probe_stack                                (rtx);
extern rtx        gen_builtin_setjmp_receiver                    (rtx);
extern rtx        gen_prefetch                                   (rtx, rtx, rtx);
extern rtx        gen_stack_protect_set                          (rtx, rtx);
extern rtx        gen_stack_protect_test                         (rtx, rtx, rtx);
extern rtx        gen_lwp_llwpcb                                 (rtx);
extern rtx        gen_lwp_slwpcb                                 (rtx);
extern rtx        gen_lwp_lwpvalsi3                              (rtx, rtx, rtx, rtx);
extern rtx        gen_lwp_lwpvaldi3                              (rtx, rtx, rtx, rtx);
extern rtx        gen_lwp_lwpinssi3                              (rtx, rtx, rtx, rtx);
extern rtx        gen_lwp_lwpinsdi3                              (rtx, rtx, rtx, rtx);
extern rtx        gen_pause                                      (void);
extern rtx        gen_xbegin                                     (rtx);
extern rtx        gen_xtest                                      (rtx);
extern rtx        gen_bnd32_mk                                   (rtx, rtx, rtx);
extern rtx        gen_bnd64_mk                                   (rtx, rtx, rtx);
extern rtx        gen_movbnd32                                   (rtx, rtx);
extern rtx        gen_movbnd64                                   (rtx, rtx);
extern rtx        gen_bnd32_cl                                   (rtx, rtx);
extern rtx        gen_bnd32_cu                                   (rtx, rtx);
extern rtx        gen_bnd32_cn                                   (rtx, rtx);
extern rtx        gen_bnd64_cl                                   (rtx, rtx);
extern rtx        gen_bnd64_cu                                   (rtx, rtx);
extern rtx        gen_bnd64_cn                                   (rtx, rtx);
extern rtx        gen_bnd32_ldx                                  (rtx, rtx, rtx);
extern rtx        gen_bnd64_ldx                                  (rtx, rtx, rtx);
extern rtx        gen_bnd32_stx                                  (rtx, rtx, rtx);
extern rtx        gen_bnd64_stx                                  (rtx, rtx, rtx);
extern rtx        gen_rdpkru                                     (rtx);
extern rtx        gen_wrpkru                                     (rtx);
extern rtx        gen_movv8qi                                    (rtx, rtx);
extern rtx        gen_movv4hi                                    (rtx, rtx);
extern rtx        gen_movv2si                                    (rtx, rtx);
extern rtx        gen_movv1di                                    (rtx, rtx);
extern rtx        gen_movv2sf                                    (rtx, rtx);
extern rtx        gen_movmisalignv8qi                            (rtx, rtx);
extern rtx        gen_movmisalignv4hi                            (rtx, rtx);
extern rtx        gen_movmisalignv2si                            (rtx, rtx);
extern rtx        gen_movmisalignv1di                            (rtx, rtx);
extern rtx        gen_movmisalignv2sf                            (rtx, rtx);
extern rtx        gen_mmx_addv2sf3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_subv2sf3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_subrv2sf3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_mulv2sf3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_smaxv2sf3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_sminv2sf3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_eqv2sf3                                (rtx, rtx, rtx);
extern rtx        gen_vec_setv2sf                                (rtx, rtx, rtx);
extern rtx        gen_vec_extractv2sf                            (rtx, rtx, rtx);
extern rtx        gen_vec_initv2sf                               (rtx, rtx);
extern rtx        gen_mmx_addv8qi3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_subv8qi3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_addv4hi3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_subv4hi3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_addv2si3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_subv2si3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_addv1di3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_subv1di3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_ssaddv8qi3                             (rtx, rtx, rtx);
extern rtx        gen_mmx_usaddv8qi3                             (rtx, rtx, rtx);
extern rtx        gen_mmx_sssubv8qi3                             (rtx, rtx, rtx);
extern rtx        gen_mmx_ussubv8qi3                             (rtx, rtx, rtx);
extern rtx        gen_mmx_ssaddv4hi3                             (rtx, rtx, rtx);
extern rtx        gen_mmx_usaddv4hi3                             (rtx, rtx, rtx);
extern rtx        gen_mmx_sssubv4hi3                             (rtx, rtx, rtx);
extern rtx        gen_mmx_ussubv4hi3                             (rtx, rtx, rtx);
extern rtx        gen_mmx_mulv4hi3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_smulv4hi3_highpart                     (rtx, rtx, rtx);
extern rtx        gen_mmx_umulv4hi3_highpart                     (rtx, rtx, rtx);
extern rtx        gen_mmx_pmaddwd                                (rtx, rtx, rtx);
extern rtx        gen_mmx_pmulhrwv4hi3                           (rtx, rtx, rtx);
extern rtx        gen_sse2_umulv1siv1di3                         (rtx, rtx, rtx);
extern rtx        gen_mmx_smaxv4hi3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_sminv4hi3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_umaxv8qi3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_uminv8qi3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_eqv8qi3                                (rtx, rtx, rtx);
extern rtx        gen_mmx_eqv4hi3                                (rtx, rtx, rtx);
extern rtx        gen_mmx_eqv2si3                                (rtx, rtx, rtx);
extern rtx        gen_mmx_andv8qi3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_iorv8qi3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_xorv8qi3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_andv4hi3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_iorv4hi3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_xorv4hi3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_andv2si3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_iorv2si3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_xorv2si3                               (rtx, rtx, rtx);
extern rtx        gen_mmx_pinsrw                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_mmx_pshufw                                 (rtx, rtx, rtx);
extern rtx        gen_vec_setv2si                                (rtx, rtx, rtx);
extern rtx        gen_vec_extractv2si                            (rtx, rtx, rtx);
extern rtx        gen_vec_initv2si                               (rtx, rtx);
extern rtx        gen_vec_setv4hi                                (rtx, rtx, rtx);
extern rtx        gen_vec_extractv4hi                            (rtx, rtx, rtx);
extern rtx        gen_vec_initv4hi                               (rtx, rtx);
extern rtx        gen_vec_setv8qi                                (rtx, rtx, rtx);
extern rtx        gen_vec_extractv8qi                            (rtx, rtx, rtx);
extern rtx        gen_vec_initv8qi                               (rtx, rtx);
extern rtx        gen_mmx_uavgv8qi3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_uavgv4hi3                              (rtx, rtx, rtx);
extern rtx        gen_mmx_maskmovq                               (rtx, rtx, rtx);
extern rtx        gen_mmx_emms                                   (void);
extern rtx        gen_mmx_femms                                  (void);
extern rtx        gen_movv64qi                                   (rtx, rtx);
extern rtx        gen_movv32qi                                   (rtx, rtx);
extern rtx        gen_movv16qi                                   (rtx, rtx);
extern rtx        gen_movv32hi                                   (rtx, rtx);
extern rtx        gen_movv16hi                                   (rtx, rtx);
extern rtx        gen_movv8hi                                    (rtx, rtx);
extern rtx        gen_movv16si                                   (rtx, rtx);
extern rtx        gen_movv8si                                    (rtx, rtx);
extern rtx        gen_movv4si                                    (rtx, rtx);
extern rtx        gen_movv8di                                    (rtx, rtx);
extern rtx        gen_movv4di                                    (rtx, rtx);
extern rtx        gen_movv2di                                    (rtx, rtx);
extern rtx        gen_movv4ti                                    (rtx, rtx);
extern rtx        gen_movv2ti                                    (rtx, rtx);
extern rtx        gen_movv1ti                                    (rtx, rtx);
extern rtx        gen_movv16sf                                   (rtx, rtx);
extern rtx        gen_movv8sf                                    (rtx, rtx);
extern rtx        gen_movv4sf                                    (rtx, rtx);
extern rtx        gen_movv8df                                    (rtx, rtx);
extern rtx        gen_movv4df                                    (rtx, rtx);
extern rtx        gen_movv2df                                    (rtx, rtx);
extern rtx        gen_movmisalignv64qi                           (rtx, rtx);
extern rtx        gen_movmisalignv32qi                           (rtx, rtx);
extern rtx        gen_movmisalignv16qi                           (rtx, rtx);
extern rtx        gen_movmisalignv32hi                           (rtx, rtx);
extern rtx        gen_movmisalignv16hi                           (rtx, rtx);
extern rtx        gen_movmisalignv8hi                            (rtx, rtx);
extern rtx        gen_movmisalignv16si                           (rtx, rtx);
extern rtx        gen_movmisalignv8si                            (rtx, rtx);
extern rtx        gen_movmisalignv4si                            (rtx, rtx);
extern rtx        gen_movmisalignv8di                            (rtx, rtx);
extern rtx        gen_movmisalignv4di                            (rtx, rtx);
extern rtx        gen_movmisalignv2di                            (rtx, rtx);
extern rtx        gen_movmisalignv4ti                            (rtx, rtx);
extern rtx        gen_movmisalignv2ti                            (rtx, rtx);
extern rtx        gen_movmisalignv1ti                            (rtx, rtx);
extern rtx        gen_movmisalignv16sf                           (rtx, rtx);
extern rtx        gen_movmisalignv8sf                            (rtx, rtx);
extern rtx        gen_movmisalignv4sf                            (rtx, rtx);
extern rtx        gen_movmisalignv8df                            (rtx, rtx);
extern rtx        gen_movmisalignv4df                            (rtx, rtx);
extern rtx        gen_movmisalignv2df                            (rtx, rtx);
extern rtx        gen_avx512f_loadups512                         (rtx, rtx);
extern rtx        gen_avx512f_loadups512_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_loadups256                             (rtx, rtx);
extern rtx        gen_avx_loadups256_mask                        (rtx, rtx, rtx, rtx);
extern rtx        gen_sse_loadups                                (rtx, rtx);
extern rtx        gen_sse_loadups_mask                           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_loadupd512                         (rtx, rtx);
extern rtx        gen_avx512f_loadupd512_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_loadupd256                             (rtx, rtx);
extern rtx        gen_avx_loadupd256_mask                        (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_loadupd                               (rtx, rtx);
extern rtx        gen_sse2_loadupd_mask                          (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_loaddquv32qi                           (rtx, rtx);
extern rtx        gen_avx_loaddquv32qi_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_loaddquv16qi                          (rtx, rtx);
extern rtx        gen_sse2_loaddquv16qi_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_loaddquv64qi                       (rtx, rtx);
extern rtx        gen_avx512f_loaddquv64qi_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_loaddquv32hi                      (rtx, rtx);
extern rtx        gen_avx512bw_loaddquv32hi_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loaddquv8hi                       (rtx, rtx);
extern rtx        gen_avx512vl_loaddquv8hi_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loaddquv16hi                      (rtx, rtx);
extern rtx        gen_avx512vl_loaddquv16hi_mask                 (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_loaddquv16si                       (rtx, rtx);
extern rtx        gen_avx512f_loaddquv16si_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_loaddquv8si                            (rtx, rtx);
extern rtx        gen_avx_loaddquv8si_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_loaddquv4si                           (rtx, rtx);
extern rtx        gen_sse2_loaddquv4si_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_loaddquv8di                        (rtx, rtx);
extern rtx        gen_avx512f_loaddquv8di_mask                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loaddquv4di                       (rtx, rtx);
extern rtx        gen_avx512vl_loaddquv4di_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_loaddquv2di                       (rtx, rtx);
extern rtx        gen_avx512vl_loaddquv2di_mask                  (rtx, rtx, rtx, rtx);
extern rtx        gen_storentdi                                  (rtx, rtx);
extern rtx        gen_storentsi                                  (rtx, rtx);
extern rtx        gen_storentsf                                  (rtx, rtx);
extern rtx        gen_storentdf                                  (rtx, rtx);
extern rtx        gen_storentv8di                                (rtx, rtx);
extern rtx        gen_storentv4di                                (rtx, rtx);
extern rtx        gen_storentv2di                                (rtx, rtx);
extern rtx        gen_storentv16sf                               (rtx, rtx);
extern rtx        gen_storentv8sf                                (rtx, rtx);
extern rtx        gen_storentv4sf                                (rtx, rtx);
extern rtx        gen_storentv8df                                (rtx, rtx);
extern rtx        gen_storentv4df                                (rtx, rtx);
extern rtx        gen_storentv2df                                (rtx, rtx);
extern rtx        gen_absv16sf2                                  (rtx, rtx);
extern rtx        gen_negv16sf2                                  (rtx, rtx);
extern rtx        gen_absv8sf2                                   (rtx, rtx);
extern rtx        gen_negv8sf2                                   (rtx, rtx);
extern rtx        gen_absv4sf2                                   (rtx, rtx);
extern rtx        gen_negv4sf2                                   (rtx, rtx);
extern rtx        gen_absv8df2                                   (rtx, rtx);
extern rtx        gen_negv8df2                                   (rtx, rtx);
extern rtx        gen_absv4df2                                   (rtx, rtx);
extern rtx        gen_negv4df2                                   (rtx, rtx);
extern rtx        gen_absv2df2                                   (rtx, rtx);
extern rtx        gen_negv2df2                                   (rtx, rtx);
extern rtx        gen_addv16sf3                                  (rtx, rtx, rtx);
extern rtx        gen_addv16sf3_round                            (rtx, rtx, rtx, rtx);
extern rtx        gen_addv16sf3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv16sf3_mask_round                       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv16sf3                                  (rtx, rtx, rtx);
extern rtx        gen_subv16sf3_round                            (rtx, rtx, rtx, rtx);
extern rtx        gen_subv16sf3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv16sf3_mask_round                       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv8sf3                                   (rtx, rtx, rtx);
static inline rtx gen_addv8sf3_round                             (rtx, rtx, rtx, rtx);
static inline rtx
gen_addv8sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_addv8sf3_mask                              (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_addv8sf3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_addv8sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_subv8sf3                                   (rtx, rtx, rtx);
static inline rtx gen_subv8sf3_round                             (rtx, rtx, rtx, rtx);
static inline rtx
gen_subv8sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_subv8sf3_mask                              (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_subv8sf3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_subv8sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_addv4sf3                                   (rtx, rtx, rtx);
static inline rtx gen_addv4sf3_round                             (rtx, rtx, rtx, rtx);
static inline rtx
gen_addv4sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_addv4sf3_mask                              (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_addv4sf3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_addv4sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_subv4sf3                                   (rtx, rtx, rtx);
static inline rtx gen_subv4sf3_round                             (rtx, rtx, rtx, rtx);
static inline rtx
gen_subv4sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_subv4sf3_mask                              (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_subv4sf3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_subv4sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_addv8df3                                   (rtx, rtx, rtx);
extern rtx        gen_addv8df3_round                             (rtx, rtx, rtx, rtx);
extern rtx        gen_addv8df3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv8df3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv8df3                                   (rtx, rtx, rtx);
extern rtx        gen_subv8df3_round                             (rtx, rtx, rtx, rtx);
extern rtx        gen_subv8df3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv8df3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv4df3                                   (rtx, rtx, rtx);
static inline rtx gen_addv4df3_round                             (rtx, rtx, rtx, rtx);
static inline rtx
gen_addv4df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_addv4df3_mask                              (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_addv4df3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_addv4df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_subv4df3                                   (rtx, rtx, rtx);
static inline rtx gen_subv4df3_round                             (rtx, rtx, rtx, rtx);
static inline rtx
gen_subv4df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_subv4df3_mask                              (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_subv4df3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_subv4df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_addv2df3                                   (rtx, rtx, rtx);
static inline rtx gen_addv2df3_round                             (rtx, rtx, rtx, rtx);
static inline rtx
gen_addv2df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_addv2df3_mask                              (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_addv2df3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_addv2df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_subv2df3                                   (rtx, rtx, rtx);
static inline rtx gen_subv2df3_round                             (rtx, rtx, rtx, rtx);
static inline rtx
gen_subv2df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_subv2df3_mask                              (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_subv2df3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_subv2df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_mulv16sf3                                  (rtx, rtx, rtx);
extern rtx        gen_mulv16sf3_round                            (rtx, rtx, rtx, rtx);
extern rtx        gen_mulv16sf3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulv16sf3_mask_round                       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulv8sf3                                   (rtx, rtx, rtx);
static inline rtx gen_mulv8sf3_round                             (rtx, rtx, rtx, rtx);
static inline rtx
gen_mulv8sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_mulv8sf3_mask                              (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_mulv8sf3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_mulv8sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_mulv4sf3                                   (rtx, rtx, rtx);
static inline rtx gen_mulv4sf3_round                             (rtx, rtx, rtx, rtx);
static inline rtx
gen_mulv4sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_mulv4sf3_mask                              (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_mulv4sf3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_mulv4sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_mulv8df3                                   (rtx, rtx, rtx);
extern rtx        gen_mulv8df3_round                             (rtx, rtx, rtx, rtx);
extern rtx        gen_mulv8df3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulv8df3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulv4df3                                   (rtx, rtx, rtx);
static inline rtx gen_mulv4df3_round                             (rtx, rtx, rtx, rtx);
static inline rtx
gen_mulv4df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_mulv4df3_mask                              (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_mulv4df3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_mulv4df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_mulv2df3                                   (rtx, rtx, rtx);
static inline rtx gen_mulv2df3_round                             (rtx, rtx, rtx, rtx);
static inline rtx
gen_mulv2df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_mulv2df3_mask                              (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_mulv2df3_mask_round                        (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_mulv2df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_divv8df3                                   (rtx, rtx, rtx);
extern rtx        gen_divv4df3                                   (rtx, rtx, rtx);
extern rtx        gen_divv2df3                                   (rtx, rtx, rtx);
extern rtx        gen_divv16sf3                                  (rtx, rtx, rtx);
extern rtx        gen_divv8sf3                                   (rtx, rtx, rtx);
extern rtx        gen_divv4sf3                                   (rtx, rtx, rtx);
extern rtx        gen_sqrtv8df2                                  (rtx, rtx);
extern rtx        gen_sqrtv4df2                                  (rtx, rtx);
extern rtx        gen_sqrtv2df2                                  (rtx, rtx);
extern rtx        gen_sqrtv16sf2                                 (rtx, rtx);
extern rtx        gen_sqrtv8sf2                                  (rtx, rtx);
extern rtx        gen_sqrtv4sf2                                  (rtx, rtx);
extern rtx        gen_rsqrtv8sf2                                 (rtx, rtx);
extern rtx        gen_rsqrtv4sf2                                 (rtx, rtx);
extern rtx        gen_smaxv16sf3                                 (rtx, rtx, rtx);
extern rtx        gen_smaxv16sf3_round                           (rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv16sf3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv16sf3_mask_round                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv16sf3                                 (rtx, rtx, rtx);
extern rtx        gen_sminv16sf3_round                           (rtx, rtx, rtx, rtx);
extern rtx        gen_sminv16sf3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv16sf3_mask_round                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv8sf3                                  (rtx, rtx, rtx);
static inline rtx gen_smaxv8sf3_round                            (rtx, rtx, rtx, rtx);
static inline rtx
gen_smaxv8sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_smaxv8sf3_mask                             (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_smaxv8sf3_mask_round                       (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_smaxv8sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_sminv8sf3                                  (rtx, rtx, rtx);
static inline rtx gen_sminv8sf3_round                            (rtx, rtx, rtx, rtx);
static inline rtx
gen_sminv8sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_sminv8sf3_mask                             (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_sminv8sf3_mask_round                       (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_sminv8sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_smaxv4sf3                                  (rtx, rtx, rtx);
static inline rtx gen_smaxv4sf3_round                            (rtx, rtx, rtx, rtx);
static inline rtx
gen_smaxv4sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_smaxv4sf3_mask                             (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_smaxv4sf3_mask_round                       (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_smaxv4sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_sminv4sf3                                  (rtx, rtx, rtx);
static inline rtx gen_sminv4sf3_round                            (rtx, rtx, rtx, rtx);
static inline rtx
gen_sminv4sf3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_sminv4sf3_mask                             (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_sminv4sf3_mask_round                       (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_sminv4sf3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_smaxv8df3                                  (rtx, rtx, rtx);
extern rtx        gen_smaxv8df3_round                            (rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv8df3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv8df3_mask_round                       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv8df3                                  (rtx, rtx, rtx);
extern rtx        gen_sminv8df3_round                            (rtx, rtx, rtx, rtx);
extern rtx        gen_sminv8df3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv8df3_mask_round                       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv4df3                                  (rtx, rtx, rtx);
static inline rtx gen_smaxv4df3_round                            (rtx, rtx, rtx, rtx);
static inline rtx
gen_smaxv4df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_smaxv4df3_mask                             (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_smaxv4df3_mask_round                       (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_smaxv4df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_sminv4df3                                  (rtx, rtx, rtx);
static inline rtx gen_sminv4df3_round                            (rtx, rtx, rtx, rtx);
static inline rtx
gen_sminv4df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_sminv4df3_mask                             (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_sminv4df3_mask_round                       (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_sminv4df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_smaxv2df3                                  (rtx, rtx, rtx);
static inline rtx gen_smaxv2df3_round                            (rtx, rtx, rtx, rtx);
static inline rtx
gen_smaxv2df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_smaxv2df3_mask                             (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_smaxv2df3_mask_round                       (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_smaxv2df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_sminv2df3                                  (rtx, rtx, rtx);
static inline rtx gen_sminv2df3_round                            (rtx, rtx, rtx, rtx);
static inline rtx
gen_sminv2df3_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d))
{
  return 0;
}
extern rtx        gen_sminv2df3_mask                             (rtx, rtx, rtx, rtx, rtx);
static inline rtx gen_sminv2df3_mask_round                       (rtx, rtx, rtx, rtx, rtx, rtx);
static inline rtx
gen_sminv2df3_mask_round(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b), rtx ARG_UNUSED (c), rtx ARG_UNUSED (d), rtx ARG_UNUSED (e), rtx ARG_UNUSED (f))
{
  return 0;
}
extern rtx        gen_sse3_haddv2df3                             (rtx, rtx, rtx);
extern rtx        gen_reduc_plus_scal_v8df                       (rtx, rtx);
extern rtx        gen_reduc_plus_scal_v4df                       (rtx, rtx);
extern rtx        gen_reduc_plus_scal_v2df                       (rtx, rtx);
extern rtx        gen_reduc_plus_scal_v16sf                      (rtx, rtx);
extern rtx        gen_reduc_plus_scal_v8sf                       (rtx, rtx);
extern rtx        gen_reduc_plus_scal_v4sf                       (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v32qi                      (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v32qi                      (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v16hi                      (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v16hi                      (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v8si                       (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v8si                       (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v4di                       (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v4di                       (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v8sf                       (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v8sf                       (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v4df                       (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v4df                       (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v4sf                       (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v4sf                       (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v64qi                      (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v64qi                      (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v32hi                      (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v32hi                      (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v16si                      (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v16si                      (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v8di                       (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v8di                       (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v16sf                      (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v16sf                      (rtx, rtx);
extern rtx        gen_reduc_smax_scal_v8df                       (rtx, rtx);
extern rtx        gen_reduc_smin_scal_v8df                       (rtx, rtx);
extern rtx        gen_reduc_umax_scal_v16si                      (rtx, rtx);
extern rtx        gen_reduc_umin_scal_v16si                      (rtx, rtx);
extern rtx        gen_reduc_umax_scal_v8di                       (rtx, rtx);
extern rtx        gen_reduc_umin_scal_v8di                       (rtx, rtx);
extern rtx        gen_reduc_umax_scal_v32hi                      (rtx, rtx);
extern rtx        gen_reduc_umin_scal_v32hi                      (rtx, rtx);
extern rtx        gen_reduc_umax_scal_v64qi                      (rtx, rtx);
extern rtx        gen_reduc_umin_scal_v64qi                      (rtx, rtx);
extern rtx        gen_reduc_umax_scal_v32qi                      (rtx, rtx);
extern rtx        gen_reduc_umin_scal_v32qi                      (rtx, rtx);
extern rtx        gen_reduc_umax_scal_v16hi                      (rtx, rtx);
extern rtx        gen_reduc_umin_scal_v16hi                      (rtx, rtx);
extern rtx        gen_reduc_umax_scal_v8si                       (rtx, rtx);
extern rtx        gen_reduc_umin_scal_v8si                       (rtx, rtx);
extern rtx        gen_reduc_umax_scal_v4di                       (rtx, rtx);
extern rtx        gen_reduc_umin_scal_v4di                       (rtx, rtx);
extern rtx        gen_reduc_umin_scal_v8hi                       (rtx, rtx);
extern rtx        gen_vec_cmpv16sihi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv8siqi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv4siqi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv8diqi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv4diqi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv2diqi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv16sfhi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv8sfqi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv4sfqi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv8dfqi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv4dfqi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv2dfqi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv64qidi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv16qihi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv32qisi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv32hisi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv16hihi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv8hiqi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv32qiv32qi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv16hiv16hi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv8siv8si                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv4div4di                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv16qiv16qi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv8hiv8hi                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv4siv4si                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv2div2di                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv8sfv8si                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv4dfv4di                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv4sfv4si                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpv2dfv2di                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv16sihi                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv8siqi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv4siqi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv8diqi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv4diqi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv2diqi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv64qidi                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv16qihi                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv32qisi                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv32hisi                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv16hihi                            (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv8hiqi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv32qiv32qi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv16hiv16hi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv8siv8si                           (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv4div4di                           (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv16qiv16qi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv8hiv8hi                           (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv4siv4si                           (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_cmpuv2div2di                           (rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv64qiv16sf                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv32hiv16sf                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16siv16sf                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8div16sf                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16sfv16sf                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8dfv16sf                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv64qiv8df                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv32hiv8df                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16siv8df                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8div8df                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16sfv8df                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8dfv8df                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv32qiv8sf                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv32qiv4df                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16hiv8sf                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16hiv4df                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8siv8sf                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8siv4df                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4div8sf                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4div4df                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8sfv8sf                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8sfv4df                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4dfv8sf                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4dfv4df                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16qiv4sf                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16qiv2df                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8hiv4sf                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8hiv2df                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4siv4sf                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4siv2df                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2div4sf                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2div2df                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4sfv4sf                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4sfv2df                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2dfv4sf                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2dfv2df                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v16sihi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v8siqi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v4siqi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v8diqi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v4diqi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v2diqi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v16sfhi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v8sfqi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v4sfqi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v8dfqi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v4dfqi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v2dfqi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v64qidi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v16qihi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v32qisi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v32hisi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v16hihi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v8hiqi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v32qiv32qi                      (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v16hiv16hi                      (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v8siv8si                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v4div4di                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v16qiv16qi                      (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v8hiv8hi                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v4siv4si                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v2div2di                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v8sfv8si                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v4dfv4di                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v4sfv4si                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vcond_mask_v2dfv2di                        (rtx, rtx, rtx, rtx);
extern rtx        gen_andv8sf3                                   (rtx, rtx, rtx);
extern rtx        gen_andv8sf3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_iorv8sf3                                   (rtx, rtx, rtx);
extern rtx        gen_iorv8sf3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xorv8sf3                                   (rtx, rtx, rtx);
extern rtx        gen_xorv8sf3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_andv4sf3                                   (rtx, rtx, rtx);
extern rtx        gen_andv4sf3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_iorv4sf3                                   (rtx, rtx, rtx);
extern rtx        gen_iorv4sf3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xorv4sf3                                   (rtx, rtx, rtx);
extern rtx        gen_xorv4sf3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_andv4df3                                   (rtx, rtx, rtx);
extern rtx        gen_andv4df3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_iorv4df3                                   (rtx, rtx, rtx);
extern rtx        gen_iorv4df3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xorv4df3                                   (rtx, rtx, rtx);
extern rtx        gen_xorv4df3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_andv2df3                                   (rtx, rtx, rtx);
extern rtx        gen_andv2df3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_iorv2df3                                   (rtx, rtx, rtx);
extern rtx        gen_iorv2df3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xorv2df3                                   (rtx, rtx, rtx);
extern rtx        gen_xorv2df3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_andv16sf3                                  (rtx, rtx, rtx);
extern rtx        gen_andv16sf3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_iorv16sf3                                  (rtx, rtx, rtx);
extern rtx        gen_iorv16sf3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xorv16sf3                                  (rtx, rtx, rtx);
extern rtx        gen_xorv16sf3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_andv8df3                                   (rtx, rtx, rtx);
extern rtx        gen_andv8df3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_iorv8df3                                   (rtx, rtx, rtx);
extern rtx        gen_iorv8df3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_xorv8df3                                   (rtx, rtx, rtx);
extern rtx        gen_xorv8df3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_copysignv16sf3                             (rtx, rtx, rtx);
extern rtx        gen_copysignv8sf3                              (rtx, rtx, rtx);
extern rtx        gen_copysignv4sf3                              (rtx, rtx, rtx);
extern rtx        gen_copysignv8df3                              (rtx, rtx, rtx);
extern rtx        gen_copysignv4df3                              (rtx, rtx, rtx);
extern rtx        gen_copysignv2df3                              (rtx, rtx, rtx);
extern rtx        gen_andtf3                                     (rtx, rtx, rtx);
extern rtx        gen_iortf3                                     (rtx, rtx, rtx);
extern rtx        gen_xortf3                                     (rtx, rtx, rtx);
extern rtx        gen_fmasf4                                     (rtx, rtx, rtx, rtx);
extern rtx        gen_fmadf4                                     (rtx, rtx, rtx, rtx);
extern rtx        gen_fmav4sf4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_fmav2df4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_fmav8sf4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_fmav4df4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_fmav16sf4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fmav8df4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_fmssf4                                     (rtx, rtx, rtx, rtx);
extern rtx        gen_fmsdf4                                     (rtx, rtx, rtx, rtx);
extern rtx        gen_fmsv4sf4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_fmsv2df4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_fmsv8sf4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_fmsv4df4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_fmsv16sf4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fmsv8df4                                   (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmasf4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmadf4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmav4sf4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmav2df4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmav8sf4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmav4df4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmav16sf4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmav8df4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmssf4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmsdf4                                    (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmsv4sf4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmsv2df4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmsv8sf4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmsv4df4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmsv16sf4                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_fnmsv8df4                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_fma4i_fmadd_sf                             (rtx, rtx, rtx, rtx);
extern rtx        gen_fma4i_fmadd_df                             (rtx, rtx, rtx, rtx);
extern rtx        gen_fma4i_fmadd_v4sf                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fma4i_fmadd_v2df                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fma4i_fmadd_v8sf                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fma4i_fmadd_v4df                           (rtx, rtx, rtx, rtx);
extern rtx        gen_fma4i_fmadd_v16sf                          (rtx, rtx, rtx, rtx);
extern rtx        gen_fma4i_fmadd_v8df                           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmadd_v16sf_maskz                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmadd_v16sf_maskz_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v8sf_maskz                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v8sf_maskz_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v4sf_maskz                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v4sf_maskz_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmadd_v8df_maskz                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmadd_v8df_maskz_round             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v4df_maskz                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v4df_maskz_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v2df_maskz                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmadd_v2df_maskz_round            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fmaddsub_v16sf                             (rtx, rtx, rtx, rtx);
extern rtx        gen_fmaddsub_v8sf                              (rtx, rtx, rtx, rtx);
extern rtx        gen_fmaddsub_v4sf                              (rtx, rtx, rtx, rtx);
extern rtx        gen_fmaddsub_v8df                              (rtx, rtx, rtx, rtx);
extern rtx        gen_fmaddsub_v4df                              (rtx, rtx, rtx, rtx);
extern rtx        gen_fmaddsub_v2df                              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmaddsub_v16sf_maskz               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmaddsub_v16sf_maskz_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v8sf_maskz               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v8sf_maskz_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v4sf_maskz               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v4sf_maskz_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmaddsub_v8df_maskz                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fmaddsub_v8df_maskz_round          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v4df_maskz               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v4df_maskz_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v2df_maskz               (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fmaddsub_v2df_maskz_round         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fmai_vmfmadd_v4sf                          (rtx, rtx, rtx, rtx);
extern rtx        gen_fmai_vmfmadd_v4sf_round                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fmai_vmfmadd_v2df                          (rtx, rtx, rtx, rtx);
extern rtx        gen_fmai_vmfmadd_v2df_round                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_fma4i_vmfmadd_v4sf                         (rtx, rtx, rtx, rtx);
extern rtx        gen_fma4i_vmfmadd_v2df                         (rtx, rtx, rtx, rtx);
extern rtx        gen_floatunsv16siv16sf2                        (rtx, rtx);
extern rtx        gen_floatunsv8siv8sf2                          (rtx, rtx);
extern rtx        gen_floatunsv4siv4sf2                          (rtx, rtx);
extern rtx        gen_fixuns_truncv16sfv16si2                    (rtx, rtx);
extern rtx        gen_fixuns_truncv8sfv8si2                      (rtx, rtx);
extern rtx        gen_fixuns_truncv4sfv4si2                      (rtx, rtx);
extern rtx        gen_avx_cvtpd2dq256_2                          (rtx, rtx);
extern rtx        gen_avx_cvttpd2dq256_2                         (rtx, rtx);
extern rtx        gen_sse2_cvtpd2ps                              (rtx, rtx);
extern rtx        gen_sse2_cvtpd2ps_mask                         (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_cvtmask2bv64qi                    (rtx, rtx);
extern rtx        gen_avx512vl_cvtmask2bv16qi                    (rtx, rtx);
extern rtx        gen_avx512vl_cvtmask2bv32qi                    (rtx, rtx);
extern rtx        gen_avx512bw_cvtmask2wv32hi                    (rtx, rtx);
extern rtx        gen_avx512vl_cvtmask2wv16hi                    (rtx, rtx);
extern rtx        gen_avx512vl_cvtmask2wv8hi                     (rtx, rtx);
extern rtx        gen_avx512f_cvtmask2dv16si                     (rtx, rtx);
extern rtx        gen_avx512vl_cvtmask2dv8si                     (rtx, rtx);
extern rtx        gen_avx512vl_cvtmask2dv4si                     (rtx, rtx);
extern rtx        gen_avx512f_cvtmask2qv8di                      (rtx, rtx);
extern rtx        gen_avx512vl_cvtmask2qv4di                     (rtx, rtx);
extern rtx        gen_avx512vl_cvtmask2qv2di                     (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v4sf                        (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v8sf                        (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v16sf                       (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v4sf                        (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v8sf                        (rtx, rtx);
extern rtx        gen_vec_unpacks_float_hi_v32hi                 (rtx, rtx);
extern rtx        gen_vec_unpacks_float_hi_v16hi                 (rtx, rtx);
extern rtx        gen_vec_unpacks_float_hi_v8hi                  (rtx, rtx);
extern rtx        gen_vec_unpacks_float_lo_v32hi                 (rtx, rtx);
extern rtx        gen_vec_unpacks_float_lo_v16hi                 (rtx, rtx);
extern rtx        gen_vec_unpacks_float_lo_v8hi                  (rtx, rtx);
extern rtx        gen_vec_unpacku_float_hi_v32hi                 (rtx, rtx);
extern rtx        gen_vec_unpacku_float_hi_v16hi                 (rtx, rtx);
extern rtx        gen_vec_unpacku_float_hi_v8hi                  (rtx, rtx);
extern rtx        gen_vec_unpacku_float_lo_v32hi                 (rtx, rtx);
extern rtx        gen_vec_unpacku_float_lo_v16hi                 (rtx, rtx);
extern rtx        gen_vec_unpacku_float_lo_v8hi                  (rtx, rtx);
extern rtx        gen_vec_unpacks_float_hi_v4si                  (rtx, rtx);
extern rtx        gen_vec_unpacks_float_lo_v4si                  (rtx, rtx);
extern rtx        gen_vec_unpacks_float_hi_v8si                  (rtx, rtx);
extern rtx        gen_vec_unpacks_float_lo_v8si                  (rtx, rtx);
extern rtx        gen_vec_unpacks_float_hi_v16si                 (rtx, rtx);
extern rtx        gen_vec_unpacks_float_lo_v16si                 (rtx, rtx);
extern rtx        gen_vec_unpacku_float_hi_v4si                  (rtx, rtx);
extern rtx        gen_vec_unpacku_float_lo_v4si                  (rtx, rtx);
extern rtx        gen_vec_unpacku_float_hi_v8si                  (rtx, rtx);
extern rtx        gen_vec_unpacku_float_hi_v16si                 (rtx, rtx);
extern rtx        gen_vec_unpacku_float_lo_v8si                  (rtx, rtx);
extern rtx        gen_vec_unpacku_float_lo_v16si                 (rtx, rtx);
extern rtx        gen_vec_pack_trunc_v8df                        (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v4df                        (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v2df                        (rtx, rtx, rtx);
extern rtx        gen_vec_pack_sfix_trunc_v8df                   (rtx, rtx, rtx);
extern rtx        gen_vec_pack_sfix_trunc_v4df                   (rtx, rtx, rtx);
extern rtx        gen_vec_pack_sfix_trunc_v2df                   (rtx, rtx, rtx);
extern rtx        gen_vec_pack_ufix_trunc_v8df                   (rtx, rtx, rtx);
extern rtx        gen_vec_pack_ufix_trunc_v4df                   (rtx, rtx, rtx);
extern rtx        gen_vec_pack_ufix_trunc_v2df                   (rtx, rtx, rtx);
extern rtx        gen_avx512f_vec_pack_sfix_v8df                 (rtx, rtx, rtx);
extern rtx        gen_vec_pack_sfix_v4df                         (rtx, rtx, rtx);
extern rtx        gen_vec_pack_sfix_v2df                         (rtx, rtx, rtx);
extern rtx        gen_sse_movhlps_exp                            (rtx, rtx, rtx);
extern rtx        gen_sse_movlhps_exp                            (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv8sf                    (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv8sf                     (rtx, rtx, rtx);
extern rtx        gen_avx_shufps256                              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_shufps256_mask                         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse_shufps                                 (rtx, rtx, rtx, rtx);
extern rtx        gen_sse_shufps_mask                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse_loadhps_exp                            (rtx, rtx, rtx);
extern rtx        gen_sse_loadlps_exp                            (rtx, rtx, rtx);
extern rtx        gen_vec_initv16qi                              (rtx, rtx);
extern rtx        gen_vec_initv8hi                               (rtx, rtx);
extern rtx        gen_vec_initv4si                               (rtx, rtx);
extern rtx        gen_vec_initv2di                               (rtx, rtx);
extern rtx        gen_vec_initv4sf                               (rtx, rtx);
extern rtx        gen_vec_initv2df                               (rtx, rtx);
extern rtx        gen_vec_setv32qi                               (rtx, rtx, rtx);
extern rtx        gen_vec_setv16qi                               (rtx, rtx, rtx);
extern rtx        gen_vec_setv16hi                               (rtx, rtx, rtx);
extern rtx        gen_vec_setv8hi                                (rtx, rtx, rtx);
extern rtx        gen_vec_setv16si                               (rtx, rtx, rtx);
extern rtx        gen_vec_setv8si                                (rtx, rtx, rtx);
extern rtx        gen_vec_setv4si                                (rtx, rtx, rtx);
extern rtx        gen_vec_setv8di                                (rtx, rtx, rtx);
extern rtx        gen_vec_setv4di                                (rtx, rtx, rtx);
extern rtx        gen_vec_setv2di                                (rtx, rtx, rtx);
extern rtx        gen_vec_setv16sf                               (rtx, rtx, rtx);
extern rtx        gen_vec_setv8sf                                (rtx, rtx, rtx);
extern rtx        gen_vec_setv4sf                                (rtx, rtx, rtx);
extern rtx        gen_vec_setv8df                                (rtx, rtx, rtx);
extern rtx        gen_vec_setv4df                                (rtx, rtx, rtx);
extern rtx        gen_vec_setv2df                                (rtx, rtx, rtx);
extern rtx        gen_avx512dq_vextractf64x2_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_vextracti64x2_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vextractf32x4_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vextracti32x4_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_vextractf32x8_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_vextracti32x8_mask                (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vextractf64x4_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vextracti64x4_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vextractf128v8si                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vextractf128v8sf                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vextractf128v4di                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vextractf128v4df                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vextractf128v32qi                      (rtx, rtx, rtx);
extern rtx        gen_avx_vextractf128v16hi                      (rtx, rtx, rtx);
extern rtx        gen_avx_vextractf128v8si                       (rtx, rtx, rtx);
extern rtx        gen_avx_vextractf128v4di                       (rtx, rtx, rtx);
extern rtx        gen_avx_vextractf128v8sf                       (rtx, rtx, rtx);
extern rtx        gen_avx_vextractf128v4df                       (rtx, rtx, rtx);
extern rtx        gen_vec_extractv64qi                           (rtx, rtx, rtx);
extern rtx        gen_vec_extractv32qi                           (rtx, rtx, rtx);
extern rtx        gen_vec_extractv16qi                           (rtx, rtx, rtx);
extern rtx        gen_vec_extractv32hi                           (rtx, rtx, rtx);
extern rtx        gen_vec_extractv16hi                           (rtx, rtx, rtx);
extern rtx        gen_vec_extractv8hi                            (rtx, rtx, rtx);
extern rtx        gen_vec_extractv16si                           (rtx, rtx, rtx);
extern rtx        gen_vec_extractv8si                            (rtx, rtx, rtx);
extern rtx        gen_vec_extractv4si                            (rtx, rtx, rtx);
extern rtx        gen_vec_extractv8di                            (rtx, rtx, rtx);
extern rtx        gen_vec_extractv4di                            (rtx, rtx, rtx);
extern rtx        gen_vec_extractv2di                            (rtx, rtx, rtx);
extern rtx        gen_vec_extractv16sf                           (rtx, rtx, rtx);
extern rtx        gen_vec_extractv8sf                            (rtx, rtx, rtx);
extern rtx        gen_vec_extractv4sf                            (rtx, rtx, rtx);
extern rtx        gen_vec_extractv8df                            (rtx, rtx, rtx);
extern rtx        gen_vec_extractv4df                            (rtx, rtx, rtx);
extern rtx        gen_vec_extractv2df                            (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv4df                    (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv2df                    (rtx, rtx, rtx);
extern rtx        gen_avx512f_movddup512                         (rtx, rtx);
extern rtx        gen_avx512f_movddup512_mask                    (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_unpcklpd512                        (rtx, rtx, rtx);
extern rtx        gen_avx512f_unpcklpd512_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_movddup256                             (rtx, rtx);
extern rtx        gen_avx_movddup256_mask                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_unpcklpd256                            (rtx, rtx, rtx);
extern rtx        gen_avx_unpcklpd256_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv4df                     (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv2df                     (rtx, rtx, rtx);
extern rtx        gen_avx512f_vternlogv16si_maskz                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv8si_maskz                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv4si_maskz                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vternlogv8di_maskz                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv4di_maskz                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vternlogv2di_maskz                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shufps512_mask                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv16sf_maskz                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv16sf_maskz_round          (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv8sf_maskz                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv8sf_maskz_round          (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4sf_maskz                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4sf_maskz_round          (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv8df_maskz                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_fixupimmv8df_maskz_round           (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4df_maskz                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv4df_maskz_round          (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv2df_maskz                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_fixupimmv2df_maskz_round          (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv4sf_maskz                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv4sf_maskz_round          (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv2df_maskz                (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_sfixupimmv2df_maskz_round          (rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shufpd512_mask                     (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_shufpd256                              (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_shufpd256_mask                         (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_shufpd                                (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_shufpd_mask                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_loadhpd_exp                           (rtx, rtx, rtx);
extern rtx        gen_sse2_loadlpd_exp                           (rtx, rtx, rtx);
extern rtx        gen_avx512f_ss_truncatev16siv16qi2_mask_store  (rtx, rtx, rtx);
extern rtx        gen_avx512f_truncatev16siv16qi2_mask_store     (rtx, rtx, rtx);
extern rtx        gen_avx512f_us_truncatev16siv16qi2_mask_store  (rtx, rtx, rtx);
extern rtx        gen_avx512f_ss_truncatev16siv16hi2_mask_store  (rtx, rtx, rtx);
extern rtx        gen_avx512f_truncatev16siv16hi2_mask_store     (rtx, rtx, rtx);
extern rtx        gen_avx512f_us_truncatev16siv16hi2_mask_store  (rtx, rtx, rtx);
extern rtx        gen_avx512f_ss_truncatev8div8si2_mask_store    (rtx, rtx, rtx);
extern rtx        gen_avx512f_truncatev8div8si2_mask_store       (rtx, rtx, rtx);
extern rtx        gen_avx512f_us_truncatev8div8si2_mask_store    (rtx, rtx, rtx);
extern rtx        gen_avx512f_ss_truncatev8div8hi2_mask_store    (rtx, rtx, rtx);
extern rtx        gen_avx512f_truncatev8div8hi2_mask_store       (rtx, rtx, rtx);
extern rtx        gen_avx512f_us_truncatev8div8hi2_mask_store    (rtx, rtx, rtx);
extern rtx        gen_avx512bw_ss_truncatev32hiv32qi2_mask_store (rtx, rtx, rtx);
extern rtx        gen_avx512bw_truncatev32hiv32qi2_mask_store    (rtx, rtx, rtx);
extern rtx        gen_avx512bw_us_truncatev32hiv32qi2_mask_store (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev4div4si2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev4div4si2_mask_store      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev4div4si2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev8siv8hi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev8siv8hi2_mask_store      (rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev8siv8hi2_mask_store   (rtx, rtx, rtx);
extern rtx        gen_avx512vl_ss_truncatev16hiv16qi2_mask_store (rtx, rtx, rtx);
extern rtx        gen_avx512vl_truncatev16hiv16qi2_mask_store    (rtx, rtx, rtx);
extern rtx        gen_avx512vl_us_truncatev16hiv16qi2_mask_store (rtx, rtx, rtx);
extern rtx        gen_negv64qi2                                  (rtx, rtx);
extern rtx        gen_negv32qi2                                  (rtx, rtx);
extern rtx        gen_negv16qi2                                  (rtx, rtx);
extern rtx        gen_negv32hi2                                  (rtx, rtx);
extern rtx        gen_negv16hi2                                  (rtx, rtx);
extern rtx        gen_negv8hi2                                   (rtx, rtx);
extern rtx        gen_negv16si2                                  (rtx, rtx);
extern rtx        gen_negv8si2                                   (rtx, rtx);
extern rtx        gen_negv4si2                                   (rtx, rtx);
extern rtx        gen_negv8di2                                   (rtx, rtx);
extern rtx        gen_negv4di2                                   (rtx, rtx);
extern rtx        gen_negv2di2                                   (rtx, rtx);
extern rtx        gen_addv64qi3                                  (rtx, rtx, rtx);
extern rtx        gen_subv64qi3                                  (rtx, rtx, rtx);
extern rtx        gen_addv32qi3                                  (rtx, rtx, rtx);
extern rtx        gen_subv32qi3                                  (rtx, rtx, rtx);
extern rtx        gen_addv16qi3                                  (rtx, rtx, rtx);
extern rtx        gen_subv16qi3                                  (rtx, rtx, rtx);
extern rtx        gen_addv32hi3                                  (rtx, rtx, rtx);
extern rtx        gen_subv32hi3                                  (rtx, rtx, rtx);
extern rtx        gen_addv16hi3                                  (rtx, rtx, rtx);
extern rtx        gen_subv16hi3                                  (rtx, rtx, rtx);
extern rtx        gen_addv8hi3                                   (rtx, rtx, rtx);
extern rtx        gen_subv8hi3                                   (rtx, rtx, rtx);
extern rtx        gen_addv16si3                                  (rtx, rtx, rtx);
extern rtx        gen_subv16si3                                  (rtx, rtx, rtx);
extern rtx        gen_addv8si3                                   (rtx, rtx, rtx);
extern rtx        gen_subv8si3                                   (rtx, rtx, rtx);
extern rtx        gen_addv4si3                                   (rtx, rtx, rtx);
extern rtx        gen_subv4si3                                   (rtx, rtx, rtx);
extern rtx        gen_addv8di3                                   (rtx, rtx, rtx);
extern rtx        gen_subv8di3                                   (rtx, rtx, rtx);
extern rtx        gen_addv4di3                                   (rtx, rtx, rtx);
extern rtx        gen_subv4di3                                   (rtx, rtx, rtx);
extern rtx        gen_addv2di3                                   (rtx, rtx, rtx);
extern rtx        gen_subv2di3                                   (rtx, rtx, rtx);
extern rtx        gen_addv16si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv16si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv8si3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv8si3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv4si3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv4si3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv8di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv8di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv4di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv4di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv2di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv2di3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv64qi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv64qi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv16qi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv16qi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv32qi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv32qi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv32hi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv32hi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv16hi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv16hi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_addv8hi3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_subv8hi3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_ssaddv64qi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512bw_ssaddv64qi3_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_usaddv64qi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512bw_usaddv64qi3_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_sssubv64qi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512bw_sssubv64qi3_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_ussubv64qi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512bw_ussubv64qi3_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_ssaddv32qi3                           (rtx, rtx, rtx);
extern rtx        gen_avx2_ssaddv32qi3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_usaddv32qi3                           (rtx, rtx, rtx);
extern rtx        gen_avx2_usaddv32qi3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_sssubv32qi3                           (rtx, rtx, rtx);
extern rtx        gen_avx2_sssubv32qi3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_ussubv32qi3                           (rtx, rtx, rtx);
extern rtx        gen_avx2_ussubv32qi3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_ssaddv16qi3                           (rtx, rtx, rtx);
extern rtx        gen_sse2_ssaddv16qi3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_usaddv16qi3                           (rtx, rtx, rtx);
extern rtx        gen_sse2_usaddv16qi3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_sssubv16qi3                           (rtx, rtx, rtx);
extern rtx        gen_sse2_sssubv16qi3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_ussubv16qi3                           (rtx, rtx, rtx);
extern rtx        gen_sse2_ussubv16qi3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_ssaddv32hi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512bw_ssaddv32hi3_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_usaddv32hi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512bw_usaddv32hi3_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_sssubv32hi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512bw_sssubv32hi3_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_ussubv32hi3                       (rtx, rtx, rtx);
extern rtx        gen_avx512bw_ussubv32hi3_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_ssaddv16hi3                           (rtx, rtx, rtx);
extern rtx        gen_avx2_ssaddv16hi3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_usaddv16hi3                           (rtx, rtx, rtx);
extern rtx        gen_avx2_usaddv16hi3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_sssubv16hi3                           (rtx, rtx, rtx);
extern rtx        gen_avx2_sssubv16hi3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_ussubv16hi3                           (rtx, rtx, rtx);
extern rtx        gen_avx2_ussubv16hi3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_ssaddv8hi3                            (rtx, rtx, rtx);
extern rtx        gen_sse2_ssaddv8hi3_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_usaddv8hi3                            (rtx, rtx, rtx);
extern rtx        gen_sse2_usaddv8hi3_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_sssubv8hi3                            (rtx, rtx, rtx);
extern rtx        gen_sse2_sssubv8hi3_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_ussubv8hi3                            (rtx, rtx, rtx);
extern rtx        gen_sse2_ussubv8hi3_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulv64qi3                                  (rtx, rtx, rtx);
extern rtx        gen_mulv64qi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulv32qi3                                  (rtx, rtx, rtx);
extern rtx        gen_mulv32qi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulv16qi3                                  (rtx, rtx, rtx);
extern rtx        gen_mulv16qi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulv32hi3                                  (rtx, rtx, rtx);
extern rtx        gen_mulv32hi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulv16hi3                                  (rtx, rtx, rtx);
extern rtx        gen_mulv16hi3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulv8hi3                                   (rtx, rtx, rtx);
extern rtx        gen_mulv8hi3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smulv32hi3_highpart                        (rtx, rtx, rtx);
extern rtx        gen_smulv32hi3_highpart_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umulv32hi3_highpart                        (rtx, rtx, rtx);
extern rtx        gen_umulv32hi3_highpart_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smulv16hi3_highpart                        (rtx, rtx, rtx);
extern rtx        gen_smulv16hi3_highpart_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umulv16hi3_highpart                        (rtx, rtx, rtx);
extern rtx        gen_umulv16hi3_highpart_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smulv8hi3_highpart                         (rtx, rtx, rtx);
extern rtx        gen_smulv8hi3_highpart_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umulv8hi3_highpart                         (rtx, rtx, rtx);
extern rtx        gen_umulv8hi3_highpart_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_even_v16si                 (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_even_v16si_mask            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_even_v8si                  (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_even_v8si_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_even_v4si                  (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_even_v4si_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_even_v16si                 (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_even_v16si_mask            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_even_v8si                  (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_even_v8si_mask             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_mulv2siv2di3                        (rtx, rtx, rtx);
extern rtx        gen_sse4_1_mulv2siv2di3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pmaddwd                               (rtx, rtx, rtx);
extern rtx        gen_sse2_pmaddwd                               (rtx, rtx, rtx);
extern rtx        gen_mulv16si3                                  (rtx, rtx, rtx);
extern rtx        gen_mulv16si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulv8si3                                   (rtx, rtx, rtx);
extern rtx        gen_mulv8si3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulv4si3                                   (rtx, rtx, rtx);
extern rtx        gen_mulv4si3_mask                              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulv8di3                                   (rtx, rtx, rtx);
extern rtx        gen_mulv4di3                                   (rtx, rtx, rtx);
extern rtx        gen_mulv2di3                                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_hi_v32qi                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_hi_v32qi                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_hi_v16qi                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_hi_v16qi                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_hi_v16hi                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_hi_v16hi                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_hi_v8hi                    (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_hi_v8hi                    (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_hi_v8si                    (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_hi_v8si                    (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_hi_v4si                    (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_hi_v4si                    (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_lo_v32qi                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_lo_v32qi                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_lo_v16qi                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_lo_v16qi                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_lo_v16hi                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_lo_v16hi                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_lo_v8hi                    (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_lo_v8hi                    (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_lo_v8si                    (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_lo_v8si                    (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_lo_v4si                    (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_lo_v4si                    (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_even_v4si                  (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_odd_v16si                  (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_odd_v16si                  (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_odd_v8si                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_odd_v8si                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_smult_odd_v4si                   (rtx, rtx, rtx);
extern rtx        gen_vec_widen_umult_odd_v4si                   (rtx, rtx, rtx);
extern rtx        gen_sdot_prodv32hi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_sdot_prodv16hi                             (rtx, rtx, rtx, rtx);
extern rtx        gen_sdot_prodv8hi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_sdot_prodv4si                              (rtx, rtx, rtx, rtx);
extern rtx        gen_usadv16qi                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_usadv32qi                                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_shl_v16qi                              (rtx, rtx, rtx);
extern rtx        gen_vec_shl_v8hi                               (rtx, rtx, rtx);
extern rtx        gen_vec_shl_v4si                               (rtx, rtx, rtx);
extern rtx        gen_vec_shl_v2di                               (rtx, rtx, rtx);
extern rtx        gen_vec_shr_v16qi                              (rtx, rtx, rtx);
extern rtx        gen_vec_shr_v8hi                               (rtx, rtx, rtx);
extern rtx        gen_vec_shr_v4si                               (rtx, rtx, rtx);
extern rtx        gen_vec_shr_v2di                               (rtx, rtx, rtx);
extern rtx        gen_smaxv32qi3                                 (rtx, rtx, rtx);
extern rtx        gen_sminv32qi3                                 (rtx, rtx, rtx);
extern rtx        gen_umaxv32qi3                                 (rtx, rtx, rtx);
extern rtx        gen_uminv32qi3                                 (rtx, rtx, rtx);
extern rtx        gen_smaxv16hi3                                 (rtx, rtx, rtx);
extern rtx        gen_sminv16hi3                                 (rtx, rtx, rtx);
extern rtx        gen_umaxv16hi3                                 (rtx, rtx, rtx);
extern rtx        gen_uminv16hi3                                 (rtx, rtx, rtx);
extern rtx        gen_smaxv8si3                                  (rtx, rtx, rtx);
extern rtx        gen_sminv8si3                                  (rtx, rtx, rtx);
extern rtx        gen_umaxv8si3                                  (rtx, rtx, rtx);
extern rtx        gen_uminv8si3                                  (rtx, rtx, rtx);
extern rtx        gen_smaxv64qi3                                 (rtx, rtx, rtx);
extern rtx        gen_sminv64qi3                                 (rtx, rtx, rtx);
extern rtx        gen_umaxv64qi3                                 (rtx, rtx, rtx);
extern rtx        gen_uminv64qi3                                 (rtx, rtx, rtx);
extern rtx        gen_smaxv32hi3                                 (rtx, rtx, rtx);
extern rtx        gen_sminv32hi3                                 (rtx, rtx, rtx);
extern rtx        gen_umaxv32hi3                                 (rtx, rtx, rtx);
extern rtx        gen_uminv32hi3                                 (rtx, rtx, rtx);
extern rtx        gen_smaxv16si3                                 (rtx, rtx, rtx);
extern rtx        gen_sminv16si3                                 (rtx, rtx, rtx);
extern rtx        gen_umaxv16si3                                 (rtx, rtx, rtx);
extern rtx        gen_uminv16si3                                 (rtx, rtx, rtx);
extern rtx        gen_smaxv16si3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv16si3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umaxv16si3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_uminv16si3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv8si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv8si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umaxv8si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_uminv8si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv4si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv4si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umaxv4si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_uminv4si3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv8di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv8di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umaxv8di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_uminv8di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv4di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv4di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umaxv4di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_uminv4di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv2di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sminv2di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umaxv2di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_uminv2di3_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_smaxv8di3                                  (rtx, rtx, rtx);
extern rtx        gen_sminv8di3                                  (rtx, rtx, rtx);
extern rtx        gen_umaxv8di3                                  (rtx, rtx, rtx);
extern rtx        gen_uminv8di3                                  (rtx, rtx, rtx);
extern rtx        gen_smaxv4di3                                  (rtx, rtx, rtx);
extern rtx        gen_sminv4di3                                  (rtx, rtx, rtx);
extern rtx        gen_umaxv4di3                                  (rtx, rtx, rtx);
extern rtx        gen_uminv4di3                                  (rtx, rtx, rtx);
extern rtx        gen_smaxv2di3                                  (rtx, rtx, rtx);
extern rtx        gen_sminv2di3                                  (rtx, rtx, rtx);
extern rtx        gen_umaxv2di3                                  (rtx, rtx, rtx);
extern rtx        gen_uminv2di3                                  (rtx, rtx, rtx);
extern rtx        gen_smaxv16qi3                                 (rtx, rtx, rtx);
extern rtx        gen_sminv16qi3                                 (rtx, rtx, rtx);
extern rtx        gen_smaxv8hi3                                  (rtx, rtx, rtx);
extern rtx        gen_sminv8hi3                                  (rtx, rtx, rtx);
extern rtx        gen_smaxv4si3                                  (rtx, rtx, rtx);
extern rtx        gen_sminv4si3                                  (rtx, rtx, rtx);
extern rtx        gen_umaxv16qi3                                 (rtx, rtx, rtx);
extern rtx        gen_uminv16qi3                                 (rtx, rtx, rtx);
extern rtx        gen_umaxv8hi3                                  (rtx, rtx, rtx);
extern rtx        gen_uminv8hi3                                  (rtx, rtx, rtx);
extern rtx        gen_umaxv4si3                                  (rtx, rtx, rtx);
extern rtx        gen_uminv4si3                                  (rtx, rtx, rtx);
extern rtx        gen_avx2_eqv32qi3                              (rtx, rtx, rtx);
extern rtx        gen_avx2_eqv16hi3                              (rtx, rtx, rtx);
extern rtx        gen_avx2_eqv8si3                               (rtx, rtx, rtx);
extern rtx        gen_avx2_eqv4di3                               (rtx, rtx, rtx);
extern rtx        gen_avx512bw_eqv64qi3                          (rtx, rtx, rtx);
extern rtx        gen_avx512bw_eqv64qi3_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv16qi3                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv16qi3_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv32qi3                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv32qi3_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_eqv32hi3                          (rtx, rtx, rtx);
extern rtx        gen_avx512bw_eqv32hi3_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv16hi3                          (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv16hi3_mask                     (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv8hi3                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv8hi3_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_eqv16si3                           (rtx, rtx, rtx);
extern rtx        gen_avx512f_eqv16si3_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv8si3                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv8si3_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv4si3                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv4si3_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_eqv8di3                            (rtx, rtx, rtx);
extern rtx        gen_avx512f_eqv8di3_mask                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv4di3                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv4di3_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv2di3                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_eqv2di3_mask                      (rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_eqv16qi3                              (rtx, rtx, rtx);
extern rtx        gen_sse2_eqv8hi3                               (rtx, rtx, rtx);
extern rtx        gen_sse2_eqv4si3                               (rtx, rtx, rtx);
extern rtx        gen_sse4_1_eqv2di3                             (rtx, rtx, rtx);
extern rtx        gen_vcondv64qiv64qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv32hiv64qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16siv64qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8div64qi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16sfv64qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8dfv64qi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv64qiv32hi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv32hiv32hi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16siv32hi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8div32hi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16sfv32hi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8dfv32hi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv64qiv16si                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv32hiv16si                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16siv16si                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8div16si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16sfv16si                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8dfv16si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv64qiv8di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv32hiv8di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16siv8di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8div8di                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16sfv8di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8dfv8di                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv32qiv32qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16hiv32qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8siv32qi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4div32qi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8sfv32qi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4dfv32qi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv32qiv16hi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16hiv16hi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8siv16hi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4div16hi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8sfv16hi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4dfv16hi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv32qiv8si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16hiv8si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8siv8si                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4div8si                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8sfv8si                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4dfv8si                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv32qiv4di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16hiv4di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8siv4di                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4div4di                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8sfv4di                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4dfv4di                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16qiv16qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8hiv16qi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4siv16qi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2div16qi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4sfv16qi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2dfv16qi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16qiv8hi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8hiv8hi                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4siv8hi                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2div8hi                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4sfv8hi                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2dfv8hi                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv16qiv4si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv8hiv4si                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4siv4si                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2div4si                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv4sfv4si                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2dfv4si                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2div2di                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcondv2dfv2di                              (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv64qiv64qi                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv32hiv64qi                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16siv64qi                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8div64qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16sfv64qi                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8dfv64qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv64qiv32hi                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv32hiv32hi                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16siv32hi                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8div32hi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16sfv32hi                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8dfv32hi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv64qiv16si                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv32hiv16si                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16siv16si                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8div16si                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16sfv16si                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8dfv16si                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv64qiv8di                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv32hiv8di                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16siv8di                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8div8di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16sfv8di                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8dfv8di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv32qiv32qi                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16hiv32qi                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8siv32qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4div32qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8sfv32qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4dfv32qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv32qiv16hi                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16hiv16hi                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8siv16hi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4div16hi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8sfv16hi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4dfv16hi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv32qiv8si                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16hiv8si                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8siv8si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4div8si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8sfv8si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4dfv8si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv32qiv4di                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16hiv4di                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8siv4di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4div4di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8sfv4di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4dfv4di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16qiv16qi                           (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8hiv16qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4siv16qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv2div16qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4sfv16qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv2dfv16qi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16qiv8hi                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8hiv8hi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4siv8hi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv2div8hi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4sfv8hi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv2dfv8hi                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv16qiv4si                            (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv8hiv4si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4siv4si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv2div4si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv4sfv4si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv2dfv4si                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv2div2di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vconduv2dfv2di                             (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv16qi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv8hi                               (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv4si                               (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv2di                               (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv4sf                               (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv2df                               (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv32qi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv16hi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv8si                               (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv4di                               (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv8sf                               (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv4df                               (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv16sf                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv8df                               (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv16si                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv8di                               (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv32hi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_permv64qi                              (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv4sf                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv4si                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv2df                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv2di                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv16qi                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv8hi                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv8sf                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv4df                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv8si                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv4di                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv32qi                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv16hi                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv16si                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv8di                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv16sf                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv8df                         (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv32hi                        (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_perm_constv64qi                        (rtx, rtx, rtx, rtx);
extern rtx        gen_one_cmplv16si2                             (rtx, rtx);
extern rtx        gen_one_cmplv8di2                              (rtx, rtx);
extern rtx        gen_one_cmplv64qi2                             (rtx, rtx);
extern rtx        gen_one_cmplv32qi2                             (rtx, rtx);
extern rtx        gen_one_cmplv16qi2                             (rtx, rtx);
extern rtx        gen_one_cmplv32hi2                             (rtx, rtx);
extern rtx        gen_one_cmplv16hi2                             (rtx, rtx);
extern rtx        gen_one_cmplv8hi2                              (rtx, rtx);
extern rtx        gen_one_cmplv8si2                              (rtx, rtx);
extern rtx        gen_one_cmplv4si2                              (rtx, rtx);
extern rtx        gen_one_cmplv4di2                              (rtx, rtx);
extern rtx        gen_one_cmplv2di2                              (rtx, rtx);
extern rtx        gen_avx512bw_andnotv64qi3                      (rtx, rtx, rtx);
extern rtx        gen_avx2_andnotv32qi3                          (rtx, rtx, rtx);
extern rtx        gen_sse2_andnotv16qi3                          (rtx, rtx, rtx);
extern rtx        gen_avx512bw_andnotv32hi3                      (rtx, rtx, rtx);
extern rtx        gen_avx2_andnotv16hi3                          (rtx, rtx, rtx);
extern rtx        gen_sse2_andnotv8hi3                           (rtx, rtx, rtx);
extern rtx        gen_avx512f_andnotv16si3                       (rtx, rtx, rtx);
extern rtx        gen_avx2_andnotv8si3                           (rtx, rtx, rtx);
extern rtx        gen_sse2_andnotv4si3                           (rtx, rtx, rtx);
extern rtx        gen_avx512f_andnotv8di3                        (rtx, rtx, rtx);
extern rtx        gen_avx2_andnotv4di3                           (rtx, rtx, rtx);
extern rtx        gen_sse2_andnotv2di3                           (rtx, rtx, rtx);
extern rtx        gen_avx512f_andnotv16si3_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_andnotv8si3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_andnotv4si3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_andnotv8di3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_andnotv4di3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_andnotv2di3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_andnotv64qi3_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_andnotv16qi3_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_andnotv32qi3_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_andnotv32hi3_mask                 (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_andnotv16hi3_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_andnotv8hi3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_andv16si3                                  (rtx, rtx, rtx);
extern rtx        gen_iorv16si3                                  (rtx, rtx, rtx);
extern rtx        gen_xorv16si3                                  (rtx, rtx, rtx);
extern rtx        gen_andv8di3                                   (rtx, rtx, rtx);
extern rtx        gen_iorv8di3                                   (rtx, rtx, rtx);
extern rtx        gen_xorv8di3                                   (rtx, rtx, rtx);
extern rtx        gen_andv64qi3                                  (rtx, rtx, rtx);
extern rtx        gen_iorv64qi3                                  (rtx, rtx, rtx);
extern rtx        gen_xorv64qi3                                  (rtx, rtx, rtx);
extern rtx        gen_andv32qi3                                  (rtx, rtx, rtx);
extern rtx        gen_iorv32qi3                                  (rtx, rtx, rtx);
extern rtx        gen_xorv32qi3                                  (rtx, rtx, rtx);
extern rtx        gen_andv16qi3                                  (rtx, rtx, rtx);
extern rtx        gen_iorv16qi3                                  (rtx, rtx, rtx);
extern rtx        gen_xorv16qi3                                  (rtx, rtx, rtx);
extern rtx        gen_andv32hi3                                  (rtx, rtx, rtx);
extern rtx        gen_iorv32hi3                                  (rtx, rtx, rtx);
extern rtx        gen_xorv32hi3                                  (rtx, rtx, rtx);
extern rtx        gen_andv16hi3                                  (rtx, rtx, rtx);
extern rtx        gen_iorv16hi3                                  (rtx, rtx, rtx);
extern rtx        gen_xorv16hi3                                  (rtx, rtx, rtx);
extern rtx        gen_andv8hi3                                   (rtx, rtx, rtx);
extern rtx        gen_iorv8hi3                                   (rtx, rtx, rtx);
extern rtx        gen_xorv8hi3                                   (rtx, rtx, rtx);
extern rtx        gen_andv8si3                                   (rtx, rtx, rtx);
extern rtx        gen_iorv8si3                                   (rtx, rtx, rtx);
extern rtx        gen_xorv8si3                                   (rtx, rtx, rtx);
extern rtx        gen_andv4si3                                   (rtx, rtx, rtx);
extern rtx        gen_iorv4si3                                   (rtx, rtx, rtx);
extern rtx        gen_xorv4si3                                   (rtx, rtx, rtx);
extern rtx        gen_andv4di3                                   (rtx, rtx, rtx);
extern rtx        gen_iorv4di3                                   (rtx, rtx, rtx);
extern rtx        gen_xorv4di3                                   (rtx, rtx, rtx);
extern rtx        gen_andv2di3                                   (rtx, rtx, rtx);
extern rtx        gen_iorv2di3                                   (rtx, rtx, rtx);
extern rtx        gen_xorv2di3                                   (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v32hi                       (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v16hi                       (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v8hi                        (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v16si                       (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v8si                        (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v4si                        (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v8di                        (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v4di                        (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_v2di                        (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_qi                          (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_hi                          (rtx, rtx, rtx);
extern rtx        gen_vec_pack_trunc_si                          (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv32qi                   (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv16hi                   (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv8si                    (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_highv4di                    (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv32qi                    (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv16hi                    (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv8si                     (rtx, rtx, rtx);
extern rtx        gen_vec_interleave_lowv4di                     (rtx, rtx, rtx);
extern rtx        gen_avx512dq_vinsertf64x2_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_vinserti64x2_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vinsertf32x4_mask                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vinserti32x4_mask                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_vinsertf32x8_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_vinserti32x8_mask                 (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vinsertf64x4_mask                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vinserti64x4_mask                  (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_shuf_i64x2_mask                   (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512dq_shuf_f64x2_mask                   (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shuf_f64x2_mask                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shuf_i64x2_mask                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_shuf_i32x4_mask                   (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_shuf_f32x4_mask                   (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shuf_f32x4_mask                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_shuf_i32x4_mask                    (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_pshufdv3_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_pshufdv3_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pshufdv3                              (rtx, rtx, rtx);
extern rtx        gen_avx512vl_pshufd_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_pshufd                                (rtx, rtx, rtx);
extern rtx        gen_avx512vl_pshuflwv3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pshuflwv3                             (rtx, rtx, rtx);
extern rtx        gen_avx512vl_pshuflw_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_pshuflw                               (rtx, rtx, rtx);
extern rtx        gen_avx2_pshufhwv3                             (rtx, rtx, rtx);
extern rtx        gen_avx512vl_pshufhwv3_mask                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_pshufhw_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_pshufhw                               (rtx, rtx, rtx);
extern rtx        gen_sse2_loadd                                 (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v64qi                       (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v32qi                       (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v16qi                       (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v32hi                       (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v16hi                       (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v8hi                        (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v16si                       (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v8si                        (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_v4si                        (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v64qi                       (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v32qi                       (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v16qi                       (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v32hi                       (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v16hi                       (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v8hi                        (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v16si                       (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v8si                        (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_v4si                        (rtx, rtx);
extern rtx        gen_vec_unpacku_lo_v64qi                       (rtx, rtx);
extern rtx        gen_vec_unpacku_lo_v32qi                       (rtx, rtx);
extern rtx        gen_vec_unpacku_lo_v16qi                       (rtx, rtx);
extern rtx        gen_vec_unpacku_lo_v32hi                       (rtx, rtx);
extern rtx        gen_vec_unpacku_lo_v16hi                       (rtx, rtx);
extern rtx        gen_vec_unpacku_lo_v8hi                        (rtx, rtx);
extern rtx        gen_vec_unpacku_lo_v16si                       (rtx, rtx);
extern rtx        gen_vec_unpacku_lo_v8si                        (rtx, rtx);
extern rtx        gen_vec_unpacku_lo_v4si                        (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_hi                          (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_si                          (rtx, rtx);
extern rtx        gen_vec_unpacks_lo_di                          (rtx, rtx);
extern rtx        gen_vec_unpacku_hi_v64qi                       (rtx, rtx);
extern rtx        gen_vec_unpacku_hi_v32qi                       (rtx, rtx);
extern rtx        gen_vec_unpacku_hi_v16qi                       (rtx, rtx);
extern rtx        gen_vec_unpacku_hi_v32hi                       (rtx, rtx);
extern rtx        gen_vec_unpacku_hi_v16hi                       (rtx, rtx);
extern rtx        gen_vec_unpacku_hi_v8hi                        (rtx, rtx);
extern rtx        gen_vec_unpacku_hi_v16si                       (rtx, rtx);
extern rtx        gen_vec_unpacku_hi_v8si                        (rtx, rtx);
extern rtx        gen_vec_unpacku_hi_v4si                        (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_hi                          (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_si                          (rtx, rtx);
extern rtx        gen_vec_unpacks_hi_di                          (rtx, rtx);
extern rtx        gen_avx512bw_uavgv64qi3                        (rtx, rtx, rtx);
extern rtx        gen_avx512bw_uavgv64qi3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_uavgv32qi3                            (rtx, rtx, rtx);
extern rtx        gen_avx2_uavgv32qi3_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_uavgv16qi3                            (rtx, rtx, rtx);
extern rtx        gen_sse2_uavgv16qi3_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_uavgv32hi3                        (rtx, rtx, rtx);
extern rtx        gen_avx512bw_uavgv32hi3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_uavgv16hi3                            (rtx, rtx, rtx);
extern rtx        gen_avx2_uavgv16hi3_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_uavgv8hi3                             (rtx, rtx, rtx);
extern rtx        gen_sse2_uavgv8hi3_mask                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_maskmovdqu                            (rtx, rtx, rtx);
extern rtx        gen_ssse3_pmulhrswv4hi3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ssse3_pmulhrswv8hi3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_pmulhrswv16hi3_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_ssse3_pmulhrswv4hi3                        (rtx, rtx, rtx);
extern rtx        gen_ssse3_pmulhrswv8hi3                        (rtx, rtx, rtx);
extern rtx        gen_avx2_pmulhrswv16hi3                        (rtx, rtx, rtx);
extern rtx        gen_absv64qi2                                  (rtx, rtx);
extern rtx        gen_absv32qi2                                  (rtx, rtx);
extern rtx        gen_absv16qi2                                  (rtx, rtx);
extern rtx        gen_absv32hi2                                  (rtx, rtx);
extern rtx        gen_absv16hi2                                  (rtx, rtx);
extern rtx        gen_absv8hi2                                   (rtx, rtx);
extern rtx        gen_absv16si2                                  (rtx, rtx);
extern rtx        gen_absv8si2                                   (rtx, rtx);
extern rtx        gen_absv4si2                                   (rtx, rtx);
extern rtx        gen_absv8di2                                   (rtx, rtx);
extern rtx        gen_absv4di2                                   (rtx, rtx);
extern rtx        gen_absv2di2                                   (rtx, rtx);
extern rtx        gen_avx2_pblendw                               (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_roundps_sfix256                        (rtx, rtx, rtx);
extern rtx        gen_sse4_1_roundps_sfix                        (rtx, rtx, rtx);
extern rtx        gen_avx512f_roundps512                         (rtx, rtx, rtx);
extern rtx        gen_avx512f_roundpd512                         (rtx, rtx, rtx);
extern rtx        gen_avx512f_roundps512_sfix                    (rtx, rtx, rtx);
extern rtx        gen_avx512f_roundpd_vec_pack_sfix512           (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_roundpd_vec_pack_sfix256               (rtx, rtx, rtx, rtx);
extern rtx        gen_sse4_1_roundpd_vec_pack_sfix               (rtx, rtx, rtx, rtx);
extern rtx        gen_roundv16sf2                                (rtx, rtx);
extern rtx        gen_roundv8sf2                                 (rtx, rtx);
extern rtx        gen_roundv4sf2                                 (rtx, rtx);
extern rtx        gen_roundv8df2                                 (rtx, rtx);
extern rtx        gen_roundv4df2                                 (rtx, rtx);
extern rtx        gen_roundv2df2                                 (rtx, rtx);
extern rtx        gen_roundv16sf2_sfix                           (rtx, rtx);
extern rtx        gen_roundv8sf2_sfix                            (rtx, rtx);
extern rtx        gen_roundv4sf2_sfix                            (rtx, rtx);
extern rtx        gen_roundv8df2_vec_pack_sfix                   (rtx, rtx, rtx);
extern rtx        gen_roundv4df2_vec_pack_sfix                   (rtx, rtx, rtx);
extern rtx        gen_roundv2df2_vec_pack_sfix                   (rtx, rtx, rtx);
extern rtx        gen_avx512pf_gatherpfv16sisf                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512pf_gatherpfv8disf                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512pf_gatherpfv8sidf                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512pf_gatherpfv8didf                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512pf_scatterpfv16sisf                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512pf_scatterpfv8disf                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512pf_scatterpfv8sidf                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512pf_scatterpfv8didf                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_rotlv16qi3                                 (rtx, rtx, rtx);
extern rtx        gen_rotlv8hi3                                  (rtx, rtx, rtx);
extern rtx        gen_rotlv4si3                                  (rtx, rtx, rtx);
extern rtx        gen_rotlv2di3                                  (rtx, rtx, rtx);
extern rtx        gen_rotrv16qi3                                 (rtx, rtx, rtx);
extern rtx        gen_rotrv8hi3                                  (rtx, rtx, rtx);
extern rtx        gen_rotrv4si3                                  (rtx, rtx, rtx);
extern rtx        gen_rotrv2di3                                  (rtx, rtx, rtx);
extern rtx        gen_vrotrv16qi3                                (rtx, rtx, rtx);
extern rtx        gen_vrotrv8hi3                                 (rtx, rtx, rtx);
extern rtx        gen_vrotrv4si3                                 (rtx, rtx, rtx);
extern rtx        gen_vrotrv2di3                                 (rtx, rtx, rtx);
extern rtx        gen_vrotlv16qi3                                (rtx, rtx, rtx);
extern rtx        gen_vrotlv8hi3                                 (rtx, rtx, rtx);
extern rtx        gen_vrotlv4si3                                 (rtx, rtx, rtx);
extern rtx        gen_vrotlv2di3                                 (rtx, rtx, rtx);
extern rtx        gen_vlshrv16qi3                                (rtx, rtx, rtx);
extern rtx        gen_vlshrv8hi3                                 (rtx, rtx, rtx);
extern rtx        gen_vlshrv4si3                                 (rtx, rtx, rtx);
extern rtx        gen_vlshrv2di3                                 (rtx, rtx, rtx);
extern rtx        gen_vlshrv16si3                                (rtx, rtx, rtx);
extern rtx        gen_vlshrv8di3                                 (rtx, rtx, rtx);
extern rtx        gen_vlshrv8si3                                 (rtx, rtx, rtx);
extern rtx        gen_vlshrv4di3                                 (rtx, rtx, rtx);
extern rtx        gen_vashrv8hi3                                 (rtx, rtx, rtx);
extern rtx        gen_vashrv8hi3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vashrv16qi3                                (rtx, rtx, rtx);
extern rtx        gen_vashrv2di3                                 (rtx, rtx, rtx);
extern rtx        gen_vashrv2di3_mask                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vashrv4si3                                 (rtx, rtx, rtx);
extern rtx        gen_vashrv16si3                                (rtx, rtx, rtx);
extern rtx        gen_vashrv8si3                                 (rtx, rtx, rtx);
extern rtx        gen_vashlv16qi3                                (rtx, rtx, rtx);
extern rtx        gen_vashlv8hi3                                 (rtx, rtx, rtx);
extern rtx        gen_vashlv4si3                                 (rtx, rtx, rtx);
extern rtx        gen_vashlv2di3                                 (rtx, rtx, rtx);
extern rtx        gen_vashlv16si3                                (rtx, rtx, rtx);
extern rtx        gen_vashlv8di3                                 (rtx, rtx, rtx);
extern rtx        gen_vashlv8si3                                 (rtx, rtx, rtx);
extern rtx        gen_vashlv4di3                                 (rtx, rtx, rtx);
extern rtx        gen_ashlv64qi3                                 (rtx, rtx, rtx);
extern rtx        gen_lshrv64qi3                                 (rtx, rtx, rtx);
extern rtx        gen_ashrv64qi3                                 (rtx, rtx, rtx);
extern rtx        gen_ashlv32qi3                                 (rtx, rtx, rtx);
extern rtx        gen_lshrv32qi3                                 (rtx, rtx, rtx);
extern rtx        gen_ashrv32qi3                                 (rtx, rtx, rtx);
extern rtx        gen_ashlv16qi3                                 (rtx, rtx, rtx);
extern rtx        gen_lshrv16qi3                                 (rtx, rtx, rtx);
extern rtx        gen_ashrv16qi3                                 (rtx, rtx, rtx);
extern rtx        gen_ashrv2di3                                  (rtx, rtx, rtx);
extern rtx        gen_xop_vmfrczv4sf2                            (rtx, rtx);
extern rtx        gen_xop_vmfrczv2df2                            (rtx, rtx);
extern rtx        gen_avx_vzeroall                               (void);
extern rtx        gen_avx2_permv4di                              (rtx, rtx, rtx);
extern rtx        gen_avx2_permv4df                              (rtx, rtx, rtx);
extern rtx        gen_avx512f_permv8di                           (rtx, rtx, rtx);
extern rtx        gen_avx512f_permv8df                           (rtx, rtx, rtx);
extern rtx        gen_avx512vl_permv4di_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_permv4df_mask                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_permv8di_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_permv8df_mask                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermilv8df                        (rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermilv8df_mask                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vpermilv4df                            (rtx, rtx, rtx);
extern rtx        gen_avx_vpermilv4df_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vpermilv2df                            (rtx, rtx, rtx);
extern rtx        gen_avx_vpermilv2df_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermilv16sf                       (rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermilv16sf_mask                  (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vpermilv8sf                            (rtx, rtx, rtx);
extern rtx        gen_avx_vpermilv8sf_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vpermilv4sf                            (rtx, rtx, rtx);
extern rtx        gen_avx_vpermilv4sf_mask                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv16si3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv16sf3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv8di3_maskz              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermi2varv8df3_maskz              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv8si3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv8sf3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4di3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4df3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4si3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv4sf3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv2di3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv2df3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermi2varv64qi3_maskz            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv16qi3_maskz            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv32qi3_maskz            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv8hi3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermi2varv16hi3_maskz            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermi2varv32hi3_maskz            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv16si3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv16sf3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv8di3_maskz              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_vpermt2varv8df3_maskz              (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv8si3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv8sf3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4di3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4df3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4si3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv4sf3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv2di3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv2df3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermt2varv64qi3_maskz            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv16qi3_maskz            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv32qi3_maskz            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv8hi3_maskz             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vpermt2varv16hi3_maskz            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512bw_vpermt2varv32hi3_maskz            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vperm2f128v8si3                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vperm2f128v8sf3                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vperm2f128v4df3                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vinsertv8si                       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vinsertv8sf                       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vinsertv4di                       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_vinsertv4df                       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vinsertf128v32qi                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vinsertf128v16hi                       (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vinsertf128v8si                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vinsertf128v4di                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vinsertf128v8sf                        (rtx, rtx, rtx, rtx);
extern rtx        gen_avx_vinsertf128v4df                        (rtx, rtx, rtx, rtx);
extern rtx        gen_maskloadv4sfv4si                           (rtx, rtx, rtx);
extern rtx        gen_maskloadv2dfv2di                           (rtx, rtx, rtx);
extern rtx        gen_maskloadv8sfv8si                           (rtx, rtx, rtx);
extern rtx        gen_maskloadv4dfv4di                           (rtx, rtx, rtx);
extern rtx        gen_maskloadv4siv4si                           (rtx, rtx, rtx);
extern rtx        gen_maskloadv2div2di                           (rtx, rtx, rtx);
extern rtx        gen_maskloadv8siv8si                           (rtx, rtx, rtx);
extern rtx        gen_maskloadv4div4di                           (rtx, rtx, rtx);
extern rtx        gen_maskloadv16sihi                            (rtx, rtx, rtx);
extern rtx        gen_maskloadv8siqi                             (rtx, rtx, rtx);
extern rtx        gen_maskloadv4siqi                             (rtx, rtx, rtx);
extern rtx        gen_maskloadv8diqi                             (rtx, rtx, rtx);
extern rtx        gen_maskloadv4diqi                             (rtx, rtx, rtx);
extern rtx        gen_maskloadv2diqi                             (rtx, rtx, rtx);
extern rtx        gen_maskloadv16sfhi                            (rtx, rtx, rtx);
extern rtx        gen_maskloadv8sfqi                             (rtx, rtx, rtx);
extern rtx        gen_maskloadv4sfqi                             (rtx, rtx, rtx);
extern rtx        gen_maskloadv8dfqi                             (rtx, rtx, rtx);
extern rtx        gen_maskloadv4dfqi                             (rtx, rtx, rtx);
extern rtx        gen_maskloadv2dfqi                             (rtx, rtx, rtx);
extern rtx        gen_maskloadv64qidi                            (rtx, rtx, rtx);
extern rtx        gen_maskloadv16qihi                            (rtx, rtx, rtx);
extern rtx        gen_maskloadv32qisi                            (rtx, rtx, rtx);
extern rtx        gen_maskloadv32hisi                            (rtx, rtx, rtx);
extern rtx        gen_maskloadv16hihi                            (rtx, rtx, rtx);
extern rtx        gen_maskloadv8hiqi                             (rtx, rtx, rtx);
extern rtx        gen_maskstorev4sfv4si                          (rtx, rtx, rtx);
extern rtx        gen_maskstorev2dfv2di                          (rtx, rtx, rtx);
extern rtx        gen_maskstorev8sfv8si                          (rtx, rtx, rtx);
extern rtx        gen_maskstorev4dfv4di                          (rtx, rtx, rtx);
extern rtx        gen_maskstorev4siv4si                          (rtx, rtx, rtx);
extern rtx        gen_maskstorev2div2di                          (rtx, rtx, rtx);
extern rtx        gen_maskstorev8siv8si                          (rtx, rtx, rtx);
extern rtx        gen_maskstorev4div4di                          (rtx, rtx, rtx);
extern rtx        gen_maskstorev16sihi                           (rtx, rtx, rtx);
extern rtx        gen_maskstorev8siqi                            (rtx, rtx, rtx);
extern rtx        gen_maskstorev4siqi                            (rtx, rtx, rtx);
extern rtx        gen_maskstorev8diqi                            (rtx, rtx, rtx);
extern rtx        gen_maskstorev4diqi                            (rtx, rtx, rtx);
extern rtx        gen_maskstorev2diqi                            (rtx, rtx, rtx);
extern rtx        gen_maskstorev16sfhi                           (rtx, rtx, rtx);
extern rtx        gen_maskstorev8sfqi                            (rtx, rtx, rtx);
extern rtx        gen_maskstorev4sfqi                            (rtx, rtx, rtx);
extern rtx        gen_maskstorev8dfqi                            (rtx, rtx, rtx);
extern rtx        gen_maskstorev4dfqi                            (rtx, rtx, rtx);
extern rtx        gen_maskstorev2dfqi                            (rtx, rtx, rtx);
extern rtx        gen_maskstorev64qidi                           (rtx, rtx, rtx);
extern rtx        gen_maskstorev16qihi                           (rtx, rtx, rtx);
extern rtx        gen_maskstorev32qisi                           (rtx, rtx, rtx);
extern rtx        gen_maskstorev32hisi                           (rtx, rtx, rtx);
extern rtx        gen_maskstorev16hihi                           (rtx, rtx, rtx);
extern rtx        gen_maskstorev8hiqi                            (rtx, rtx, rtx);
extern rtx        gen_cbranchv4si4                               (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchv2di4                               (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchv8si4                               (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchv4di4                               (rtx, rtx, rtx, rtx);
extern rtx        gen_vec_initv32qi                              (rtx, rtx);
extern rtx        gen_vec_initv16hi                              (rtx, rtx);
extern rtx        gen_vec_initv8si                               (rtx, rtx);
extern rtx        gen_vec_initv4di                               (rtx, rtx);
extern rtx        gen_vec_initv8sf                               (rtx, rtx);
extern rtx        gen_vec_initv4df                               (rtx, rtx);
extern rtx        gen_vec_initv16si                              (rtx, rtx);
extern rtx        gen_vec_initv16sf                              (rtx, rtx);
extern rtx        gen_vec_initv8di                               (rtx, rtx);
extern rtx        gen_vec_initv8df                               (rtx, rtx);
extern rtx        gen_vec_initv32hi                              (rtx, rtx);
extern rtx        gen_vec_initv64qi                              (rtx, rtx);
extern rtx        gen_vcvtps2ph_mask                             (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vcvtps2ph                                  (rtx, rtx, rtx);
extern rtx        gen_avx2_gathersiv2di                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gathersiv2df                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gathersiv4di                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gathersiv4df                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gathersiv4si                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gathersiv4sf                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gathersiv8si                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gathersiv8sf                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gatherdiv2di                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gatherdiv2df                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gatherdiv4di                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gatherdiv4df                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gatherdiv4si                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gatherdiv4sf                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gatherdiv8si                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx2_gatherdiv8sf                          (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_gathersiv16si                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_gathersiv16sf                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_gathersiv8di                       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_gathersiv8df                       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gathersiv8si                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gathersiv8sf                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gathersiv4di                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gathersiv4df                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gathersiv4si                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gathersiv4sf                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gathersiv2di                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gathersiv2df                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_gatherdiv16si                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_gatherdiv16sf                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_gatherdiv8di                       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_gatherdiv8df                       (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gatherdiv8si                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gatherdiv8sf                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gatherdiv4di                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gatherdiv4df                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gatherdiv4si                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gatherdiv4sf                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gatherdiv2di                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_gatherdiv2df                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scattersiv16si                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scattersiv16sf                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scattersiv8di                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scattersiv8df                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scattersiv8si                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scattersiv8sf                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scattersiv4di                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scattersiv4df                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scattersiv4si                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scattersiv4sf                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scattersiv2di                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scattersiv2df                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scatterdiv16si                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scatterdiv16sf                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scatterdiv8di                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_scatterdiv8df                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scatterdiv8si                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scatterdiv8sf                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scatterdiv4di                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scatterdiv4df                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scatterdiv4si                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scatterdiv4sf                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scatterdiv2di                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_scatterdiv2df                     (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_expandv16si_maskz                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_expandv16sf_maskz                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_expandv8di_maskz                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512f_expandv8df_maskz                   (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv8si_maskz                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv8sf_maskz                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv4di_maskz                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv4df_maskz                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv4si_maskz                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv4sf_maskz                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv2di_maskz                  (rtx, rtx, rtx, rtx);
extern rtx        gen_avx512vl_expandv2df_maskz                  (rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52huqv8di_maskz                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52huqv4di_maskz                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52huqv2di_maskz                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52luqv8di_maskz                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52luqv4di_maskz                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_vpamdd52luqv2di_maskz                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sse2_lfence                                (void);
extern rtx        gen_sse_sfence                                 (void);
extern rtx        gen_sse2_mfence                                (void);
extern rtx        gen_mem_thread_fence                           (rtx);
extern rtx        gen_atomic_loadqi                              (rtx, rtx, rtx);
extern rtx        gen_atomic_loadhi                              (rtx, rtx, rtx);
extern rtx        gen_atomic_loadsi                              (rtx, rtx, rtx);
extern rtx        gen_atomic_loaddi                              (rtx, rtx, rtx);
extern rtx        gen_atomic_storeqi                             (rtx, rtx, rtx);
extern rtx        gen_atomic_storehi                             (rtx, rtx, rtx);
extern rtx        gen_atomic_storesi                             (rtx, rtx, rtx);
extern rtx        gen_atomic_storedi                             (rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapqi                  (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swaphi                  (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapsi                  (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapdi                  (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapti                  (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);

#endif /* GCC_INSN_FLAGS_H */
