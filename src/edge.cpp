#include "edge.h"

#include "screen_utils.h"
#include "vector_math.h"
// TODO: Probably lots of math optimizations!

#include "game.h"



edge::edge(game& g, node& start, node& end, bn::fixed k) :
    _g(g),
    _start(start),
    _end(end),
    _k(k),
    _scale(1),
    _ideal_dist(dist(start.position(), end.position()))
     {}

void edge::exert() {
    bn::fixed _cur_dist = dist(_start.position(), _end.position());

    if(_cur_dist == 0) {
        // avoid div by 0. Probably a better way to handle this?
        return;
    }
    bn::fixed force = (_cur_dist - (_ideal_dist * _scale)) * _k;

    bn::fixed_point unit = (_end.position() - _start.position()) / _cur_dist;

    _start.push(unit * force);
    _end.push(unit * -force);
}

void edge::draw() {
    _g.draw_line(_start.position(), _end.position());
}

bn::fixed edge::scale() {
    return _scale;
}

void edge::set_scale(bn::fixed scale) {
    _scale = scale;
}