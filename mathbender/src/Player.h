//
// Created by Maikel on 26-12-2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_PLAYER_H
#define GBA_SPRITE_ENGINE_PROJECT_PLAYER_H


#include "Entity.h"

class Player : public Entity {
private:

public:
    Player();

    void move(int x, int y) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_PLAYER_H
