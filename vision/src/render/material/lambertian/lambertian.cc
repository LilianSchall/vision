#include "lambertian.hh"

Lambertian::Lambertian(RgbColor _albedo) : albedo(_albedo) {}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

bool Lambertian::scatter(Ray &in, Ray &out, HitRecord &record, RgbColor &attenuation) {

    Vector3 dir = lambertian_diffusion(record.normal);
    out = Ray{record.p, dir};
    attenuation = albedo;

    return true;
}

#pragma GCC diagnostic pop