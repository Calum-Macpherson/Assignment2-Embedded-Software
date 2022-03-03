
#include <Ticker.h>
const int signalA_LED=15;
const int signalB_LED=21;
const int input_button = 23;
boolean input_button_state = 0;
const int no_of_tasks = 8;
int counter =0;

Ticker myTick;

void setup() {
  Serial.begin(9600);
  pinMode(signalA_LED, OUTPUT); 
  pinMode(signalB_LED, OUTPUT);
  pinMode(input_button, INPUT);
  myTick.attach_ms(1,myCycle);
}
void loop(){
  
}

void myCycle(){ 
  counter++;
  digitalWrite(signalB_LED, HIGH);
  delayMicroseconds(50);
  digitalWrite(signalB_LED,LOW);
  if (counter%200==0){ 
    task2();
    Serial.print(input_button_state);
  }

}


void task2(){
  input_button_state= digitalRead(input_button);
  //if (input_button_state = HIGH){]
   
}


 
