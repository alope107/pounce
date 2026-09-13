#pragma once

#include <bn_sprite_ptr.h>
#include <bn_rect.h>
#include "arrow_math.h"

#include <bn_sprite_animate_actions.h>

#include <bn_sprite_items_snack.h>
#include <bn_sprite_items_deadsnack.h>
#include <bn_sprite_items_salmon.h>
#include <bn_sprite_items_deadsalmon.h>
#include <bn_sprite_items_puffer.h>
#include <bn_sprite_items_deadpuffer.h>
#include <bn_sprite_items_realgoldfish.h>
#include <bn_sprite_items_deadgoldfish.h>

enum FISH_TYPE {
    SNACK,
    SALMON,
    PUFFER,
    GOLDFISH,
    // CHIP,
};

struct fish_info {
    bn::sprite_item alive;
    bn::sprite_item dead;
    int swim_frames;
};

// todo: compute
static constexpr int MAX_FISH_FRAMES = 10;

// TODO: better data structure
static constexpr fish_info FISH_TABLE[4] = {
    fish_info{bn::sprite_items::snack, bn::sprite_items::deadsnack, 8},
    fish_info{bn::sprite_items::salmon, bn::sprite_items::deadsalmon, 3},
    fish_info{bn::sprite_items::puffer, bn::sprite_items::deadpuffer, 10},
    fish_info{bn::sprite_items::realgoldfish, bn::sprite_items::deadgoldfish, 3},
};

class fish {
    public:
        fish(bn::fixed_point start_position, FISH_TYPE fish_type, bn::rect bounds, arrow start_vel={.5, .5});
        void update();
        bn::rect hitbox();
    private:
        bn::sprite_ptr _spr;
        // Use cached animation? Or seomthing else?
        // This feels heavyweight
        bn::sprite_animate_action<MAX_FISH_FRAMES> _anim;
        bn::rect _bounds;
        arrow _vel;
};