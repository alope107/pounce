#include "fish_game.h"

#include <bn_keypad.h>
#include <bn_log.h>
#include <bn_rect.h>

#include "fish.h"
#include "arrow_math.h"

#include "bn_sprite_items_debug_dot.h"
#include "bn_regular_bg_items_bottomofpond.h"

static constexpr bool DEBUG_DOT = false;

fish_game::fish_game(game_state& state, bn::random& rng) :
    _state(state),
    _bg(bn::regular_bg_items::bottomofpond.create_bg()),
    _debug_dot(bn::sprite_items::debug_dot.create_sprite(-100, -100)),
    _rng(rng),
    // _arm(bn::rect(-30, -30, 30, 30), {-30, -30}),
    _simple_arm(*this, bn::rect(0, -60, 220, 60)),
    _timer(GAME_DUR)
     {
        for(int i = 0; i < 10; i++) {
            _fishes.push_back(fish(
                {rng.get_fixed(-120, 120), rng.get_fixed(-80, 80)},
                static_cast<FISH_TYPE>(rng.get_int(4)),
                bn::rect(0, 0, 240, 160),
                {_rng.get_fixed(-1, 1), _rng.get_fixed(-1, 1)}
            ));
        }
}



GAME_TYPE fish_game::update() {
    _timer.update();
    if(bn::keypad::select_pressed() || _timer.frames_left() == 0) {
        return GAME_TYPE::END_SCREEN;
    }
    _simple_arm.update();
    auto paw_hitbox = _simple_arm.hitbox();
    if(paw_hitbox.has_value() && DEBUG_DOT) {
        _debug_dot.set_position((*paw_hitbox).center());
    } else {
        _debug_dot.set_position(-100, 100);
    }
    for(auto it = _fishes.begin(); it != _fishes.end(); ) {
        fish& f = *it;
        f.update();
        if(paw_hitbox.has_value() && f.hitbox().intersects(*paw_hitbox)) {
                _state.catch_fish(f.fish_type());
                it = _fishes.erase(it);// Maybe inefficient to do with vector? Probably small enough it doesn't matter
                BN_LOG("hit!");
                //_grabbeds.push_back(grabbed(_simple_arm, {-100, -100}));
                //_simple_arm.set_state(arm_state::RETURNING);
        } else {
            it++;
        }
    }
    for (auto g : _grabbeds) {
        g.update();
    }
    
    return GAME_TYPE::FISH_GAME;
}