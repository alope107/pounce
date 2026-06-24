#pragma once

#include <bn_fixed_point.h>
#include <bn_math.h>

// 2d arrow representing a dx and a dy - a 1d (mathematical) vector with 2 elements
// Used to distinguish from a 2d point
// (a better name would be "vector", but avoiding that to avoid confusion with bn::vector)
typedef bn::fixed_point arrow;

inline bn::fixed squared_dist(const bn::fixed_point& a, const bn::fixed_point& b) {
    bn::fixed dx = a.x() - b.x();
    bn::fixed dy = a.y() - b.y();
    return dx*dx + dy*dy;
}

inline bn::fixed dist(const bn::fixed_point& a, const bn::fixed_point& b) {
    return bn::sqrt(squared_dist(a, b));
}

inline bn::fixed dot(const arrow& u, const arrow& v) {
    return u.x()*v.x() + u.y()*v.y();
}

inline bn::fixed cross(const arrow& u, const arrow& v) {
    return u.x()*v.y() - u.y()*v.x();
}

inline bn::fixed magnitude(const arrow& vec) {
    return bn::sqrt(vec.x()*vec.x() + vec.y()*vec.y());
}

// Returns an arrow in the same direction with magnitude 1
// TODO: Handle {0, 0} vector?
inline arrow unit(const arrow& vec) {
    return vec / magnitude(vec);
}

// normal (perpendicular) with same magnitude
// TODO: explore consequences of negating y vs x
inline arrow normal(const arrow& vec) {
    return {-vec.y(), vec.x()};
}

// angle between 2 arrows
bn::fixed angle(const arrow& u, const arrow& v);

//angle between 3 points
bn::fixed angle(const bn::fixed_point& a, const bn::fixed_point& hinge, const bn::fixed_point& b);

// Creates an arrow that forms angle degress with X axis and has a length of magnitude
arrow degrees_to_arrow(bn::fixed angle, bn::fixed magnitude);

// Calculates the angle of the arrow with the X axis: [-180, 180]
bn::fixed arrow_to_degrees(arrow u);