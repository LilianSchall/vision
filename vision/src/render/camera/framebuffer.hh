#ifndef FRAMEBUFFER_HH
#define FRAMEBUFFER_HH

#include <memory>
#include <SDL2/SDL.h>

#include "tools/sdltools.hh"
#include "maths/maths.hh"
#include "maths/vector/vector3/vector3.hh"

class FrameBuffer {
public:
    FrameBuffer(int _width, int _height);

    void init_write_mode(SDL_Texture *_texture);
    void put(int x, int y, RgbColor& color, int sample_per_pixel);
    void render_texture_on_renderer(SDL_Renderer *renderer, SDL_Rect *pos);


private:
    uint32_t *pixels = nullptr;
    SDL_Texture *texture = nullptr;
    int width;
    int height;
    int pitch;
};

#endif // !FRAMEBUFFER_HH
