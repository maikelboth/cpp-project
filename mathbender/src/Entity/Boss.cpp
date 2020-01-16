//
// Created by Maikel on 4-1-2020.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "Boss.h"
#include "../Sprite/sprites.h"
#include "Fireball.h"
#include "Bullet.h"

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

void Boss::reduceHealth(int amount) {
    if (amount > health) health = 0;
    else health -= amount;
}

void Boss::setHealth(int amount) {
    if (amount > maxHealth) health = maxHealth;
    else health = amount;
}

void Boss::respawn() {
    setHealth(maxHealth);
    moveTo(spawnPosition.x, spawnPosition.y);
}

void Boss::load() {
    builder = std::make_unique<SpriteBuilder<Sprite>>();

    bossSprite = builder
            ->withData(B4Tiles, sizeof(B4Tiles))
            .withSize(SIZE_32_32)
            .withAnimated(0,8, 5)
            .withLocation(spawnPosition.x, spawnPosition.y)
            .buildPtr();

    bulletSprite = builder
            ->withData(bulletTiles, sizeof(bulletTiles))
            .withLocation(GBA_SCREEN_WIDTH + 20, GBA_SCREEN_HEIGHT + 20)
            .withSize(SIZE_16_16)
            .buildPtr();
}

Sprite* Boss::getSprite() {
    return bossSprite.get();
}

std::vector<Sprite *> Boss::getTemplateSprites() {
    return {bulletSprite.get()};
}

std::unique_ptr<Attack> Boss::attack() {
    attackCooldown = maxAttackCooldown;

    // Create attack with appropriate velocity dx,dy.
    std::unique_ptr<Attack> bullet = std::unique_ptr<Attack>(new Bullet(builder->buildWithDataOf(*bulletSprite), false));
    bullet->moveTo(bossSprite->getCenter().x - (bullet->getSprite()->getWidth() / 2), bossSprite->getY() + bossSprite->getHeight() - bullet->getSprite()->getHeight());
    bullet->setVelocity(0, 1);

    return bullet;
}