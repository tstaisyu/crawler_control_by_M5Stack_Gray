#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

#include "CytronMotorDriver.h"

const int PWM_R = 25;
const int DIR_R = 19;

const int PWM_L = 26;
const int DIR_L = 23;

CytronMD motorR(PWM_DIR, 25, 19);
CytronMD motorL(PWM_DIR, 26, 23);

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

}

void loop() {
  if (SerialBT.available()) {
    int16_t speed1 = SerialBT.read();
    if (speed1 == 1) {
      Serial.println(1);
      motorR.setSpeed(0);
      motorL.setSpeed(0);
    }  
    if (speed1 == 2) {
      Serial.println(2);
      motorR.setSpeed(255);
      motorL.setSpeed(0);
    }  
    if (speed1 == 3) {
      Serial.println(3);
      motorR.setSpeed(-255);
      motorL.setSpeed(0);
    }  
    if (speed1 == 4) {
      Serial.println(4);
      motorR.setSpeed(0);
      motorL.setSpeed(255);
    }  
    if (speed1 == 5) {
      Serial.println(5);
      motorR.setSpeed(255);
      motorL.setSpeed(255);
    }  
    if (speed1 == 6) {
      Serial.println(6);
      motorR.setSpeed(-255);
      motorL.setSpeed(255);
    }  
    if (speed1 == 7) {
      Serial.println(7);
      motorR.setSpeed(0);
      motorL.setSpeed(-255);
    }  
    if (speed1 == 8) {
      Serial.println(8);
      motorR.setSpeed(255);
      motorL.setSpeed(-255);
    }  
    if (speed1 == 9) {
      Serial.println(9);
      motorR.setSpeed(-255);
      motorL.setSpeed(-255);
    }  
  }
  delay(20);
}
