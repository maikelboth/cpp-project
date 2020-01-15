//
// Created by Maikel on 26-12-2019.
//

#include "Level1Screen.h"
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>

#include <memory>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include "Sprite/level1BG.h"
//#include "Sprite/kul.h"
#include "Sprite/player.h"

#include "MainScreen.h"

#include <chrono>

Level1Screen::Level1Screen(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> Level1Screen::sprites() {
    return entityManager->getSprites();
}

std::vector<Background *> Level1Screen::backgrounds() {
    return {
        bg.get()
    };
}

void Level1Screen::load() {
    entityManager = std::make_unique<EntityManager>();
    entityManager->load();

    foregroundPalette = std::make_unique<ForegroundPaletteManager>(sharedPal, sizeof(sharedPal));
    backgroundPalette = std::make_unique<BackgroundPaletteManager>(level1BGPal, sizeof(level1BGPal));

    bg = std::make_unique<Background>(1, level1BGTiles, sizeof(level1BGTiles), level1BGMap, sizeof(level1BGMap));
    bg->useMapScreenBlock(16);
}

void Level1Screen::tick(u16 keys) {
    int attackAmount = entityManager->getAttacks().size();

    TextStream::instance().setText(std::string("HP: " + std::to_string(entityManager->getPlayer()->getHealth()) + "/" + std::to_string(entityManager->getPlayer()->getMaxHealth())), 0, 0);
    TextStream::instance().setText(std::string("Boss HP: " + std::to_string(entityManager->getBoss()->getHealth()) + "/" + std::to_string(entityManager->getBoss()->getMaxHealth())), 1,0);

//    TextStream::instance().setText(std::to_string(ticks), 1, 0);
//    TextStream::instance().setText(std::to_string(attackAmount), 2, 0);
//    TextStream::instance().setText(std::to_string(entityManager->getPlayer()->getAttackCooldown()), 3, 0);

    entityManager->tick(keys);

    if (keys & KEY_START) {

    }

    if (keys & KEY_SELECT) {
        engine->setScene(new MainScreen(engine));
    }

    if (attackAmount != entityManager->getAttacks().size()) {
        engine->updateSpritesInScene();
    }
}

