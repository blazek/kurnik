#include "Arduino.h"
#include <DS3231.h>
#include "Wire.h"
#include "Motor.h"

DS3231 rtc;
RTCDateTime dateTime;

int motorPins[4] = { 8, 9, 10, 11 };
Motor motor(motorPins);

// This has to be run just once
void setupTime() {
    //rtc.setDateTime(__DATE__, __TIME__);  // compilation time
    rtc.setDateTime(__DATE__, "21:35:00"); // set to CET
}

// Print to serial for verification,
// can be read on Linux using: busybox microcom -t 9600 /dev/ttyUSB0
void printTime() {
    dateTime = rtc.getDateTime();
    Serial.println(rtc.dateFormat("Y-m-d H:i:s", dateTime));
}

void setup() {
    // Start comunication with RTC, 9600 baud
    Serial.begin(9600);
    rtc.begin();
    // setupTime(); // call once
    
    motor.setup();
}

void loop() {
    printTime();
    /*
    int revolutions = 1;
    motor.rotate(Motor::ROTATE_RIGHT, revolutions);
    delay(1000);
  
    motor.rotate(Motor::ROTATE_LEFT, revolutions);
    */
    
    delay(1000);
}
