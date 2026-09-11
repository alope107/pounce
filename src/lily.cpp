#include "lily.h"

#include "bn_sprite_items_lilypad1.h"
#include "bn_sprite_items_lilypad2.h"

lily::lily(bn::fixed_point position,
           arrow arr,
           bn::fixed scale,
           unsigned int anim_delay) :
           _spr(bn::sprite_items::lilypad2.create_sprite(position)),
           _anim(bn::create_sprite_animate_action_forever(
                    _spr,
                    anim_delay,
                    bn::sprite_items::lilypad2.tiles_item(),
                    0,1,2,3)),
            _arr(arr) {
            _spr.set_scale(scale);
}

void lily::update() {
    _spr.set_position(_spr.position() + _arr);
    _anim.update();
}