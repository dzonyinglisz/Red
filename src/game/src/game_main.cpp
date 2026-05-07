#include "../../engine/core/game_main.h"
#include "game/src/user-interface/main_view.h"
#include "raylib.h"
#include <raygui.h>

void process_game(double dt);
void draw_game();
void load_fnaz_assets();

// UI
class MainGameView;
MainGameView gameView;

// Mechanics
TimeKeeper timeKeeper(0);

void game_main(Engine *engine)
{
    SetWindowState(FLAG_WINDOW_HIGHDPI);
    SetWindowTitle("FNaZST - ORIGINS");

    const Vector2 baseSize = {320 * 3, 256 * 3};
    Vector2 scaledSize = {
        baseSize.x * GetWindowScaleDPI().x,
        baseSize.y * GetWindowScaleDPI().y};
    SetWindowSize(scaledSize.x, scaledSize.y);

    engine->addLoadFunc(&load_fnaz_assets);
    engine->addDrawFunc(&draw_game);
    engine->addProcessFunc(&process_game);

    gameView.timeKeeper = &timeKeeper;
}

void draw_game()
{
    gameView.drawUi();
}

void load_fnaz_assets()
{
    gameView.loadTextures();
}

void process_game(double dt)
{
    timeKeeper.progressTime(dt);
}