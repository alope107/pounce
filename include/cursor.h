#pragma once

#include <bn_sprite_ptr.h>

class jump_game;


class cursor {
public:
    cursor(jump_game& g, bn::fixed_point start={0, 0}, bn::fixed speed=3);
    void update();
private:
    jump_game& _g;
    bn::sprite_ptr _spr;
    bn::fixed _speed;
    void _spawn_node();

};