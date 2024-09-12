/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MicroMouseTemplate.c
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

#include "MicroMouseTemplate.h"
#include "rtwtypes.h"
#include "MicroMouseTemplate_types.h"
#include "MicroMouseTemplate_private.h"
#include <string.h>
#include <math.h>
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"

/* Named constants for Chart: '<Root>/HelloMicroMouse!' */
#define Micr_IN_WaitUntilButtonPressed2 ((uint8_T)5U)
#define MicroMouseTe_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define MicroMouseTem_IN_ButtonPressed2 ((uint8_T)3U)
#define MicroMouseTemplate_IN_Baseline1 ((uint8_T)1U)
#define MicroMouseTemplate_IN_Baseline2 ((uint8_T)2U)
#define MicroMouseTemplate_IN_Left     ((uint8_T)1U)
#define MicroMouseTemplate_IN_Right    ((uint8_T)2U)
#define MicroMouseTemplate_IN_Stop2    ((uint8_T)4U)

/* user code (top of source file) */
/* System '<Root>' */
extern I2C_HandleTypeDef hi2c2;

/* Exported block states */
real32_T IMU_Accel[3];                 /* '<S10>/Data Store Memory' */
real32_T IMU_Gyro[3];                  /* '<S10>/Data Store Memory1' */
int32_T currTicksRS;                   /* '<S2>/Data Store Memory2' */
int32_T currTicksLS;                   /* '<S2>/Data Store Memory4' */
uint16_T Thresholds[8];                /* '<S2>/Data Store Memory1' */
uint16_T ADC1s[9];                     /* '<S9>/Data Store Memory' */
uint16_T ADC_H[9];                     /* '<S9>/Data Store Memory1' */
uint16_T ADC_L[9];                     /* '<S9>/Data Store Memory2' */
boolean_T Detections[8];               /* '<S2>/Data Store Memory' */

/* Block signals (default storage) */
B_MicroMouseTemplate_T MicroMouseTemplate_B;

/* Block states (default storage) */
DW_MicroMouseTemplate_T MicroMouseTemplate_DW;

/* Real-time model */
static RT_MODEL_MicroMouseTemplate_T MicroMouseTemplate_M_;
RT_MODEL_MicroMouseTemplate_T *const MicroMouseTemplate_M =
  &MicroMouseTemplate_M_;

/* Forward declaration for local functions */
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

  /* Start for MATLABSystem: '<S33>/MATLAB System1' */
  localDW->objisempty = true;
  localDW->obj.InitialCondition = localP->MATLABSystem1_InitialCondition;
  localDW->obj.isInitialized = 1;

  /*  Number of inputs */
  /*  Initialize the buffer during the first call */
  for (i = 0; i < 25; i++) {
    localDW->obj.Buffer[i] = localDW->obj.InitialCondition;
  }

  /* End of Start for MATLABSystem: '<S33>/MATLAB System1' */
}

/* Output and update for atomic system: */
void MicroMouseTem_MATLABSystem1(real_T rtu_0, B_MATLABSystem1_MicroMouseTem_T
  *localB, DW_MATLABSystem1_MicroMouseTe_T *localDW,
  P_MATLABSystem1_MicroMouseTem_T *localP)
{
  /* MATLABSystem: '<S33>/MATLAB System1' */
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

  /* End of MATLABSystem: '<S33>/MATLAB System1' */
}

/* System initialize for atomic system: */
void MicroMou_MATLABSystem3_Init(DW_MATLABSystem3_MicroMouseTe_T *localDW,
  P_MATLABSystem3_MicroMouseTem_T *localP)
{
  int32_T i;

  /* Start for MATLABSystem: '<S33>/MATLAB System3' */
  localDW->objisempty = true;
  localDW->obj.InitialCondition = localP->MATLABSystem3_InitialCondition;
  localDW->obj.isInitialized = 1;

  /*  Number of inputs */
  /*  Initialize the buffer during the first call */
  for (i = 0; i < 10; i++) {
    localDW->obj.Buffer[i] = localDW->obj.InitialCondition;
  }

  /* End of Start for MATLABSystem: '<S33>/MATLAB System3' */
}

/* Output and update for atomic system: */
void MicroMouseTem_MATLABSystem3(real_T rtu_0, B_MATLABSystem3_MicroMouseTem_T
  *localB, DW_MATLABSystem3_MicroMouseTe_T *localDW,
  P_MATLABSystem3_MicroMouseTem_T *localP)
{
  /* MATLABSystem: '<S33>/MATLAB System3' */
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

  /* End of MATLABSystem: '<S33>/MATLAB System3' */
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

  /* Start for MATLABSystem: '<S32>/Analog to Digital Converter' */
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

  /* Start for MATLABSystem: '<S28>/PWM Output' */
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S28>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S28>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void MicroMouseT_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Mi_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S26>/PWM Output' */
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S26>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel4(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S26>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function for TID0 */
void MicroMouseTemplate_step0(void)
                                /* Sample time: [0.024999999999999998s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  int32_T i;

  {                             /* Sample time: [0.024999999999999998s, 0.0s] */
    rate_monotonic_scheduler();
  }

  for (i = 0; i < 8; i++) {
    /* DataStoreWrite: '<S2>/Data Store Write' */
    Detections[i] = false;

    /* DataStoreWrite: '<S2>/Data Store Write1' */
    Thresholds[i] = 0U;
  }

  /* DataStoreWrite: '<S2>/Data Store Write2' */
  currTicksRS = 0;

  /* DataStoreWrite: '<S2>/Data Store Write3' */
  currTicksLS = 0;

  /* MATLABSystem: '<S24>/Digital Port Write' incorporates:
   *  Constant: '<S7>/Constant'
   */
  portNameLoc = GPIOD;
  if (MicroMouseTemplate_P.Constant_Value_l != 0.0) {
    i = 128;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 128U);

  /* End of MATLABSystem: '<S24>/Digital Port Write' */

  /* MATLABSystem: '<S41>/Digital Port Write' incorporates:
   *  Constant: '<S11>/Constant'
   */
  portNameLoc = GPIOB;
  if (MicroMouseTemplate_P.Constant_Value_i != 0.0) {
    i = 8;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 8U);

  /* End of MATLABSystem: '<S41>/Digital Port Write' */

  /* Outputs for Atomic SubSystem: '<Root>/GPIO for IR LEDs' */
  /* MATLABSystem: '<S17>/Digital Port Write' incorporates:
   *  Constant: '<S3>/Constant'
   */
  portNameLoc = GPIOE;
  if (MicroMouseTemplate_P.Constant_Value != 0.0) {
    i = 256;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 256U);

  /* End of MATLABSystem: '<S17>/Digital Port Write' */

  /* MATLABSystem: '<S19>/Digital Port Write' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  portNameLoc = GPIOE;
  if (MicroMouseTemplate_P.Constant1_Value != 0.0) {
    i = 32768;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)i & 32768U);

  /* End of MATLABSystem: '<S19>/Digital Port Write' */
  /* End of Outputs for SubSystem: '<Root>/GPIO for IR LEDs' */

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
  real_T maxV_0;
  real_T maxV_1;
  real_T minV;
  real_T rtb_Quantizer1;
  real_T u1;
  int32_T i;
  uint32_T pinReadLoc;
  uint32_T pinReadLoc_0;

  /* MATLABSystem: '<S32>/Analog to Digital Converter' */
  regularReadADCDMA(MicroMouseTemplate_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                    &ADC1s[0]);

  /* DSPFlip: '<S9>/Flip' incorporates:
   *  MATLABSystem: '<S32>/Analog to Digital Converter'
   */
  MicroMouseTemplate_B.Flip[0] = ADC1s[7];
  MicroMouseTemplate_B.Flip[7] = ADC1s[0];
  MicroMouseTemplate_B.Flip[1] = ADC1s[6];
  MicroMouseTemplate_B.Flip[6] = ADC1s[1];
  MicroMouseTemplate_B.Flip[2] = ADC1s[5];
  MicroMouseTemplate_B.Flip[5] = ADC1s[2];
  MicroMouseTemplate_B.Flip[3] = ADC1s[4];
  MicroMouseTemplate_B.Flip[4] = ADC1s[3];

  /* DataTypeConversion: '<S35>/Cast To Double' */
  for (i = 0; i < 8; i++) {
    MicroMouseTemplate_B.CastToDouble[i] = MicroMouseTemplate_B.Flip[i];
  }

  /* End of DataTypeConversion: '<S35>/Cast To Double' */
  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[0],
    &MicroMouseTemplate_B.MATLABSystem2_ci,
    &MicroMouseTemplate_DW.MATLABSystem2_ci,
    &MicroMouseTemplate_P.MATLABSystem2_ci);

  /* MinMax: '<S33>/Max of Elements' incorporates:
   *  MATLABSystem: '<S35>/MATLAB System2'
   */
  MicroMouseTemplate_B.maxV =
    MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.maxV < u1) {
      MicroMouseTemplate_B.maxV = u1;
    }
  }

  MicroMouseTem_MATLABSystem3((real_T)MicroMouseTemplate_B.CastToDouble[1],
    &MicroMouseTemplate_B.MATLABSystem4, &MicroMouseTemplate_DW.MATLABSystem4,
    &MicroMouseTemplate_P.MATLABSystem4);

  /* MinMax: '<S33>/Max of Elements1' incorporates:
   *  MATLABSystem: '<S33>/MATLAB System4'
   */
  MicroMouseTemplate_B.maxV_m =
    MicroMouseTemplate_B.MATLABSystem4.MATLABSystem3[0];
  for (i = 0; i < 9; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem4.MATLABSystem3[i + 1];
    if (MicroMouseTemplate_B.maxV_m < u1) {
      MicroMouseTemplate_B.maxV_m = u1;
    }
  }

  MicroMouseTem_MATLABSystem1(MicroMouseTemplate_B.maxV_m,
    &MicroMouseTemplate_B.MATLABSystem1, &MicroMouseTemplate_DW.MATLABSystem1,
    &MicroMouseTemplate_P.MATLABSystem1);

  /* End of MinMax: '<S33>/Max of Elements1' */

  /* MinMax: '<S33>/Min' incorporates:
   *  MATLABSystem: '<S33>/MATLAB System1'
   */
  rtb_Quantizer1 = MicroMouseTemplate_B.MATLABSystem1.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem1.MATLABSystem1[i + 1];
    if (rtb_Quantizer1 > u1) {
      rtb_Quantizer1 = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[2],
    &MicroMouseTemplate_B.MATLABSystem1_ci,
    &MicroMouseTemplate_DW.MATLABSystem1_ci,
    &MicroMouseTemplate_P.MATLABSystem1_ci);

  /* MinMax: '<S33>/Max of Elements2' incorporates:
   *  MATLABSystem: '<S35>/MATLAB System1'
   */
  MicroMouseTemplate_B.maxV_m =
    MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.maxV_m < u1) {
      MicroMouseTemplate_B.maxV_m = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[3],
    &MicroMouseTemplate_B.MATLABSystem3_c,
    &MicroMouseTemplate_DW.MATLABSystem3_c,
    &MicroMouseTemplate_P.MATLABSystem3_c);

  /* MinMax: '<S33>/Max of Elements3' incorporates:
   *  MATLABSystem: '<S35>/MATLAB System3'
   */
  MicroMouseTemplate_B.maxV_c =
    MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.maxV_c < u1) {
      MicroMouseTemplate_B.maxV_c = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[4],
    &MicroMouseTemplate_B.MATLABSystem4_c,
    &MicroMouseTemplate_DW.MATLABSystem4_c,
    &MicroMouseTemplate_P.MATLABSystem4_c);

  /* MinMax: '<S33>/Max of Elements4' incorporates:
   *  MATLABSystem: '<S35>/MATLAB System4'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[i + 1];
    if (maxV < u1) {
      maxV = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[5],
    &MicroMouseTemplate_B.MATLABSystem5, &MicroMouseTemplate_DW.MATLABSystem5,
    &MicroMouseTemplate_P.MATLABSystem5);

  /* MinMax: '<S33>/Max of Elements5' incorporates:
   *  MATLABSystem: '<S35>/MATLAB System5'
   */
  maxV_0 = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[i + 1];
    if (maxV_0 < u1) {
      maxV_0 = u1;
    }
  }

  MicroMouseTem_MATLABSystem3((real_T)MicroMouseTemplate_B.CastToDouble[6],
    &MicroMouseTemplate_B.MATLABSystem3, &MicroMouseTemplate_DW.MATLABSystem3,
    &MicroMouseTemplate_P.MATLABSystem3);

  /* MinMax: '<S33>/Max of Elements6' incorporates:
   *  MATLABSystem: '<S33>/MATLAB System3'
   */
  maxV_1 = MicroMouseTemplate_B.MATLABSystem3.MATLABSystem3[0];
  for (i = 0; i < 9; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem3.MATLABSystem3[i + 1];
    if (maxV_1 < u1) {
      maxV_1 = u1;
    }
  }

  MicroMouseTem_MATLABSystem1(maxV_1, &MicroMouseTemplate_B.MATLABSystem2,
    &MicroMouseTemplate_DW.MATLABSystem2, &MicroMouseTemplate_P.MATLABSystem2);

  /* End of MinMax: '<S33>/Max of Elements6' */

  /* MinMax: '<S33>/Min1' incorporates:
   *  MATLABSystem: '<S33>/MATLAB System2'
   */
  minV = MicroMouseTemplate_B.MATLABSystem2.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem2.MATLABSystem1[i + 1];
    if (minV > u1) {
      minV = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[7],
    &MicroMouseTemplate_B.MATLABSystem6, &MicroMouseTemplate_DW.MATLABSystem6,
    &MicroMouseTemplate_P.MATLABSystem6);

  /* MinMax: '<S33>/Max of Elements7' incorporates:
   *  MATLABSystem: '<S35>/MATLAB System6'
   */
  maxV_1 = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[i + 1];
    if (maxV_1 < u1) {
      maxV_1 = u1;
    }
  }

  /* MinMax: '<S33>/Max of Elements' */
  u1 = fmod(floor(MicroMouseTemplate_B.maxV), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_H Write' incorporates:
   *  MinMax: '<S33>/Max of Elements'
   */
  ADC_H[0] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S33>/Min' */
  u1 = fmod(floor(rtb_Quantizer1), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_H Write' incorporates:
   *  MinMax: '<S33>/Min'
   */
  ADC_H[1] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S33>/Max of Elements2' */
  u1 = fmod(floor(MicroMouseTemplate_B.maxV_m), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_H Write' incorporates:
   *  MinMax: '<S33>/Max of Elements2'
   */
  ADC_H[2] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S33>/Max of Elements3' */
  u1 = fmod(floor(MicroMouseTemplate_B.maxV_c), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_H Write' incorporates:
   *  MinMax: '<S33>/Max of Elements3'
   */
  ADC_H[3] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S33>/Max of Elements4' */
  u1 = fmod(floor(maxV), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_H Write' incorporates:
   *  MinMax: '<S33>/Max of Elements4'
   */
  ADC_H[4] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S33>/Max of Elements5' */
  u1 = fmod(floor(maxV_0), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_H Write' incorporates:
   *  MinMax: '<S33>/Max of Elements5'
   */
  ADC_H[5] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S33>/Min1' */
  u1 = fmod(floor(minV), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_H Write' incorporates:
   *  MinMax: '<S33>/Min1'
   */
  ADC_H[6] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S33>/Max of Elements7' */
  u1 = fmod(floor(maxV_1), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_H Write' incorporates:
   *  Constant: '<S30>/Constant'
   *  MinMax: '<S33>/Max of Elements7'
   */
  ADC_H[7] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);
  ADC_H[8] = MicroMouseTemplate_P.Constant_Value_b;

  /* MinMax: '<S34>/Max of Elements8' incorporates:
   *  MATLABSystem: '<S35>/MATLAB System2'
   */
  rtb_Quantizer1 = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem2_ci.MATLABSystem1[i + 1];
    if (rtb_Quantizer1 > u1) {
      rtb_Quantizer1 = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[1],
    &MicroMouseTemplate_B.MATLABSystem1_c,
    &MicroMouseTemplate_DW.MATLABSystem1_c,
    &MicroMouseTemplate_P.MATLABSystem1_c);

  /* MinMax: '<S34>/Max of Elements9' incorporates:
   *  MATLABSystem: '<S34>/MATLAB System1'
   */
  minV = MicroMouseTemplate_B.MATLABSystem1_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem1_c.MATLABSystem1[i + 1];
    if (minV > u1) {
      minV = u1;
    }
  }

  /* MinMax: '<S34>/Max of Elements10' incorporates:
   *  MATLABSystem: '<S35>/MATLAB System1'
   */
  MicroMouseTemplate_B.maxV_m =
    MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem1_ci.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.maxV_m > u1) {
      MicroMouseTemplate_B.maxV_m = u1;
    }
  }

  /* MinMax: '<S34>/Max of Elements11' incorporates:
   *  MATLABSystem: '<S35>/MATLAB System3'
   */
  MicroMouseTemplate_B.maxV_c =
    MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem3_c.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.maxV_c > u1) {
      MicroMouseTemplate_B.maxV_c = u1;
    }
  }

  /* MinMax: '<S34>/Max of Elements12' incorporates:
   *  MATLABSystem: '<S35>/MATLAB System4'
   */
  maxV = MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem4_c.MATLABSystem1[i + 1];
    if (maxV > u1) {
      maxV = u1;
    }
  }

  /* MinMax: '<S34>/Max of Elements13' incorporates:
   *  MATLABSystem: '<S35>/MATLAB System5'
   */
  maxV_0 = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem5.MATLABSystem1[i + 1];
    if (maxV_0 > u1) {
      maxV_0 = u1;
    }
  }

  MicroMouseTem_MATLABSystem1((real_T)MicroMouseTemplate_B.CastToDouble[6],
    &MicroMouseTemplate_B.MATLABSystem2_c,
    &MicroMouseTemplate_DW.MATLABSystem2_c,
    &MicroMouseTemplate_P.MATLABSystem2_c);

  /* MinMax: '<S34>/Max of Elements14' incorporates:
   *  MATLABSystem: '<S34>/MATLAB System2'
   */
  maxV_1 = MicroMouseTemplate_B.MATLABSystem2_c.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem2_c.MATLABSystem1[i + 1];
    if (maxV_1 > u1) {
      maxV_1 = u1;
    }
  }

  /* MinMax: '<S34>/Max of Elements15' incorporates:
   *  MATLABSystem: '<S35>/MATLAB System6'
   */
  MicroMouseTemplate_B.maxV = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[0];
  for (i = 0; i < 24; i++) {
    u1 = MicroMouseTemplate_B.MATLABSystem6.MATLABSystem1[i + 1];
    if (MicroMouseTemplate_B.maxV > u1) {
      MicroMouseTemplate_B.maxV = u1;
    }
  }

  /* MinMax: '<S34>/Max of Elements8' */
  u1 = fmod(floor(rtb_Quantizer1), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_L Write' incorporates:
   *  MinMax: '<S34>/Max of Elements8'
   */
  ADC_L[0] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S34>/Max of Elements9' */
  u1 = fmod(floor(minV), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_L Write' incorporates:
   *  MinMax: '<S34>/Max of Elements9'
   */
  ADC_L[1] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S34>/Max of Elements10' */
  u1 = fmod(floor(MicroMouseTemplate_B.maxV_m), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_L Write' incorporates:
   *  MinMax: '<S34>/Max of Elements10'
   */
  ADC_L[2] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S34>/Max of Elements11' */
  u1 = fmod(floor(MicroMouseTemplate_B.maxV_c), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_L Write' incorporates:
   *  MinMax: '<S34>/Max of Elements11'
   */
  ADC_L[3] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S34>/Max of Elements12' */
  u1 = fmod(floor(maxV), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_L Write' incorporates:
   *  MinMax: '<S34>/Max of Elements12'
   */
  ADC_L[4] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S34>/Max of Elements13' */
  u1 = fmod(floor(maxV_0), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_L Write' incorporates:
   *  MinMax: '<S34>/Max of Elements13'
   */
  ADC_L[5] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S34>/Max of Elements14' */
  u1 = fmod(floor(maxV_1), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_L Write' incorporates:
   *  MinMax: '<S34>/Max of Elements14'
   */
  ADC_L[6] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);

  /* MinMax: '<S34>/Max of Elements15' */
  u1 = fmod(floor(MicroMouseTemplate_B.maxV), 65536.0);

  /* DataStoreWrite: '<S30>/ADC_L Write' incorporates:
   *  Constant: '<S30>/Constant1'
   *  MinMax: '<S34>/Max of Elements15'
   */
  ADC_L[7] = (uint16_T)(u1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u1 :
                        (int32_T)(uint16_T)u1);
  ADC_L[8] = MicroMouseTemplate_P.Constant1_Value_c;

  /* MATLABSystem: '<S53>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S51>/Digital Port Read' */
  pinReadLoc_0 = LL_GPIO_ReadInputPort(GPIOE);

  /* Quantizer: '<S1>/Quantizer1' incorporates:
   *  DataTypeConversion: '<S1>/Cast To Double1'
   *  Gain: '<S1>/Gain2'
   */
  rtb_Quantizer1 = rt_roundd((real_T)((uint32_T)MicroMouseTemplate_P.Gain2_Gain *
    MicroMouseTemplate_B.Flip[6]) * 1.4901161193847656E-8 /
    MicroMouseTemplate_P.Quantizer1_Interval) *
    MicroMouseTemplate_P.Quantizer1_Interval;

  /* Chart: '<Root>/HelloMicroMouse!' incorporates:
   *  DSPFlip: '<S1>/Flip1'
   *  Logic: '<S12>/NOT'
   *  Logic: '<S12>/NOT1'
   *  MATLABSystem: '<S51>/Digital Port Read'
   *  MATLABSystem: '<S53>/Digital Port Read'
   * */
  if (MicroMouseTemplate_DW.temporalCounter_i1 < 31U) {
    MicroMouseTemplate_DW.temporalCounter_i1++;
  }

  if (MicroMouseTemplate_DW.bitsForTID1.is_active_c2_MicroMouseTemplate == 0U) {
    MicroMouseTemplate_DW.bitsForTID1.is_active_c2_MicroMouseTemplate = 1U;
    MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
    MicroMouseTemplate_DW.bitsForTID1.is_c2_MicroMouseTemplate =
      Micr_IN_WaitUntilButtonPressed2;
  } else {
    switch (MicroMouseTemplate_DW.bitsForTID1.is_c2_MicroMouseTemplate) {
     case MicroMouseTemplate_IN_Baseline1:
      if (MicroMouseTemplate_DW.counter >= 50.0) {
        MicroMouseTemplate_DW.bitsForTID1.is_c2_MicroMouseTemplate =
          MicroMouseTemplate_IN_Baseline2;
        if (MicroMouseTemplate_DW.baseline <= 1.0) {
          MicroMouseTemplate_B.LED0 = true;
          MicroMouseTemplate_B.LED1 = true;
          MicroMouseTemplate_B.LED2 = true;
        }

        if (MicroMouseTemplate_DW.baseline <= 1.5) {
          MicroMouseTemplate_B.LED0 = false;
          MicroMouseTemplate_B.LED1 = true;
          MicroMouseTemplate_B.LED2 = true;
        }

        if (MicroMouseTemplate_DW.baseline <= 2.0) {
          MicroMouseTemplate_B.LED0 = false;
          MicroMouseTemplate_B.LED1 = false;
          MicroMouseTemplate_B.LED2 = true;
        }
      } else {
        while (MicroMouseTemplate_DW.counter <= 50.0) {
          MicroMouseTemplate_DW.counter++;
          MicroMouseTemplate_DW.sum += rtb_Quantizer1;
        }

        MicroMouseTemplate_DW.baseline = MicroMouseTemplate_DW.sum /
          MicroMouseTemplate_DW.counter;
      }
      break;

     case MicroMouseTemplate_IN_Baseline2:
      if ((pinReadLoc_0 & 64U) == 0U) {
        MicroMouseTemplate_DW.bitsForTID1.is_c2_MicroMouseTemplate =
          MicroMouseTem_IN_ButtonPressed2;
        MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed2 =
          MicroMouseTemplate_IN_Left;
        MicroMouseTemplate_B.leftWheelforward = 3000.0;
        MicroMouseTemplate_B.rightWheelforward = 3000.0;
        MicroMouseTemplate_B.leftWheelbackward = 0.0;
        MicroMouseTemplate_B.rightWheelbackward = 0.0;
      }
      break;

     case MicroMouseTem_IN_ButtonPressed2:
      if ((pinReadLoc & 4U) == 0U) {
        MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed2 =
          MicroMouseTe_IN_NO_ACTIVE_CHILD;
        MicroMouseTemplate_DW.bitsForTID1.is_c2_MicroMouseTemplate =
          MicroMouseTemplate_IN_Stop2;
        MicroMouseTemplate_B.LED0 = false;
        MicroMouseTemplate_B.LED1 = false;
        MicroMouseTemplate_B.LED2 = false;
        MicroMouseTemplate_B.leftWheelforward = 0.0;
        MicroMouseTemplate_B.rightWheelforward = 0.0;
        MicroMouseTemplate_B.leftWheelbackward = 0.0;
        MicroMouseTemplate_B.rightWheelbackward = 0.0;
      } else if (MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed2 ==
                 MicroMouseTemplate_IN_Left) {
        if (rtb_Quantizer1 > MicroMouseTemplate_DW.baseline + 0.5) {
          MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed2 =
            MicroMouseTemplate_IN_Right;
          MicroMouseTemplate_B.leftWheelforward = 0.0;
          MicroMouseTemplate_B.rightWheelforward = 3000.0;
          MicroMouseTemplate_B.leftWheelbackward = 3000.0;
          MicroMouseTemplate_B.rightWheelbackward = 0.0;
        }

        /* case IN_Right: */
      } else if (rtb_Quantizer1 <= MicroMouseTemplate_DW.baseline) {
        MicroMouseTemplate_DW.bitsForTID1.is_ButtonPressed2 =
          MicroMouseTemplate_IN_Left;
        MicroMouseTemplate_B.leftWheelforward = 3000.0;
        MicroMouseTemplate_B.rightWheelforward = 3000.0;
        MicroMouseTemplate_B.leftWheelbackward = 0.0;
        MicroMouseTemplate_B.rightWheelbackward = 0.0;
      }
      break;

     case MicroMouseTemplate_IN_Stop2:
      if ((pinReadLoc & 4U) == 0U) {
        MicroMouseTemplate_DW.temporalCounter_i1 = 0U;
        MicroMouseTemplate_DW.bitsForTID1.is_c2_MicroMouseTemplate =
          Micr_IN_WaitUntilButtonPressed2;
      }
      break;

     default:
      /* case IN_WaitUntilButtonPressed2: */
      if (MicroMouseTemplate_DW.temporalCounter_i1 >= 20U) {
        MicroMouseTemplate_DW.bitsForTID1.is_c2_MicroMouseTemplate =
          MicroMouseTemplate_IN_Baseline1;
        MicroMouseTemplate_B.LED0 = false;
        MicroMouseTemplate_B.LED1 = false;
        MicroMouseTemplate_B.LED2 = false;
      } else {
        MicroMouseTemplate_B.LED0 = !MicroMouseTemplate_B.LED0;
        MicroMouseTemplate_B.LED1 = !MicroMouseTemplate_B.LED1;
        MicroMouseTemplate_B.LED2 = !MicroMouseTemplate_B.LED2;
        MicroMouseTemplate_B.leftWheelforward = 0.0;
        MicroMouseTemplate_B.rightWheelforward = 0.0;
        MicroMouseTemplate_B.leftWheelbackward = 0.0;
        MicroMouseTemplate_B.rightWheelbackward = 0.0;
        MicroMouseTemplate_DW.baseline = 0.0;
        MicroMouseTemplate_DW.counter = 0.0;
        MicroMouseTemplate_DW.sum = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/HelloMicroMouse!' */

  /* MATLABSystem: '<S28>/PWM Output' */
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

  /* End of MATLABSystem: '<S28>/PWM Output' */

  /* MATLABSystem: '<S26>/PWM Output' */
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

  /* End of MATLABSystem: '<S26>/PWM Output' */

  /* MATLABSystem: '<S43>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOC;
  if (MicroMouseTemplate_B.LED0) {
    i = 8192;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 8192U);

  /* End of MATLABSystem: '<S43>/Digital Port Write' */

  /* MATLABSystem: '<S45>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOC;
  if (MicroMouseTemplate_B.LED1) {
    i = 16384;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 16384U);

  /* End of MATLABSystem: '<S45>/Digital Port Write' */

  /* MATLABSystem: '<S47>/Digital Port Write' */
  MicroMouseTemplate_B.portNameLoc = GPIOC;
  if (MicroMouseTemplate_B.LED2) {
    i = 32768;
  } else {
    i = 0;
  }

  LL_GPIO_SetOutputPin(MicroMouseTemplate_B.portNameLoc, (uint32_T)i);
  LL_GPIO_ResetOutputPin(MicroMouseTemplate_B.portNameLoc, ~(uint32_T)i & 32768U);

  /* End of MATLABSystem: '<S47>/Digital Port Write' */

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
    for (i = 0; i < 8; i++) {
      /* Start for DataStoreMemory: '<S2>/Data Store Memory' */
      Detections[i] = MicroMouseTemplate_P.DataStoreMemory_InitialValue_p4;

      /* Start for DataStoreMemory: '<S2>/Data Store Memory1' */
      Thresholds[i] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue_j;
    }

    /* Start for DataStoreMemory: '<S2>/Data Store Memory2' */
    currTicksRS = MicroMouseTemplate_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<S2>/Data Store Memory4' */
    currTicksLS = MicroMouseTemplate_P.DataStoreMemory4_InitialValue;

    /* Start for DataStoreMemory: '<S10>/Data Store Memory' */
    IMU_Accel[0] = MicroMouseTemplate_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S10>/Data Store Memory1' */
    IMU_Gyro[0] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<S10>/Data Store Memory' */
    IMU_Accel[1] = MicroMouseTemplate_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S10>/Data Store Memory1' */
    IMU_Gyro[1] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<S10>/Data Store Memory' */
    IMU_Accel[2] = MicroMouseTemplate_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S10>/Data Store Memory1' */
    IMU_Gyro[2] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue;
    for (i = 0; i < 9; i++) {
      /* Start for DataStoreMemory: '<S9>/Data Store Memory' */
      ADC1s[i] = MicroMouseTemplate_P.DataStoreMemory_InitialValue_p;

      /* Start for DataStoreMemory: '<S9>/Data Store Memory1' */
      ADC_H[i] = MicroMouseTemplate_P.DataStoreMemory1_InitialValue_p;

      /* Start for DataStoreMemory: '<S9>/Data Store Memory2' */
      ADC_L[i] = MicroMouseTemplate_P.DataStoreMemory2_InitialValue_p;
    }

    /* user code (Initialize function Body) */

    /* System '<Root>' */
    initIMU();

    /* Start for MATLABSystem: '<S32>/Analog to Digital Converter' */
    MicroMouseTemplate_DW.obj.isInitialized = 0;
    MicroMouseTemplate_DW.obj.matlabCodegenIsDeleted = false;
    MicroMouseTemp_SystemCore_setup(&MicroMouseTemplate_DW.obj);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem2_ci,
      &MicroMouseTemplate_P.MATLABSystem2_ci);
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
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem6,
      &MicroMouseTemplate_P.MATLABSystem6);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem1_c,
      &MicroMouseTemplate_P.MATLABSystem1_c);
    MicroMou_MATLABSystem1_Init(&MicroMouseTemplate_DW.MATLABSystem2_c,
      &MicroMouseTemplate_P.MATLABSystem2_c);

    /* Start for MATLABSystem: '<S28>/PWM Output' */
    MicroMouseTemplate_DW.obj_g.matlabCodegenIsDeleted = false;
    MicroMouseTemplate_DW.obj_g.isSetupComplete = false;
    MicroMouseTemplate_DW.obj_g.isInitialized = 1;
    MicroMous_PWMOutput_setupImpl_d(&MicroMouseTemplate_DW.obj_g);
    MicroMouseTemplate_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S26>/PWM Output' */
    MicroMouseTemplate_DW.obj_n.matlabCodegenIsDeleted = false;
    MicroMouseTemplate_DW.obj_n.isSetupComplete = false;
    MicroMouseTemplate_DW.obj_n.isInitialized = 1;
    MicroMouseT_PWMOutput_setupImpl(&MicroMouseTemplate_DW.obj_n);
    MicroMouseTemplate_DW.obj_n.isSetupComplete = true;
  }
}

/* Model terminate function */
void MicroMouseTemplate_terminate(void)
{
  /* Terminate for MATLABSystem: '<S32>/Analog to Digital Converter' */
  if (!MicroMouseTemplate_DW.obj.matlabCodegenIsDeleted) {
    MicroMouseTemplate_DW.obj.matlabCodegenIsDeleted = true;
    if ((MicroMouseTemplate_DW.obj.isInitialized == 1) &&
        MicroMouseTemplate_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(MicroMouseTemplate_DW.obj.ADCHandle,
                        ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S32>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S28>/PWM Output' */
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

  /* End of Terminate for MATLABSystem: '<S28>/PWM Output' */

  /* Terminate for MATLABSystem: '<S26>/PWM Output' */
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

  /* End of Terminate for MATLABSystem: '<S26>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
