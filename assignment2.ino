const int signalA_LED=15;
const int signalB_LED=21;


void setup() {
  pinMode(signalA_LED, OUTPUT); 
  pinMode(signalB_LED, OUTPUT);

}

void loop() {

  digitalWrite(signalB_LED, HIGH);
  delayMicroseconds(50);
  digitalWrite(signalB_LED,LOW);
}
