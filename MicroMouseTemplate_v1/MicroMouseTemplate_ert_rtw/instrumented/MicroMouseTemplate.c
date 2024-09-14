/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MicroMouseTemplate.c
 *
 * Code generated for Simulink model 'MicroMouseTemplate'.
 *
 * Model version                  : 3.63
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Sep 15 00:25:40 2024
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
#define Micr_IN_WaitUntilButtonPressed4 ((uint8_T)2U)
#define MicroMouseTem_IN_ButtonPressed4 ((uint8_T)1U)

/* user code (top of source file) */
/* System '<Root>' */
extern I2C_HandleTypeDef hi2c2;

/* Exported block states */
real32_T IMU_Accel[3];                 /* '<S9>/Data Store Memory' */
real32_T IMU_Gyro[3];                  /* '<S9>/Data Store Memory1' */
int32_T currTicksRS;                   /* '<S3>/Data Store Memory2' */
int32_T currTicksLS;                   /* '<S3>/Data Store Memory4' */
uint16_T ADC1s[9];                     /* '<S8>/Data Store Memory' */
uint16_T ADC_H[9];                     /* '<S8>/Data Store Memory1' */
uint16_T ADC_L[9];                     /* '<S8>/Data Store Memory2' */
uint16_T Thresholds[8];                /* '<S3>/Data Store Memory1' */
boolean_T Detections[8];               /* '<S3>/Data Store Memory' */

/* Block signals (default storage) */
B_MicroMouseTemplate_T MicroMouseTemplate_B;

/* Block states (default storage) */
DW_MicroMouseTemplate_T MicroMouseTemplate_DW;

/* Real-time model */
static RT_MODEL_MicroMouseTemplate_T MicroMouseTemplate_M_;
RT_MODEL_MicroMouseTemplate_T *const MicroMouseTemplate_M =
  &MicroMouseTemplate_M_;

/* Forward declaration for local functions */
static void enter_atomic_WaitUntilButtonPre(real_T *LED_RIGHT_ENABLE, real_T
  *LED_LEFT_ENABLE, real_T *LED_FWD_RIGHT_ENABLE, real_T *LED_FWD_LEFT_ENABLE);
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

  /* Start for MATLABSystem: '<S50>/MATLAB System1' */
  localDW->objisempty = true;
  localDW->obj.InitialCondition = localP->MATLABSystem1_InitialCondition;
  localDW->obj.isInitialized = 1;

  /*  Number of inputs */
  /*  Initialize the buffer during the first call */
  for (i = 0; i < 25; i++) {
    localDW->obj.Buffer[i] = localDW->obj.InitialCondition;
  }

  /* End of Start for MATLABSystem: '<S50>/MATLAB System1' */
}

/* Output and update for atomic system: */
void MicroMouseTem_MATLABSystem1(real_T rtu_0, B_MATLABSystem1_MicroMouseTem_T
  *localB, DW_MATLABSystem1_MicroMouseTe_T *localDW,
  P_MATLABSystem1_MicroMouseTem_T *localP)
{
  /* MATLABSystem: '<S50>/MATLAB System1' */
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

  /* End of MATLABSystem: '<S50>/MATLAB System1' */
}

/* System initialize for atomic system: */
void MicroMou_MATLABSystem3_Init(DW_MATLABSystem3_MicroMouseTe_T *localDW,
  P_MATLABSystem3_MicroMouseTem_T *localP)
{
  int32_T i;

  /* Start for MATLABSystem: '<S50>/MATLAB System3' */
  localDW->objisempty = true;
  localDW->obj.InitialCondition = localP->MATLABSystem3_InitialCondition;
  localDW->obj.isInitialized = 1;

  /*  Number of inputs */
  /*  Initialize the buffer during the first call */
  for (i = 0; i < 10; i++) {
    localDW->obj.Buffer[i] = localDW->obj.InitialCondition;
  }

  /* End of Start for MATLABSystem: '<S50>/MATLAB System3' */
}

/* Output and update for atomic system: */
void MicroMouseTem_MATLABSystem3(real_T rtu_0, B_MATLABSystem3_MicroMouseTem_T
  *localB, DW_MATLABSystem3_MicroMouseTe_T *localDW,
  P_MATLABSystem3_MicroMouseTem_T *localP)
{
  /* MATLABSystem: '<S50>/MATLAB System3' */
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

  /* End of MATLABSystem: '<S50>/MATLAB System3' */
}

/* Function for Chart: '<Root>/HelloMicroMouse!' */
static void enter_atomic_WaitUntilButtonPre(real_T *LED_RIGHT_ENABLE, real_T
  *LED_LEFT_ENABLE, real_T *LED_FWD_RIGHT_ENABLE, real_T *LED_FWD_LEFT_ENABLE)
{
  *LED_FWD_LEFT_ENABLE = 1.0;
  *LED_FWD_RIGHT_ENABLE = 1.0;
  *LED_LEFT_ENABLE = 0.0;
  *LED_RIGHT_ENABLE = 0.0;
  MicroMouseTemplate_B.LED0 = true;
  MicroMouseTemplate_B.LED1 = true;
  MicroMouseTemplate_B.LED2 = true;
  MicroMouseTemplate_B.leftWheelforward = 0.0;
  MicroMouseTemplate_B.rightWheelforward = 0.0;
  MicroMouseTemplate_B.leftWheelbackward = 0.0;
  MicroMouseTemplate_B.rightWheelbackward = 0.0;
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

static void MicroMouseTemp_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S49>/Analog to Digital Converter' */
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

  /* Start for MATLABSystem: '<S45>/PWM Output' */
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S45>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S45>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void MicroMouseT_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S43>/PWM Output' */
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S43>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel4(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S43>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function for TID0 */
void MicroMouseTemplate_step0(void)
/* Sample time: [0.024999999999999998s, 0.0s] */
{
  real_T LED_FWD_LEFT_ENABLE;
  real_T LED_FWD_RIGHT_ENABLE;
  real_T LED_LEFT_ENABLE;
  real_T LED_RIGHT_ENABLE;
  real_T rtb_PulseGenerator;
  real_T u1;
  int32_T i;
  uint32_T pinReadLoc;
  uint32_T pinReadLoc_0;
  uint16_T rtb_TmpRTBAtMaxofElements7Outpo;
  uint16_T rtb_TmpRTBAtMaxofElementsOutpor;

  {                                    /* Sample time: [0.024999999999999998s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<S49>/Analog to Digital Converter' */
  regularReadADCDMA(MicroMouseTemplate_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                    &ADC1s[0]);

  /* RateTransition generated from: '<S50>/Max of Elements' */
  rtb_TmpRTBAtMaxofElementsOutpor =
    MicroMouseTemplate_DW.TmpRTBAtMaxofElementsOutport1_B;

  /* DSPFlip: '<S8>/Flip' incorporates:
   *  MATLABSystem: '<S49>/Analog to Digital Converter'
   */
  MicroMouseTemplate_B.Flip[0] = ADC1s[7];
  MicroMouseTemplate_B.Flip[7] = ADC1s[0];
  MicroMouseTemplate_B.Flip[1] = ADC1s[6];
  MicroMouseTemplate_B.Flip[6] = ADC1s[1];
  MicroMouseTemplate_B.Flip[2] = ADC1s[5];
  MicroMouseTemplate_B.Flip[5] = ADC1s[2];
  MicroMouseTemplate_B.Flip[3] = ADC1s[4];
  MicroMouseTemplate_B.Flip[4] = ADC1s[3];

  /* DataTypeConversion: '<S52>/Cast To Double' */
  for (i = 0; i < 8; i++) {
    MicroMouseTemplate_B.CastToDouble[i] = MicroMouseTemplate_B.Flip[i];
  }

  /* End of DataTypeConversion: '<S52>/Cast To Double' */
  MicroMouseTem_MATLABSystem3((real_T)MicroMouseTemplate_B.CastToDouble[1],
    &MicroMouseTemplate_B.MATLABSystem4, &MicroMouseTemplate_DW.MATLABSystem4,
    &MicroMouseTemplate_P.MATLABSystem4);

  /* MinMax: '<S50>/Max of Elements1' incorporates:
   *  MATLABSystem: '<S50>/MATLAB System4'
   */
  LED_FWD_RIGHT_ENABLE = MicroMouseTemplate_B.MATLABSystem4.MATLABSystem3[0];
  for (i = 0; i < 9; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem4.MATLABSystem3[i + 1];
    if (LED_FWD_RIGHT_ENABLE < u1) {
      LED_FWD_RIGHT_ENABLE = u1;
    }
  }

  MicroMouseTem_MATLABSystem1(LED_FWD_RIGHT_ENABLE,
    &MicroMouseTemplate_B.MATLABSystem1, &MicroMouseTemplate_DW.MATLABSystem1,
    &MicroMouseTemplate_P.MATLABSystem1);

  /* End of MinMax: '<S50>/Max of Elements1' */

  /* MinMax: '<S50>/Min' incorporates:
   *  MATLABSystem: '<S50>/MATLAB System1'
   */
  rtb_PulseGenerator = MicroMouseTemplate_B.MATLABSystem1.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem1.MATLABSystem1[i + 1];
    if (rtb_PulseGenerator > u1) {
      rtb_PulseGenerator = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[2],
    &MicroMouseTemplate_B.MATLABSystem1_ci,
    &MicroMouseTemplate_DW.MATLABSystem1_ci,
    &MicroMouseTemplate_P.MATLABSystem1_ci);

  /* MinMax: '<S50>/Max of Elements2' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System1'
   */
  LED_FWD_RIGHT_ENABLE = MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[i + 1];
    if (LED_FWD_RIGHT_ENABLE < u1) {
      LED_FWD_RIGHT_ENABLE = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[3],
    &MicroMouseTemplate_B.MATLABSystem3_c,
    &MicroMouseTemplate_DW.MATLABSystem3_c,
    &MicroMouseTemplate_P.MATLABSystem3_c);

  /* MinMax: '<S50>/Max of Elements3' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System3'
   */
  LED_LEFT_ENABLE = MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[i + 1];
    if (LED_LEFT_ENABLE < u1) {
      LED_LEFT_ENABLE = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[4],
    &MicroMouseTemplate_B.MATLABSystem4_c,
    &MicroMouseTemplate_DW.MATLABSystem4_c,
    &MicroMouseTemplate_P.MATLABSystem4_c);

  /* MinMax: '<S50>/Max of Elements4' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System4'
   */
  LED_RIGHT_ENABLE = MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[i + 1];
    if (LED_RIGHT_ENABLE < u1) {
      LED_RIGHT_ENABLE = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[5],
    &MicroMouseTemplate_B.MATLABSystem5, &MicroMouseTemplate_DW.MATLABSystem5,
    &MicroMouseTemplate_P.MATLABSystem5);

  /* MinMax: '<S50>/Max of Elements5' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System5'
   */
  MicroMouseTemplate_B.maxV = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.maxV < u1) {
      MicroMouseTemplate_B.maxV = u1;
    }
  }

  MicroMouseTem_MATLABSystem3((real_T)MicroMouseTemplate_B.CastToDouble[6],
    &MicroMouseTemplate_B.MATLABSystem3, &MicroMouseTemplate_DW.MATLABSystem3,
    &MicroMouseTemplate_P.MATLABSystem3);

  /* MinMax: '<S50>/Max of Elements6' incorporates:
   *  MATLABSystem: '<S50>/MATLAB System3'
   */
  LED_FWD_LEFT_ENABLE = MicroMouseTemplate_B.MATLABSystem3.MATLABSystem3[0];
  for (i = 0; i < 9; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem3.MATLABSystem3[i + 1];
    if (LED_FWD_LEFT_ENABLE < u1) {
      LED_FWD_LEFT_ENABLE = u1;
    }
  }

  MicroMouseTem_MATLABSystem1(LED_FWD_LEFT_ENABLE,
    &MicroMouseTemplate_B.MATLABSystem2, &MicroMouseTemplate_DW.MATLABSystem2,
    &MicroMouseTemplate_P.MATLABSystem2);

  /* End of MinMax: '<S50>/Max of Elements6' */

  /* MinMax: '<S50>/Min1' incorporates:
   *  MATLABSystem: '<S50>/MATLAB System2'
   */
  LED_FWD_LEFT_ENABLE = MicroMouseTemplate_B.MATLABSystem2.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem2.MATLABSystem1[i + 1];
    if (LED_FWD_LEFT_ENABLE > u1) {
      LED_FWD_LEFT_ENABLE = u1;
    }
  }

  /* RateTransition generated from: '<S50>/Max of Elements7' */
  rtb_TmpRTBAtMaxofElements7Outpo =
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements7Outport1_;

  /* DataStoreWrite: '<S47>/ADC_H Write' */
  ADC_H[0] = rtb_TmpRTBAtMaxofElementsOutpor;

  /* MinMax: '<S50>/Min' */
  u1 = fmod(floor(rtb_PulseGenerator), 65536.0);

  /* DataStoreWrite: '<S47>/ADC_H Write' incorporates:
   *  MinMax: '<S50>/Min'
   */
  ADC_H[1] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S50>/Max of Elements2' */
  u1 = fmod(floor(LED_FWD_RIGHT_ENABLE), 65536.0);

  /* DataStoreWrite: '<S47>/ADC_H Write' incorporates:
   *  MinMax: '<S50>/Max of Elements2'
   */
  ADC_H[2] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S50>/Max of Elements3' */
  u1 = fmod(floor(LED_LEFT_ENABLE), 65536.0);

  /* DataStoreWrite: '<S47>/ADC_H Write' incorporates:
   *  MinMax: '<S50>/Max of Elements3'
   */
  ADC_H[3] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S50>/Max of Elements4' */
  u1 = fmod(floor(LED_RIGHT_ENABLE), 65536.0);

  /* DataStoreWrite: '<S47>/ADC_H Write' incorporates:
   *  MinMax: '<S50>/Max of Elements4'
   */
  ADC_H[4] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S50>/Max of Elements5' */
  u1 = fmod(floor(MicroMouseTemplate_B.maxV), 65536.0);

  /* DataStoreWrite: '<S47>/ADC_H Write' incorporates:
   *  MinMax: '<S50>/Max of Elements5'
   */
  ADC_H[5] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S50>/Min1' */
  u1 = fmod(floor(LED_FWD_LEFT_ENABLE), 65536.0);

  /* DataStoreWrite: '<S47>/ADC_H Write' incorporates:
   *  Constant: '<S47>/Constant'
   *  MinMax: '<S50>/Min1'
   */
  ADC_H[6] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);
  ADC_H[7] = rtb_TmpRTBAtMaxofElements7Outpo;
  ADC_H[8] = MicroMouseTemplate_P.Constant_Value_b;

  /* RateTransition generated from: '<S51>/Max of Elements8' */
  rtb_TmpRTBAtMaxofElementsOutpor =
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements8Outport1_;
  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[1],
    &MicroMouseTemplate_B.MATLABSystem1_c,
    &MicroMouseTemplate_DW.MATLABSystem1_c,
    &MicroMouseTemplate_P.MATLABSystem1_c);

  /* MinMax: '<S51>/Max of Elements9' incorporates:
   *  MATLABSystem: '<S51>/MATLAB System1'
   */
  rtb_PulseGenerator = MicroMouseTemplate_B.MATLABSystem1_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem1_c.MATLABSystem1[i + 1];
    if (rtb_PulseGenerator > u1) {
      rtb_PulseGenerator = u1;
    }
  }

  /* MinMax: '<S51>/Max of Elements10' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System1'
   */
  LED_FWD_LEFT_ENABLE = MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[i + 1];
    if (LED_FWD_LEFT_ENABLE > u1) {
      LED_FWD_LEFT_ENABLE = u1;
    }
  }

  /* MinMax: '<S51>/Max of Elements11' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System3'
   */
  LED_FWD_RIGHT_ENABLE = MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[i + 1];
    if (LED_FWD_RIGHT_ENABLE > u1) {
      LED_FWD_RIGHT_ENABLE = u1;
    }
  }

  /* MinMax: '<S51>/Max of Elements12' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System4'
   */
  LED_LEFT_ENABLE = MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[i + 1];
    if (LED_LEFT_ENABLE > u1) {
      LED_LEFT_ENABLE = u1;
    }
  }

  /* MinMax: '<S51>/Max of Elements13' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System5'
   */
  LED_RIGHT_ENABLE = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[i + 1];
    if (LED_RIGHT_ENABLE > u1) {
      LED_RIGHT_ENABLE = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[6],
    &MicroMouseTemplate_B.MATLABSystem2_c,
    &MicroMouseTemplate_DW.MATLABSystem2_c,
    &MicroMouseTemplate_P.MATLABSystem2_c);

  /* MinMax: '<S51>/Max of Elements14' incorporates:
   *  MATLABSystem: '<S51>/MATLAB System2'
   */
  MicroMouseTemplate_B.maxV =
    MicroMouseTemplate_B.MATLABSystem2_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem2_c.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.maxV > u1) {
      MicroMouseTemplate_B.maxV = u1;
    }
  }

  /* RateTransition generated from: '<S51>/Max of Elements15' */
  rtb_TmpRTBAtMaxofElements7Outpo =
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements15Outport1;

  /* DataStoreWrite: '<S47>/ADC_L Write' */
  ADC_L[0] = rtb_TmpRTBAtMaxofElementsOutpor;

  /* MinMax: '<S51>/Max of Elements9' */
  u1 = fmod(floor(rtb_PulseGenerator), 65536.0);

  /* DataStoreWrite: '<S47>/ADC_L Write' incorporates:
   *  MinMax: '<S51>/Max of Elements9'
   */
  ADC_L[1] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S51>/Max of Elements10' */
  u1 = fmod(floor(LED_FWD_LEFT_ENABLE), 65536.0);

  /* DataStoreWrite: '<S47>/ADC_L Write' incorporates:
   *  MinMax: '<S51>/Max of Elements10'
   */
  ADC_L[2] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S51>/Max of Elements11' */
  u1 = fmod(floor(LED_FWD_RIGHT_ENABLE), 65536.0);

  /* DataStoreWrite: '<S47>/ADC_L Write' incorporates:
   *  MinMax: '<S51>/Max of Elements11'
   */
  ADC_L[3] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S51>/Max of Elements12' */
  u1 = fmod(floor(LED_LEFT_ENABLE), 65536.0);

  /* DataStoreWrite: '<S47>/ADC_L Write' incorporates:
   *  MinMax: '<S51>/Max of Elements12'
   */
  ADC_L[4] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S51>/Max of Elements13' */
  u1 = fmod(floor(LED_RIGHT_ENABLE), 65536.0);

  /* DataStoreWrite: '<S47>/ADC_L Write' incorporates:
   *  MinMax: '<S51>/Max of Elements13'
   */
  ADC_L[5] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S51>/Max of Elements14' */
  u1 = fmod(floor(MicroMouseTemplate_B.maxV), 65536.0);

  /* DataStoreWrite: '<S47>/ADC_L Write' incorporates:
   *  Constant: '<S47>/Constant1'
   *  MinMax: '<S51>/Max of Elements14'
   */
  ADC_L[6] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);
  ADC_L[7] = rtb_TmpRTBAtMaxofElements7Outpo;
  ADC_L[8] = MicroMouseTemplate_P.Constant1_Value_c;

  /* RateTransition: '<S52>/Rate Transition' */
  if (MicroMouseTemplate_M->Timing.RateInteraction.TID0_1) {
    MicroMouseTemplate_DW.RateTransition_Buffer =
      MicroMouseTemplate_B.CastToDouble[0];

    /* RateTransition: '<S52>/Rate Transition1' */
    MicroMouseTemplate_DW.RateTransition1_Buffer =
      MicroMouseTemplate_B.CastToDouble[7];
  }

  /* End of RateTransition: '<S52>/Rate Transition' */
  for (i = 0; i < 8; i++) {
    /* DataStoreWrite: '<S3>/Data Store Write' */
    Detections[i] = false;

    /* DataStoreWrite: '<S3>/Data Store Write1' */
    Thresholds[i] = 0U;
  }

  /* DataStoreWrite: '<S3>/Data Store Write2' */
  currTicksRS = 0;

  /* DataStoreWrite: '<S3>/Data Store Write3' */
  currTicksLS = 0;

  /* DiscretePulseGenerator: '<S6>/Pulse Generator' */
  rtb_PulseGenerator = (MicroMouseTemplate_DW.clockTickCounter <
                        MicroMouseTemplate_P.PulseGenerator_Duty) &&
    (MicroMouseTemplate_DW.clockTickCounter >= 0) ?
    MicroMouseTemplate_P.PulseGenerator_Amp : 0.0;
  if (MicroMouseTemplate_DW.clockTickCounter >=
      MicroMouseTemplate_P.PulseGenerator_Period - 1.0) {
    MicroMouseTemplate_DW.clockTickCounter = 0;
  } else {
    MicroMouseTemplate_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S6>/Pulse Generator' */

  /* MATLABSystem: '<S70>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S68>/Digital Port Read' */
  pinReadLoc_0 = LL_GPIO_ReadInputPort(GPIOE);

  /* Chart: '<Root>/HelloMicroMouse!' incorporates:
   *  Logic: '<S11>/NOT'
   *  Logic: '<S11>/NOT1'
   *  MATLABSystem: '<S68>/Digital Port Read'
   *  MATLABSystem: '<S70>/Digital Port Read'
   * */
  if (MicroMouseTemplate_DW.bitsForTID0.is_active_c2_MicroMouseTemplate == 0U) {
    MicroMouseTemplate_DW.bitsForTID0.is_active_c2_MicroMouseTemplate = 1U;
    MicroMouseTemplate_DW.bitsForTID0.is_c2_MicroMouseTemplate =
      Micr_IN_WaitUntilButtonPressed4;
    enter_atomic_WaitUntilButtonPre(&LED_RIGHT_ENABLE, &LED_LEFT_ENABLE,
      &LED_FWD_RIGHT_ENABLE, &LED_FWD_LEFT_ENABLE);
  } else if (MicroMouseTemplate_DW.bitsForTID0.is_c2_MicroMouseTemplate ==
             MicroMouseTem_IN_ButtonPressed4) {
    LED_FWD_LEFT_ENABLE = 0.0;
    LED_FWD_RIGHT_ENABLE = 0.0;
    LED_LEFT_ENABLE = 1.0;
    LED_RIGHT_ENABLE = 1.0;
    if ((pinReadLoc & 4U) == 0U) {
      MicroMouseTemplate_DW.bitsForTID0.is_c2_MicroMouseTemplate =
        Micr_IN_WaitUntilButtonPressed4;
      enter_atomic_WaitUntilButtonPre(&LED_RIGHT_ENABLE, &LED_LEFT_ENABLE,
        &LED_FWD_RIGHT_ENABLE, &LED_FWD_LEFT_ENABLE);
    }
  } else {
    /* case IN_WaitUntilButtonPressed4: */
    LED_FWD_LEFT_ENABLE = 1.0;
    LED_FWD_RIGHT_ENABLE = 1.0;
    LED_LEFT_ENABLE = 0.0;
    LED_RIGHT_ENABLE = 0.0;
    MicroMouseTemplate_B.LED0 = true;
    MicroMouseTemplate_B.LED1 = true;
    MicroMouseTemplate_B.LED2 = true;
    MicroMouseTemplate_B.leftWheelforward = 0.0;
    MicroMouseTemplate_B.rightWheelforward = 0.0;
    MicroMouseTemplate_B.leftWheelbackward = 0.0;
    MicroMouseTemplate_B.rightWheelbackward = 0.0;
    if ((pinReadLoc_0 & 64U) == 0U) {
      MicroMouseTemplate_DW.bitsForTID0.is_c2_MicroMouseTemplate =
        MicroMouseTem_IN_ButtonPressed4;
      LED_FWD_LEFT_ENABLE = 0.0;
      LED_FWD_RIGHT_ENABLE = 0.0;
      LED_LEFT_ENABLE = 1.0;
      LED_RIGHT_ENABLE = 1.0;
    }
  }

  /* End of Chart: '<Root>/HelloMicroMouse!' */

  /* Outputs for Atomic SubSystem: '<Root>/GPIO for IR LEDs' */
  /* MATLABSystem: '<S22>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S4>/Constant2'
   */
  if (MicroMouseTemplate_P.Switch2_Threshold < 0.0) {
    u1 = rtb_PulseGenerator;
  } else {
    u1 = MicroMouseTemplate_P.Constant2_Value;
  }

  /* MATLABSystem: '<S22>/Digital Port Write' incorporates:
   *  Switch: '<S4>/Switch2'
   */
  if (u1 != 0.0) {
    i = 512;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 512U);

  /* MATLABSystem: '<S24>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S4>/Switch5' incorporates:
   *  Constant: '<S4>/Constant5'
   */
  if (MicroMouseTemplate_P.Switch5_Threshold < 0.0) {
    u1 = rtb_PulseGenerator;
  } else {
    u1 = MicroMouseTemplate_P.Constant5_Value;
  }

  /* MATLABSystem: '<S24>/Digital Port Write' incorporates:
   *  Switch: '<S4>/Switch5'
   */
  if (u1 != 0.0) {
    i = 16384;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 16384U);

  /* MATLABSystem: '<S26>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  if (LED_FWD_LEFT_ENABLE > MicroMouseTemplate_P.Switch1_Threshold) {
    u1 = rtb_PulseGenerator;
  } else {
    u1 = MicroMouseTemplate_P.Constant1_Value;
  }

  /* MATLABSystem: '<S26>/Digital Port Write' incorporates:
   *  Switch: '<S4>/Switch1'
   */
  if (u1 != 0.0) {
    i = 256;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 256U);

  /* MATLABSystem: '<S28>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S4>/Switch6' incorporates:
   *  Constant: '<S4>/Constant6'
   */
  if (LED_FWD_RIGHT_ENABLE > MicroMouseTemplate_P.Switch6_Threshold) {
    u1 = rtb_PulseGenerator;
  } else {
    u1 = MicroMouseTemplate_P.Constant6_Value;
  }

  /* MATLABSystem: '<S28>/Digital Port Write' incorporates:
   *  Switch: '<S4>/Switch6'
   */
  if (u1 != 0.0) {
    i = 32768;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 32768U);

  /* MATLABSystem: '<S30>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S4>/Switch3' incorporates:
   *  Constant: '<S4>/Constant3'
   */
  if (LED_LEFT_ENABLE > MicroMouseTemplate_P.Switch3_Threshold) {
    u1 = rtb_PulseGenerator;
  } else {
    u1 = MicroMouseTemplate_P.Constant3_Value;
  }

  /* MATLABSystem: '<S30>/Digital Port Write' incorporates:
   *  Switch: '<S4>/Switch3'
   */
  if (u1 != 0.0) {
    i = 4096;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 4096U);

  /* MATLABSystem: '<S32>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOB;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   */
  if (MicroMouseTemplate_P.Switch_Threshold < 0.0) {
    u1 = rtb_PulseGenerator;
  } else {
    u1 = MicroMouseTemplate_P.Constant_Value;
  }

  /* MATLABSystem: '<S32>/Digital Port Write' incorporates:
   *  Switch: '<S4>/Switch'
   */
  if (u1 != 0.0) {
    i = 4096;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 4096U);

  /* MATLABSystem: '<S34>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S4>/Switch7' incorporates:
   *  Constant: '<S4>/Constant7'
   */
  if (MicroMouseTemplate_P.Switch7_Threshold < 0.0) {
    u1 = rtb_PulseGenerator;
  } else {
    u1 = MicroMouseTemplate_P.Constant7_Value;
  }

  /* MATLABSystem: '<S34>/Digital Port Write' incorporates:
   *  Switch: '<S4>/Switch7'
   */
  if (u1 != 0.0) {
    i = 8192;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 8192U);

  /* MATLABSystem: '<S36>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOE;

  /* Switch: '<S4>/Switch4' incorporates:
   *  Constant: '<S4>/Constant4'
   */
  if (LED_RIGHT_ENABLE <= MicroMouseTemplate_P.Switch4_Threshold) {
    rtb_PulseGenerator = MicroMouseTemplate_P.Constant4_Value;
  }

  /* MATLABSystem: '<S36>/Digital Port Write' incorporates:
   *  Switch: '<S4>/Switch4'
   */
  if (rtb_PulseGenerator != 0.0) {
    i = 2048;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 2048U);

  /* End of Outputs for SubSystem: '<Root>/GPIO for IR LEDs' */

  /* MATLABSystem: '<S45>/PWM Output' */
  u1 = rt_roundd(MicroMouseTemplate_B.rightWheelbackward);
  if (u1 < 4.294967296E+9) {
    if (u1 >= 0.0) {
      pinReadLoc = (uint32_T)u1;
    } else {
      pinReadLoc = 0U;
    }
  } else {
    pinReadLoc = MAX_uint32_T;
  }

  pinReadLoc = checkFrequencyAndDutyCycleLimits
    (MicroMouseTemplate_DW.obj_g.TimerHandle, pinReadLoc);
  setDutyCycleChannel1(MicroMouseTemplate_DW.obj_g.TimerHandle, pinReadLoc);
  u1 = rt_roundd(MicroMouseTemplate_B.rightWheelforward);
  if (u1 < 4.294967296E+9) {
    if (u1 >= 0.0) {
      pinReadLoc = (uint32_T)u1;
    } else {
      pinReadLoc = 0U;
    }
  } else {
    pinReadLoc = MAX_uint32_T;
  }

  pinReadLoc = checkFrequencyAndDutyCycleLimits
    (MicroMouseTemplate_DW.obj_g.TimerHandle, pinReadLoc);
  setDutyCycleChannel2(MicroMouseTemplate_DW.obj_g.TimerHandle, pinReadLoc);

  /* End of MATLABSystem: '<S45>/PWM Output' */

  /* MATLABSystem: '<S43>/PWM Output' */
  u1 = rt_roundd(MicroMouseTemplate_B.leftWheelforward);
  if (u1 < 4.294967296E+9) {
    if (u1 >= 0.0) {
      pinReadLoc = (uint32_T)u1;
    } else {
      pinReadLoc = 0U;
    }
  } else {
    pinReadLoc = MAX_uint32_T;
  }

  pinReadLoc = checkFrequencyAndDutyCycleLimits
    (MicroMouseTemplate_DW.obj_n.TimerHandle, pinReadLoc);
  setDutyCycleChannel3(MicroMouseTemplate_DW.obj_n.TimerHandle, pinReadLoc);
  u1 = rt_roundd(MicroMouseTemplate_B.leftWheelbackward);
  if (u1 < 4.294967296E+9) {
    if (u1 >= 0.0) {
      pinReadLoc = (uint32_T)u1;
    } else {
      pinReadLoc = 0U;
    }
  } else {
    pinReadLoc = MAX_uint32_T;
  }

  pinReadLoc = checkFrequencyAndDutyCycleLimits
    (MicroMouseTemplate_DW.obj_n.TimerHandle, pinReadLoc);
  setDutyCycleChannel4(MicroMouseTemplate_DW.obj_n.TimerHandle, pinReadLoc);

  /* End of MATLABSystem: '<S43>/PWM Output' */

  /* MATLABSystem: '<S41>/Digital Port Write' incorporates:
   *  Constant: '<S7>/Constant'
   */
  MicroMouseTemplate_B.portNameLoc = GPIOD;
  if (MicroMouseTemplate_P.Constant_Value_l != 0.0) {
    i = 128;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 128U);

  /* End of MATLABSystem: '<S41>/Digital Port Write' */

  /* MATLABSystem: '<S60>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOC;
  if (MicroMouseTemplate_B.LED0) {
    i = 8192;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 8192U);

  /* End of MATLABSystem: '<S60>/Digital Port Write' */

  /* MATLABSystem: '<S62>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOC;
  if (MicroMouseTemplate_B.LED1) {
    i = 16384;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 16384U);

  /* End of MATLABSystem: '<S62>/Digital Port Write' */

  /* MATLABSystem: '<S64>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOC;
  if (MicroMouseTemplate_B.LED2) {
    i = 32768;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 32768U);

  /* End of MATLABSystem: '<S64>/Digital Port Write' */

  /* MATLABSystem: '<S58>/Digital Port Write' incorporates:
   *  Constant: '<S10>/Constant'
   */
  MicroMouseTemplate_B.portNameLoc = GPIOB;
  if (MicroMouseTemplate_P.Constant_Value_i != 0.0) {
    i = 8;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 8U);

  /* End of MATLABSystem: '<S58>/Digital Port Write' */

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
  real_T rtb_RateTransition;
  int32_T k;
  uint16_T rtb_MaxofElements;
  uint16_T rtb_MaxofElements7;

  /* RateTransition: '<S52>/Rate Transition' */
  rtb_RateTransition = MicroMouseTemplate_DW.RateTransition_Buffer;
  MicroMouseTem_MATLABSystem1(rtb_RateTransition,
    &MicroMouseTemplate_B.MATLABSystem2_ci,
    &MicroMouseTemplate_DW.MATLABSystem2_ci,
    &MicroMouseTemplate_P.MATLABSystem2_ci);

  /* MinMax: '<S50>/Max of Elements' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System2'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[0];
  for (k = 0; k < 24; k++) {
    rtb_RateTransition = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[k +
      1];
    if (maxV < rtb_RateTransition) {
      maxV = rtb_RateTransition;
    }
  }

  rtb_RateTransition = fmod(floor(maxV), 65536.0);
  rtb_MaxofElements = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* End of MinMax: '<S50>/Max of Elements' */

  /* RateTransition: '<S52>/Rate Transition1' */
  rtb_RateTransition = MicroMouseTemplate_DW.RateTransition1_Buffer;
  MicroMouseTem_MATLABSystem1(rtb_RateTransition,
    &MicroMouseTemplate_B.MATLABSystem6, &MicroMouseTemplate_DW.MATLABSystem6,
    &MicroMouseTemplate_P.MATLABSystem6);

  /* MinMax: '<S50>/Max of Elements7' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System6'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[0];
  for (k = 0; k < 24; k++) {
    rtb_RateTransition = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[k + 1];
    if (maxV < rtb_RateTransition) {
      maxV = rtb_RateTransition;
    }
  }

  rtb_RateTransition = fmod(floor(maxV), 65536.0);
  rtb_MaxofElements7 = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* End of MinMax: '<S50>/Max of Elements7' */

  /* RateTransition generated from: '<S50>/Max of Elements7' */
  MicroMouseTemplate_DW.TmpRTBAtMaxofElements7Outport1_ = rtb_MaxofElements7;

  /* RateTransition generated from: '<S50>/Max of Elements' */
  MicroMouseTemplate_DW.TmpRTBAtMaxofElementsOutport1_B = rtb_MaxofElements;

  /* MinMax: '<S51>/Max of Elements15' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System6'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[0];
  for (k = 0; k < 24; k++) {
    rtb_RateTransition = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[k + 1];
    if (maxV > rtb_RateTransition) {
      maxV = rtb_RateTransition;
    }
  }

  rtb_RateTransition = fmod(floor(maxV), 65536.0);
  rtb_MaxofElements = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* End of MinMax: '<S51>/Max of Elements15' */

  /* MinMax: '<S51>/Max of Elements8' incorporates:
   *  MATLABSystem: '<S52>/MATLAB System2'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[0];
  for (k = 0; k < 24; k++) {
    rtb_RateTransition = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[k +
      1];
    if (maxV > rtb_RateTransition) {
      maxV = rtb_RateTransition;
    }
  }

  rtb_RateTransition = fmod(floor(maxV), 65536.0);
  rtb_MaxofElements7 = (uint16_T)(rtb_RateTransition < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_RateTransition : (int32_T)(uint16_T)
    rtb_RateTransition);

  /* End of MinMax: '<S51>/Max of Elements8' */

  /* RateTransition generated from: '<S51>/Max of Elements15' */
  MicroMouseTemplate_DW.TmpRTBAtMaxofElements15Outport1 = rtb_MaxofElements;

  /* RateTransition generated from: '<S51>/Max of Elements8' */
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
      /* Start for DataStoreMemory: '<S8>/Data Store Memory' */
      ADC1s[i] = MicroMouseTemplate_P.DataStoreMemory_InitialValue_p;

      /* Start for DataStoreMemory: '<S8>/Data Store Memory1' */
      ADC_H[i] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue_p;

      /* Start for DataStoreMemory: '<S8>/Data Store Memory2' */
      ADC_L[i] = MicroMouseTemplate_P.DataStoreMemory2_InitialValue_p;
    }

    for (i = 0; i < 8; i++) {
      /* Start for DataStoreMemory: '<S3>/Data Store Memory' */
      Detections[i] = MicroMouseTemplate_P.DataStoreMemory_InitialValue_p4;

      /* Start for DataStoreMemory: '<S3>/Data Store Memory1' */
      Thresholds[i] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue_j;
    }

    /* Start for DataStoreMemory: '<S3>/Data Store Memory2' */
    currTicksRS = MicroMouseTemplate_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<S3>/Data Store Memory4' */
    currTicksLS = MicroMouseTemplate_P.DataStoreMemory4_InitialValue;

    /* Start for DataStoreMemory: '<S9>/Data Store Memory' */
    IMU_Accel[0] = MicroMouseTemplate_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S9>/Data Store Memory1' */
    IMU_Gyro[0] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<S9>/Data Store Memory' */
    IMU_Accel[1] = MicroMouseTemplate_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S9>/Data Store Memory1' */
    IMU_Gyro[1] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<S9>/Data Store Memory' */
    IMU_Accel[2] = MicroMouseTemplate_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S9>/Data Store Memory1' */
    IMU_Gyro[2] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue;

    /* user code (Initialize function Body) */

    /* System '<Root>' */
    initIMU();

    /* InitializeConditions for RateTransition generated from: '<S50>/Max of Elements' */
    MicroMouseTemplate_DW.TmpRTBAtMaxofElementsOutport1_B =
      MicroMouseTemplate_P.TmpRTBAtMaxofElementsOutport1_I;

    /* InitializeConditions for RateTransition generated from: '<S50>/Max of Elements7' */
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements7Outport1_ =
      MicroMouseTemplate_P.TmpRTBAtMaxofElements7Outport1_;

    /* InitializeConditions for RateTransition generated from: '<S51>/Max of Elements8' */
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements8Outport1_ =
      MicroMouseTemplate_P.TmpRTBAtMaxofElements8Outport1_;

    /* InitializeConditions for RateTransition generated from: '<S51>/Max of Elements15' */
    MicroMouseTemplate_DW.TmpRTBAtMaxofElements15Outport1 =
      MicroMouseTemplate_P.TmpRTBAtMaxofElements15Outport1;

    /* Start for MATLABSystem: '<S49>/Analog to Digital Converter' */
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

    /* Start for MATLABSystem: '<S45>/PWM Output' */
    MicroMouseTemplate_DW.obj_g.matlabCodegenIsDeleted = false;
    MicroMouseTemplate_DW.obj_g.isSetupComplete = false;
    MicroMouseTemplate_DW.obj_g.isInitialized = 1;
    MicroMous_PWMOutput_setupImpl_d(&MicroMouseTemplate_DW.obj_g);
    MicroMouseTemplate_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S43>/PWM Output' */
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
  /* Terminate for MATLABSystem: '<S49>/Analog to Digital Converter' */
  if (!MicroMouseTemplate_DW.obj.matlabCodegenIsDeleted) {
    MicroMouseTemplate_DW.obj.matlabCodegenIsDeleted = true;
    if ((MicroMouseTemplate_DW.obj.isInitialized == 1) &&
        MicroMouseTemplate_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(MicroMouseTemplate_DW.obj.ADCHandle,
                        ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S49>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S45>/PWM Output' */
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

  /* End of Terminate for MATLABSystem: '<S45>/PWM Output' */

  /* Terminate for MATLABSystem: '<S43>/PWM Output' */
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

  /* End of Terminate for MATLABSystem: '<S43>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
