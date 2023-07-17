#ifndef CAMERA_HH
#define CAMERA_HH

#include <list>
#include <memory>
#include <SDL2/SDL.h>

#include "object/object.hh"
#include "maths/maths.hh"
#include "maths/vector/vector2/vector2.hh"
#include "maths/ray/ray.hh"
#include "tools/sdltools.hh"
#include "framebuffer.hh"
#include "engine/engine.hh"

class Camera : public Object {
public:
    // Camera(Transform &_transform);
    Camera(Transform &_transform, Vector2 &_image_size, Vector2 &_pos_on_screen, Vector2 &_viewport,
           double _focal_length);
    void create_texture(SDL_Renderer *renderer);
    void render(SDL_Renderer *renderer, std::list<Object *> *objs);
    bool shoot_ray(const Ray &ray, double t_min, double t_max, HitRecord &record, std::list<Object *> *objs);

private:
    RgbColor ray_color(const Ray &ray, std::list<Object *> *objs);

private:
    int image_width;
    int image_height;

    double aspect_ratio;
    double focal_length;

    Vector2 pos_on_screen;
    Vector2 viewport;


    FrameBuffer buffer;
    std::unique_ptr<SDL_Texture, SDL_TextureDestroyer> texture;
};

#endif // !CAMERA_HH
