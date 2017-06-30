/******************************************************************************
*
*                      Ain Shams University
*                     Faculty of Engineering
*
*******************************************************************************
*               File: motordriver.cpp
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
/*=============================== INCLUSIONS ================================*/
#include "motordriver.h"
/*============================ MACRO DEFINITIONS ============================*/

/*================================= GLOBALS =================================*/
/*=========================== FUNCTIONS DECLARATIONS ========================*/
/**
*  Initializes the motor driver
*/
void init_motor_driver() {
  pinMode(motorL1,OUTPUT);
  pinMode(motorR1,OUTPUT);
  pinMode(motorL2,OUTPUT);
  pinMode(motorR2,OUTPUT);
  BreakMotorLeft();
  BreakMotorRight();
}
/*========================= END OF motordriver.cpp ==========================*/