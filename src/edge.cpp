#include "edge.h"

#include <bn_math.h>
#include <bn_log.h>

// TODO: Probably lots of math optimizations!

bn::fixed dist(bn::fixed_point a, bn::fixed_point b) {
    // Can we use squared dists? Or work on the vector directly?
    bn::fixed dx = a.x() - b.x();
    bn::fixed dy = a.y() - b.y();
    return bn::sqrt(dx*dx + dy*dy);
}

edge::edge(node& start, node& end, bn::fixed k) :
    _start(start),
    _end(end),
    _k(k),
    _ideal_dist(dist(start.position(), end.position())) {}

void edge::exert() {
    BN_LOG("A");
    bn::fixed _cur_dist = dist(_start.position(), _end.position());

    if(_cur_dist == 0) {
        // avoid div by 0. Probably a better way to handle this?
        return;
    }
    bn::fixed force = (_cur_dist - _ideal_dist) * _k;
    BN_LOG("C");

    bn::fixed_point unit = (_end.position() - _start.position()) / _cur_dist;
    BN_LOG(unit.x(), " ", unit.y());

    _start.push(unit * force);
    _end.push(unit * -force);
}

/*

002
[WARN] GBA Debug:	-3.54199 11.4030
[WARN] GBA Debug:	0.86938 1.77929
[WARN] GBA Debug:	7.87011 -23.8117
[WARN] GBA Debug:	0.41796 -5.93164
[WARN] GBA Debug:	-1.83007 5.22705
[WARN] GBA Debug:	-0.43017 3.99780
[WARN] GBA Debug:	13.7219 -37.7902
[WARN] GBA Debug:	1.62280 -7.02758
[WARN] GBA Debug:	-1.96337 5.23730
[WARN] GBA Debug:	-3.89306 16.0485
[WARN] GBA Debug:	2.08862 -4.96752
[WARN] GBA Debug:	1.62084 -6.38330
[WARN] GBA Debug:	-1.46533 3.31665
[WARN] GBA Debug:	-2.23950 8.50048
[WARN] GBA Debug:	3.29418 -6.76049
[WARN] GBA Debug:	2.39770 -8.57666
[WARN] GBA Debug:	-1.84570 3.25341
[WARN] GBA Debug:	-2.73461 9.46777
[WARN] GBA Debug:	0.78466 -0.98950
[WARN] GBA Debug:	2.33520 -7.93896
[WARN] GBA Debug:	-0.57812 0.34912
[WARN] GBA Debug:	-2.48388 8.32543
[WARN] GBA Debug:	0.57519 0.54223
[WARN] GBA Debug:	2.90014 -9.42407
[WARN] GBA Debug:	-0.16235 -1.62451
[WARN] GBA Debug:	-17.6411 55.8286
[WARN] GBA Debug:	-2.02978 8.67187
[WARN] GBA Debug:	2.64282 -8.22436
[WARN] GBA Debug:	3.74414 -15.3740
[WARN] GBA Debug:	-3.17431 9.44140
[WARN] GBA Debug:	-2.35278 9.26977
[WARN] GBA Debug:	6.44799 -18.6669
[WARN] GBA Debug:	2.58544 -9.56127
[WARN] GBA Debug:	-1.97265 5.52685
[WARN] GBA Debug:	-2.85913 10.4020
[WARN] GBA Debug:	16.1506 -43.6420
[WARN] GBA Debug:	7.64965 11.7006
[WARN] GBA Debug*/