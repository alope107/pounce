#pragma once

#include <bn_vector.h>
#include <bn_random.h>
#include "fish.h"

static constexpr int MAX_FISH = 10;

class fish_game {
    public:
        fish_game(bn::random rng);
        void update();
    private:
        bn::random& _rng;
        bn::vector<fish, MAX_FISH> _fishes;
};