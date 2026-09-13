#pragma once

#include <bn_vector.h>

#include "fish.h"



class fish_stack {
    public:
        fish_stack(bn::fixed_point base_pos, bn::vector<FISH_TYPE, MAX_FISH> caught);
        void update();
    private:
        bn::vector<bn::sprite_ptr, MAX_FISH> _fishes;
};