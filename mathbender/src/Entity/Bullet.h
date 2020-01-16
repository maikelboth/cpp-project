//
// Created by Mountsom3 on 11/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BULLET_H
#define GBA_SPRITE_ENGINE_PROJECT_BULLET_H


#include <libgba-sprite-engine/sprites/sprite.h>
#include "Attack.h"

class Bullet : public Attack {

private:
    std::unique_ptr<Sprite> bulletSprite;
    bool friendly;
    int damage = 5;
public:
    Bullet(bool isFriendly) { friendly = isFriendly; };
    ~Bullet();

    Sprite* getSprite() override { return bulletSprite.get(); };
    int getDamage() override { return damage; };
    void move(int x, int y);
    void moveTo(int x, int y) override;
    void setVelocity(int dx, int dy) override;
    bool isFriendly() override { return friendly; };
    void load() override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BULLET_H
