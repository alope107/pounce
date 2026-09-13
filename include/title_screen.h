#pragma once

#include <bn_regular_bg_ptr.h>
#include <bn_sprite_animate_actions.h>
#include <bn_vector.h>
#include "bn_sound_handle.h"

#include "game.h"
#include "lily.h"

static constexpr int FRITO_BUTT_FRAMES = 6;
static constexpr int TITLE_LILY_COUNT = 4;

class title_screen : public game {
    public:
        title_screen();
        ~title_screen();
        GAME_TYPE update();
        
    private:
        bn::regular_bg_ptr _bg;
        // Maybe make Frito + animation her own class?
        bn::sprite_ptr _frito_spr;
        bn::sprite_animate_action<FRITO_BUTT_FRAMES> _frito_anim;
        bn::vector<lily, TITLE_LILY_COUNT> _lillies;
        bn::vector<bn::sprite_ptr, 20> _text_sprs;
        bn::sound_handle _song;
};