//
// Created by Maikel on 26-12-2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ENTITYMANAGER_H
#define GBA_SPRITE_ENGINE_PROJECT_ENTITYMANAGER_H


#include <vector>
#include <memory>
#include <libgba-sprite-engine/sprites/sprite.h>
#include "Entity/Entity.h"
#include "Entity/Player.h"
#include "Entity/Boss.h"
#include "Entity/Attack.h"

class EntityManager {
private:
    std::unique_ptr<Player> player;
    std::unique_ptr<Boss> boss;
    std::vector<std::unique_ptr<Attack>> attacks;

public:
    EntityManager();

    std::vector<Sprite *> getSprites();

    Player* getPlayer() { return player.get(); };
    Boss* getBoss() { return boss.get(); };
    std::vector<Attack *> getAttacks();

    bool checkCollusions();
    void collisionCheck();
    void addAttack(Attack * newAttack);


    void load();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENTITYMANAGER_H
