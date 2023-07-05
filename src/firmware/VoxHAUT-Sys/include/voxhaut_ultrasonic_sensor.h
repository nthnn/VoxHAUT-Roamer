#ifndef VOXHAUT_ULTRASONIC_SENSOR_H
#define VOXHAUT_ULTRASONIC_SENSOR_H

#include <Arduino.h>

class VoxHAUTUltrasonicSensor {
    public:
    VoxHAUTUltrasonicSensor(uint16_t trig_pin, uint16_t echo_pin):
        _trig_pin(trig_pin),
        _echo_pin(echo_pin) {
        pinMode(this->_trig_pin, OUTPUT);
        pinMode(this->_echo_pin, INPUT);
    }

    int get_distance();

    private:
    uint16_t _trig_pin, _echo_pin;
};

#endif