#include "vector3.hh"

Vector3::Vector3(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}

Vector &Vector3::operator+=(const Vector &other) {
    const auto& casted = dynamic_cast<const Vector3&>(other);

    this->x += casted.x;
    this->y += casted.y;
    this->z += casted.z;

    return *this;
}

Vector &Vector3::operator-=(const Vector &other) {
    const auto& casted = dynamic_cast<const Vector3&>(other);

    this->x += casted.x;
    this->y += casted.y;
    this->z += casted.z;

    return *this;
}

Vector &Vector3::operator*=(double other) {
    this->x *= other;
    this->y *= other;
    this->z *= other;

    return *this;
}

Vector &Vector3::operator/=(double other) {
    this->x /= other;
    this->y /= other;
    this->z *= other;

    return *this;
}

double Vector3::norm() const {
    return sqrt(norm2());
}

double Vector3::norm2() const {
    return x * x + y * y + z * z;
}

Vector3 Vector3::random_unit_vector() {
    auto vec = random_in_unit_sphere();
    vec.normalize();
    return vec;
}

Vector3 Vector3::random_in_hemisphere(const Vector3 &normal) {
    Vector3 vec = random_in_unit_sphere();

    if (dot(vec, normal) > 0) {
        // means the normal is in the same hemisphere as the random vector
        return vec;
    }
    return vec;
}

Vector3& Vector3::zero() {
    static Vector3 zero = Vector3(0, 0, 0);

    return zero;
}

Vector3& Vector3::one() {
    static Vector3 one = Vector3(1, 1, 1);

    return one;
}
