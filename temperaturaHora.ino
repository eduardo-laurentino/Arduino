#include <virtuabotixRTC.h> 

void setup() {
  Serial.begin(9600);
}

void temperatura(){
//Leitura de temperatura usando um termistor

// Conexão do termistor
const int pinTermistor = A0;
 
// Parâmetros do termistor
const double beta = 3600.0;
const double r0 = 10000.0;
const double t0 = 273.0 + 25.0;
const double rx = r0 * exp(-beta/t0);
 
// Parâmetros do circuito
const double vcc = 5.0;
const double R = 10000.0;
 
// Numero de amostras na leitura
const int nAmostras = 10;


// Le o sensor algumas vezes
  int soma = 0;
  for (int i = 0; i < nAmostras; i++) {
    soma += analogRead(pinTermistor);
    delay (10);
  }
 
  // Determina a resistência do termistor
  double v = (vcc*soma)/(nAmostras*1024.0);
  double rt = (vcc*R)/v - R;
 
  // Calcula a temperatura
  double t = beta / log(rt/rx);
  Serial.print(" | ");
  Serial.print("TEMPERATURA ");
  Serial.print (t-273.0);
  Serial.println (" °C");
 
  // Dá um tempo entre leituras
  //delay (1000);
  
  }

void dataHora(){
//Determina os pinos ligados ao modulo
  #define clk 6
  #define dat 7
  #define rst 8
  #define seg 0
  #define mnt 04
  #define hor 14
  #define d_sem 1
  #define d_mes 26
  #define mes 3
  #define ano 2023
  
  
  virtuabotixRTC meuRTC(clk, dat, rst);
  meuRTC.updateTime();
  
  // Imprime informações
  dia_semana(meuRTC.dayofweek);
  Serial.print(meuRTC.dayofmonth);
  Serial.print("/");
  if (meuRTC.month < 10) Serial.print("0");
  Serial.print(meuRTC.month);
  Serial.print("/");
  Serial.print(meuRTC.year);
  Serial.print(" | ");
  Serial.print("HORA = ");
  if(meuRTC.hours < 10) Serial.print("0");
  Serial.print(meuRTC.hours);
  Serial.print(":");
  if(meuRTC.minutes < 10) Serial.print("0");
  Serial.print(meuRTC.minutes);
  Serial.print(":");
  if(meuRTC.seconds < 10) Serial.print("0");
  Serial.print(meuRTC.seconds);
  //delay(1000);
    
  }

// Converte o dia da semana na escrita dia da semana
 void dia_semana(int day_semana){
  switch(day_semana){
  case 1 : Serial.print("DOMINGO "); 
  break;
  case 2 : Serial.print("SEGUNDA "); 
  break;
  case 3 : Serial.print("TERÇA "); 
  break;
  case 4 : Serial.print("QUARTA "); 
  break;
  case 5 : Serial.print("QUINTA "); 
  break;
  case 6 : Serial.print("SEXTA "); 
  break;
  case 7 : Serial.print("SÁBADO "); 
  break;
}
}


void loop() {
  delay(1000);
  dataHora();
  temperatura();
  delay(1200000);
}
