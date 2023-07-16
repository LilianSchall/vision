#ifndef SDLTOOLS_HH
#define SDLTOOLS_HH

#include <SDL2/SDL.h>
#include <iostream>

struct SDL_WindowDestroyer {
    void operator()(SDL_Window *window) const;
};

struct SDL_RendererDestroyer {
    void operator()(SDL_Renderer *renderer) const;
};

struct SDL_TextureDestroyer {
    void operator()(SDL_Texture *texture) const;
};

uint32_t map_rgb(uint32_t r, uint32_t g, uint32_t b);

#endif // !SDLTOOLS_HH