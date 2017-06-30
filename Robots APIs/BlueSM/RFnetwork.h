/******************************************************************************
*
*                      Ain Shams University
*                     Faculty of Engineering
*
*******************************************************************************
*               File: RFnetwork.h
*        Description: RF Transceiver API header file
*         Dependency: TMRH 20 RF24 library.
*                     Arduino FreeRTOS
*        Assumptions: N/A
*			Hardware: 2.4 GHz nRF 24L01
*           Platform: AVR 8-bit
*
* Date:         Author:           Revision Number:
* -----         -------           ----------------
* 22-06-2017    Samuel Wilson     1.0
*
******************************************************************************/
#ifndef __RFNETWORK_H_ 
#define __RFNETWORK_H_    
/*=============================== INCLUSIONS ================================*/
#include "RF24.h"
#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include "PinsDefinition.h"

/*============================ MACRO DEFINITIONS ============================*/
#define VERBOSE       	0     // Enables verbose output via Serial Port 
#define RFRECVPERIOD  	10    // RF Receiving period in system ticks
#define RFSENDPERIOD  	15    // RF Sending period in system ticks
#define TASKSTACKSZIE 	128   // Stack size for the tasks
#define READINGPIPE		0	  // Address of reading pipe
#define WRITINGPIPE		1	  // Address of writing pipe

/*=========================== FUNCTIONS DECLARATIONS ========================*/
/*****************************************************************************/
/**
*  Prints all the fields of a specific frame, useful in debugging.
*/
#if(VERBOSE == 1)
void printFrame(struct FRAME * frame);
#endif
/*****************************************************************************/
/**
*  Sends ownFrame via RF
*  RETURN: True if successful
*  RETURN: False otherwise
*/
bool sendFrame();
/*****************************************************************************/
/**
*  RTOS Periodic task for sending RF frames 
*/
void vSendFrame(void * param);
/*****************************************************************************/
/**
*  RTOS Periodic task for receiving RF frames 
*/
void vRecvFrame(void * param);
/*****************************************************************************/
/**
*  Initializes RF and creates RTOS tasks
*/
void init_rf();
#endif
/*=========================== END OF RFnetwork.h ============================*/
