#include <bn_core.h>

#include "jump_game.h"


int main() {
    bn::core::init();
    jump_game g = jump_game();
    
    while(true) {
        g.update();
        bn::core::update();
    }
}

