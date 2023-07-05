#include "voxhaut_ultrasonic_sensor.h"

int VoxHAUTUltrasonicSensor::get_distance() {
    int duration = 0;

    digitalWrite(this->_trig_pin, LOW);
    delayMicroseconds(2);

    digitalWrite(this->_trig_pin, HIGH);
    delayMicroseconds(10);

    digitalWrite(this->_trig_pin, LOW);
    return pulseIn(this->_echo_pin, HIGH) * 0.034 / 2;
}
