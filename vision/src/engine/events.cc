#include "events.hh"

void handle_sdl_event(SDL_Event *event, bool *running) {
    switch(event->type) {
        case SDL_QUIT:
            *running = true;
            break;
    }
}
