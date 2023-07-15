#include "sdltools.hh"

void SDL_WindowDestroyer::operator()(SDL_Window *window) const {
    SDL_DestroyWindow(window);
}

void SDL_RendererDestroyer::operator()(SDL_Renderer *renderer) const {
    SDL_DestroyRenderer(renderer);
}
