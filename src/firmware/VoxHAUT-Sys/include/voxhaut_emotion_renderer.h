#ifndef VOXHAUT_EMOTION_RENDERER_H
#define VOXHAUT_EMOTION_RENDERER_H

class VoxHAUTEmotionRenderer {
    public:
    static void init();

    static void render_happy();
    static void render_sad();
    static void render_idle();
};

#endif