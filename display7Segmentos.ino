byte seven_seg_digits[16][7] = {
{ 1,1,1,1,1,1,0 }, //DIGITO 0
{ 0,1,1,0,0,0,0 }, //DIGITO 1
{ 1,1,0,1,1,0,1 }, //DIGITO 2
{ 1,1,1,1,0,0,1 }, //DIGITO 3
{ 0,1,1,0,0,1,1 }, //DIGITO 4
{ 1,0,1,1,0,1,1 }, //DIGITO 5
{ 1,0,1,1,1,1,1 }, //DIGITO 6
{ 1,1,1,0,0,0,0 }, //DIGITO 7
{ 1,1,1,1,1,1,1 }, //DIGITO 8
{ 1,1,1,1,0,1,1 }, //DIGITO 9
{ 1,1,1,0,1,1,1 }, //DIGITO A
{ 0,0,1,1,1,1,1 }, //DIGITO B
{ 1,0,0,1,1,1,0 }, //DIGITO C
{ 0,1,1,1,1,0,1 }, //DIGITO D
{ 1,0,0,1,1,1,1 }, //DIGITO E
{ 1,0,0,0,1,1,1 } //DIGITO F
};
void setup(){
pinMode(2, OUTPUT); //Pino 2 -> Segmento A
pinMode(3, OUTPUT); //Pino 3 -> Segmento B
pinMode(4, OUTPUT); //Pino 4 -> Segmento C
pinMode(5, OUTPUT); //Pino 5 -> Segmento D
pinMode(6, OUTPUT); //Pino 6 -> Segmento E
pinMode(7, OUTPUT); //Pino 7 -> Segmento F
pinMode(8, OUTPUT); //Pino 8 -> Segmento G
pinMode(9, OUTPUT); //Pino 9 -> Segmento PONTO
ligaPonto(0);
}
void ligaPonto(byte dot){ //Função que aciona o ponto do display
digitalWrite(9, dot);
}
void ligaSegmentosDisplay(byte digit){ //FUNÇÃO QUE ACIONA O DISPLAY
byte pino = 2;
for (byte contadorSegmentos = 0; contadorSegmentos < 7;
++contadorSegmentos){
//Para "contadorSegmentos"
//Igual a 0, enquanto "contadorsegmentos" menor que 7, incrementa"contadorSegmentos"
digitalWrite(pino, seven_seg_digits[digit][contadorSegmentos]);
//Percorre o array e liga os
//Segmentos correspondentes ao digito
++pino; //Incrementa "pino"
}
ligaPonto(1); //Liga o ponto do display
delay(100); //Intervalo de 100 milissegundos
ligaPonto(0); //Desliga o ponto do display
}
//Método responsável pela contagem de 0 a 9 e contagem de "a" até "f"(na contagem hexadecimal "A"=10 / "B"=11 / "C"=12 / "D"=13 / "E"=14 /"F"=15)
void loop() {
for (byte contador = 0; contador < 16; contador++){ //Para "contador"
//Igual a 0, enquanto "contador" menor que 16, incrementa "contador"
delay(500); //Intervalo de 500 milissegundos
ligaSegmentosDisplay(contador); //Faz a contagem
}
delay(2000); //Intervalo de 2 segundos
}
