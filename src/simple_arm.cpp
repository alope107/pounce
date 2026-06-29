// Going with a simpler approach for MVP
// Will return to more complex after

#include "simple_arm.h"
#include "screen_utils.h"

#include <bn_keypad.h>

#include "bn_sprite_items_arm.h"

static constexpr int BASE_ANGLE = 275;
static constexpr int MAX_ANGLE = 355;

simple_arm::simple_arm(bn::rect bounds, bn::fixed move_speed, bn::fixed swipe_speed) : 
    _spr(bn::sprite_items::arm.create_sprite()),
    _bounds(bounds),
    _move_speed(move_speed),
    _swipe_speed(swipe_speed),
    _state(arm_state::MOVING) {
    _spr.set_rotation_angle(BASE_ANGLE);
}

void simple_arm::update() {
    switch (_state)
    {
    case arm_state::MOVING:
        if(bn::keypad::a_pressed()) {
            _state = arm_state::SWIPING;
        } else {
            _move();
        }
        break;

    case arm_state::SWIPING:
        _swipe();
        break;

    default: // RETURNING
        _return();
        break;
    }
}

void simple_arm::_move() {
    bn::fixed_point target = _spr.position();
    // TODO - extract to utility? 
    target.set_x(target.x() + _move_speed * 
        tribool(bn::keypad::left_held(), bn::keypad::right_held()));
    
    target.set_y(target.y() + _move_speed * 
        tribool(bn::keypad::up_held(), bn::keypad::down_held()));

    _spr.set_position(clamp_point(_bounds, target));
}

void simple_arm::_swipe() {
    bn::fixed current = _spr.rotation_angle();
    // TODO: handle overshoot where angle wraps
    if(current < MAX_ANGLE) {
        _spr.set_rotation_angle(current + _swipe_speed);
    } else {
        _state = arm_state::RETURNING;
    }
}

void simple_arm::_return() {
    bn::fixed current = _spr.rotation_angle();
    if (current > BASE_ANGLE) {
        // TODO: handle overshoot where angle wraps
        _spr.set_rotation_angle(current - (_swipe_speed / 2));
    } else {
        _spr.set_rotation_angle(BASE_ANGLE);
        _state = arm_state::MOVING;
    }
}

