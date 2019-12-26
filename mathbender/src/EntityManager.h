//
// Created by Maikel on 26-12-2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ENTITYMANAGER_H
#define GBA_SPRITE_ENGINE_PROJECT_ENTITYMANAGER_H


#include <vector>
#include <memory>
#include "Entity.h"

class EntityManager {
private:
    std::unique_ptr<Entity> player;

public:
    EntityManager();

    Entity* getPlayer() { return player.get(); };
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENTITYMANAGER_H
