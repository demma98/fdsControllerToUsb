#include <Keyboard.h>
//version for keyboard emulation

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
int up1 = LOW;
int down1 = LOW;
int left1 = LOW;
int right1 = LOW;

void setup() {
  Keyboard.begin();
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

  pressKey(a1, 'c');
  pressKey(b1, 'x');
  pressKey(start1, 'z');
  pressKey(select1, KEY_ESC);
  
  pressKey(up1, KEY_UP_ARROW);
  pressKey(down1, KEY_DOWN_ARROW);
  pressKey(left1, KEY_LEFT_ARROW);
  pressKey(right1, KEY_RIGHT_ARROW);
  //delay(10);
}

void pressKey(int button, int key){
  if(button == HIGH){
    Keyboard.press(key);
  }
  else{
    Keyboard.release(key);
  }
}

void pulse(int pin){
  digitalWrite(pin, HIGH);
  //delay(10);
  digitalWrite(pin, LOW);
}

