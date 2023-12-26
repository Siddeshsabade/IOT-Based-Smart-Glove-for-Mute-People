/************************************
    scl-----A5   Sda-----A4
*************************************/
#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;
#define adc1 A0
#define adc2 A1
#define adc3 A2
#define adc4 A3
#define ledd 13
float flex2=0,flex1=0,flex3=0,flex4=0;
void setup() 
{
  
 pinMode(ledd,OUTPUT);
 digitalWrite(ledd,LOW);
 Serial.begin(9600 );
 Serial.println("Initialize MPU6050");
 while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
 {
  Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
  delay(500);
 }
 checkSettings();
 
}
void checkSettings()
{
 
 Serial.println();  
 Serial.print(" * Sleep Mode:            ");
 Serial.println(mpu.getSleepEnabled() ? "Enabled" : "Disabled");
 Serial.print(" * Clock Source:          ");
 switch(mpu.getClockSource())
 {
  case MPU6050_CLOCK_KEEP_RESET:     Serial.println("Stops the clock and keeps the timing generator in reset"); break;
  case MPU6050_CLOCK_EXTERNAL_19MHZ: Serial.println("PLL with external 19.2MHz reference"); break;
  case MPU6050_CLOCK_EXTERNAL_32KHZ: Serial.println("PLL with external 32.768kHz reference"); break;
  case MPU6050_CLOCK_PLL_ZGYRO:      Serial.println("PLL with Z axis gyroscope reference"); break;
  case MPU6050_CLOCK_PLL_YGYRO:      Serial.println("PLL with Y axis gyroscope reference"); break;
  case MPU6050_CLOCK_PLL_XGYRO:      Serial.println("PLL with X axis gyroscope reference"); break;
  case MPU6050_CLOCK_INTERNAL_8MHZ:  Serial.println("Internal 8MHz oscillator"); break;
 }
 Serial.print(" * Accelerometer:         ");
  switch(mpu.getRange())
  {
    case MPU6050_RANGE_16G:            Serial.println("+/- 16 g"); break;
    case MPU6050_RANGE_8G:             Serial.println("+/- 8 g"); break;
    case MPU6050_RANGE_4G:             Serial.println("+/- 4 g"); break;
    case MPU6050_RANGE_2G:             Serial.println("+/- 2 g"); break;
  }  
 Serial.print(" * Accelerometer offsets: ");
 Serial.print(mpu.getAccelOffsetX());
 Serial.print(" / ");
 Serial.print(mpu.getAccelOffsetY());
 Serial.print(" / ");
 Serial.println(mpu.getAccelOffsetZ());
 Serial.println();
}

void loop()
{
  //Serial.println(A0);
  flex1=analogRead(adc1);
  flex2=analogRead(adc2);
  flex3=analogRead(adc3);
  flex4=analogRead(adc4);
  delay(10);
  Vector rawAccel = mpu.readRawAccel();
  Vector normAccel = mpu.readNormalizeAccel();
  float v1=(1000/flex1)*5;
  float v2=(1000/flex2)*5;
  float v3=(1000/flex3)*5;
  float v4=(1000/flex4)*5;
  
  //Serial.print(flex1-914.5);
  //Serial.print("-");
 
  if(v1>5.07)
  {
  Serial.println("Food");delay(500);
  }
   else if(v2>5.07)
  {
   Serial.println("Water");delay(500);
  }
   else if(v3>5.07)
  {
   Serial.println("Help");delay(500);
  }
  else  if(v4>5.03)
  {
   Serial.println("OM");delay(2000);
  }
 
  
  
  }
