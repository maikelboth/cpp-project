//
// Created by Maikel on 16-1-2020.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "Water.h"
#include "../Sprite/sprites.h"

void Water::move(int x, int y) {
    moveTo(sprite->getPos().x + x, sprite->getPos().y + y);
}

void Water::moveTo(int x, int y) {
    sprite->moveTo(x, y);
}

void Water::setVelocity(int dx, int dy) {
    sprite->setVelocity(dx, dy);
}

bool Water::collidesWith(Sprite &sprite2) {

    return getHitboxX() < sprite2.getX() + sprite2.getWidth() &&
        getHitboxX() + getHitboxWidth() > sprite2.getX() &&
        getHitboxY() < sprite2.getY() + sprite2.getHeight() &&
        getHitboxY() + getHitboxHeight() > sprite2.getY();
}

u32 Water::getHitboxX() {
    u32 hitboxWidth = getHitboxWidth();
    u32 currentFrame = sprite->getCurrentFrame();
    u32 numberOfFrames = sprite->getNumberOfFrames();

    if (currentFrame < numberOfFrames / 2) {
        return sprite->getX() + (currentFrame * hitboxWidth);
    } else if (currentFrame > numberOfFrames / 2) {
        return sprite->getX() + ((numberOfFrames - currentFrame) * hitboxWidth);
    } else {
        return sprite->getX() + sprite->getWidth() - hitboxWidth;
    }
}

u32 Water::getHitboxY() {
    return sprite->getY() + ((sprite->getNumberOfFrames() - (sprite->getCurrentFrame() + 1)) * (sprite->getHeight() / sprite->getNumberOfFrames()));
}

u32 Water::getHitboxHeight() {
    return sprite->getHeight() / sprite->getNumberOfFrames();
}

u32 Water::getHitboxWidth() {
    return sprite->getWidth() / (sprite->getNumberOfFrames() / 2);
}
