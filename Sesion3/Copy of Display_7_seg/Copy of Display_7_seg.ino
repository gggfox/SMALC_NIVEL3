int Pins[]={3,4,5,6,7,8,9};
int valores[]={1,1,1,1,1,1,1};
char x;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i<7; i++){
    pinMode(Pins[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  x=Serial.read();
  numero(x);
  for(int i = 0; i<7;i++)
    digitalWrite(Pins[i],valores[i]);

}

void numero(char numero){
  switch(numero){
    case '0':
      valores[0]=0;
      valores[1]=0;
      valores[2]=0;
      valores[3]=0;
      valores[4]=0;
      valores[5]=0;
      valores[6]=1;
      break;
    case '1':
      valores[0]=1;
      valores[1]=0;
      valores[2]=0;
      valores[3]=1;
      valores[4]=1;
      valores[5]=1;
      valores[6]=1;
      break;
    case '2':
      valores[0]=0;
      valores[1]=0;
      valores[2]=1;
      valores[3]=0;
      valores[4]=0;
      valores[5]=1;
      valores[6]=0;
      break;
    case '3':
      valores[0]=0;
      valores[1]=0;
      valores[2]=0;
      valores[3]=0;
      valores[4]=1;
      valores[5]=1;
      valores[6]=0;
      break;
    case '4':
      valores[0]=1;
      valores[1]=0;
      valores[2]=0;
      valores[3]=1;
      valores[4]=1;
      valores[5]=0;
      valores[6]=0;
      break;
    case '5':
      valores[0]=0;
      valores[1]=1;
      valores[2]=0;
      valores[3]=0;
      valores[4]=1;
      valores[5]=0;
      valores[6]=0;
      break;
    case '6':
      valores[0]=0;
      valores[1]=1;
      valores[2]=0;
      valores[3]=0;
      valores[4]=0;
      valores[5]=0;
      valores[6]=0;
      break;
    case '7':
      valores[0]=0;
      valores[1]=0;
      valores[2]=0;
      valores[3]=1;
      valores[4]=1;
      valores[5]=1;
      valores[6]=1;
      break;
    case '8':
      valores[0]=0;
      valores[1]=0;
      valores[2]=0;
      valores[3]=0;
      valores[4]=0;
      valores[5]=0;
      valores[6]=0;
      break;
    case '9':
      valores[0]=0;
      valores[1]=0;
      valores[2]=0;
      valores[3]=0;
      valores[4]=1;
      valores[5]=0;
      valores[6]=0;
      break;
    case 'a':
      valores[0]=0;
      valores[1]=0;
      valores[2]=0;
      valores[3]=1;
      valores[4]=0;
      valores[5]=0;
      valores[6]=0;
      break;
    case 'b':
      valores[0]=1;
      valores[1]=1;
      valores[2]=0;
      valores[3]=0;
      valores[4]=0;
      valores[5]=0;
      valores[6]=0;
      break;
    case 'c':
      valores[0]=0;
      valores[1]=1;
      valores[2]=1;
      valores[3]=0;
      valores[4]=0;
      valores[5]=0;
      valores[6]=1;
      break;
    case 'd':
      valores[0]=1;
      valores[1]=0;
      valores[2]=0;
      valores[3]=0;
      valores[4]=0;
      valores[5]=1;
      valores[6]=0;
      break;
    case 'e':
      valores[0]=0;
      valores[1]=1;
      valores[2]=1;
      valores[3]=0;
      valores[4]=0;
      valores[5]=0;
      valores[6]=0;
      break;
    case 'f':
      valores[0]=0;
      valores[1]=1;
      valores[2]=1;
      valores[3]=1;
      valores[4]=0;
      valores[5]=0;
      valores[6]=0;
      break;
  }
}

