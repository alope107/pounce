#include "game.h"
#include "screen_utils.h"

game::game() : _cursor(*this) {
    _nodes.emplace_back(bn::fixed_point(30, 0));
    _nodes.emplace_back(bn::fixed_point(29, -40));
    _nodes.emplace_back(bn::fixed_point(15, -20));

    _edges.emplace_back(_nodes[0], _nodes[1], 1);
    _edges.emplace_back(_nodes[1], _nodes[2], 1);
    _edges.emplace_back(_nodes[2], _nodes[0], 1);
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

node& game::emplace_node(bn::fixed_point position, bool connect) {
    auto& new_node = _nodes.emplace_back(position);

    bn::fixed squared_connect_thresh = 2000;

    if(connect) {
        for(auto it = _nodes.begin(); it < _nodes.end() -1; it++) {
            if(squared_dist(new_node.position(), it->position()) < squared_connect_thresh) {
                _edges.emplace_back(new_node, *it, 1);
            }
        }
    }

    return new_node;
}