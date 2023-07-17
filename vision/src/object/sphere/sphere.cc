#include "sphere.hh"

Sphere::Sphere(Transform &_transform, double _radius) : Object(_transform), radius(_radius) {}

double Sphere::hit(const Ray &ray) {
    // The equation of a sphere of center C with a Point P on the sphere is:
    // (P - C) \dot (P - C) = radius ^ 2
    // We want to know if our Ray P(t) = origin + t * dir ever hits the sphere
    // If it does, then a certain t exists that satisfies the following equation:
    // (P(t) - C) \dot (P(t) - C) = radius ^ 2
    // By expanding this equation we get:
    // t^2 * ||dir||_2 + 2 * t * dir \dot (origin - C) + ||origin - C||_2 - radius^2 = 0
    // which is a quadratic equation.
    // So if delta = 0, we have one point that intersects with our ray,
    // If delta > 0, we have two points, else none.
    Vector3 origin_to_center = ray.origin - this->transform.position;

    double a = ray.dir.norm2();
    double half_b = dot(origin_to_center, ray.dir);
    double c = origin_to_center.norm2() - radius * radius;

    double delta = half_b * half_b - a * c;

    // branch-less programming: this is the same as:
    // if delta < 0 : return -1 else return x1
    // check-out this awesome video: https://youtu.be/bVJ-mWWL7cE
    return (delta < 0) * -1 + (delta >= 0) * ((-half_b - sqrt(delta)) / (a));
}
