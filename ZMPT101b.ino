#include "EmonLib.h"

#define VOLT_CAL 350 //Valor de calibración del sensor
EnergyMonitor emon1; //Crea una instancia de Energy Monitor

//******************************************** SETUP ********************************************************************
void setup() {
 
 Serial.begin(115200);
 emon1.voltage(32, VOLT_CAL, 1.7); //Configuración de función 'voltage' (Pin de lectura, Calibración, Cambio de Fase)
}
//******************************************** LOOP ********************************************************************
void loop() {

 emon1.calcVI(20,2000); //Función de cálculo (20 semiciclos, tiempo de espera para tomar medición) 
 
 float tension = emon1.Vrms; //Valor V RMS obtenido

 Serial.print(tension);
 Serial.println("V RMS");
}