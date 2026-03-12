#ifndef REDPROJECT_ENTITY_H
#define REDPROJECT_ENTITY_H

#include "../Room.h"


// Interface class - do not use as a standalone object!
class Entity {
public:
    virtual ~Entity() = default;


    int getAggressionLevel() const;
    Room *getCurrentlyOccupiedRoom() const;

    void setAggressionLevel(int new_value);
    void setCurrentlyOccupiedRoom(Room *new_value);

protected:
    virtual bool attemptMovement(double current_time) { return false; }


    // Time between each attempt in millis
    int time_per_move = 1000;
    // Chance of successful movement (range 0.0-1.0)
    double movement_chance = 1.0;

    int aggression_level = 0;
    Room *currently_occupied_room = nullptr;
};


#endif //REDPROJECT_ENTITY_H