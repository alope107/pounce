#include "end_screen.h"

#include <bn_keypad.h>

#include "bn_sprite_items_fritojump.h"
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
    _stack(bn::fixed_point{-50, 30}, _state) {
    if(_state.caught().size() < HAPPY_THRESH) {
        bn::sound_items::losetrumpet.play();
    } else if (_state.caught().size() < EXCITED_THRESH) {
        bn::sound_items::positive.play();
    } else {
        bn::sound_items::won.play();
    }
}

GAME_TYPE end_screen::update() {
    if(bn::keypad::a_pressed() || 
       bn::keypad::b_pressed() ||
       bn::keypad::start_pressed()) {
        // Todo: transition animation
        return GAME_TYPE::TITLE_SCREEN;
    }

    _frito_anim.update();
    _stack.update();

    return GAME_TYPE::END_SCREEN;
}