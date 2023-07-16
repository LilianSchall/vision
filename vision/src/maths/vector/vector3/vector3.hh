#ifndef VECTOR3_HH
#define VECTOR3_HH

#include "maths/vector/vector.hh"

class Vector3 : public Vector {
public:
    Vector3(double  _x, double _y, double _z);
    Vector& operator+=(const Vector& other) override;
    Vector& operator-=(const Vector& other) override;
    Vector& operator*=(double other) override;
    Vector& operator/=(double other) override;
    double norm() override;
    double norm2() override;

public:
    double x;
    double y;
    double z;

};

#include "vector3.hxx"

#endif // !VECTOR3_HH