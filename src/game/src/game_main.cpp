#include "../../engine/core/game_main.h"
#include "game/src/user-interface/main_view.h"
#include "raylib.h"
#include <raygui.h>


class MainGameView;
MainGameView gameView;


void draw_game();
void game_main(Engine *engine) {
    SetWindowState(FLAG_WINDOW_HIGHDPI);
    SetWindowTitle("FNaZST - ORIGINS");
    SetWindowSize(1024, 768);

    engine->addDrawFunc(&draw_game);
}

void draw_game() {
    gameView.drawUi();
}
