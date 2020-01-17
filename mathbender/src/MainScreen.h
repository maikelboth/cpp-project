//
// Created by Mountsom3 on 09/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MAINSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_MAINSCREEN_H


#include <libgba-sprite-engine/scene.h>
#include "EntityManager.h"

class MainScreen : public Scene {
private:
    std::unique_ptr<Background> bg;
    void writeHCT(const std::string& s, int row); // Horizontal Centered Text


public:
    MainScreen(const std::shared_ptr<GBAEngine> &engine);

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;

};

#endif //GBA_SPRITE_ENGINE_PROJECT_MAINSCREEN_H
