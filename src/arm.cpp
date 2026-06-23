#include "arm.h"
#include "arrow_math.h"

#include <bn_log.h>

#include "bn_sprite_items_arm.h"

arm::arm(bn::rect shoulder_bounds, mins paw_bounds) :
    _spr(bn::sprite_items::arm.create_sprite()),
    _shoulder_bounds(shoulder_bounds),
    _paw_bounds(paw_bounds),
    _shoulder(_shoulder_bounds.position()),
    _paw(_shoulder + degrees_to_arrow(315, ARM_LENGTH)) {
    // center sprite halfway between arm and paw
    // match angle of arm
    arrow half_arm = _paw - _shoulder;
    BN_LOG(half_arm.x(), ",", half_arm.y());
    _spr.set_position(half_arm);
    bn::fixed ang = arrow_to_degrees(half_arm);
    BN_LOG(ang);
    _spr.set_rotation_angle(bn::safe_degrees_angle(-ang));
}

void arm::update() {
    bn::fixed ang = arrow_to_degrees(_paw-_shoulder);
    ang += 1.5;
    _paw = _shoulder + degrees_to_arrow(ang, ARM_LENGTH);
    arrow half_arm = _paw - _shoulder;
    _spr.set_position(half_arm);
    ang = arrow_to_degrees(half_arm);
    _spr.set_rotation_angle(bn::safe_degrees_angle(-ang));
}