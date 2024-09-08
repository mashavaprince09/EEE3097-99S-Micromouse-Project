//********************************************************************
//*                      Mech Educational Board                      *
//*                          IMU Library                             *
//*==================================================================*
//* @author:    Jesse Jabez Arendse                                  *
//* @date:      24-10-2023                                           *
//*==================================================================*
#ifndef IMU_H
#define IMU_H

#include "stm32l4xx.h"
#include "main.h"

//====================================================================
// GLOBAL CONSTANTS
//====================================================================

#define IMU_ADDRESS 0b1101001 //left floating, works with AD0 = 1

#define IMU_DEVICE_CHECK 0x75 // read this, returns 104 if working
#define IMU_WAKE_ADDRESS 0x6B
#define IMU_OUTPUT_RATE_ADDRESS 0x19
#define IMU_ACCEL_CONFIG_ADDRESS 0x1C
#define IMU_GYRO_CONFIG_ADDRESS 0x1B
#define IMU_ACCEL_DATA_ADDRESS 0x3B
#define IMU_GYRO_DATA_ADDRESS 0x43

#define IMU_OUTPUT_RATE 0x07

#define IMU_X_AXIS 0
#define IMU_Y_AXIS 1
#define IMU_Z_AXIS 2


//====================================================================
// FUNCTION DECLARATIONS
//====================================================================


float readAccel(short axis);
float readGyro(short axis);
void refreshIMUValues();
void initIMU();
//====================================================================

#endif

//********************************************************************
// END OF PROGRAM
//********************************************************************
