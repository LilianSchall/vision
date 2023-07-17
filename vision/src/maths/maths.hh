#ifndef MATHS_HH
#define MATHS_HH

#include "maths.hxx"

class Vector3;
using Point3 = Vector3;
using RgbColor = Vector3;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double deg_to_rad(double degrees) {
    return degrees * pi / 180.0;
}

#endif // !MATHS_HH
