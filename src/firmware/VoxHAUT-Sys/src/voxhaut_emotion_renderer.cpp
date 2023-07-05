#include <Adafruit_SSD1306.h>

#include "voxhaut_bitmaps.h"
#include "voxhaut_emotion_renderer.h"

Adafruit_SSD1306 display(128, 32, &Wire, -1);

void VoxHAUTEmotionRenderer::init() {
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c))
        for(;;);

    display.setRotation(2);
    display.clearDisplay();
}

void VoxHAUTEmotionRenderer::render_happy() {
    display.clearDisplay();
    display.drawBitmap(16, 3, happy_emotion_bitmap, 96, 20, 1);
    display.display();
}

void VoxHAUTEmotionRenderer::render_sad() {
    display.clearDisplay();
    display.drawBitmap(16, 3, sad_emotion_bitmap, 96, 20, 1);
    display.display();
}

void VoxHAUTEmotionRenderer::render_idle() {
    display.clearDisplay();
    display.drawBitmap(16, 3, idle_emotion_bitmap, 96, 20, 1);
    display.display();
}