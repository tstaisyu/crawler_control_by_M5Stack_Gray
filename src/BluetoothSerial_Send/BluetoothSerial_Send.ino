#include "BluetoothSerial.h"
#include <M5Stack.h>

BluetoothSerial SerialBT;

String MACadd = "94:B9:7E:8C:31:0A";
uint8_t address[6]  = {0x94, 0xB9, 0x7E, 0x8C, 0x31, 0x0A};
//uint8_t address[6]  = {0x00, 0x1D, 0xA5, 0x02, 0xC3, 0x22};
String name = "OBDII";
char *pin = "1234"; //<- standard pin would be provided by default
bool connected;

void setup() {
  Serial.begin(115200);
  //SerialBT.setPin(pin);
  SerialBT.begin("ESP32test", true); 
  //SerialBT.setPin(pin);
  Serial.println("The device started in master mode, make sure remote BT device is on!");
  
  // connect(address) is fast (upto 10 secs max), connect(name) is slow (upto 30 secs max) as it needs
  // to resolve name to address first, but it allows to connect to different devices with the same name.
  // Set CoreDebugLevel to Info to view devices bluetooth address and device names
  //connected = SerialBT.connect(name);
  connected = SerialBT.connect(address);
  
  if(connected) {
    Serial.println("Connected Succesfully!");
  } else {
    while(!SerialBT.connected(10000)) {
      Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app."); 
    }
  }
  // disconnect() may take upto 10 secs max
  if (SerialBT.disconnect()) {
    Serial.println("Disconnected Succesfully!");
  }
  // this would reconnect to the name(will use address, if resolved) or address used with connect(name/address).
  SerialBT.connect();

  M5.begin();

}

void loop() {
  int16_t speed1 = map(analogRead(35), 0, 4095, -255, 255);
  int16_t speed2 = map(analogRead(36), 0, 4095, -255, 255);

  // Serial.println(speed1);
  // Serial.println(speed2);

  if (((-100 < speed1) && (speed1 < 100)) && ((-100 < speed2) && (speed2 < 100))) {
    Serial.println(1);
    SerialBT.write(1);
  }
  else if (((100 <= speed1) && (speed1 <= 255)) && ((-100 < speed2) && (speed2 < 100))) {
    Serial.println(2);
    SerialBT.write(2);
  }
  else if (((-255 <= speed1) && (speed1 <= -100)) && ((-100 < speed2) && (speed2 < 100))) {
    Serial.println(3);
    SerialBT.write(3);
  }
  else if (((-100 < speed1) && (speed1 < 100)) && ((-255 <= speed2) && (speed2 <= -100))) {
    Serial.println(4);
    SerialBT.write(4);
  }
  else if (((100 <= speed1) && (speed1 <= 255)) && ((-255 <= speed2) && (speed2 <= -100))) {
    Serial.println(5);
    SerialBT.write(5);
  }
  else if (((-255 <= speed1) && (speed1 <= -100)) && ((-255 <= speed2) && (speed2 <= -100))) {
    Serial.println(6);
    SerialBT.write(6);
  }
  else if (((-100 < speed1) && (speed1 < 100)) && ((100 <= speed2) && (speed2 <= 255))) {
    Serial.println(7);
    SerialBT.write(7);
  }
  else if (((100 <= speed1) && (speed1 <= 255)) && ((100 <= speed2) && (speed2 <= 255))) {
    Serial.println(8);
    SerialBT.write(8);
  }
  else if (((-255 <= speed1) && (speed1 <= -100)) && ((100 <= speed2) && (speed2 <= 255))) {
    Serial.println(9);
    SerialBT.write(9);
  }
  else {

  }
  delay(20);
}
