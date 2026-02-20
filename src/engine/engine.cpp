#include "engine.h"
#include <cstring>
#include <iostream>

// TODO: break this into smaller files

// Check if a point is inside the hitbox
bool Interactable::containsPoint(Vector2D globalPos, Vector2D point) const
{
    int left = globalPos.x + hitbox.offsetX;
    int right = left + hitbox.width;
    int top = globalPos.y + hitbox.offsetY;
    int bottom = top + hitbox.height;
    
    return (point.x >= left && point.x <= right &&
            point.y >= top && point.y <= bottom);
}

// InteractableNode draw - calls parent draw
void InteractableNode::draw()
{
    VisualNode::draw();
}

// Helper function to process interactables in the node tree
static void processInteractables(Node* node, Vector2D mousePos, 
                                  bool mouseDown, bool mousePressed, bool mouseReleased)
{
    if (!node) return;
    
    // Check if this node is an InteractableNode
    InteractableNode* interactable = dynamic_cast<InteractableNode*>(node);
    if (interactable)
    {
        Vector2D globalPos = interactable->globalPosition();
        bool wasHovered = interactable->isHovered;
        bool wasPressed = interactable->isPressed;
        bool nowContains = interactable->containsPoint(globalPos, mousePos);
        
        // Update hover state
        interactable->isHovered = nowContains;
        
        // Mouse enter event
        if (nowContains && !wasHovered && interactable->onMouseEnter)
        {
            interactable->onMouseEnter(interactable);
        }
        
        // Mouse leave event
        if (!nowContains && wasHovered && interactable->onMouseLeave)
        {
            interactable->onMouseLeave(interactable);
        }
        
        // Mouse down event (only when mouse is pressed while hovering)
        if (nowContains && mousePressed && interactable->onMouseDown)
        {
            interactable->isPressed = true;
            interactable->onMouseDown(interactable);
        }
        
        // Mouse up event (only when mouse is released and was pressed)
        if (mouseReleased && wasPressed && interactable->onMouseUp)
        {
            interactable->isPressed = false;
            interactable->onMouseUp(interactable);
        }
        
        // Reset pressed state if mouse released outside
        if (mouseReleased)
        {
            interactable->isPressed = false;
        }
    }
    
    // Recursively process children
    for (size_t i = 0; i < node->children.size(); i++)
    {
        processInteractables(node->children[i], mousePos, mouseDown, mousePressed, mouseReleased);
    }
}

void Engine::handleInteractions()
{
    Vector2 mousePos = GetMousePosition();
    Vector2D mousePosV = { (int)mousePos.x, (int)mousePos.y };
    
    bool mouseDown = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
    bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    bool mouseReleased = IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
    
    processInteractables(&root, mousePosV, mouseDown, mousePressed, mouseReleased);
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

void ButtonNode::draw()
{
    Vector2D globalPos = globalPosition();
    DrawRectangle(globalPos.x + hitbox.offsetX, globalPos.y + hitbox.offsetY, 
                  hitbox.width, hitbox.height, isHovered ? LIGHTGRAY : DARKGRAY);
    InteractableNode::draw();
}