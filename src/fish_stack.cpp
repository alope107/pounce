#include "fish_stack.h"

static constexpr int STACK_DELAY = 20;

fish_stack::fish_stack(bn::fixed_point base_pos, game_state& state) :
    _base_pos(base_pos),
    _state(state),
    _fishes(),
    _currently_stacked(0),
    _frame(0) {
}

void fish_stack::update() {
    if(!done_stacking()) {
        _frame++;
        if(_frame == STACK_DELAY) {
            _frame = 0;
            auto fish = FISH_TABLE[_state.caught()[_currently_stacked]];
            _fishes.push_back(fish.dead.create_sprite(
                _base_pos  - bn::fixed_point{0, 6*_currently_stacked++}
        ));
        }
    }
}

bool fish_stack::done_stacking() {
    return _currently_stacked == _state.caught().size();
}