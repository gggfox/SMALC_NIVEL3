//Libreria para utilizar servo
#include <Servo.h>

//Declaramos nustro servo
Servo servo;

int x=180;
//variable para guardar los grados que moveremos
//el servo


void setup() {
servo.attach(9);
//El equivalente a pinMode, pero para servos
//Gracias a la libreria, se puede conectr
//cualquier pin digital

}

void loop() {
 servo.write(x);
 //Funcion para mover el servo
 //se definen los grados a mover
 //Rango de 0 a 180
 //ejemplo
 
 //servo.write(180);
 //delay(500);
 //servo.write(90);
 //delay(500);
 //servo.write(0);

}
