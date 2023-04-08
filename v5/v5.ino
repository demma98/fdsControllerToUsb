#include <Joystick.h>
 //incomplete for detecting throttle n shit
Joystick_ Joystick(0x03, JOYSTICK_TYPE_JOYSTICK
,  6, 0,  true, true, false, false, false
, false, false, false, false, false, false);

const int powerLed = 4;
const int powerButton = 2;
const int restButton = 3;

const int data1 = 13;
const int latch = 10;
const int clock1 = 7;

int aTemp1[] = {LOW, LOW, LOW, LOW};
int bTemp1[] = {LOW, LOW, LOW, LOW};
int aAcm1 = 0;
int bAcm1 = 0;
int aChange1 = LOW;
int bChange1 = LOW;
int a1 = LOW;
int b1 = LOW;
int aT1 = LOW;
int bT1 = LOW;
int select1 = LOW;
int start1 = LOW;
int up1 = LOW;
int down1 = LOW;
int left1 = LOW;
int right1 = LOW;

int x1 = 1;
int y1 = 1;

void pulse(int pin){
  digitalWrite(pin, HIGH);
  //delay(10);
  digitalWrite(pin, LOW);
}

void setup() {
  Joystick.begin();
  pinMode(powerLed, OUTPUT);
  pinMode(powerButton, INPUT);
  pinMode(restButton, INPUT);
  
  pinMode(clock1, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(data1, INPUT);

  Joystick.setXAxisRange(0, 2);
  Joystick.setYAxisRange(0, 2);

  Joystick.setXAxis(1);
  Joystick.setYAxis(1);

  digitalWrite(powerLed, HIGH);
}

void loop() {
  pulse(latch);

  aTemp1[0] =  !digitalRead(data1);
  pulse(clock1);
  bTemp1[0] =  !digitalRead(data1);
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

  Joystick.setButton(0, select1);
  Joystick.setButton(1, start1);
  Joystick.setButton(2, b1);
  Joystick.setButton(3, a1);
  Joystick.setButton(4, bT1);
  Joystick.setButton(5, aT1);

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
  
  Joystick.setXAxis(x1);
  Joystick.setYAxis(y1);

  //delay(10);
}

