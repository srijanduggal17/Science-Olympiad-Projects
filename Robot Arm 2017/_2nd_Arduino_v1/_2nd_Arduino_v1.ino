#include <Servo.h>
Servo flip;
Servo cap1;
Servo cap2;


int flipDown = 4;
int flipUp = 2;
int cap1Pot = A3;
int cap2Pot = A4;

int flipPin = 9;
int cap1Pin = 11;
int cap2Pin = 6;


void setup() {
  flip.attach(flipPin);
  cap1.attach(cap1Pin);
  cap2.attach(cap2Pin);

  flip.write(0);
  cap1.write(90);
  cap2.write(90);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(flipDown) == HIGH) {
    flip.write(0);
    Serial.println("flipDown");
  }

  if (digitalRead(flipUp) == HIGH) {
    flip.write(180);
    Serial.println("flipUp");
  }


  int cap1Val = map(analogRead(cap1Pot),0,1023,0,180);
  int cap2Val = map(analogRead(cap2Pot),0,1023,0,180);

  Serial.println(cap1Val);
  Serial.println(cap2Val);

  cap1.write(cap1Val);
  cap2.write(cap2Val);
}
