#include "Arduino.h"
#include "Motor.h"

int motorPins[4] = { 8, 9, 10, 11 };

Motor motor(motorPins);

void setup() {
    motor.setup();
}

void loop() {
    int revolutions = 1;
    motor.rotate(Motor::ROTATE_RIGHT, revolutions);
    delay(1000);
  
    motor.rotate(Motor::ROTATE_LEFT, revolutions);
    delay(1000);
}
