#include <Arduino.h>

#include "voxhaut_config.h"
#include "voxhaut_sensor_reader.h"
#include "voxhaut_wifi_ap.h"

VoxHAUTWiFiAP ap_server;
VoxHAUTSensorReader sensor_reader;

void setup() {
    Serial.begin(115200);
    sensor_reader.init();

    ap_server.init();
    ap_server.begin();
}

void loop() {
    ap_server.loop();
}