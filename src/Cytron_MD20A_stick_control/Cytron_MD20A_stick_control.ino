#include <M5Stack.h>
#include "CytronMotorDriver.h"

const int PWM_R = 25;
const int DIR_R = 2;

const int PWM_L = 26;
const int DIR_L = 5;

CytronMD motorR(PWM_DIR, 25, 2);
CytronMD motorL(PWM_DIR, 26, 5);

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(2);
}

void loop() {
  int16_t speed1 = map(analogRead(35), 1275, 4095, -255, 255);
  int16_t speed2 = map(analogRead(36), 1275, 4095, -255, 255);
 
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("R: ");
  M5.Lcd.print(speed1, DEC);
  M5.Lcd.println("      ");
  M5.Lcd.print("L: ");
  M5.Lcd.print(speed2, DEC);
  M5.Lcd.println("      ");
  
  motorR.setSpeed(speed1);
  motorL.setSpeed(speed2);
  delay(20);
  
}
