#ifndef OBJECT_HH
#define OBJECT_HH

#include "transform/transform.hh"

class Object {
public:
    explicit Object(Transform &_transform);

public:
    Transform transform;
};

#endif // !OBJECT_HH