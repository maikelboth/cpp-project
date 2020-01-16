//
// Created by Mountsom3 on 11/01/2020.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Bullet.h"
#include "../Sprite/sprites.h"

void Bullet::move(int x, int y) {
    moveTo(bulletSprite->getPos().x + x, bulletSprite->getPos().y + y);
}

void Bullet::moveTo(int x, int y) {
    bulletSprite->moveTo(x, y);
}

void Bullet::setVelocity(int dx, int dy) {
    bulletSprite->setVelocity(dx, dy);
}

void Bullet::load() {
    SpriteBuilder<Sprite> builder;

    bulletSprite = builder
            .withData(bulletTiles, sizeof(bulletTiles))
            .withSize(SIZE_16_16)
            .buildPtr();
}

Bullet::~Bullet() {
    bulletSprite->moveTo(0, 0);
    bulletSprite.reset();
}