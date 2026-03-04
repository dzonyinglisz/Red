#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "core/raygui.h"

#include "game_main.h"
#include "core/engine.h"

int main()
{
    Engine engine;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI);
    InitWindow(1024, 768, "raygui - i forgor");
    SetTargetFPS(60);

    game_main(&engine);

    while (!WindowShouldClose())
    {
        engine.process(GetFrameTime());
        engine.draw();
    }
    CloseWindow();
    return 0;
}
