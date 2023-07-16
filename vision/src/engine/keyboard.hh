#ifndef KEYBOARD_HH
#define KEYBOARD_HH

#include <SDL2/SDL.h>

void handle_keyboard_event(SDL_Event *event, bool *is_running);

#endif // !KEYBOARD_HH