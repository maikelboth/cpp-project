//
// Created by Maikel on 26-12-2019.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <algorithm>
#include "EntityManager.h"

EntityManager::EntityManager() {}

std::vector<Sprite *> EntityManager::getSprites() {
    std::vector<Sprite *> sprites;
    sprites.push_back(player->getSprite());
    sprites.push_back(boss->getSprite());

    for (auto & attack : attacks) {
        sprites.push_back(attack.get()->getSprite());
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

void EntityManager::addAttack(Attack * newAttack) {
    newAttack->getSprite()->setStayWithinBounds(false);
    attacks.insert(attacks.begin(), std::unique_ptr<Attack>(newAttack));
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
            // Reduce boss health
            removeAttack(a->get());
        } else if (a->get()->getSprite()->collidesWith(*player->getSprite()) && !a->get()->isFriendly()) {
            // Reduce player health
            removeAttack(a->get());
        }
    }
}

void EntityManager::removeAttacksInShadowRealm() {
    for (auto a = attacks.begin(); a < attacks.end(); a++) {
        if (a->get()->getSprite()->getY() > 128) attacks.erase(a);
    }
}

void EntityManager::tick() {
    removeAttacksInShadowRealm();

    if (boss->isAttackOnCooldown()) boss->reduceAttackCooldown(1);
    if (player->isAttackOnCooldown()) player->reduceAttackCooldown(1);

    collisionCheck();
}
