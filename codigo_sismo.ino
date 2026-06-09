#include <Servo.h>

Servo miServo;
const int pinPerilla = A0;
int angulo = 90;
int direccion = 1;

void setup() {
  pinMode(8, OUTPUT); 
  pinMode(7, OUTPUT); 
  digitalWrite(8, HIGH); 
  digitalWrite(7, LOW);  
  delay(500); 
  
  miServo.attach(9); 
  miServo.write(90); 
}

void loop() {
  int lectura = analogRead(pinPerilla); 
  
  if (lectura > 50) {
    int velocidad = map(lectura, 50, 1023, 100, 5); 
    
    // Avanza en pasos más cortos de 3 en 3 grados para no forzar los engranajes
    angulo += (3 * direccion); 
    
    // RANGOS REDUCIDOS DE EMERGENCIA (Zona central limpia)
    if (angulo >= 110) { direccion = -1; }
    if (angulo <= 70)  { direccion = 1;  }
    
    miServo.write(angulo);
    delay(velocidad); 
  } else {
    miServo.write(90); 
  }
}
