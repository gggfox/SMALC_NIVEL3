//definimos los pines de nuestro display de 7 segmentos
int Pins[]={3,4,5,6,7,8,9};
//empezamos con nuestros valores en 1
int valores[]={1,1,1,1,1,1,1};
//vamos a usar un char para guardar las variables pq vamos a utilizar letras y numeros
char x;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //declaramos todos los pines como output
  for(int i = 0; i < 7; i++){
    pinMode(Pins[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //hacemos un read de parte del usuario en consola
  x = Serial.read();
  //Llamamos a nuestra funcion numero con nuestro variable x para obtener un arreglo de nuestros valores
  numero(x);
  //ciclo para prender los pines
  for(int i = 0; i < 7;i++)
  //nuestros pines estan como los declaramos de manera global, los valores son de nuestra funcion numero
    digitalWrite(Pins[i],valores[i]);
}

 
void numero(char numero){
  switch(numero){
    case '0':
      valores[0] = 1;
      valores[1] = 1;
      valores[2] = 1;
      valores[3] = 1;
      valores[4] = 1;
      valores[5] = 1;
      valores[6] = 0;
    break;
    
    case '1':
      valores[0] = 0;
      valores[1] = 1;
      valores[2] = 1;
      valores[3] = 0;
      valores[4] = 0;
      valores[5] = 0;
      valores[6] = 0;
    break;
    
    case '2':
      valores[0] = 1;
      valores[1] = 1;
      valores[2] = 0;
      valores[3] = 1;
      valores[4] = 1;
      valores[5] = 0;
      valores[6] = 1;
    break;
    
    case '3':
      valores[0] = 1;
      valores[1] = 1;
      valores[2] = 1;
      valores[3] = 1;
      valores[4] = 0;
      valores[5] = 0;
      valores[6] = 1;
    break;
    
    case '4':
      valores[0] = 0;
      valores[1] = 1;
      valores[2] = 1;
      valores[3] = 0;
      valores[4] = 0;
      valores[5] = 1;
      valores[6] = 1;
    break;
    
    case '5':
      valores[0] = 1;
      valores[1] = 0;
      valores[2] = 1;
      valores[3] = 1;
      valores[4] = 0;
      valores[5] = 1;
      valores[6] = 1;
    break;
    
    case '6':
      valores[0] = 1;
      valores[1] = 0;
      valores[2] = 1;
      valores[3] = 1;
      valores[4] = 1;
      valores[5] = 1;
      valores[6] = 1;
    break;
    
    case '7':
      valores[0] = 1;
      valores[1] = 1;
      valores[2] = 1;
      valores[3] = 0;
      valores[4] = 0;
      valores[5] = 0;
      valores[6] = 0;
    break;
    
    case '8':
      valores[0] = 1;
      valores[1] = 1;
      valores[2] = 1;
      valores[3] = 1;
      valores[4] = 1;
      valores[5] = 1;
      valores[6] = 1;
    break;
    
    case '9':
      valores[0] = 1;
      valores[1] = 1;
      valores[2] = 1;
      valores[3] = 0;
      valores[4] = 0;
      valores[5] = 1;
      valores[6] = 1;
    break;
    
    case 'a':
      valores[0] = 1;
      valores[1] = 1;
      valores[2] = 1;
      valores[3] = 0;
      valores[4] = 1;
      valores[5] = 1;
      valores[6] = 1;
    break;
    
    case 'b':
      valores[0] = 0;
      valores[1] = 0;
      valores[2] = 1;
      valores[3] = 1;
      valores[4] = 1;
      valores[5] = 1;
      valores[6] = 1;
    break;
    
    case 'c':
      valores[0] = 1;
      valores[1] = 0;
      valores[2] = 0;
      valores[3] = 1;
      valores[4] = 1;
      valores[5] = 1;
      valores[6] = 0;
    break;
    
    case 'd':
      valores[0] = 0;
      valores[1] = 1;
      valores[2] = 1;
      valores[3] = 1;
      valores[4] = 1;
      valores[5] = 0;
      valores[6] = 1;
    break;
    
    case 'e':
      valores[0] = 1;
      valores[1] = 0;
      valores[2] = 0;
      valores[3] = 1;
      valores[4] = 1;
      valores[5] = 1;
      valores[6] = 1;
    break;
    
    case 'f':
      valores[0] = 1;
      valores[1] = 0;
      valores[2] = 0;
      valores[3] = 0;
      valores[4] = 1;
      valores[5] = 1;
      valores[6] = 1;
    break;
  }
}

