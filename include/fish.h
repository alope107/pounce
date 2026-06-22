#pragma once

#include <bn_sprite_ptr.h>
#include <bn_rect.h>
#include "arrow_math.h"

class fish {
    public:
        fish(bn::rect bounds, arrow start_vel={.5, .5});
        void update();
    private:
        bn::sprite_ptr _spr;
        bn::rect _bounds;
        arrow _vel;
};