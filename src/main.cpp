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
#include "bn_unique_ptr.h"


int main() {
    bn::core::init();

    auto rng = bn::random();
    // jump_game g = jump_game();
    bool isFish = true; //todo: swap this to an enum of scenes
    // bn::unique_ptr<game> g = bn::make_unique<fish_game>(rng);

    auto bg = bn::regular_bg_items::background.create_bg(0,0);
    auto frito_spr = bn::sprite_items::fritobuttshake.create_sprite({0, -25});
    auto frito_anim = bn::create_sprite_animate_action_forever(frito_spr, 18, 
        bn::sprite_items::fritobuttshake.tiles_item(), 0,1,2,3,4,5);

    bn::vector<bn::sprite_ptr,9>  lillies = {};
    //lillies.push_back(bn::sprite_items::lilypad1.create_sprite({-25, -25}));

    bn::vector<bn::sprite_animate_action<4>, 9> lily_anims = {}; 
    
    lillies.push_back(bn::sprite_items::lilypad2.create_sprite({25, 15}));
    lillies.push_back(bn::sprite_items::lilypad2.create_sprite({-25, 15}));

    lillies[0].set_scale(.7);
    lillies[1].set_scale(.9);

    for(auto &lily : lillies) {
        lily_anims.push_back(
            bn::create_sprite_animate_action_forever(lily, 30, bn::sprite_items::lilypad2.tiles_item(), 0,1,2,3));
    }
    
    while(true) {
        // if(bn::keypad::select_pressed()) {
        //     if(isFish) {
        //         g = bn::make_unique<jump_game>();
        //     } else {
        //         g = bn::make_unique<fish_game>(rng);
        //     }
        //     isFish = !isFish;
        // }
        frito_anim.update();
        lillies[0].set_position(lillies[0].position() + bn::fixed_point{.1, .05});
        lillies[1].set_position(lillies[1].position() + bn::fixed_point{-0.02, .05});
        for(auto &anim : lily_anims) {
            anim.update();
        }
        // g->update();
        bn::core::update();
    }
}

