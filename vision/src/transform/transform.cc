#include "transform.hh"

Transform::Transform(Vector3& _position, Vector3& _rotation) : position(_position), rotation(_rotation) {}

void Transform::translate(Vector3 &t) {
    this->position += t;
}
