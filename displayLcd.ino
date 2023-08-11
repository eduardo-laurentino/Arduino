// Enviar dados para o LCD sem biblioteca, com RW aterrado e com 8 bits
// --- Mapeamento dos pinos ---
#define db7 7
#define db6 6
#define db5 5
#define db4 4
#define db3 11
#define db2 10
#define db1 9
#define db0 8
#define rs 13
#define en 12
// --- Configurações para iniciar o LCD de acordo com a página 24 do Datasheet HITACHI ---
void setup()
{
//configura saídas
pinMode(db0, OUTPUT);
pinMode(db1, OUTPUT);
pinMode(db2, OUTPUT);
pinMode(db3, OUTPUT);
pinMode(db4, OUTPUT);
pinMode(db5, OUTPUT);
pinMode(db6, OUTPUT);
pinMode(db7, OUTPUT);
pinMode(rs, OUTPUT);
pinMode(en, OUTPUT);
//inicializa saídas
digitalWrite(db0, LOW);
digitalWrite(db1, LOW);
digitalWrite(db2, LOW);
digitalWrite(db3, LOW);
digitalWrite(db4, LOW);
digitalWrite(db5, LOW);
digitalWrite(db6, LOW);
digitalWrite(db7, LOW);
digitalWrite(en, LOW);
digitalWrite(rs, LOW);
delay(2);
// Limpa LCD - Clear display na pagina 24 do datasheet HITACHI
digitalWrite(db0, HIGH);
digitalWrite(db1, LOW);
digitalWrite(db2, LOW);
digitalWrite(db3, LOW);
digitalWrite(db4, LOW);
digitalWrite(db5, LOW);
digitalWrite(db6, LOW);
digitalWrite(db7, LOW);
// Pulso no enable: LOW em 2ms, vai para HIGH durante 2ms e volta para LOW
digitalWrite(en, LOW);
delay(2);
digitalWrite(en, HIGH);
delay(2);
digitalWrite(en, LOW);
delay(2);
// Modo de 8 Bitis com 5X8 em cada caractere com linha 1 (pg 24 do datasheet HITACHI)
digitalWrite(db1, LOW);
digitalWrite(db2, LOW); // db2=0 5X8
digitalWrite(db3, LOW); // db3=0 linha 1
digitalWrite(db4, HIGH);
digitalWrite(db5, HIGH);
digitalWrite(db6, LOW);
digitalWrite(db7, LOW);
// Pulso no enable: LOW em 2ms, vai para HIGH durante 2ms e volta para LOW
digitalWrite(en, LOW);
delay(2);
digitalWrite(en, HIGH);
delay(2);
digitalWrite(en, LOW);
delay(2);
// Liga o LCD, liga CURSOR, desliga BLINK - Display on/off Control página 24 do datasheet HITACHI
digitalWrite(db0, LOW); // db0=0 sem Blink
digitalWrite(db1, HIGH); // db1=1 com cursor
digitalWrite(db2, HIGH);
digitalWrite(db3, HIGH);
digitalWrite(db4, LOW);
digitalWrite(db5, LOW);
digitalWrite(db6, LOW);
digitalWrite(db7, LOW);
// Pulso no enable LOW em 2ms, vai para HIGH durante 2ms e volta para LOW
digitalWrite(en, LOW);
delay(2);
digitalWrite(en, HIGH);
delay(2);
digitalWrite(en, LOW);
delay(2);
// Habilita INCREMENTO, Desliga SCROLL ( Scroll Move o conteúdo do display (texto+cursor) um espaço para a direita)
digitalWrite(db0, LOW); // db0=0 Scroll E
digitalWrite(db1, HIGH); // db1=1 incremento e db1=0 decremento
digitalWrite(db2, HIGH);
digitalWrite(db3, LOW);
digitalWrite(db4, LOW);
digitalWrite(db5, LOW);
digitalWrite(db6, LOW);
digitalWrite(db7, LOW);
// Pulso no enable LOW em 2ms, vai para HIGH durante 2ms e volta para LOW
digitalWrite(en, LOW);
delay(2);
digitalWrite(en, HIGH);
delay(2);
digitalWrite(en, LOW);
delay(2);
// ENVIA CARACTERE "0" (30h-110000b)de acordo com a tabela ascii
digitalWrite(db0, LOW); // menos significativo
digitalWrite(db1, LOW);
digitalWrite(db2, LOW);
digitalWrite(db3, LOW);
digitalWrite(db4, HIGH);
digitalWrite(db5, HIGH);
digitalWrite(db6, LOW);
digitalWrite(db7, LOW); // mais significativo
// escreve
digitalWrite(rs, HIGH);
delay(2);
// Pulso no enable: vai para HIGH durante 2ms e volta para LOW
digitalWrite(en, HIGH);
delay(2);
digitalWrite(en, LOW);
delay(2);
// ENVIA CARACTERE "1" (31h-110001b)de acordo com a tabela ascii
digitalWrite(db0, HIGH); // menos significativo
digitalWrite(db1, LOW);
digitalWrite(db2, LOW);
digitalWrite(db3, LOW);
digitalWrite(db4, HIGH);
digitalWrite(db5, HIGH);
digitalWrite(db6, LOW);
digitalWrite(db7, LOW); // mais significativo
// escreve
digitalWrite(rs, HIGH);
delay(2);
// Pulso no enable: vai para HIGH durante 2ms e volta para LOW
digitalWrite(en, HIGH);
delay(2);
digitalWrite(en, LOW);
delay(2);
// ENVIA CARACTERE "2" (32h-110010b)de acordo com a tabela ascii
digitalWrite(db0, LOW); // menos significativo
digitalWrite(db1, HIGH);
digitalWrite(db2, LOW);
digitalWrite(db3, LOW);
digitalWrite(db4, HIGH);
digitalWrite(db5, HIGH);
digitalWrite(db6, LOW);
digitalWrite(db7, LOW); // mais significativo
// escreve
digitalWrite(rs, HIGH);
delay(2);
// Pulso no enable: vai para HIGH durante 2ms e volta para LOW
digitalWrite(en, HIGH);
delay(2);
digitalWrite(en, LOW);
delay(2);
// ENVIA CARACTERE "3" (33h-110011b)de acordo com a tabela ascii
digitalWrite(db0, HIGH); // menos significativo
digitalWrite(db1, HIGH);
digitalWrite(db2, LOW);
digitalWrite(db3, LOW);
digitalWrite(db4, HIGH);
digitalWrite(db5, HIGH);
digitalWrite(db6, LOW);
digitalWrite(db7, LOW); // mais significativo
// escreve
digitalWrite(rs, HIGH);
delay(2);
// Pulso no enable: vai para HIGH durante 2ms e volta para LOW
digitalWrite(en, HIGH);
delay(2);
digitalWrite(en, LOW);
delay(2);
// ENVIA CARACTERE "4" (34h-110100b)de acordo com a tabela ascii
digitalWrite(db0, LOW); // menos significativo
digitalWrite(db1, LOW);
digitalWrite(db2, HIGH);
digitalWrite(db3, LOW);
digitalWrite(db4, HIGH);
digitalWrite(db5, HIGH);
digitalWrite(db6, LOW);
digitalWrite(db7, LOW); // mais significativo
// escreve
digitalWrite(rs, HIGH);
delay(2);
// Pulso no enable: vai para HIGH durante 2ms e volta para LOW
digitalWrite(en, HIGH);
delay(2);
digitalWrite(en, LOW);
delay(2);
// ENVIA CARACTERE "5" (35h-110101b)de acordo com a tabela ascii
digitalWrite(db0, HIGH); // menos significativo
digitalWrite(db1, LOW);
digitalWrite(db2, HIGH);
digitalWrite(db3, LOW);
digitalWrite(db4, HIGH);
digitalWrite(db5, HIGH);
digitalWrite(db6, LOW);
digitalWrite(db7, LOW); // mais significativo
// escreve
digitalWrite(rs, HIGH);
delay(2);
// Pulso no enable: vai para HIGH durante 2ms e volta para LOW
digitalWrite(en, HIGH);
delay(2);
digitalWrite(en, LOW);
delay(2);
// ENVIA CARACTERE "6" (36h-110110b)de acordo com a tabela ascii
digitalWrite(db0, LOW); // menos significativo
digitalWrite(db1, HIGH);
digitalWrite(db2, HIGH);
digitalWrite(db3, LOW);
digitalWrite(db4, HIGH);
digitalWrite(db5, HIGH);
digitalWrite(db6, LOW);
digitalWrite(db7, LOW); // mais significativo
// escreve
digitalWrite(rs, HIGH);
delay(2);
// Pulso no enable: vai para HIGH durante 2ms e volta para LOW
digitalWrite(en, HIGH);
delay(2);
digitalWrite(en, LOW);
delay(2);
}
// Fim do setup

// --- Loop Infinito ---
void loop()
{
}
// Fim do loop
