#include "vision.hh"

int main() {

    int width = 2400;
    int height = 1200;

    std::unique_ptr<Engine> engine = std::make_unique<Engine>("vision", width, height);
    Transform camTransform = Transform{Vector3::zero(), Vector3::zero(), Vector3::zero()};
    Vector2 image_size = Vector2{static_cast<double>(width), static_cast<double>(height)};
    Vector2 viewport = Vector2{4, 2};
    std::unique_ptr<Camera> cam = std::make_unique<Camera>(camTransform, image_size, Vector2::zero(), viewport, 0.5);

    engine->add_camera(*cam);
    return engine->run();
}
