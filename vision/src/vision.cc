#include "vision.hh"

int main() {

    int width = 2400;
    int height = 1200;

    std::unique_ptr<Engine> engine = std::make_unique<Engine>("vision", width, height);

    Transform camTransform = Transform{Vector3::zero(), Vector3::zero(), Vector3::zero()};
    Vector2 image_size = Vector2{static_cast<double>(width), static_cast<double>(height)};
    Vector2 viewport = Vector2{4, 2};
    Camera cam = Camera(camTransform, image_size, Vector2::zero(), viewport, 0.5);

    Vector3 spherePos = Vector3{0,0,-1};
    Transform sphereTransform = Transform{spherePos, Vector3::zero(), Vector3::one()};
    Sphere sphere = Sphere{sphereTransform, 0.5};

    engine->add_camera(cam);
    engine->add_object(sphere);
    return engine->run();
}
