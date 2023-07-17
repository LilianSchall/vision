#ifndef SPHERE_HH
#define SPHERE_HH

#include "object/object.hh"
#include "maths/ray/ray.hh"
#include "engine/engine.hh"

class Sphere : public Object {

public:
    Sphere(Transform &_transform, double _radius);
    bool hit(const Ray &ray, double t_min, double t_max, HitRecord& record) override;
private:
    double radius;
};

#endif // !SPHERE_HH
