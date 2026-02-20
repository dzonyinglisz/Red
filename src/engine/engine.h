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

// Forward declaration
class InteractableNode;

// Callback type using std::function to support lambdas with captures
using MouseCallback = std::function<void(InteractableNode* node)>;

// Hitbox struct for custom interaction areas
struct Hitbox {
    int width = 0;
    int height = 0;
    int offsetX = 0;  // Offset from node's global position
    int offsetY = 0;
};

class Interactable {
public:
    Hitbox hitbox;
    
    // Callback function pointers
    MouseCallback onMouseDown = nullptr;
    MouseCallback onMouseUp = nullptr;
    MouseCallback onMouseEnter = nullptr;
    MouseCallback onMouseLeave = nullptr;
    
    // State tracking
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

class ButtonNode: public InteractableNode {
    public:
    virtual void draw() override;
};

class Engine {
public:
    Node root;
    void handleInteractions();
    // TODO: add more options
};

#endif //REDPROJECT_CORE_ENGINE_H