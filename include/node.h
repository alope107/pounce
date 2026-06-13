#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>

class node {
public:
    node();
    void update();

private:
    bn::sprite_ptr _spr;
    bn::fixed_point _velocity;
    bn::fixed _restitution;
    bn::fixed_point _gravity;
};