//
// Created by Maikel on 15-1-2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_ENDSCREEN_H
#define GBA_SPRITE_ENGINE_PROJECT_ENDSCREEN_H


#include <libgba-sprite-engine/scene.h>

class EndScreen : public Scene {
private:
    std::unique_ptr<Background> bg;
    void writeHCT(const std::string& s, int row); // Horizontal Centered Text
    int score;
public:
    EndScreen(const std::shared_ptr<GBAEngine> &engine);

    void setScore(int score) { this->score = score; };
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_ENDSCREEN_H
