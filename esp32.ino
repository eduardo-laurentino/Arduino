#include <WiFi.h>
#include "FirebaseESP32.h"

#define WIFI_SSID "Yasmin"
#define WIFI_PASSWORD "Bandeira001"
#define FIREBASE_HOST "https://lampada-f83c6-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "syegr4w2LKqRVWOmIi8V1m6XFyNIgJYxSHL85DpX"

FirebaseData firebaseData;
String lampada = "/lampada";
void setup() {
  pinMode(15, OUTPUT);
  Serial.begin(115200);
  Serial.println();
  // put your setup code here, to run once:
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("Conectando ao WIFI");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
    }
    Serial.println();
    Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  Firebase.getString(firebaseData, lampada);
  Serial.println(firebaseData.stringData());
  //Firebase.setString(firebaseData, lampada, "0ff");
  //Serial.println(firebaseData.stringData());
  //Firebase.end(firebaseData);
  if (firebaseData.stringData() == "on"){
    digitalWrite(15, HIGH);
    }else{
      digitalWrite(15, LOW);
      }
    delay(1000);
}
