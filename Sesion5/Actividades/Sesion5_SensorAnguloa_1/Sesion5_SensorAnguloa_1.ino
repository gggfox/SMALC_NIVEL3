

// Librerias I2C para controlar el mpu6050
// la libreria MPU6050.h necesita I2Cdev.h, I2Cdev.h necesita Wire.h
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"


// La dirección del MPU6050 puede ser 0x68 o 0x69, dependiendo 
// del estado de AD0. Si no se especifica, 0x68 estará implicito
MPU6050 sensor;

// Valores RAW (sin procesar) del acelerometro y giroscopio en los ejes x,y,z
int16_t accY, accZ, accX;

float accAngle, acXAngle,acYAngle;

void setup() {
  Serial.begin(57600);    //Iniciando puerto serial
  Wire.begin();   
  //Iniciando I2C  
  sensor.initialize();    //Iniciando el sensor

  if (sensor.testConnection()) Serial.println("Sensor iniciado correctamente");
  else Serial.println("Error al iniciar el sensor");
}

void loop() {
  // Leer las aceleraciones y velocidades angulares
  //Se realiza la operacion matemática vista en la presentacion (funciones trigonometricas)
    acYAngle = atan2(accY, accZ)*RAD_TO_DEG;
  acXAngle = atan2(accX, accZ)*RAD_TO_DEG;
  
  //OBTENEMOS ACELERACIONES DEL SENSOR
  accZ = sensor.getAccelerationZ();
  accY = sensor.getAccelerationY();
  accX = sensor.getAccelerationX();

//ANGULOS DE X y Y de rango 0,90
   acXAngle=constrain(acXAngle,0,180);
  acYAngle=constrain(acYAngle,0,180);
  
  if(isnan(acYAngle));
  else{
    Serial.print(" ANGULO  Y   ");
    
    Serial.print(int(acYAngle)); //SOBRE EJE y

    Serial.print(" ANGULO  X   ");
    
    Serial.println(int(acXAngle)); //SOBRE EJE y

    //Utilizamos esto para Imprimir los angulos
    
  }
  delay(100);
}

