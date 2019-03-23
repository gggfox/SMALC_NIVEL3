#include <LiquidCrystal.h> 
int cont=0;
int Sensor=2;
int led=4;
LiquidCrystal lcd (A0, A1, A2, A3, A4, A5);
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
pinMode(Sensor,INPUT);
 lcd.begin(16, 2);
}

void loop() {
  int statusS=digitalRead(Sensor);
    lcd.setCursor(0, 0);
  lcd.print("Aplausos ");
  lcd.setCursor(0, 1);
  lcd.print("Cont: ");
  lcd.print(cont);
  if (statusS==0)
  {
    lcd.clear();
    digitalWrite(led,HIGH);
    cont++;
  }
  else
  {
    digitalWrite(led,LOW);
  }
  // put your main code here, to run repeatedly:

}
