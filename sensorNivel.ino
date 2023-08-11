int sensor1 = 9;
int sensor2 = 10;
int rele = 11;
void setup() {
  pinMode (sensor1, INPUT);
  pinMode (sensor2, INPUT);
  pinMode (rele, OUTPUT);

}

void loop() {
  sensor1 = digitalRead(9);
  sensor2 = digitalRead(10);
  
  if(sensor1 == LOW && sensor2 == LOW){
    digitalWrite (rele, HIGH);
    }
  if(sensor2 == HIGH && sensor1 == HIGH){
      digitalWrite (rele, LOW);
      }
      delay (500);

}
