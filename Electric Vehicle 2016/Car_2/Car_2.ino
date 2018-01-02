unsigned long delaytime = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (11, OUTPUT);
  pinMode (13, INPUT);
  pinMode (12, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
    // put your main code here, to run repeatedly:
  int reads = analogRead(A1);

  //Serial.println(reads);

  //delaytime = reads *100L;
  //map (reads,0,1023,0,204600);
  
  
  //Serial.print ("Delay:\t");
  //Serial.println (delaytime);
 

  if (digitalRead(13) == HIGH) {
    digitalWrite(12,HIGH);
    delay(200);
    digitalWrite(12,LOW);
    delay(200);
    digitalWrite(12,HIGH);
    delay(200);
    digitalWrite(12,LOW);
    digitalWrite (11,255);
    delay (delaytime); //Enter the delay value from the regression. Put the distance they give you into the equation and then solve for delay.
    endProgram ();
  }
}

void endProgram (){
  while (true){
  analogWrite (11,0);
  digitalWrite (12, HIGH);
  }
}

