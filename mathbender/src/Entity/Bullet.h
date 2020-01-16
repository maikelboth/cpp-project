//
// Created by Mountsom3 on 11/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BULLET_H
#define GBA_SPRITE_ENGINE_PROJECT_BULLET_H


#include <libgba-sprite-engine/sprites/sprite.h>
#include "Attack.h"

class Bullet : public Attack {

private:
    std::unique_ptr<Sprite> sprite;
    bool friendly;
    int damage = 5;
public:
    Bullet(std::unique_ptr<Sprite> sprite, bool isFriendly) : sprite(std::move(sprite)), friendly(isFriendly) {};

    Sprite* getSprite() override { return sprite.get(); };
    int getDamage() override { return damage; };
    void move(int x, int y);
    void moveTo(int x, int y) override;
    void setVelocity(int dx, int dy) override;
    bool isFriendly() override { return friendly; };
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BULLET_H
