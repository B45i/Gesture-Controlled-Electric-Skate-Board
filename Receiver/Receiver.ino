//Data pin to arduino 11
#include <RH_ASK.h>
#include <SPI.h>

//Motor pins
const int leftM1  = 9;
const int leftM2  = 8;
const int rightM1 = 7;
const int rightM2 = 6;

const int enLeft = 10;
const int enRight = 5;

RH_ASK driver;


void motorStop() {
  //Serial.println("Stopping...");
  digitalWrite(leftM1, LOW);
  digitalWrite(leftM2, LOW);
  digitalWrite(rightM1, LOW);
  digitalWrite(rightM2, LOW);
}


void goForward() {
  motorStop();
  Serial.println("Going FWD");
  digitalWrite(leftM1, HIGH);
  digitalWrite(leftM2, LOW);
  digitalWrite(rightM1, HIGH);
  digitalWrite(rightM2, LOW);
}

void goLeft() {
  motorStop();
  Serial.println("Going Left");
  digitalWrite(rightM1, HIGH);
  digitalWrite(rightM2, LOW);
}

void goRight() {
  motorStop();
  Serial.println("Going Right");
  digitalWrite(leftM1, HIGH);
  digitalWrite(leftM2, LOW);
}

void goBackward() {
  motorStop();
  Serial.println("Going BWD");
  digitalWrite(leftM1, LOW);
  digitalWrite(leftM2, HIGH);
  digitalWrite(rightM1, LOW);
  digitalWrite(rightM2, HIGH);
}

void setup() {

  pinMode(leftM1, OUTPUT);
  pinMode(leftM2, OUTPUT);
  pinMode(rightM1, OUTPUT);
  pinMode(rightM2, OUTPUT);

  pinMode(enRight, OUTPUT);
  pinMode(enLeft, OUTPUT);
  digitalWrite(enLeft, HIGH);
  digitalWrite(enRight, HIGH);

  Serial.begin(9600);

  if (!driver.init())
    Serial.println("init failed");
}

void loop() {
  uint8_t buf[1];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) {
    int i;

    if(buf[0] == 0x66) {
      goForward();
    }
    else if(buf[0] == 0x62) {
      goBackward();
    }
    else if(buf[0] == 0x72) {
      goLeft();
    }
    else if(buf[0] == 0x6c) {
      goRight();
    }
    else {
      motorStop();
    }
  }
}

