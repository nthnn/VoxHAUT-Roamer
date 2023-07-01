#ifndef SENSOR_READER_H
#define SENSOR_READER_H

#include <Arduino.h>
#include <Adafruit_AHTX0.h>

class SensorReader {
    public:
    void init();

    float read_temperature();
    float read_humidity();

    private:
    sensors_event_t temp_evt, humidity_evt;

    void read();
};

#endif