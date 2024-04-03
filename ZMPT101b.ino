#include "EmonLib.h" //Se utiliza para el monitoreo de Energía Eléctrica

#define VOLT_CAL 350 //Valor de calibración del sensor VC
EnergyMonitor emon1; //crea una instancia de Energy Monitor

//******************************************** SETUP ********************************************************************
void setup(){
 
 Serial.begin(115200); //Abre la comunicación con el monitor serial de Arduino
 emon1.voltage(32, VOLT_CAL, 1.7); //Seteo de la función voltaje (Pin de lectura, Valor de Calibración, Cambio de Fase)

//******************************************** LOOP ********************************************************************
void loop(){

 emon1.calcVI(20,2000); //función de cálculo (20 semiciclos, tiempo de espera para tomar medición) 
 
 float tension = emon1.Vrms; //variable que recibe el valor de voltaje rms obtenido

 Serial.print(tension);
 Serial.println("V RMS");
 
}