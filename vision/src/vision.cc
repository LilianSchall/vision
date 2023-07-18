#include "vision.hh"

int main() {

    int width = 1600;
    int height = 900;

    Engine::init("vision", width, height);

    Transform camTransform = Transform{Vector3::zero(), Vector3::zero(), Vector3::zero()};
    Vector2 image_size = Vector2{static_cast<double>(width), static_cast<double>(height)};
    Vector2 viewport = Vector2{2.0 * width / height, 2};
    Camera cam = Camera(camTransform, image_size, Vector2::zero(), viewport, 0.5, 8);

    Vector3 spherePos = Vector3{0, 0, -1};
    Transform sphereTransform = Transform{spherePos, Vector3::zero(), Vector3::one()};
    Sphere sphere = Sphere{sphereTransform, 0.5};

    Vector3 planePos = Vector3{0, -100.5, -1};
    Transform planeTransform = Transform{planePos, Vector3::zero(), Vector3::one()};
    Sphere plane = Sphere{planeTransform, 100};

    return Engine::run();
}
