#include <Servo.h>

#define THRESHOLD 300 //In order to determine the state of the hand (opened/closed)
#define EMGPIN0 A0 //Analog pin connected to Muscle Sensor V3 Board
/* To add other myoware muscle sensors for more diverse movements
#define EMGPIN1 A1 //Analog pin connected to Muscle Sensor V3 Board
#define EMGPIN2 A2 //Analog pin connected to Muscle Sensor V3 Board
*/
#define PINKYPIN  3 //Digital pin used by PINKY servo
#define RINGPIN    5 //Digital pin used by Ring servo
#define MIDDLEPIN  6 //Digital pin used by Middle servo
#define INDEXPIN   9 //Digital pin used by Index servo
#define THUMBPIN  10 //Digital pin used by Thumb servo

//Constants used to open and close the digits
#define PINKY 1 
#define RING   2
#define MIDDLE 3
#define INDEX  4
#define THUMB  5

Servo servoPinky;         // Define servo digits
Servo servoRing;         // Define servo digits
Servo servoMiddle;         // Define servo digits
Servo servoIndex;         // Define servo digits
Servo servoThumb;         // Define servo digits
//Servo servoWrist;

int digit;

// Motion routines for handopen and handclose
void openhand(){for(digit = 1; digit < 6; digit++){opendigit(digit);}}
void closehand(){for(digit = 1; digit < 6 ; digit++){closedigit(digit);}}

void opendigit(int digit){
  if(digit==PINKY){servoPinky.write(170);} // PINKY digit
  else if(digit==RING){servoRing.write(170);}// Ring digit
  else if(digit==MIDDLE){servoMiddle.write(170);}// Middle digits
  else if(digit==INDEX){servoIndex.write(170);}// Index digit
  else if(digit==THUMB){servoThumb.write(170);}//Thumb digits
  delay(100);
}
void closedigit(int digit){
  if(digit==PINKY){servoPinky.write(0);} // PINKY digit
  else if(digit==RING){servoRing.write(0);}// Ring digit
  else if(digit==MIDDLE){servoMiddle.write(0);}// Middle digits
  else if(digit==INDEX){servoIndex.write(0);}// Index digit
  else if(digit==THUMB){servoThumb.write(0);}//Thumb digits
  delay(100);
}
void setup(){
  
  Serial.begin(115200); //BAUDRATE set to 115200, remember it to set monitor serial properly (used this BaudRate and "NL&CR" option to visualize the values correctly)

  servoPinky.attach(PINKYPIN);  // Set PINKY digit servo to digital pin 3
  servoRing.attach(RINGPIN);  // Set Ring digit servo to digital pin 5
  servoMiddle.attach(MIDDLEPIN);  // Set Middle digit servo to digital pin 6
  servoIndex.attach(INDEXPIN);  // Set Index digit servo to digital pin 9
  servoThumb.attach(THUMBPIN);  // Set Thumb digit servo to digital pin 10

}//end setup

void loop() {// Nothing to do here, all is done in the interrupt function

  int value = analogRead(EMGPIN0); //Sampling analog signal
  if(value>THRESHOLD) //If the value of the sample is greater than THRESHOLD means that the hand has been closed
  {closehand();}
  else //Otherwise the hand is open
  {openhand();}
  Serial.println(value); //You can use serial monitor to set THRESHOLD properly, comparing the values shown when you open and close your hand
  
  /* Add in to measure multiple signals
  int value1 = analogRead(EMGPIN1); //Sampling analog signal
  int value2 = analogRead(EMGPIN2); //Sampling analog signal
  if(value>THRESHOLD||value1>THRESHOLD||value2>THRESHOLD) 
  {closehand();}
  else //Otherwise the hand is open
  {openhand();}
  Serial.println(value);
  Serial.println(value1);
  Serial.println(value2);
  */
}