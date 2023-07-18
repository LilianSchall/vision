#include "camera.hh"

Camera::Camera(Transform &_transform, Vector2 &_image_size, Vector2 &_pos_on_screen, Vector2 &_viewport,
               double _focal_length, int _sample_per_pixel)
        : Object(_transform), sample_per_pixel(_sample_per_pixel), focal_length(_focal_length),
          pos_on_screen(_pos_on_screen), viewport(_viewport),
          buffer(static_cast<int>(_image_size.x), static_cast<int>(_image_size.y)) {

    aspect_ratio = max2<double>(_image_size.x, _image_size.y) / min2<double>(_image_size.x, _image_size.y);
    image_width = static_cast<int>(_image_size.x);
    image_height = static_cast<int>(_image_size.y);
    vertical_viewport = this->transform.down() * viewport.y;
    horizontal_viewport = this->transform.right() * viewport.x;
    lower_left_corner = this->transform.position - horizontal_viewport / 2 - vertical_viewport / 2 - Vector3{0, 0, focal_length};

    Engine::add_camera(*this);
}

void Camera::create_texture(SDL_Renderer *renderer) {
    SDL_Texture *_texture = SDL_CreateTexture(renderer,
                                              SDL_PIXELFORMAT_ARGB8888,
                                              SDL_TEXTUREACCESS_STREAMING,
                                              image_width, image_height);

    if (_texture == nullptr) {
        std::cerr << "SDL_Texture has not been created. Reason: " << SDL_GetError() << "\n";
        // TODO: Clean exit
    }

    texture = std::unique_ptr<SDL_Texture, SDL_TextureDestroyer>(_texture);
}

Ray Camera::generate_ray(double u, double v) {
    Ray ray = Ray{this->transform.position,
                  lower_left_corner + u * horizontal_viewport + v * vertical_viewport - this->transform.position};
    return ray;
}

bool Camera::shoot_ray(const Ray &ray, double t_min, double t_max, HitRecord &record, std::list<Object *> *objs) {
    HitRecord temp_record;
    bool hit_anything = false;
    double closest = t_max;

    for (Object *object: *objs) {
        if (object->hit(ray, t_min, closest, temp_record)) {
            hit_anything = true;
            closest = temp_record.t;
            record = temp_record;
        }
    }

    return hit_anything;
}

RgbColor Camera::ray_color(const Ray &ray, std::list<Object *> *objs, int depth) {
    HitRecord record;

    if (depth <= 0)
        return RgbColor{0,0,0};

    if (shoot_ray(ray, 0.001, infinity, record, objs)) {
        Point3 target = record.p + record.normal + random_in_unit_sphere();
        return 0.5 * ray_color(Ray{record.p, target - record.p}, objs, depth - 1);
    }

    Vector3 unit_dir = ray.dir;
    unit_dir.normalize();

    double t = 0.5 * (unit_dir.y + 1.0);

    return (1.0 - t) * RgbColor(1.0, 1.0, 1.0) + t * RgbColor(0.5, 0.7, 1.0);
}

void Camera::render(SDL_Renderer *renderer, std::list<Object *> *objs) {

    static SDL_Rect pos = this->pos_on_screen.to_sdl_rect(image_width, image_height);
    buffer.init_write_mode(texture.get());
    for (int y = image_height - 1; y >= 0; y--) {
        for (int x = 0; x < image_width; x++) {
            RgbColor color = RgbColor{0,0,0};
            for (int s = 0; s < sample_per_pixel; s++) {
                double u = (random_double() + double(x)) / (image_width - 1);
                double v = (random_double() + double(y)) / (image_height - 1);
                Ray ray = generate_ray(u, v);
                color += ray_color(ray, objs, 50);
            }
            buffer.put(x, y, color, sample_per_pixel);
        }
    }
    buffer.render_texture_on_renderer(renderer, &pos);
}
