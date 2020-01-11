#include <iostream>
#include <libgba-sprite-engine/gba_engine.h>
#include "Level1Screen.h"
#include "MainScreen.h"

int main() {

    std::shared_ptr<GBAEngine> engine(new GBAEngine());
    //auto scene = new Level1Screen(engine);
    auto scene = new MainScreen(engine);
    engine->setScene(scene);

    while (true) {
        engine->update();
    }

}
