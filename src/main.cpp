//
// Created by catnip on 2/19/26.
//

#include <raylib.h>


int main(int argc, char *argv[]) {
    InitWindow(1024, 768, "raylib window");

    bool shouldQuit = false;
    while (!shouldQuit) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();

        PollInputEvents();

        if (IsKeyPressed(KEY_ESCAPE))
            shouldQuit = true;
    }
}