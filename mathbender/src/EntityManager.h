//
// Created by Maikel on 26-12-2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ENTITYMANAGER_H
#define GBA_SPRITE_ENGINE_PROJECT_ENTITYMANAGER_H


#include <vector>
#include <memory>
#include <libgba-sprite-engine/sprites/sprite.h>
#include "Entity.h"
#include "Player.h"

class EntityManager {
private:
    std::unique_ptr<Player> player;

public:
    EntityManager();

    std::vector<Sprite *> getSprites();

    Entity* getPlayer() { return player.get(); };

    void load();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENTITYMANAGER_H
