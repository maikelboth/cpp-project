//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <engine/gba/tonc_memdef.h>
#include <engine/gba/tonc_oam.h>

#include "affine_sprite.h"

void AffineSprite::identity() {
    obj_aff_identity(this->affine.get());
}

void AffineSprite::rotate(u16 alpha) {
    obj_aff_rotate(this->affine.get(), alpha);
}

void AffineSprite::syncOam() {
    Sprite::syncOam();
    rebuildOamAttr1ForAffineIndex();
}

void AffineSprite::setTransformationMatrix(OBJ_AFFINE *matrix) {
    // Only copy over affine related pX properties, watch out with OAM overlapping!
    obj_aff_copy(matrix, this->affine.get(), 1);
    //obj_aff_identity(matrix);
    //obj_aff_scale(matrix, 1, 2);
    //obj_aff_postmul(matrix, this->affine.get());
}

void AffineSprite::rebuildOamAttr1ForAffineIndex() {
    this->oam->attr1 = this->x |
                       ATTR1_AFF_ID(affIndex) |
                       (HORIZONTAL_FLIP_FLAG << 12) |
                       (VERTICAL_FLIP_FLAG << 13) |
                       (this->size_bits << 14);
}

void AffineSprite::buildOam(int tileIndex) {
    Sprite::buildOam(tileIndex);
    this->oam->attr0 = ATTR0_Y(this->y) |
                       ATTR0_MODE(1) |
                       (GFX_MODE << 10) |
                       (MOSAIC_MODE << 12) |
                       (COLOR_MODE_256 << 13) |
                       (this->shape_bits << 14);
    rebuildOamAttr1ForAffineIndex();

    this->affine = std::unique_ptr<OBJ_AFFINE>(new OBJ_AFFINE());
    identity();
}
