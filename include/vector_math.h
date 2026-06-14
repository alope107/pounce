#pragma once

#include <bn_fixed_point.h>
#include <bn_math.h>

inline bn::fixed squared_dist(const bn::fixed_point& a, const bn::fixed_point& b) {
    bn::fixed dx = a.x() - b.x();
    bn::fixed dy = a.y() - b.y();
    return dx*dx + dy*dy;
}

inline bn::fixed dist(const bn::fixed_point& a, const bn::fixed_point& b) {
    return bn::sqrt(squared_dist(a, b));
}

inline bn::fixed_point dot(bn::fixed_point& a, bn::fixed_point& b) {
    return {a.x()*b.x(), a.y()*b.y()};
}

inline bn::fixed magnitude(bn::fixed_point& pt) {
    return bn::sqrt(pt.x()*pt.x() + pt.y()*pt.y());
}

// bn::fixed angle(bn::fixed_point& a, bn::fixed_point& hinge, bn::fixed_point& b) {
//     bn::fixed_point v1 = a - hinge;
//     bn::fixed_point v2 = b - hinge;

//     return bn::
// }
