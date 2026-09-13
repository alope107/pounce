#pragma once

#include <bn_regular_bg_ptr.h>
#include <bn_sprite_animate_actions.h>

#include "game.h"
#include "fish_stack.h"

static constexpr int FRITO_JUMP_FRAMES = 12;

class end_screen : public game {
    public:
        end_screen();
        GAME_TYPE update();
    private:
        bn::regular_bg_ptr _bg;
        // Maybe make Frito + animation her own class?
        bn::sprite_ptr _frito_spr;
        bn::sprite_animate_action<FRITO_JUMP_FRAMES> _frito_anim;
        fish_stack _stack;
};