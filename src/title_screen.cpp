#include "title_screen.h"

#include <bn_keypad.h>
#include <bn_sprite_text_generator.h>

#include "bn_sprite_items_fritobuttshake.h"
#include "bn_sprite_items_lilypad1.h"
#include "bn_sprite_items_lilypad2.h"
#include "bn_regular_bg_items_background.h"

#include "fuzzyfont.h"

#include "bn_sound_items.h"
#include "bn_sprite_items_title.h"

static constexpr bn::fixed_point FRITO_TITLE_POS = {0, -25};
static constexpr int FRITO_BUTT_DELAY = 18;


title_screen::title_screen() :
    _bg(bn::regular_bg_items::background.create_bg()),
    _frito_spr(bn::sprite_items::fritobuttshake.create_sprite(FRITO_TITLE_POS)),
    _frito_anim(bn::create_sprite_animate_action_forever(
                 _frito_spr,
                 FRITO_BUTT_DELAY, 
                bn::sprite_items::fritobuttshake.tiles_item(),
                0,1,2,3,4,5)),
    _lillies(),
    _song(bn::sound_items::talkingcute.play()),
    _title(bn::sprite_items::title.create_sprite({-90, -50})) {
        _lillies.push_back(lily({30, 12}, {0, 0}, .7, 20));
        _lillies.push_back(lily({-25, 26}, {0, 0}, 1));

        _flowers.push_back(flower({-90, 45}));
        _flowers.push_back(flower({-60, 55}));
        _flowers.push_back(flower({100, 30}));
        _flowers.push_back(flower({60, 50}));

        bn::sprite_text_generator text_generator(fuzzyfont);
        text_generator.set_alignment(bn::sprite_text_generator::alignment_type::CENTER);
        text_generator.generate({0, 68}, "PRESS A", _text_sprs);
}

GAME_TYPE title_screen::update() {
    if(bn::keypad::a_pressed() || 
       bn::keypad::b_pressed() ||
       bn::keypad::start_pressed()) {
        // Todo: transition animation
        return GAME_TYPE::FISH_GAME;
    }

    _frito_anim.update();
    for(auto &lil : _lillies) {
        lil.update();
    }

    for(auto& flow : _flowers) {
        flow.update();
    }

    if(!_song.active()) {
        _song = bn::sound_items::talkingcute.play();
    }

    return GAME_TYPE::TITLE_SCREEN;
}

title_screen::~title_screen() {
    _song.stop();
}