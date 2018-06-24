/**
 * motor.h - step motor library 
 * 
 * Written for 28BYJ-48 step motor with ULN2003 driver.
 */

#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"

class Motor
{
    public:
        Motor(int pins[4]);
        void setup();
        void rotate(int direction, int revolutions);

        // Direction when looking towards shaft
        static const int ROTATE_LEFT = 0;
        static const int ROTATE_RIGHT = 1;
        
        
    private:
        int pinValue(int pin, int step);
        
        // Output pins
        int * mPins;
        
        static const int STEPS[];
        // Steps pins in counter clockwise direction
        /*
        static constexpr int STEPS[8] = {
            0b0001,
            0b0011,
            0b0010,
            0b0110,
            0b0100,
            0b1100,
            0b1000,
            0b1001
        };
        */
        
        int mStepDelay = 2; // 1 is losing steps?
};

#endif
