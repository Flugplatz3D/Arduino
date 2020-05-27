#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char *ssid_STA = "mi_ssid_local";
const char *password_STA = "????????";
ESP8266WebServer server(80);
void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid_STA, password_STA);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  WiFi.setAutoReconnect(true);
  Serial.println("WiFi conectada.");
  Serial.println();
  WiFi.printDiag(Serial);
  Serial.println();
  Serial.print("STA dirección IP: ");
  Serial.println(WiFi.localIP());
  server.on("/", []() {
    server.send(200, "text/plain", "Hola mundo!!");
  });
  server.begin();
  Serial.println("Servidor inicializado.");
}
void loop() {
  server.handleClient();
}
