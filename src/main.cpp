//
// Created by catnip on 2/19/26.
// with orl0pl on same day and days after
//

#include <raylib.h>
#include <iostream>
#include <./engine/engine.h>

int main(int argc, char *argv[])
{
    Engine engine = Engine();
    Node root = Node();

    Transform2DNode *parent = new Transform2DNode();
    parent->localPosition = {100, 100};

    char *text = NULL;

    TextNode *childText = new TextNode(&text, 15, RED);
    childText->localPosition = {50, 50};
    childText->setParent(parent);

    parent->children.push_back(childText);

    root.children.push_back(parent);
    engine.root = root;

    InitWindow(1024, 768, "raylib window");

    SetTargetFPS(60);

    float speed = 1.0f;
    float screenWidth = 1024.0f;

    // TODO: find better way to do this without showing errors of invalid convert of `const char*` into `char*`
    std::string s = "meow";
    text = (char *)s.data();

    int count = 0;

    ButtonNode *button = new ButtonNode();
    button->localPosition = {100, 100};
    button->hitbox.width = 200;
    button->hitbox.height = 50;



    button->onMouseDown = [&count](InteractableNode *node)
    {
        std::cout << "Button clicked!" << std::endl;
        count++;
    };

    parent->children.push_back(button);

    bool shouldQuit = false;
    while (!shouldQuit)
    {
        float dt = GetFrameTime() * GetFPS();
    
        std::string s = std::to_string(count);
        text = (char *)s.data();

        BeginDrawing();
        ClearBackground(BLACK);

        engine.root.draw();

        EndDrawing();

        if (IsKeyPressed(KEY_ESCAPE))
            shouldQuit = true;
        
        engine.handleInteractions();
        PollInputEvents();
    }
}