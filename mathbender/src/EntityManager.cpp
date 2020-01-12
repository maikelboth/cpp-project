//
// Created by Maikel on 26-12-2019.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
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
    //attacks.push_back(std::unique_ptr<Attack>(newAttack));
}

void EntityManager::collisionCheck() {
    int n = attacks.size();
    for (auto a = attacks.begin(); a < attacks.end(); a++) {
        if (a->get()->getSprite()->getY() > 128) attacks.erase(a);
        else if (a->get()->getSprite()->getY() < 24) {
            a->get()->moveTo(0, 200); // sends sprites to the shadow-realm
        }
    }
}

void EntityManager::tick() {
    if (boss->isAttackOnCooldown()) boss->reduceAttackCooldown(1);
    if (player->isAttackOnCooldown()) player->reduceAttackCooldown(1);

    collisionCheck();
}
