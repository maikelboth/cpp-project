//
// Created by Maikel on 16-1-2020.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Water.h"
#include "../Sprite/sprites.h"

void Water::move(int x, int y) {
    moveTo(sprite->getPos().x + x, sprite->getPos().y + y);
}

void Water::moveTo(int x, int y) {
    sprite->moveTo(x, y);
}

void Water::setVelocity(int dx, int dy) {
    sprite->setVelocity(dx, dy);
}