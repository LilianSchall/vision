#include "setup.hh"

Init::Init(std::string title, int width, int height) {

    this->_width = width;
    this->_height = height;

    SDL_Window *window = SDL_CreateWindow(title.c_str(),
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    width, height,
                                    0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window,
                                                -1,
                                                SDL_RENDERER_ACCELERATED);

    this->window = std::unique_ptr<SDL_Window, SDL_WindowDestroyer>(window);
    this->renderer = std::unique_ptr<SDL_Renderer, SDL_RendererDestroyer>(renderer);
}
