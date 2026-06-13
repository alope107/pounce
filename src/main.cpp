#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>

#include "bn_sprite_items_node.h"


int main() {
    bn::core::init();

    bn::sprite_ptr node = bn::sprite_items::node.create_sprite();

    while(true) {

        bn::core::update();
    }
}