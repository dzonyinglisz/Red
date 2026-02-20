#include "engine.h"
#include <cstring>
#include <iostream>

void Engine::handleInteractions()
{
    
}

void Node::draw()
{
    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->draw();
    }
}

TextNode::TextNode(char **text, int fontSize, Color color)
{
    this->text = text;
    this->fontSize = fontSize;
    this->color = color;
}

void TextNode::draw()
{
    Vector2D globalPos = globalPosition();
    DrawText(*text, globalPos.x, globalPos.y, fontSize, color);
    // std::cout << "DRAW: " << text << " at (" << globalPos.x << ", " << globalPos.y << ")\n";
}

void TextNode::setText(char **x)
{
    text = x;
}

Vector2D TextNode::dimensions()
{
    Vector2D size;
    size.x = MeasureText(*text, fontSize);
    size.y = fontSize;
    return size;
}