#include <Ticker.h>
const int signalA_LED=15;
const int signalB_LED=21;
const int input_V = 19;
int pot_val=0;
float v_values[4];
float total=0;
float filtered_val=0;
const int input_button = 23;
int input_button_state = 0;
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
  }
  if (counter%1000==0){
    task3();
  }
  if(counter%42==0){
    task4();
    task5();
  }
  if (counter%5000==0){
    task9();
  }
}


void task2(){
  input_button_state= digitalRead(input_button);
  //if (input_button_state = HIGH){]
  //Serial.print(input_button_state);
}
void task3(){
  
}
void task4(){
  pot_val = digitalRead(input_V);
  //Serial.print(pot_val);
}
void task5(){
  filtered_val=0;
  for(int i=0;i<4;i++){
    v_values[i]=pot_val;
  }
  for(int j=0;j<4;j++){
    total +=v_values[j];
  }
  filtered_val=(total/4);  
}
void task6(){
  for (int j=0;j<1000;j++){
    __asm__ __volatile__ ("nop");
  }
  
}
void task9(){
  int first = input_button_state;
  String second = "hi";
  Serial.println(first );
  Serial.println(second);
  Serial.println(total);
  
}
