/******************************************************************************
*
*                      Ain Shams University
*                     Faculty of Engineering
*
*******************************************************************************
*               File: linetracker.h
*        Description: Line Trakcer API header file 
*         Dependency: None
*        Assumptions: N/A
*			Hardware: Horizontal Line Trakcer
*           Platform: AVR 8-bit
*
* Date:         Author:           Revision Number:
* -----         -------           ----------------
* 24-06-2017    Michael Adel      1.0
*
******************************************************************************/
#ifndef __LINETRACKER_H_ 
#define __LINETRACKER_H_    
/*=============================== INCLUSIONS ================================*/
#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include "PinsDefinition.h"

/*============================ MACRO DEFINITIONS ============================*/

/*================================= GLOBALS =================================*/
extern unsigned long LineDetectorCounterLeft;
extern unsigned long LineDetectorCounterRight;

/*=========================== FUNCTIONS DECLARATIONS ========================*/
/**
*  ISR for first line detector, simply increments a counter
*/
void LineDetectorFunction_1();
/*****************************************************************************/
/**
*  ISR for second line detector, simply increments a counter
*/
void LineDetectorFunction_2();
/*****************************************************************************/
/**
*  Initializes both line trackers. Sets GPIO pins and Enables Interrupts
*/
void init_line_tracker();
#endif
/*=========================== END OF linetracker.h ==========================*/