/******************************************************************************
*
*                      Ain Shams University
*                     Faculty of Engineering
*
*******************************************************************************
*               File: motordriver.h
*        Description: Motor Driver API header file
*         Dependency: N/A
*        Assumptions: N/A
*			Hardware: L9110 Dual Motor Driver
*           Platform: AVR 8-bit
*
* Date:         Author:           Revision Number:
* -----         -------           ----------------
* 15-06-2017    Mina Sherif       1.0
* 17-06-2017	Michael Adel	  1.1
*
******************************************************************************/
#ifndef __MOTORDRIVER_H_ 
#define __MOTORDRIVER_H_    

/*=============================== INCLUSIONS ================================*/
#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include "PinsDefinition.h"

/*============================ MACRO DEFINITIONS ============================*/
/* Basic functions are defined as macros to save stack space */
#define MotorDriverLeft( pwm , dir){    switch (dir)  { case 1: analogWrite(motorL1, 0); analogWrite(motorR1,pwm);  break; case 0: analogWrite(motorL1,  pwm); analogWrite(motorR1,0);   break;  }}
#define MotorDriverRight( pwm , dir){    switch (dir)  { case 1: analogWrite(motorL2, 255 - pwm); analogWrite(motorR2,255);  break; case 0: analogWrite(motorL2, pwm); analogWrite(motorR2,0);   break;  }}

#define BreakMotorLeft() digitalWrite( motorL1, HIGH );  digitalWrite( motorR1, HIGH )
#define BreakMotorRight() digitalWrite( motorL2, HIGH ); digitalWrite( motorR2, HIGH )

#define StopMotorLeft() digitalWrite( motorL1, LOW );  digitalWrite( motorR1, LOW )
#define StopMotorRight() digitalWrite( motorL2, LOW ); digitalWrite( motorR2, LOW )

/*================================= GLOBALS =================================*/
/*=========================== FUNCTIONS DECLARATIONS ========================*/
/**
*  Initializes the motor driver
*/
void init_motor_driver();
#endif
/*========================== END OF motordriver.h ===========================*/