#include <iostream>
#include <libgba-sprite-engine/gba_engine.h>
#include "StartScreen.h"

int main() {

    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    auto scene = new StartScreen(engine);
    engine->setScene(scene);

    while (true) {
        engine->update();
    }

}