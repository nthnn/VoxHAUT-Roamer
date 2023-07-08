#ifndef VOXHAUT_MOTOR_DRIVER_H
#define VOXHAUT_MOTOR_DRIVER_H

#include <Arduino.h>

class VoxHAUTMotorDriver {
    public: 
    VoxHAUTMotorDriver(uint16_t pwm_a, uint16_t pwm_b, uint16_t dma, uint16_t dmb):
        _pwm_a(pwm_a), _pwm_b(pwm_b), _dma(dma), _dmb(dmb) { }

    void init();

    void drive_left();
    void drive_right();
    void drive_forward();
    void stop();

    private:
    uint16_t _pwm_a, _pwm_b, _dma, _dmb;
};

#endif