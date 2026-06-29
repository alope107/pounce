#pragma once

static constexpr int SIMPLE_ARM_LENGTH = 64;

#include <bn_fixed_point.h>
#include <bn_rect.h>
#include <bn_sprite_ptr.h>

class fish_game;

enum class arm_state {
    MOVING,
    SWIPING,
    RETURNING
};

class simple_arm {
    public:
        simple_arm(fish_game& g, bn::rect bounds, bn::fixed move_speed=1, bn::fixed swipe_speed=10);
        void update();
        void set_state(arm_state state);
        bn::optional<bn::rect> hitbox(); // Gives the active hitbox if it exists. Hitbox is only active when swiping
    private:
        fish_game& _g;
        bn::sprite_ptr _spr;
        bn::rect _bounds;
        bn::fixed _move_speed;
        bn::fixed _swipe_speed;
        arm_state _state;
        
        void _move();
        void _swipe();
        void _return();

};