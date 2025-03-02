/*
Hackathon 2025
Secondaria II grado
TEST12: HTTP client broker read
legge  ogni 5 secondi il valore di una grandezza dal server Rabbits
*/
#include "WiFiS3.h" 
#include <ArduinoHttpClient.h>
#include "arduino_secrets.h"
#include <ArduinoJson.h>
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
char serverAddress[] = "www.schoolmakerday.it";  // server address
int port = 80;
WiFiClient wifi;
HttpClient client = HttpClient(wifi, serverAddress, port);
int status = WL_IDLE_STATUS;
StaticJsonDocument<512> doc;           //received JSON object
DeserializationError error;           //JSON deserialization result
int uscita;        //valore da attuare
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
  Serial.println("making GET request");
  Serial.println("/rabbits/get.php?key=cmd1");
  client.get("/rabbits/get.php?key=cmd1");
  // read the status code and body of the response
  int statusCode = client.responseStatusCode();
  String response = client.responseBody();
  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);
  error=deserializeJson(doc,response);
  if(error){
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
  }
  else {             
    String sta=doc["status"];
    Serial.println(sta);
    String key = doc["data"]["key"];
    String value = doc["data"]["value"];
    String ts = doc["data"]["ts"];
    Serial.println("key:"+key+" value:"+value+" timestamp:"+ts);
    if(value=="0"){
      digitalWrite(3,LOW);
    }
    else {
      digitalWrite(3,HIGH);
    }
  } 
  Serial.println("Wait five seconds");
  delay(5000);
}
