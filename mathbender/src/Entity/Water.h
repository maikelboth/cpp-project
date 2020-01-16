//
// Created by Maikel on 16-1-2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_WATER_H
#define GBA_SPRITE_ENGINE_PROJECT_WATER_H


#include "Attack.h"

class Water : public Attack {

private:
    std::unique_ptr<Sprite> sprite;
    bool friendly;
    int damage = 5;
public:
    Water(std::unique_ptr<Sprite> sprite, bool isFriendly) : sprite(std::move(sprite)), friendly(isFriendly) {};

    Sprite* getSprite() override { return sprite.get(); };
    int getDamage() override { return damage; };
    void move(int x, int y);
    void moveTo(int x, int y) override;
    void setVelocity(int dx, int dy) override;
    bool isFriendly() override { return friendly; };
    bool collidesWith(Sprite &sprite2) override;
    u32 getHitboxX() override;
    u32 getHitboxY() override;
    u32 getHitboxWidth() override;
    u32 getHitboxHeight() override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_WATER_H
