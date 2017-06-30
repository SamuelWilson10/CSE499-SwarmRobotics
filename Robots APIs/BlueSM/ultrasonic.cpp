/******************************************************************************
*
*                      Ain Shams University
*                     Faculty of Engineering
*
*******************************************************************************
*               File: ultrasonic.cpp
*        Description: UltraSonic Sensor API source file 
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
/*=============================== INCLUSIONS ================================*/
#include "ultrasonic.h"
/*============================ MACRO DEFINITIONS ============================*/

/*================================= GLOBALS =================================*/
/*=========================== FUNCTIONS DEFINITIONS =========================*/
/**
*  returns an averaged (4 readings) reading for a specific sensor
*/
unsigned long ultrasonic (byte sensor) {
  unsigned long res = 0;
  for (byte i = 0; i < 4; i++) {
	res += getReading(sensor);
  }
  return (res >> 2);
}
/*****************************************************************************/
/**
*  returns a single reading from a specific sensor
*  returns MAX RANGE if reading exceeds it	
*/
unsigned long getReading(byte i) {
  unsigned long ultrasoundValue;
  digitalWrite(ultraSonicEcho + i, HIGH); 	// Turn on pullup resistor
  unsigned long echo = 0;                  	//duration of the echo pulse
  while(echo == 0) {
	taskENTER_CRITICAL();
    digitalWrite(ultraSoundSignal + i, LOW); // Send low pulse
    delayMicroseconds(2); // Wait for 2 microseconds
    digitalWrite(ultraSoundSignal + i, HIGH); // Send high pulse
    delayMicroseconds(5); // Wait for 5 microseconds
    digitalWrite(ultraSoundSignal + i, LOW); // Holdoff
    /* please note that pulseIn has a 1sec timeout, which may
	 * not be desirable. Depending on your sensor specs, you
     * can likely bound the time like this -- marcmerlin
	 */
    echo = pulseIn(ultraSonicEcho + i, HIGH); // Listen for echo
    taskEXIT_CRITICAL();

    ultrasoundValue = (echo / 58.138); // convert to CM
  }
  if (ultrasoundValue < MAXRANGE) {
    return ultrasoundValue;
  } 
  else
	// Returns 0 in case of error
	return MAXRANGE;
}
/*****************************************************************************/
/**
*  Intializes all ultrasonic sensors
*/
void init_ultrasonic() {
	for(char i = 0;i<3;i++) {
	  pinMode(ultraSoundSignal + i, OUTPUT); //set the signal pin to OUTPUT
	  pinMode(ultraSonicEcho + i, INPUT);    //sets the echo pin to INPUT
	}
}
/*========================== END OF ultrasonic.cpp ==========================*/
