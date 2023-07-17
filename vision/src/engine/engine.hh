#ifndef ENGINE_HH
#define ENGINE_HH

#include "object/fwd.hh"
#include "render/fwd.hh"
#include "tools/sdltools.hh"

#include <SDL2/SDL.h>
#include <memory>
#include <string>

namespace Engine {
    void init(const std::string &title, int width, int height);
    void add_object(Object &obj);
    void add_camera(Camera &cam);
    int run();
}
#endif // !ENGINE_HH
