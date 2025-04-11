int buzzerPin = 9;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  
  // Reproducir la canción una vez al iniciar
  tocarEstrellita();
}

void loop() {
  // No se hace nada más
}

// ============================
// 🎵 Canción: Estrellita ⭐
// Notas: 1 1 5 5 6 6 5 ...
// ============================

void tocarEstrellita() {
  int duracion = 400; // Duración base por nota (ms)

  tocarNota(262, duracion);  // 1 - Do
  tocarNota(262, duracion);  // 1 - Do
  tocarNota(392, duracion);  // 5 - Sol
  tocarNota(392, duracion);  // 5 - Sol
  tocarNota(440, duracion);  // 6 - La
  tocarNota(440, duracion);  // 6 - La
  tocarNota(392, duracion * 2);  // 5 - Sol

  tocarNota(349, duracion);  // 4 - Fa
  tocarNota(349, duracion);  // 4 - Fa
  tocarNota(330, duracion);  // 3 - Mi
  tocarNota(330, duracion);  // 3 - Mi
  tocarNota(294, duracion);  // 2 - Re
  tocarNota(294, duracion);  // 2 - Re
  tocarNota(262, duracion * 2);  // 1 - Do

  tocarNota(392, duracion);  // 5 - Sol
  tocarNota(392, duracion);  // 5 - Sol
  tocarNota(349, duracion);  // 4 - Fa
  tocarNota(349, duracion);  // 4 - Fa
  tocarNota(330, duracion);  // 3 - Mi
  tocarNota(330, duracion);  // 3 - Mi
  tocarNota(294, duracion * 2);  // 2 - Re

  tocarNota(392, duracion);  // 5 - Sol
  tocarNota(392, duracion);  // 5 - Sol
  tocarNota(349, duracion);  // 4 - Fa
  tocarNota(349, duracion);  // 4 - Fa
  tocarNota(330, duracion);  // 3 - Mi
  tocarNota(330, duracion);  // 3 - Mi
  tocarNota(294, duracion * 2);  // 2 - Re

  tocarNota(262, duracion);  // 1 - Do
  tocarNota(262, duracion);  // 1 - Do
  tocarNota(392, duracion);  // 5 - Sol
  tocarNota(392, duracion);  // 5 - Sol
  tocarNota(440, duracion);  // 6 - La
  tocarNota(440, duracion);  // 6 - La
  tocarNota(392, duracion * 2);  // 5 - Sol

  tocarNota(349, duracion);  // 4 - Fa
  tocarNota(349, duracion);  // 4 - Fa
  tocarNota(330, duracion);  // 3 - Mi
  tocarNota(330, duracion);  // 3 - Mi
  tocarNota(294, duracion);  // 2 - Re
  tocarNota(294, duracion);  // 2 - Re
  tocarNota(262, duracion * 2);  // 1 - Do
}

// 🎶 Función para tocar una nota con pausa
void tocarNota(int frecuencia, int duracion) {
  tone(buzzerPin, frecuencia);
  delay(duracion);
  noTone(buzzerPin);
  delay(100);  // Pequeña pausa entre notas
}
