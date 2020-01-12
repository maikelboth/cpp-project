//
// Created by Mountsom3 on 11/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_FIRE_H
#define GBA_SPRITE_ENGINE_PROJECT_FIRE_H


#include <libgba-sprite-engine/sprites/sprite.h>
#include "Attack.h"

class Fire : public Attack {

private:
    Type attackType = PROJECTILE;
    std::unique_ptr<Sprite> fireSprite;
public:
    Fire() = default;

    Type getAttackType() override { return attackType; }
    Sprite* getSprite() override { return fireSprite.get(); };
    void load() override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_FIRE_H
