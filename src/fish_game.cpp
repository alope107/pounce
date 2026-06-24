#include "fish_game.h"

#include "fish.h"

#include <bn_rect.h>
#include "arrow_math.h"

fish_game::fish_game(bn::random rng) : 
    _rng(rng),
    _arm(bn::rect(-30, -30, 30, 30), {-30, -30})
     {
        for(int i = 0; i < 3; i++) {
            _fishes.push_back(fish(
                bn::rect(0, 0, 100, 80),
                {_rng.get_fixed(-1, 1), _rng.get_fixed(-1, 1)}
            ));
        }
}

void fish_game::update() {
    _arm.update();
    for(fish& fish : _fishes) {
        fish.update();
    }
}