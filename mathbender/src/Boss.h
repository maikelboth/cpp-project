//
// Created by Maikel on 4-1-2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BOSS_H
#define GBA_SPRITE_ENGINE_PROJECT_BOSS_H


#include <libgba-sprite-engine/sprites/sprite.h>
#include <vector>
#include "Entity.h"

class Boss : public Entity {
private:
    std::unique_ptr<Sprite> bossSprite;

public:
    Boss();

    Sprite * getSprite();
    void load();
    void move(int x, int y) override;
    void setVelocity(int dx, int dy) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_BOSS_H
