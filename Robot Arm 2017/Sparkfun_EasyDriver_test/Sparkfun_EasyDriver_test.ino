//Declare pin functions on Redboard
#define stp 4
#define dir 7
#define MS1 50
#define MS2 51
#define EN  48

int delaying = 1;

//Declare variables for functions
String user_input;
int x;
int y;
int state;

void setup() {
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  Serial.begin(9600); //Open Serial connection for debugging
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  
}


void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(but2));
  //Serial.println(digitalRead(but1));

  /*if(Serial.available()) {

      int xy = Serial.read();
      delaying = xy;
      Serial.println(delaying);
    
   }*/
         digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
    for(x= 1; x<1600; x++)  //Loop the forward stepping enough times for motion to be visible
    {
      digitalWrite(stp,HIGH); //Trigger one step forward
      delay(delaying);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(delaying);
    }

       digitalWrite(dir, HIGH); //Pull direction pin low to move "forward"
    for(x= 1; x<1600; x++)  //Loop the forward stepping enough times for motion to be visible
    {
      digitalWrite(stp,HIGH); //Trigger one step forward
      delay(delaying);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(delaying);
    }

  
   

  
}

