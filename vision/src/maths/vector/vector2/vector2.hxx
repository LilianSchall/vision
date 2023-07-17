#ifndef VECTOR2_HXX
#define VECTOR2_HXX

#include <ostream>

#include "vector2.hh"

inline std::ostream &operator<<(std::ostream &out, const Vector2 &v) {
    return out << v.x << ' ' << v.y;
}

inline Vector2 operator+(const Vector2 &u, const Vector2 &v) {
    return Vector2{u.x + v.x, u.y + v.y};
}

inline Vector2 operator-(const Vector2 &u, const Vector2 &v) {
    return Vector2{u.x - v.x, u.y - v.y};
}

inline Vector2 operator-(const Vector2 &u) {
    return Vector2{-u.x, -u.y};
}

inline Vector2 operator*(const Vector2 &u, const Vector2 &v) {
    return Vector2{u.x * v.x, u.y * v.y};
}

inline Vector2 operator*(double c, const Vector2 &v) {
    return Vector2{v.x * c, v.y * c};
}

inline Vector2 operator*(const Vector2 &v, double c) {
    return c * v;
}

inline Vector2 operator/(const Vector2 &v, double c) {
    return (1 / c) * v;
}

inline double dot(const Vector2 &u, const Vector2 &v) {
    return u.x * v.x + u.y * v.y;
}

#endif // !VECTOR2_HXX
