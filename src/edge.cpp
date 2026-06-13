#include "edge.h"

#include "screen_utils.h"
// TODO: Probably lots of math optimizations!



edge::edge(node& start, node& end, bn::fixed k) :
    _start(start),
    _end(end),
    _k(k),
    _ideal_dist(dist(start.position(), end.position())) {}

void edge::exert() {
    bn::fixed _cur_dist = dist(_start.position(), _end.position());

    if(_cur_dist == 0) {
        // avoid div by 0. Probably a better way to handle this?
        return;
    }
    bn::fixed force = (_cur_dist - _ideal_dist) * _k;
    // force = clamp(-2, 2, force);

    bn::fixed_point unit = (_end.position() - _start.position()) / _cur_dist;

    _start.push(unit * force);
    _end.push(unit * -force);
}