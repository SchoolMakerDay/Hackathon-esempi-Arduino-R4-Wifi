/*
Hackathon 2025
Secondaria II grado
TEST125 HTTP client broker write JSON
invia ogni 5 secondi il valore di una grandezza analogica in formato JSON  al server Rabbits riceve una risposta
*/
#include "WiFiS3.h" 
#include <ArduinoHttpClient.h>
#include "arduino_secrets.h"
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
char serverAddress[] = "www.schoolmakerday.it";  // server address
int port = 80;
WiFiClient wifi;
HttpClient client = HttpClient(wifi, serverAddress, port);
int status = WL_IDLE_STATUS;
int ingresso;     //valore letto (range 0-4095)  
int scalato;      //valore scalato per PWM (valore letto diviso 16 range 0-255)
char buffer[100]="";
void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);

    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);
  }
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop() {
  ingresso=analogRead(A0);             //legge il nuovo valore dell'ingresso (range 0-1023)
  Serial.print("ingresso: ");
  Serial.println(ingresso);
  scalato=ingresso/4;
  Serial.print("scalato: ");
  Serial.println(scalato);
  Serial.println("----------------");
  analogWrite(3,scalato);             //emette un valore PWM sul LED (range 0-255)
  Serial.println("making GET request");
  sprintf(buffer, "/rabbits/set.php?key=var1&value=%d", scalato);
  Serial.println(buffer);
  client.get(buffer);
  // read the status code and body of the response
  int statusCode = client.responseStatusCode();
  String response = client.responseBody();
  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);
  Serial.println("Wait five seconds");
  delay(5000);
}
