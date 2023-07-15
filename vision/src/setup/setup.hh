#ifndef SETUP_HH
#define SETUP_HH

#include <string>
#include <SDL2/SDL.h>
#include <memory>

#include "tools/sdltools.hh"

class Init {
public:
    Init(std::string title, int width, int height);

public:
    std::unique_ptr<SDL_Window, SDL_WindowDestroyer> window;
    std::unique_ptr<SDL_Renderer, SDL_RendererDestroyer> renderer;
private:
    int _width;
    int _height;
};

#endif // !SETUP_HH
