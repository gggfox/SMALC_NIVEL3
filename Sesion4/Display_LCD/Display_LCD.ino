#include <LiquidCrystal.h> //se incluye Liquid Crystal que es la biblioteca que se usa par ael display

//Solo se necesitan conectar 6 pines al arduino, el de rs, en, el del d4-d7
const int rs = 10;
const int en = 9;
const int d4 = 6;
const int d5 = 5;
const int d6 = 4;
const int d7 = 3;

LiquidCrystal lcd(rs, en, d4,d5,d6,d7);
//Esta es para declarar una variable tipo LiquidCrystal
//Esta sirve para poder llamar todas las funciones de la bilbioteca
//Cada vez que quieras llamar una funcion usas lcd y un punto
// De esta forma ---->   lcd.begin();
//el lcd sirve para que busque la funcion en liquidcrystal

//El orden en el ue se declara los parametros en lcd es fijo, y lo buscan en internet,
//pero para que funcione solo necesita esos 6 parametros

void setup() {
  //Esto es para iniciar la display y decirle que quieres
  //16 columnas y 2 filas
  lcd.begin(16,2);
  //Esta sirve para imprimir lo que sea que le escribas
  //Si el texto no cabe en los 16 cuadros, se tiene que recorrer para que se pueda ver
  lcd.print("hello World");
   
}

void loop() {
  // put your main code here, to run repeatedly:

  //Esta es para cambiar el cursor de posicion
  //Te lo acomoda en la fila y columna que quieras,
  //en este caso se pondria enla segunda line en la primera posicion
  //Para regresarlo al origen seria lc.setCursor(0,0=;
  lcd.setCursor(0,1);

  //Para desplegar los millis a modo de contador)
  lcd.print(millis()/1000);
  //el print imprime variable o el texto que le mandes.
  
}
