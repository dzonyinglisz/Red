#include <string>

#include "../core/engine.h"
#include "raylib.h"
#include <raygui.h>


void draw_game();
void game_main(Engine *engine) {
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    SetWindowTitle("FNaZST - ORIGINS");
    SetWindowSize(1024*GetWindowScaleDPI().x, 768*GetWindowScaleDPI().y);

    engine->addDrawFunc(&draw_game);
}

void draw_game() {
    const Vector2 SCREEN_SIZE = {
        static_cast<float>(GetScreenWidth()), 
        static_cast<float>(GetScreenHeight())};
    //

    // OFFICE UI ( HOUR, CAMERAS BTN, MASK BTN )
    {
        // TODO: Remove and replace with actuall implementation
        int tempNightMinutes = 186; // 3am
        
        std::string hourText = std::to_string(tempNightMinutes / 60);
        if (tempNightMinutes < 60) hourText += "PM"; else hourText += "AM";
        
        
        // Drawing: hour
        int defaultTextSize = GuiGetStyle(DEFAULT, TEXT_SIZE);
        GuiSetStyle(DEFAULT, TEXT_SIZE, 24);
            GuiLabel(
                (Rectangle){0, 0, 100, 32},
                hourText.c_str());
        GuiSetStyle(DEFAULT, TEXT_SIZE, defaultTextSize);

        // cameras and mask buttons
        const Vector2 officeBtnSize = {SCREEN_SIZE.x * 0.45f, 30.0f};
        const float officeBtnOffset = officeBtnSize.x * 0.1f;
        GuiButton(
            (Rectangle){
                officeBtnOffset,
                SCREEN_SIZE.y-officeBtnSize.y-(officeBtnOffset*0.5f),
                officeBtnSize.x,
                officeBtnSize.y},
            "CAM BUTTON");
        GuiButton(
            (Rectangle){
                SCREEN_SIZE.x-officeBtnOffset-officeBtnSize.x,
                SCREEN_SIZE.y-officeBtnSize.y-(officeBtnOffset*0.5f),
                officeBtnSize.x,
                officeBtnSize.y
            }, 
            "MASK BUTTON");
    }

    // CAMERAS UI ( MAP, POWER, ACTIONS )
    {
        // TODO: Remove this and replace with real implementation
        float tempPower = 0.578; // percentage (value between 0.0-1.0)
    }
}
