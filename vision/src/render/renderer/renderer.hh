#ifndef RENDERER_HH
#define RENDERER_HH

#include "maths/vector/vector3/vector3.hh"

Vector3 lambertian_diffusion(const Vector3 &normal);
Vector3 hemispheral_diffusion(const Vector3 &normal);


#endif // !RENDERER_HH
