/*
Hackathon 2024
Secondaria II grado
TEST07: light sensor led
comando di un LED con un sensore di suono
Il sensore di luminosità collegato ad A0 fornisce in ingresso una tensione variabile che viene trasformata in un valore digitale tra 0-1023
Se il valore supera la soglia di 512 viene attivato il LED
*/
int luce;
void setup() {
  Serial.begin(9600);
  pinMode(D3, OUTPUT);           //Inzializza la porta 3 come uscita (LED)
}

void loop() {
  luce=analogRead(A0);         //legge l'intensità della luce (range 0-1023)
  Serial.println(luce);
  if (luce>350) {              //se l'intensità della luce supera la soglia accende il LED
    digitalWrite(3,HIGH);
  }
  else {                        //altrimenti spegne il LED
    digitalWrite(3,LOW);    
  }
}
