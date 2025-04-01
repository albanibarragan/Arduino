#include <Servo.h>
#include <Keypad.h>

// C++ code


//Teclado
const int FILAS = 4;
const int COLUMNAS = 4;

char keys[FILAS][COLUMNAS]= {
  {'1', '2', '3','A'},
  {'4', '5', '6','B'},
  {'7', '8', '9','C'},
  {'*', '0', '#','D'}
};

// Pines conectados asociados a las Filas y Columnas
byte rowPins[]= {9,8,7,6};
byte columnPins[] = {5,4,3,2} ;

Keypad keypad = Keypad(makeKeymap(keys),rowPins ,columnPins,FILAS,COLUMNAS);

//Leds
int ledVerde = 12;
int ledRojo = 13;

//Servo 
int servoPin = 10;
Servo myServo;

//contraseña 
char password[5];
char newPassword[5];
char passwordGuardada[] = "1234"; //guardada por defecto
int indice = 0;

//cambiar contraseña
bool modoCambioClave = false;

void setup()
{
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(0);
  Serial.begin(9600);  
  Serial.println("Presiona una tecla...");
}

void loop()
{
  char key = keypad.getKey(); 
  if (!key) return;
  
  //Opcion de cambiar la contraseña
  
  if (key == '#' && !modoCambioClave) {
    modoCambioClave = true;
    indice = 0;
    Serial.println("Modo cambio de clave activado. Ingresa nueva clave:");
    delay(300);
    return;  // Salir para esperar próxima tecla
  }
  
   if (modoCambioClave) {
    if (key != '#') { 
      newPassword[indice] = key;
      Serial.print("Digita nueva clave: ");
      Serial.println(key);
      indice++;

      if (indice == 4) {
        newPassword[4] = '\0';
        Serial.print("Nueva clave guardada: ");
        Serial.println(newPassword);
        strcpy(passwordGuardada, newPassword);
        modoCambioClave = false;
        indice = 0;
        Serial.println("Ingresa clave para acceso:");
        delay(500);
      }
    }
    return;  
  }
    
  if (key && indice < 4) {
    Serial.print("Tecla presionada: ");
    Serial.println(key);
    password[indice] = key;
    indice++;
  }
  
  if(indice == 4){
    // Espacio para 4 letras + '\0' (fin de texto)
    password[4] = '\0';
   	Serial.print("La password ingresada es: ");
  	Serial.println(password);
    indice =0;
    // verificar si las contraseñas son iguales
  	 if(strcmp(password, passwordGuardada) == 0){
      Serial.print("Ingreso correcto");
      digitalWrite(ledVerde, HIGH);
      myServo.write(90);
      delay(2000);
      digitalWrite(ledRojo, LOW);
      myServo.write(0);
    }else{
    Serial.print("Error al ingresar");
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
    delay(2000);
    }
    
  } 
      
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledVerde, LOW);
}
