//
// Created by catnip on 2/19/26.
//

#ifndef REDPROJECT_CYFRAENTITY_H
#define REDPROJECT_CYFRAENTITY_H

#include "backend/entities/entity.h"


// Works similarly to foxy in FNaF 1
class CyfraEntity: Entity {
public:
    explicit CyfraEntity(Room *closet_room) : closet_room(closet_room) {}

private:
    Room *closet_room;

};


#endif //REDPROJECT_CYFRAENTITY_H