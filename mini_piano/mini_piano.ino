//declarar el pin del buzzer
int buzzPin = 4;
int buzzDelay = 5;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buzzPin, HIGH);
  delay(buzzDelay);
  digitalWrite(buzzPin, LOW);
  delay(buzzDelay);
}
