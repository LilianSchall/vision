#ifndef TRANSFORM_HH
#define TRANSFORM_HH

#include "maths/vector/vector3/vector3.hh"

class Transform {

public:
    Transform(Vector3 &_position, Vector3 &_rotation, Vector3 &_size);
    void translate(Vector3& t);

    inline Vector3 up() {
        return _up;
    }

    inline Vector3 down() {
        return _down;
    }

    inline Vector3 left() {
        return _left;
    }

    inline Vector3 right() {
        return _right;
    }

    inline Vector3 forward() {
        return _forward;
    }

    inline Vector3 backward() {
        return _backward;
    }


public:
    Vector3 position;
    Vector3 rotation;
    Vector3 size;

private:
    Vector3 _up = Vector3(0, 1, 0);
    Vector3 _down = Vector3(0, -1, 0);
    Vector3 _left = Vector3(-1, 0, 0);
    Vector3 _right = Vector3(1, 0, 0);
    Vector3 _forward = Vector3(0, 0, 1);
    Vector3 _backward = Vector3(0, 0, -1);
};

#endif // !TRANSFORM_HH