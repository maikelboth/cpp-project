//
// Created by Maikel on 15-1-2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ENDSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_ENDSCREEN_H


#include <libgba-sprite-engine/scene.h>

class EndScreen : public Scene {
private:
    std::unique_ptr<Background> bg;
    void writeHCT(std::string s, int row); // Horizontal Centered Text
public:
    EndScreen(const std::shared_ptr<GBAEngine> &engine);

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENDSCREEN_H
