#ifndef OBJECT_HH
#define OBJECT_HH

#include "transform/transform.hh"
#include "maths/ray/ray.hh"
#include "maths/ray/hit_record.hh"

class Object {
public:
    explicit Object(Transform &_transform);
    virtual ~Object() = default;
    virtual bool hit(const Ray &ray, double t_min, double t_max, HitRecord& record);

public:
    Transform transform;
};

#endif // !OBJECT_HH