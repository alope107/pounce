#include "game.h"

game::game() {
    _nodes.push_back(node({30, 0}));
    _nodes.push_back(node({29, -40}));
    _nodes.push_back(node({15, -20}));

    _edges.push_back(edge(_nodes[0], _nodes[1], 1));
    _edges.push_back(edge(_nodes[1], _nodes[2], 1));
    _edges.push_back(edge(_nodes[2], _nodes[0], 1));
}

void game::update() {
    _cursor.update();
    for(edge& edge : _edges) {
        edge.exert();
    }
    for(node& node: _nodes) {
        node.update();
    }
}