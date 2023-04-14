#include <Joystick.h>

Joystick_ Joystick1(0x03, JOYSTICK_TYPE_JOYSTICK
,  4, 0,  true, true, false, false, false
, false, false, false, false, false, false);

Joystick_ Joystick2(0x04, JOYSTICK_TYPE_JOYSTICK
,  4, 0,  true, true, false, false, false
, false, false, false, false, false, false);

const int powerLed = 4;
const int powerButton = 2;
const int restButton = 3;

const int data1 = 13;
const int latch = 10;
const int clock1 = 7;

const int data2 = 11;
const int clock2 = 9;

int a1 = LOW;
int b1 = LOW;
int select1 = LOW;
int start1 = LOW;
int up1 = LOW;
int down1 = LOW;
int left1 = LOW;
int right1 = LOW;

int x1 = 1;
int y1 = 1;

int a2 = LOW;
int b2 = LOW;
int select2 = LOW;
int start2 = LOW;
int up2 = LOW;
int down2 = LOW;
int left2 = LOW;
int right2 = LOW;

int x2 = 1;
int y2 = 1;

void setup() {
  Joystick1.begin();
  Joystick2.begin();
  pinMode(powerLed, OUTPUT);
  pinMode(powerButton, INPUT);
  pinMode(restButton, INPUT);
  
  pinMode(clock1, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(data1, INPUT);
  pinMode(clock2, OUTPUT);
  pinMode(data2, INPUT);

  Joystick1.setXAxisRange(0, 2);
  Joystick1.setYAxisRange(0, 2);

  Joystick1.setXAxis(1);
  Joystick1.setYAxis(1);
  
  Joystick2.setXAxisRange(0, 2);
  Joystick2.setYAxisRange(0, 2);

  Joystick2.setXAxis(1);
  Joystick2.setYAxis(1);

  digitalWrite(powerLed, HIGH);
}

void loop() {
  pulse(latch);

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

  Joystick1.setButton(0, select1);
  Joystick1.setButton(1, start1);
  Joystick1.setButton(2, b1);
  Joystick1.setButton(3, a1);

  x1 = 1;
  y1 = 1;
  if(up1 == HIGH){
    y1--;
  }
  if(down1 == HIGH){
    y1++;
  }
  if(left1 == HIGH){
    x1--;
  }
  if(right1 == HIGH){
    x1++;
  }
  
  Joystick1.setXAxis(x1);
  Joystick1.setYAxis(y1);
  
  //player 2
  
  pulse(latch);
  a2 = !digitalRead(data2);
  pulse(clock2);
  b2 = !digitalRead(data2);
  pulse(clock2);
  select2 = !digitalRead(data2);
  pulse(clock2);
  start2 = !digitalRead(data2);
  pulse(clock2);
  up2 = !digitalRead(data2);
  pulse(clock2);
  down2 = !digitalRead(data2);
  pulse(clock2);
  left2 = !digitalRead(data2);
  pulse(clock2);
  right2 = !digitalRead(data2);

  Joystick2.setButton(0, select2);
  Joystick2.setButton(1, start2);
  Joystick2.setButton(2, b2);
  Joystick2.setButton(3, a2);

  x2 = 1;
  y2 = 1;
  if(up2 == HIGH){
    y2--;
  }
  if(down2 == HIGH){
    y2++;
  }
  if(left2 == HIGH){
    x2--;
  }
  if(right2 == HIGH){
    x2++;
  }
  
  Joystick2.setXAxis(x2);
  Joystick2.setYAxis(y2);

  //delay(10);
}

void pulse(int pin){
  digitalWrite(pin, HIGH);
  //delay(10);
  digitalWrite(pin, LOW);
}

