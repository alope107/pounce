#include "fish.h"

#include "bn_sprite_items_snack.h"

#include "bn_sprite_tiles_item.h"

namespace {
    static const bn::sprite_tiles_item tiles = bn::sprite_items::snack.tiles_item();
}

fish::fish(bn::rect bounds, arrow start_vel) :
    _spr(bn::sprite_items::snack.create_sprite()),
    // TODO: std::apply or macro to expand animation frames?
    _anim(bn::create_sprite_animate_action_forever(_spr, 9, bn::sprite_items::snack.tiles_item(), 0, 1, 2, 3)),
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
    _anim.update();
}

