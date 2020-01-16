//
// Created by Mountsom3 on 11/01/2020.
//

#include "Bullet.h"
#include "../Sprite/sprites.h"

void Bullet::move(int x, int y) {
    moveTo(sprite->getPos().x + x, sprite->getPos().y + y);
}

void Bullet::moveTo(int x, int y) {
    sprite->moveTo(x, y);
}

void Bullet::setVelocity(int dx, int dy) {
    sprite->setVelocity(dx, dy);
}