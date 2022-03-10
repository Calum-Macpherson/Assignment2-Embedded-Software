#include <Ticker.h>
const int signalA_LED=15;
const int signalB_LED=21;
const int input_V = 2;
int inputV_task3=5;
unsigned  long duration;
unsigned long freq;
int pot_val=0;
float v_values[4];
float total=0;
float filtered_val=0;
const int input_button = 23;
int input_button_state = 0;
const int no_of_tasks = 8;
int counter =0;
boolean error_code=0;

Ticker myTick;

void setup() {
  Serial.begin(9600);
  pinMode(signalA_LED, OUTPUT); 
  pinMode(signalB_LED, OUTPUT);
  pinMode(input_button, INPUT);
  pinMode(input_V,INPUT);
  pinMode(inputV_task3,INPUT);
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
  if (counter%100==0){
    task6();
  }
  if (counter%300==0){
    task7();
    task8();
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
unsigned long task3(){
  duration=pulseIn(inputV_task3,HIGH);
  freq=1/(duration*2*pow(10, -6));
  //Serial.println(freq);
}
float task4(){
  pot_val = analogRead(input_V);
  return pot_val;
  //Serial.print(pot_val);
}
float task5(){
  total=0;
  for(int j=0;j<4;j++){
    v_values[j]=pot_val;
    total +=v_values[j];    
  }
  filtered_val=(total/4);  
  return total;
  return filtered_val;
  
}
void task6(){
  for (int j=0;j<1000;j++){
    __asm__ __volatile__ ("nop");
  } 
}
boolean task7(){
  if (filtered_val >(4095/2)){
    error_code = 1;
  }
  else if (filtered_val<(4095/2)){
    error_code = 0;
  }
  return error_code;
}
void task8(){
  if (error_code==1){
    digitalWrite(signalA_LED, HIGH);
  }
  else{
    digitalWrite(signalA_LED, LOW);
  }
}

void task9(){
  Serial.print(input_button_state);
  Serial.print (",    ");
  Serial.print(total);
  Serial.print (",    ");
  Serial.println(filtered_val);
  
}
