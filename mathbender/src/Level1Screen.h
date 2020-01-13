//
// Created by Maikel on 26-12-2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_LEVEL1SCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_LEVEL1SCREEN_H


#include <libgba-sprite-engine/scene.h>
#include "EntityManager.h"

class Level1Screen : public Scene {
private:
    std::unique_ptr<Background> bg;
    std::unique_ptr<EntityManager> entityManager;
    int totalAttacks = 0;
    int ticks = 0;
    int attackCountdown = 20;

public:

    Level1Screen(const std::shared_ptr<GBAEngine> &engine);
    //FlyingStuffScene(std::shared_ptr<GBAEngine> engine) : Scene(engine), rotation(0), rotationDiff(128), scrollX(0), scrollY(0) {}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;


    void load() override;
    void tick(u16 keys) override;
    bool isOutOfMap(Sprite* sprite);
    bool isOutOfMap(int xLeft, int xRight, int yTop, int yBottom);
    bool canMove(Sprite* sprite, int dx, int dy);
    void bossAI();
};


#endif //GBA_SPRITE_ENGINE_PROJECT_LEVEL1SCREEN_H
