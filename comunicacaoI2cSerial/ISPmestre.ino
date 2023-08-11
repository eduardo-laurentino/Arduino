#include <Wire.h>
#include "dataHora.h"
#include "temperatura.h"
#include "teste.h"

#define SDA_PIN 4
#define SCL_PIN 5
const int16_t I2C_MASTER = 0x42;
const int16_t I2C_SLAVE = 0x08;

void setup() {
  Wire.begin();
}
void loop() {
  transmissao1();
  transmissao2();
  //Wire.endTransmission();
  delay (500);
}

void transmissao1() {
  Wire.beginTransmission(I2C_SLAVE);
  Wire.write("x is ");
  Wire.write(temperatura());
  Wire.endTransmission();
}

void transmissao2() {
  Wire.beginTransmission(I2C_SLAVE);
  Wire.write("x é ");
  Wire.write(temperatura());
  Wire.endTransmission();
}
