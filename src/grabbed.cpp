#include "grabbed.h"
#include "arrow_math.h"

#include <bn_log.h>

#include "bn_sprite_items_snack.h"

grabbed::grabbed(simple_arm& arm, bn::fixed_point final_loc, bn::fixed fly_speed) :
    _spr(bn::sprite_items::snack.create_sprite()),
    _arm(arm),
    _final_loc(final_loc),
    _fly_speed(fly_speed),
    _state(grabbed_state::FLYING) {
}

void grabbed::update() {
    BN_LOG(static_cast<int>(_state));
    switch(_state) {
    case grabbed_state::HELD: {
        auto hb = _arm.hitbox();
        if(hb.has_value()) {
            _spr.set_position(hb.get()->position());
        } else {
            BN_LOG("bup");
            _state = grabbed_state::FLYING;
            BN_LOG(static_cast<int>(_state));
        }
        break;
    }

    case grabbed_state::FLYING: {
        BN_LOG("whee");
        arrow remaining = _final_loc - _spr.position();
        bn::fixed dist_remaining = magnitude(remaining);
        if(dist_remaining < _fly_speed*1.5) {
            _spr.set_position(_final_loc);
            _state = grabbed_state::FINISHED;
        } else {
            _spr.set_position(_spr.position() + (remaining * (_fly_speed / dist_remaining)));
        }
        break;
    }
        
    default: // FINISHED
        break;
    }
    // if(_held) {
    //     // arm only has hitbox while swiping. (this feels brittle, beter way to do?)
    //     auto hb = _arm.hitbox();
    //     if(hb.has_value()) {
    //         _spr.set_position(hb.get()->position());
    //     } else {
    //         _held = false;
    //     }
    // } else {

    // }
    
}