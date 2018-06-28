#include <Arduino.h>
#include "Motor.h"

// Steps pins in counter clockwise direction
const int Motor::STEPS[8] = {
    0b0001,
    0b0011,
    0b0010,
    0b0110,
    0b0100,
    0b1100,
    0b1000,
    0b1001
};

Motor::Motor(int pins[4])
{
    mPins = pins;
}

void Motor::setup() {
    for(int i = 0; i < 4; i++) {
        pinMode(mPins[i], OUTPUT);
    }
}

// pin: 0-3
// returns 1 (HIGH) or 0 (LOW)
int Motor::pinValue(int pin, int step) {
    int pinMask[] = {
        0b0001,
        0b0010,
        0b0100,
        0b1000
    };
    int value = pinMask[pin] & step;
    return value;
}

/** 
 * Revolution of output shaft
 * @param direction: ROTATE_RIGHT or  ROTATE_LEFT
 * @param number of step cycles (8 steps = cycle), 360 degrees = 512 cycles
 */ 
void Motor::rotateStepCycles(int direction, int stepsCycles) {
    for(int c = 0; c < stepsCycles; c++) {
        for(int step = 0; step < 8; step++) {
            int directionStep;
            if ( direction == ROTATE_RIGHT ) {
                directionStep = 7-step;
            } else {
                directionStep = step;
            }
            for(int pin = 0; pin < 4; pin++) {
                int value = pinValue(pin, STEPS[directionStep]);
                digitalWrite(mPins[pin], value);
            }
            delay(mStepDelay);
        }
    }
    clear();
}

/** 
 * Revolution of output shaft
 * @param direction: ROTATE_RIGHT or  ROTATE_LEFT
 * @param number of revolutions
 */ 
void Motor::rotate(int direction, int revolutions) {
    for (int r = 0; r < revolutions; r++ ) {
        // 360 degrees = 512 cycles
        for(int c = 0; c < 512; c++) {
            for(int step = 0; step < 8; step++) {
                int directionStep;
                if ( direction == ROTATE_RIGHT ) {
                    directionStep = 7-step;
                } else {
                    directionStep = step;
                }
                for(int pin = 0; pin < 4; pin++) {
                    int value = pinValue(pin, STEPS[directionStep]);
                    digitalWrite(mPins[pin], value);
                }
                delay(mStepDelay);
            }
        }
    }
    clear();
}

void Motor::clear() {
    for(int pin = 0; pin < 4; pin++) {
        digitalWrite(mPins[pin], LOW);
    }
}



