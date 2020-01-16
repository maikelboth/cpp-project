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
            .withData(playerTiles, sizeof(playerTiles))
            .withSize(SIZE_16_16)
            .withLocation(120, 100)
            .buildPtr();

    fireballSprite = builder
            .withData(F3Tiles, sizeof(F3Tiles))
            .withLocation(1,1)
            .withAnimated(0,12, 10)
            .withSize(SIZE_8_32)
            .buildPtr();

    waterSprite = builder
            .withData(W3Tiles, sizeof(W3Tiles))
            //.withLocation(GBA_SCREEN_WIDTH + 20, GBA_SCREEN_HEIGHT + 20)
            .withLocation(0, 32)
            .withAnimated(9, 3)
            .withSize(SIZE_32_64)
            .buildPtr();
}

Sprite* Player::getSprite() {
    return playerSprite.get();
}

std::vector<Sprite *> Player::getTemplateSprites() {
    return {fireballSprite.get(), waterSprite.get()};
}

std::unique_ptr<Attack> Player::attack(AttackType type) {
    attackCooldown = maxAttackCooldown;

    switch (type) {
        case WATER:
            return std::unique_ptr<Attack>(new Water(builder
                    .withLocation(playerSprite->getCenter().x - (waterSprite->getWidth() / 2), playerSprite->getY() - waterSprite->getHeight())
                    .withVelocity(0, 0)
                    .withAnimated(0, 9, 3)
                    .buildWithDataOf(*waterSprite), true));
        case FIRE:
            return std::unique_ptr<Attack>(new Fireball(builder
                    .withLocation(playerSprite->getCenter().x - (fireballSprite->getWidth() / 2), playerSprite->getY() + playerSprite->getHeight() - fireballSprite->getHeight())
                    .withVelocity(0, -1)
                    .withAnimated(0, 12, 3)
                    .buildWithDataOf(*fireballSprite), true));
    }

    return std::unique_ptr<Attack>(new Fireball(builder
        .withLocation(playerSprite->getCenter().x - (fireballSprite->getWidth() / 2), playerSprite->getY() + playerSprite->getHeight() - fireballSprite->getHeight())
        .withVelocity(0, -1)
        .withAnimated(0, 12, 3)
        .buildWithDataOf(*fireballSprite), true));
}