#pragma once

#include <bn_vector.h>

#include "fish.h"
#include "game.h"

class fish_stack {
    public:
        fish_stack(bn::fixed_point base_pos, game_state& state);
        void update();
        bool done_stacking();
    private:
        bn::fixed_point _base_pos;
        game_state& _state;
        bn::vector<bn::sprite_ptr, MAX_FISH> _fishes;
        int _currently_stacked;
        int _frame;
};