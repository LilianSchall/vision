#ifndef HIT_RECORD_HH
#define HIT_RECORD_HH

#include "maths/maths.hh"
#include "maths/vector/vector3/vector3.hxx"

struct HitRecord {
    Point3 p;
    Vector3 normal;
    double t{};
    bool front_face{};

    inline void set_face_normal(const Ray &ray, const Vector3& outward_normal) {
        front_face = dot(ray.dir, outward_normal) < 0;
        normal = /*(!front_face) * (-1) * outward_normal; // <==>*/ front_face ? outward_normal : -outward_normal;
    }
};

#endif // !HIT_RECORD_HH
