#include "camera.hh"

Camera::Camera(Transform &_transform, Vector2 &_image_size, Vector2 &_pos_on_screen, Vector2 &_viewport,
               double _focal_length)
        : Object(_transform), focal_length(_focal_length), pos_on_screen(_pos_on_screen),
          viewport(_viewport),
          buffer(static_cast<int>(_image_size.x), static_cast<int>(_image_size.y)) {

    aspect_ratio = max2<double>(_image_size.x, _image_size.y) / min2<double>(_image_size.x, _image_size.y);
    image_width = static_cast<int>(_image_size.x);
    image_height = static_cast<int>(_image_size.y);

    Engine::add_camera(*this);
}

void Camera::create_texture(SDL_Renderer *renderer) {
    SDL_Texture *_texture = SDL_CreateTexture(renderer,
                                              SDL_PIXELFORMAT_ARGB8888,
                                              SDL_TEXTUREACCESS_STREAMING,
                                              image_width, image_height);

    texture = std::unique_ptr<SDL_Texture, SDL_TextureDestroyer>(_texture);
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

RgbColor Camera::ray_color(const Ray &ray, std::list<Object *> *objs) {
    HitRecord record;
    if (shoot_ray(ray, 0, infinity, record, objs)) {
        return 0.5 * (record.normal + RgbColor{1, 1, 1});
    }

    Vector3 unit_dir = ray.dir;
    unit_dir.normalize();

    double t = 0.5 * (unit_dir.y + 1.0);

    return (1.0 - t) * RgbColor(1.0, 1.0, 1.0) + t * RgbColor(0.5, 0.7, 1.0);
}

void Camera::render(SDL_Renderer *renderer, std::list<Object *> *objs) {

    Vector3 vertical = this->transform.down() * viewport.y;
    Vector3 horizontal = this->transform.right() * viewport.x;
    Vector3 lower_left_corner = this->transform.position - horizontal / 2 - vertical / 2 - Vector3{0, 0, focal_length};

    for (int y = image_height - 1; y >= 0; y--) {
        for (int x = 0; x < image_width; x++) {
            double u = double(x) / (image_width - 1);
            double v = double(y) / (image_height - 1);
            Ray ray = Ray{this->transform.position,
                          lower_left_corner + u * horizontal + v * vertical - this->transform.position};
            RgbColor color = ray_color(ray, objs);
            buffer.put(x, y, color);
        }
    }

    buffer.update_texture(texture.get());
    SDL_Rect pos = this->pos_on_screen.to_sdl_rect(image_width, image_height);
    SDL_RenderCopy(renderer, texture.get(), nullptr, &pos);
}
