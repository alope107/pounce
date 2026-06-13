#pragma once

#include "node.h"

class edge {
public:
    edge(node& start, node& end, bn::fixed k);
    void exert();
private:
    node& _start;
    node& _end;
    bn::fixed _k;
    bn::fixed _ideal_dist;
};