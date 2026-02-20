#ifndef REDPROJECT_CORE_ENGINE_TEXT_H
#define REDPROJECT_CORE_ENGINE_TEXT_H

#include "engine.h"

class TextNode: public VisualNode {
public:
    TextNode(char** text = nullptr, int fontSize = 10, Color color = BLUE);
    
    char** text;
    int fontSize = 10;
    Color color = BLUE;
    virtual void draw();
    void setText(char** text);
    Vector2D dimensions();
};

#endif
