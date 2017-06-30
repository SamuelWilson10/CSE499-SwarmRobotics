/******************************************************************************
*
*                      Ain Shams University
*                     Faculty of Engineering
*
*******************************************************************************
*               File: linetracker.cpp
*        Description: Line Trakcer API source file
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
/*=============================== INCLUSIONS ================================*/
#include "linetracker.h"
/*============================ MACRO DEFINITIONS ============================*/

/*================================= GLOBALS =================================*/
unsigned long LineDetectorCounterLeft = 0;
unsigned long LineDetectorCounterRight = 0;

/*=========================== FUNCTIONS DEFINITIONS =========================*/
/**
*  ISR for first line detector, simply increments a counter
*/
void LineDetectorFunction_1() {
  LineDetectorCounterLeft++;
}
/*****************************************************************************/
/**
*  ISR for second line detector, simply increments a counter
*/
void LineDetectorFunction_2() {
  LineDetectorCounterRight++;
}
/*****************************************************************************/
/**
*  Initializes both line trackers. Sets GPIO pins and Enables Interrupts
*/
void init_line_tracker() {
  pinMode(LineDetectorLeft , INPUT);
  pinMode(LineDetectorRight , INPUT);
  pinMode(LineDetectorLeft , INPUT_PULLUP);
  pinMode(LineDetectorRight , INPUT_PULLUP);
  attachInterrupt (digitalPinToInterrupt(LineDetectorLeft), LineDetectorFunction_1, FALLING);
  attachInterrupt (digitalPinToInterrupt(LineDetectorRight), LineDetectorFunction_2, RISING);
}
/*========================== END OF linetracker.cpp =========================*/
