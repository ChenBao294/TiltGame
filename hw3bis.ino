/* Graph I2C Accelerometer On RedBear Duo over Serial Port
 * Adafruit Part 2809 LIS3DH - http://adafru.it/2809
 * This example shows how to program I2C manually
 * I2C Pins SDA1==D0, SCL1 == D1
 * Default address: 0x18
 */
 
// do not use the cloud functions - assume programming through Arduino IDE
#if defined(ARDUINO) 
SYSTEM_MODE(MANUAL); 
#endif

#include "Adafruit_LIS3DH.h"
#include "Adafruit_Sensor.h"

// I2C
Adafruit_LIS3DH lis = Adafruit_LIS3DH();


void setup(void) {
  
  Serial.begin(9600);
  Serial.println("LIS3DH test!");
  
  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1)
      Serial.println("Couldn't start");
      delay(1000);
  }
  Serial.println("LIS3DH found!");
  
  lis.setRange(LIS3DH_RANGE_2_G);   // 2, 4, 8 or 16 G!

}


void loop() {
  lis.read();      // get X Y and Z data at once
  sensors_event_t event; 
  lis.getEvent(&event);

  //send through serial transmission the values of the accelerations along the x and y axes in the form "x(xvalue)y(yvalue)"
  Serial.print("x");
  Serial.print(event.orientation.x);
  Serial.print("y");
  Serial.print(event.orientation.y);
  Serial.println("");
  delay(20);

  
}
