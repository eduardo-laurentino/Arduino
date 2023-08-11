void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial3.begin(115200);
  Serial3.setTimeout(50);
}
String recebi;
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial3.available() > 0) {
    //Leitura de um byte.
    recebi = Serial3.readString();
    //Imprima o mesmo dado pela porta usb.
    if(recebi == "on\r\n"){
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      }else{
        digitalWrite(12, LOW);
        digitalWrite(11, HIGH);
        }
     delay(500);
  }
}
