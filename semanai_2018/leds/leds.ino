int verde=2;
int amarillo=3;
int rojo=4;
void setup() {
  // put your setup code here, to run once:
pinMode(verde, OUTPUT);
pinMode(amarillo,OUTPUT);
pinMode(rojo,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(verde,HIGH);
delay(500);
digitalWrite(verde,LOW);
digitalWrite(amarillo,HIGH);
delay(500);
digitalWrite(amarillo,LOW);
digitalWrite(rojo,HIGH);
delay(500);
digitalWrite(rojo,LOW);
}
