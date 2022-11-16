#include <M5Stack.h>
#include "CytronMotorDriver.h"

CytronMD motor(PWM_DIR, 25, 32);

void setup() {

}

void loop() {
  motor.setSpeed(128);  // Run forward at 50% speed.
  delay(1000);
  
  motor.setSpeed(255);  // Run forward at full speed.
  delay(1000);

  motor.setSpeed(0);    // Stop.
  delay(1000);

  motor.setSpeed(-128);  // Run backward at 50% speed.
  delay(1000);
  
  motor.setSpeed(-255);  // Run backward at full speed.
  delay(1000);

  motor.setSpeed(0);    // Stop.
  delay(1000);
}
