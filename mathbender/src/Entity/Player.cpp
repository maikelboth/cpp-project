//
// Created by Maikel on 26-12-2019.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include "Player.h"
//#include "../Sprite/kul.h"
#include "../Sprite/player.h"
#include "Ball.h"

Player::Player() {}

void Player::move(int x, int y) {
    playerSprite->moveTo(playerSprite->getPos().x + x, playerSprite->getPos().y + y);
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
            .withData(playerTiles, sizeof(playerTiles))
            .withSize(SIZE_16_16)
            .withLocation(120, 100)
            .buildPtr();
}

Sprite* Player::getSprite() {
    return playerSprite.get();
}

Attack * Player::attack() {
    attackCooldown = maxAttackCooldown;

    // Create attack with appropriate velocity dx,dy.
    Ball * ball = new Ball();
    ball->load();
    ball->moveTo(playerSprite->getCenter().x - (ball->getSprite()->getWidth()/2), playerSprite->getCenter().y - (ball->getSprite()->getHeight()/2));
    ball->setVelocity(0, -1);

    return ball;
}