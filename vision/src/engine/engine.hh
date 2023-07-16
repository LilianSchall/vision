#ifndef SETUP_HH
#define SETUP_HH

#include <chrono>
#include <SDL2/SDL.h>
#include <memory>
#include <string>
#include <thread>

#include "tools/sdltools.hh"
#include "keyboard.hh"

class Engine {
public:
    Engine(std::string title, int width, int height);
    int run() const;

public:
    std::unique_ptr<SDL_Window, SDL_WindowDestroyer> window;
    std::unique_ptr<SDL_Renderer, SDL_RendererDestroyer> renderer;
private:
    int _width;
    int _height;
};

#endif // !SETUP_HH
