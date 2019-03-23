#include <LiquidCrystal.h> // Incluye la Libreria LiquidCrystal
const int rs = 8;
const int en = 9;
const int d4 = 6;
const int d5 = 5;
const int d6 = 4;
const int d7 = 3;
LiquidCrystal lcd(rs, en, d4,d5,d6,d7);
const int button = 12; 
int butttonState = 0;
bool start = 0;
unsigned long tiempo;
int segundos = 0;
int minutos = 0;
int horas = 0;

void setup() {   
  pinMode(button,INPUT);
  lcd.begin(16,2); // Inicializa la interface para el LCD screen, and determina sus dimensiones (ancho y alto) del display
  Serial.begin(9600);
}

void loop() { 
 int  buttonState = digitalRead(button);


  
  if(buttonState == HIGH){
      start=1;
      }
  if(start){
    lcd.setCursor(0,0);
    lcd.print("Tiempo: ");
    lcd.setCursor(0,1);
    tiempo = millis();
    segundos = (tiempo/1000);
    minutos = (segundos/60);
    horas = (minutos/60);
    if(horas<10){
      lcd.print(0);
    }
    lcd.print(horas);
    lcd.print(":");
    if(minutos-(60*horas)<10){
      lcd.print(0);
    }
    lcd.print(minutos-(60*horas));
    lcd.print(":");
    if((segundos-(60*minutos)-(360*horas))<10){
      lcd.print(0);
    }
    lcd.print(segundos-(60*minutos));
    delay(900);
    lcd.clear();
    delay(100);
  }

 }
