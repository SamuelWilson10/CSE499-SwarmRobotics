/******************************************************************************
*
*                      Ain Shams University
*                     Faculty of Engineering
*
*******************************************************************************
*               File: ultrasonic.h
*        Description: UltraSonic Sensor API header file 
*         Dependency: None
*        Assumptions: N/A
*			Hardware: HC-SR04 UltraSonic Sensor (out-of-the-shelf)
*           Platform: AVR 8-bit
*
* Date:         Authors:           Revision Number:
* -----         -------           ----------------
* 24-06-2017    Mina Sherif       1.0
* 24-06-2017    Maram Zidan       1.0
*
******************************************************************************/
#ifndef __ULTRASONIC_H_ 
#define __ULTRASONIC_H_    

/*=============================== INCLUSIONS ================================*/
#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include "PinsDefinition.h"

/*============================ MACRO DEFINITIONS ============================*/
#define MAXRANGE			150		// Maximum range in cm

/*================================= GLOBALS =================================*/
/*=========================== FUNCTIONS DECLARATIONS ========================*/
/**
*  returns an averaged (4 readings) reading for a specific sensor
*/
unsigned long ultrasonic (byte sensor);
/*****************************************************************************/
/**
*  returns a single reading from a specific sensor
*  returns MAX RANGE if reading exceeds it	
*/
unsigned long getReading(byte i);
/*****************************************************************************/
/**
*  Intializes all ultrasonic sensors
*/
void init_ultrasonic();
#endif
/*=========================== END OF ultrasonic.h ===========================*/
