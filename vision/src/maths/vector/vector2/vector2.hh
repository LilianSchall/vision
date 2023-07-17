#ifndef VECTOR2_HH
#define VECTOR2_HH

#include <SDL2/SDL.h>

#include "maths/vector/vector.hh"

class Vector2 : public Vector {
public:
    Vector2(double _x, double _y);
    Vector& operator+=(const Vector& other) override;
    Vector& operator-=(const Vector& other) override;
    Vector& operator*=(double other) override;
    Vector& operator/=(double other) override;
    double norm() const override;
    double norm2() const override;

    SDL_Rect to_sdl_rect(int width, int height);

    static Vector2& zero();
    static Vector2& one();


public:
    double x;
    double y;

};

#include "vector2.hxx"

#endif // !VECTOR2_HH