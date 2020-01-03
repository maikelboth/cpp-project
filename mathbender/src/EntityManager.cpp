//
// Created by Maikel on 26-12-2019.
//

#include "EntityManager.h"

EntityManager::EntityManager() {}

std::vector<Sprite *> EntityManager::getSprites() {
    return {
        player->getSprite()
    };
}

void EntityManager::load() {
    player = std::make_unique<Player>();
    player->load();
}
