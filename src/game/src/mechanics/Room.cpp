#include "Room.h"

#include <cstddef>


bool Room::attemptEnter(Entity *entering_entity, const bool override_max) {
    if (entering_entity == nullptr)
        return false;
    if (this->occupied_by.size() < static_cast<std::size_t>(this->max_occupation) || override_max) {
        this->occupied_by.push_back(entering_entity);
        return true;
    }
    return false;
}

void Room::leaveRoom(const Entity *exiting_entity) {
    if (exiting_entity == nullptr)
        return;

    for (std::size_t index = 0; index < this->occupied_by.size();) {
        if (this->occupied_by[index] != exiting_entity) {
            ++index;
            continue;
        }
        this->occupied_by.erase(this->occupied_by.begin() + index);
    }
}
