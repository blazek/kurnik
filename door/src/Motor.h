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
        void rotateStepCycles(int direction, int stepsCycles);
        void rotate(int direction, int revolutions);

        // Direction when looking towards shaft
        static const int ROTATE_LEFT = 0;
        static const int ROTATE_RIGHT = 1;
        
        static const int STEP_CYCLES_PER_REVOLUTION = 512;
        
        
    private:
        int pinValue(int pin, int step);
        void clear();
        
        // Output pins
        int * mPins;
        
        static const int STEPS[];

        
        // Delay in ms, each 1 ms means approximatelly 1*8*512*10 = 40960ms = 40s longer open/close
        // 1 is losing steps or motor is even stopping
        // 2 seems not losing steps
        int mStepDelay = 2; 
};

#endif
