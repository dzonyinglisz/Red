#ifndef REDPROJECT_CYFRAENTITY_H
#define REDPROJECT_CYFRAENTITY_H

#include "../entity.h"


// Works similarly to foxy in FNaF 1
class CyfraEntity: public Entity {
public:
    explicit CyfraEntity(Room *closet_room) : closet_room(closet_room) {}

private:
    Room *closet_room;

};


#endif //REDPROJECT_CYFRAENTITY_H