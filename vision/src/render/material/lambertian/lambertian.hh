#ifndef LAMBERTIAN_HH
#define LAMBERTIAN_HH

#include "render/material/material.hh"

class Lambertian : public Material {
public:
    explicit Lambertian(RgbColor _albedo);
    ~Lambertian() override = default;
    bool scatter(Ray &in, Ray &out, HitRecord &record, RgbColor &attenuation) override;

private:
    RgbColor albedo;
};

#endif // !LAMBERTIAN_HH
