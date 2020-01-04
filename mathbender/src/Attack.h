//
// Created by Maikel on 4-1-2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ATTACK_H
#define GBA_SPRITE_ENGINE_PROJECT_ATTACK_H


#include <libgba-sprite-engine/sprites/sprite.h>
#include "Entity.h"

class Attack : public Entity {
    enum Type {PROJECTILE, MELEE, STATIONARY};

private:

public:
    Attack() = default;

    virtual Type getAttackType() = 0;
    virtual Sprite * getSprite() = 0;
    virtual void load() = 0;
    void move(int x, int y) override = 0;
    void setVelocity(int dx, int dy) override = 0;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ATTACK_H
