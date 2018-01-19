//Sensor pins
const int xPin = A0;
const int yPin = A1;
const int zPin = A2;

//Motor pins
const int leftM1  = 9;
const int leftM2  = 8;
const int rightM1 = 7;
const int rightM2 = 6;

//Sensitivity, adjust this for triggering movement
const int xMinSensitivity = 300;
const int xMaxSensitivity = 400;
const int yMinSensitivity = 280;
const int yMaxSensitivity = 370;

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

  Serial.begin(9600);
}

void loop() {

  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  if(xVal < xMinSensitivity) { goForward(); }
  else if(xVal > xMaxSensitivity) { goBackward(); }
  else if(yVal < yMinSensitivity) { goRight(); }
  else if(yVal > yMaxSensitivity) { goLeft(); }
  else  { motorStop();}
}


