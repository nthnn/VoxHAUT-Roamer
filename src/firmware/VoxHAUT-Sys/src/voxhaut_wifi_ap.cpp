#include "voxhaut_wifi_ap.h"

ESP8266WebServer server(VOXHAUT_SERVER_PORT);

void VoxHAUTWiFiAP::init() {
    WiFi.disconnect();
    WiFi.softAP(VOXHAUT_SERVER_SSID, VOXHAUT_SERVER_PASSWORD);
    WiFi.softAPConfig(
        IPAddress(VOXHAUT_SERVER_LOCAL_IP), 
        IPAddress(VOXHAUT_SERVER_GATEWAY),
        IPAddress(VOXHAUT_SERVER_SUBNET));
}

void VoxHAUTWiFiAP::begin() {
    server.begin();
}

void VoxHAUTWiFiAP::loop() {
    server.handleClient();
}

void VoxHAUTWiFiAP::handle(String path, void (*callback)()) {
    server.on("/" + path, callback);
}

void VoxHAUTWiFiAP::respond(VoxHAUTWiFiAPResponse response) {
    server.send(response.response_code, response.content_type, response.content);
}

String VoxHAUTWiFiAP::get_parameter(String param_name) {
    return server.arg(param_name);
}
