int MOTOR = 9 ;
int BOTAO = 7 ;
int valor;
void setup() {
pinMode(MOTOR, OUTPUT);
pinMode(BOTAO, INPUT);
// digitalWrite(RELE, HIGH);

}
void loop() {
valor = digitalRead(BOTAO);
if (valor==1){
digitalWrite(MOTOR, HIGH);}
else {digitalWrite(MOTOR, LOW);}
//digitalWrite(RELE, LOW);}
//else {digitalWrite(RELE, HIGH);}
delay (50);
}
