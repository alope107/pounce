#pragma once

#include "node.h"

class joint {
public:
    joint(node& a, node& hinge, node& b, bn::fixed k);
    void exert();
    bn::fixed ideal_angle();
    void set_ideal_angle(bn::fixed new_angle);
private:
    node& _a;
    node& _hinge;
    node& _b;
    bn::fixed _k;
    bn::fixed _ideal_angle;
};