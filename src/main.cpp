//
// Created by catnip on 2/19/26.
// with orl0pl on same day and days after
//

#include <raylib.h>
#include <./engine/engine.h>

int main(int argc, char *argv[]) {
    Engine engine = Engine();
    Node root = Node();
    
    TextNode* parentText = new TextNode("Meow", 20, BLUE);
    parentText->localPosition = {100, 100};
    
    TextNode* childText = new TextNode("Mrrp", 15, RED);
    childText->localPosition = {50, 50};
    childText->setParent(parentText);
    
    parentText->children.push_back(childText);
    
    root.children.push_back(parentText);
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
