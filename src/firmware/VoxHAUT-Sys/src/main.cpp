#include <Arduino.h>
#include <anomalia.h>
#include <navigador.h>

#include "voxhaut_config.h"
#include "voxhaut_emotion_renderer.h"
#include "voxhaut_sensor_reader.h"
#include "voxhaut_wifi_ap.h"
#include "voxhaut_ultrasonic_sensor.h"
#include "voxhaut_voice_player.h"
#include "voxhaut_voice_player_defs.h"

VoxHAUTWiFiAP ap_server;
VoxHAUTEmotionRenderer emotion_renderer;
VoxHAUTSensorReader sensor_reader;
VoxHAUTVoicePlayer voice_player;

VoxHAUTUltrasonicSensor obstacle_sensor(
    VOXHAUT_ULTRASONIC_SENSOR_TRIGGER_PIN,
    VOXHAUT_ULTRASONIC_SENSOR_ECHO_PIN
);

Navigador navigador(
    VOXHAUT_MOTOR_1A,
    VOXHAUT_MOTOR_1B,
    VOXHAUT_MOTOR_2A,
    VOXHAUT_MOTOR_2B
);

Anomalia anomalia;

void httpCheckHandler();
void httpContactHandler();

void setup() {
    sensor_reader.init();
    voice_player.init();

    emotion_renderer.init();
    emotion_renderer.render_sad();

    ap_server.init(); 
    ap_server.handle("check", httpCheckHandler);
    ap_server.handle("contact", httpContactHandler);
    ap_server.begin();
}

void loop() {
    ap_server.loop();
    anomalia.check();
}

void httpCheckHandler() {
    ap_server.respond(RESP(200, "text/plain", "OK"));

    emotion_renderer.render_happy();
    voice_player.greet();

    delay(1000);
    emotion_renderer.render_idle();
}

void httpContactHandler() {
    String type = ap_server.get_parameter("type");
    emotion_renderer.render_happy();

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
    else if(type == "sing") {
        ap_server.respond(RESP(200, "text/json", "{ \"response\": \"Ok, I'll play a song for you.\"}"));
        voice_player.play_track();
    }

    delay(1350);
    emotion_renderer.render_idle();
}
