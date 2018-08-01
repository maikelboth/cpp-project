//
// Created by Wouter Groeneveld on 26/07/18.
//

#include <cstdlib>
#include <engine/gba/tonc_memdef.h>
#include "sprite.h"

Sprite::Sprite(const void *imageData, int imageSize, int x, int y, SpriteSize size)
        : x(x), y(y), data(imageData), imageSize(imageSize) {
    setAttributesBasedOnSize(size);
}

void Sprite::moveTo(int x, int y) {
    this->x = x;
    this->y = y;
    syncOam();
}

void Sprite::syncOam() {
    oam->attr0 = (oam->attr0 &  ~ATTR0_Y_MASK) | (y & ATTR0_Y_MASK);
    oam->attr1 = (oam->attr1 & ~ATTR1_X_MASK) | (x & ATTR1_X_MASK);
}

void Sprite::move() {
    this->x += this->dx;
    this-> y += this->dy;
    syncOam();
}

void Sprite::setAttributesBasedOnSize(SpriteSize size) {
    switch (size) {
        case SIZE_8_8:   size_bits = 0; shape_bits = 0; w = 8; h = 8; break;
        case SIZE_16_16: size_bits = 1; shape_bits = 0; w = 16; h = 16; break;
        case SIZE_32_32: size_bits = 2; shape_bits = 0; w = 32; h = 32; break;
        case SIZE_64_64: size_bits = 3; shape_bits = 0; w = 64; h = 64; break;
        case SIZE_16_8:  size_bits = 0; shape_bits = 1; w = 16; h = 8; break;
        case SIZE_32_8:  size_bits = 1; shape_bits = 1; w = 32; h = 8; break;
        case SIZE_32_16: size_bits = 2; shape_bits = 1; w = 32; h = 16; break;
        case SIZE_64_32: size_bits = 3; shape_bits = 1; w = 64; h = 32; break;
        case SIZE_8_16:  size_bits = 0; shape_bits = 2; w = 8; h = 16; break;
        case SIZE_8_32:  size_bits = 1; shape_bits = 2; w = 8; h = 32; break;
        case SIZE_16_32: size_bits = 2; shape_bits = 2; w = 16; h = 32; break;
        case SIZE_32_64: size_bits = 3; shape_bits = 2; w = 32; h = 64; break;
    }
}

bool Sprite::collidesWith(const Sprite &o) {
    const Sprite &s = *this;
    if((abs(s.x - o.x) < (s.w + o.w) / 2)
       && abs(s.y - o.y) < (s.h + o.h) / 2) {
        return true;
    }
    return false;
}


void Sprite::buildOam(int tileIndex) {
    this->oam = std::unique_ptr<OBJ_ATTR>(new OBJ_ATTR());

    this->oam->attr0 = ATTR0_Y(this->y) |
            ATTR0_MODE(0) |
            (GFX_MODE << 10) |
            (MOSAIC_MODE << 12) |
            (COLOR_MODE_256 << 13) |
            (this->shape_bits << 14);
    this->oam->attr1 = this->x |
            (AFFINE_FLAG_NONE_SET_YET << 9) |
            (HORIZONTAL_FLIP_FLAG << 12) |
            (VERTICAL_FLIP_FLAG << 13) |
            (this->size_bits << 14);

    this->oam->attr2 = ATTR2_ID(tileIndex) |
            ATTR2_PRIO(priority) |
            ATTR2_PALBANK(0);
}