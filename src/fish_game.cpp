#include "fish_game.h"

#include "fish.h"

#include <bn_rect.h>
#include <bn_log.h>

#include "arrow_math.h"

#include "bn_sprite_items_debug_dot.h"

static constexpr bool DEBUG_DOT = false;

fish_game::fish_game(bn::random rng) :
    _debug_dot(bn::sprite_items::debug_dot.create_sprite(-100, -100)),
    _rng(rng),
    // _arm(bn::rect(-30, -30, 30, 30), {-30, -30}),
    _simple_arm(*this, bn::rect(-30, -30, 30, 30))
     {
        for(int i = 0; i < 3; i++) {
            _fishes.push_back(fish(
                bn::rect(0, 0, 100, 80),
                {_rng.get_fixed(-1, 1), _rng.get_fixed(-1, 1)}
            ));
        }
}



void fish_game::update() {
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
                it = _fishes.erase(it);// Maybe inefficient to do with vector? Probably small enough it doesn't matter
                BN_LOG("hit!");
                //_simple_arm.set_state(arm_state::RETURNING);
        } else {
            it++;
        }
    }
}