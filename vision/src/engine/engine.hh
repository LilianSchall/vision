#ifndef SETUP_HH
#define SETUP_HH

#include <chrono>
#include <SDL2/SDL.h>
#include <memory>
#include <string>
#include <list>
#include <thread>

#include "tools/sdltools.hh"
#include "keyboard.hh"
#include "render/camera/camera.hh"

class Engine {
public:
    Engine(const std::string& title, int width, int height);
    ~Engine();
    void add_camera(Camera &cam);
    int run() const;

private:
    std::list<Camera*> cameras;
    std::unique_ptr<SDL_Window, SDL_WindowDestroyer> window;
    std::unique_ptr<SDL_Renderer, SDL_RendererDestroyer> renderer;
    int _width;
    int _height;

};

#endif // !SETUP_HH
