#pragma once

#include <bn_sprite_ptr.h>

class game;


class cursor {
public:
    cursor(game& g, bn::fixed_point start={0, 0}, bn::fixed speed=3);
    void update();
private:
    game& _g;
    bn::sprite_ptr _spr;
    bn::fixed _speed;
    void _spawn_node();

};