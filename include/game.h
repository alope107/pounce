#pragma once 

#include <bn_vector.h>
#include "edge.h"
#include "cursor.h"
#include "node.h"

static constexpr int MAX_NODES = 50;
static constexpr int MAX_EDGES = 50;


class game {
public:
    game();
    void update();
    node& emplace_node(bn::fixed_point position, bool connect); 
private:
    bn::vector<node, MAX_NODES> _nodes;
    bn::vector<edge, MAX_EDGES> _edges;
    cursor _cursor;
};