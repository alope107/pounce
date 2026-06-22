#pragma once

#include <bn_sprite_ptr.h>
#include <bn_rect.h>
#include "arrow_math.h"

#include <bn_sprite_animate_actions.h>

// Have this be templated?
static constexpr int ANIM_FRAMES = 4;

class fish {
    public:
        fish(bn::rect bounds, arrow start_vel={.5, .5});
        void update();
    private:
        bn::sprite_ptr _spr;
        // Use cached animation? Or seomthing else?
        // This feels heavyweight
        bn::sprite_animate_action<ANIM_FRAMES> _anim;
        bn::rect _bounds;
        arrow _vel;
};