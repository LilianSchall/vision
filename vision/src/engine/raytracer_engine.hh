#ifndef RAYTRACER_ENGINE_HH
#define RAYTRACER_ENGINE_HH

#include "events.hh"
#include "keyboard.hh"
#include "object/object.hh"
#include "render/camera/camera.hh"
#include "tools/sdltools.hh"

#include <SDL2/SDL.h>
#include <chrono>
#include <list>
#include <memory>
#include <string>
#include <thread>

class RayTracerEngine {
public:
    RayTracerEngine();
    RayTracerEngine(const std::string& title, int width, int height);
    ~RayTracerEngine();
    void add_object(Object &obj);
    void add_camera(Camera &cam);
    int run();

private:
    std::list<Camera*> cameras;
    std::list<Object*> objects;
    std::unique_ptr<SDL_Window, SDL_WindowDestroyer> window;
    std::unique_ptr<SDL_Renderer, SDL_RendererDestroyer> renderer;
    int _width;
    int _height;

};

#endif // !RAYTRACER_ENGINE_HH
