#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10,11);
char data=0;

void setup() {
  // put your setup code here, to run once:
bluetooth.begin(9600);
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(bluetooth.available()>0)
{
  data=bluetooth.read();
  Serial.print(data);
  Serial.print("\n");
  if(data=='1')
  digitalWrite(13,HIGH);
  else if (data=='0')
  digitalWrite(13,LOW);
}
}
