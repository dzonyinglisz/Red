#include "button.h"

void ButtonNode::draw()
{
    Vector2D globalPos = globalPosition();
    DrawRectangle(globalPos.x + hitbox.offsetX, globalPos.y + hitbox.offsetY, 
                  hitbox.width, hitbox.height, isHovered ? LIGHTGRAY : DARKGRAY);
    InteractableNode::draw();
}