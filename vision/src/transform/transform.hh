#ifndef TRANSFORM_HH
#define TRANSFORM_HH

#include "maths/maths.hh"

class Transform {

public:
    Transform(Vector3 &_position, Vector3 &_rotation);
    void translate(Vector3& t);

    Vector3 position;
    Vector3 rotation;
};

#endif // !TRANSFORM_HH