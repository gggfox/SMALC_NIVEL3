 int led = 3;
int knob = A3;
void setup() {
  // put your setup code here, to run once:
  pinMode(knob, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int val = analogRead(knob);
val = map(val, 1, 1024, 1, 255);
analogWrite(led, val);
Serial.println(val);
delay(val*10);
digitalWrite(led,LOW);
delay(val*10);

}
