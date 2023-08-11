int LED = 9; // Pino no qual o LED está conectado
int BOTAO = 7; // Pino no qual o Botão está conectado
int valor;
void setup() {
pinMode(LED, OUTPUT); // Definir o pino como saída
pinMode(BOTAO, INPUT); // Definir o pino com entrada
}
void loop() {
// Obtém LOW (botão não pressionado) ou HIGH (pressionado)
valor = digitalRead(BOTAO);
// escreve o resultado obtido em “valor” na saída LED
digitalWrite(LED, valor);
delay (50);
}
