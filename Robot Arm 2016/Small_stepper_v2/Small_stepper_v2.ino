/******************************************
	PURPOSE:	Running a stepper motor with the Arduino
	Created by      Rudy Schlaf after a sketch by Sam Leong
	DATE:		1/2014
*******************************************/

#define pin1  8//these are the Arduino pins that we use to activate coils 1-4 of the stepper motor
#define pin2  9
#define pin3  10
#define pin4  11

#define delaytime 8   //delay time in ms to control the stepper motor delaytime.
                      //Our tests showed that 8 is about the fastest that can yield reliable operation w/o missing steps
                   
int previous;

void setup() {
  // initialize the 8 pin as an output:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT); 
  pinMode(pin3, OUTPUT); 
  pinMode(pin4, OUTPUT);
  previous = map(analogRead(A1),0,1023,0,510);
  Serial.begin(9600);
  
}

void loop(){
  int val = map(analogRead(A1),0,1023,0,510);
  Serial.println(val);
  if(val > previous+5) {
    
    forward(val - previous);
    previous = val;
  }
  else if (val < previous-5) {
    backward(previous - val);
    previous = val;
  }
  
  
  /*Serial.println(val);
  Serial.println(numberOfSteps);
  step_OFF();         //turning all coils off
  while(steps>0) {
    forward();
    steps --;
    Serial.print("Forward:\t");
    Serial.println(steps);
  }
  while(steps<-10){
    backward();       //going backward
    int stepps = -steps;
    //Serial.println(stepps);
    stepps -- ;//counting down the number of steps
    //Serial.println("Backward");
  }
  previous = val;
  */

}
