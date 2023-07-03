#include "voxhaut_sensor_reader.h"

Adafruit_AHTX0 aht;

void VoxHAUTSensorReader::init() {
    aht.begin();
}

void VoxHAUTSensorReader::read() {
    aht.getEvent(&this->humidity_evt, &this->temp_evt);
}

float VoxHAUTSensorReader::read_temperature() {
    this->read();
    return this->temp_evt.temperature;
}

float VoxHAUTSensorReader::read_humidity() {
    this->read();
    return this->humidity_evt.relative_humidity;
}