#ifndef VECTOR3_HH
#define VECTOR3_HH

#include "maths/vector/vector.hh"
#include "maths/maths.hh"

class Vector3 : public Vector {
public:
    Vector3() = default;
    Vector3(double  _x, double _y, double _z);
    Vector& operator+=(const Vector& other) override;
    Vector& operator-=(const Vector& other) override;
    Vector& operator*=(double other) override;
    Vector& operator/=(double other) override;
    [[nodiscard]] double norm() const override;
    [[nodiscard]] double norm2() const override;

    static Vector3& zero();
    static Vector3& one();
    static inline Vector3 random() {
        return Vector3{random_double(), random_double(), random_double()};
    }

    static inline Vector3 random(int min, int max) {
        return Vector3{random_double(min,max), random_double(min,max), random_double(min, max)};
    }

public:
    double x = 0;
    double y = 0;
    double z = 0;
};

#include "vector3.hxx"

#endif // !VECTOR3_HH