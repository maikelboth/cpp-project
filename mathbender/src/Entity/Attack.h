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

    virtual Sprite * getSprite() = 0;
    virtual int getDamage() = 0;
    virtual void moveTo(int x, int y) = 0;
    virtual void setVelocity(int dx, int dy) = 0;
    virtual bool isFriendly() = 0;
    virtual bool collidesWith(Sprite &sprite2) = 0;
    virtual u32 getHitboxX() = 0;
    virtual u32 getHitboxY() = 0;
    virtual u32 getHitboxWidth() = 0;
    virtual u32 getHitboxHeight() = 0;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ATTACK_H
