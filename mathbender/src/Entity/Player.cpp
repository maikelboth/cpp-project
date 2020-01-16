//
// Created by Maikel on 26-12-2019.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>

#include <memory>
#include <libgba-sprite-engine/gba_engine.h>
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

    playerSprite = builder
            ->withData(playerTiles, sizeof(playerTiles))
            .withSize(SIZE_16_16)
            .withLocation(120, 100)
            .buildPtr();

    fireballSprite = builder
            ->withData(F3Tiles, sizeof(F3Tiles))
            .withLocation(1,1)
            .withAnimated(0,12, 10)
            .withSize(SIZE_8_32)
            .buildPtr();

    waterSprite = builder
            ->withData(W2Tiles, sizeof(W2Tiles))
            .withLocation(GBA_SCREEN_WIDTH + 20, GBA_SCREEN_HEIGHT + 20)
            .withAnimated(9, 3)
            .withSize(SIZE_16_32)
            .buildPtr();
}

Sprite* Player::getSprite() {
    return playerSprite.get();
}

std::vector<Sprite *> Player::getTemplateSprites() {
    return {fireballSprite.get(), waterSprite.get()};
}

Attack* Player::attack(AttackType type) {
    attackCooldown = maxAttackCooldown;

    Attack *attack = nullptr;

    switch (type) {
        case WATER:
            attack = new Water(builder->buildWithDataOf(*waterSprite), true);
            break;
        case FIRE:
            attack = new Fireball(builder->buildWithDataOf(*fireballSprite), true);
            break;
    }
    if (attack == nullptr)
        attack = new Fireball(builder->buildWithDataOf(*fireballSprite), true);

    attack->moveTo(playerSprite->getCenter().x - (attack->getSprite()->getWidth() / 2), playerSprite->getY() + playerSprite->getHeight() - attack->getSprite()->getHeight());
    if (type != WATER) attack->setVelocity(0, -1);
    return attack;
}