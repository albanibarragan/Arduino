int pin1 = 8;
int dot = 100;
int dash = 300;


void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin1, HIGH);
  delay(dot);
  digitalWrite(pin1, LOW);
  delay(dot);

  digitalWrite(pin1, HIGH);
  delay(dot);
  digitalWrite(pin1, LOW);
  delay(dot);
  
  digitalWrite(pin1, HIGH);
  delay(dash);
  digitalWrite(pin1, LOW);
  delay(dash);
  
}
