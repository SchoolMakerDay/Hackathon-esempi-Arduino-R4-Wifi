/*
Hackathon 2025
Secondaria II grado
TEST10: accelerometro dati su seriale
test di rilevamento dell'orientamento con accelerometro
rileva l'accelerazione sui tre assi x,y,z e la mostra, espressa in g, sulla seriale.
con il dispositivo a riposo i dati indicano l'orientamento del dispositivo (l'asse z attraversa il piano del dispositivo)
*/
#include <Wire.h>
#include "MMA7660.h"
MMA7660 accelerometro;
float ax,ay,az;
void setup(){
  accelerometro.init();  
  Serial.begin(9600);
}
void loop(){
  accelerometro.getAcceleration(&ax,&ay,&az);
  Serial.print("ax = ");
  Serial.print(ax);
  Serial.print(" ay = ");
  Serial.print(ay);
  Serial.print(" az = ");
  Serial.print(az);
  Serial.println();
  delay(1000);
}
