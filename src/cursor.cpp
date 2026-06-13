#include "cursor.h"
#include "screen_utils.h"

#include <bn_keypad.h>

#include "bn_sprite_items_cursor.h"

cursor::cursor(bn::fixed_point start, bn::fixed speed) 
: _spr(bn::sprite_items::cursor.create_sprite(start)),
  _speed(speed) {
}

void cursor::update() {
    bn::fixed_point delta = {
        tribool(bn::keypad::left_held(), bn::keypad::right_held()) * _speed,
        tribool(bn::keypad::up_held(), bn::keypad::down_held()) * _speed
    };

    bn::fixed_point new_pos = clamp_to_screen(_spr.position() + delta);
    _spr.set_position(new_pos);
}