#include <Servo.h>

// Librerias I2C para controlar el mpu6050
// la libreria MPU6050.h necesita I2Cdev.h, I2Cdev.h necesita Wire.h
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"


// La dirección del MPU6050 puede ser 0x68 o 0x69, dependiendo 
// del estado de AD0. Si no se especifica, 0x68 estará implicito
MPU6050 sensor;
Servo servo,servo2;

// Valores RAW (sin procesar) del acelerometro y giroscopio en los ejes x,y,z
int16_t accY, accZ, accX;
int ax, ay, az;
int gx, gy, gz;

long tiempo_prev;
float dt;
float ang_x, ang_y;
float ang_x_prev, ang_y_prev;
float accAngle, acXAngle,acYAngle;
float angxFINAL;
void setup() {
  Serial.begin(57600);    //Iniciando puerto serial
  Wire.begin();   
  servo.attach(6);
  servo2.attach(5);
  //Iniciando I2C  
  sensor.initialize();    //Iniciando el sensor

  if (sensor.testConnection()) Serial.println("Sensor iniciado correctamente");
  else Serial.println("Error al iniciar el sensor");
}

void loop() {
  // Leer las aceleraciones y velocidades angulares
  sensor.getAcceleration(&ax, &ay, &az);
  sensor.getRotation(&gx, &gy, &gz);
    acYAngle = atan2(accY, accZ)*RAD_TO_DEG;
  acXAngle = atan2(accX, accZ)*RAD_TO_DEG;
  
  dt = (millis()-tiempo_prev)/1000.0;
  tiempo_prev=millis();
  
  //Calcular los ángulos con acelerometro
  float accel_ang_x=atan(ay/sqrt(pow(ax,2) + pow(az,2)))*(180.0/3.14);
  float accel_ang_y=atan(-ax/sqrt(pow(ay,2) + pow(az,2)))*(180.0/3.14);
  
  //Calcular angulo de rotación con giroscopio y filtro complemento  
  ang_x = 0.98*(ang_x_prev+(gx/131)*dt) + 0.02*accel_ang_x;
  ang_y = 0.98*(ang_y_prev+(gy/131)*dt) + 0.02*accel_ang_y;
  
  
  ang_x_prev=ang_x;
  ang_y_prev=ang_y;

  //Mostrar los angulos separadas por un [tab]

  Serial.print("Rotacion en X:  ");
  Serial.print(ang_x); 
  Serial.print("tRotacion en Y: ");
  Serial.print(ang_y);

//accZ = mpu.getAccelerationZ();
  accY = sensor.getAccelerationY();
  accX = sensor.getAccelerationX();

//ANGULOS DE X y Y de rango 0,90
   acXAngle=constrain(acXAngle,0,90);
  acYAngle=constrain(acYAngle,0,90);
  angxFINAL=map(acYAngle,0,90,0,90);
  if(isnan(acYAngle));
  else{
    Serial.print(" INCLINACIÓN  Y   ");
    
    Serial.print(acYAngle); //SOBRE EJE y

    Serial.print(" INCLINACIÓN  X   ");
    
    Serial.println(int(acXAngle)); //SOBRE EJE y
    servo.write(acYAngle);
    servo2.write(acXAngle);
  }
  delay(10);
}

