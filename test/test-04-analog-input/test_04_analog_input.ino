/*
Hackathon 2025
Secondaria II grado
TEST04: analog input
comando di un LED in PWM con un potenziometro
Il potenziometro collegato ad A1 fornisce in ingresso una tensione variabile che viene trasformata in un valore digitale tra 0-4095
il valore viene convertito in PWM in range tra 0-255 dividendolo per 4 ed inviato al LED che si illumina con una intensità variabile
*/
int ingresso;     //valore letto (range 0-4095)  
int scalato;      //valore scalato per PWM (valore letto diviso 16 range 0-255)
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);               //Inzializza la porta 3 come uscita (LED)
  pinMode(LED_BUILTIN, OUTPUT);      //Inzializza la porta LED_BUILT_IN come uscita (LED)
  delay(5000);
  Serial.println("Starting analog input demo");
}

void loop() {
  ingresso=analogRead(A0);             //legge il nuovo valore dell'ingresso (range 0-4095)
  Serial.print("ingresso: ");
  Serial.println(ingresso);
  scalato=ingresso/16;
  Serial.print("scalato: ");
  Serial.println(scalato);
  Serial.println("----------------");
  analogWrite(3,scalato);             //emette un valore PWM sul LED (range 0-255)
  analogWrite(LED_BUILTIN,scalato);    //emette un valore PWM sul LED (range 0-255)
  delay(1000); 
}
