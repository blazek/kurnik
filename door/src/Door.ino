#include <Arduino.h>
#include <DS3231.h>
#include <Wire.h>
#include "Motor.h"
#include "Sun.h"
#include "Utils.h"

DS3231 rtc;

int motorPins[4] = { 8, 9, 10, 11 };
Motor motor(motorPins);

// Number of revolutions to fully open the door
short OPEN_REVOLUTIONS = 7;
// How many times open status is written to memory per revolution
// It should be a reasonable number 360 degrees = 512 cycles
short UNIT_PER_REVOLUTION = 4;

int ADJUSTMENT_DELAY = 60; // seconds

bool addjustment = false;

void setup() {
    // Start comunication with RTC, 9600 baud
    Serial.begin(9600);
    rtc.begin();
    
    // call once when a battery was inserted to RTC
    // rtc.setDateTime(__DATE__, "21:35:00"); // set CET
    
    // call to reset open status
    // EEPROMWriteOpen(0);
    
    // After reset during the day, close the door and left it close for a while for addjustment
    
    boolean isDay = getIsDay(rtc);
    if ( isDay ) {
        addjustment = true;
    }
    
    motor.setup();
}

void loop() {
    printTime(rtc);
    boolean isDay = getIsDay(rtc);
    Serial.println("isDay = " + String(isDay));
    
    short openUnits = EEPROMReadOpen();
    short maxUnits = OPEN_REVOLUTIONS * UNIT_PER_REVOLUTION;
    Serial.println("openUnits = " + String(openUnits) + " maxUnits = " + String(maxUnits));
    int stepCycles = Motor::STEP_CYCLES_PER_REVOLUTION / UNIT_PER_REVOLUTION;
    if ( (!isDay && openUnits > 0) || addjustment ) {
        Serial.println("close openUnits = " + String(openUnits) + " addjustment = " + addjustment);
        for ( int i = openUnits; i > 0; i-- ) {
            motor.rotateStepCycles(Motor::ROTATE_LEFT, stepCycles);
            openUnits--;
            Serial.println("write openUnits = " + String(openUnits));
            EEPROMWriteOpen(openUnits);
            Serial.println("open = " + String(EEPROMReadOpen()));
        }
        
        // clear adjustment mode 
        if ( addjustment ) {
            for ( int s = ADJUSTMENT_DELAY; s > 0; s-- ) {
                Serial.println("waiting for adjustment " + String(s) + " / " + String(ADJUSTMENT_DELAY) + " s");
                printTime(rtc);
                delay(1000);
            }
            addjustment = false;
        }
    } else if ( isDay && openUnits < maxUnits ) {
        int missingUnits = maxUnits-openUnits;
        Serial.println("open missingUnits = " + String(missingUnits));
        for ( int i = 0; i < missingUnits; i++ ) {
            motor.rotateStepCycles(Motor::ROTATE_RIGHT, stepCycles);
            openUnits++;
            Serial.println("write openUnits = " + String(openUnits));
            EEPROMWriteOpen(openUnits);
            Serial.println("open = " + String(EEPROMReadOpen()));

        }
    } 
    delay(1000);
}
