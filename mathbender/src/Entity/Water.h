//
// Created by Maikel on 16-1-2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_WATER_H
#define GBA_SPRITE_ENGINE_PROJECT_WATER_H


#include "Attack.h"

class Water : public Attack {

private:
    std::unique_ptr<Sprite> waterSprite;
    bool friendly;
    int damage = 5;
public:
    Water(bool isFriendly) { friendly = isFriendly;};
    ~Water();

    Sprite* getSprite() override { return waterSprite.get(); };
    int getDamage() override { return damage; };
    void load() override;
    void move(int x, int y);
    void moveTo(int x, int y) override;
    void setVelocity(int dx, int dy) override;
    bool isFriendly() override { return friendly; };
};


#endif //GBA_SPRITE_ENGINE_PROJECT_WATER_H
