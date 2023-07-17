#include "object.hh"

Object::Object(Transform &_transform): transform(_transform){}

double Object::hit(const Ray &ray) {
    // TODO: deactivate unused parameter for this method because
    //       for now I have used a weird trick
    if (ray.origin.x)
        return 0.0;
    return 0.0;
}
