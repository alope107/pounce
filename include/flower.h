#pragma once

#include <bn_sprite_animate_actions.h>

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>

class flower {
    public:
        flower(bn::fixed_point position);
        void update();
    private:
        bn::sprite_ptr _spr;
        bn::sprite_animate_action<10> _anim;
};