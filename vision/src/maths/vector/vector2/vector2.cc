#include "vector2.hh"

Vector2::Vector2(double _x, double _y) : x(_x), y(_y) {}

Vector &Vector2::operator+=(const Vector &other) {
    const auto& casted = dynamic_cast<const Vector2&>(other);

    this->x += casted.x;
    this->y += casted.y;

    return *this;
}

Vector &Vector2::operator-=(const Vector &other) {
    const auto& casted = dynamic_cast<const Vector2&>(other);

    this->x += casted.x;
    this->y += casted.y;

    return *this;
}

Vector &Vector2::operator*=(double other) {
    this->x *= other;
    this->y *= other;

    return *this;
}

Vector &Vector2::operator/=(double other) {
    this->x /= other;
    this->y /= other;

    return *this;
}

double Vector2::norm() {
    return sqrt(norm2());
}

double Vector2::norm2() {
    return x * x + y * y;
}

Vector2& Vector2::zero() {
    static Vector2 zero = Vector2(0, 0);

    return zero;
}

SDL_Rect Vector2::to_sdl_rect(int width, int height) {
    return SDL_Rect{static_cast<int>(x), static_cast<int>(y),width,height};
}