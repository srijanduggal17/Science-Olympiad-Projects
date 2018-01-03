#include <Wire.h>
#include <Adafruit_MotorShield.h>


// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);

int previous;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  myMotor->setSpeed(10);  // 10 rpm   
  previous = map(analogRead(0),0,1023,0,200);
}


void loop() 
{
  // get the sensor value

 
  int val = map(analogRead(0),0,1023,0,200);

  // move a number of steps equal to the change in the
  // sensor reading
  int steps = val - previous;

  Serial.println(steps);
  if (steps > 0)
  {
     myMotor->step(steps, FORWARD, SINGLE);
  }
  else if (steps < 0)
  {
     myMotor->step(-steps, BACKWARD, SINGLE);
  }

  // remember the previous value of the sensor
  previous = val;
}
