// Going with a simpler approach for MVP
// Will return to more complex after

#include "arrow_math.h"
#include "simple_arm.h"
#include "screen_utils.h"
#include "fish.h"
#include "fish_game.h"

#include <bn_keypad.h>

#include "bn_sprite_items_fritozoomarm.h"

static constexpr int BASE_ANGLE = 275;
static constexpr int MIN_ANGLE = 195;//355;

static constexpr int HITBOX_WIDTH = 8;

static constexpr int PAW_LOC = (SIMPLE_ARM_LENGTH >> 1) - (HITBOX_WIDTH >> 1);

simple_arm::simple_arm(fish_game &g, bn::rect bounds, bn::fixed move_speed, bn::fixed swipe_speed) : _g(g),
                                                                                                     _elbow_spr(bn::sprite_items::fritozoomarm.create_sprite()),
                                                                                                     _paw_spr(bn::sprite_items::fritozoomarm.create_sprite()),
                                                                                                     _bounds(bounds),
                                                                                                     _move_speed(move_speed),
                                                                                                     _swipe_speed(swipe_speed),
                                                                                                     _state(arm_state::MOVING)
{
    _paw_spr.set_rotation_angle(BASE_ANGLE);
    _elbow_spr.set_rotation_angle(BASE_ANGLE);
}

void simple_arm::update()
{
    switch (_state)
    {
    case arm_state::MOVING:
        if (bn::keypad::a_pressed())
        {
            _state = arm_state::SWIPING;
        }
        else
        {
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
    bn::fixed_point joint = _paw_spr.position() - degrees_to_arrow(-_paw_spr.rotation_angle(), PAW_LOC);
    _elbow_spr.set_position(joint + bn::fixed_point{0, -20});
}

void simple_arm::set_state(arm_state state)
{
    _state = state;
}

bn::optional<bn::rect> simple_arm::hitbox()
{
    if (_state != arm_state::SWIPING)
        return {};
    // TODO determine whether negating the rotation is appropriate or if the degrees_to_arrow is backward
    bn::fixed_point hit_center = _paw_spr.position() + degrees_to_arrow(-_paw_spr.rotation_angle(), PAW_LOC);
    return bn::rect(round_fixed_point(hit_center), {HITBOX_WIDTH, HITBOX_WIDTH});
}

void simple_arm::_move()
{
    bn::fixed_point target = _paw_spr.position();
    // TODO - extract to utility?
    target.set_x(target.x() + _move_speed *
                                  tribool(bn::keypad::left_held(), bn::keypad::right_held()));

    target.set_y(target.y() + _move_speed *
                                  tribool(bn::keypad::up_held(), bn::keypad::down_held()));

    _paw_spr.set_position(clamp_point(_bounds, target));
}

void simple_arm::_swipe()
{
    bn::fixed current = _paw_spr.rotation_angle();
    // TODO: handle overshoot where angle wraps
    if (current > MIN_ANGLE)
    {
        current -= _swipe_speed;
        _paw_spr.set_rotation_angle(current);
    }
    else
    {
        _state = arm_state::RETURNING;
    }
}

void simple_arm::_return()
{
    bn::fixed current = _paw_spr.rotation_angle();
    if (current < BASE_ANGLE)
    {
        // TODO: handle overshoot where angle wraps
        _paw_spr.set_rotation_angle(current + (_swipe_speed / 2));
    }
    else
    {
        _paw_spr.set_rotation_angle(BASE_ANGLE);
        _state = arm_state::MOVING;
    }
}
