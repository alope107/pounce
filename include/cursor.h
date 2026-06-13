#pragma once

#include <bn_sprite_ptr.h>

class cursor {
public:
    cursor(bn::fixed_point start={0, 0}, bn::fixed speed=3);
    void update();
private:
    bn::sprite_ptr _spr;
    bn::fixed _speed;
};