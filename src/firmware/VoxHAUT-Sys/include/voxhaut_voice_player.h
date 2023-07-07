#ifndef VOXHAUT_VOICE_PLAYER_H
#define VOXHAUT_VOICE_PLAYER_H

#include <Arduino.h>

#include "voxhaut_voice_player_defs.h"

class VoxHAUTVoicePlayer {
    public:
    void init();

    void greet();
    void speak(uint16_t message, uint16_t number);
    void play_track();
    bool is_busy();
};

#endif