#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_vector.h>

#include "edge.h"
#include "node.h"


int main() {
    bn::core::init();


    bn::vector<node, 10> nodes = {};
    bn::vector<edge, 10> edges = {};

    nodes.push_back(node({30, 0}));
    nodes.push_back(node({29, -40}));
    nodes.push_back(node({15, -20}));

    edges.push_back(edge(nodes[0], nodes[1], 1));
    edges.push_back(edge(nodes[1], nodes[2], 1));
    edges.push_back(edge(nodes[2], nodes[0], 1));

    while(true) {
        for(edge& edge : edges) {
            edge.exert();
        }
        for(node& node: nodes) {
            node.update();
        }
        bn::core::update();
    }
}

