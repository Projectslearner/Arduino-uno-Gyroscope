/*
    Code by : Projects_learner
    Project name : Gyroscope using Ardino UNO
    Modified Date : 28-05-2023
    Website : https://projectslearner.com/learn/arduino-uno-accelerometer-gyroscope-module
*/
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup()
 {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  if (mpu.testConnection())
   {
    Serial.println("MPU6050 connection successful");
  } 
  else
   {
    Serial.println("MPU6050 connection failed");
    while (1) 
    {
      // Infinite loop to halt further execution
    }
  }
}

void loop() {
  // Check if MPU-6050 is connected
  if (!mpu.testConnection())
  {
    Serial.println("MPU6050 disconnected");
    delay(1000);  // Wait for a while before rechecking
    checkConnection();
    return;
  }

  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  // Read accelerometer and gyroscope data
  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);

  // Print accelerometer data
  Serial.print("aX: "); Serial.print(ax);
  Serial.print(" | aY: "); Serial.print(ay);
  Serial.print(" | aZ: "); Serial.println(az);
  delay(5000);
  // Print gyroscope data
  Serial.print("gX: "); Serial.print(gx);
  Serial.print(" | gY: "); Serial.print(gy);
  Serial.print(" | gZ: "); Serial.println(gz);

  delay(5000);
}

void checkConnection()
 {
  while (!mpu.testConnection())
  {
    Serial.println("MPU6050 connection failed. Rechecking...");
    delay(1000);  // Wait before rechecking
    mpu.initialize();  // Reinitialize the MPU-6050
  }
  Serial.println("MPU6050 reconnected");
}
