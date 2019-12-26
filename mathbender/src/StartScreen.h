//
// Created by Maikel on 26-12-2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_STARTSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_STARTSCREEN_H


#include <libgba-sprite-engine/scene.h>

class StartScreen : public Scene {
private:



public:

    StartScreen(const std::shared_ptr<GBAEngine> &engine);

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_STARTSCREEN_H
