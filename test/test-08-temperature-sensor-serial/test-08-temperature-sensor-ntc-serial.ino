/*
Hackathon 2025
Secondaria II grado
TEST08: temperature sensor serial
raccolta valori di temperatura inviati sul canale seriale
Il sensore di di temperatura NTC collegato ad A0 fornisce in ingresso una tensione variabile che viene trasformata in un valore digitale tra 0-1023
il dato grezzo va convertito con la formula 1/T = 1/T0 + 1/B * ln(R/R0)
*/
const int B = 4275;               // valore B value del termisore
const int R0 = 100000;            // R0 = 100k partitore di tensione
int a;                            //lettura analogica
float R;                          //valore convertito
float t;                          //temperatura in °C
void setup() {
  Serial.begin(9600);
}

void loop() {
  a = analogRead(A0);         //legge l'intensità della luce (range 0-1023)
  R = (1023.0/a-1.0)*R0;
  t = 1.0/(log(R/R0)/B+1/298.15)-273.15;
  Serial.println(t);
  delay(1000);
}