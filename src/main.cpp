#include <bn_core.h>

#include "game.h"


int main() {
    bn::core::init();


    game g = game();

    while(true) {
        g.update();
        bn::core::update();
    }
}

