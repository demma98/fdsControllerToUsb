#include <Joystick.h>

Joystick_ Joystick;

const int powerLed = 4;
const int powerButton = 2;
const int restButton = 3;

const int data1 = 13;
const int latch = 10;
const int clock1 = 7;

int a1 = LOW;
int b1 = LOW;
int select1 = LOW;
int start1 = LOW;

void setup() {
  Joystick.begin();
  pinMode(powerLed, OUTPUT);
  pinMode(powerButton, INPUT);
  pinMode(restButton, INPUT);
  
  pinMode(clock1, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(data1, INPUT);

  
  digitalWrite(clock1, HIGH);
}

void loop() {
  pulse(latch);

  a1 = digitalRead(data1);
  pulse(clock1);
  b1 = digitalRead(data1);

  if(a1 == HIGH){
    digitalWrite(powerLed, HIGH);
  }
  else{
    digitalWrite(powerLed, LOW);
  }
  delay(50);
}

void pulse(int pin){
  digitalWrite(pin, HIGH);
  delay(20);
  digitalWrite(pin, LOW);
}

