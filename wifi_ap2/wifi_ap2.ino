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

float h = 0;
float t = 0;

void handleRoot() {
  String miliseg = server.arg("miliseg");
  String Temperatura = server.arg("Temperatura");
  String Humedad = server.arg("Humedad");
  String Mensaje = "";
  
  t = dht.readTemperature();
  h = dht.readHumidity();

  Serial.print(t);
  Serial.print("ºC - ");
  Serial.print(h);
  Serial.println("%");
  
  miliseg = millis();
  Temperatura = t;
  Humedad = h;

  Mensaje = "<H1>Lectura DHT11 con NodeMCU (Wifi_AP) - " + miliseg + "<br><br>";
  Mensaje += "Temperatura = " + Temperatura + " C<br>";
  Mensaje += "Humedad = " + Humedad + " %</H1>";

  server.send(200, "text/html", Mensaje);
  
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);
  Serial.println(millis());
  digitalWrite(LED_BUILTIN, HIGH);
}

void setup() {
  Serial.begin(9600);
  dht.begin();
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
