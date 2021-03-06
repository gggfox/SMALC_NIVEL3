#include "DHT.h"
DHT dht(11, DHT11);

void setup() {
  //lcd.begin(16,2); // Inicializa la interface para el LCD screen, and determina sus dimensiones (ancho y alto) del display
  Serial.begin(9600);
  Serial.println("Prueba del sensor DHT11");
  dht.begin();
}

void loop() {
  delay(2000);
  // LEER LA HUMEDAD USANDO EL METRODO READHUMIDITY
  float h = dht.readHumidity();
  // LEER LA TEMPERATURA USANDO EL METRODO READTEMPERATURE
  float t = dht.readTemperature();

  // REVISAR QUE LOS RESULTADOS SEAN VALORES NUMERICOS VALIDOS, INDICANDO QUE LA COMUNICACION ES CORRECTA
  if (isnan(h) || isnan(t)) {
    Serial.println("Fal  la al leer el sensor DHT11!");
    return;
  }

  // IMPRIMIR RESULTADO AL MONITOR SERIAL
  Serial.println("Humedad: ");
  Serial.print(h);
  Serial.println(" % ");
  Serial.println("Temp:   ");
  Serial.print(t);
  Serial.println(" *C");
}
