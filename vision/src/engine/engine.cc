#include "engine.hh"
#include "raytracer_engine.hh"

namespace Engine {
    namespace {
        std::unique_ptr<RayTracerEngine> engine;
    }

    void init(const std::string &title, int width, int height) {
        engine = std::make_unique<RayTracerEngine>(title, width, height);
    }

    void add_object(Object &obj) {
        engine->add_object(obj);
    }

    void add_camera(Camera &cam) {
        engine->add_camera(cam);
    }

    int run() {
        return engine->run();
    }
}