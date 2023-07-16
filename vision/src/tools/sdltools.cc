#include "sdltools.hh"

void SDL_WindowDestroyer::operator()(SDL_Window *window) const {
    SDL_DestroyWindow(window);
    std::cout << "SDL_Window has been successfully destroyed.\n";
}

void SDL_RendererDestroyer::operator()(SDL_Renderer *renderer) const {
    SDL_DestroyRenderer(renderer);
    std::cout << "SDL_Renderer has been successfully destroyed.\n";
}

void SDL_TextureDestroyer::operator()(SDL_Texture *texture) const {
    SDL_DestroyTexture(texture);
    std::cout << "SDL_Texture has been successfully destroyed.\n";
}

uint32_t map_rgb(uint32_t r, uint32_t g, uint32_t b) {
    return 0xFF000000 | (r << 16) | (g << 8) | b;
}
