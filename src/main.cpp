#include <bn_assert.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_regular_bg_ptr.h>
#include <bn_sprite_animate_actions.h>
#include <bn_sprite_text_generator.h>

#include "jump_game.h"
#include "fish_game.h"
#include "end_screen.h"

#include "bn_sprite_items_snack.h"
#include "bn_sprite_items_fritobuttshake.h"
#include "bn_sprite_items_lilypad1.h"
#include "bn_sprite_items_lilypad2.h"
#include "bn_regular_bg_items_background.h"

#include "bn_sprite_animate_actions.h"
#include "game.h"
#include "title_screen.h"
#include "bn_unique_ptr.h"
#include "fuzzyfont.h"

int main()
{
    bn::core::init();

    auto rng = bn::random();
    bn::unique_ptr<game> g = bn::make_unique<title_screen>();

    GAME_TYPE current_game_type = GAME_TYPE::TITLE_SCREEN;

    bn::sprite_font font = fuzzyfont;
    bn::sprite_text_generator text_generator(font);
    text_generator.set_alignment(bn::sprite_text_generator::alignment_type::CENTER);

    bn::vector<bn::sprite_ptr, 20> text_sprs;
    text_generator.generate({0, 50}, "PRESS A", text_sprs);
    text_generator.generate({0, 68}, "TO START", text_sprs);


    while (true)
    {
        GAME_TYPE new_game_type = g->update();
        if (new_game_type != current_game_type)
        {
            g.reset(); // Clear old game first so memory is freed before loading new one
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
            case GAME_TYPE::END_SCREEN:
                g = bn::make_unique<end_screen>();
                break;
            default:
                BN_ASSERT(false, "Got unknown game type");
            }
            current_game_type = new_game_type;
        }
        bn::core::update();
    }
}
