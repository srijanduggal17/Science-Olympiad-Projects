//radio
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(9, 10);
long message = 0;

 
void setup() 
{ 
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (7, INPUT);
  Serial.begin (115200);
  
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(pipe);
  
  radio.stopListening();
} 
 
 
void loop() 
{ 
  int emergency = digitalRead(7);

  int delaytime = map (analogRead(A0),0,1023,0,10230);
  Serial.print ("Delay:\t");
  Serial.print (delaytime);

  int throttle = map (analogRead(A1),0,1023,0,255);
  Serial.print ("  Speed:\t");
  Serial.print (throttle);

  message = delaytime*1000L + throttle;
  
  if (emergency == HIGH) {
    message = 10240256;
  }
  
  radio.write(&message, sizeof(message));
  Serial.print ("  Message:\t");
  Serial.println (message);
  
  
} 
