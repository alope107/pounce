#pragma once

#include "node.h"

class jump_game;

class edge {
public:
    edge(jump_game& g, node& start, node& end, bn::fixed k);
    void exert();
    void draw();
    bn::fixed scale();
    void set_scale(bn::fixed scale);
private:
    jump_game& _g;
    node& _start;
    node& _end;
    bn::fixed _k;
    bn::fixed _scale;
    bn::fixed _ideal_dist;
};