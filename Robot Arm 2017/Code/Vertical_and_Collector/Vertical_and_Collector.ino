#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *base = AFMS.getStepper(200, 1);
Adafruit_StepperMotor *vertical = AFMS.getStepper(200, 2);


#include <Servo.h>
Servo spool;
int baseL = 6;
int baseR = 7;
int vertL = 11;
int vertR = 12;
Servo collector1;
int pot1 = A0;

void setup() {
  pinMode(baseL,INPUT);
  pinMode(baseR,INPUT);
  pinMode(vertL,INPUT);
  pinMode(vertR,INPUT);
  Serial.begin(9600);           // set up Serial library at 9600 bps
  
  AFMS.begin();  // create with the default frequency 1.6KHz
  base->setSpeed(10);  // 10 rpm   
  vertical->setSpeed(70);

  spool.attach(9);
  spool.write(90);
  collector1.attach(10);
}

void loop() {
  spool.write(90);
  if(digitalRead(baseL)==HIGH){
    base->step(10, FORWARD, SINGLE);
  }

  if(digitalRead(baseR)==HIGH) {
    base->step(10, BACKWARD, SINGLE);
  }

  while(digitalRead(vertL)==HIGH){
    vertical->step(10, FORWARD, SINGLE);
    spool.write(91);
  }

  while(digitalRead(vertR)==HIGH) {
    vertical->step(10, BACKWARD, SINGLE);
    spool.write(87);
  }

  collector1.write(180);
  int collectorknob1 = map(analogRead(pot1),0,1023,0,180);
 // collector1.write(collectorknob1);  
  

}
