//
// Created by Maikel on 26-12-2019.
//

#include <libgba-sprite-engine/background/text_stream.h>
#include "EntityManager.h"

EntityManager::EntityManager() {}

std::vector<Sprite *> EntityManager::getSprites() {
    std::vector<Sprite *> sprites;
    sprites.push_back(player->getSprite());
    sprites.push_back(boss->getSprite());

    for (auto attack = attacks.begin(); attack != attacks.end(); ++attack) {
        sprites.push_back(attack->get()->getSprite());
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
    attacks.push_back(std::unique_ptr<Attack>(newAttack));
}
