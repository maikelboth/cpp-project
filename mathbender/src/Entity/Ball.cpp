//
// Created by Maikel on 6-1-2020.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Ball.h"
//#include "../Sprite/SpriteBall.h"
#include "../Sprite/player.h"

void Ball::move(int x, int y) {
    ballSprite->moveTo(ballSprite->getPos().x + x, ballSprite->getPos().y + y);
}

void Ball::moveTo(int x, int y) {
    ballSprite->moveTo(x, y);
}

void Ball::setVelocity(int dx, int dy) {
    ballSprite->setVelocity(dx, dy);
}

void Ball::load() {
    SpriteBuilder<Sprite> builder;

    ballSprite = builder
            .withData(F3Tiles, sizeof(F3Tiles))
            .withAnimated(12, 3)
            .withSize(SIZE_8_32)
            .buildPtr();
}


Ball::~Ball(){
    ballSprite.get()->moveTo(0, 0);
    ballSprite.reset();
}
