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

double Vector3::norm() {
    return sqrt(norm2());
}

double Vector3::norm2() {
    return x * x + y * y + z * z;
}

