#include "game.h"
#include "screen_utils.h"
#include "arrow_math.h"

#include "bn_palette_bitmap_items_pal.h"

#include <bn_keypad.h>

game::game() : _bg(bn::palette_bitmap_bg_ptr::create(bn::palette_bitmap_items::pal.palette_item())),
               _painter(_bg),
                _cursor(*this),
                _scale(1) {
    
    reset();
}

void game::reset() {
    _edges.clear();
    _nodes.clear();

    _nodes.emplace_back(bn::fixed_point(30, 0));
    _nodes.emplace_back(bn::fixed_point(29, -40));
    _nodes.emplace_back(bn::fixed_point(15, -20));

    _edges.emplace_back(*this, _nodes[0], _nodes[1], .5);
    _edges.emplace_back(*this, _nodes[1], _nodes[2], .5);
    //_edges.emplace_back(*this, _nodes[2], _nodes[0], .5);

    _joints.emplace_back(*this, _nodes[0], _nodes[1], _nodes[2], 30, true);
    _base_joint_angle = _joints[0].ideal_angle();
}

void game::update() {
    _painter.clear();
    if(bn::keypad::start_pressed()) reset();

    // TODO: tribool?
    if(bn::keypad::b_held() && bn::keypad::up_held()) {
        _scale += .01;
    }
    if(bn::keypad::b_held() && bn::keypad::down_held()) {
        _scale -= .01;
    }

    if(bn::keypad::b_released()) {
        _scale = 1;
    }

    _joints[0].set_ideal_angle(_base_joint_angle * _scale);

    _cursor.update();
    for(joint& joint : _joints) {
        joint.exert();
    }
    for(edge& edge : _edges) {
        edge.exert();
    }
    for(node& node: _nodes) {
        node.update();
    }

    
    for(edge& edge : _edges) {
        edge.draw();
    }
    _painter.flip_page_later();
}

void game::draw_line(const bn::fixed_point& start, const bn::fixed_point& end, int color_idx) {
    // Convert from game coordinates (origin at center)
    // to screen coordinates (origin at top-left)
    _painter.line(start.x().floor_integer() + MAX_X, 
                  start.y().floor_integer() + MAX_Y,
                  end.x().floor_integer() + MAX_X,
                  end.y().floor_integer() + MAX_Y,
                   color_idx);
}

node& game::emplace_node(bn::fixed_point position, bool connect) {
    auto& new_node = _nodes.emplace_back(position);

    bn::fixed squared_connect_thresh = 2000;

    if(connect) {
        for(auto it = _nodes.begin(); it < _nodes.end() -1; it++) {
            if(squared_dist(new_node.position(), it->position()) < squared_connect_thresh) {
                _edges.emplace_back(*this, new_node, *it, .5);
            }
        }
    }

    return new_node;
}