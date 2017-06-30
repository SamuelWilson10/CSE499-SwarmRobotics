/******************************************************************************
*
*                      Ain Shams University
*                     Faculty of Engineering
*
*******************************************************************************
*               File: colorsensor.h
*        Description: Color Sensor API header file 
*         Dependency: None
*        Assumptions: N/A
*			Hardware: TCS230 RGB sensor
*           Platform: AVR 8-bit
*
* Date:         Author:           Revision Number:
* -----         -------           ----------------
* 24-06-2017    Mina Sherif       1.0
*
******************************************************************************/
#ifndef __COLORSENSOR_H_ 
#define __COLORSENSOR_H_

/*=============================== INCLUSIONS ================================*/
#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include "PinsDefinition.h"

/*============================ MACRO DEFINITIONS ============================*/

/*================================= GLOBALS =================================*/
/*=========================== FUNCTIONS DECLARATIONS ========================*/
/**
*  Initialization function for GPIO
*/
void init_color_sensor();
/*****************************************************************************/
/**
*  Returns the intensity of a certain color
*/
unsigned long colorSensor(char color);
#endif
/*=========================== END OF colorsensor.h ==========================*/
