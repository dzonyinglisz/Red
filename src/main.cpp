//
// Created by catnip on 2/19/26.
// with orl0pl on same day and days after
//

#include <raylib.h>
#include <iostream>
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main()
{
    InitWindow(1024, 768, "raygui - i forgor");
    SetTargetFPS(60);

    bool showMessageBox = false;
    int count = 0;

    while (!WindowShouldClose())
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            if (GuiButton((Rectangle){ 24, 24, 120, 30 }, std::to_string(count).c_str())) count++;


        EndDrawing();
    }

    CloseWindow();
    return 0;
}