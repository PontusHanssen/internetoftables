#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "0123456789024";
const char* password = "askmotherwherethingsare";

const int DOWN = 5;
const int UP = 4;

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "Hello from esp8266!");
}

void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void){
  pinMode(UP, OUTPUT);
  pinMode(DOWN, OUTPUT);
  
  digitalWrite(UP, LOW);
  digitalWrite(DOWN, LOW);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/up", [](){
    server.send(200, "text/plain", "going up");
    digitalWrite(UP, HIGH);
    delay(2000);
    digitalWrite(UP, LOW);
  });

  server.on("/down", [](){
    server.send(200, "text/plain", "going down");
    digitalWrite(DOWN, HIGH);
    delay(2000);
    digitalWrite(DOWN, LOW);
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
