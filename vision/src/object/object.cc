#include "object.hh"

Object::Object(Transform &_transform): transform(_transform){}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

bool Object::hit(const Ray &ray, double t_min, double t_max, HitRecord &record) {
    return false;
}
#pragma GCC diagnostic pop
