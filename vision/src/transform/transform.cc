#include "transform.hh"

Transform::Transform(Vector3& _position, Vector3& _rotation, Vector3 &_size)
: position(_position), rotation(_rotation), size(_size){
}

void Transform::translate(Vector3 &t) {
    this->position += t;
}