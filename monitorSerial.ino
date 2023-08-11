int sensor = A0; //define a entrada A0
void setup() {
pinMode(sensor, INPUT);
Serial.begin(9600); //Inicializa o monitor Serial
}
void loop() {
float tensao = analogRead(sensor)*5.0/1023.0;
Serial.print("Tensao do pino A0 em Volts: ");
Serial.println(tensao);
delay(1000);
}
