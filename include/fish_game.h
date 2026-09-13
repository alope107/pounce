#pragma once

#include <bn_regular_bg_ptr.h>
#include <bn_vector.h>
#include <bn_random.h>
#include "fish.h"
#include "arm.h"
#include "simple_arm.h"
#include "game.h"
#include "grabbed.h"
#include "fish_stack.h"

class fish_game : public game {
    public:
        fish_game(game_state& state, bn::random rng);
        GAME_TYPE update();
    private:
        game_state& _state;
        bn::regular_bg_ptr _bg;
        bn::sprite_ptr _debug_dot;
        bn::random _rng;
        simple_arm _simple_arm;
        bn::vector<fish, MAX_FISH> _fishes;
        bn::vector<grabbed, MAX_FISH> _grabbeds;
};