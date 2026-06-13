#pragma once

#include "node.h"

class game;

class edge {
public:
    edge(game& g, node& start, node& end, bn::fixed k);
    void exert();
    void draw();
private:
    game& _g;
    node& _start;
    node& _end;
    bn::fixed _k;
    bn::fixed _ideal_dist;
};