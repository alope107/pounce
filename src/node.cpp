#include "node.h"
#include "screen_utils.h"

#include "bn_sprite_items_node.h"

static const int radius = 8;
static const int spr_max_y = MAX_Y - radius;

node::node(bn::fixed_point start) : 
               _spr(bn::sprite_items::node.create_sprite(start)),
               _velocity(bn::fixed_point(0, 0)),
               _restitution(.3),
               _gravity(bn::fixed_point(0, .2)) {
}

void node::update() {
    _velocity += _gravity;
    auto candidate = _spr.position() + _velocity;
    if (candidate.y() > spr_max_y) {
        candidate.set_y(spr_max_y);
        _velocity.set_y(_velocity.y() * -_restitution);
    }
    _spr.set_position(candidate);
}

void node::push(bn::fixed_point force) {
    _velocity += force;
}

bn::fixed_point node::position() {
    return _spr.position();
}