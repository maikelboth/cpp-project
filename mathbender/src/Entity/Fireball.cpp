//
// Created by Maikel on 6-1-2020.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Fireball.h"
#include "../Sprite/sprites.h"

void Fireball::move(int x, int y) {
    fireballSprite->moveTo(fireballSprite->getPos().x + x, fireballSprite->getPos().y + y);
}

void Fireball::moveTo(int x, int y) {
    fireballSprite->moveTo(x, y);
}

void Fireball::setVelocity(int dx, int dy) {
    fireballSprite->setVelocity(dx, dy);
}

void Fireball::load() {
    SpriteBuilder<Sprite> builder;

    fireballSprite = builder
            .withData(F3Tiles, sizeof(F3Tiles))
            .withAnimated(12, 3)
            .withSize(SIZE_8_32)
            .buildPtr();
}


Fireball::~Fireball(){
    fireballSprite.get()->moveTo(0, 0);
    fireballSprite.reset();
}
