//
// Created by catnip on 2/20/26.
//

#include <string>

#include "raygui.h"
#include "core/engine.h"


int count = 0;


void draw_game();
void game_main(Engine *engine) {
    engine->addDrawFunc(&draw_game);
}

void draw_game() {
    if (GuiButton((Rectangle){ 24, 24, 120, 30 }, std::to_string(count).c_str())) {
        count++;
    }
}
