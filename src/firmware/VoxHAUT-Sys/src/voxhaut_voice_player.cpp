#include <JQ8400_Serial.h>
#include <SoftwareSerial.h>

#include <voxhaut_voice_player.h>

SoftwareSerial serial(3, 1);
JQ8400_Serial jq8400(serial);

void VoxHAUTVoicePlayer::init() {
    serial.begin(9600);

    jq8400.reset();
    jq8400.setVolume(20);
}

void VoxHAUTVoicePlayer::greet() {
    if(this->is_busy())
        jq8400.stop();

    jq8400.setVolume(30);
    jq8400.playFileByIndexNumber(VOX_SYNTH_HELLO);    
}

void VoxHAUTVoicePlayer::speak(uint16_t message, uint16_t number) {
    if(this->is_busy())
        jq8400.stop();

    jq8400.setVolume(30);
    jq8400.playFileByIndexNumber(message);

    delay(3100);
    jq8400.playFileByIndexNumber(number);
}

void VoxHAUTVoicePlayer::play_track() {
    if(this->is_busy())
        jq8400.stop();

    jq8400.setVolume(30);
    jq8400.playFileByIndexNumber(VOX_SYNTH_SONG);
}

bool VoxHAUTVoicePlayer::is_busy() {
    return jq8400.busy();
}
