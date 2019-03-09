int arr[7]={2,3,4,5,6,7,8};
int valores[7]={1,1,1,1,1,1,1};


void setup() {
  // put your setup code here, to run once:
for(int i =0; i<7;i++)
pinMode (arr[i],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for (int j=0;j<6;j++){
numero(j);
for (int i=0; i<7;i++)
digitalWrite (arr[i],valores[i]);
delay(1000);
}
}

void numero (int numero){

switch (numero){
  case 0:
  valores[0]=0;
  valores[1]=0;
  valores[2]=0;
  valores[3]=0;
  valores[4]=0;
  valores[5]=0;
  valores[6]=1;
  break;
    case 1:
  valores[0]=1;
  valores[1]=0;
  valores[2]=0;
  valores[3]=1;
  valores[4]=1;
  valores[5]=1;
  valores[6]=1;
  break;
    case 2:
  valores[0]=0;
  valores[1]=0;
  valores[2]=1;
  valores[3]=0;
  valores[4]=0;
  valores[5]=1;
  valores[6]=0;
  break;
    case 3:
  valores[0]=0;
  valores[1]=0;
  valores[2]=0;
  valores[3]=0;
  valores[4]=1;
  valores[5]=1;
  valores[6]=0;
  break;
    case 4:
  valores[0]=1;
  valores[1]=0;
  valores[2]=0;
  valores[3]=1;
  valores[4]=1;
  valores[5]=0;
  valores[6]=0;
  break;
    case 5:
  valores[0]=0;
  valores[1]=1;
  valores[2]=0;
  valores[3]=0;
  valores[4]=1;
  valores[5]=0;
  valores[6]=0;
  break;
}
}
