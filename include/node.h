#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>

class node {
public:
    node(bn::fixed_point start={0, 0});
    void push(bn::fixed_point force);
    void update();
    bn::fixed_point position();

private:
    bn::sprite_ptr _spr;
    bn::fixed_point _velocity;
    bn::fixed _restitution;
    bn::fixed_point _gravity;
};