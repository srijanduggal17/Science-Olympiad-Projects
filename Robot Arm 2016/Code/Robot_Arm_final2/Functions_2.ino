//these functions set the pin settings for each of the four steps per rotation of the motor (keepp in mind that the motor in the kit is geared down,
//i.e. there are many steps necessary per rotation

void Step_E(){
  digitalWrite(pin5, HIGH);//turn on coil 1 
  digitalWrite(pin6, LOW); 
  digitalWrite(pin7, LOW); 
  digitalWrite(pin8, LOW); 
}
void Step_F(){
  digitalWrite(pin5, LOW); 
  digitalWrite(pin6, HIGH);//turn on coil 2
  digitalWrite(pin7, LOW); 
  digitalWrite(pin8, LOW); 
}
void Step_G(){
  digitalWrite(pin5, LOW); 
  digitalWrite(pin6, LOW); 
  digitalWrite(pin7, HIGH); //turn on coil 3
  digitalWrite(pin8, LOW); 
}
void Step_H(){
  digitalWrite(pin5, LOW); 
  digitalWrite(pin6, LOW); 
  digitalWrite(pin7, LOW); 
  digitalWrite(pin8, HIGH); //turn on coil 4
}
void step_OFF1(){
  digitalWrite(pin5, LOW); //power all coils down
  digitalWrite(pin6, LOW); 
  digitalWrite(pin7, LOW); 
  digitalWrite(pin8, LOW); 
}

//these functions run the above configurations in forward and reverse order
//the direction of a stepper motor depends on the order in which the coils are turned on.
void forward1(int numSteps){//one tooth forward
  while(numSteps > 0) {
    Step_E();
    delay(delaytime);
    Step_F();
    delay(delaytime);
    Step_G();
    delay(delaytime);
    Step_H();
    delay(delaytime);
    numSteps--;
  }
}

void backward1(int numSteps){//one tooth backward
  while(numSteps > 0) {
    Step_H();
    delay(delaytime);
    Step_G();
    delay(delaytime);
    Step_F();
    delay(delaytime);
    Step_E();
    delay(delaytime);
    numSteps--;
  }
}

