#ifndef FRAMEBUFFER_HH
#define FRAMEBUFFER_HH

#include <memory>
#include <SDL2/SDL.h>

#include "tools/sdltools.hh"
#include "maths/maths.hh"
#include "maths/vector/vector3/vector3.hh"

class FrameBuffer {
public:
    FrameBuffer(int width, int height);

    void put(int x, int y, const RgbColor& color);
    void update_texture(SDL_Texture *texture);


private:
    std::unique_ptr<uint32_t[]> buffer;
    int width;
    int height;
    int pitch;
};

#endif // !FRAMEBUFFER_HH
