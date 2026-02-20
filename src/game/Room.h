//
// Created by catnip on 2/19/26.
//

#ifndef REDPROJECT_ROOM_H
#define REDPROJECT_ROOM_H
#include <vector>


class Entity;

class Room {
public:
    std::vector <Room *> connected_rooms;
    std::vector <Entity *> occupied_by;
    const int max_occupation;

    // Constructor
    explicit Room(const int max_occupation = 1) : max_occupation(max_occupation) {}

    bool attemptEnter(Entity *entering_entity, bool override_max);
    void leaveRoom(const Entity *exiting_entity);
};


#endif //REDPROJECT_ROOM_H