int Pins[]={3,4,5,6,7,8,9};
int val[]={1,1,1,1,1,1,1};
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
    digitalWrite(Pins[i],val[i]);

}

void numero(char numero){
  switch(numero){
    case '0':
      val[0]=0;
      val[1]=0;
      val[2]=0;
      val[3]=0;
      val[4]=0;
      val[5]=0;
      val[6]=1;
      break;
    case '1':
      val[0]=1;
      val[1]=0;
      val[2]=0;
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
   
  }
}

