#ifndef REDPROJECT_CORE_ENGINE_BUTTON_H
#define REDPROJECT_CORE_ENGINE_BUTTON_H

#include "interactable.h"

class ButtonNode: public InteractableNode {
    public:
    virtual void draw() override;
};

#endif
