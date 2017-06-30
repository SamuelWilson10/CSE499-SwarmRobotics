/******************************************************************************
*
*                      Ain Shams University
*                     Faculty of Engineering
*
*******************************************************************************
*               File: colorsensor.cpp
*        Description: Color Sensor API source file 
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
/*=============================== INCLUSIONS ================================*/
#include "colorsensor.h"

/*============================ MACRO DEFINITIONS ============================*/
/*================================= GLOBALS =================================*/
/*=========================== FUNCTIONS DEFINITIONS =========================*/
/**
*  Initialization function for GPIO
*/
void init_color_sensor() {
  pinMode(stwo, OUTPUT);
  pinMode(sthree, OUTPUT);
  pinMode(colorout, INPUT);
}
/*****************************************************************************/
/**
*  Returns the intensity of a certain color
*/
unsigned long colorSensor(char color) {
  unsigned long counters	= 0; // gets input from sensor frequency generator
  unsigned long countR 		= 0; // accumilates 8 readings to get average
  unsigned long count 		= 0; // saves the final average reading

  // gets 8 reading for each color
  for (char i = 0; i < 8; i++) {
    if(color == 1) {
      digitalWrite(stwo, LOW);
      digitalWrite(sthree, LOW); 
    }
    else if(color == 0) {
      digitalWrite(stwo, LOW);
      digitalWrite(sthree, HIGH);
    }
    else if(color == 2) {
      digitalWrite(stwo, HIGH);
      digitalWrite(sthree, HIGH);
    }
    else if(color == 3) {
      digitalWrite(stwo, HIGH);
      digitalWrite(sthree, LOW);
    }

	// resets counter
    counters = 0;  
	
    /* stops RTOS interrupt */
    taskENTER_CRITICAL();
	
	/* reads the pulse width which is inversely proportional to the frequency
	 * so the less the pulse width the more the frequency and the more the 
	 * intensity
	 */
    counters = pulseIn(colorout, LOW);
	
	/* resumes RTOS interrupt */
    taskEXIT_CRITICAL();

    countR = countR + counters;

  }

  count = countR >> 3;
  return count;
}
/*========================== END OF colorsensor.cpp =========================*/