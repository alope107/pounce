#include "fish_stack.h"

fish_stack::fish_stack(bn::fixed_point base_pos, bn::vector<FISH_TYPE, MAX_FISH> caught) {
    _fishes = {};

    // TODO: get from actual gameplay
    caught.push_back(FISH_TYPE::GOLDFISH);
    caught.push_back(FISH_TYPE::PUFFER);
    caught.push_back(FISH_TYPE::SNACK);
    caught.push_back(FISH_TYPE::SALMON);
    caught.push_back(FISH_TYPE::GOLDFISH);

    for(int i = 0; i < caught.size(); i++) {
        auto fish = FISH_TABLE[caught[i]];
        _fishes.push_back(fish.dead.create_sprite(
            base_pos  - bn::fixed_point{0, 6*i}
        ));
    }
}

void fish_stack::update() {
    // TODO: stacking animatiom
}