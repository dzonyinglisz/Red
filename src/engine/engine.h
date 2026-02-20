#ifndef REDPROJECT_CORE_ENGINE_H
#define REDPROJECT_CORE_ENGINE_H
#include <vector>
#include <string>
#include <cmath>
#include <functional>
#include <raylib.h>

class Node {
public:
    std::vector <Node *> children;
    virtual void draw();
};

struct Vector2D {
    int x;
    int y;
    float lenght() {
        return std::sqrt((x*x)+(y*y));
    }
};

class Transform2DNode: public Node  {
public:
    Vector2D localPosition;
    Transform2DNode* parent = nullptr;

    Transform2DNode() {}
    
    Vector2D globalPosition() const {
        if (parent == nullptr) {
            return localPosition;
        }
        Vector2D parentGlobal = parent->globalPosition();
        return {parentGlobal.x + localPosition.x, parentGlobal.y + localPosition.y};
    }
    
    void setParent(Transform2DNode* newParent) {
        parent = newParent;
    }
};

class VisualNode: public Transform2DNode {
    public:
    Vector2D dimensions();
};

class Engine {
public:
    Node root;
    void handleInteractions();
    // TODO: add more options
};

#endif //REDPROJECT_CORE_ENGINE_H