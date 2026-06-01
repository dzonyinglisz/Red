#include "engine.h"

#include <cstddef>
#include "raylib.h"

void Engine::process(const double deltaTime) const
{
    for (void (*func)(double) : activeProcessFunctions)
    {
        (*func)(deltaTime); // Call the function
    }
}
void Engine::draw() const
{
    BeginDrawing();
    ClearBackground(BLACK);
    for (void (*func)() : activeDrawFunctions)
    {
        func(); // Call the function
    }
    EndDrawing();
}
void Engine::loadAll() const
{
    while (!IsWindowReady())
    {
    }
    for (void (*func)() : loadFunctions)
    {
        func(); // Call the function
    }
}

void Engine::addLoadFunc(void (*function)())
{
    loadFunctions.push_back(function);
}

void Engine::addProcessFunc(void (*function)(double))
{
    activeProcessFunctions.push_back(function);
}

bool Engine::removeProcessFunc(void (*function)(double))
{
    bool was_removed = false;

    for (size_t i = 0; i < activeProcessFunctions.size();)
    {
        if (activeProcessFunctions[i] != function)
        {
            ++i;
            continue;
        }
        activeProcessFunctions.erase(activeProcessFunctions.begin() + i);
        was_removed = true;
    }
    return was_removed;
}

bool Engine::changeProcessPriority(void (*function)(double), int priority)
{
    const int currentPriority = getProcessPriority(function);

    if (currentPriority == -1)
    {
        return false; // Function not found
    }

    // Clamp the requested priority into the valid index range to avoid an
    // out-of-bounds insert iterator (undefined behaviour).
    const int lastIndex = static_cast<int>(activeProcessFunctions.size()) - 1;
    if (priority < 0)
        priority = 0;
    else if (priority > lastIndex)
        priority = lastIndex;

    if (currentPriority == priority)
    {
        return true; // No change needed
    }

    activeProcessFunctions.erase(activeProcessFunctions.begin() + currentPriority);
    if (currentPriority < priority)
    {
        --priority;
    }
    activeProcessFunctions.insert(activeProcessFunctions.begin() + priority, function);
    return true;
}

int Engine::getProcessPriority(void (*function)(double)) const
{
    for (size_t i = 0; i < activeProcessFunctions.size(); i++)
    {
        void (*func)(double) = activeProcessFunctions[i];
        if (func != function)
            continue;
        return static_cast<int>(i);
    }
    return -1;
}

void Engine::addDrawFunc(void (*function)())
{
    activeDrawFunctions.push_back(function);
}

bool Engine::removeDrawFunc(void (*function)())
{
    bool was_removed = false;

    for (size_t i = 0; i < activeDrawFunctions.size();)
    {
        if (activeDrawFunctions[i] != function)
        {
            ++i;
            continue;
        }
        activeDrawFunctions.erase(activeDrawFunctions.begin() + i);
        was_removed = true;
    }
    return was_removed;
}

bool Engine::changeDrawPriority(void (*function)(), int priority)
{
    const int currentPriority = getDrawPriority(function);

    if (currentPriority == -1)
    {
        return false; // Function not found
    }

    // Clamp the requested priority into the valid index range to avoid an
    // out-of-bounds insert iterator (undefined behaviour).
    const int lastIndex = static_cast<int>(activeDrawFunctions.size()) - 1;
    if (priority < 0)
        priority = 0;
    else if (priority > lastIndex)
        priority = lastIndex;

    if (currentPriority == priority)
    {
        return true; // No change needed
    }

    activeDrawFunctions.erase(activeDrawFunctions.begin() + currentPriority);
    if (currentPriority < priority)
    {
        --priority;
    }
    activeDrawFunctions.insert(activeDrawFunctions.begin() + priority, function);
    return true;
}

int Engine::getDrawPriority(void (*function)()) const
{
    for (size_t i = 0; i < activeDrawFunctions.size(); i++)
    {
        void (*func)() = activeDrawFunctions[i];
        if (func != function)
            continue;
        return static_cast<int>(i);
    }
    return -1;
}
