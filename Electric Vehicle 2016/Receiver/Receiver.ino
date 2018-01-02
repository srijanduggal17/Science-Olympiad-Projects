int motorPin = 3;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN 9
#define CSN_PIN 10 // NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe</p><p>/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio</p><p>/*-----( Declare Variables )-----*/
const uint8_t x = 0; // 2 element array holding Joystick readings</p><p>
int t = 1;
long base = 0;

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();;
  pinMode(motorPin, OUTPUT);

}



void loop() {
  
    if (radio.available()){
      // Dump the payloads until we've gotten everything
      unsigned long got_time;
      bool done = false;

      // Fetch the payload, and see if this was the last one.
      done = radio.read( &got_time, sizeof(unsigned long) );

      base = got_time;
      // Serial.print(base);
      
     
      delay(20);

    }
     Serial.print("Base:\t");
      Serial.println(base);

    if (base < 256)
      {
        analogWrite(motorPin, (int)base);
      }

    else
      {
        analogWrite(motorPin, 0);
      }
     
}

