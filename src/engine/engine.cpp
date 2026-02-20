#include "engine.h"
#include <cstring>
#include <iostream>
#include "interactable.h"


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