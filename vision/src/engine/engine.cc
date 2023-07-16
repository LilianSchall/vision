#include <iostream>
#include "engine.hh"

Engine::Engine(std::string title, int width, int height) {

    this->_width = width;
    this->_height = height;

    SDL_Window *_window = SDL_CreateWindow(title.c_str(),
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    width, height,
                                    0);
    SDL_Renderer *_renderer = SDL_CreateRenderer(_window,
                                                -1,
                                                SDL_RENDERER_ACCELERATED);

    this->window = std::unique_ptr<SDL_Window, SDL_WindowDestroyer>(_window);
    this->renderer = std::unique_ptr<SDL_Renderer, SDL_RendererDestroyer>(_renderer);
}

int Engine::run() const {

    SDL_Event event;
    bool running = true;

    while (running) {
        if (SDL_PollEvent(&event)) {
            // we wrap the polling of event in a condition
            // so that we do not send an event to handle
            // that has been already processed
            handle_keyboard_event(&event, &running);
        }
        SDL_SetRenderDrawColor(this->renderer.get(), 0,0,0,0);
        SDL_RenderClear(this->renderer.get());
        SDL_RenderPresent(this->renderer.get());
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 60));
    }

    return 0;
}
