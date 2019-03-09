int jugador1 = 0;
int jugador2 = 0;
int tiempo= 0;
int crono= 0;
int x=0;
int y = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, INPUT);
}

void loop()
{
  do{
      if (checa(13)){
      jugador1 = 1;
      prendeLED(12);
      }
      if (checa(9)){
      jugador2= 1;
      prendeLED(10);
      }
  }while (jugador1 == 0 || jugador2 == 0);
  
  delay(500);
  apaga();
  Serial.println("Juego Nuevo");
  tiempo= random(1000,7000);
  
  do{

      if (checa(13)){
        prendeLED(12);
        prendeLED(11);
      } else if (checa(9)){
        prendeLED(10);
        prendeLED(11);
      }
      delay(50);
      crono += 50;
  }while (tiempo > crono); //Tiempo de espera
  
  digitalWrite(11,HIGH); 
  x= millis();
  
  do{
    if (checa(13)){
      jugador1 = 1;
      prendeLED(12);
      y = millis();
    }else if (checa(9)){
      jugador2= 1;
      prendeLED(10);
      y = millis();
    }
  
  }while (jugador1 == 0 && jugador2 ==0);

  Serial.println(y-x);
  digitalWrite(11,LOW);
  delay(5000);
  apaga();
}

void prendeLED(int pin){
digitalWrite(pin,5);
}

bool checa(int pin){
  if (digitalRead(pin) == 1)
    return true;
    else return false;
}

void apaga(){
  digitalWrite(12,LOW);
  digitalWrite(10,LOW);
  jugador1=0;
  jugador2=0;
  crono=0;
}


