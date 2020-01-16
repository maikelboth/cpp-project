//
// Created by Maikel on 16-1-2020.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Water.h"
#include "../Sprite/sprites.h"

void Water::move(int x, int y) {
    moveTo(waterSprite->getPos().x + x, waterSprite->getPos().y + y);
}

void Water::moveTo(int x, int y) {
    waterSprite->moveTo(x, y);
}

void Water::setVelocity(int dx, int dy) {
    waterSprite->setVelocity(dx, dy);
}

void Water::load() {
    SpriteBuilder<Sprite> builder;

    waterSprite = builder
            .withData(W2Tiles, sizeof(W2Tiles))
            .withAnimated(12, 3)
            .withSize(SIZE_16_32)
            .buildPtr();
}

Water::~Water() {
    waterSprite->moveTo(0, 0);
    waterSprite.reset();
}