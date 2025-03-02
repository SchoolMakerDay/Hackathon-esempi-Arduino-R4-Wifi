/*
Hackathon 2025
Secondaria II grado
TEST08: piezo vibro sensor
misura la presenza di vibrazioni e restituisce una info di tipo logico 0=vibrazioni sotto soglia, 1=vibrazioni sopra soglia sul led 3
E' possibile collegare un generatore di vibrazioni al pin 4 e comandarlo con un pushbutton al pin 5
*/
int timeout=millis();      //timeout di vibrazione
int ton=millis();
int fase=LOW;         //fase di vibrazione LOW/HIGH
int cmd=LOW;            //comando di vibrazione
void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
}

void loop() {
  //legge il comando di vibrazione
  cmd=digitalRead(5);
  if(cmd==HIGH) { //se comando attivo effettua il ciclo
    if(millis()-timeout>50){ //se il semiperiodo è completato
      if(fase==LOW){          //se era spento accende
        digitalWrite(4,HIGH);
        fase=HIGH;            //cambia semiperiodo
          //legge il sensore
      }
      else {                  //se era acceso spegne
        digitalWrite(4,LOW);
        fase=LOW;             //cambia semiperiodo      
      }
      timeout=millis();       //riavvia il timeout
    }
  }
  else {        //se comando non attivo spegne comunque
    digitalWrite(4,LOW);
  }
  //legge il sensore
  int sensorState = digitalRead(2);
  //segnala lo stato
  //Serial.println(sensorState);
  if (sensorState == HIGH) {
    ton=millis();
    digitalWrite(3, HIGH);
  }
  if(millis()-ton>1000){
    digitalWrite(3, LOW);
  }
}