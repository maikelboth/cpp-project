//
// Created by Maikel on 26-12-2019.
//

#include "StartScreen.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>

#include <memory>
#include "sprites/kul.h"

StartScreen::StartScreen(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> StartScreen::sprites() {
    return {
        entityManager->getSprites()
    };
}

std::vector<Background *> StartScreen::backgrounds() {
    return {
//        bg.get()
    };
}

void StartScreen::load() {
    entityManager = std::make_unique<EntityManager>();
    entityManager->load();

    foregroundPalette = std::make_unique<ForegroundPaletteManager>(sharedPal, sizeof(sharedPal));
//    backgroundPalette = std::make_unique<BackgroundPaletteManager>(bg_palette, sizeof(bg_palette));

//    bg = std::make_unique<Background>(1, background_data, sizeof(background_data), map, sizeof(map));
//    bg->useMapScreenBlock(16);
}

void StartScreen::tick(u16 keys) {}

