/*
Hackathon 2025
Secondaria II grado
TEST02: digital in/out
comando di un LED con un pulsante sensibile allo stato
Quando il pulsante sulla porta D2 è premuto il LED sulla porta D3 è acceso
Echo anche sul Builtin LED
*/
#include "wemosd1r32.h"
void setup() {
  pinMode(D2, INPUT);            //Inzializza la porta D2 come ingresso (pulsante)
  pinMode(D3, OUTPUT);           //Inzializza la porta D3 come uscita (LED)
  pinMode(LED_BUILTIN, OUTPUT);  //Inzializza la porta LED_BUILT_IN come uscita (LED)
}

void loop() {
  if(digitalRead(D2)==HIGH) {         //se pulsante premuto
    digitalWrite(D3, HIGH);           //Accende il LED
    digitalWrite(LED_BUILTIN, HIGH);  //Accende il LED
  }
  else {
    digitalWrite(D3, LOW);            //Spegne il LED   
    digitalWrite(LED_BUILTIN, LOW);   //Spegne il LED   
  } 
}
