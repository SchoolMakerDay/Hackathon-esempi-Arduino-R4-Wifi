/*
Hackathon 2025
Secondaria II grado
TEST01: salve mondo
test di funzionalità della scheda WEMOS LOLIN R1 D32.
Fa lampeggiare il LED integrato nella scheda collegato alla porta LED_BUILTIN
*/
void setup() {
pinMode(LED_BUILTIN, OUTPUT);     //Inzializza la LED_BUILTIN come uscita
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  //Accende il LED
  delay(2000);                      //Aspetta 2 secondi
  digitalWrite(LED_BUILTIN, LOW);   //Spegne il LED
  delay(1000);                      //aspetta 1 secondo
}
