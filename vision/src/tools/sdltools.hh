#ifndef SDLTOOLS_HH
#define SDLTOOLS_HH

#include <SDL2/SDL.h>

struct SDL_WindowDestroyer {
    void operator()(SDL_Window *window) const;
};

struct SDL_RendererDestroyer {
    void operator()(SDL_Renderer *renderer) const;
};

#endif // !SDLTOOLS_HH