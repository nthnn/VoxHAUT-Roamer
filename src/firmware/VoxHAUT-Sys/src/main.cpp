#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "voxhaut_config.h"
#include "voxhaut_sensor_reader.h"

ESP8266WebServer server(VOXHAUT_SERVER_PORT);
VoxHAUTSensorReader sensor_reader;

void setup() {
    Serial.begin(115200);
    sensor_reader.init();
}

void loop() {
}