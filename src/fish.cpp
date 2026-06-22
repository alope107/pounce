#include "fish.h"

#include "bn_sprite_items_snack.h"

fish::fish(bn::rect bounds, arrow start_vel) :
    _spr(bn::sprite_items::snack.create_sprite()),
    _bounds(bounds),
    _vel(start_vel) {
}

void fish::update() {
    bn::fixed_point new_pos = _spr.position() + _vel;

    if(new_pos.x() > _bounds.right()) {
        new_pos.set_x(_bounds.right());
        _vel.set_x(_vel.x() * -1);
    }
    if(new_pos.x() < _bounds.left()) {
        new_pos.set_x(_bounds.left());
        _vel.set_x(_vel.x() * -1);
    }
    if(new_pos.y() > _bounds.bottom()) {
        new_pos.set_y(_bounds.bottom());
        _vel.set_y(_vel.y() * -1);
    }
    if(new_pos.y() < _bounds.top()) {
        new_pos.set_y(_bounds.top());
        _vel.set_y(_vel.y() * -1);
    }

    _spr.set_position(new_pos);
}

