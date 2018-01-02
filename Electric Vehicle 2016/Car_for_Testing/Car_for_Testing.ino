//radio
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>/*-----( Declare Constants and Pin Numbers )-----*/
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe</p><p>/*-----( Declare objects )-----*/
RF24 radio(9, 10); // Create a Radio</p><p>/*-----( Declare Variables )-----*/
long message = 0;

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  pinMode(3, OUTPUT);
  pinMode(5,OUTPUT);

}



void loop() {
  
    if (radio.available()){
      // Dump the payloads until we've gotten everything
      unsigned long got_time;
      bool done = false;

      // Fetch the payload, and see if this was the last one.
      done = radio.read( &got_time, sizeof(unsigned long) );

      message = got_time;
          
      delay(20);

    }
    
     Serial.print ("Message:\t");
     Serial.print (message);

     int delaytime = message/1000L;
     Serial.print ("Delay:\t");
     Serial.print (delaytime);

     int throttle = message - (delaytime*1000L);
     Serial.print ("Throttle:\t");
     Serial.println (throttle);

     analogWrite (3, throttle);
     delay (delaytime);
     analogWrite (3,0);

     if (message = 10240256) {
      analogWrite (3,0);
      endProgram();
     }
}

void endProgram () {
  while (true){
    digitalWrite (4,HIGH);
  }
}

