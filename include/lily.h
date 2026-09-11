#pragma once

#include <bn_sprite_animate_actions.h>
#include <bn_sprite_ptr.h>

#include "arrow_math.h"

static constexpr int LILY_ANIM_FRAMES = 4;

class lily {
    public:
        lily(bn::fixed_point position={0,0},
             arrow arr={0,0},
             bn::fixed scale=1,
             unsigned int anim_delay=30);
        void update();
    private:
        bn::sprite_ptr _spr;
        bn::sprite_animate_action<LILY_ANIM_FRAMES> _anim;
        arrow _arr;
};