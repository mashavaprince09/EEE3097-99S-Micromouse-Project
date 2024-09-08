/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MicroMouseTemplate_private.h
 *
 * Code generated for Simulink model 'MicroMouseTemplate'.
 *
 * Model version                  : 3.22
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Sep  7 13:46:51 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef MicroMouseTemplate_private_h_
#define MicroMouseTemplate_private_h_
#include "rtwtypes.h"
#include "MicroMouseTemplate.h"
#include "MicroMouseTemplate_types.h"

extern real_T rt_roundd(real_T u);
extern void MicroMou_MATLABSystem1_Init(DW_MATLABSystem1_MicroMouseTe_T *localDW,
  P_MATLABSystem1_MicroMouseTem_T *localP);
extern void MicroMouseTem_MATLABSystem1(real_T rtu_0,
  B_MATLABSystem1_MicroMouseTem_T *localB, DW_MATLABSystem1_MicroMouseTe_T
  *localDW, P_MATLABSystem1_MicroMouseTem_T *localP);
extern void MicroMou_MATLABSystem3_Init(DW_MATLABSystem3_MicroMouseTe_T *localDW,
  P_MATLABSystem3_MicroMouseTem_T *localP);
extern void MicroMouseTem_MATLABSystem3(real_T rtu_0,
  B_MATLABSystem3_MicroMouseTem_T *localB, DW_MATLABSystem3_MicroMouseTe_T
  *localDW, P_MATLABSystem3_MicroMouseTem_T *localP);

#endif                                 /* MicroMouseTemplate_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
