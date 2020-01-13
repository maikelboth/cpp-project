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

bool Level1Screen::isOutOfMap(Sprite* sprite) {
    int xLeft = sprite->getX();
    int xRight = sprite->getX() + sprite->getWidth();
    int yTop = sprite->getY();
    int yBottom = sprite->getY() + sprite->getHeight();

    return isOutOfMap(xLeft, xRight, yTop, yBottom);
}

bool Level1Screen::isOutOfMap(int xLeft, int xRight, int yTop, int yBottom) {
    return (yTop < 25 || yBottom > 140) || (xLeft < 20 || xRight > 220) || ((xLeft < 46 || xRight > 194) && yTop < 57) || ((xLeft < 62 || xRight > 178) && yTop < 41);
}

bool Level1Screen::canMove(Sprite* sprite, int dx, int dy) {
    double xLeft = sprite->getX() + dx;
    double xRight = sprite->getX() + sprite->getWidth() + dx;
    double yTop = sprite->getY() + dy;
    double yBottom = sprite->getY() + sprite->getHeight() + dy;

    return !isOutOfMap(xLeft, xRight, yTop, yBottom);
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

//    TextStream::instance().setText(std::to_string(entityManager->getSprites().size()), 0, 0);
    TextStream::instance().setText(std::to_string(ticks), 1, 0);
    TextStream::instance().setText(std::to_string(attackAmount), 2, 0);
    TextStream::instance().setText(std::to_string(entityManager->getPlayer()->getAttackCooldown()), 3, 0);

    entityManager->tick();
    bossAI();

    Player* player = entityManager->getPlayer();

    for (Attack* attack : entityManager->getAttacks()) {
        if (isOutOfMap(attack->getSprite())) {
            entityManager->removeAttack(attack);
        }
    }

    if (keys & KEY_START) {

    }

    if (keys & KEY_SELECT) {
        engine->setScene(new MainScreen(engine));
    }
    if (keys & KEY_A) { // attack
        if (!player->isAttackOnCooldown()) {
            totalAttacks++;
            Attack* newAttack = player->attack();
            if (newAttack != nullptr) {
                entityManager->addAttack(newAttack);
                //engine->updateSpritesInScene();
            }
        }
        //entityManager->getBoss()->getSprite()->animateToFrame(0);
    }
    if (keys & KEY_B) {
        entityManager->getBoss()->getSprite()->animateToFrame(8);
    }
    if (keys & KEY_LEFT) {
        if (canMove(player->getSprite(), -1, 0))
            player->move(-1, 0);
    }
    if (keys & KEY_RIGHT) {
        if (canMove(player->getSprite(), 1, 0))
            player->move(1, 0);
    }
    if (keys & KEY_UP) {
        if (canMove(player->getSprite(), 0, -1))
            player->move(0, -1);
    }
    if (keys & KEY_DOWN) {
        if (canMove(player->getSprite(), 0, 1))
            player->move(0, 1);
    }

    if(attackAmount != entityManager->getAttacks().size()){
        engine->updateSpritesInScene();
    }
}

void Level1Screen::bossAI() {
    Boss* boss = entityManager->getBoss();
    Player* player = entityManager->getPlayer();

    if (boss->getSprite()->getCenter().x < player->getSprite()->getCenter().x) {
        if (canMove(boss->getSprite(), 1, 0)) {
            boss->move(1, 0);
        }
    } else if (boss->getSprite()->getCenter().x > player->getSprite()->getCenter().x) {
        if (canMove(boss->getSprite(), -1, 0)) {
            boss->move(-1, 0);
        }
    }

    if (!boss->isAttackOnCooldown()) {
        totalAttacks++;
        Attack* newAttack = boss->attack();
        if (newAttack != nullptr) {
            entityManager->addAttack(newAttack);
            //engine->updateSpritesInScene();
        }
    }
}

