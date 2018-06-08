#include "ESP8266WiFi.h"

// Conexión WiFi
const char* ssid     = "OnePlus 5T"; 
const char* password = "themonster2195";    




void setup()
{
  
  Serial.begin(115200); 

  // Conectando a la WiFi
  Serial.println();
  Serial.print("Contectando a ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    Serial.println("");
    Serial.println("Conectado de forma correcta a ");
    Serial.println(ssid);
 
}


void loop()
{
 
 
}

