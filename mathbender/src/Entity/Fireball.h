//
// Created by Maikel on 6-1-2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_FIREBALL_H
#define GBA_SPRITE_ENGINE_PROJECT_FIREBALL_H


#include "Attack.h"

class Fireball : public Attack {

private:
    std::unique_ptr<Sprite> sprite;
    bool friendly;
    int damage = 5;
public:
    Fireball(std::unique_ptr<Sprite> sprite, bool isFriendly) : sprite(std::move(sprite)), friendly(isFriendly) {};

    Sprite* getSprite() override { return sprite.get(); };
    int getDamage() override { return damage; };
    void move(int x, int y);
    void moveTo(int x, int y) override;
    void setVelocity(int dx, int dy) override;
    bool isFriendly() override { return friendly; };
    bool collidesWith(Sprite &sprite2) override { return sprite->collidesWith(sprite2); };
    u32 getHitboxX() override { return sprite->getX(); };
    u32 getHitboxY() override { return sprite->getY(); };
    u32 getHitboxWidth() override { return sprite->getWidth(); };
    u32 getHitboxHeight() override { return sprite->getHeight(); };
};


#endif //GBA_SPRITE_ENGINE_PROJECT_FIREBALL_H
