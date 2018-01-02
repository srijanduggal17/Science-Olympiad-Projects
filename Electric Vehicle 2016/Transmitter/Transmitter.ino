//potentiometers
int potPin = A3;    // select the input pin for the potentiometer

//emergency stop button
int but = 7;
//radio
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN 9  
#define CSN_PIN 10
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe</p><p>/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
long deg = 0;

void setup() {
  radio.begin();
  radio.openWritingPipe(pipe);
  Serial.begin(9600);
}

void loop() {
  int tf = analogRead(potPin);
  deg = map(tf, 0, 1023, 0, 180);

  if(digitalRead(but) == HIGH) {
    deg = 181;
  }
  //send signal to the quad
  radio.write(&deg, sizeof(deg));

  
  Serial.print("Deg:\t");
  Serial.println(deg);
  
}


