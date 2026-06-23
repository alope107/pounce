#pragma once

#include <bn_fixed_point.h>
#include <bn_rect.h>
#include <bn_sprite_ptr.h>

// Bounds for a point in quadrant IV
// defines a minimum X and Y
// maximums are unbounded
// TODO; move elsewhere? Use pair? Use struct?
typedef bn::fixed_point mins;

static constexpr int ARM_LENGTH = 64;

class arm {
    public:
        arm(bn::rect shoulder_bounds, mins paw_bounds);
        void update();
    private:
        bn::sprite_ptr _spr;
        bn::rect _shoulder_bounds;
        mins _paw_bounds;
        bn::fixed_point _shoulder;
        bn::fixed_point _paw;
};