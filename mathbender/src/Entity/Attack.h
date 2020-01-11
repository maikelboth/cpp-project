//
// Created by Maikel on 4-1-2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ATTACK_H
#define GBA_SPRITE_ENGINE_PROJECT_ATTACK_H


#include <libgba-sprite-engine/sprites/sprite.h>

class Attack {

protected:
private:

public:
    Attack() = default;
    enum Type {PROJECTILE, MELEE, STATIONARY};

    virtual Type getAttackType() = 0;
    virtual Sprite * getSprite() = 0;
    virtual void load() = 0;
    virtual void moveTo(int x, int y) = 0;
    virtual void setVelocity(int dx, int dy) = 0;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ATTACK_H
