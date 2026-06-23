#pragma once

#include "node.h"

class jump_game;

class joint {
public:
    joint(jump_game& g, node& a, node& hinge, node& b, bn::fixed k, bool draw_debug=false);
    void exert();
    bn::fixed ideal_angle();
    void set_ideal_angle(bn::fixed new_angle);
private:
    jump_game& _g;
    node& _a;
    node& _hinge;
    node& _b;
    bn::fixed _k;
    bn::fixed _ideal_angle;
    bool _draw_debug;
};