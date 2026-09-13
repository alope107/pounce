#include "fish.h"

#include <bn_rect.h>
#include <bn_log.h>
#include <bn_assert.h>

#include "screen_utils.h"

#include "bn_sprite_items_snack.h"

#include "bn_sprite_tiles_item.h"



namespace {
    static constexpr int FISH_WIDTH = 16;
    static constexpr int FISH_HEIGHT = 16;
}

bn::sprite_animate_action<MAX_FISH_FRAMES> make_fish_anim(bn::sprite_ptr spr, FISH_TYPE fish_type) {
    auto item = FISH_TABLE[fish_type].alive;
    int delay = 9; // TODO: configure per fish?

    // will be overwritten
    // TODO: more elegant way?
    bn::sprite_animate_action<MAX_FISH_FRAMES> anim = bn::create_sprite_animate_action_forever(
                spr,
                delay,
                item.tiles_item(),
                0,1,2,3,4,5,6,7
            );;

    // Todo: proprely expand anim frames instead of hard coding
    switch (fish_type) {
        case FISH_TYPE::SNACK:
            anim = bn::create_sprite_animate_action_forever(
                spr,
                delay,
                item.tiles_item(),
                0,1,2,3,4,5,6,7
            );
            break;
        case FISH_TYPE::SALMON:
            anim = bn::create_sprite_animate_action_forever(
                spr,
                delay,
                item.tiles_item(),
                0,1,2
            );
            break;
        case FISH_TYPE::PUFFER:
            anim = bn::create_sprite_animate_action_forever(
                spr,
                delay,
                item.tiles_item(),
                0,1,2,3,4,5,6,7,8,9
            );
            break;
        case FISH_TYPE::GOLDFISH:
            anim = bn::create_sprite_animate_action_forever(
                spr,
                delay,
                item.tiles_item(),
                0,1,2
            );
            break;
        default:
            BN_ASSERT(false, "Unknown fish type");
    }
    return anim;
}

fish::fish(bn::fixed_point start_position, FISH_TYPE fish_type, bn::rect bounds, arrow start_vel) :
    _fish_type(fish_type),
    _spr(FISH_TABLE[fish_type].alive.create_sprite(start_position)),
    // TODO: std::apply or macro to expand animation frames?
    _anim(make_fish_anim(_spr, fish_type)),
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
    // _spr.set_rotation_angle_safe(arrow_to_degrees({_vel.x(), -_vel.y()}));
    _anim.update();
}

bn::rect fish::hitbox() {
    // TODO: if there are multiple collision checks per frame we will want to cache the hitbox
    return bn::rect(round_fixed_point(_spr.position()),
                              {FISH_WIDTH, FISH_HEIGHT});
}

FISH_TYPE fish::fish_type() {
    return _fish_type;
}