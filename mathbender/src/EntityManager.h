//
// Created by Maikel on 26-12-2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ENTITYMANAGER_H
#define GBA_SPRITE_ENGINE_PROJECT_ENTITYMANAGER_H


#include <vector>
#include <memory>
#include <libgba-sprite-engine/sprites/sprite.h>
#include "Entity/Player.h"
#include "Entity/Boss.h"
#include "Entity/Attack.h"

class EntityManager {
private:
    std::unique_ptr<Player> player;
    std::unique_ptr<Boss> boss;
    std::vector<std::shared_ptr<Attack>> attacks;
    void removeAttacksInShadowRealm();
    int level = 0;

public:
    EntityManager();

    std::vector<Sprite *> getSprites();

    Player* getPlayer() { return player.get(); };
    Boss* getBoss() { return boss.get(); };
    std::vector<Attack *> getAttacks();

    int calculateScore();
    int getLevel() { return level; };
    void collisionCheck();
    void addAttack(const std::shared_ptr<Attack>& newAttack);
    void removeAttack(Attack* attack);
    bool isOutOfMap(Attack* attack);
    bool isOutOfMap(Sprite* sprite);
    bool isOutOfMap(int xLeft, int xRight, int yTop, int yBottom);
    bool canMove(Sprite* sprite, int dx, int dy);
    void tick(u16 keys);
    void bossAI();

    void load();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENTITYMANAGER_H
