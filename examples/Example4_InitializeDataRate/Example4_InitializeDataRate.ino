/******************************************************************************
  Reading full scale of acceleration and customizing data rate from the MMA8452Q
  SFE_MMA8452Q Library Basic Example Sketch
  Jim Lindblom @ SparkFun Electronics
  Original Creation Date: June 3, 2014
  https://github.com/sparkfun/MMA8452_Accelerometer

  This sketch uses the SparkFun_MMA8452Q library to initialize the
  accelerometer, and stream values from it.

  Hardware hookup:
  Arduino --------------- MMA8452Q Breakout
    3.3V  ---------------     3.3V
    GND   ---------------     GND
  SDA (A4) --\/330 Ohm\/--    SDA
  SCL (A5) --\/330 Ohm\/--    SCL

  The MMA8452Q is a 3.3V max sensor, so you'll need to do some
  level-shifting between the Arduino and the breakout. Series
  resistors on the SDA and SCL lines should do the trick.

  Development environment specifics:
  IDE: Arduino 1.0.5
  Hardware Platform: Arduino Uno

  **Updated for Arduino 1.6.4 5/2015**

  This code is beerware; if you see me (or any other SparkFun employee) at the
  local, and you've found our code helpful, please buy us a round!

  Distributed as-is; no warranty is given.
******************************************************************************/
#include <Wire.h>                 // Must include Wire library for I2C
#include "SparkFun_MMA8452Q.h"    // Includes the SFE_MMA8452Q library

MMA8452Q accel;               // create instance of the MMA8452 class

void setup() {
  Serial.begin(9600);
  Serial.println("MMA8452Q Test Code!");

  /* Initialize with FULL-SCALE and DATA RATE setting. If you
     want control over how fast your accelerometer produces
     data use one of the following options in the second param:
     ODR_800, ODR_400, ODR_200, ODR_100, ODR_50, ODR_12,
     ODR_6, or ODR_1. 
     Sets to 800, 400, 200, 100, 50, 12.5, 6.25, or 1.56 Hz 
     respectively
  */
  accel.init(SCALE_8G, ODR_6);               

  // WRITE A FUNCTION TO CHECK IS BOARD IS CONNECTED
}

void loop() {
  if (accel.available()) {    // Wait for new data from accelerometer
    accel.read();             // Read new variables

    printCalculatedAccels();  // Acceleration of x, y, and z directions in g units

    Serial.println();
  }
}

void printCalculatedAccels() {
  Serial.print(accel.cx, 3);
  Serial.print("\t");
  Serial.print(accel.cy, 3);
  Serial.print("\t");
  Serial.print(accel.cz, 3);
  Serial.print("\t");
}

