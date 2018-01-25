//data pin to arduino 12
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

//Sensor pins
const int xPin = A0;
const int yPin = A1;
const int zPin = A2;

//Sensitivity, adjust this for triggering movement
const int xMinSensitivity = 300;
const int xMaxSensitivity = 400;
const int yMinSensitivity = 280;
const int yMaxSensitivity = 370;

void setup() {
  Serial.begin(9600);
  if (!driver.init())
     Serial.println("init failed");
}

void loop() {

  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  char *msg = "s";

  if(xVal < xMinSensitivity) { msg = "f"; }
  else if(xVal > xMaxSensitivity) { msg = "b"; }
  else if(yVal < yMinSensitivity) { msg = "l"; }
  else if(yVal > yMaxSensitivity) { msg = "r"; }
  //else  { motorStop();}

  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
}

