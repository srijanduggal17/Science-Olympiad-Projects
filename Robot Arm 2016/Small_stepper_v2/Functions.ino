//these functions set the pin settings for each of the four steps per rotation of the motor (keepp in mind that the motor in the kit is geared down,
//i.e. there are many steps necessary per rotation

void Step_A(){
  digitalWrite(pin1, HIGH);//turn on coil 1 
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, LOW); 
}
void Step_B(){
  digitalWrite(pin1, LOW); 
  digitalWrite(pin2, HIGH);//turn on coil 2
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, LOW); 
}
void Step_C(){
  digitalWrite(pin1, LOW); 
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, HIGH); //turn on coil 3
  digitalWrite(pin4, LOW); 
}
void Step_D(){
  digitalWrite(pin1, LOW); 
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, HIGH); //turn on coil 4
}
void step_OFF(){
  digitalWrite(pin1, LOW); //power all coils down
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, LOW); 
}

//these functions run the above configurations in forward and reverse order
//the direction of a stepper motor depends on the order in which the coils are turned on.
void forward(int numSteps){//one tooth forward
  while(numSteps > 0) {
    Step_A();
    delay(delaytime);
    Step_B();
    delay(delaytime);
    Step_C();
    delay(delaytime);
    Step_D();
    delay(delaytime);
    numSteps--;
 }
}

void backward(int numSteps){//one tooth backward
  while(numSteps > 0) {
    Step_D();
    delay(delaytime);
    Step_C();
    delay(delaytime);
    Step_B();
    delay(delaytime);
    Step_A();
    delay(delaytime);
    numSteps--;
  }
}

