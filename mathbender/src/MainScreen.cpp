//
// Created by Mountsom3 on 09/01/2020.
//

#include "MainScreen.h"
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>

#include <memory>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include "Sprite/mainScreenBG.h"

#include "Level1Screen.h"

MainScreen::MainScreen(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> MainScreen::sprites() {
    return {};
}

std::vector<Background *> MainScreen::backgrounds() {
    return {
        bg.get()
    };
}

void MainScreen::load() {

    //foregroundPalette = std::make_unique<ForegroundPaletteManager>(sharedPal, sizeof(sharedPal));
    backgroundPalette = std::make_unique<BackgroundPaletteManager>(mainScreenBGPal, sizeof(mainScreenBGPal));

    bg = std::make_unique<Background>(1, mainScreenBGTiles, sizeof(mainScreenBGTiles), mainScreenBGMap, sizeof(mainScreenBGMap));
    bg->useMapScreenBlock(16);
}

void MainScreen::tick(u16 keys) {
    writeHCT("PRESS START", 9);

    if (keys & KEY_START) {
        auto scene = new Level1Screen(engine);
        engine->setScene(scene);
        return;
    }
}

void MainScreen::writeHCT(const std::string& s, int row) {
    TextStream::instance().setText(s, row, 15-(s.size()/2));
}