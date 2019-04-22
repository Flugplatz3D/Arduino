#include <ESP8266WiFi.h>        // Include the Wi-Fi library

// Configuración de la WiFi generada
const char *ssid = "NodeMCU";
const char *password = "pa55word";

void setup() {
  Serial.begin(9600);
  delay(2000);

  WiFi.mode(WIFI_AP);
  while (!WiFi.softAP(ssid, password))
  {
    Serial.println(".");
    delay(100);
  }

  Serial.print("Iniciado AP ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

}

void loop() { }
