#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266WebServer.h>
#include <DHT.h>

#define LED_BUILTIN 2

#define DHTPIN D1
#define DHTTYPE DHT11

const char* ssid = "JAZZTEL_b4J6";
const char* password = "bejjmnwkyubc";
float h = 0;
float t = 0;
unsigned long millisAnt = 0;
ESP8266WebServer server(80);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  Serial.println();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    digitalWrite(LED_BUILTIN, bitRead(millis(), 4));
  }
  WiFi.setAutoReconnect(true);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("Iniciado AP -> ");
  Serial.println(ssid);
  Serial.print("IP address -> ");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String miliseg = server.arg("miliseg");
  String Temperatura = server.arg("Temperatura");
  String Humedad = server.arg("Humedad");
  String Mensaje = "";

  t = dht.readTemperature();
  h = dht.readHumidity();
  while (isnan(h) || isnan(t))
  {
    delay(500);
    t = dht.readTemperature();
    h = dht.readHumidity();
  }
  Temperatura = t;
  Humedad = h;
  miliseg = millis();
  Mensaje = "<H1>Lectura DHT11 con NodeMCU - " + miliseg + "<br><br>";
  Mensaje += "Temperatura = " + Temperatura + " C<br>";
  Mensaje += "Humedad = " + Humedad + " %</H1>";
  server.send(200, "text/html", Mensaje);
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);
  Serial.println(millis());
  digitalWrite(LED_BUILTIN, HIGH);
}
