#include <voxhaut_motor_driver.h>

void VoxHAUTMotorDriver::init() {
  pinMode(this->_pwm_a, OUTPUT);
  pinMode(this->_pwm_b, OUTPUT);
  pinMode(this->_dma, OUTPUT);
  pinMode(this->_dmb, OUTPUT);
}

void VoxHAUTMotorDriver::drive_left() {
    digitalWrite(this->_pwm_a, 255);
    digitalWrite(this->_pwm_b, 255);

    digitalWrite(this->_dma, HIGH);
    digitalWrite(this->_dmb, LOW);
}

void VoxHAUTMotorDriver::drive_right() {
    digitalWrite(this->_pwm_a, 255);
    digitalWrite(this->_pwm_b, 255);

    digitalWrite(this->_dma, LOW);
    digitalWrite(this->_dmb, HIGH);
}

void VoxHAUTMotorDriver::drive_forward() {
    digitalWrite(this->_pwm_a, 255);
    digitalWrite(this->_pwm_b, 255);

    digitalWrite(this->_dma, HIGH);
    digitalWrite(this->_dmb, HIGH);
}

void VoxHAUTMotorDriver::stop() {
    digitalWrite(this->_pwm_a, 0);
    digitalWrite(this->_pwm_b, 0);

    digitalWrite(this->_dma, LOW);
    digitalWrite(this->_dmb, LOW);
}
