#define BUZZER 9  // Pin del buzzer

int botones[] = {2, 3, 4, 5};  // Pines de los botones
int notas[] = {262, 294, 330, 392};  // Frecuencias (Do, Re, Mi, Sol)

void setup() {
  pinMode(BUZZER, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(botones[i], INPUT_PULLUP); // Configurar botones con resistencia interna
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    if (digitalRead(botones[i]) == LOW) {  // Si se presiona el botón
      tone(BUZZER, notas[i]);  // Toca la nota correspondiente
      delay(300);  // Pequeña pausa
      noTone(BUZZER);  // Apaga el sonido
    }
  }
}


