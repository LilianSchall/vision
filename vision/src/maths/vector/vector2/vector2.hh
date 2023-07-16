#ifndef VECTOR2_HH
#define VECTOR2_HH

#include "maths/vector/vector.hh"

class Vector2 : public Vector {
public:
    Vector2(double _x, double _y);
     Vector& operator+=(const Vector& other) override;
     Vector& operator-=(const Vector& other) override;
     Vector& operator*=(double other) override;
     Vector& operator/=(double other) override;
     double norm() override;
     double norm2() override;

public:
    double x;
    double y;

};

#include "vector2.hxx"

#endif // !VECTOR2_HH