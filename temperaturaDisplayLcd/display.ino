//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
#include "temperatura.h"
#include <SoftwareSerial.h>

 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  Serial.begin(9600);
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
}
 
void loop()
{
  float aux = temperatura();

  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(0, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Temp");
  lcd.setCursor(0, 1);
  lcd.print(aux);
  lcd.setCursor(12, 0);
  lcd.print("Turb");
  Serial.write(int(aux));
  delay(5000);
}
