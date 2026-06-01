#ifndef REDPROJECT_ENGINE_H
#define REDPROJECT_ENGINE_H

#include <vector>

class Engine
{
public:
    // Constructor and Destructor
    Engine() = default;
    ~Engine() = default;

    // Called every frame - each call functions from the assigned lists
    void process(double deltaTime) const;
    void draw() const;
    void loadAll() const;

    // Setter and getter functions
    void addProcessFunc(void (*function)(double));
    bool removeProcessFunc(void (*function)(double));
    bool changeProcessPriority(void (*function)(double), int priority);
    int getProcessPriority(void (*function)(double)) const;

    void addDrawFunc(void (*function)());
    bool removeDrawFunc(void (*function)());
    bool changeDrawPriority(void (*function)(), int priority);
    int getDrawPriority(void (*function)()) const;

    void addLoadFunc(void (*function)());
    void addUnloadFunc(void (*function)());
    void unloadAll() const;

private:
    std::vector<void (*)(double)> activeProcessFunctions;
    std::vector<void (*)()> activeDrawFunctions;
    std::vector<void (*)()> loadFunctions;
    std::vector<void (*)()> unloadFunctions;
};

#endif // REDPROJECT_ENGINE_H