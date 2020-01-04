//
// Created by Maikel on 4-1-2020.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Boss.h"
#include "sprites/SpriteBoss.h"

Boss::Boss() : Entity() {}

void Boss::move(int x, int y) {
    bossSprite->moveTo(bossSprite->getPos().x + x, bossSprite->getPos().y + y);
}

void Boss::setVelocity(int dx, int dy) {
    bossSprite->setVelocity(dx, dy);
}

void Boss::load() {
    SpriteBuilder<Sprite> builder;

    bossSprite = builder
            .withData(bossTiles, sizeof(bossTiles))
            .withSize(SIZE_64_32)
            .withLocation(60, 60)
            .buildPtr();
}

Sprite * Boss::getSprite() {
    return bossSprite.get();
}