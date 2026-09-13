#pragma once

#include <bn_vector.h>

#include "fish.h"

// TODO: put this in a better spot
static constexpr int MAX_FISH = 100;

class fish_stack {
    public:
        fish_stack(bn::fixed_point base_pos, bn::vector<FISH_TYPE, MAX_FISH> caught);
        void update();
    private:
        bn::vector<bn::sprite_ptr, MAX_FISH> _fishes;
};