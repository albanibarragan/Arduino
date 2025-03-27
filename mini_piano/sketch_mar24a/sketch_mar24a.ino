int buttonDo = 2;
int buttonRe = 3;
int buttonMi = 4;
int buttonFa = 5;
int buttonSol = 6;
int buttonLa = 7;
int buttonSi = 8;
// Buzzer
int buzzerPin = 9;

//potenciometro
int potPin = A0;

void setup() {
  pinMode(buttonDo, INPUT_PULLUP);
  pinMode(buttonRe, INPUT_PULLUP);
  pinMode(buttonMi, INPUT_PULLUP);
  pinMode(buttonFa, INPUT_PULLUP);
  pinMode(buttonSol, INPUT_PULLUP);
  pinMode(buttonLa, INPUT_PULLUP);
  pinMode(buttonSi, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);  // Valor entre 0 y 1023
  Serial.println(potValue);           
  float escala = 1.0;
  
   // Selector de octava basado en el potenciómetro
  if (potValue < 341) {
    escala = 0.5;  // Octava baja
  } else if (potValue < 682) {
    escala = 1.0;  // Octava media
  } else {
    escala = 2.0;  // Octava alta
  }

  if (digitalRead(buttonDo) == LOW) {
    tone(buzzerPin, 262 * escala );
  } else if (digitalRead(buttonRe) == LOW) {
    tone(buzzerPin, 294 * escala);
  } else if (digitalRead(buttonMi) == LOW) {
    tone(buzzerPin, 330 * escala);
  } else if (digitalRead(buttonFa) == LOW) {
    tone(buzzerPin, 349 * escala);
  } else if (digitalRead(buttonSol) == LOW) {
    tone(buzzerPin, 392 * escala);
  } else if (digitalRead(buttonLa) == LOW) {
    tone(buzzerPin, 440 * escala);
  } else if (digitalRead(buttonSi) == LOW) {
    tone(buzzerPin, 494 * escala);
  } else {
    noTone(buzzerPin);
  }
}