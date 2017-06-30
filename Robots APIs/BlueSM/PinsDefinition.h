/******************************************************************************
*
*                      Ain Shams University
*                     Faculty of Engineering
*
*******************************************************************************
*               File: PinsDefinition.h
*        Description: Contains all definition of pins used 
*         Dependency: None
*        Assumptions: N/A
*			Hardware: Arduino Nano (ATmega328p)
*           Platform: AVR 8-bit
*
* Date:         Authors:           Revision Number:
* -----         --------           ----------------
* 30-06-2017    Samuel Wilson      1.0
*
******************************************************************************/
#ifndef __PINSDEFINITION_H_
#define __PINSDEFINITION_H_

#define MEGA          		0     // Arduino Mega requires different Pinout

/* RF: uses SPI pins in addition to the following pins */
#if (MEGA == 1)
  #define RF_CE				53
  #define RF_CSN			48
#else
  #define RF_CE				7
  #define RF_CSN			8
#endif

/* Line Tracker */
#define LineDetectorLeft 	2 		// Left  wheel
#define LineDetectorRight 	3 		// Right wheel

/* Ultrasonic */
#define ultraSonicEcho  	A3 		// Ultrasonic echo pin
#define ultraSoundSignal  	A0 		// Ultrasonic signal pin

/* Motor Driver */
#define motorL1 			5
#define motorR1 			10 
#define motorL2 			6
#define motorR2 			9

/* Color Sensor */
#define stwo				10
#define sthree				9 
#define colorout  			4

/* Electromagnet */
#define Electromagnet		4

#endif
