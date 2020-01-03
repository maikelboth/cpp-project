//
// Created by Maikel on 26-12-2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_PLAYER_H
#define GBA_SPRITE_ENGINE_PROJECT_PLAYER_H


#include <libgba-sprite-engine/sprites/sprite.h>
#include <vector>
#include "Entity.h"

class Player : public Entity {
private:
    std::unique_ptr<Sprite> playerSprite;

public:
    Player();

    std::vector<Sprite *> getSprite();

    void load();
    void move(int x, int y) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_PLAYER_H
