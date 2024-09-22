/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MicroMouseTemplate.c
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

#include "MicroMouseTemplate.h"
#include "rtwtypes.h"
#include "MicroMouseTemplate_types.h"
#include "MicroMouseTemplate_private.h"
#include <string.h>
#include <math.h>
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"

/* Named constants for Chart: '<Root>/HelloMicroMouse!' */
#define MicroMouseTe_IN_FRONT_BASELINE5 ((uint8_T)2U)
#define MicroMouseTe_IN_INITIALISATION7 ((uint8_T)4U)
#define MicroMouseTem_IN_LineCorrection ((uint8_T)2U)
#define MicroMouseTem_IN_SIDE_BASELINE6 ((uint8_T)5U)
#define MicroMouseTemp_IN_FRONT_ENABLE5 ((uint8_T)3U)
#define MicroMouseTemp_IN_TURN_DECISION ((uint8_T)5U)
#define MicroMouseTempl_IN_Empty_Path11 ((uint8_T)1U)
#define MicroMouseTempl_IN_SIDE_ENABLE6 ((uint8_T)6U)
#define MicroMouseTemplat_IN_TURN_RIGHT ((uint8_T)7U)
#define MicroMouseTemplate_IN_FORWARD  ((uint8_T)1U)
#define MicroMouseTemplate_IN_SCAN     ((uint8_T)3U)
#define MicroMouseTemplate_IN_STOP     ((uint8_T)4U)
#define MicroMouseTemplate_IN_TURN_LEFT ((uint8_T)6U)
#define MicroMouseTemplate_IN_Wait     ((uint8_T)8U)
#define MicroMouseTemplate_IN_fix      ((uint8_T)9U)
#define MicroMouseTemplate_IN_fix1     ((uint8_T)10U)

/* user code (top of source file) */
/* System '<Root>' */
extern I2C_HandleTypeDef hi2c2;

/* Exported block states */
real32_T IMU_Accel[3];                 /* '<S15>/Data Store Memory' */
real32_T IMU_Gyro[3];                  /* '<S15>/Data Store Memory1' */
int32_T currTicksRS;                   /* '<S9>/Data Store Memory2' */
int32_T currTicksLS;                   /* '<S9>/Data Store Memory4' */
uint16_T ADC1s[9];                     /* '<S14>/Data Store Memory' */
uint16_T ADC_H[9];                     /* '<S14>/Data Store Memory1' */
uint16_T ADC_L[9];                     /* '<S14>/Data Store Memory2' */
uint16_T Thresholds[8];                /* '<S9>/Data Store Memory1' */
boolean_T Detections[8];               /* '<S9>/Data Store Memory' */

/* Block signals (default storage) */
B_MicroMouseTemplate_T MicroMouseTemplate_B;

/* Block states (default storage) */
DW_MicroMouseTemplate_T MicroMouseTemplate_DW;

/* Real-time model */
static RT_MODEL_MicroMouseTemplate_T MicroMouseTemplate_M_;
RT_MODEL_MicroMouseTemplate_T *const MicroMouseTemplate_M =
  &MicroMouseTemplate_M_;

/* Forward declaration for local functions */
static void MicroMouseTemplate_Empty_Path11(const real_T *Flip1, const real_T
  *Flip1_k, const real_T *Flip1_c, const real_T *Flip1_m, const real_T *Flip1_i,
  const real_T *Flip1_p);
static void MicroMouseTemp_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void MicroMous_PWMOutput_setupImpl_d(stm32cube_blocks_PWMOutput_Mi_T *obj);
static void MicroMouseT_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void MicroMouseTemplate_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(MicroMouseTemplate_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  MicroMouseTemplate_M->Timing.RateInteraction.TID0_1 =
    (MicroMouseTemplate_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (MicroMouseTemplate_M->Timing.TaskCounters.TID[1])++;
  if ((MicroMouseTemplate_M->Timing.TaskCounters.TID[1]) > 3) {/* Sample time: [0.1s, 0.0s] */
    MicroMouseTemplate_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* System initialize for atomic system: */
void MicroMou_MATLABSystem1_Init(DW_MATLABSystem1_MicroMouseTe_T *localDW,
  P_MATLABSystem1_MicroMouseTem_T *localP)
{
  int32_T i;

  /* Start for MATLABSystem: '<S56>/MATLAB System1' */
  localDW->objisempty = true;
  localDW->obj.InitialCondition = localP->MATLABSystem1_InitialCondition;
  localDW->obj.isInitialized = 1;

  /*  Number of inputs */
  /*  Initialize the buffer during the first call */
  for (i = 0; i < 25; i++) {
    localDW->obj.Buffer[i] = localDW->obj.InitialCondition;
  }

  /* End of Start for MATLABSystem: '<S56>/MATLAB System1' */
}

/* Output and update for atomic system: */
void MicroMouseTem_MATLABSystem1(real_T rtu_0, B_MATLABSystem1_MicroMouseTem_T
  *localB, DW_MATLABSystem1_MicroMouseTe_T *localDW,
  P_MATLABSystem1_MicroMouseTem_T *localP)
{
  /* MATLABSystem: '<S56>/MATLAB System1' */
  if (localDW->obj.InitialCondition != localP->MATLABSystem1_InitialCondition) {
    localDW->obj.InitialCondition = localP->MATLABSystem1_InitialCondition;
  }

  /*  Number of inputs */
  /*  Number of outputs */
  /*  Output the current state of the buffer */
  memcpy(&localB->MATLABSystem1[0], &localDW->obj.Buffer[0], 25U * sizeof(real_T));

  /*  Update the buffer */
  localB->rtu_0[0] = rtu_0;
  memcpy(&localB->rtu_0[1], &localDW->obj.Buffer[0], 24U * sizeof(real_T));
  memcpy(&localDW->obj.Buffer[0], &localB->rtu_0[0], 25U * sizeof(real_T));

  /* End of MATLABSystem: '<S56>/MATLAB System1' */
}

/* System initialize for atomic system: */
void MicroMou_MATLABSystem3_Init(DW_MATLABSystem3_MicroMouseTe_T *localDW,
  P_MATLABSystem3_MicroMouseTem_T *localP)
{
  int32_T i;

  /* Start for MATLABSystem: '<S56>/MATLAB System3' */
  localDW->objisempty = true;
  localDW->obj.InitialCondition = localP->MATLABSystem3_InitialCondition;
  localDW->obj.isInitialized = 1;

  /*  Number of inputs */
  /*  Initialize the buffer during the first call */
  for (i = 0; i < 10; i++) {
    localDW->obj.Buffer[i] = localDW->obj.InitialCondition;
  }

  /* End of Start for MATLABSystem: '<S56>/MATLAB System3' */
}

/* Output and update for atomic system: */
void MicroMouseTem_MATLABSystem3(real_T rtu_0, B_MATLABSystem3_MicroMouseTem_T
  *localB, DW_MATLABSystem3_MicroMouseTe_T *localDW,
  P_MATLABSystem3_MicroMouseTem_T *localP)
{
  /* MATLABSystem: '<S56>/MATLAB System3' */
  if (localDW->obj.InitialCondition != localP->MATLABSystem3_InitialCondition) {
    localDW->obj.InitialCondition = localP->MATLABSystem3_InitialCondition;
  }

  /*  Number of inputs */
  /*  Number of outputs */
  /*  Output the current state of the buffer */
  memcpy(&localB->MATLABSystem3[0], &localDW->obj.Buffer[0], 10U * sizeof(real_T));

  /*  Update the buffer */
  localB->rtu_0[0] = rtu_0;
  memcpy(&localB->rtu_0[1], &localDW->obj.Buffer[0], 9U * sizeof(real_T));
  memcpy(&localDW->obj.Buffer[0], &localB->rtu_0[0], 10U * sizeof(real_T));

  /* End of MATLABSystem: '<S56>/MATLAB System3' */
}

real_T rt_roundd(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<Root>/HelloMicroMouse!' */
static void MicroMouseTemplate_Empty_Path11(const real_T *Flip1, const real_T
  *Flip1_k, const real_T *Flip1_c, const real_T *Flip1_m, const real_T *Flip1_i,
  const real_T *Flip1_p)
{
  real_T tmp;
  real_T tmp_0;
  switch (MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11) {
   case MicroMouseTemplate_IN_FORWARD:
    if ((*Flip1 > MicroMouseTemplate_DW.baseline_RS_FWD + 0.2) && (*Flip1_k >
         MicroMouseTemplate_DW.baseline_LS_FWD + 0.2)) {
      MicroMouseTemplate_B.LED0 = false;
      MicroMouseTemplate_B.LED1 = false;
      MicroMouseTemplate_B.LED2 = false;
      MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTemplate_IN_SCAN;
    } else if ((*Flip1_p > *Flip1_c) || (*Flip1_p < *Flip1_c)) {
      MicroMouseTemplate_B.LED0 = false;
      MicroMouseTemplate_B.LED1 = false;
      MicroMouseTemplate_B.LED2 = false;
      MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTemplate_IN_fix;
    } else {
      MicroMouseTemplate_DW.counter = -1.0;
      MicroMouseTemplate_B.LED0 = false;
      MicroMouseTemplate_B.LED1 = false;
      MicroMouseTemplate_B.LED2 = false;
      MicroMouseTemplate_B.LED_LEFT_ENABLE = 0.0;
      MicroMouseTemplate_B.LED_RIGHT_ENABLE = 0.0;
      MicroMouseTemplate_B.LED_FWD_LEFT_ENABLE = 1.0;
      MicroMouseTemplate_B.LED_FWD_RIGHT_ENABLE = 1.0;
      MicroMouseTemplate_B.leftWheelforward = MicroMouseTemplate_DW.speed;
      MicroMouseTemplate_B.rightWheelforward = MicroMouseTemplate_DW.speed;
      MicroMouseTemplate_B.leftWheelbackward = 0.0;
      MicroMouseTemplate_B.rightWheelbackward = 0.0;
    }
    break;

   case MicroMouseTem_IN_LineCorrection:
    if (MicroMouseTemplate_DW.turn == 2.0) {
      MicroMouseTemplate_B.LED0 = false;
      MicroMouseTemplate_B.LED1 = false;
      MicroMouseTemplate_B.LED2 = false;
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTemplate_IN_FORWARD;
    } else if ((*Flip1_p > *Flip1_c) || (*Flip1_p < *Flip1_c)) {
      MicroMouseTemplate_B.LED0 = false;
      MicroMouseTemplate_B.LED1 = false;
      MicroMouseTemplate_B.LED2 = false;
      MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTemplate_IN_fix1;
    } else {
      MicroMouseTemplate_B.LED0 = !MicroMouseTemplate_B.LED0;
      MicroMouseTemplate_B.LED1 = !MicroMouseTemplate_B.LED1;
      MicroMouseTemplate_B.LED2 = !MicroMouseTemplate_B.LED2;
      MicroMouseTemplate_DW.turn = -1.0;
      if (((*Flip1_c <= MicroMouseTemplate_DW.baseline_DOWN_RS) && (*Flip1_p <=
            MicroMouseTemplate_DW.baseline_DOWN_LS)) ||
          (MicroMouseTemplate_DW.counter >= 3.0)) {
        MicroMouseTemplate_DW.turn = 2.0;
      }
    }
    break;

   case MicroMouseTemplate_IN_SCAN:
    if (MicroMouseTemplate_DW.temporalCounter_i1 >= 80U) {
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTemp_IN_TURN_DECISION;
      tmp = fabs(*Flip1_i - MicroMouseTemplate_DW.baseline_LS);
      tmp_0 = fabs(*Flip1_m - MicroMouseTemplate_DW.baseline_RS);
      if (tmp > tmp_0) {
        MicroMouseTemplate_DW.turn = 1.0;
      } else if (tmp < tmp_0) {
        MicroMouseTemplate_DW.turn = 0.0;
      }
    } else {
      MicroMouseTemplate_B.leftWheelforward = 0.0;
      MicroMouseTemplate_B.rightWheelforward = 0.0;
      MicroMouseTemplate_B.leftWheelbackward = 0.0;
      MicroMouseTemplate_B.rightWheelbackward = 0.0;
      MicroMouseTemplate_B.LED_FWD_LEFT_ENABLE = 0.0;
      MicroMouseTemplate_B.LED_FWD_RIGHT_ENABLE = 0.0;
      MicroMouseTemplate_B.LED_LEFT_ENABLE = 1.0;
      MicroMouseTemplate_B.LED_RIGHT_ENABLE = 1.0;
      MicroMouseTemplate_B.LED1 = true;
    }
    break;

   case MicroMouseTemplate_IN_STOP:
    if (MicroMouseTemplate_DW.turn == 0.0) {
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTemplate_IN_FORWARD;
    } else if (MicroMouseTemplate_DW.turn == 1.0) {
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTem_IN_LineCorrection;
    }
    break;

   case MicroMouseTemp_IN_TURN_DECISION:
    if (MicroMouseTemplate_DW.turn == 1.0) {
      MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTemplate_IN_TURN_LEFT;
    } else if (MicroMouseTemplate_DW.turn == 0.0) {
      MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTemplat_IN_TURN_RIGHT;
    }
    break;

   case MicroMouseTemplate_IN_TURN_LEFT:
    if (MicroMouseTemplate_DW.temporalCounter_i1 >= 52U) {
      MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTemplate_IN_Wait;
      MicroMouseTemplate_B.leftWheelforward = 0.0;
      MicroMouseTemplate_B.rightWheelforward = 0.0;
      MicroMouseTemplate_B.leftWheelbackward = 0.0;
      MicroMouseTemplate_B.rightWheelbackward = 0.0;
    } else {
      MicroMouseTemplate_B.LED0 = true;
      MicroMouseTemplate_B.leftWheelforward = 0.0;
      MicroMouseTemplate_B.rightWheelforward = 3000.0;
      MicroMouseTemplate_B.leftWheelbackward = 3000.0;
      MicroMouseTemplate_B.rightWheelbackward = 0.0;
      MicroMouseTemplate_B.LED_FWD_LEFT_ENABLE = 1.0;
      MicroMouseTemplate_B.LED_FWD_RIGHT_ENABLE = 1.0;
      MicroMouseTemplate_B.LED_LEFT_ENABLE = 0.0;
      MicroMouseTemplate_B.LED_RIGHT_ENABLE = 0.0;
    }
    break;

   case MicroMouseTemplat_IN_TURN_RIGHT:
    if (MicroMouseTemplate_DW.temporalCounter_i1 >= 52U) {
      MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTemplate_IN_Wait;
      MicroMouseTemplate_B.leftWheelforward = 0.0;
      MicroMouseTemplate_B.rightWheelforward = 0.0;
      MicroMouseTemplate_B.leftWheelbackward = 0.0;
      MicroMouseTemplate_B.rightWheelbackward = 0.0;
    } else {
      MicroMouseTemplate_B.LED2 = true;
      MicroMouseTemplate_B.leftWheelforward = 3000.0;
      MicroMouseTemplate_B.rightWheelforward = 0.0;
      MicroMouseTemplate_B.leftWheelbackward = 0.0;
      MicroMouseTemplate_B.rightWheelbackward = 3000.0;
      MicroMouseTemplate_B.LED_FWD_LEFT_ENABLE = 1.0;
      MicroMouseTemplate_B.LED_FWD_RIGHT_ENABLE = 1.0;
      MicroMouseTemplate_B.LED_LEFT_ENABLE = 0.0;
      MicroMouseTemplate_B.LED_RIGHT_ENABLE = 0.0;
    }
    break;

   case MicroMouseTemplate_IN_Wait:
    if (MicroMouseTemplate_DW.temporalCounter_i1 >= 40U) {
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTemplate_IN_STOP;
      MicroMouseTemplate_DW.turn = 0.0;
      MicroMouseTemplate_B.LED0 = false;
      MicroMouseTemplate_B.LED1 = false;
      MicroMouseTemplate_B.LED2 = false;
      if ((*Flip1 < MicroMouseTemplate_DW.baseline_RS_FWD + 0.2) && (*Flip1_k <
           MicroMouseTemplate_DW.baseline_LS_FWD + 0.2)) {
        MicroMouseTemplate_DW.turn = 1.0;
      }
    }
    break;

   case MicroMouseTemplate_IN_fix:
    if (MicroMouseTemplate_DW.temporalCounter_i1 >= 4U) {
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTemplate_IN_FORWARD;
    } else {
      if (*Flip1_p > *Flip1_c) {
        MicroMouseTemplate_B.LED2 = true;
        MicroMouseTemplate_B.leftWheelforward = MicroMouseTemplate_DW.speed;
        MicroMouseTemplate_B.rightWheelforward = MicroMouseTemplate_DW.speed +
          MicroMouseTemplate_DW.adjustmentSpeed;
        MicroMouseTemplate_B.leftWheelbackward = 0.0;
        MicroMouseTemplate_B.rightWheelbackward = 0.0;
      }

      if (*Flip1_p < *Flip1_c) {
        MicroMouseTemplate_B.LED0 = true;
        MicroMouseTemplate_B.leftWheelforward = MicroMouseTemplate_DW.speed +
          MicroMouseTemplate_DW.adjustmentSpeed;
        MicroMouseTemplate_B.rightWheelforward = MicroMouseTemplate_DW.speed;
        MicroMouseTemplate_B.leftWheelbackward = 0.0;
        MicroMouseTemplate_B.rightWheelbackward = 0.0;
      }
    }
    break;

   default:
    /* case IN_fix1: */
    if (MicroMouseTemplate_DW.temporalCounter_i1 >= 4U) {
      MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
        MicroMouseTem_IN_LineCorrection;
    } else {
      MicroMouseTemplate_DW.counter++;
      if (*Flip1_p > *Flip1_c) {
        MicroMouseTemplate_B.LED2 = true;
        MicroMouseTemplate_B.leftWheelforward = MicroMouseTemplate_DW.minSpeed;
        MicroMouseTemplate_B.rightWheelforward = MicroMouseTemplate_DW.minSpeed
          + MicroMouseTemplate_DW.adjustmentSpeed;
        MicroMouseTemplate_B.leftWheelbackward = 0.0;
        MicroMouseTemplate_B.rightWheelbackward = 0.0;
      }

      if (*Flip1_p < *Flip1_c) {
        MicroMouseTemplate_B.LED0 = true;
        MicroMouseTemplate_B.leftWheelforward = MicroMouseTemplate_DW.minSpeed +
          MicroMouseTemplate_DW.adjustmentSpeed;
        MicroMouseTemplate_B.rightWheelforward = MicroMouseTemplate_DW.minSpeed;
        MicroMouseTemplate_B.leftWheelbackward = 0.0;
        MicroMouseTemplate_B.rightWheelbackward = 0.0;
      }
    }
    break;
  }
}

static void MicroMouseTemp_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S55>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void*)(&obj->ADCInternalBuffer[0]);
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC2;
  adcStructLoc.dmaPeripheralPtr = DMA1;
  adcStructLoc.dmastream = LL_DMA_CHANNEL_2;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_UNLIMITED;
  adcStructLoc.InternalBufferSize = 9U;
  adcStructLoc.RegularNoOfConversion = 9U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_DMA_INTERRUPT_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_ENABLE_9RANKS);
  enableADCAutomaticCalibrationOffset(obj->ADCHandle, 2);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
}

static void MicroMous_PWMOutput_setupImpl_d(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S51>/PWM Output' */
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S51>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S51>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void MicroMouseT_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S49>/PWM Output' */
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S49>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel4(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S49>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function for TID0 */
void MicroMouseTemplate_step0(void)
                                /* Sample time: [0.024999999999999998s, 0.0s] */
{
  real_T Flip1_i;
  real_T Flip1_m;
  real_T Flip1_p;
  real_T rtb_Quantizer1;
  int32_T i;
  uint32_T pinReadLoc;
  uint16_T rtb_TmpRTBAtMaxofElements7Outpo;
  uint16_T rtb_TmpRTBAtMaxofElementsOutpor;

  {                             /* Sample time: [0.024999999999999998s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<S55>/Analog to Digital Converter' */
  regularReadADCDMA(MicroMouseTemplate_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                    &ADC1s[0]);

  /* RateTransition generated from: '<S56>/Max of Elements' */
  rtb_TmpRTBAtMaxofElementsOutpor =
    MicroMouseTemplate_DW.TmpRTBAtMaxofElementsOutport1_B;

  /* DSPFlip: '<S14>/Flip' incorporates:
   *  MATLABSystem: '<S55>/Analog to Digital Converter'
   */
  MicroMouseTemplate_B.Flip[0] = ADC1s[7];
  MicroMouseTemplate_B.Flip[7] = ADC1s[0];
  MicroMouseTemplate_B.Flip[1] = ADC1s[6];
  MicroMouseTemplate_B.Flip[6] = ADC1s[1];
  MicroMouseTemplate_B.Flip[2] = ADC1s[5];
  MicroMouseTemplate_B.Flip[5] = ADC1s[2];
  MicroMouseTemplate_B.Flip[3] = ADC1s[4];
  MicroMouseTemplate_B.Flip[4] = ADC1s[3];

  /* DataTypeConversion: '<S58>/Cast To Double' */
  for (i = 0; i < 8; i++) {
    MicroMouseTemplate_B.CastToDouble[i] = MicroMouseTemplate_B.Flip[i];
  }

  /* End of DataTypeConversion: '<S58>/Cast To Double' */
  MicroMouseTem_MATLABSystem3((real_T)MicroMouseTemplate_B.CastToDouble[1],
    &MicroMouseTemplate_B.MATLABSystem4, &MicroMouseTemplate_DW.MATLABSystem4,
    &MicroMouseTemplate_P.MATLABSystem4);

  /* MinMax: '<S56>/Max of Elements1' incorporates:
   *  MATLABSystem: '<S56>/MATLAB System4'
   */
  rtb_Quantizer1 = MicroMouseTemplate_B.MATLABSystem4.MATLABSystem3[0];
  for (i = 0; i < 9; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem4.MATLABSystem3[i + 1];
    if (rtb_Quantizer1 < MicroMouseTemplate_B.Quantizer1) {
      rtb_Quantizer1 = MicroMouseTemplate_B.Quantizer1;
    }
  }

  MicroMouseTem_MATLABSystem1(rtb_Quantizer1,
    &MicroMouseTemplate_B.MATLABSystem1, &MicroMouseTemplate_DW.MATLABSystem1,
    &MicroMouseTemplate_P.MATLABSystem1);

  /* End of MinMax: '<S56>/Max of Elements1' */

  /* MinMax: '<S56>/Min' incorporates:
   *  MATLABSystem: '<S56>/MATLAB System1'
   */
  MicroMouseTemplate_B.PulseGenerator =
    MicroMouseTemplate_B.MATLABSystem1.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem1.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.PulseGenerator > MicroMouseTemplate_B.Quantizer1) {
      MicroMouseTemplate_B.PulseGenerator = MicroMouseTemplate_B.Quantizer1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[2],
    &MicroMouseTemplate_B.MATLABSystem1_ci,
    &MicroMouseTemplate_DW.MATLABSystem1_ci,
    &MicroMouseTemplate_P.MATLABSystem1_ci);

  /* MinMax: '<S56>/Max of Elements2' incorporates:
   *  MATLABSystem: '<S58>/MATLAB System1'
   */
  rtb_Quantizer1 = MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[i + 1];
    if (rtb_Quantizer1 < MicroMouseTemplate_B.Quantizer1) {
      rtb_Quantizer1 = MicroMouseTemplate_B.Quantizer1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[3],
    &MicroMouseTemplate_B.MATLABSystem3_c,
    &MicroMouseTemplate_DW.MATLABSystem3_c,
    &MicroMouseTemplate_P.MATLABSystem3_c);

  /* MinMax: '<S56>/Max of Elements3' incorporates:
   *  MATLABSystem: '<S58>/MATLAB System3'
   */
  Flip1_m = MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[i + 1];
    if (Flip1_m < MicroMouseTemplate_B.Quantizer1) {
      Flip1_m = MicroMouseTemplate_B.Quantizer1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[4],
    &MicroMouseTemplate_B.MATLABSystem4_c,
    &MicroMouseTemplate_DW.MATLABSystem4_c,
    &MicroMouseTemplate_P.MATLABSystem4_c);

  /* MinMax: '<S56>/Max of Elements4' incorporates:
   *  MATLABSystem: '<S58>/MATLAB System4'
   */
  Flip1_i = MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[i + 1];
    if (Flip1_i < MicroMouseTemplate_B.Quantizer1) {
      Flip1_i = MicroMouseTemplate_B.Quantizer1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[5],
    &MicroMouseTemplate_B.MATLABSystem5, &MicroMouseTemplate_DW.MATLABSystem5,
    &MicroMouseTemplate_P.MATLABSystem5);

  /* MinMax: '<S56>/Max of Elements5' incorporates:
   *  MATLABSystem: '<S58>/MATLAB System5'
   */
  Flip1_p = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[i + 1];
    if (Flip1_p < MicroMouseTemplate_B.Quantizer1) {
      Flip1_p = MicroMouseTemplate_B.Quantizer1;
    }
  }

  MicroMouseTem_MATLABSystem3((real_T)MicroMouseTemplate_B.CastToDouble[6],
    &MicroMouseTemplate_B.MATLABSystem3, &MicroMouseTemplate_DW.MATLABSystem3,
    &MicroMouseTemplate_P.MATLABSystem3);

  /* MinMax: '<S56>/Max of Elements6' incorporates:
   *  MATLABSystem: '<S56>/MATLAB System3'
   */
  MicroMouseTemplate_B.Quantizer1_m =
    MicroMouseTemplate_B.MATLABSystem3.MATLABSystem3[0];
  for (i = 0; i < 9; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem3.MATLABSystem3[i + 1];
    if (MicroMouseTemplate_B.Quantizer1_m < MicroMouseTemplate_B.Quantizer1) {
      MicroMouseTemplate_B.Quantizer1_m = MicroMouseTemplate_B.Quantizer1;
    }
  }

  MicroMouseTem_MATLABSystem1(MicroMouseTemplate_B.Quantizer1_m,
    &MicroMouseTemplate_B.MATLABSystem2, &MicroMouseTemplate_DW.MATLABSystem2,
    &MicroMouseTemplate_P.MATLABSystem2);

  /* End of MinMax: '<S56>/Max of Elements6' */

  /* MinMax: '<S56>/Min1' incorporates:
   *  MATLABSystem: '<S56>/MATLAB System2'
   */
  MicroMouseTemplate_B.Quantizer1_m =
    MicroMouseTemplate_B.MATLABSystem2.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem2.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.Quantizer1_m > MicroMouseTemplate_B.Quantizer1) {
      MicroMouseTemplate_B.Quantizer1_m = MicroMouseTemplate_B.Quantizer1;
    }
  }

  /* RateTransition generated from: '<S56>/Max of Elements7' */
  rtb_TmpRTBAtMaxofElements7Outpo =
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements7Outport1_;

  /* DataStoreWrite: '<S53>/ADC_H Write' */
  ADC_H[0] = rtb_TmpRTBAtMaxofElementsOutpor;

  /* MinMax: '<S56>/Min' */
  MicroMouseTemplate_B.Quantizer1 = fmod(floor
    (MicroMouseTemplate_B.PulseGenerator), 65536.0);

  /* DataStoreWrite: '<S53>/ADC_H Write' incorporates:
   *  MinMax: '<S56>/Min'
   */
  ADC_H[1] = (uint16_T)(MicroMouseTemplate_B.Quantizer1 < 0.0 ? (int32_T)
                        (uint16_T)-(int16_T)(uint16_T)
                        -MicroMouseTemplate_B.Quantizer1 : (int32_T)(uint16_T)
                        MicroMouseTemplate_B.Quantizer1);

  /* MinMax: '<S56>/Max of Elements2' */
  MicroMouseTemplate_B.Quantizer1 = fmod(floor(rtb_Quantizer1), 65536.0);

  /* DataStoreWrite: '<S53>/ADC_H Write' incorporates:
   *  MinMax: '<S56>/Max of Elements2'
   */
  ADC_H[2] = (uint16_T)(MicroMouseTemplate_B.Quantizer1 < 0.0 ? (int32_T)
                        (uint16_T)-(int16_T)(uint16_T)
                        -MicroMouseTemplate_B.Quantizer1 : (int32_T)(uint16_T)
                        MicroMouseTemplate_B.Quantizer1);

  /* MinMax: '<S56>/Max of Elements3' */
  MicroMouseTemplate_B.Quantizer1 = fmod(floor(Flip1_m), 65536.0);

  /* DataStoreWrite: '<S53>/ADC_H Write' incorporates:
   *  MinMax: '<S56>/Max of Elements3'
   */
  ADC_H[3] = (uint16_T)(MicroMouseTemplate_B.Quantizer1 < 0.0 ? (int32_T)
                        (uint16_T)-(int16_T)(uint16_T)
                        -MicroMouseTemplate_B.Quantizer1 : (int32_T)(uint16_T)
                        MicroMouseTemplate_B.Quantizer1);

  /* MinMax: '<S56>/Max of Elements4' */
  MicroMouseTemplate_B.Quantizer1 = fmod(floor(Flip1_i), 65536.0);

  /* DataStoreWrite: '<S53>/ADC_H Write' incorporates:
   *  MinMax: '<S56>/Max of Elements4'
   */
  ADC_H[4] = (uint16_T)(MicroMouseTemplate_B.Quantizer1 < 0.0 ? (int32_T)
                        (uint16_T)-(int16_T)(uint16_T)
                        -MicroMouseTemplate_B.Quantizer1 : (int32_T)(uint16_T)
                        MicroMouseTemplate_B.Quantizer1);

  /* MinMax: '<S56>/Max of Elements5' */
  MicroMouseTemplate_B.Quantizer1 = fmod(floor(Flip1_p), 65536.0);

  /* DataStoreWrite: '<S53>/ADC_H Write' incorporates:
   *  MinMax: '<S56>/Max of Elements5'
   */
  ADC_H[5] = (uint16_T)(MicroMouseTemplate_B.Quantizer1 < 0.0 ? (int32_T)
                        (uint16_T)-(int16_T)(uint16_T)
                        -MicroMouseTemplate_B.Quantizer1 : (int32_T)(uint16_T)
                        MicroMouseTemplate_B.Quantizer1);

  /* MinMax: '<S56>/Min1' */
  MicroMouseTemplate_B.Quantizer1 = fmod(floor(MicroMouseTemplate_B.Quantizer1_m),
    65536.0);

  /* DataStoreWrite: '<S53>/ADC_H Write' incorporates:
   *  Constant: '<S53>/Constant'
   *  MinMax: '<S56>/Min1'
   */
  ADC_H[6] = (uint16_T)(MicroMouseTemplate_B.Quantizer1 < 0.0 ? (int32_T)
                        (uint16_T)-(int16_T)(uint16_T)
                        -MicroMouseTemplate_B.Quantizer1 : (int32_T)(uint16_T)
                        MicroMouseTemplate_B.Quantizer1);
  ADC_H[7] = rtb_TmpRTBAtMaxofElements7Outpo;
  ADC_H[8] = MicroMouseTemplate_P.Constant_Value_b;

  /* RateTransition generated from: '<S57>/Max of Elements8' */
  rtb_TmpRTBAtMaxofElementsOutpor =
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements8Outport1_;
  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[1],
    &MicroMouseTemplate_B.MATLABSystem1_c,
    &MicroMouseTemplate_DW.MATLABSystem1_c,
    &MicroMouseTemplate_P.MATLABSystem1_c);

  /* MinMax: '<S57>/Max of Elements9' incorporates:
   *  MATLABSystem: '<S57>/MATLAB System1'
   */
  MicroMouseTemplate_B.PulseGenerator =
    MicroMouseTemplate_B.MATLABSystem1_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem1_c.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.PulseGenerator > MicroMouseTemplate_B.Quantizer1) {
      MicroMouseTemplate_B.PulseGenerator = MicroMouseTemplate_B.Quantizer1;
    }
  }

  /* MinMax: '<S57>/Max of Elements10' incorporates:
   *  MATLABSystem: '<S58>/MATLAB System1'
   */
  MicroMouseTemplate_B.Quantizer1_m =
    MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.Quantizer1_m > MicroMouseTemplate_B.Quantizer1) {
      MicroMouseTemplate_B.Quantizer1_m = MicroMouseTemplate_B.Quantizer1;
    }
  }

  /* MinMax: '<S57>/Max of Elements11' incorporates:
   *  MATLABSystem: '<S58>/MATLAB System3'
   */
  rtb_Quantizer1 = MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[i + 1];
    if (rtb_Quantizer1 > MicroMouseTemplate_B.Quantizer1) {
      rtb_Quantizer1 = MicroMouseTemplate_B.Quantizer1;
    }
  }

  /* MinMax: '<S57>/Max of Elements12' incorporates:
   *  MATLABSystem: '<S58>/MATLAB System4'
   */
  Flip1_m = MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[i + 1];
    if (Flip1_m > MicroMouseTemplate_B.Quantizer1) {
      Flip1_m = MicroMouseTemplate_B.Quantizer1;
    }
  }

  /* MinMax: '<S57>/Max of Elements13' incorporates:
   *  MATLABSystem: '<S58>/MATLAB System5'
   */
  Flip1_i = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[i + 1];
    if (Flip1_i > MicroMouseTemplate_B.Quantizer1) {
      Flip1_i = MicroMouseTemplate_B.Quantizer1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[6],
    &MicroMouseTemplate_B.MATLABSystem2_c,
    &MicroMouseTemplate_DW.MATLABSystem2_c,
    &MicroMouseTemplate_P.MATLABSystem2_c);

  /* MinMax: '<S57>/Max of Elements14' incorporates:
   *  MATLABSystem: '<S57>/MATLAB System2'
   */
  Flip1_p = MicroMouseTemplate_B.MATLABSystem2_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    MicroMouseTemplate_B.Quantizer1 =
      MicroMouseTemplate_B.MATLABSystem2_c.MATLABSystem1[i + 1];
    if (Flip1_p > MicroMouseTemplate_B.Quantizer1) {
      Flip1_p = MicroMouseTemplate_B.Quantizer1;
    }
  }

  /* RateTransition generated from: '<S57>/Max of Elements15' */
  rtb_TmpRTBAtMaxofElements7Outpo =
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements15Outport1;

  /* DataStoreWrite: '<S53>/ADC_L Write' */
  ADC_L[0] = rtb_TmpRTBAtMaxofElementsOutpor;

  /* MinMax: '<S57>/Max of Elements9' */
  MicroMouseTemplate_B.Quantizer1 = fmod(floor
    (MicroMouseTemplate_B.PulseGenerator), 65536.0);

  /* DataStoreWrite: '<S53>/ADC_L Write' incorporates:
   *  MinMax: '<S57>/Max of Elements9'
   */
  ADC_L[1] = (uint16_T)(MicroMouseTemplate_B.Quantizer1 < 0.0 ? (int32_T)
                        (uint16_T)-(int16_T)(uint16_T)
                        -MicroMouseTemplate_B.Quantizer1 : (int32_T)(uint16_T)
                        MicroMouseTemplate_B.Quantizer1);

  /* MinMax: '<S57>/Max of Elements10' */
  MicroMouseTemplate_B.Quantizer1 = fmod(floor(MicroMouseTemplate_B.Quantizer1_m),
    65536.0);

  /* DataStoreWrite: '<S53>/ADC_L Write' incorporates:
   *  MinMax: '<S57>/Max of Elements10'
   */
  ADC_L[2] = (uint16_T)(MicroMouseTemplate_B.Quantizer1 < 0.0 ? (int32_T)
                        (uint16_T)-(int16_T)(uint16_T)
                        -MicroMouseTemplate_B.Quantizer1 : (int32_T)(uint16_T)
                        MicroMouseTemplate_B.Quantizer1);

  /* MinMax: '<S57>/Max of Elements11' */
  MicroMouseTemplate_B.Quantizer1 = fmod(floor(rtb_Quantizer1), 65536.0);

  /* DataStoreWrite: '<S53>/ADC_L Write' incorporates:
   *  MinMax: '<S57>/Max of Elements11'
   */
  ADC_L[3] = (uint16_T)(MicroMouseTemplate_B.Quantizer1 < 0.0 ? (int32_T)
                        (uint16_T)-(int16_T)(uint16_T)
                        -MicroMouseTemplate_B.Quantizer1 : (int32_T)(uint16_T)
                        MicroMouseTemplate_B.Quantizer1);

  /* MinMax: '<S57>/Max of Elements12' */
  MicroMouseTemplate_B.Quantizer1 = fmod(floor(Flip1_m), 65536.0);

  /* DataStoreWrite: '<S53>/ADC_L Write' incorporates:
   *  MinMax: '<S57>/Max of Elements12'
   */
  ADC_L[4] = (uint16_T)(MicroMouseTemplate_B.Quantizer1 < 0.0 ? (int32_T)
                        (uint16_T)-(int16_T)(uint16_T)
                        -MicroMouseTemplate_B.Quantizer1 : (int32_T)(uint16_T)
                        MicroMouseTemplate_B.Quantizer1);

  /* MinMax: '<S57>/Max of Elements13' */
  MicroMouseTemplate_B.Quantizer1 = fmod(floor(Flip1_i), 65536.0);

  /* DataStoreWrite: '<S53>/ADC_L Write' incorporates:
   *  MinMax: '<S57>/Max of Elements13'
   */
  ADC_L[5] = (uint16_T)(MicroMouseTemplate_B.Quantizer1 < 0.0 ? (int32_T)
                        (uint16_T)-(int16_T)(uint16_T)
                        -MicroMouseTemplate_B.Quantizer1 : (int32_T)(uint16_T)
                        MicroMouseTemplate_B.Quantizer1);

  /* MinMax: '<S57>/Max of Elements14' */
  MicroMouseTemplate_B.Quantizer1 = fmod(floor(Flip1_p), 65536.0);

  /* DataStoreWrite: '<S53>/ADC_L Write' incorporates:
   *  Constant: '<S53>/Constant1'
   *  MinMax: '<S57>/Max of Elements14'
   */
  ADC_L[6] = (uint16_T)(MicroMouseTemplate_B.Quantizer1 < 0.0 ? (int32_T)
                        (uint16_T)-(int16_T)(uint16_T)
                        -MicroMouseTemplate_B.Quantizer1 : (int32_T)(uint16_T)
                        MicroMouseTemplate_B.Quantizer1);
  ADC_L[7] = rtb_TmpRTBAtMaxofElements7Outpo;
  ADC_L[8] = MicroMouseTemplate_P.Constant1_Value_c;

  /* RateTransition: '<S58>/Rate Transition' */
  if (MicroMouseTemplate_M->Timing.RateInteraction.TID0_1) {
    MicroMouseTemplate_DW.RateTransition_Buffer =
      MicroMouseTemplate_B.CastToDouble[0];

    /* RateTransition: '<S58>/Rate Transition1' */
    MicroMouseTemplate_DW.RateTransition1_Buffer =
      MicroMouseTemplate_B.CastToDouble[7];
  }

  /* End of RateTransition: '<S58>/Rate Transition' */
  for (i = 0; i < 8; i++) {
    /* DataStoreWrite: '<S9>/Data Store Write' */
    Detections[i] = false;

    /* DataStoreWrite: '<S9>/Data Store Write1' */
    Thresholds[i] = 0U;
  }

  /* DataStoreWrite: '<S9>/Data Store Write2' */
  currTicksRS = 0;

  /* DataStoreWrite: '<S9>/Data Store Write3' */
  currTicksLS = 0;

  /* DiscretePulseGenerator: '<S12>/Pulse Generator' */
  MicroMouseTemplate_B.PulseGenerator = (MicroMouseTemplate_DW.clockTickCounter <
    MicroMouseTemplate_P.PulseGenerator_Duty) &&
    (MicroMouseTemplate_DW.clockTickCounter >= 0) ?
    MicroMouseTemplate_P.PulseGenerator_Amp : 0.0;
  if (MicroMouseTemplate_DW.clockTickCounter >=
      MicroMouseTemplate_P.PulseGenerator_Period - 1.0) {
    MicroMouseTemplate_DW.clockTickCounter = 0;
  } else {
    MicroMouseTemplate_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S12>/Pulse Generator' */

  /* MATLABSystem: '<S76>/Digital Port Read' */
  LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S74>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOE);

  /* Quantizer: '<S2>/Quantizer1' incorporates:
   *  DSPFlip: '<S14>/Flip'
   *  DataTypeConversion: '<S2>/Cast To Double1'
   *  Gain: '<S2>/Gain2'
   *  MATLABSystem: '<S55>/Analog to Digital Converter'
   */
  MicroMouseTemplate_B.Quantizer1 = rt_roundd((real_T)((uint32_T)
    MicroMouseTemplate_P.Gain2_Gain * ADC1s[6]) * 1.4901161193847656E-8 /
    MicroMouseTemplate_P.Quantizer1_Interval) *
    MicroMouseTemplate_P.Quantizer1_Interval;

  /* Quantizer: '<S1>/Quantizer1' incorporates:
   *  DSPFlip: '<S14>/Flip'
   *  DataTypeConversion: '<S1>/Cast To Double1'
   *  Gain: '<S1>/Gain2'
   *  MATLABSystem: '<S55>/Analog to Digital Converter'
   */
  MicroMouseTemplate_B.Quantizer1_m = rt_roundd((real_T)((uint32_T)
    MicroMouseTemplate_P.Gain2_Gain_n * ADC1s[1]) * 1.4901161193847656E-8 /
    MicroMouseTemplate_P.Quantizer1_Interval_b) *
    MicroMouseTemplate_P.Quantizer1_Interval_b;

  /* Quantizer: '<S4>/Quantizer1' incorporates:
   *  DSPFlip: '<S14>/Flip'
   *  DataTypeConversion: '<S4>/Cast To Double1'
   *  Gain: '<S4>/Gain2'
   *  MATLABSystem: '<S55>/Analog to Digital Converter'
   */
  rtb_Quantizer1 = rt_roundd((real_T)((uint32_T)
    MicroMouseTemplate_P.Gain2_Gain_b * ADC1s[5]) * 1.4901161193847656E-8 /
    MicroMouseTemplate_P.Quantizer1_Interval_bc) *
    MicroMouseTemplate_P.Quantizer1_Interval_bc;

  /* DSPFlip: '<S5>/Flip1' incorporates:
   *  DSPFlip: '<S14>/Flip'
   *  DataTypeConversion: '<S5>/Cast To Double1'
   *  Gain: '<S5>/Gain2'
   *  MATLABSystem: '<S55>/Analog to Digital Converter'
   *  Quantizer: '<S5>/Quantizer1'
   */
  Flip1_m = rt_roundd((real_T)((uint32_T)MicroMouseTemplate_P.Gain2_Gain_j *
    ADC1s[4]) * 1.4901161193847656E-8 /
                      MicroMouseTemplate_P.Quantizer1_Interval_j) *
    MicroMouseTemplate_P.Quantizer1_Interval_j;

  /* DSPFlip: '<S6>/Flip1' incorporates:
   *  DSPFlip: '<S14>/Flip'
   *  DataTypeConversion: '<S6>/Cast To Double1'
   *  Gain: '<S6>/Gain2'
   *  MATLABSystem: '<S55>/Analog to Digital Converter'
   *  Quantizer: '<S6>/Quantizer1'
   */
  Flip1_i = rt_roundd((real_T)((uint32_T)MicroMouseTemplate_P.Gain2_Gain_f *
    ADC1s[3]) * 1.4901161193847656E-8 /
                      MicroMouseTemplate_P.Quantizer1_Interval_e) *
    MicroMouseTemplate_P.Quantizer1_Interval_e;

  /* DSPFlip: '<S7>/Flip1' incorporates:
   *  DSPFlip: '<S14>/Flip'
   *  DataTypeConversion: '<S7>/Cast To Double1'
   *  Gain: '<S7>/Gain2'
   *  MATLABSystem: '<S55>/Analog to Digital Converter'
   *  Quantizer: '<S7>/Quantizer1'
   */
  Flip1_p = rt_roundd((real_T)((uint32_T)MicroMouseTemplate_P.Gain2_Gain_f0 *
    ADC1s[2]) * 1.4901161193847656E-8 /
                      MicroMouseTemplate_P.Quantizer1_Interval_l) *
    MicroMouseTemplate_P.Quantizer1_Interval_l;

  /* Chart: '<Root>/HelloMicroMouse!' incorporates:
   *  DSPFlip: '<S1>/Flip1'
   *  DSPFlip: '<S2>/Flip1'
   *  DSPFlip: '<S4>/Flip1'
   *  Logic: '<S17>/NOT'
   *  MATLABSystem: '<S74>/Digital Port Read'
   * */
  if (MicroMouseTemplate_DW.temporalCounter_i1 < 127U) {
    MicroMouseTemplate_DW.temporalCounter_i1++;
  }

  if (MicroMouseTemplate_DW.bitsForTID0.is_active_c2_MicroMouseTemplate == 0U) {
    MicroMouseTemplate_DW.bitsForTID0.is_active_c2_MicroMouseTemplate = 1U;
    MicroMouseTemplate_DW.bitsForTID0.is_c2_MicroMouseTemplate =
      MicroMouseTe_IN_INITIALISATION7;
    MicroMouseTemplate_B.LED0 = !MicroMouseTemplate_B.LED0;
    MicroMouseTemplate_B.LED1 = !MicroMouseTemplate_B.LED1;
    MicroMouseTemplate_B.LED2 = !MicroMouseTemplate_B.LED2;
    MicroMouseTemplate_DW.speed = 3000.0;
    MicroMouseTemplate_DW.adjustmentSpeed = 200.0;
    MicroMouseTemplate_DW.minSpeed = 2900.0;
    MicroMouseTemplate_B.leftWheelforward = 0.0;
    MicroMouseTemplate_B.rightWheelforward = 0.0;
    MicroMouseTemplate_B.leftWheelbackward = 0.0;
    MicroMouseTemplate_B.rightWheelbackward = 0.0;
    MicroMouseTemplate_DW.baseline_LS_FWD = 0.0;
    MicroMouseTemplate_DW.baseline_RS_FWD = 0.0;
    MicroMouseTemplate_DW.baseline_DOWN_LS = 0.0;
    MicroMouseTemplate_DW.baseline_RS = 0.0;
    MicroMouseTemplate_DW.baseline_LS = 0.0;
    MicroMouseTemplate_DW.baseline_DOWN_RS = 0.0;
    MicroMouseTemplate_DW.counter = 0.0;
    MicroMouseTemplate_B.LED_FWD_LEFT_ENABLE = 0.0;
    MicroMouseTemplate_B.LED_FWD_RIGHT_ENABLE = 0.0;
    MicroMouseTemplate_B.LED_LEFT_ENABLE = 0.0;
    MicroMouseTemplate_B.LED_RIGHT_ENABLE = 0.0;
    MicroMouseTemplate_B.LED_DOWN_LEFT_ENABLE = 1.0;
    MicroMouseTemplate_B.LED_DOWN_RIGHT_ENABLE = 1.0;
    MicroMouseTemplate_B.LED_MOT_RIGHT_ENABLE = 0.0;
    MicroMouseTemplate_B.LED_MOT_LEFT_ENABLE = 0.0;
    MicroMouseTemplate_DW.minLeftADC = 3.3;
    MicroMouseTemplate_DW.minRightADC = 3.3;
    MicroMouseTemplate_DW.turn = -1.0;
    MicroMouseTemplate_DW.c = 1.0;
  } else {
    switch (MicroMouseTemplate_DW.bitsForTID0.is_c2_MicroMouseTemplate) {
     case MicroMouseTempl_IN_Empty_Path11:
      MicroMouseTemplate_Empty_Path11(&MicroMouseTemplate_B.Quantizer1,
        &MicroMouseTemplate_B.Quantizer1_m, &rtb_Quantizer1, &Flip1_m, &Flip1_i,
        &Flip1_p);
      break;

     case MicroMouseTe_IN_FRONT_BASELINE5:
      if ((pinReadLoc & 64U) == 0U) {
        MicroMouseTemplate_DW.bitsForTID0.is_c2_MicroMouseTemplate =
          MicroMouseTempl_IN_Empty_Path11;
        MicroMouseTemplate_DW.bitsForTID0.is_Empty_Path11 =
          MicroMouseTemplate_IN_FORWARD;
      } else {
        MicroMouseTemplate_B.LED0 = true;
        MicroMouseTemplate_B.LED1 = true;
        MicroMouseTemplate_B.LED2 = true;
        MicroMouseTemplate_DW.baseline_LS_FWD =
          MicroMouseTemplate_B.Quantizer1_m;
        MicroMouseTemplate_DW.baseline_RS_FWD = MicroMouseTemplate_B.Quantizer1;
        MicroMouseTemplate_DW.baseline_DOWN_RS = rtb_Quantizer1;
        MicroMouseTemplate_DW.baseline_DOWN_LS = Flip1_p;
        if (Flip1_p < MicroMouseTemplate_DW.minLeftADC) {
          MicroMouseTemplate_DW.minLeftADC = Flip1_p;
        }

        if (rtb_Quantizer1 < MicroMouseTemplate_DW.minRightADC) {
          MicroMouseTemplate_DW.minRightADC = rtb_Quantizer1;
        }

        MicroMouseTemplate_DW.start = 1.0;
      }
      break;

     case MicroMouseTemp_IN_FRONT_ENABLE5:
      if (MicroMouseTemplate_DW.temporalCounter_i1 >= 120U) {
        MicroMouseTemplate_DW.bitsForTID0.is_c2_MicroMouseTemplate =
          MicroMouseTe_IN_FRONT_BASELINE5;
      } else {
        MicroMouseTemplate_B.LED0 = !MicroMouseTemplate_B.LED0;
        MicroMouseTemplate_B.LED1 = !MicroMouseTemplate_B.LED1;
        MicroMouseTemplate_B.LED2 = !MicroMouseTemplate_B.LED2;
        MicroMouseTemplate_B.LED_FWD_LEFT_ENABLE = 1.0;
        MicroMouseTemplate_B.LED_FWD_RIGHT_ENABLE = 1.0;
      }
      break;

     case MicroMouseTe_IN_INITIALISATION7:
      MicroMouseTemplate_B.LED_DOWN_LEFT_ENABLE = 1.0;
      MicroMouseTemplate_B.LED_DOWN_RIGHT_ENABLE = 1.0;
      MicroMouseTemplate_B.LED_MOT_RIGHT_ENABLE = 0.0;
      MicroMouseTemplate_B.LED_MOT_LEFT_ENABLE = 0.0;
      if (MicroMouseTemplate_DW.c == 1.0) {
        MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
        MicroMouseTemplate_DW.bitsForTID0.is_c2_MicroMouseTemplate =
          MicroMouseTempl_IN_SIDE_ENABLE6;
        MicroMouseTemplate_B.LED_LEFT_ENABLE = 1.0;
        MicroMouseTemplate_B.LED_RIGHT_ENABLE = 1.0;
      }
      break;

     case MicroMouseTem_IN_SIDE_BASELINE6:
      if (MicroMouseTemplate_DW.start == 1.0) {
        MicroMouseTemplate_B.LED_LEFT_ENABLE = 0.0;
        MicroMouseTemplate_B.LED_RIGHT_ENABLE = 0.0;
        MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
        MicroMouseTemplate_DW.bitsForTID0.is_c2_MicroMouseTemplate =
          MicroMouseTemp_IN_FRONT_ENABLE5;
      } else {
        MicroMouseTemplate_B.LED0 = !MicroMouseTemplate_B.LED0;
        MicroMouseTemplate_B.LED1 = !MicroMouseTemplate_B.LED1;
        MicroMouseTemplate_B.LED2 = !MicroMouseTemplate_B.LED2;
      }
      break;

     default:
      /* case IN_SIDE_ENABLE6: */
      if (MicroMouseTemplate_DW.temporalCounter_i1 >= 120U) {
        MicroMouseTemplate_DW.bitsForTID0.is_c2_MicroMouseTemplate =
          MicroMouseTem_IN_SIDE_BASELINE6;
        MicroMouseTemplate_DW.baseline_RS = Flip1_m;
        MicroMouseTemplate_DW.baseline_LS = Flip1_i;
        MicroMouseTemplate_DW.start = 1.0;
      } else {
        MicroMouseTemplate_B.LED0 = !MicroMouseTemplate_B.LED0;
        MicroMouseTemplate_B.LED1 = !MicroMouseTemplate_B.LED1;
        MicroMouseTemplate_B.LED2 = !MicroMouseTemplate_B.LED2;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/HelloMicroMouse!' */

  /* Outputs for Atomic SubSystem: '<Root>/GPIO for IR LEDs' */
  /* MATLABSystem: '<S28>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S10>/Switch2' incorporates:
   *  Constant: '<S10>/Constant2'
   */
  if (MicroMouseTemplate_B.LED_DOWN_LEFT_ENABLE >
      MicroMouseTemplate_P.Switch2_Threshold) {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_B.PulseGenerator;
  } else {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_P.Constant2_Value;
  }

  /* MATLABSystem: '<S28>/Digital Port Write' incorporates:
   *  Switch: '<S10>/Switch2'
   */
  if (MicroMouseTemplate_B.Quantizer1 != 0.0) {
    i = 512;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 512U);

  /* MATLABSystem: '<S30>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S10>/Switch5' incorporates:
   *  Constant: '<S10>/Constant5'
   */
  if (MicroMouseTemplate_B.LED_DOWN_RIGHT_ENABLE >
      MicroMouseTemplate_P.Switch5_Threshold) {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_B.PulseGenerator;
  } else {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_P.Constant5_Value;
  }

  /* MATLABSystem: '<S30>/Digital Port Write' incorporates:
   *  Switch: '<S10>/Switch5'
   */
  if (MicroMouseTemplate_B.Quantizer1 != 0.0) {
    i = 16384;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 16384U);

  /* MATLABSystem: '<S32>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S10>/Switch1' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  if (MicroMouseTemplate_B.LED_FWD_LEFT_ENABLE >
      MicroMouseTemplate_P.Switch1_Threshold) {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_B.PulseGenerator;
  } else {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_P.Constant1_Value;
  }

  /* MATLABSystem: '<S32>/Digital Port Write' incorporates:
   *  Switch: '<S10>/Switch1'
   */
  if (MicroMouseTemplate_B.Quantizer1 != 0.0) {
    i = 256;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 256U);

  /* MATLABSystem: '<S34>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S10>/Switch6' incorporates:
   *  Constant: '<S10>/Constant6'
   */
  if (MicroMouseTemplate_B.LED_FWD_RIGHT_ENABLE >
      MicroMouseTemplate_P.Switch6_Threshold) {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_B.PulseGenerator;
  } else {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_P.Constant6_Value;
  }

  /* MATLABSystem: '<S34>/Digital Port Write' incorporates:
   *  Switch: '<S10>/Switch6'
   */
  if (MicroMouseTemplate_B.Quantizer1 != 0.0) {
    i = 32768;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 32768U);

  /* MATLABSystem: '<S36>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S10>/Switch3' incorporates:
   *  Constant: '<S10>/Constant3'
   */
  if (MicroMouseTemplate_B.LED_LEFT_ENABLE >
      MicroMouseTemplate_P.Switch3_Threshold) {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_B.PulseGenerator;
  } else {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_P.Constant3_Value;
  }

  /* MATLABSystem: '<S36>/Digital Port Write' incorporates:
   *  Switch: '<S10>/Switch3'
   */
  if (MicroMouseTemplate_B.Quantizer1 != 0.0) {
    i = 4096;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 4096U);

  /* MATLABSystem: '<S38>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOB;

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   */
  if (MicroMouseTemplate_B.LED_MOT_LEFT_ENABLE >
      MicroMouseTemplate_P.Switch_Threshold) {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_B.PulseGenerator;
  } else {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_P.Constant_Value;
  }

  /* MATLABSystem: '<S38>/Digital Port Write' incorporates:
   *  Switch: '<S10>/Switch'
   */
  if (MicroMouseTemplate_B.Quantizer1 != 0.0) {
    i = 4096;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 4096U);

  /* MATLABSystem: '<S40>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S10>/Switch7' incorporates:
   *  Constant: '<S10>/Constant7'
   */
  if (MicroMouseTemplate_B.LED_MOT_RIGHT_ENABLE >
      MicroMouseTemplate_P.Switch7_Threshold) {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_B.PulseGenerator;
  } else {
    MicroMouseTemplate_B.Quantizer1 = MicroMouseTemplate_P.Constant7_Value;
  }

  /* MATLABSystem: '<S40>/Digital Port Write' incorporates:
   *  Switch: '<S10>/Switch7'
   */
  if (MicroMouseTemplate_B.Quantizer1 != 0.0) {
    i = 8192;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 8192U);

  /* MATLABSystem: '<S42>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S10>/Switch4' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  if (MicroMouseTemplate_B.LED_RIGHT_ENABLE <=
      MicroMouseTemplate_P.Switch4_Threshold) {
    MicroMouseTemplate_B.PulseGenerator = MicroMouseTemplate_P.Constant4_Value;
  }

  /* MATLABSystem: '<S42>/Digital Port Write' incorporates:
   *  Switch: '<S10>/Switch4'
   */
  if (MicroMouseTemplate_B.PulseGenerator != 0.0) {
    i = 2048;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 2048U);

  /* End of Outputs for SubSystem: '<Root>/GPIO for IR LEDs' */

  /* MATLABSystem: '<S51>/PWM Output' */
  MicroMouseTemplate_B.Quantizer1 = rt_roundd
    (MicroMouseTemplate_B.rightWheelbackward);
  if (MicroMouseTemplate_B.Quantizer1 < 4.294967296E+9) {
    if (MicroMouseTemplate_B.Quantizer1 >= 0.0) {
      pinReadLoc = (uint32_T)MicroMouseTemplate_B.Quantizer1;
    } else {
      pinReadLoc = 0U;
    }
  } else {
    pinReadLoc = MAX_uint32_T;
  }

  pinReadLoc = checkFrequencyAndDutyCycleLimits
    (MicroMouseTemplate_DW.obj_g.TimerHandle, pinReadLoc);
  setDutyCycleChannel1(MicroMouseTemplate_DW.obj_g.TimerHandle, pinReadLoc);
  MicroMouseTemplate_B.Quantizer1 = rt_roundd
    (MicroMouseTemplate_B.rightWheelforward);
  if (MicroMouseTemplate_B.Quantizer1 < 4.294967296E+9) {
    if (MicroMouseTemplate_B.Quantizer1 >= 0.0) {
      pinReadLoc = (uint32_T)MicroMouseTemplate_B.Quantizer1;
    } else {
      pinReadLoc = 0U;
    }
  } else {
    pinReadLoc = MAX_uint32_T;
  }

  pinReadLoc = checkFrequencyAndDutyCycleLimits
    (MicroMouseTemplate_DW.obj_g.TimerHandle, pinReadLoc);
  setDutyCycleChannel2(MicroMouseTemplate_DW.obj_g.TimerHandle, pinReadLoc);

  /* End of MATLABSystem: '<S51>/PWM Output' */

  /* MATLABSystem: '<S49>/PWM Output' */
  MicroMouseTemplate_B.Quantizer1 = rt_roundd
    (MicroMouseTemplate_B.leftWheelforward);
  if (MicroMouseTemplate_B.Quantizer1 < 4.294967296E+9) {
    if (MicroMouseTemplate_B.Quantizer1 >= 0.0) {
      pinReadLoc = (uint32_T)MicroMouseTemplate_B.Quantizer1;
    } else {
      pinReadLoc = 0U;
    }
  } else {
    pinReadLoc = MAX_uint32_T;
  }

  pinReadLoc = checkFrequencyAndDutyCycleLimits
    (MicroMouseTemplate_DW.obj_n.TimerHandle, pinReadLoc);
  setDutyCycleChannel3(MicroMouseTemplate_DW.obj_n.TimerHandle, pinReadLoc);
  MicroMouseTemplate_B.Quantizer1 = rt_roundd
    (MicroMouseTemplate_B.leftWheelbackward);
  if (MicroMouseTemplate_B.Quantizer1 < 4.294967296E+9) {
    if (MicroMouseTemplate_B.Quantizer1 >= 0.0) {
      pinReadLoc = (uint32_T)MicroMouseTemplate_B.Quantizer1;
    } else {
      pinReadLoc = 0U;
    }
  } else {
    pinReadLoc = MAX_uint32_T;
  }

  pinReadLoc = checkFrequencyAndDutyCycleLimits
    (MicroMouseTemplate_DW.obj_n.TimerHandle, pinReadLoc);
  setDutyCycleChannel4(MicroMouseTemplate_DW.obj_n.TimerHandle, pinReadLoc);

  /* End of MATLABSystem: '<S49>/PWM Output' */

  /* MATLABSystem: '<S47>/Digital Port Write' incorporates:
   *  Constant: '<S13>/Constant'
   */
  MicroMouseTemplate_B.portNameLoc = GPIOD;
  if (MicroMouseTemplate_P.Constant_Value_l != 0.0) {
    i = 128;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 128U);

  /* End of MATLABSystem: '<S47>/Digital Port Write' */

  /* MATLABSystem: '<S66>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOC;
  if (MicroMouseTemplate_B.LED0) {
    i = 8192;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 8192U);

  /* End of MATLABSystem: '<S66>/Digital Port Write' */

  /* MATLABSystem: '<S68>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOC;
  if (MicroMouseTemplate_B.LED1) {
    i = 16384;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 16384U);

  /* End of MATLABSystem: '<S68>/Digital Port Write' */

  /* MATLABSystem: '<S70>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOC;
  if (MicroMouseTemplate_B.LED2) {
    i = 32768;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 32768U);

  /* End of MATLABSystem: '<S70>/Digital Port Write' */

  /* MATLABSystem: '<S64>/Digital Port Write' incorporates:
   *  Constant: '<S16>/Constant'
   */
  MicroMouseTemplate_B.portNameLoc = GPIOB;
  if (MicroMouseTemplate_P.Constant_Value_i != 0.0) {
    i = 8;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 8U);

  /* End of MATLABSystem: '<S64>/Digital Port Write' */

  /* user code (Update function Body for TID0) */

  /* System '<Root>' */
  refreshIMUValues();

  /* System '<Root>' */
  CustomWhile();
}

/* Model step function for TID1 */
void MicroMouseTemplate_step1(void)    /* Sample time: [0.1s, 0.0s] */
{
  real_T maxV;
  real_T u1;
  int32_T k;
  uint16_T rtb_MaxofElements;
  uint16_T rtb_MaxofElements7;

  /* RateTransition: '<S58>/Rate Transition' */
  MicroMouseTem_MATLABSystem1(MicroMouseTemplate_DW.RateTransition_Buffer,
    &MicroMouseTemplate_B.MATLABSystem2_ci,
    &MicroMouseTemplate_DW.MATLABSystem2_ci,
    &MicroMouseTemplate_P.MATLABSystem2_ci);

  /* MinMax: '<S56>/Max of Elements' incorporates:
   *  MATLABSystem: '<S58>/MATLAB System2'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[0];
  for (k = 0; k < 24; k++) {
    u1 = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[k + 1];
    if (maxV < u1) {
      maxV = u1;
    }
  }

  u1 = fmod(floor(maxV), 65536.0);
  rtb_MaxofElements = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-u1 : (int32_T)(uint16_T)u1);

  /* End of MinMax: '<S56>/Max of Elements' */

  /* RateTransition: '<S58>/Rate Transition1' */
  MicroMouseTem_MATLABSystem1(MicroMouseTemplate_DW.RateTransition1_Buffer,
    &MicroMouseTemplate_B.MATLABSystem6, &MicroMouseTemplate_DW.MATLABSystem6,
    &MicroMouseTemplate_P.MATLABSystem6);

  /* MinMax: '<S56>/Max of Elements7' incorporates:
   *  MATLABSystem: '<S58>/MATLAB System6'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[0];
  for (k = 0; k < 24; k++) {
    u1 = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[k + 1];
    if (maxV < u1) {
      maxV = u1;
    }
  }

  u1 = fmod(floor(maxV), 65536.0);
  rtb_MaxofElements7 = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-u1 : (int32_T)(uint16_T)u1);

  /* End of MinMax: '<S56>/Max of Elements7' */

  /* RateTransition generated from: '<S56>/Max of Elements7' */
  MicroMouseTemplate_DW.TmpRTBAtMaxofElements7Outport1_ = rtb_MaxofElements7;

  /* RateTransition generated from: '<S56>/Max of Elements' */
  MicroMouseTemplate_DW.TmpRTBAtMaxofElementsOutport1_B = rtb_MaxofElements;

  /* MinMax: '<S57>/Max of Elements15' incorporates:
   *  MATLABSystem: '<S58>/MATLAB System6'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[0];
  for (k = 0; k < 24; k++) {
    u1 = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[k + 1];
    if (maxV > u1) {
      maxV = u1;
    }
  }

  u1 = fmod(floor(maxV), 65536.0);
  rtb_MaxofElements = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-u1 : (int32_T)(uint16_T)u1);

  /* End of MinMax: '<S57>/Max of Elements15' */

  /* MinMax: '<S57>/Max of Elements8' incorporates:
   *  MATLABSystem: '<S58>/MATLAB System2'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[0];
  for (k = 0; k < 24; k++) {
    u1 = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[k + 1];
    if (maxV > u1) {
      maxV = u1;
    }
  }

  u1 = fmod(floor(maxV), 65536.0);
  rtb_MaxofElements7 = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-u1 : (int32_T)(uint16_T)u1);

  /* End of MinMax: '<S57>/Max of Elements8' */

  /* RateTransition generated from: '<S57>/Max of Elements15' */
  MicroMouseTemplate_DW.TmpRTBAtMaxofElements15Outport1 = rtb_MaxofElements;

  /* RateTransition generated from: '<S57>/Max of Elements8' */
  MicroMouseTemplate_DW.TmpRTBAtMaxofElements8Outport1_ = rtb_MaxofElements7;

  /* user code (Update function Body for TID1) */

  /* System '<Root>' */
  refreshIMUValues();

  /* System '<Root>' */
  CustomWhile();
}

/* Model initialize function */
void MicroMouseTemplate_initialize(void)
{
  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      /* Start for DataStoreMemory: '<S14>/Data Store Memory' */
      ADC1s[i] = MicroMouseTemplate_P.DataStoreMemory_InitialValue_p;

      /* Start for DataStoreMemory: '<S14>/Data Store Memory1' */
      ADC_H[i] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue_p;

      /* Start for DataStoreMemory: '<S14>/Data Store Memory2' */
      ADC_L[i] = MicroMouseTemplate_P.DataStoreMemory2_InitialValue_p;
    }

    for (i = 0; i < 8; i++) {
      /* Start for DataStoreMemory: '<S9>/Data Store Memory' */
      Detections[i] = MicroMouseTemplate_P.DataStoreMemory_InitialValue_p4;

      /* Start for DataStoreMemory: '<S9>/Data Store Memory1' */
      Thresholds[i] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue_j;
    }

    /* Start for DataStoreMemory: '<S9>/Data Store Memory2' */
    currTicksRS = MicroMouseTemplate_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<S9>/Data Store Memory4' */
    currTicksLS = MicroMouseTemplate_P.DataStoreMemory4_InitialValue;

    /* Start for DataStoreMemory: '<S15>/Data Store Memory' */
    IMU_Accel[0] = MicroMouseTemplate_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S15>/Data Store Memory1' */
    IMU_Gyro[0] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<S15>/Data Store Memory' */
    IMU_Accel[1] = MicroMouseTemplate_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S15>/Data Store Memory1' */
    IMU_Gyro[1] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<S15>/Data Store Memory' */
    IMU_Accel[2] = MicroMouseTemplate_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S15>/Data Store Memory1' */
    IMU_Gyro[2] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue;

    /* user code (Initialize function Body) */

    /* System '<Root>' */
    initIMU();

    /* InitializeConditions for RateTransition generated from: '<S56>/Max of Elements' */
    MicroMouseTemplate_DW.TmpRTBAtMaxofElementsOutport1_B =
      MicroMouseTemplate_P.TmpRTBAtMaxofElementsOutport1_I;

    /* InitializeConditions for RateTransition generated from: '<S56>/Max of Elements7' */
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements7Outport1_ =
      MicroMouseTemplate_P.TmpRTBAtMaxofElements7Outport1_;

    /* InitializeConditions for RateTransition generated from: '<S57>/Max of Elements8' */
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements8Outport1_ =
      MicroMouseTemplate_P.TmpRTBAtMaxofElements8Outport1_;

    /* InitializeConditions for RateTransition generated from: '<S57>/Max of Elements15' */
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements15Outport1 =
      MicroMouseTemplate_P.TmpRTBAtMaxofElements15Outport1;

    /* Start for MATLABSystem: '<S55>/Analog to Digital Converter' */
    MicroMouseTemplate_DW.obj.isInitialized = 0;
    MicroMouseTemplate_DW.obj.matlabCodegenIsDeleted = false;
    MicroMouseTemp_SystemCore_setup(&MicroMouseTemplate_DW.obj);
    MicroMou_MATLABSystem3_Init(&MicroMouseTemplate_DW.MATLABSystem4,
      &MicroMouseTemplate_P.MATLABSystem4);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem1,
      &MicroMouseTemplate_P.MATLABSystem1);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem1_ci,
      &MicroMouseTemplate_P.MATLABSystem1_ci);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem3_c,
      &MicroMouseTemplate_P.MATLABSystem3_c);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem4_c,
      &MicroMouseTemplate_P.MATLABSystem4_c);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem5,
      &MicroMouseTemplate_P.MATLABSystem5);
    MicroMou_MATLABSystem3_Init(&MicroMouseTemplate_DW.MATLABSystem3,
      &MicroMouseTemplate_P.MATLABSystem3);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem2,
      &MicroMouseTemplate_P.MATLABSystem2);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem1_c,
      &MicroMouseTemplate_P.MATLABSystem1_c);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem2_c,
      &MicroMouseTemplate_P.MATLABSystem2_c);

    /* Start for MATLABSystem: '<S51>/PWM Output' */
    MicroMouseTemplate_DW.obj_g.matlabCodegenIsDeleted = false;
    MicroMouseTemplate_DW.obj_g.isSetupComplete = false;
    MicroMouseTemplate_DW.obj_g.isInitialized = 1;
    MicroMous_PWMOutput_setupImpl_d(&MicroMouseTemplate_DW.obj_g);
    MicroMouseTemplate_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S49>/PWM Output' */
    MicroMouseTemplate_DW.obj_n.matlabCodegenIsDeleted = false;
    MicroMouseTemplate_DW.obj_n.isSetupComplete = false;
    MicroMouseTemplate_DW.obj_n.isInitialized = 1;
    MicroMouseT_PWMOutput_setupImpl(&MicroMouseTemplate_DW.obj_n);
    MicroMouseTemplate_DW.obj_n.isSetupComplete = true;
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem2_ci,
      &MicroMouseTemplate_P.MATLABSystem2_ci);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem6,
      &MicroMouseTemplate_P.MATLABSystem6);
  }
}

/* Model terminate function */
void MicroMouseTemplate_terminate(void)
{
  /* Terminate for MATLABSystem: '<S55>/Analog to Digital Converter' */
  if (!MicroMouseTemplate_DW.obj.matlabCodegenIsDeleted) {
    MicroMouseTemplate_DW.obj.matlabCodegenIsDeleted = true;
    if ((MicroMouseTemplate_DW.obj.isInitialized == 1) &&
        MicroMouseTemplate_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(MicroMouseTemplate_DW.obj.ADCHandle,
                        ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S55>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S51>/PWM Output' */
  if (!MicroMouseTemplate_DW.obj_g.matlabCodegenIsDeleted) {
    MicroMouseTemplate_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((MicroMouseTemplate_DW.obj_g.isInitialized == 1) &&
        MicroMouseTemplate_DW.obj_g.isSetupComplete) {
      disableCounter(MicroMouseTemplate_DW.obj_g.TimerHandle);
      disableTimerInterrupts(MicroMouseTemplate_DW.obj_g.TimerHandle, 0);
      disableTimerChannel1(MicroMouseTemplate_DW.obj_g.TimerHandle, ENABLE_CH);
      disableTimerChannel2(MicroMouseTemplate_DW.obj_g.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S51>/PWM Output' */

  /* Terminate for MATLABSystem: '<S49>/PWM Output' */
  if (!MicroMouseTemplate_DW.obj_n.matlabCodegenIsDeleted) {
    MicroMouseTemplate_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((MicroMouseTemplate_DW.obj_n.isInitialized == 1) &&
        MicroMouseTemplate_DW.obj_n.isSetupComplete) {
      disableCounter(MicroMouseTemplate_DW.obj_n.TimerHandle);
      disableTimerInterrupts(MicroMouseTemplate_DW.obj_n.TimerHandle, 0);
      disableTimerChannel3(MicroMouseTemplate_DW.obj_n.TimerHandle, ENABLE_CH);
      disableTimerChannel4(MicroMouseTemplate_DW.obj_n.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S49>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
