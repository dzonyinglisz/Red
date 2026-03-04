//
// Created by catnip on 2/20/26.
//

#include <string>

#include "../core/raygui.h"
#include "../core/engine.h"


int count = 0;


void draw_game();
void game_main(Engine *engine) {
    engine->addDrawFunc(&draw_game);
}

void draw_game() {
    const Vector2 SCREEN_SIZE = {static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight())};

    if (GuiButton((Rectangle){ 24, 24, 120, 30 }, std::to_string(count).c_str())) {
        count++;
    }


    // TODO: Have to make our own button because it should act on hover not click
    const Vector2 maskBtnSize = {SCREEN_SIZE.x * 0.45f, 30};
    const double maskBtnOffset = maskBtnSize.x * 0.1;
    const Rectangle maskBtnRect = {
        static_cast<float>(maskBtnOffset),
        static_cast<float>(SCREEN_SIZE.y-maskBtnSize.y - (maskBtnOffset* 0.5f)),
        maskBtnSize.x,
        maskBtnSize.y
    };
    GuiButton(maskBtnRect, "use mask button");


    const Vector2 cameraBtnSize = {SCREEN_SIZE.x * 0.45f, 30};
    const double cameraBtnOffset = cameraBtnSize.x * 0.1;
    const Rectangle cameraBtnRect = {
        static_cast<float>(SCREEN_SIZE.x - cameraBtnOffset - maskBtnSize.x),
        static_cast<float>(SCREEN_SIZE.y-cameraBtnSize.y - (cameraBtnOffset* 0.5f)),
        cameraBtnSize.x,
        cameraBtnSize.y
    };
    GuiButton(cameraBtnRect, "use cameras button");
}
