// Brushless motor library
// copyright Alexandre Iooss, 2017-2018
// Please see README.txt for license information

#ifndef BRUSHLESS_SERVO_h
#define BRUSHLESS_SERVO_h

#include "Arduino.h"

#define PRECISION 1024  // nb of divisions of one revolution
#define CYCLES 8  // dependent of the motor
#define FLOAT_RESOLUTION 32767  // 32768-1 because 16 bits

class BrushlessServo {
  public:
    BrushlessServo();
	void attach(int pin1, int pin2, int pin3); // Initialization
    void writeOffset(int offset);  // Move to a offset between 0 and PRECISION
    void write(float degree);  // Move to a angle in degree
    void setOutputPower(int power);  // Set a power multiplier between 0 (min) and 1024 (max)

  private:
    int _pin1;
    int _pin2;
    int _pin3;
    int _sinTable[PRECISION];
    float _power;
};

#endif

