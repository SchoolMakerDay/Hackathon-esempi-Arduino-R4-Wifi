/*
Hackathon 2025
Secondaria II grado
TEST09: temperature sensor DH11 serial
raccolta valori di temperatura e umidità  inviati sul canale seriale
Il sensore di di temperatura DH11 collegato al pin digitale 2 con un protocollo proprietario
Il dato è già calibrato
*/
#include "Grove_Temperature_And_Humidity_Sensor.h"
#define DHTTYPE DHT11   // DHT 11
#define DHTPIN 2     // what pin we're connected to（DHT10 and DHT20 don't need define it）
DHT dht(DHTPIN, DHTTYPE);   //   DHT11 DHT21 DHT22

void setup() {
    Serial.begin(9600);
    Serial.println("DHTxx test!");
    Wire.begin();
    dht.begin();
}
void loop() {
    float temp_hum_val[2] = {0};
    if (!dht.readTempAndHumidity(temp_hum_val)) {
        Serial.print("Humidity: ");
        Serial.print(temp_hum_val[0]);
        Serial.print(" %\t");
        Serial.print("Temperature: ");
        Serial.print(temp_hum_val[1]);
        Serial.println(" *C");
    } else {
        Serial.println("Failed to get temprature and humidity value.");
    }
    delay(1500);
}
