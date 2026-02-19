//
// Created by catnip on 2/19/26.
// with orl0pl on same day and days after
//

#include <raylib.h>
#include <./engine/engine.h>

int main(int argc, char *argv[]) {
    Engine engine = Engine();
    Node root = Node();
    root.children.push_back(new TextNode("Meow :3", 10, GREEN));
    engine.root = root;
    InitWindow(1024, 768, "raylib window");

    bool shouldQuit = false;
    while (!shouldQuit) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        engine.root.draw();
        EndDrawing();

        PollInputEvents();

        if (IsKeyPressed(KEY_ESCAPE))
            shouldQuit = true;
    }
}