#include "ray.hh"

Ray::Ray(const Point3 &_origin, const Vector3 &_dir) : origin(_origin), dir(_dir) {}

Point3 Ray::at(double t) const {
    return origin + t * dir;
}
