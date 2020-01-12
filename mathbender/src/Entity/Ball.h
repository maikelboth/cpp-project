//
// Created by Maikel on 6-1-2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BALL_H
#define GBA_SPRITE_ENGINE_PROJECT_BALL_H


#include "Attack.h"

class Ball : public Attack {

private:
    Type attackType = PROJECTILE;
    std::unique_ptr<Sprite> ballSprite;
public:
    Ball() = default;
    ~Ball();

    Type getAttackType() override { return attackType; }
    Sprite* getSprite() override { return ballSprite.get(); };
    void load() override;
    void move(int x, int y);
    void moveTo(int x, int y) override;
    void setVelocity(int dx, int dy) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BALL_H
