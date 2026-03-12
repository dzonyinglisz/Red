#include "../../engine/core/game_main.h"
#include "game/src/user-interface/main_view.h"
#include "raylib.h"
#include <raygui.h>


class MainGameView;
MainGameView gameView;


void draw_game();
void game_main(Engine *engine) {
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    SetWindowTitle("FNaZST - ORIGINS");
    SetWindowSize(1024*GetWindowScaleDPI().x, 768*GetWindowScaleDPI().y);

    engine->addDrawFunc(&draw_game);
}

void draw_game() {
    gameView.drawUi();
}
