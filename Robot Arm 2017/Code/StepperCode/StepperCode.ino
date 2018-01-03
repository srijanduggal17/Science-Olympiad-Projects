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

//Declare pin functions on Redboard
#define stp 52
#define dir 53
#define MS1 50
#define MS2 51
#define EN  48


int but1 = 40;
int but2 = 41;

int delaying = 10;

//Declare variables for functions
int x;

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

  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);

  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(EN, LOW);
 
}

void loop() {
  spool.write(90);
  while(digitalRead(baseL)==HIGH){
    base->step(40, FORWARD, DOUBLE);
    Serial.println("forward");
  }

  while(digitalRead(baseR)==HIGH) {
    base->step(40, BACKWARD, DOUBLE);
    Serial.println("backward 2");
  }

  while(digitalRead(vertL)==HIGH){
    vertical->step(10, FORWARD, SINGLE);
    spool.write(91);
  }

  while(digitalRead(vertR)==HIGH) {
    vertical->step(10, BACKWARD, SINGLE);
    spool.write(87);
  }




  /*if(Serial.available()) {

      delaying = Serial.parseInt();

      Serial.println(delaying);
    
   }*/
  
  if(digitalRead(but2) == 1) {
       digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
    for(x= 1; x<10; x++)  //Loop the forward stepping enough times for motion to be visible
    {
      digitalWrite(stp,HIGH); //Trigger one step forward
      delay(delaying);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(delaying);
    }

  }
  if(digitalRead(but1) == 1) {
       digitalWrite(dir, HIGH); //Pull direction pin low to move "forward"
    for(x= 1; x<10; x++)  //Loop the forward stepping enough times for motion to be visible
    {
      digitalWrite(stp,HIGH); //Trigger one step forward
      delay(delaying);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(delaying);
    }

  }
  
    

}
