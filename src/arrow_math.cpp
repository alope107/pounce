#include "arrow_math.h"
#include <bn_math.h>

// angle between 2 arrows
bn::fixed angle(const arrow& u, const arrow& v) {
    // angle = atan2(||u x v||, u dot v)

    // Todo: bit shifting of data to get better precision?
    int num = cross(u, v).floor_integer();
    int denom = dot(u, v).floor_integer();

    // alternatively, approximate with diamond angle?
    bn::fixed angle = bn::atan2(num, denom);

    return angle;
}

//angle between 3 points
bn::fixed angle(const bn::fixed_point& a, const bn::fixed_point& hinge, const bn::fixed_point& b) {
    arrow u = a - hinge;
    arrow v = b - hinge;

    return angle(u, v);
}

arrow degrees_to_arrow(bn::fixed degrees, bn::fixed magnitude) {
    auto trig = bn::degrees_lut_sin_and_cos(bn::safe_degrees_angle(degrees));
    return {magnitude * trig.second, magnitude * trig.first};
}

bn::fixed arrow_to_degrees(arrow u) {
    // todo: better way to round less? diamond angle?
    return bn::safe_degrees_angle(bn::degrees_atan2(u.y().shift_integer(), u.x().shift_integer()));
}