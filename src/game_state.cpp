#include "game_state.h"

game_state::game_state() {

}

void game_state::catch_fish(FISH_TYPE fish_type) {
    _caught.push_back(fish_type);
}

bn::vector<FISH_TYPE, MAX_FISH>& game_state::caught() {
    return _caught;
}