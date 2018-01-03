#include <Servo.h>
Servo rotate;
Servo rotate1;
Servo flip;

int rotateRight = 4;
int rotateLeft = 2;

int rotate1Right = 12;

int flipButton = 13;

int rotatePin = 9;
int rotate1Pin = 6;
int flipPin = 10;

int val = 0;
int hello = 0;

void setup() {
  rotate.attach(rotatePin);
  rotate1.attach(rotate1Pin);
  flip.attach(flipPin);
  rotate.write(0);
  rotate1.write(0);
  flip.write(0);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(rotateRight) == HIGH) {
    rotate.write(0);
    Serial.println("Rotate Right: ");
  }

  if (digitalRead(rotateLeft) == HIGH) {
    rotate.write(180);
    Serial.println("Rotate Left: ");
  }

  if (digitalRead(rotate1Right) == HIGH && val == 0) {
    rotate1.write(0);
    val = 1;
    Serial.println(val);
    delay(600);
    flip.write(180);
  }

  if (digitalRead(rotate1Right) == HIGH && val == 1) {
    rotate1.write(180);
    val = 0;
    Serial.println("bye");
    delay(600);
  }

}
  /*if (digitalRead(rotate1Left) == HIGH) {
    rotate1.write(180);
    Serial.println("Rotate 1 Left: "); 
