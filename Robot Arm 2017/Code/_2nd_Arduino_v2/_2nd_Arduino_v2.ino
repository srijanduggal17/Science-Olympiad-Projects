#include <Servo.h>
Servo rotate;

int rotateRight = 4;
int rotateLeft = 2;

int rotatePin = 9;

int rotateVal = 0;


void setup() {
  rotate.attach(rotatePin);
  rotate.write(rotateVal);

  Serial.begin(9600);
}

void loop() {
  while (digitalRead(rotateRight) == HIGH) {
    rotateVal = rotateVal + 2;
    if (rotateVal < 181) {
      rotate.write(rotateVal);
    }
    Serial.print("Rotate Right: ");
    Serial.println(rotateVal);
  }

  while (digitalRead(rotateLeft) == HIGH) {
    rotateVal = rotateVal - 2;
    if (rotateVal > 0) {
      rotate.write(rotateVal);
    }
    Serial.print("Rotate Left: ");
    Serial.println(rotateVal);
  }
}
