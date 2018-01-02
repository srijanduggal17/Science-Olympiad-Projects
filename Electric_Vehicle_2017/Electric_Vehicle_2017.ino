//Enter delaytime below

int delaytime = 7000;


void setup() {
  // put your setup code here, to run once:
  pinMode (11, OUTPUT);
  pinMode (13, INPUT);
  pinMode (12, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  Serial.print ("Delay:\t");
  Serial.println (delaytime);
 

  if (digitalRead(13) == HIGH) {
    Serial.print ("Pushed");
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

