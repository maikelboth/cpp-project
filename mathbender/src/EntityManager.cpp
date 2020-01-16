//
// Created by Maikel on 26-12-2019.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <algorithm>
#include "EntityManager.h"
#include "Entity/Water.h"

EntityManager::EntityManager() {}

std::vector<Sprite *> EntityManager::getSprites() {
    std::vector<Sprite *> sprites;
    sprites.push_back(player->getSprite());
    sprites.push_back(boss->getSprite());

    for (auto & attack : attacks) {
        sprites.push_back(attack.get()->getSprite());
    }

    for (auto & templateSprite : player->getTemplateSprites()) {
        sprites.push_back(templateSprite);
    }

    for (auto & templateSprite : boss->getTemplateSprites()) {
        sprites.push_back(templateSprite);
    }

    return sprites;
}

void EntityManager::load() {
    player = std::make_unique<Player>();
    player->load();

    boss = std::make_unique<Boss>();
    boss->load();
}

std::vector<Attack *> EntityManager::getAttacks() {
    std::vector<Attack *> result;

    for (auto & attack : attacks) {
        result.push_back(attack.get());
    }
    return result;
}

void EntityManager::addAttack(const std::shared_ptr<Attack>& newAttack) {
    if (newAttack == nullptr) return;
    newAttack->getSprite()->setStayWithinBounds(false);
    attacks.insert(attacks.begin(), newAttack);
}

void EntityManager::removeAttack(Attack* attack) {
    for (auto a = attacks.begin(); a < attacks.end(); a++) {
        if (a->get() == attack) {
            a->get()->moveTo(0, 200); // sends sprites to the shadow-realm
        }
    }
}

void EntityManager::collisionCheck() {
    for (auto a = attacks.begin(); a < attacks.end(); a++) {
        if (a->get()->getSprite()->collidesWith(*boss->getSprite()) && a->get()->isFriendly()) {
            boss->reduceHealth(a->get()->getDamage());
            removeAttack(a->get());
            if (boss->isDead()) {
                // Spawn new boss with more health.
                level++;
                boss->setMaxHealth(20 + 4*level);
                boss->respawn();
            }
        } else if (a->get()->getSprite()->collidesWith(*player->getSprite()) && !a->get()->isFriendly()) {
            player->reduceHealth(a->get()->getDamage());
            removeAttack(a->get());
        }
    }
}

void EntityManager::removeAttacksInShadowRealm() {
    for (auto a = attacks.begin(); a < attacks.end(); a++) {
        if (a->get()->getSprite()->getY() > 128) attacks.erase(a);
    }
}

bool EntityManager::isOutOfMap(Sprite* sprite) {
    int xLeft = sprite->getX();
    int xRight = sprite->getX() + sprite->getWidth();
    int yTop = sprite->getY();
    int yBottom = sprite->getY() + sprite->getHeight();

    return isOutOfMap(xLeft, xRight, yTop, yBottom);
}

bool EntityManager::isOutOfMap(int xLeft, int xRight, int yTop, int yBottom) {
    return (yTop < 25 || yBottom > 140) || (xLeft < 20 || xRight > 220) || ((xLeft < 46 || xRight > 194) && yTop < 57) || ((xLeft < 62 || xRight > 178) && yTop < 41);
}

bool EntityManager::canMove(Sprite* sprite, int dx, int dy) {
    double xLeft = sprite->getX() + dx;
    double xRight = sprite->getX() + sprite->getWidth() + dx;
    double yTop = sprite->getY() + dy;
    double yBottom = sprite->getY() + sprite->getHeight() + dy;

    return !isOutOfMap(xLeft, xRight, yTop, yBottom);
}

int EntityManager::calculateScore() {
    return level;
}

void EntityManager::bossAI() {
    if (boss->getSprite()->getCenter().x < player->getSprite()->getCenter().x) {
        if (canMove(boss->getSprite(), 1, 0)) {
            boss->move(1, 0);
        }
    } else if (boss->getSprite()->getCenter().x > player->getSprite()->getCenter().x) {
        if (canMove(boss->getSprite(), -1, 0)) {
            boss->move(-1, 0);
        }
    }

    if (!boss->isAttackOnCooldown()) {
        addAttack(boss->attack());
    }
}

void EntityManager::tick(u16 keys) {
    removeAttacksInShadowRealm();

    if (boss->isAttackOnCooldown()) boss->reduceAttackCooldown(1);
    if (player->isAttackOnCooldown()) player->reduceAttackCooldown(1);

    for (auto & attack : attacks) {
        if (isOutOfMap(attack->getSprite())) {
            removeAttack(attack.get());
        }

        if (dynamic_cast<const Water*>(attack.get()) != nullptr) { // Check if attack is Water attack
            if (attack->getSprite()->getCurrentFrame() >= attack->getSprite()->getNumberOfFrames()-1) {
                removeAttack(attack.get());
            }
        }
    }

    if (keys & KEY_A) { // attack
        if (!player->isAttackOnCooldown()) {
            addAttack(player->attack(Player::FIRE));
        }
    }
    if (keys & KEY_B) {
        if (!player->isAttackOnCooldown()) {
            addAttack(player->attack(Player::WATER));
        }
    }
    if (keys & KEY_LEFT) {
        if (canMove(player->getSprite(), -1, 0))
            player->move(-1, 0);
    }
    if (keys & KEY_RIGHT) {
        if (canMove(player->getSprite(), 1, 0))
            player->move(1, 0);
    }
    if (keys & KEY_UP) {
        if (canMove(player->getSprite(), 0, -1))
            player->move(0, -1);
    }
    if (keys & KEY_DOWN) {
        if (canMove(player->getSprite(), 0, 1))
            player->move(0, 1);
    }
    bossAI();
    collisionCheck();
}
