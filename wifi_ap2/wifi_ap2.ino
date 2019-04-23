#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266WebServer.h>
#include <DHT.h>

#define LED_BUILTIN 2

#define DHTPIN D1
#define DHTTYPE DHT11

// Configuración de la WiFi generada
const char *ssid = "MVC_AP";
const char *password = "pa55word";

ESP8266WebServer server(80);

DHT dht(DHTPIN, DHTTYPE);

void handleRoot() {
  String miliseg = server.arg("state");
  miliseg = millis();
  server.send(200, "text/html", "<H1>TimeStamp del NodeMCU -> " + miliseg + "</H1>");
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
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
