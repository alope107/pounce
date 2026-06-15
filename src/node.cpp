#include "node.h"
#include "screen_utils.h"

#include "bn_sprite_items_node.h"

static const int radius = 30;//0;//= 8; // setting to 0 while sprites are hidden
static const int spr_max_y = MAX_Y - radius;

node::node(bn::fixed_point start) : 
               _spr(bn::sprite_items::node.create_sprite(start)),
               _velocity(arrow(0, 0)),
               _restitution(.6),
               _gravity(arrow(0, .2)),
               _friction(.99) {
    _spr.set_visible(false);
}

void node::update() {
    // _velocity += _gravity;
    _velocity *= _friction;
    auto candidate = _spr.position() + _velocity;
    if (candidate.y() > spr_max_y) {
        candidate.set_y(spr_max_y);
        _velocity.set_y(_velocity.y() * -_restitution);
    }
    _spr.set_position(candidate);
}

void node::push(arrow force) {
    _velocity += force;
}

bn::fixed_point node::position() {
    return _spr.position();
}