#include <ESP8266WiFi.h>
//#include <WiFi.h>
#include "FirebaseESP32.h"

#define WIFI_SSID ""
#define WIFI_PASSWORD ""
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""

FirebaseData firebaseData;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Serial.println("Conectado");
}

void loop() {
  delay(500);
  Firebase.getBool(firebaseData, "/MeuPrimeiroProjeto/lampada");
  delay(500);
  Serial.println(firebaseData.stringData());
  //Firebase.setString(firebaseData, lampada, aux);
  //Firebase.end(firebaseData);
}
