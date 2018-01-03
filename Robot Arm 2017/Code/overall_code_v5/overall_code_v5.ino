#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *base = AFMS.getStepper(200, 1);
Adafruit_StepperMotor *band = AFMS.getStepper(200, 2);


#include <Servo.h>
Servo spool;
Servo cap;
Servo cap2;
Servo flip;

//Define input pins
int baseR = 24;
int baseL = 25;
int bandF = 26;
int bandB = 27;
int vertU = 30;
int vertD = 31;
int flipUp = 34;
int flipDown = 35;
int capPot = A0;
int cap2Pot = A1;

//Define Servo Pins
int flipServoPin = 9;
int capServoPin = 12;
int cap2ServoPin = 13;
int spoolServoPin = 10;


//Declare pin functions on Easydriver
#define stp 53
#define dir 52
#define MS1 50
#define MS2 51
#define EN  48

int delaying = 5;


//Declare variables for functions
int x;


//Define LED status pins
int statusPin1 = 41;
int statusPin2 = 40;

void setup() {
  pinMode(statusPin1,OUTPUT);
  pinMode(statusPin2,OUTPUT);

/*
  digitalWrite(statusPin1,HIGH);
  delay(200);
  digitalWrite(statusPin1,LOW);
  delay(200);
  digitalWrite(statusPin1,HIGH);
  delay(200);
  */
  //attach the servos to their pins
  spool.attach(spoolServoPin);
  flip.attach(flipServoPin);
  cap.attach(capServoPin);
  cap2.attach(cap2ServoPin);

  spool.write(1500);

  pinMode(baseL,INPUT);
  pinMode(baseR,INPUT);
  pinMode(bandF,INPUT);
  pinMode(bandB,INPUT);
  pinMode(vertU,INPUT);
  pinMode(vertD,INPUT);
  pinMode(flipUp,INPUT);
  pinMode(flipDown,INPUT);

  
  Serial.begin(9600);           // set up Serial library at 9600 bps
  
  AFMS.begin();  // create with the default frequency 1.6KHz
  base->setSpeed(2);  // 10 rpm   
  band->setSpeed(70);

  spool.write(1500);
  flip.write(0);
  

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
  //digitalWrite(statusPin1,HIGH);
  digitalWrite(statusPin2,LOW);
  spool.write(1500);
  
  while(digitalRead(baseL)==HIGH){
    base->step(1, BACKWARD, MICROSTEP);
    Serial.println("baseL On");
   digitalWrite(statusPin2,HIGH);
  }

  while(digitalRead(baseR)==HIGH) {
    base->step(1, FORWARD, MICROSTEP);
    Serial.println("baseR On");
    digitalWrite(statusPin2,HIGH);
  }

  while(digitalRead(bandF)==HIGH){
    band->step(40, FORWARD, DOUBLE);
    Serial.println("bandF On");
    digitalWrite(statusPin2,HIGH);
  }

  while(digitalRead(bandB)==HIGH) {
    band->step(40, BACKWARD, DOUBLE);
    Serial.println("bandB On");
    digitalWrite(statusPin2,HIGH);
  }


  
  if(digitalRead(vertU) == HIGH) {
    digitalWrite(statusPin2,HIGH);
    Serial.println("vertU On");
    spool.write(1510);
    digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
    for(x= 1; x<10; x++)  //Loop the forward stepping enough times for motion to be visible
    {
      digitalWrite(stp,HIGH); //Trigger one step forward
      delay(delaying);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(delaying);
    }
    

  }
  if(digitalRead(vertD) == HIGH) {
    digitalWrite(statusPin2,HIGH);
    Serial.println("vertD On");
    spool.write(1460);
    digitalWrite(dir, HIGH); //Pull direction pin low to move "forward"
    for(x = 1; x<10; x++)  //Loop the forward stepping enough times for motion to be visible
    {
      digitalWrite(stp,HIGH); //Trigger one step forward
      delay(delaying);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(delaying);
    }
    

  }

  
  //get the potentiometer values for the two flap servos
  int capVal = map(analogRead(capPot), 0, 1023, 0,180 );  
  int cap2Val = map(analogRead(cap2Pot), 0, 1023, 0, 180);

  //write these values to the servos
  cap.write(135);
  //cap.write(capVal);
  Serial.println(capVal);
  cap2.write(135);
  //cap2.write(cap2Val);
  Serial.println(cap2Val);

  //check if the flip button is pressed, but we only want to flip if the button hasn't been pressed previously 
  if(digitalRead(flipUp) == HIGH) {
    Serial.println("flipUp On");
    digitalWrite(statusPin2,HIGH);
    flip.write(0);
  }

  if(digitalRead(flipDown) == HIGH) {
    Serial.println("flipDown On");
    digitalWrite(statusPin2,HIGH);
    flip.write(180);
  }

  //delay so we don't overload the Arduino
  delay(10);
  
    

}
