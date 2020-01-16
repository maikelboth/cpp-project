//
// Created by Maikel on 6-1-2020.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Fireball.h"
#include "../Sprite/sprites.h"

void Fireball::move(int x, int y) {
    sprite->moveTo(sprite->getPos().x + x, sprite->getPos().y + y);
}

void Fireball::moveTo(int x, int y) {
    sprite->moveTo(x, y);
}

void Fireball::setVelocity(int dx, int dy) {
    sprite->setVelocity(dx, dy);
}

void Fireball::load() {}


Fireball::~Fireball(){
    sprite->moveTo(0, 0);
    sprite.reset();
}
