#pragma once 
#include <bn_palette_bitmap_bg_builder.h>
#include <bn_palette_bitmap_bg_painter.h>
#include <bn_vector.h>
#include "edge.h"
#include "cursor.h"
#include "node.h"

static constexpr int MAX_NODES = 300;
static constexpr int MAX_EDGES = 300;


class game {
public:
    game();
    void update();
    void reset();
    void draw_line(const bn::fixed_point& start, const bn::fixed_point end);
    node& emplace_node(bn::fixed_point position, bool connect); 
private:
    bn::palette_bitmap_bg_ptr _bg;
    bn::palette_bitmap_bg_painter _painter;
    bn::vector<node, MAX_NODES> _nodes;
    bn::vector<edge, MAX_EDGES> _edges;
    cursor _cursor;
};