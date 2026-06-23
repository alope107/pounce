#include <bn_core.h>

#include "jump_game.h"
#include "fish_game.h"

#include "bn_sprite_items_snack.h"

#include "bn_sprite_animate_actions.h"


int main() {
    bn::core::init();

    auto rng = bn::random();
    // jump_game g = jump_game();
    fish_game g = fish_game(rng);
    
    while(true) {
        g.update();
        bn::core::update();
    }
}

