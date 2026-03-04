#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "core/raygui.h"

#include "core/game_main.h"
#include "core/engine.h"

int main()
{
    Engine engine;

    // Defaults (can be changed later)
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI);
    InitWindow(1024, 768, "new raylib window");
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
