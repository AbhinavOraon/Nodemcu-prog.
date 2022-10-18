#include <ESP8266WiFi.h>
const char* ssid="zxr";
const char* password="1234567890";
const int led= 4;
WiFiServer server(80);
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
Serial.begin(115200);
Serial.print("Connecting to.");
Serial.println(ssid);

WiFi.mode(WIFI_STA);
WiFi.begin(ssid,password);
while (WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print("..");}
Serial.println("Nodemcu(esp8266) is connected to the ssid");
Serial.println(WiFi.localIP());
 server.begin();
 delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
WiFiClient client;
client=server.available();

if (client ==1){
  String request=client.readStringUntil('\n');
  client.flush();
  Serial.println(request);
  if (request.indexOf("ledon") != -1){
    digitalWrite(led,HIGH);
    Serial.println("LED IS ON NOW");}
   else if (request.indexOf("ledoff") != -1){
    digitalWrite(led,LOW);
    
    client.println("HTTP/1.1 200 OK");
    Serial.println("LED IS OFF NOW");}
    Serial.print("Client Disconnected");
    Serial.println("===========================================================");
  Serial.println("                              ");
}
}
