//
// Created by catnip on 2/19/26.
//

#include "Room.h"


bool Room::attemptEnter(Entity *entering_entity, const bool override_max) {
    if (entering_entity == nullptr)
        return false;
    if (this->occupied_by.size() >= this->max_occupation || override_max) {
        this->occupied_by.push_back(entering_entity);
        return true;
    }
    return false;
}

void Room::leaveRoom(const Entity *exiting_entity) {
    if (exiting_entity == nullptr)
        return;

    for (int index = 0; index < this->occupied_by.size(); index++) {
        if (this->occupied_by[index] != exiting_entity)
            continue;
        this->occupied_by.erase(this->occupied_by.begin() + index);
    }
}
