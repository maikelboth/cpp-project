//
// Created by Maikel on 4-1-2020.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Boss.h"
#include "../Sprite/SpriteBoss.h"
#include "../Sprite/player.h"

Boss::Boss() {}

void Boss::move(int x, int y) {
    bossSprite->moveTo(bossSprite->getPos().x + x, bossSprite->getPos().y + y);
}

void Boss::moveTo(int x, int y) {
    bossSprite->moveTo(x, y);
}

void Boss::setVelocity(int dx, int dy) {
    bossSprite->setVelocity(dx, dy);
}

void Boss::reduceAttackCooldown(int ticks) {
    if (ticks > attackCooldown) attackCooldown = 0;
    else attackCooldown -= ticks;
}

void Boss::setHealth(int amount) {
    if (amount > health) health = 0;
    else health -= amount;
}

void Boss::load() {
    SpriteBuilder<Sprite> builder;

    bossSprite = builder
            .withData(B3Tiles, sizeof(B3Tiles))
            .withSize(SIZE_32_32)
            .withAnimated(1,8, 5)
            .withLocation(120-16, 32)
            .buildPtr();
}

Sprite * Boss::getSprite() {
    return bossSprite.get();
}