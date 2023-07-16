#ifndef VECTOR3_HXX
#define VECTOR3_HXX

#include <ostream>

#include "vector3.hh"

inline std::ostream &operator<<(std::ostream &out, const Vector3 &v) {
    return out << v.x << ' ' << v.y << ' ' << v.z;
}

inline Vector3 operator+(const Vector3 &u, const Vector3 &v) {
    return Vector3{u.x + v.x, u.y + v.y, u.z + v.z};
}

inline Vector3 operator-(const Vector3 &u, const Vector3 &v) {
    return Vector3{u.x - v.x, u.y - v.y, u.z - v.z};
}

inline Vector3 operator*(const Vector3 &u, const Vector3 &v) {
    return Vector3{u.x * v.x, u.y * v.y, u.z * v.z};
}

inline Vector3 operator*(double c, const Vector3 &v) {
    return Vector3{v.x * c, v.y * c, v.z * c};
}

inline Vector3 operator*(const Vector3 &v, double c) {
    return c * v;
}

inline Vector3 operator/(const Vector3 &v, double c) {
    return (1 / c) * v;
}

inline double dot(const Vector3 &u, const Vector3 &v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

inline Vector3 cross(const Vector3 &u, const Vector3 &v) {
    return Vector3{u.y * v.z - u.z * v.y,
                   u.z * v.x - u.x * v.z,
                   u.x * v.y - u.y * v.x};
}

#endif // !VECTOR3_HXX
