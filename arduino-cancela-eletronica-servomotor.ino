#include <Servo.h>
/* Link para baixar a biblioteca NewPing:
   https://drive.google.com/file/d/0B91L9po09u35c3EzOG9pOXBldVU/view
*/
#include <NewPing.h>
//distância máxima
#define MAXIMA 10
//pinos do sensor ultrassônico
const int p_echo = 8;
const int p_trig = 9;
//Objeto NewPing
NewPing sensor(p_trig, p_echo, MAXIMA);
//pinos para uso das led
const int ledFechado = 4;
const int ledAberto = 5;
//pino servo motor
const int p_servo = 7;
//Objeto servo
Servo motor;

bool distancia();

void setup() {
  Serial.begin(9200);
  pinMode(ledAberto, OUTPUT);
  pinMode(ledFechado, OUTPUT);
  motor.attach(p_servo);
}

void loop() {
  if (distancia()) {
    digitalWrite(ledFechado, HIGH);
    motor.write(100);
    delay(2000);
    digitalWrite(ledFechado, LOW);
  }
  motor.write(0);
  digitalWrite(ledAberto, HIGH);
  delay(50);
}

bool distancia() {
  int sen = sensor.ping_cm();
  //limite de 3cm para detectar
  if ((sen <= 3) && (sen > 0)) {
    return true;
  } else {
    return false;
  }
}
