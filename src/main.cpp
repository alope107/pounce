#include <bn_assert.h>
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

    auto rng = bn::random();
    bn::unique_ptr<game> g = bn::make_unique<title_screen>();//bn::make_unique<title_screen>();

    GAME_TYPE current_game_type = GAME_TYPE::TITLE_SCREEN;

    
    while(true) {
        // if(bn::keypad::select_pressed()) {
        //     if(isFish) {
        //         g = bn::make_unique<jump_game>();
        //     } else {
        //         g = bn::make_unique<fish_game>(rng);
        //     }
        //     isFish = !isFish;
        // }
        GAME_TYPE new_game_type = g->update();
        if(new_game_type != current_game_type) {
            //g.release(); // Release old game first so memory is freed before loading new one
            switch (new_game_type)
            {
                case GAME_TYPE::TITLE_SCREEN:
                    g = bn::make_unique<title_screen>();
                    break;
                case GAME_TYPE::FISH_GAME:
                    g = bn::make_unique<fish_game>(rng);
                    break;
                case GAME_TYPE::JUMP_GAME: // Currently unused
                    g = bn::make_unique<jump_game>();
                    break;
                default:
                    BN_ASSERT(false, "Got unknown game type");
            }
            current_game_type = new_game_type;
        }
        bn::core::update();
    }
}

