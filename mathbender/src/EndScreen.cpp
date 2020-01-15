//
// Created by Maikel on 15-1-2020.
//

#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include "EndScreen.h"
#include "Sprite/mainScreenBG.h"
#include "Level1Screen.h"

EndScreen::EndScreen(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Sprite *> EndScreen::sprites() {
    return {};
}

std::vector<Background *> EndScreen::backgrounds() {
    return {
        bg.get()
    };
}

void EndScreen::load() {
    backgroundPalette = std::make_unique<BackgroundPaletteManager>(mainScreenBGPal, sizeof(mainScreenBGPal));

    bg = std::make_unique<Background>(1, mainScreenBGTiles, sizeof(mainScreenBGTiles), mainScreenBGMap, sizeof(mainScreenBGMap));
    bg->useMapScreenBlock(16);
}

void EndScreen::tick(u16 keys) {
    writeHCT("YOU DIED", 9);
    writeHCT("PRESS START TO TRY AGAIN", 11);

    if (keys & KEY_START) {
        // restart game
        auto scene = new Level1Screen(engine);
        engine->setScene(scene);
        return;
    }
}

void EndScreen::writeHCT(const std::string s, int row) {
    TextStream::instance().setText(s, row, 15-(s.size()/2));
}
