#include "engine.h"
#include <cstring>
#include <iostream>

void Node::draw (){
    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->draw();
    }
    
}

TextNode::TextNode(const char* text, int fontSize, Color color) {
    if (text != nullptr) {
        this->text = new char[strlen(text) + 1];
        strcpy(this->text, text);
    } else {
        this->text = nullptr;
    }
    this->fontSize = fontSize;
    this->color = color;
}

void TextNode::draw (){
    Vector2D globalPos = globalPosition();
    DrawText(text, globalPos.x, globalPos.y, fontSize, color);
    // std::cout << "DRAW: " << text << " at (" << globalPos.x << ", " << globalPos.y << ")\n";
}
