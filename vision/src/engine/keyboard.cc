#include "keyboard.hh"

void handle_keydown(SDL_Event *event, bool *is_running);

void handle_keydown(SDL_Event *event, bool *is_running) {
    switch (event->key.keysym.sym) {
        case SDLK_ESCAPE:
            *is_running = false;
    }
}

void handle_keyboard_event(SDL_Event *event, bool *is_running) {
    switch (event->type) {
        case SDL_KEYDOWN:
            handle_keydown(event, is_running);
            break;
    }
}
