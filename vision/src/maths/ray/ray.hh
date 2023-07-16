#ifndef RAY_HH
#define RAY_HH

#include "maths/vector/vector3/vector3.hh"
#include "maths/maths.hh"

class Ray {
public:
    Ray(const Point3 &_origin, const Vector3 &_dir);

    [[nodiscard]] Point3 at(double t) const;

public:
    Point3 origin;
    Vector3 dir;
};

#endif // !RAY_HH
