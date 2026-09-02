#pragma once

#include "simple_arm.h"

#include <bn_sprite_ptr.h>

enum class grabbed_state {
    HELD,
    FLYING,
    FINISHED
};

class grabbed {
    public:
        grabbed(simple_arm& arm, bn::fixed_point final_loc, bn::fixed fly_speed=2);
        void update();
    private:
        bn::sprite_ptr _spr;
        simple_arm& _arm;
        bn::fixed_point _final_loc;
        bn::fixed _fly_speed;
        grabbed_state _state;
};