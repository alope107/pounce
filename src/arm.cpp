#include "arm.h"
#include "arrow_math.h"

#include <bn_log.h>
#include <bn_keypad.h>

#include "bn_sprite_items_arm.h"

/*
Spitballing alternate plan:
- instead of targeting shoulder move, target paw move
- worry about shoulder bounds later (will be useful for player altering angle)
- if paw at top or left, no move
- paw is bounded by quarter circle going right/down
- for now (not worrying about shoulder bounds)
    - if attempting to move out of semicircle, use target move location to determine angle from shoulder to paw
    - clamp to magnitude of arm
- Needs more thinking
*/

arm::arm(bn::rect shoulder_bounds, mins paw_bounds, bn::fixed speed) :
    _spr(bn::sprite_items::arm.create_sprite()),
    _shoulder_bounds(shoulder_bounds),
    _paw_bounds(paw_bounds),
    _shoulder(_shoulder_bounds.position()),
    _speed(speed),
    _angle(315) {
    //_paw(_shoulder + degrees_to_arrow(315, ARM_LENGTH)) {
    // center sprite halfway between arm and paw
    // match angle of arm
    // arrow half_arm = _paw - _shoulder;
    // BN_LOG(half_arm.x(), ",", half_arm.y());
    // _spr.set_position(half_arm);
    // bn::fixed ang = arrow_to_degrees(half_arm);
    // BN_LOG(ang);
    // _spr.set_rotation_angle(bn::safe_degrees_angle(-ang));
        _update_sprite();

}

void arm::update() {
    _move();
}

void arm::_move() {

    bool moved = false;

    // TODO START REMOVE
    // spinning for now for validation
    // _angle += 1.5;
    // moved = true;
    // TODO END REMOVE

    // TODO: make diagonals normalized?
    if(bn::keypad::up_held()) {
        _shoulder.set_y(_shoulder.y() - _speed);
        if(_shoulder.y() < _shoulder_bounds.top()) {
            _shoulder.set_y(_shoulder_bounds.top());

            //TODO handle angle change
            _angle -= _speed;
        }
        moved = true;
    }
    if(bn::keypad::down_held()) {
        _shoulder.set_y(_shoulder.y() + _speed);
        if(_shoulder.y() > _shoulder_bounds.bottom()) {
            _shoulder.set_y(_shoulder_bounds.bottom());

            //TODO handle angle change
        }
        moved = true;
    }
    if(bn::keypad::left_held()) {
        _shoulder.set_x(_shoulder.x() - _speed);
        if(_shoulder.x() < _shoulder_bounds.left()) {
            _shoulder.set_x(_shoulder_bounds.left());

            //TODO handle angle change
            // TODO normalize angle change speed
            // TODO keep paw in bounds
            _angle += _speed;
        }
        moved = true;
    }
    if(bn::keypad::right_held()) {
        _shoulder.set_x(_shoulder.x() + _speed);
        if(_shoulder.x() > _shoulder_bounds.right()) {
            _shoulder.set_x(_shoulder_bounds.right());

            //TODO handle angle change
        }
        moved = true;
    }

    if(moved) {
        _update_sprite();
    }
}

void arm::_update_sprite() {
    _spr.set_rotation_angle(bn::safe_degrees_angle(-_angle));

    // center sprite halfway between arm and paw
    arrow half_arm = degrees_to_arrow(_angle, ARM_LENGTH >> 1);
    _spr.set_position(_shoulder + half_arm);
}

