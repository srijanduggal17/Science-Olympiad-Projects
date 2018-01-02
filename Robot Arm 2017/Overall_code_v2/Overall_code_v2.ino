#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *base = AFMS.getStepper(200, 1);
Adafruit_StepperMotor *band = AFMS.getStepper(200, 2);


#include <Servo.h>
Servo spool;
int baseL = 2;
int baseR = 3;
int bandF = 6;
int bandB = 7;
int vertU = 10;
int vertD = 11;

//Declare pin functions on Easydriver
#define stp 52
#define dir 53
#define MS1 50
#define MS2 51
#define EN  48

int delaying = 5;



//Declare variables for functions
int x;

void setup() {
  pinMode(baseL,INPUT);
  pinMode(baseR,INPUT);
  pinMode(bandF,INPUT);
  pinMode(bandB,INPUT);
  pinMode(vertU,INPUT);
  pinMode(vertD,INPUT);
  Serial.begin(9600);           // set up Serial library at 9600 bps
  
  AFMS.begin();  // create with the default frequency 1.6KHz
  base->setSpeed(2);  // 10 rpm   
  band->setSpeed(70);

  spool.attach(9);
  spool.write(1500);

  

  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);

  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(EN, LOW);
 
}

void loop() {
  spool.write(1500);

  
  while(digitalRead(baseL)==HIGH){
    base->step(1, BACKWARD, MICROSTEP);
    Serial.println("forward");
  }

  while(digitalRead(baseR)==HIGH) {
    base->step(1, FORWARD, MICROSTEP);
    Serial.println("backward 2");
  }

  while(digitalRead(bandF)==HIGH){
    band->step(40, FORWARD, DOUBLE);
  }

  while(digitalRead(bandB)==HIGH) {
    band->step(40, BACKWARD, DOUBLE);
  }


  
  if(digitalRead(vertU) == HIGH) {
    digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
    spool.write(1505);
    for(x= 1; x<10; x++)  //Loop the forward stepping enough times for motion to be visible
    {
      digitalWrite(stp,HIGH); //Trigger one step forward
      delay(delaying);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(delaying);
    }
    

  }
  if(digitalRead(vertD) == HIGH) {
    digitalWrite(dir, HIGH); //Pull direction pin low to move "forward"
    spool.write(1480);
    for(x = 1; x<10; x++)  //Loop the forward stepping enough times for motion to be visible
    {
      digitalWrite(stp,HIGH); //Trigger one step forward
      delay(delaying);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(delaying);
    }
    

  }
  
    

}
