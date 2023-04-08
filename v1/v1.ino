#include <Joystick.h>

Joystick_ Joystick;

const int powerButton = 5;
const int powerLed = 4;


void setup() {
  Joystick.begin();
  pinMode(powerButton, INPUT);
  pinMode(powerLed, OUTPUT);
}

void loop() {
  if(digitalRead(powerButton) == LOW){
    digitalWrite(powerLed, HIGH);
  }
  else{
    digitalWrite(powerLed, LOW);
  }
  delay(50);
}
