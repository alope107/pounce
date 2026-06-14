#include "joint.h"

#include "arrow_math.h"

joint::joint(node& a, node& hinge, node& b, bn::fixed k) :
 _a(a),
 _hinge(hinge), 
 _b(b), 
 _k(k),
 _ideal_angle(angle(a.position(), hinge.position(), b.position()))
 {}

void joint::exert() {
    arrow u = _a.position() - _hinge.position();
    arrow v = _b.position() - _hinge.position();

    bn::fixed curr_angle = angle(u, v);
    bn::fixed angle_delta = curr_angle - _ideal_angle;

    arrow u_norm = normal(u);
    arrow v_norm = normal(v);

    bn::fixed scale = angle_delta * _k;

    _a.push(u_norm * scale);
    _b.push(v_norm * scale);
}

bn::fixed joint::ideal_angle() {
    return _ideal_angle;
}


void joint::set_ideal_angle(bn::fixed new_angle) {
    _ideal_angle = new_angle;
}