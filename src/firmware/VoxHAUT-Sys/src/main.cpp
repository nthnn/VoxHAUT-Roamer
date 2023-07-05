#include <Arduino.h>

#include "voxhaut_config.h"
#include "voxhaut_emotion_renderer.h"
#include "voxhaut_sensor_reader.h"
#include "voxhaut_wifi_ap.h"
#include "voxhaut_voice_player.h"
#include "voxhaut_voice_player_defs.h"

VoxHAUTWiFiAP ap_server;
VoxHAUTEmotionRenderer emotion_renderer;
VoxHAUTSensorReader sensor_reader;
VoxHAUTVoicePlayer voice_player;

void httpCheckHandler();
void httpFetchDataHandler();

void setup() {
    ap_server.init(); 
    emotion_renderer.init();
    sensor_reader.init();
    voice_player.init();

    ap_server.handle("check", httpCheckHandler);
    ap_server.handle("data", httpFetchDataHandler);
    ap_server.begin();
}

void loop() {
    ap_server.loop();
}

void httpCheckHandler() {
    ap_server.respond(RESP(200, "text/plain", "OK"));
    voice_player.greet();
}

void httpFetchDataHandler() {
    String type = ap_server.get_parameter("type");

    if(type == "temp") {
        int temp = (int) sensor_reader.read_temperature();

        ap_server.respond(RESP(200, "text/json", "{\"response\": \"The temperature in Celcius right now is " + String(temp) + ".\"}"));
        voice_player.speak(VOX_SYNTH_TEMP, temp);
    }
    else if(type == "humid") {
        int humidity = (int) sensor_reader.read_humidity();

        ap_server.respond(RESP(200, "text/json", "{\"response\": \"The humidity in percentage right now is " + String(humidity) + ".\"}"));
        voice_player.speak(VOX_SYNTH_HUMIDITY, humidity);
    }
}