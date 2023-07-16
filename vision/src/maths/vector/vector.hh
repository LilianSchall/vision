#ifndef VECTOR_HH
#define VECTOR_HH

#include <cmath>

class Vector {
public:
    virtual Vector& operator+=(const Vector& other) = 0;
    virtual Vector& operator-=(const Vector& other) = 0;
    virtual Vector& operator*=(double other) = 0;
    virtual Vector& operator/=(double other) = 0;
    virtual double norm() = 0;
    virtual double norm2() = 0;
    Vector& normalize() {
        *this /= norm();
        return *this;
    }
};

#endif // !VECTOR_HH