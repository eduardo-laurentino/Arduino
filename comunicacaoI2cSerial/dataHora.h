#include <virtuabotixRTC.h>

byte dataHora(){
//Determina os pinos ligados ao modulo
  #define clk 22
  #define dat 23
  #define rst 24
  #define seg 0
  #define mnt 58
  #define hor 15
  #define d_sem 7
  #define d_mes 13
  #define mes 5
  #define ano 2023

  virtuabotixRTC meuRTC(clk, dat, rst);
  //meuRTC.setDS1302Time(seg, mnt, hor, d_sem, d_mes, mes, ano);
  meuRTC.updateTime();
  
  // Imprime informações
  int dia_semana(meuRTC.dayofweek);
  if(meuRTC.dayofmonth < 10) Serial.print("0");
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
    return meuRTC.dayofweek, meuRTC.dayofmonth, meuRTC.month, meuRTC.year, meuRTC.hours, meuRTC.minutes, meuRTC.seconds;
  }

// Converte o dia da semana na escrita dia da semana
 void dia_semana(int day_semana){
  switch(day_semana){
  case 1 : return "DOMINGO "; 
  break;
  case 2 : return "SEGUNDA "; 
  break;
  case 3 : return "TERÇA "; 
  break;
  case 4 : return "QUARTA "; 
  break;
  case 5 : return "QUINTA "; 
  break;
  case 6 : return "SEXTA "; 
  break;
  case 7 : return "SÁBADO "; 
  break;
}
}
