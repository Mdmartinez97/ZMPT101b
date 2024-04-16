#include <ZMPT101B.h>

#define SENSITIVITY 500 //Sensibilidad, calibrar con ejemplo en librería

ZMPT101B voltageSensor(A0, 50); // (GPIO Pin, Frecuencia de red)

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  voltageSensor.setSensitivity(SENSITIVITY);
}

void loop() {

  float voltage = voltageSensor.getRmsVoltage(); // Leer sensor en VRMS

  Serial.println(voltage);

  delay(1000);
}