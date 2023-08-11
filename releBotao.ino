int RELE = 9;
int BOTAO = 7;
int valor;
void setup() {
pinMode(RELE, OUTPUT);
pinMode(BOTAO, INPUT);
// digitalWrite(RELE, HIGH);
}
void loop() {
valor = digitalRead(BOTAO);
if (valor==1){
digitalWrite(RELE, HIGH);
}
else {digitalWrite(RELE, LOW);}
//digitalWrite(RELE, LOW);}
//else {digitalWrite(RELE, HIGH);}
delay (50);


}
