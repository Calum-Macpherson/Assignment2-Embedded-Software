#include <Ticker.h>
//Below I have intitialised the global variables used throughout the code
const int signalA_LED=15;
const int signalB_LED=21;
const int signal_check =16;
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

Ticker myTick; // Initialises the ticker

void setup() {
  Serial.begin(9600);
  pinMode(signalA_LED, OUTPUT); 
  pinMode(signalB_LED, OUTPUT);
  pinMode(signal_check, OUTPUT);
  pinMode(input_button, INPUT);
  pinMode(input_V,INPUT);
  pinMode(inputV_task3,INPUT);
  myTick.attach_ms(4,myCycle);//Ticker set up to "tick"  every 4ms to accomodate for a worse case scenario
}
void loop(){
  
}

void myCycle(){ 
  counter++;//increments the counter each time the cycle is ran
  digitalWrite(signalB_LED, HIGH);
  delayMicroseconds(50);
  digitalWrite(signalB_LED,LOW);
  /*
  The counter values below have been calculated by dividing the
  original periods by 4, since the ticker "ticks" every 4ms.
  */
  
  if (counter%50==0){ 
    task2();
  }
  if (counter%250==0){
    //digitalWrite(signal_check,HIGH);
    task3();
    //digitalWrite(signal_check,LOW);
  }
  if(counter%11==0){
    //digitalWrite(signal_check,HIGH);
    task4();
    //digitalWrite(signal_check,LOW);
  }
  if(counter%11==1){
    task5();
  }
  if (counter%25==0){
    task6();
  }
  if (counter%75==0){
    task7();
  }
  if (counter%75==1){
    task8();
  }
  if (counter%1250==0){
    task9();
  }
}


void task2(){
  input_button_state= digitalRead(input_button);
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
  Serial.print (",  ");
  Serial.print(freq);
  Serial.print (",  ");
  Serial.println(filtered_val);
  
}
