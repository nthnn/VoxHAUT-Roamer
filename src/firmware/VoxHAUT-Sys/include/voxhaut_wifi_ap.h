#ifndef VOXHAUT_WIFI_AP_H
#define VOXHAUT_WIFI_AP_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "voxhaut_config.h"

#define RESP(_response_code, _content_type, _content) (VoxHAUTWiFiAPResponse) {\
    .response_code = _response_code, \
    .content_type = _content_type,\
    .content = _content \
}

struct _VoxHAUTWiFiAPResponse {
    int response_code;
    String content_type;
    String content;
};

typedef struct _VoxHAUTWiFiAPResponse VoxHAUTWiFiAPResponse;

class VoxHAUTWiFiAP {
    public:
    void init();
    void begin();
    void loop();

    void handle(String path, void (*callback)());
    void respond(VoxHAUTWiFiAPResponse response);

    String get_parameter(String param_name);
};

#endif