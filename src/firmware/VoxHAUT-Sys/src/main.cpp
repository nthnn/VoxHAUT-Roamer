#include <Arduino.h>

#include "voxhaut_config.h"
#include "voxhaut_emotion_renderer.h"
#include "voxhaut_sensor_reader.h"
#include "voxhaut_wifi_ap.h"

VoxHAUTWiFiAP ap_server;
VoxHAUTEmotionRenderer emotion_renderer;
VoxHAUTSensorReader sensor_reader;

void httpCheckHandler();

void setup() {
    Serial.begin(115200);

    emotion_renderer.init();
    sensor_reader.init();
    ap_server.init();

    ap_server.handle("check", httpCheckHandler);
    ap_server.begin();
}

void loop() {
    ap_server.loop();
}

void httpCheckHandler() {
    ap_server.respond(RESP(200, "text/plain", "OK"));
}