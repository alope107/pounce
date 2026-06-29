#pragma once

#include <bn_vector.h>
#include <bn_random.h>
#include "fish.h"
#include "arm.h"
#include "simple_arm.h"

static constexpr int MAX_FISH = 10;

class fish_game {
    public:
        fish_game(bn::random rng);
        void update();
        // bn::optional<fish&> hit_fish(bn::rect hitbox);
    private:
        bn::sprite_ptr _debug_dot;
        bn::random& _rng;
        // arm _arm;
        simple_arm _simple_arm;
        bn::vector<fish, MAX_FISH> _fishes;
};