/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MicroMouseTemplate.h
 *
 * Code generated for Simulink model 'MicroMouseTemplate'.
 *
 * Model version                  : 3.49
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Sep 12 21:30:47 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef MicroMouseTemplate_h_
#define MicroMouseTemplate_h_
#ifndef MicroMouseTemplate_COMMON_INCLUDES_
#define MicroMouseTemplate_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "main.h"
#endif                                 /* MicroMouseTemplate_COMMON_INCLUDES_ */

#include "MicroMouseTemplate_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* user code (top of header file) */
#include "MicroMouseProgramming\Core\Inc\IMU.h"
#include "MicroMouseProgramming\Core\Inc\CustomWhile.h"
#include "MicroMouseProgramming\Core\Inc\Motors.h"

/* Block signals for system '<S33>/MATLAB System1' */
typedef struct {
  real_T MATLABSystem1[25];            /* '<S33>/MATLAB System1' */
  real_T rtu_0[25];
} B_MATLABSystem1_MicroMouseTem_T;

/* Block states (default storage) for system '<S33>/MATLAB System1' */
typedef struct {
  CircularBuffer_MicroMouseTemp_T obj; /* '<S33>/MATLAB System1' */
  boolean_T objisempty;                /* '<S33>/MATLAB System1' */
} DW_MATLABSystem1_MicroMouseTe_T;

/* Block signals for system '<S33>/MATLAB System3' */
typedef struct {
  real_T MATLABSystem3[10];            /* '<S33>/MATLAB System3' */
  real_T rtu_0[10];
} B_MATLABSystem3_MicroMouseTem_T;

/* Block states (default storage) for system '<S33>/MATLAB System3' */
typedef struct {
  CircularBuffer_MicroMouseTe_p_T obj; /* '<S33>/MATLAB System3' */
  boolean_T objisempty;                /* '<S33>/MATLAB System3' */
} DW_MATLABSystem3_MicroMouseTe_T;

/* Block signals (default storage) */
typedef struct {
  uint16_T Flip[8];                    /* '<S9>/Flip' */
  uint16_T CastToDouble[8];            /* '<S35>/Cast To Double' */
  GPIO_TypeDef * portNameLoc;
  real_T leftWheelbackward;            /* '<Root>/HelloMicroMouse!' */
  real_T leftWheelforward;             /* '<Root>/HelloMicroMouse!' */
  real_T rightWheelbackward;           /* '<Root>/HelloMicroMouse!' */
  real_T rightWheelforward;            /* '<Root>/HelloMicroMouse!' */
  real_T maxV;
  real_T maxV_m;
  real_T maxV_c;
  boolean_T LED0;                      /* '<Root>/HelloMicroMouse!' */
  boolean_T LED2;                      /* '<Root>/HelloMicroMouse!' */
  boolean_T LED1;                      /* '<Root>/HelloMicroMouse!' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem6;/* '<S33>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem5;/* '<S33>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem4_c;/* '<S33>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem3_c;/* '<S33>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem2_ci;/* '<S33>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem1_ci;/* '<S33>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem2_c;/* '<S33>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem1_c;/* '<S33>/MATLAB System1' */
  B_MATLABSystem3_MicroMouseTem_T MATLABSystem4;/* '<S33>/MATLAB System3' */
  B_MATLABSystem3_MicroMouseTem_T MATLABSystem3;/* '<S33>/MATLAB System3' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem2;/* '<S33>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem1;/* '<S33>/MATLAB System1' */
} B_MicroMouseTemplate_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S32>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_g;/* '<S28>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_n;/* '<S26>/PWM Output' */
  real_T baseline;                     /* '<Root>/HelloMicroMouse!' */
  real_T counter;                      /* '<Root>/HelloMicroMouse!' */
  real_T sum;                          /* '<Root>/HelloMicroMouse!' */
  struct {
    uint_T is_c2_MicroMouseTemplate:3; /* '<Root>/HelloMicroMouse!' */
    uint_T is_ButtonPressed2:2;        /* '<Root>/HelloMicroMouse!' */
    uint_T is_active_c2_MicroMouseTemplate:1;/* '<Root>/HelloMicroMouse!' */
  } bitsForTID1;

  uint8_T temporalCounter_i1;          /* '<Root>/HelloMicroMouse!' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem6;/* '<S33>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem5;/* '<S33>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem4_c;/* '<S33>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem3_c;/* '<S33>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem2_ci;/* '<S33>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem1_ci;/* '<S33>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem2_c;/* '<S33>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem1_c;/* '<S33>/MATLAB System1' */
  DW_MATLABSystem3_MicroMouseTe_T MATLABSystem4;/* '<S33>/MATLAB System3' */
  DW_MATLABSystem3_MicroMouseTe_T MATLABSystem3;/* '<S33>/MATLAB System3' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem2;/* '<S33>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem1;/* '<S33>/MATLAB System1' */
} DW_MicroMouseTemplate_T;

/* Parameters for system: '<S33>/MATLAB System1' */
struct P_MATLABSystem1_MicroMouseTem_T_ {
  real_T MATLABSystem1_InitialCondition;/* Expression: 0
                                         * Referenced by: '<S33>/MATLAB System1'
                                         */
};

/* Parameters for system: '<S33>/MATLAB System3' */
struct P_MATLABSystem3_MicroMouseTem_T_ {
  real_T MATLABSystem3_InitialCondition;/* Expression: 0
                                         * Referenced by: '<S33>/MATLAB System3'
                                         */
};

/* Parameters (default storage) */
struct P_MicroMouseTemplate_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 10
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Quantizer1_Interval;          /* Expression: 0.01
                                        * Referenced by: '<S1>/Quantizer1'
                                        */
  real_T Quantizer1_Interval_o;        /* Expression: 0.01
                                        * Referenced by: '<S8>/Quantizer1'
                                        */
  real_T Quantizer1_Interval_h;        /* Expression: 0.01
                                        * Referenced by: '<S6>/Quantizer1'
                                        */
  int32_T DataStoreMemory2_InitialValue;
                            /* Computed Parameter: DataStoreMemory2_InitialValue
                             * Referenced by: '<S2>/Data Store Memory2'
                             */
  int32_T DataStoreMemory4_InitialValue;
                            /* Computed Parameter: DataStoreMemory4_InitialValue
                             * Referenced by: '<S2>/Data Store Memory4'
                             */
  real32_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<S10>/Data Store Memory'
                              */
  real32_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<S10>/Data Store Memory1'
                             */
  uint16_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S1>/Gain2'
                                        */
  uint16_T Gain2_Gain_o;               /* Computed Parameter: Gain2_Gain_o
                                        * Referenced by: '<S8>/Gain2'
                                        */
  uint16_T Gain2_Gain_f;               /* Computed Parameter: Gain2_Gain_f
                                        * Referenced by: '<S6>/Gain2'
                                        */
  uint16_T DataStoreMemory1_InitialValue_j;
                          /* Computed Parameter: DataStoreMemory1_InitialValue_j
                           * Referenced by: '<S2>/Data Store Memory1'
                           */
  uint16_T Constant_Value_b;           /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S30>/Constant'
                                        */
  uint16_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S30>/Constant1'
                                        */
  uint16_T DataStoreMemory_InitialValue_p;
                           /* Computed Parameter: DataStoreMemory_InitialValue_p
                            * Referenced by: '<S9>/Data Store Memory'
                            */
  uint16_T DataStoreMemory1_InitialValue_p;
                          /* Computed Parameter: DataStoreMemory1_InitialValue_p
                           * Referenced by: '<S9>/Data Store Memory1'
                           */
  uint16_T DataStoreMemory2_InitialValue_p;
                          /* Computed Parameter: DataStoreMemory2_InitialValue_p
                           * Referenced by: '<S9>/Data Store Memory2'
                           */
  boolean_T DataStoreMemory_InitialValue_p4;
                          /* Computed Parameter: DataStoreMemory_InitialValue_p4
                           * Referenced by: '<S2>/Data Store Memory'
                           */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem6;/* '<S33>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem5;/* '<S33>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem4_c;/* '<S33>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem3_c;/* '<S33>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem2_ci;/* '<S33>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem1_ci;/* '<S33>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem2_c;/* '<S33>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem1_c;/* '<S33>/MATLAB System1' */
  P_MATLABSystem3_MicroMouseTem_T MATLABSystem4;/* '<S33>/MATLAB System3' */
  P_MATLABSystem3_MicroMouseTem_T MATLABSystem3;/* '<S33>/MATLAB System3' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem2;/* '<S33>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem1;/* '<S33>/MATLAB System1' */
};

/* Code_Instrumentation_Declarations_Placeholder */

/* Real-time Model Data Structure */
struct tag_RTM_MicroMouseTemplate_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_MicroMouseTemplate_T MicroMouseTemplate_P;

/* Block signals (default storage) */
extern B_MicroMouseTemplate_T MicroMouseTemplate_B;

/* Block states (default storage) */
extern DW_MicroMouseTemplate_T MicroMouseTemplate_DW;

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern real32_T IMU_Accel[3];          /* '<S10>/Data Store Memory' */
extern real32_T IMU_Gyro[3];           /* '<S10>/Data Store Memory1' */
extern int32_T currTicksRS;            /* '<S2>/Data Store Memory2' */
extern int32_T currTicksLS;            /* '<S2>/Data Store Memory4' */
extern uint16_T Thresholds[8];         /* '<S2>/Data Store Memory1' */
extern uint16_T ADC1s[9];              /* '<S9>/Data Store Memory' */
extern uint16_T ADC_H[9];              /* '<S9>/Data Store Memory1' */
extern uint16_T ADC_L[9];              /* '<S9>/Data Store Memory2' */
extern boolean_T Detections[8];        /* '<S2>/Data Store Memory' */

/* External function called from main */
extern void MicroMouseTemplate_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void MicroMouseTemplate_initialize(void);
extern void MicroMouseTemplate_step0(void);
extern void MicroMouseTemplate_step1(void);
extern void MicroMouseTemplate_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MicroMouseTemplate_T *const MicroMouseTemplate_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Pulse Generator' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Diff' : Unused code path elimination
 * Block '<S54>/TSamp' : Unused code path elimination
 * Block '<S54>/UD' : Unused code path elimination
 * Block '<S13>/LS' : Unused code path elimination
 * Block '<S13>/Unit Delay' : Unused code path elimination
 * Block '<S30>/Cast1' : Eliminate redundant data type conversion
 * Block '<S30>/Cast3' : Eliminate redundant data type conversion
 * Block '<S35>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S35>/Rate Transition1' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MicroMouseTemplate'
 * '<S1>'   : 'MicroMouseTemplate/Bit_to_Volts'
 * '<S2>'   : 'MicroMouseTemplate/Detections and Thresholds'
 * '<S3>'   : 'MicroMouseTemplate/GPIO for IR LEDs'
 * '<S4>'   : 'MicroMouseTemplate/HelloMicroMouse!'
 * '<S5>'   : 'MicroMouseTemplate/IR LED Pattern'
 * '<S6>'   : 'MicroMouseTemplate/Left_volts'
 * '<S7>'   : 'MicroMouseTemplate/Motors'
 * '<S8>'   : 'MicroMouseTemplate/Right_volts'
 * '<S9>'   : 'MicroMouseTemplate/Subsystem'
 * '<S10>'  : 'MicroMouseTemplate/Subsystem1'
 * '<S11>'  : 'MicroMouseTemplate/Subsystem2'
 * '<S12>'  : 'MicroMouseTemplate/Subsystem3'
 * '<S13>'  : 'MicroMouseTemplate/Subsystem4'
 * '<S14>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_LEFT1'
 * '<S15>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_RIGHT1'
 * '<S16>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_LEFT1/ECSoC'
 * '<S17>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_LEFT1/ECSoC/ECSimCodegen'
 * '<S18>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_RIGHT1/ECSoC'
 * '<S19>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_RIGHT1/ECSoC/ECSimCodegen'
 * '<S20>'  : 'MicroMouseTemplate/Motors/MOTOR_EN'
 * '<S21>'  : 'MicroMouseTemplate/Motors/PWM Output'
 * '<S22>'  : 'MicroMouseTemplate/Motors/PWM Output1'
 * '<S23>'  : 'MicroMouseTemplate/Motors/MOTOR_EN/ECSoC'
 * '<S24>'  : 'MicroMouseTemplate/Motors/MOTOR_EN/ECSoC/ECSimCodegen'
 * '<S25>'  : 'MicroMouseTemplate/Motors/PWM Output/ECSoC'
 * '<S26>'  : 'MicroMouseTemplate/Motors/PWM Output/ECSoC/ECSimCodegen'
 * '<S27>'  : 'MicroMouseTemplate/Motors/PWM Output1/ECSoC'
 * '<S28>'  : 'MicroMouseTemplate/Motors/PWM Output1/ECSoC/ECSimCodegen'
 * '<S29>'  : 'MicroMouseTemplate/Subsystem/ADC2 IN10  IN1'
 * '<S30>'  : 'MicroMouseTemplate/Subsystem/get Highs and Lows'
 * '<S31>'  : 'MicroMouseTemplate/Subsystem/ADC2 IN10  IN1/ECSoC'
 * '<S32>'  : 'MicroMouseTemplate/Subsystem/ADC2 IN10  IN1/ECSoC/ECSimCodegen'
 * '<S33>'  : 'MicroMouseTemplate/Subsystem/get Highs and Lows/Subsystem'
 * '<S34>'  : 'MicroMouseTemplate/Subsystem/get Highs and Lows/Subsystem1'
 * '<S35>'  : 'MicroMouseTemplate/Subsystem/get Highs and Lows/Subsystem2'
 * '<S36>'  : 'MicroMouseTemplate/Subsystem2/CTRL_LEDs'
 * '<S37>'  : 'MicroMouseTemplate/Subsystem2/LED_0'
 * '<S38>'  : 'MicroMouseTemplate/Subsystem2/LED_1'
 * '<S39>'  : 'MicroMouseTemplate/Subsystem2/LED_2'
 * '<S40>'  : 'MicroMouseTemplate/Subsystem2/CTRL_LEDs/ECSoC'
 * '<S41>'  : 'MicroMouseTemplate/Subsystem2/CTRL_LEDs/ECSoC/ECSimCodegen'
 * '<S42>'  : 'MicroMouseTemplate/Subsystem2/LED_0/ECSoC'
 * '<S43>'  : 'MicroMouseTemplate/Subsystem2/LED_0/ECSoC/ECSimCodegen'
 * '<S44>'  : 'MicroMouseTemplate/Subsystem2/LED_1/ECSoC'
 * '<S45>'  : 'MicroMouseTemplate/Subsystem2/LED_1/ECSoC/ECSimCodegen'
 * '<S46>'  : 'MicroMouseTemplate/Subsystem2/LED_2/ECSoC'
 * '<S47>'  : 'MicroMouseTemplate/Subsystem2/LED_2/ECSoC/ECSimCodegen'
 * '<S48>'  : 'MicroMouseTemplate/Subsystem3/SW_1'
 * '<S49>'  : 'MicroMouseTemplate/Subsystem3/SW_2'
 * '<S50>'  : 'MicroMouseTemplate/Subsystem3/SW_1/ECSoC'
 * '<S51>'  : 'MicroMouseTemplate/Subsystem3/SW_1/ECSoC/ECSimCodegen'
 * '<S52>'  : 'MicroMouseTemplate/Subsystem3/SW_2/ECSoC'
 * '<S53>'  : 'MicroMouseTemplate/Subsystem3/SW_2/ECSoC/ECSimCodegen'
 * '<S54>'  : 'MicroMouseTemplate/Subsystem4/Discrete Derivative1'
 */
#endif                                 /* MicroMouseTemplate_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
