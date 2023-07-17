#ifndef OBJECT_HH
#define OBJECT_HH

#include "transform/transform.hh"
#include "maths/ray/ray.hh"

class Object {
public:
    explicit Object(Transform &_transform);
    virtual double hit(const Ray &ray);

public:
    Transform transform;
};

#endif // !OBJECT_HH