#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_regular_bg_ptr.h>
#include <bn_sprite_animate_actions.h>

#include "jump_game.h"
#include "fish_game.h"

#include "bn_sprite_items_snack.h"
#include "bn_sprite_items_fritobuttshake.h"
#include "bn_sprite_items_lilypad1.h"
#include "bn_sprite_items_lilypad2.h"
#include "bn_regular_bg_items_background.h"

#include "bn_sprite_animate_actions.h"
#include "game.h"
#include "title_screen.h"
#include "bn_unique_ptr.h"


int main() {
    bn::core::init();

    // auto rng = bn::random();
    // jump_game g = jump_game();
    //bool isFish = true; //todo: swap this to an enum of scenes
    bn::unique_ptr<game> g = bn::make_unique<title_screen>();

    
    while(true) {
        // if(bn::keypad::select_pressed()) {
        //     if(isFish) {
        //         g = bn::make_unique<jump_game>();
        //     } else {
        //         g = bn::make_unique<fish_game>(rng);
        //     }
        //     isFish = !isFish;
        // }
        g->update();
        bn::core::update();
    }
}

