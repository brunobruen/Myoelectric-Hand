#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// Watch video V1 to understand the two lines below: http://youtu.be/y8X9X10Tn1k
#define SERVOMIN  50 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  330 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}

// the code inside loop() has been updated by Robojax
void loop() {

    for(int angle =0; angle<181; angle +=10){
      delay(50);
        pwm.setPWM(1, 0, angleToPulse(angle));
      delay(50);
        pwm.setPWM(2, 0, angleToPulse(angle));
      delay(50);
        pwm.setPWM(3, 0, angleToPulse(angle));
      delay(50);
        pwm.setPWM(4, 0, angleToPulse(angle));
      delay(50);
          pwm.setPWM(5, 0, angleToPulse(angle));
      delay(50);
          pwm.setPWM(6, 0, angleToPulse(angle));
    }
    
    /*
    for(int angle=0;angle<=180;angle+=1){
      pwm.setPWM(2, 0, angleToPulse(angle));
      delay(10);
    }
    for(int angle=180;angle>0;angle-=1){
      pwm.setPWM(2, 0, angleToPulse(angle));
      delay(10);
    }
    */
    
  // robojax PCA9865 16 channel Servo control
 // delay(1000);// wait for 1 second
 
}

int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}