#include <Servo.h>

Servo servoPinky;         // Define servo digits
Servo servoRing;         // Define servo digits
Servo servoMiddle;         // Define servo digits
Servo servoIndex;         // Define servo digits
Servo servoThumb;         // Define servo digits
Servo servoWrist;

void setup() {
  Serial.begin(9600);
  Serial.println("Servo test");

  
  //yield();
}

void loop() {
       servoPinky.write(170);
      delay(50);
       servoPinky.write(0);
      delay(50);
      //Ring Finger
       servoRing.write(170);
      delay(50);
       servoRing.write(0);
      delay(50);
      //Middle FInger
        servoMiddle.write(170);
      delay(50);
        servoMiddle.write(0);
      delay(50);
      //Index Finger
        servoIndex.write(170);
      delay(50);
        servoIndex.write(0);
      delay(50);
      //Thumb 
        servoThumb.write(170);
      delay(50);
        servoThumb.write(0);
      //Wrist
      delay(50);
        servoWrist.write(170);
      delay(50);
        servoWrist.write(170);
}
