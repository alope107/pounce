#include "flower.h"

#include "bn_sprite_items_flower.h"

flower::flower(bn::fixed_point pos) :
    _spr(bn::sprite_items::flower.create_sprite(pos)),
    _anim(bn::create_sprite_animate_action_forever(
        _spr,
        10,
        bn::sprite_items::flower.tiles_item(),
        0,1,2,3,4,4,3,2,1,0
    )){
}

void flower::update() {
    _anim.update();
}