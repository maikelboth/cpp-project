//
// Created by Maikel on 26-12-2019.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Player.h"
#include "sprites/kul.h"

Player::Player() : Entity() {}

void Player::move(int x, int y) {

}

void Player::load() {
    SpriteBuilder<Sprite> builder;

    playerSprite = builder
            .withData(kulTiles, sizeof(kulTiles))
            .withSize(SIZE_64_32)
            .withLocation(30, 30)
            .buildPtr();
}

std::vector<Sprite *> Player::getSprite() {
    return {
            playerSprite.get()
    };
}