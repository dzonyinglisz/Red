#ifndef REDPROJECT_CORE_ENGINE_INTERACTABLE_H
#define REDPROJECT_CORE_ENGINE_INTERACTABLE_H

#include <functional>
#include "engine.h"

class InteractableNode;
using MouseCallback = std::function<void(InteractableNode* node)>;
struct Hitbox {
    int width = 0;
    int height = 0;
    int offsetX = 0;
    int offsetY = 0;
};

class Interactable {
public:
    Hitbox hitbox;
    
    MouseCallback onMouseDown = nullptr;
    MouseCallback onMouseUp = nullptr;
    MouseCallback onMouseEnter = nullptr;
    MouseCallback onMouseLeave = nullptr;
    
    bool isHovered = false;
    bool isPressed = false;
    
    // Check if a point is inside the hitbox (needs global position of the node)
    bool containsPoint(Vector2D globalPos, Vector2D point) const;
};

// Base class for interactable nodes using multiple inheritance
class InteractableNode : public VisualNode, public Interactable {
public:
    virtual void draw() override;
};

#endif