int pinoPWM = 10;
void setup() {
// setup não necessário
}
void loop(){
for (int i = 0; i <= 255; i++) {
analogWrite(pinoPWM, i);
delay(10);
}
}
