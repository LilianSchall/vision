#include "renderer.hh"

Vector3 lambertian_diffusion(const Vector3 &normal) {
    return normal + Vector3::random_unit_vector();
}

Vector3 hemispheral_diffusion(const Vector3 &normal) {
    return Vector3::random_in_hemisphere(normal);
}
