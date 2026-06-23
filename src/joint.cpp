#include "joint.h"

#include "arrow_math.h"
#include "jump_game.h"

joint::joint(jump_game& g,node& a, node& hinge, node& b, bn::fixed k, bool draw_debug) :
 _g(g),
 _a(a),
 _hinge(hinge), 
 _b(b), 
 _k(k),
 _ideal_angle(angle(a.position(), hinge.position(), b.position())),
 _draw_debug(draw_debug)
 {}

void joint::exert() {
    arrow u = _a.position() - _hinge.position();
    arrow v = _b.position() - _hinge.position();

    bn::fixed curr_angle = angle(u, v);
    bn::fixed angle_delta = _ideal_angle - curr_angle;

    arrow u_norm = -unit(normal(u));
    arrow v_norm = unit(normal(v));

    if(_draw_debug) {
        _g.draw_line(_a.position(), _a.position() + u_norm, 11);
        _g.draw_line(_b.position(), _b.position() + v_norm, 11);
    }
    

    bn::fixed scale = angle_delta * _k;

    arrow u_force = u_norm * scale;
    arrow v_force = v_norm * scale;

    _a.push(u_force);
    _b.push(v_force);
    _hinge.push(-(u_force + v_force));

    // if(_draw_debug) {
    //     _g.draw_line(_a.position(), _a.position() + u_norm * scale * 400, 11);
    //     _g.draw_line(_b.position(), _b.position() + v_norm * scale * 400, 11);
    // }
}

bn::fixed joint::ideal_angle() {
    return _ideal_angle;
}


void joint::set_ideal_angle(bn::fixed new_angle) {
    _ideal_angle = new_angle;
}