#include "../../engine/core/game_main.h"
#include "game/src/user-interface/main_view.h"
#include "raylib.h"
#include <raygui.h>


class MainGameView;
MainGameView gameView;


void process_game();
void draw_game();
void game_main(Engine *engine) {
    SetWindowState(FLAG_WINDOW_HIGHDPI);
    SetWindowTitle("FNaZST - ORIGINS");

    const Vector2 baseSize = {1024, 768};
    Vector2 scaledSize = {
        baseSize.x * GetWindowScaleDPI().x,
        baseSize.y * GetWindowScaleDPI().y
    };
    SetWindowSize(scaledSize.x, scaledSize.y);

    engine->addDrawFunc(&draw_game);
}

void draw_game() {
    gameView.drawUi();
}
