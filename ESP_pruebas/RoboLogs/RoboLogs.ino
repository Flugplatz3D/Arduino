#include <ESP8266WiFi.h>

#define LED_BUILTIN 2

//Nombre de la red
const char* nombre = "*******";

//Password
const char* password = "********";

//Puerto (dejar en 80 por defecto)
WiFiServer server(80);



void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  delay(50); //Hay que dejar un margen de tiempo
  Serial.println();
  Serial.println("Intentando conectar a la red WiFi");

  // Conectar a la red WiFi
  WiFi.begin(nombre, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100); //aqui tambien hay que dejar un margen de tiempo
    digitalWrite(LED_BUILTIN, bitRead(millis(), 5));
  }
  
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Conectado a la red WiFi");

  // Iniciar el servidor
  server.begin();
  Serial.println("Se ha iniciado el servidor");

  // Escribir la direccion IP
  Serial.print("IP: ");
  Serial.print(WiFi.localIP());
  Serial.println("");
}

void loop() {
  // Comprobar si se ha conectado algun cliente
  WiFiClient client = server.available();

  if (client) {
    Serial.println("Nueva conexion");

    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
    digitalWrite(LED_BUILTIN, HIGH);

    // Escribir las cabeceras HTML
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");

    //Escribir el contenido que vamos a visualizar
    client.println("<html><h1>");
    client.print("TimeStamp del NodeMCU -> ");
    client.print(millis());
    client.println("</h1></html>");
  }
}
