#pragma once

static constexpr int SIMPLE_ARM_LENGTH = 64;

#include <bn_fixed_point.h>
#include <bn_rect.h>
#include <bn_sprite_ptr.h>

enum class arm_state {
    MOVING,
    SWIPING,
    RETURNING
};

class simple_arm {
    public:
        simple_arm(bn::rect bounds, bn::fixed move_speed=1, bn::fixed swipe_speed=10);
        void update();
    private:
        bn::sprite_ptr _spr;
        bn::rect _bounds;
        bn::fixed _move_speed;
        bn::fixed _swipe_speed;
        arm_state _state;
        

        void _move();
        void _swipe();
        void _return();

};