
#define pin1  8//these are the Arduino pins that we use to activate coils 1-4 of the stepper motor
#define pin2  9
#define pin3  10
#define pin4  11

#define delaytime 8   //delay time in ms to control the stepper motor delaytime.
                      //Our tests showed that 8 is about the fastest that can yield reliable operation w/o missing steps
                   
int previous;

#include <Servo.h>
Servo myservo;


void setup() {
  // initialize the 8 pin as an output:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT); 
  pinMode(pin3, OUTPUT); 
  pinMode(pin4, OUTPUT);
  
  previous = map(analogRead(A1),0,1023,0,510);
  Serial.begin(9600);
  myservo.attach(5);
  myservo.write(101);
  delay(1000);
  
}

void loop(){

  int claw = analogRead(A0);
 //Serial.print(claw);
 //Serial.print("\t");
 int maps = map(claw,0,1023,0,180);
 //Serial.println(maps);
 myservo.write(maps);
  
  int val = map(analogRead(A1),0,1023,0,510);
  int steps = val - previous;
  int pivot1 = analogRead(A1);
  //Serial.println(pivot1);
 

  step_OFF();         //turning all coils off

  while(steps>0) {
    forward();
    steps--;
    //Serial.print("Forward:\t");
    //Serial.println(steps);
  }
  
  
  while(steps<0){
    backward();       //going backward
    steps++;
    //Serial.println("Backward");
  }

  previous = val;
 
}
