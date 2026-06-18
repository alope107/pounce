#include <bn_core.h>

#include "game.h"

#include "bn_sprite_items_snack.h"

#include "bn_sprite_animate_actions.h"


int main() {
    bn::core::init();
    game g = game();

    bn::sprite_ptr goldfish = bn::sprite_items::snack.create_sprite();

    bn::sprite_animate_action<4> anim = bn::create_sprite_animate_action_forever(goldfish, 9, 
        bn::sprite_items::snack.tiles_item(), 0, 1, 2, 3);

    
    while(true) {
        g.update();
        anim.update();
        bn::core::update();
    }
}

