const int pinTermistor = A0;
const double beta = 3600.0;
const double r0 = 1000.0;
const double t0 = 273.0 + 25.0;
const double rx = r0 * exp(-beta/t0);
const double vcc = 5.0;
const double R = 10000.0;
const int nAmostras = 5;
void setup() {
Serial.begin(9600);
}
void loop() {
int soma = 0;
for (int i = 0; i < nAmostras; i++) {
soma += analogRead(pinTermistor);
delay (10);
}
double v = (vcc*soma)/(nAmostras*1024.0);
double rt = (vcc*R)/v - R;
double t = beta / log(rt/rx);
Serial.print("Valor de Rx ");
Serial.print (rx, 5);
Serial.println(" Ohm");
Serial.print("Tensão em A0 ");
Serial.print (v);
Serial.println(" V");
Serial.print("Valor de Rt ");
Serial.print (rt);
Serial.println(" Ohm");
Serial.print("Temperatura no Sensor ");
Serial.print (t - 273.0);
Serial.println(" °C");
delay (1000);
}
