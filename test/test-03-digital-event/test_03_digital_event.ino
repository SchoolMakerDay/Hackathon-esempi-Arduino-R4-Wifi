/*
Hackathon 2025
Secondaria II grado
TEST03: digital event
comando di un LED con un pulsante sensibile all' evento di pressione
Quando il pulsante sulla porta D2 viene premuto il LED effettua un lampeggio di mezzo secondo
Si deve rilasciare il pulsante per un successivo lampeggio.
*/
int stato_attuale;                  //stato attuale del pulsante
int stato_precedente;               //stato precedente del pulsantw
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);                //Inzializza la porta 2 come ingresso (pulsante)
  pinMode(3, OUTPUT);               //Inzializza la porta 3 come uscita (LED)
  pinMode(LED_BUILTIN, OUTPUT);      //Inzializza la porta LED_BUILT_IN come uscita (LED)
  stato_attuale=digitalRead(2);     //inizializza lo stato attuale
  stato_precedente=stato_attuale;   //forza nessuna variazione  
  delay(5000);
  Serial.println("Starting digital event demo");
}

void loop() {
  stato_attuale=digitalRead(2);                        //legge il nuovo stato attuale del pulsante
  if((stato_attuale==HIGH)&&(stato_precedente==LOW)) {  //se lo stato attuale è HIGH E lo stato precedente è LOW: evento pressione
    Serial.println("Button pressed");
    digitalWrite(3, HIGH);                             //Accende il LED
    digitalWrite(LED_BUILTIN, HIGH);                    //Accende il LED
    delay(500);
    digitalWrite(3, LOW);                              //Spegne il LED
    digitalWrite(LED_BUILTIN, LOW);                      //Spegne il LED
  }
  stato_precedente=stato_attuale;                       //aggiorna lo stato precedente con il nuovo stato attuale
}
