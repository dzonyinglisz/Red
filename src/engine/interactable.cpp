#include "interactable.h"
#include "engine.h"

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