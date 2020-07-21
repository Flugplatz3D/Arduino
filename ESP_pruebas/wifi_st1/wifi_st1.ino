#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266WebServer.h>

#define LED_BUILTIN 2

const char* ssid = "JAZZTEL_b4J6";
const char* password = "bejjmnwkyubc";
ESP8266WebServer server(80);

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
  String miliseg = server.arg("state");
  miliseg = millis();
  server.send(200, "text/html", "<H1>TimeStamp del NodeMCU -> " + miliseg + "</H1>");
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);
}
