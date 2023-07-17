#ifndef SPHERE_HH
#define SPHERE_HH

#include "object/object.hh"
#include "maths/ray/ray.hh"

class Sphere : public Object {

public:
    Sphere(Transform &_transform, double _radius);
    double hit(const Ray &ray) override;
private:
    double radius;
};

#endif // !SPHERE_HH
