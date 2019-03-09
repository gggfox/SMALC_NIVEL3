int LED1 = 7;
int LED2 = 6;
int LED3 = 5;

int boton1 = 3;
int boton2 = 2;

int jugador1 = 0;
int jugador2 = 0;

int tiempo = 0;
int crono = 0;
int x = 0;
int y = 0;

void setup()
{
  Serial.begin(9600);
  //randomSeed(2);
  randomSeed(analogRead(A0));
  
  for( int i=1;i<11;i++){
      int alazar = random(1,7);
      Serial.print(alazar);
      Serial.print("   ");
  }
  Serial.println("");
  
  
  pinMode(boton1, INPUT); 
  pinMode(boton2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
 
}

void loop(){
Serial.println(millis());
  do{
      if (checa(boton1)){
      jugador1 = 1;
      prendeLED(LED1);
      }
      if (checa(boton2)){
      jugador2= 1;
      prendeLED(LED3);
      }
  }while (jugador1 == 0 || jugador2 == 0);
  
  delay(500);
  apaga();
  Serial.println("Juego Nuevo");
  tiempo= random(1000,7000);
  
  do{

      if (checa(boton1)){
        prendeLED(LED1);
        prendeLED(LED2);
      } else if (checa(boton2)){
        prendeLED(LED3);
        prendeLED(LED2);
      }
      delay(50);
      crono += 50;
  }while (tiempo > crono); //Tiempo de espera
  
 // digitalWrite(11,HIGH); 
  x= millis();
  
  do{
    if (checa(boton1)){
      jugador1 = 1;
      prendeLED(LED1);
      y = millis();
    }else if (checa(boton2)){
      jugador2= 1;
      prendeLED(LED3);
      y = millis();
    }
  }while (jugador1 == 0 && jugador2 == 0);

  Serial.println(y-x);
  digitalWrite(11,LOW);
  delay(5000);
  apaga();
}

void prendeLED(int pin){
digitalWrite(pin,HIGH);
}

bool checa(int pin){
  if (digitalRead(pin) == 1)
    return true;
    else return false;
}

void apaga(){
  digitalWrite(LED1,LOW);
  digitalWrite(LED3,LOW);
  jugador1 = 0;
  jugador2 = 0;
  crono = 0;
}


