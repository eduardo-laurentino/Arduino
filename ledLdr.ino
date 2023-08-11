int LED = 10; // Pino no qual o LED está conectado
int LDR = A0; // Pino no qual o LDR está conectado
//int POT = A1; // pino no qual o Potenciômetro está conectado
int entrada = 0; // Variável que receberá o valor obtido do LDR
void setup() {
Serial.begin(9600); // Definir a velocidade de comunicação na porta serial
pinMode(LED, OUTPUT); // Definir o pino como saída
pinMode(LDR, INPUT);
//pinMode(POT, INPUT);
}
void loop() {
entrada = analogRead(LDR);
Serial.print("LDR: "); // Valor mostrado no serial monitor do Arduino
Serial.println(entrada);
//Serial.print("POT: "); // Valor mostrado no serial monitor do Arduino
//Serial.println(analogRead(POT));
//if (entrada < analogRead(POT)){
  if (entrada < 100){
digitalWrite(LED, HIGH); // Acende o LED
}
else{
digitalWrite(LED, LOW); // Apaga o LED
}
delay(100);
}
