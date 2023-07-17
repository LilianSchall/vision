#include "sphere.hh"

Sphere::Sphere(Transform &_transform, double _radius) : Object(_transform), radius(_radius) {
    Engine::add_object(*this);
}

bool Sphere::hit(const Ray &ray, double t_min, double t_max, HitRecord& record) {
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

    if (delta < 0)
        return false;

    double sqrt_delta = sqrt(delta);

    double root = (-half_b - sqrt_delta) / a;

    if (root < t_min || root > t_max) {
        root = (-half_b + sqrt_delta) / a;
        if (root < t_min || root > t_max)
            return false;
    }

    record.t = root;
    record.p = ray.at(root);
    Vector3 outward_normal = (record.p - this->transform.position) / radius;
    record.set_face_normal(ray, outward_normal);

    return true;
}
