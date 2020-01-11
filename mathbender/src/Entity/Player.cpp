//
// Created by Maikel on 26-12-2019.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include "Player.h"
#include "../Sprite/kul.h"
#include "Ball.h"

Player::Player() : Entity() {}

void Player::move(int x, int y) {
    playerSprite->moveTo(playerSprite->getPos().x + x, playerSprite->getPos().y + y);
    if (abs(x) > abs(y)) {
        if (x > 0) spriteDirection = RIGHT;
        if (x < 0) spriteDirection = LEFT;
    } else {
        if (y > 0) spriteDirection = DOWN;
        if (y < 0) spriteDirection = UP;
    }
}

void Player::moveTo(int x, int y) {
    playerSprite->moveTo(x, y);
}

void Player::setVelocity(int dx, int dy) {
    playerSprite->setVelocity(dx, dy);
}

void Player::reduceAttackCooldown(int ticks) {
    if (ticks > attackCooldown) attackCooldown = 0;
    else attackCooldown -= ticks;
}

void Player::setHealth(int amount) {
    if (amount > health) health = 0;
    else health -= amount;
}

void Player::load() {
    SpriteBuilder<Sprite> builder;

    playerSprite = builder
            .withData(kulTiles, sizeof(kulTiles))
            .withSize(SIZE_64_32)
            .withLocation(30, 30)
            .buildPtr();
}

Sprite * Player::getSprite() {
    return playerSprite.get();
}

Attack * Player::attack() {
    attackCooldown = maxAttackCooldown;

    // Direction of attack depending on sprite direction
    int dx = 0;
    int dy = 0;

    switch (spriteDirection) {
        case UP:
            dy = -1;
            break;
        case DOWN:
            dy = 1;
            break;
        case LEFT:
            dx = -1;
            break;
        case RIGHT:
            dx = 1;
            break;
    }

    // Create attack with appropriate velocity dx,dy.
    Ball * ball = new Ball();
    ball->load();
    ball->moveTo(playerSprite->getCenter().x - (ball->getSprite()->getWidth()/2), playerSprite->getCenter().y - (ball->getSprite()->getHeight()/2));
    ball->setVelocity(dx, dy);

    return ball;
}