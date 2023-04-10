#include <Mouse.h>
//version for keyboard emulation

const int powerLed = 4;
const int powerButton = 2;
const int restButton = 3;

const int data1 = 13;
const int latch = 10;
const int clock1 = 7;

int power = LOW;
int startTemp1 = LOW;
int aTemp1 = LOW;
int bTemp1 = LOW;

int a1 = LOW;
int b1 = LOW;
int select1 = LOW;
int start1 = LOW;
int up1 = LOW;
int down1 = LOW;
int left1 = LOW;
int right1 = LOW;

void setup() {
  Mouse.begin();
  pinMode(powerLed, OUTPUT);
  pinMode(powerButton, INPUT);
  pinMode(restButton, INPUT);
  
  pinMode(clock1, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(data1, INPUT);

  digitalWrite(powerLed, HIGH);
}

void loop() {
  pulse(latch);

  startTemp1 = start1;
  aTemp1 = a1;
  bTemp1 = b1;

  a1 = !digitalRead(data1);
  pulse(clock1);
  b1 = !digitalRead(data1);
  pulse(clock1);
  select1 = !digitalRead(data1);
  pulse(clock1);
  start1 = !digitalRead(data1);
  pulse(clock1);
  up1 = !digitalRead(data1);
  pulse(clock1);
  down1 = !digitalRead(data1);
  pulse(clock1);
  left1 = !digitalRead(data1);
  pulse(clock1);
  right1 = !digitalRead(data1);


  if(power == HIGH){
    if(start1 == HIGH && startTemp1 == LOW){
      power = LOW;
    }
    if(a1 == HIGH && aTemp1 == LOW){
      Mouse.press(MOUSE_RIGHT);
    }
    if(a1 == LOW && aTemp1 == HIGH){
      Mouse.release(MOUSE_RIGHT);
    }
    if(b1 == HIGH && bTemp1 == LOW){
      Mouse.press(MOUSE_LEFT);
    }
    if(b1 == LOW && bTemp1 == HIGH){
      Mouse.release(MOUSE_LEFT);
    }
    if(up1 == HIGH){
      Mouse.move(0, -1, 0);
    }
    if(down1 == HIGH){
      Mouse.move(0, 1, 0);
    }
    if(left1 == HIGH){
      Mouse.move(-1, 0, 0);
    }
    if(right1 == HIGH){
      Mouse.move(1, 0, 0);
    }
  }
  else{
    if(start1 == HIGH && startTemp1 == LOW){
      power = HIGH;
    }
  }
  
  //delay(10);
}


void pulse(int pin){
  digitalWrite(pin, HIGH);
  //delay(10);
  digitalWrite(pin, LOW);
}

