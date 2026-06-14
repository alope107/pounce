#pragma once

#include "arrow_math.h"

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>


class node {
public:
    node(bn::fixed_point start={0, 0});
    void push(arrow force);
    void update();
    bn::fixed_point position();

private:
    bn::sprite_ptr _spr;
    arrow _velocity;
    bn::fixed _restitution;
    arrow _gravity;
    bn::fixed _friction;
};