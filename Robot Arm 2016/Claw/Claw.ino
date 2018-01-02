#include <Servo.h>
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(101);
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:

 int potRead = analogRead(A0);
 Serial.print(potRead);
 Serial.print("\t");
 int maps = map(potRead,0,1023,0,180);
 Serial.println(maps);
 myservo.write(maps);
 
}
