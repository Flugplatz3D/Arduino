#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266WebServer.h>

// Configuración de la WiFi generada
const char *ssid = "Umbrella_Corp";
const char *password = "pa55word";

ESP8266WebServer server(80);

void handleRoot() {
  String miliseg = server.arg("state");
  miliseg = millis();
  server.send(200, "text/html", "TimeStamp del NodeMCU -> " + miliseg);
}

void setup() {
  Serial.begin(9600);
  delay(1000);

  WiFi.mode(WIFI_AP);
  while (!WiFi.softAP(ssid, password))
  {
    Serial.println(".");
    delay(100);
  }

  Serial.print("Iniciado AP -> ");
  Serial.println(ssid);
  Serial.print("IP address -> ");
  Serial.println(WiFi.softAPIP());
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
