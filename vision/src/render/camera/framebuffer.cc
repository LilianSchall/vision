#include "framebuffer.hh"

FrameBuffer::FrameBuffer(int _width, int _height) : width(_width), height(_height) {
    buffer = std::unique_ptr<uint32_t[]>(new uint32_t[width * height]);
    pitch = width * sizeof(uint32_t);
}

void FrameBuffer::put(int x, int y, const RgbColor& color) {
    int r = static_cast<int>(255.999 * color.x);
    int g = static_cast<int>(255.999 * color.y);
    int b = static_cast<int>(255.999 * color.z);
    buffer.get()[y * width + x] = map_rgb(r,g,b);
}

void FrameBuffer::update_texture(SDL_Texture *texture) {
    SDL_UpdateTexture(texture, nullptr, buffer.get(), pitch);
}