#include <Arduino.h>
#include <TM1637Display.h>
//Pinos de controle do modulo
#define CLK 4
#define DIO 5
#define pin_pot A0
//Inicializa o display
TM1637Display display(CLK, DIO);
int valor;
void setup()
{
pinMode(A0, INPUT);
}
void loop()
{
//Define o brilho do display em f, ou seja 15.
display.setBrightness(0x0f);
//Le o valor do potenciometro
valor = analogRead(pin_pot);
//Mostra o valor no display
display.showNumberDec(valor, false);
delay(1000);
}
