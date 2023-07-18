#ifndef MATHS_HH
#define MATHS_HH

#include "maths.hxx"

#include <random>

class Vector3;
using Point3 = Vector3;
using RgbColor = Vector3;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double deg_to_rad(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;

    return distribution(generator);
}

inline double random_double(double min, double max) {
    return min + (max - min) * random_double();
}

#endif // !MATHS_HH
