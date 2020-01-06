//
// Created by Maikel on 26-12-2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_PLAYER_H
#define GBA_SPRITE_ENGINE_PROJECT_PLAYER_H


#include <libgba-sprite-engine/sprites/sprite.h>
#include <vector>
#include "Entity.h"
#include "Attack.h"

class Player : public Entity {
    enum Direction {UP, DOWN, RIGHT, LEFT};

private:
    std::unique_ptr<Sprite> playerSprite;
    Direction spriteDirection;

public:
    Player();

    Sprite * getSprite();
    void load();
    void move(int x, int y);
    void moveTo(int x, int y) override;
    void setVelocity(int dx, int dy) override;
    Attack * attack();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_PLAYER_H
