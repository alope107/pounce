#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_vector.h>

#include "node.h"


int main() {
    bn::core::init();


    bn::vector<node, 10> nodes = {};

    nodes.push_back(node({30, 0}));
    nodes.push_back(node({10, -20}));

    while(true) {
        for(node& node: nodes) {
            node.update();
        }
        bn::core::update();
    }
}