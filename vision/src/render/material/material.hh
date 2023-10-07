#ifndef MATERIAL_HH
#define MATERIAL_HH

#include "maths/ray/hit_record.hh"
#include "maths/ray/ray.hh"
#include "render/renderer/renderer.hh"

class Material {
public:
    virtual ~Material() = default;

    virtual bool scatter(Ray& in, Ray& out, HitRecord& record, RgbColor &attenuation) = 0;
};

#endif // !MATERIAL_HH
