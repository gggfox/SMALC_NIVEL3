#include <LiquidCrystal.h> // Incluye la Libreria LiquidCrystal
const int rs = 8;
const int en = 9;
const int d4 = 6;
const int d5 = 5;
const int d6 = 4;
const int d7 = 3;
LiquidCrystal lcd(rs, en, d4,d5,d6,d7);
void setup() {
  lcd.begin(16,1); // Inicializa la interface para el LCD screen, and determina sus dimensiones (ancho y alto) del display
    Serial.begin(9600);
}

void loop() {
  lcd.print("Nany, Carolina, Pedro, Hector, Marcos, Emmanuel, Enrique"); // Imprime "LCD Tutorial" sobre el LCD
  delay(3000);   // 3 segundos de espera
  
  lcd.setCursor(0,1); // Seteamos la ubicacion texto 0 linea 1 que sera escrita sobre el LCD
    for (int positionCounter = 0; positionCounter < 36; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(500);
    }
  }
