/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MicroMouseTemplate.h
 *
 * Code generated for Simulink model 'MicroMouseTemplate'.
 *
 * Model version                  : 3.230
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Sep 22 03:04:01 2024
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

/* Block signals for system '<S56>/MATLAB System1' */
typedef struct {
  real_T MATLABSystem1[25];            /* '<S56>/MATLAB System1' */
  real_T rtu_0[25];
} B_MATLABSystem1_MicroMouseTem_T;

/* Block states (default storage) for system '<S56>/MATLAB System1' */
typedef struct {
  CircularBuffer_MicroMouseTemp_T obj; /* '<S56>/MATLAB System1' */
  boolean_T objisempty;                /* '<S56>/MATLAB System1' */
} DW_MATLABSystem1_MicroMouseTe_T;

/* Block signals for system '<S56>/MATLAB System3' */
typedef struct {
  real_T MATLABSystem3[10];            /* '<S56>/MATLAB System3' */
  real_T rtu_0[10];
} B_MATLABSystem3_MicroMouseTem_T;

/* Block states (default storage) for system '<S56>/MATLAB System3' */
typedef struct {
  CircularBuffer_MicroMouseTe_p_T obj; /* '<S56>/MATLAB System3' */
  boolean_T objisempty;                /* '<S56>/MATLAB System3' */
} DW_MATLABSystem3_MicroMouseTe_T;

/* Block signals (default storage) */
typedef struct {
  uint16_T CastToDouble[8];            /* '<S58>/Cast To Double' */
  uint16_T Flip[8];                    /* '<S14>/Flip' */
  GPIO_TypeDef * portNameLoc;
  real_T leftWheelbackward;            /* '<Root>/HelloMicroMouse!' */
  real_T leftWheelforward;             /* '<Root>/HelloMicroMouse!' */
  real_T rightWheelbackward;           /* '<Root>/HelloMicroMouse!' */
  real_T rightWheelforward;            /* '<Root>/HelloMicroMouse!' */
  real_T LED_FWD_LEFT_ENABLE;          /* '<Root>/HelloMicroMouse!' */
  real_T LED_FWD_RIGHT_ENABLE;         /* '<Root>/HelloMicroMouse!' */
  real_T LED_LEFT_ENABLE;              /* '<Root>/HelloMicroMouse!' */
  real_T LED_RIGHT_ENABLE;             /* '<Root>/HelloMicroMouse!' */
  real_T LED_DOWN_LEFT_ENABLE;         /* '<Root>/HelloMicroMouse!' */
  real_T LED_DOWN_RIGHT_ENABLE;        /* '<Root>/HelloMicroMouse!' */
  real_T LED_MOT_RIGHT_ENABLE;         /* '<Root>/HelloMicroMouse!' */
  real_T LED_MOT_LEFT_ENABLE;          /* '<Root>/HelloMicroMouse!' */
  real_T PulseGenerator;               /* '<S12>/Pulse Generator' */
  real_T Quantizer1;                   /* '<S3>/Quantizer1' */
  real_T Quantizer1_m;                 /* '<S3>/Quantizer1' */
  boolean_T LED0;                      /* '<Root>/HelloMicroMouse!' */
  boolean_T LED2;                      /* '<Root>/HelloMicroMouse!' */
  boolean_T LED1;                      /* '<Root>/HelloMicroMouse!' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem6;/* '<S56>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem5;/* '<S56>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem4_c;/* '<S56>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem3_c;/* '<S56>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem2_ci;/* '<S56>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem1_ci;/* '<S56>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem2_c;/* '<S56>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem1_c;/* '<S56>/MATLAB System1' */
  B_MATLABSystem3_MicroMouseTem_T MATLABSystem4;/* '<S56>/MATLAB System3' */
  B_MATLABSystem3_MicroMouseTem_T MATLABSystem3;/* '<S56>/MATLAB System3' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem2;/* '<S56>/MATLAB System1' */
  B_MATLABSystem1_MicroMouseTem_T MATLABSystem1;/* '<S56>/MATLAB System1' */
} B_MicroMouseTemplate_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S55>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Mi_T obj_g;/* '<S51>/PWM Output' */
  stm32cube_blocks_PWMOutput_Mi_T obj_n;/* '<S49>/PWM Output' */
  real_T RateTransition_Buffer;        /* '<S58>/Rate Transition' */
  real_T RateTransition1_Buffer;       /* '<S58>/Rate Transition1' */
  real_T counter;                      /* '<Root>/HelloMicroMouse!' */
  real_T baseline_LS_FWD;              /* '<Root>/HelloMicroMouse!' */
  real_T baseline_RS_FWD;              /* '<Root>/HelloMicroMouse!' */
  real_T baseline_DOWN_LS;             /* '<Root>/HelloMicroMouse!' */
  real_T baseline_DOWN_RS;             /* '<Root>/HelloMicroMouse!' */
  real_T baseline_LS;                  /* '<Root>/HelloMicroMouse!' */
  real_T baseline_RS;                  /* '<Root>/HelloMicroMouse!' */
  real_T c;                            /* '<Root>/HelloMicroMouse!' */
  real_T start;                        /* '<Root>/HelloMicroMouse!' */
  real_T turn;                         /* '<Root>/HelloMicroMouse!' */
  real_T minLeftADC;                   /* '<Root>/HelloMicroMouse!' */
  real_T minRightADC;                  /* '<Root>/HelloMicroMouse!' */
  real_T speed;                        /* '<Root>/HelloMicroMouse!' */
  real_T adjustmentSpeed;              /* '<Root>/HelloMicroMouse!' */
  real_T minSpeed;                     /* '<Root>/HelloMicroMouse!' */
  int32_T clockTickCounter;            /* '<S12>/Pulse Generator' */
  struct {
    uint_T is_Empty_Path11:4;          /* '<Root>/HelloMicroMouse!' */
    uint_T is_c2_MicroMouseTemplate:3; /* '<Root>/HelloMicroMouse!' */
    uint_T is_active_c2_MicroMouseTemplate:1;/* '<Root>/HelloMicroMouse!' */
  } bitsForTID0;

  volatile uint16_T TmpRTBAtMaxofElementsOutport1_B;/* synthesized block */
  volatile uint16_T TmpRTBAtMaxofElements7Outport1_;/* synthesized block */
  volatile uint16_T TmpRTBAtMaxofElements8Outport1_;/* synthesized block */
  volatile uint16_T TmpRTBAtMaxofElements15Outport1;/* synthesized block */
  uint8_T temporalCounter_i1;          /* '<Root>/HelloMicroMouse!' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem6;/* '<S56>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem5;/* '<S56>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem4_c;/* '<S56>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem3_c;/* '<S56>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem2_ci;/* '<S56>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem1_ci;/* '<S56>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem2_c;/* '<S56>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem1_c;/* '<S56>/MATLAB System1' */
  DW_MATLABSystem3_MicroMouseTe_T MATLABSystem4;/* '<S56>/MATLAB System3' */
  DW_MATLABSystem3_MicroMouseTe_T MATLABSystem3;/* '<S56>/MATLAB System3' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem2;/* '<S56>/MATLAB System1' */
  DW_MATLABSystem1_MicroMouseTe_T MATLABSystem1;/* '<S56>/MATLAB System1' */
} DW_MicroMouseTemplate_T;

/* Parameters for system: '<S56>/MATLAB System1' */
struct P_MATLABSystem1_MicroMouseTem_T_ {
  real_T MATLABSystem1_InitialCondition;/* Expression: 0
                                         * Referenced by: '<S56>/MATLAB System1'
                                         */
};

/* Parameters for system: '<S56>/MATLAB System3' */
struct P_MATLABSystem3_MicroMouseTem_T_ {
  real_T MATLABSystem3_InitialCondition;/* Expression: 0
                                         * Referenced by: '<S56>/MATLAB System3'
                                         */
};

/* Parameters (default storage) */
struct P_MicroMouseTemplate_T_ {
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant7'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S10>/Switch2'
                                        */
  real_T Switch5_Threshold;            /* Expression: 0
                                        * Referenced by: '<S10>/Switch5'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S10>/Switch1'
                                        */
  real_T Switch6_Threshold;            /* Expression: 0
                                        * Referenced by: '<S10>/Switch6'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S10>/Switch3'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S10>/Switch'
                                        */
  real_T Switch7_Threshold;            /* Expression: 0
                                        * Referenced by: '<S10>/Switch7'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: '<S10>/Switch4'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S12>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S12>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S12>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S12>/Pulse Generator'
                                        */
  real_T Quantizer1_Interval;          /* Expression: 0.01
                                        * Referenced by: '<S2>/Quantizer1'
                                        */
  real_T Quantizer1_Interval_b;        /* Expression: 0.01
                                        * Referenced by: '<S1>/Quantizer1'
                                        */
  real_T Quantizer1_Interval_bc;       /* Expression: 0.01
                                        * Referenced by: '<S4>/Quantizer1'
                                        */
  real_T Quantizer1_Interval_j;        /* Expression: 0.01
                                        * Referenced by: '<S5>/Quantizer1'
                                        */
  real_T Quantizer1_Interval_e;        /* Expression: 0.01
                                        * Referenced by: '<S6>/Quantizer1'
                                        */
  real_T Quantizer1_Interval_l;        /* Expression: 0.01
                                        * Referenced by: '<S7>/Quantizer1'
                                        */
  real_T Quantizer1_Interval_k;        /* Expression: 0.01
                                        * Referenced by: '<S8>/Quantizer1'
                                        */
  real_T Quantizer1_Interval_a;        /* Expression: 0.01
                                        * Referenced by: '<S3>/Quantizer1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S16>/Constant'
                                        */
  int32_T DataStoreMemory2_InitialValue;
                            /* Computed Parameter: DataStoreMemory2_InitialValue
                             * Referenced by: '<S9>/Data Store Memory2'
                             */
  int32_T DataStoreMemory4_InitialValue;
                            /* Computed Parameter: DataStoreMemory4_InitialValue
                             * Referenced by: '<S9>/Data Store Memory4'
                             */
  real32_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<S15>/Data Store Memory'
                              */
  real32_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<S15>/Data Store Memory1'
                             */
  uint16_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S2>/Gain2'
                                        */
  uint16_T Gain2_Gain_n;               /* Computed Parameter: Gain2_Gain_n
                                        * Referenced by: '<S1>/Gain2'
                                        */
  uint16_T Gain2_Gain_b;               /* Computed Parameter: Gain2_Gain_b
                                        * Referenced by: '<S4>/Gain2'
                                        */
  uint16_T Gain2_Gain_j;               /* Computed Parameter: Gain2_Gain_j
                                        * Referenced by: '<S5>/Gain2'
                                        */
  uint16_T Gain2_Gain_f;               /* Computed Parameter: Gain2_Gain_f
                                        * Referenced by: '<S6>/Gain2'
                                        */
  uint16_T Gain2_Gain_f0;              /* Computed Parameter: Gain2_Gain_f0
                                        * Referenced by: '<S7>/Gain2'
                                        */
  uint16_T Gain2_Gain_k;               /* Computed Parameter: Gain2_Gain_k
                                        * Referenced by: '<S8>/Gain2'
                                        */
  uint16_T Gain2_Gain_m;               /* Computed Parameter: Gain2_Gain_m
                                        * Referenced by: '<S3>/Gain2'
                                        */
  uint16_T TmpRTBAtMaxofElementsOutport1_I;
                          /* Computed Parameter: TmpRTBAtMaxofElementsOutport1_I
                           * Referenced by:
                           */
  uint16_T TmpRTBAtMaxofElements7Outport1_;
                          /* Computed Parameter: TmpRTBAtMaxofElements7Outport1_
                           * Referenced by:
                           */
  uint16_T Constant_Value_b;           /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S53>/Constant'
                                        */
  uint16_T TmpRTBAtMaxofElements8Outport1_;
                          /* Computed Parameter: TmpRTBAtMaxofElements8Outport1_
                           * Referenced by:
                           */
  uint16_T TmpRTBAtMaxofElements15Outport1;
                          /* Computed Parameter: TmpRTBAtMaxofElements15Outport1
                           * Referenced by:
                           */
  uint16_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S53>/Constant1'
                                        */
  uint16_T DataStoreMemory_InitialValue_p;
                           /* Computed Parameter: DataStoreMemory_InitialValue_p
                            * Referenced by: '<S14>/Data Store Memory'
                            */
  uint16_T DataStoreMemory1_InitialValue_p;
                          /* Computed Parameter: DataStoreMemory1_InitialValue_p
                           * Referenced by: '<S14>/Data Store Memory1'
                           */
  uint16_T DataStoreMemory2_InitialValue_p;
                          /* Computed Parameter: DataStoreMemory2_InitialValue_p
                           * Referenced by: '<S14>/Data Store Memory2'
                           */
  uint16_T DataStoreMemory1_InitialValue_j;
                          /* Computed Parameter: DataStoreMemory1_InitialValue_j
                           * Referenced by: '<S9>/Data Store Memory1'
                           */
  boolean_T DataStoreMemory_InitialValue_p4;
                          /* Computed Parameter: DataStoreMemory_InitialValue_p4
                           * Referenced by: '<S9>/Data Store Memory'
                           */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem6;/* '<S56>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem5;/* '<S56>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem4_c;/* '<S56>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem3_c;/* '<S56>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem2_ci;/* '<S56>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem1_ci;/* '<S56>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem2_c;/* '<S56>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem1_c;/* '<S56>/MATLAB System1' */
  P_MATLABSystem3_MicroMouseTem_T MATLABSystem4;/* '<S56>/MATLAB System3' */
  P_MATLABSystem3_MicroMouseTem_T MATLABSystem3;/* '<S56>/MATLAB System3' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem2;/* '<S56>/MATLAB System1' */
  P_MATLABSystem1_MicroMouseTem_T MATLABSystem1;/* '<S56>/MATLAB System1' */
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

    struct {
      boolean_T TID0_1;
    } RateInteraction;
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
extern real32_T IMU_Accel[3];          /* '<S15>/Data Store Memory' */
extern real32_T IMU_Gyro[3];           /* '<S15>/Data Store Memory1' */
extern int32_T currTicksRS;            /* '<S9>/Data Store Memory2' */
extern int32_T currTicksLS;            /* '<S9>/Data Store Memory4' */
extern uint16_T ADC1s[9];              /* '<S14>/Data Store Memory' */
extern uint16_T ADC_H[9];              /* '<S14>/Data Store Memory1' */
extern uint16_T ADC_L[9];              /* '<S14>/Data Store Memory2' */
extern uint16_T Thresholds[8];         /* '<S9>/Data Store Memory1' */
extern boolean_T Detections[8];        /* '<S9>/Data Store Memory' */

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
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S77>/Diff' : Unused code path elimination
 * Block '<S77>/TSamp' : Unused code path elimination
 * Block '<S77>/UD' : Unused code path elimination
 * Block '<S18>/LS' : Unused code path elimination
 * Block '<S18>/Unit Delay' : Unused code path elimination
 * Block '<S53>/Cast1' : Eliminate redundant data type conversion
 * Block '<S53>/Cast3' : Eliminate redundant data type conversion
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
 * '<S2>'   : 'MicroMouseTemplate/Bit_to_Volts1'
 * '<S3>'   : 'MicroMouseTemplate/Bit_to_Volts2'
 * '<S4>'   : 'MicroMouseTemplate/Bit_to_Volts3'
 * '<S5>'   : 'MicroMouseTemplate/Bit_to_Volts4'
 * '<S6>'   : 'MicroMouseTemplate/Bit_to_Volts5'
 * '<S7>'   : 'MicroMouseTemplate/Bit_to_Volts6'
 * '<S8>'   : 'MicroMouseTemplate/Bit_to_Volts7'
 * '<S9>'   : 'MicroMouseTemplate/Detections and Thresholds'
 * '<S10>'  : 'MicroMouseTemplate/GPIO for IR LEDs'
 * '<S11>'  : 'MicroMouseTemplate/HelloMicroMouse!'
 * '<S12>'  : 'MicroMouseTemplate/IR LED Pattern'
 * '<S13>'  : 'MicroMouseTemplate/Motors'
 * '<S14>'  : 'MicroMouseTemplate/Subsystem'
 * '<S15>'  : 'MicroMouseTemplate/Subsystem1'
 * '<S16>'  : 'MicroMouseTemplate/Subsystem2'
 * '<S17>'  : 'MicroMouseTemplate/Subsystem3'
 * '<S18>'  : 'MicroMouseTemplate/Subsystem4'
 * '<S19>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_DOWN_LEFT'
 * '<S20>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_DOWN_RIGHT'
 * '<S21>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_LEFT'
 * '<S22>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_RIGHT'
 * '<S23>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_LEFT'
 * '<S24>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_MOT_LEFT'
 * '<S25>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_MOT_RIGHT'
 * '<S26>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_RIGHT'
 * '<S27>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_DOWN_LEFT/ECSoC'
 * '<S28>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_DOWN_LEFT/ECSoC/ECSimCodegen'
 * '<S29>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_DOWN_RIGHT/ECSoC'
 * '<S30>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_DOWN_RIGHT/ECSoC/ECSimCodegen'
 * '<S31>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_LEFT/ECSoC'
 * '<S32>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_LEFT/ECSoC/ECSimCodegen'
 * '<S33>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_RIGHT/ECSoC'
 * '<S34>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_FWD_RIGHT/ECSoC/ECSimCodegen'
 * '<S35>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_LEFT/ECSoC'
 * '<S36>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_LEFT/ECSoC/ECSimCodegen'
 * '<S37>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_MOT_LEFT/ECSoC'
 * '<S38>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_MOT_LEFT/ECSoC/ECSimCodegen'
 * '<S39>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_MOT_RIGHT/ECSoC'
 * '<S40>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_MOT_RIGHT/ECSoC/ECSimCodegen'
 * '<S41>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_RIGHT/ECSoC'
 * '<S42>'  : 'MicroMouseTemplate/GPIO for IR LEDs/LED_RIGHT/ECSoC/ECSimCodegen'
 * '<S43>'  : 'MicroMouseTemplate/Motors/MOTOR_EN'
 * '<S44>'  : 'MicroMouseTemplate/Motors/PWM Output'
 * '<S45>'  : 'MicroMouseTemplate/Motors/PWM Output1'
 * '<S46>'  : 'MicroMouseTemplate/Motors/MOTOR_EN/ECSoC'
 * '<S47>'  : 'MicroMouseTemplate/Motors/MOTOR_EN/ECSoC/ECSimCodegen'
 * '<S48>'  : 'MicroMouseTemplate/Motors/PWM Output/ECSoC'
 * '<S49>'  : 'MicroMouseTemplate/Motors/PWM Output/ECSoC/ECSimCodegen'
 * '<S50>'  : 'MicroMouseTemplate/Motors/PWM Output1/ECSoC'
 * '<S51>'  : 'MicroMouseTemplate/Motors/PWM Output1/ECSoC/ECSimCodegen'
 * '<S52>'  : 'MicroMouseTemplate/Subsystem/ADC2 IN10  IN1'
 * '<S53>'  : 'MicroMouseTemplate/Subsystem/get Highs and Lows'
 * '<S54>'  : 'MicroMouseTemplate/Subsystem/ADC2 IN10  IN1/ECSoC'
 * '<S55>'  : 'MicroMouseTemplate/Subsystem/ADC2 IN10  IN1/ECSoC/ECSimCodegen'
 * '<S56>'  : 'MicroMouseTemplate/Subsystem/get Highs and Lows/Subsystem'
 * '<S57>'  : 'MicroMouseTemplate/Subsystem/get Highs and Lows/Subsystem1'
 * '<S58>'  : 'MicroMouseTemplate/Subsystem/get Highs and Lows/Subsystem2'
 * '<S59>'  : 'MicroMouseTemplate/Subsystem2/CTRL_LEDs'
 * '<S60>'  : 'MicroMouseTemplate/Subsystem2/LED_0'
 * '<S61>'  : 'MicroMouseTemplate/Subsystem2/LED_1'
 * '<S62>'  : 'MicroMouseTemplate/Subsystem2/LED_2'
 * '<S63>'  : 'MicroMouseTemplate/Subsystem2/CTRL_LEDs/ECSoC'
 * '<S64>'  : 'MicroMouseTemplate/Subsystem2/CTRL_LEDs/ECSoC/ECSimCodegen'
 * '<S65>'  : 'MicroMouseTemplate/Subsystem2/LED_0/ECSoC'
 * '<S66>'  : 'MicroMouseTemplate/Subsystem2/LED_0/ECSoC/ECSimCodegen'
 * '<S67>'  : 'MicroMouseTemplate/Subsystem2/LED_1/ECSoC'
 * '<S68>'  : 'MicroMouseTemplate/Subsystem2/LED_1/ECSoC/ECSimCodegen'
 * '<S69>'  : 'MicroMouseTemplate/Subsystem2/LED_2/ECSoC'
 * '<S70>'  : 'MicroMouseTemplate/Subsystem2/LED_2/ECSoC/ECSimCodegen'
 * '<S71>'  : 'MicroMouseTemplate/Subsystem3/SW_1'
 * '<S72>'  : 'MicroMouseTemplate/Subsystem3/SW_2'
 * '<S73>'  : 'MicroMouseTemplate/Subsystem3/SW_1/ECSoC'
 * '<S74>'  : 'MicroMouseTemplate/Subsystem3/SW_1/ECSoC/ECSimCodegen'
 * '<S75>'  : 'MicroMouseTemplate/Subsystem3/SW_2/ECSoC'
 * '<S76>'  : 'MicroMouseTemplate/Subsystem3/SW_2/ECSoC/ECSimCodegen'
 * '<S77>'  : 'MicroMouseTemplate/Subsystem4/Discrete Derivative1'
 */
#endif                                 /* MicroMouseTemplate_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
