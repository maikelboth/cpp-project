//
// Created by Maikel on 26-12-2019.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include "Player.h"
#include "../Sprite/sprites.h"
#include "Fireball.h"
#include "Water.h"

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

void Player::reduceHealth(int amount) {
    if (amount > health) health = 0;
    else health -= amount;
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

Attack* Player::attack(AttackType type) {
    attackCooldown = maxAttackCooldown;

    Attack *attack = nullptr;

    switch (type) {
        case WATER:
            attack = new Water(true);
            break;
        case FIRE:
            attack = new Fireball(true);
            break;
    }
    if (attack == nullptr)
        attack = new Fireball(true);

    attack->load();
    attack->moveTo(playerSprite->getCenter().x - (attack->getSprite()->getWidth() / 2), playerSprite->getY() + playerSprite->getHeight() - attack->getSprite()->getHeight());
    attack->setVelocity(0, -1);

    return attack;

}