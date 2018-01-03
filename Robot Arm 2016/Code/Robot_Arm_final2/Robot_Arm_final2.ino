
#define pin1  13 //8  //these are the Arduino pins that we use to activate coils 1-4 of the stepper motor
#define pin2  12 //6
#define pin3  10 //5 
#define pin4  8 //11

#define pin5  7 //13  //these are the Arduino pins that we use to activate coils 1-4 of the stepper motor
#define pin6  5 //10
#define pin7  3 //9
#define pin8  2 //3

#define delaytime 8   //delay time in ms to control the stepper motor delaytime.
                      //Our tests showed that 8 is about the fastest that can yield reliable operation w/o missing steps
                   
int Lclaw = 50;
int Rclaw = 42;
int Lpivot = 34;
int Rpivot = 26;


int Lclawled = 47;
int Rclawled = 39;
int Lpivotled = 31;
int Rpivotled = 23;



void setup() {
  // initialize the 8 pin as an output:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT); 
  pinMode(pin3, OUTPUT); 
  pinMode(pin4, OUTPUT);

  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT); 
  pinMode(pin7, OUTPUT); 
  pinMode(pin8, OUTPUT);
  
 Serial.begin(9600);

  pinMode(Lclaw,INPUT);
  pinMode(Rclaw,INPUT);
  pinMode(Lpivot,INPUT);
  pinMode(Rpivot,INPUT);

  pinMode(Lclawled,OUTPUT);
  pinMode(Rclawled,OUTPUT);
  pinMode(Lpivotled,OUTPUT);
  pinMode(Rpivotled,OUTPUT);
 
}

void loop(){
  
 if (digitalRead(Lclaw)==HIGH) {
  forward(10);
  step_OFF();
  Serial.println ("L");
  digitalWrite(Lclawled,HIGH);
  delay(500);
  digitalWrite(Lclawled,LOW);
 }

 if (digitalRead(Rclaw)==HIGH) {
  backward(10);
  step_OFF();
  Serial.println ("R");
  digitalWrite(Rclawled,HIGH);
  delay(500);
  digitalWrite(Rclawled,LOW);
 }

 if (digitalRead(Lpivot)==HIGH){
  forward1(10);
  step_OFF1();
  Serial.println("L1");
  digitalWrite(Lpivotled,HIGH);
  delay(500);
  digitalWrite(Lpivotled,LOW);
  
 }

 if (digitalRead(Rpivot)==HIGH) {
  backward1(10);
  step_OFF1();
  Serial.println("R1");
  digitalWrite(Rpivotled,HIGH);
  delay(500);
  digitalWrite(Rpivotled,LOW);
 }
  

  
}
