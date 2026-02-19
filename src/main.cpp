//
// Created by catnip on 2/19/26.
// with orl0pl on same day and days after
//

#include <raylib.h>
#include <./engine/engine.h>

int main(int argc, char *argv[])
{
    Engine engine = Engine();
    Node root = Node();

    Transform2DNode *parent = new Transform2DNode();
    parent->localPosition = {100, 100};

    TextNode *childText = new TextNode("Wah", 15, RED);
    childText->localPosition = {50, 50};
    childText->setParent(parent);

    parent->children.push_back(childText);

    root.children.push_back(parent);
    engine.root = root;

    InitWindow(1024, 768, "raylib window");

    SetTargetFPS(60);

    float speed = 1.0f;
    float screenWidth = 1024.0f;
    float textWidth = 100.0f;

    bool shouldQuit = false;
    while (!shouldQuit)
    {
        float dt = GetFrameTime() * GetFPS();
        parent->localPosition.x += speed * dt;
        parent->localPosition.y = 200.0f + (100.0f*sinf32(parent->localPosition.x/80.0f));

        if (parent->localPosition.x > screenWidth)
        {
            parent->localPosition.x = -textWidth;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        engine.root.draw();
        EndDrawing();

        PollInputEvents();

        if (IsKeyPressed(KEY_ESCAPE))
            shouldQuit = true;
    }
}
