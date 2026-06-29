#include "fish_game.h"

#include "fish.h"

#include <bn_rect.h>
#include <bn_log.h>

#include "arrow_math.h"

#include "bn_sprite_items_debug_dot.h"

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

// bn::optional<fish&> fish_game::hit_fish(bn::rect hitbox) {
//     BN_LOG("Trying to hit");
//     BN_LOG("Paw hitbox", hitbox.left(), hitbox.top(), hitbox.right(), hitbox.bottom());
//     for(fish& f : _fishes) {
//         if (f.hit(hitbox)) {
//             return bn::optional<fish&>(f);
//         }
//     }
//     return bn::optional<fish&>();
// }

void fish_game::update() {
    _simple_arm.update();
    auto paw_hitbox = _simple_arm.hitbox();
    if(paw_hitbox.has_value()) {
        _debug_dot.set_position((*paw_hitbox).center());
    } else {
        _debug_dot.set_position(-100, 100);
    }
    for(fish& fish : _fishes) {
        fish.update();
        if(paw_hitbox.has_value()) {
            if(fish.hitbox().intersects(*paw_hitbox)) {
                BN_LOG("hit!");
                _simple_arm.set_state(arm_state::RETURNING);
            }
        }
    }
}