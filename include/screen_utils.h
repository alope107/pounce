#pragma once
#include <bn_fixed_point.h>
#include <bn_math.h>

static const int MIN_X = -120;
static const int MIN_Y = -80;
static const int MAX_X = 120;
static const int MAX_Y = 80;


inline bn::fixed clamp(int min, int max, bn::fixed val) {
    return val < min ? min : val > max ? max : val;
}

inline bn::fixed_point clamp_point(int min_x, int min_y, int max_x, int max_y, bn::fixed_point point) {
    return {
        clamp(min_x, max_x, point.x()),
        clamp(min_y, max_y, point.y())
    };
}

inline bn::fixed_point clamp_to_screen (const bn::fixed_point& point) {
    return clamp_point(MIN_X, MIN_Y, MAX_X, MAX_Y, point);
}

inline int tribool (bool neg, bool pos) {
    if((neg && pos) || (!neg && !pos)) return 0;
    return neg ? -1 : 1;
}

inline bn::fixed squared_dist(const bn::fixed_point& a, const bn::fixed_point& b) {
    bn::fixed dx = a.x() - b.x();
    bn::fixed dy = a.y() - b.y();
    return dx*dx + dy*dy;
}

inline bn::fixed dist(const bn::fixed_point& a, const bn::fixed_point& b) {
    return bn::sqrt(squared_dist(a, b));
}