//
// Created by catnip on 2/19/26.
//

#include "entity.h"

int Entity::getAggressionLevel() const {
    return aggression_level;
}

Room * Entity::getCurrentlyOccupiedRoom() const {
    return currently_occupied_room;
}

void Entity::setAggressionLevel(int new_value) {
    aggression_level = new_value;
}

void Entity::setCurrentlyOccupiedRoom(Room *new_value) {
    currently_occupied_room = new_value;
}
