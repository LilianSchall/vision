#include "framebuffer.hh"

FrameBuffer::FrameBuffer(int _width, int _height) : width(_width), height(_height) {
    pitch = width * sizeof(uint32_t);
}

void FrameBuffer::init_write_mode(SDL_Texture *_texture) {
    texture = _texture;

    // We do this sort of static casting trick because c++
    // doesn't approve an implicit casting of uint32_t* to void*
    // even though technically they're the same size xdddd

    void *casted = (static_cast<void *>(pixels));
    bool error_occurred = SDL_LockTexture(_texture, nullptr, &casted, &pitch) < 0;
     if (error_occurred) {
         std::cerr << SDL_GetError() << ": address of related texture is = " << _texture << "\n";
         // TODO: clean exit
     }
    pixels = static_cast<uint32_t *>(casted);
}

void FrameBuffer::put(int x, int y, RgbColor& color, int sample_per_pixel) {

    double scale = 1.0 / sample_per_pixel;
    color *= scale;

    int r = static_cast<int>(256 * clamp(sqrt(color.x), 0.0, 0.999));
    int g = static_cast<int>(256 * clamp(sqrt(color.y), 0.0, 0.999));
    int b = static_cast<int>(256 * clamp(sqrt(color.z), 0.0, 0.999));

    pixels[y * width + x] = map_rgb(r,g,b);
}

void FrameBuffer::render_texture_on_renderer(SDL_Renderer *renderer, SDL_Rect *pos) {
    SDL_UnlockTexture(texture);
    SDL_RenderCopy(renderer, texture, nullptr, pos);
}
