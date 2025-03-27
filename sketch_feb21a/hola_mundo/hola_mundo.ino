void setup() {
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available() > 0) {
    String mensaje = Serial.readString(); 
    Serial.println("Mensaje recibido: " + mensaje);
    while(true);
  } else {
    Serial.println("Esperando datos...");
    delay(1000);
  }
}