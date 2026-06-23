#include "fish_game.h"

#include "fish.h"

#include <bn_rect.h>
#include "arrow_math.h"

fish_game::fish_game(bn::random rng) : 
    _rng(rng) {
        for(int i = 0; i < 3; i++) {
            _fishes.push_back(fish(
                bn::rect(0, 0, 100, 80),
                {_rng.get_fixed(-1, 1), _rng.get_fixed(-1, 1)}
            ));
        }
}

void fish_game::update() {
    for(fish& fish : _fishes) {
        fish.update();
    }
}