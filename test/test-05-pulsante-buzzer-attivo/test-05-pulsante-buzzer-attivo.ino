/*
Hackathon 2025
Secondaria II grado
TEST05: pulsante buzzer attivo
comando di un buzzer attivo con un pulsante sensibile allo stato
Quando il pulsante sulla porta D2 è premuto il buzzer suona con un tono predefinito
*/
void setup() {
  pinMode(2, INPUT);            //Inzializza la porta 2 come ingresso (pulsante)
  pinMode(3, OUTPUT);           //Inzializza la porta 3 come uscita (buzzer)
}

void loop() {
  if(digitalRead(2)==HIGH) {    //se pulsante premuto
    digitalWrite(3, HIGH);      //Accende il buzzer
  }
  else {
    digitalWrite(3, LOW);       //Spegne il buzzer
  }
}
