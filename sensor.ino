bool estadoSensor;
void setup() {
pinMode(10,OUTPUT);
pinMode(4,INPUT);
}
void loop() {
estadoSensor = digitalRead(4);
if (estadoSensor == HIGH)
{
digitalWrite(10, HIGH);
}
else
{
digitalWrite(10, LOW);
}
}
