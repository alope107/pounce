#include "arrow_math.h"

// angle between 2 arrows
bn::fixed angle(const arrow& u, const arrow& v) {
    // angle = atan2(||u x v||, u dot v)

    // atan2 requires num/denom as ints
    // getting internal fixed point data is equivalent to multiplying by (1 << precision)
    // if we multiply this with both the numerator and denominator it's equivalnt to multiplying by 1/1
    // We then get ints without any loss of precision
    // I'm a little worried about overflowing atan2 internally, but we'll see!
    int num = cross(u, v).floor_integer();
    int denom = dot(u, v).floor_integer();

    // do we want atan or atan2 here...
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