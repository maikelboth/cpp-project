//
// Created by Maikel on 26-12-2019.
//

#include "StartScreen.h"

StartScreen::StartScreen(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> StartScreen::sprites() {
    return {};
}

std::vector<Background *> StartScreen::backgrounds() {
    return {};
}

void StartScreen::tick(u16 keys) {}

void StartScreen::load() {

}