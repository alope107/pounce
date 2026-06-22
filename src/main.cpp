#include <bn_core.h>

#include "jump_game.h"

#include "bn_sprite_items_snack.h"

#include "bn_sprite_animate_actions.h"


int main() {
    bn::core::init();
    jump_game g = jump_game();
    
    while(true) {
        g.update();
        bn::core::update();
    }
}

