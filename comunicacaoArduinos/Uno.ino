void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}
String recebi;
void loop() {
  // put your main code here, to run repeatedly:
 if (Serial.available() > 0) {
    //Leitura de um byte.
    recebi = Serial.readString();
    //Imprima o mesmo dado pela porta usb.
    if(recebi == "Ligado\r\n"){
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      }else{
        digitalWrite(12, LOW);
        digitalWrite(11, HIGH);
        }
     delay(1000);
  }
}
