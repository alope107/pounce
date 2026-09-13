#include "end_screen.h"

#include <bn_keypad.h>

#include "bn_sprite_items_fritojump.h"
#include "bn_sprite_items_sadfrito.h"
#include "bn_sprite_items_happyfrito.h"
#include "bn_regular_bg_items_endscreen.h"
#include "bn_sound_items.h"

static constexpr bn::fixed_point FRITO_END_POS = {0, 0};
static constexpr int FRITO_JUMP_DELAY = 18;

end_screen::end_screen(game_state& state) :
    _state(state),
    _bg(bn::regular_bg_items::endscreen.create_bg()),
    _frito_spr(bn::sprite_items::fritojump.create_sprite(FRITO_END_POS)),
    _frito_anim(bn::create_sprite_animate_action_forever(
        _frito_spr,
        FRITO_JUMP_DELAY,
        bn::sprite_items::fritojump.tiles_item(),
        0,1,2,3,4,5,6,7,8,9,10,11
    )),
    _stack(bn::fixed_point{-50, 30}, _state),
    _jingle_started(false) {

    if(_state.caught().size() < HAPPY_THRESH) {
        _frito_spr = bn::sprite_items::sadfrito.create_sprite(FRITO_END_POS);
        _frito_anim =bn::create_sprite_animate_action_forever(
            _frito_spr,
            FRITO_JUMP_DELAY,
            bn::sprite_items::sadfrito.tiles_item(),
            0,1,2,3,4,5,6,7
        );
    } else if (_state.caught().size() < EXCITED_THRESH) {
        _frito_spr = bn::sprite_items::happyfrito.create_sprite(FRITO_END_POS);
        _frito_anim =bn::create_sprite_animate_action_forever(
            _frito_spr,
            FRITO_JUMP_DELAY,
            bn::sprite_items::happyfrito.tiles_item(),
            0,1,2,3,4,5,6
        );
    } 
}

GAME_TYPE end_screen::update() {
    if(bn::keypad::a_pressed() || 
       bn::keypad::b_pressed() ||
       bn::keypad::start_pressed()) {
        // Todo: transition animation
        return GAME_TYPE::TITLE_SCREEN;
    }

    if(!_jingle_started && _stack.done_stacking()) {
        _jingle_started = true;
        if(_state.caught().size() < HAPPY_THRESH) {
            bn::sound_items::losetrumpet.play();
        } else if (_state.caught().size() < EXCITED_THRESH) {
            bn::sound_items::positive.play();
        } else {
            bn::sound_items::won.play();
        }
    }

    _frito_anim.update();
    _stack.update();

    return GAME_TYPE::END_SCREEN;
}