/*
Hackathon 2025
Secondaria II grado
TEST14: HTTP client JSON
richiede ogni cinque secondi il time al server Rabbits riceve una stringa JSON contenente data ed ora del server e la converte
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

void setup() {
  Serial.begin(9600);
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
  client.get("/rabbits/time.php");
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
    String year = doc["data"]["year"];
    String month = doc["data"]["month"];
    String day = doc["data"]["day"];
    String hour = doc["data"]["hour"];
    String minute = doc["data"]["minute"];
    String second = doc["data"]["second"];
    Serial.println(day+"/"+month+"/"+year+" "+hour+":"+minute+":"+second);
  } 
  Serial.println("Wait five seconds");
  delay(5000);
}
