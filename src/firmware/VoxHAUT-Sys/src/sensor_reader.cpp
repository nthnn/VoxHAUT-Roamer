#include "sensor_reader.h"

Adafruit_AHTX0 aht;

void SensorReader::init() {
    aht.begin();
}

void SensorReader::read() {
    aht.getEvent(&this->humidity_evt, &this->temp_evt);
}

float SensorReader::read_temperature() {
    this->read();
    return this->temp_evt.temperature;
}

float SensorReader::read_humidity() {
    this->read();
    return this->humidity_evt.relative_humidity;
}