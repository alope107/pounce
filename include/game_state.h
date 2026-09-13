#pragma once

#include <bn_vector.h>

#include "fish.h"


class game_state {
    public:
        game_state();
        void catch_fish(FISH_TYPE fish_type);
        bn::vector<FISH_TYPE, MAX_FISH> caught();
    private:
        bn::vector<FISH_TYPE, MAX_FISH> _caught;
};