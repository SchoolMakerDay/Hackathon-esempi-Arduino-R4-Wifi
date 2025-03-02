/*
Hackathon 2024
Secondaria II grado
TEST06: sound sensor led
comando di un LED con un sensore di suono
Il sensore di suono collegato ad A0 fornisce in ingresso una tensione variabile che viene trasformata in un valore digitale tra 0-4095
Se il valore supera la soglia regolabile in base alla rumorosità dell'ambiente viene attivato il LED
*/
int suono;
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);           //Inzializza la porta 3 come uscita (LED)
}

void loop() {
  suono=analogRead(A0);         //legge l'intensità del suono (range 0-1023)
  Serial.println(suono);
  if (suono>250) {              //se l'intensità del suono supera la soglia accende il LED
    digitalWrite(3,HIGH);
    Serial.println("suona");
  }
  else {                        //altrimenti spegne il LED
    digitalWrite(3,LOW);    
  }
}
