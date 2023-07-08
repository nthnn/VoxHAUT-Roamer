#include <Arduino.h>

#include <voxhaut_config.h>
#include <voxhaut_emotion_renderer.h>
#include <voxhaut_sensor_reader.h>
#include <voxhaut_wifi_ap.h>
#include <voxhaut_ultrasonic_sensor.h>
#include <voxhaut_voice_player.h>
#include <voxhaut_voice_player_defs.h>
#include <voxhaut_motor_driver.h>

VoxHAUTWiFiAP ap_server;
VoxHAUTEmotionRenderer emotion_renderer;
VoxHAUTSensorReader sensor_reader;
VoxHAUTVoicePlayer voice_player;

VoxHAUTUltrasonicSensor obstacle_sensor(
    VOXHAUT_ULTRASONIC_SENSOR_TRIGGER_PIN,
    VOXHAUT_ULTRASONIC_SENSOR_ECHO_PIN
);

VoxHAUTMotorDriver dual_motor(
    VOXHAUT_L293DD_PWM_A,
    VOXHAUT_L293DD_PWM_B,
    VOXHAUT_L293DD_DMA,
    VOXHAUT_L293DD_DMB
);

bool was_prev_right = true, first = false;

void httpCheckHandler();
void httpContactHandler();

void obstacle_avoidance_task();
void webserver_handling_task();

void setup() {
    sensor_reader.init();
    voice_player.init();
    dual_motor.init();

    emotion_renderer.init();
    emotion_renderer.render_sad();

    ap_server.init(); 
    ap_server.handle("check", httpCheckHandler);
    ap_server.handle("contact", httpContactHandler);
    ap_server.begin();
}

void loop() {
    if(first)
        obstacle_avoidance_task();
    else webserver_handling_task();

    first = !first;
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

    dual_motor.stop();
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
    dual_motor.drive_forward();
}

void obstacle_avoidance_task() {
    if(obstacle_sensor.get_distance() <= 16) {
        dual_motor.stop();

        if(was_prev_right)
            dual_motor.drive_left();
        else dual_motor.drive_right();
        was_prev_right = !was_prev_right;

        delay(500);
        dual_motor.stop();
        return;
    }

    dual_motor.drive_forward();
}

void webserver_handling_task() {
    ap_server.loop();
}