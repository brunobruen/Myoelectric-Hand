//Script to control InMoov Arm using Muscle Sensor V3 from Advancer Technologies
//by Carlos Alquezar (calquezar87@gmail.com)
//Zaragoza (Spain)
//February 2014
//Part of Roujin Project (website available soon)

//For information about Muscle Sensor V3 board, manual and other resouces, please visit:
// http://www.advancertechnologies.com/p/muscle-sensor-v3.html

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details. 
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
*/


#include <Servo.h>

#define THRESHOLD 300 //In order to determine the state of the hand (opened/closed)
#define EMGPIN0 A0 //Analog pin connected to Muscle Sensor V3 Board
/* To add other myoware muscle sensors
#define EMGPIN1 A1 //Analog pin connected to Muscle Sensor V3 Board
#define EMGPIN2 A2 //Analog pin connected to Muscle Sensor V3 Board
*/
#define LITTLEPIN  3 //Digital pin used by Little servo
#define RINGPIN    5 //Digital pin used by Ring servo
#define MIDDLEPIN  6 //Digital pin used by Middle servo
#define INDEXPIN   9 //Digital pin used by Index servo
#define THUMBPIN  10 //Digital pin used by Thumb servo

//Constants used to open and close the fingers
#define LITTLE 1 
#define RING   2
#define MIDDLE 3
#define INDEX  4
#define THUMB  5

Servo servoLittleFinger;         // Define servo fingers
Servo servoRingFinger;         // Define servo fingers
Servo servoMiddleFinger;         // Define servo fingers
Servo servoIndexFinger;         // Define servo fingers
Servo servoThumbFinger;         // Define servo fingers

int finger;

// Motion routines for handopen and handclose
void openhand(){for(finger = 1; finger < 6; finger++){openFinger(finger);}}
void closehand(){for(finger = 1; finger < 6 ; finger++){closeFinger(finger);}}

void openFinger(int finger){
  if(finger==LITTLE){servoLittleFinger.write(170);} // Little finger
  else if(finger==RING){servoRingFinger.write(170);}// Ring finger
  else if(finger==MIDDLE){servoMiddleFinger.write(170);}// Middle fingers
  else if(finger==INDEX){servoIndexFinger.write(170);}// Index finger
  else if(finger==THUMB){servoThumbFinger.write(170);}//Thumb fingers
  delay(100);
}

void closeFinger(int finger){
  if(finger==LITTLE){servoLittleFinger.write(0);} // Little finger 
  else if(finger==RING){servoRingFinger.write(0);}// Ring finger
  else if(finger==MIDDLE){servoMiddleFinger.write(0);}// Middle finger
  else if(finger==INDEX){servoIndexFinger.write(0);}// Index finger
  else if(finger==THUMB){servoThumbFinger.write(0);}//Thumb finger
  delay(100);
}

void setup(){
  
  Serial.begin(115200); //BAUDRATE set to 115200, remember it to set monitor serial properly (used this BaudRate and "NL&CR" option to visualize the values correctly)

  servoLittleFinger.attach(LITTLEPIN);  // Set Little finger servo to digital pin 3
  servoRingFinger.attach(RINGPIN);  // Set Ring finger servo to digital pin 5
  servoMiddleFinger.attach(MIDDLEPIN);  // Set Middle finger servo to digital pin 6
  servoIndexFinger.attach(INDEXPIN);  // Set Index finger servo to digital pin 9
  servoThumbFinger.attach(THUMBPIN);  // Set Thumb finger servo to digital pin 10

}//end setup

void loop() {// Nothing to do here, all is done in the interrupt function

  int value = analogRead(EMGPIN0); //Sampling analog signal
  /*
  int value1 = analogRead(EMGPIN1); //Sampling analog signal
  int value2 = analogRead(EMGPIN2); //Sampling analog signal
*/
  if(value>THRESHOLD||value1>THRESHOLD||value2>THRESHOLD) //If the value of the sample is greater than THRESHOLD means that the hand has been closed
  {closehand();}
  else //Otherwise the hand is open
  {openhand();}
  Serial.println(value); //You can use serial monitor to set THRESHOLD properly, comparing the values shown when you open and close your hand
  /* Add in to measure multiple signals
  Serial.println(value1);
  Serial.println(value2);
  */
}