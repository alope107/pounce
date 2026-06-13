#pragma once

#include <bn_sprite_ptr.h>

class cursor {
public:
    cursor();
    void update();
private:
    bn::sprite_ptr _spr;

};