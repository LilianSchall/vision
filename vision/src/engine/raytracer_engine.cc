#include "raytracer_engine.hh"

RayTracerEngine::RayTracerEngine() : _width(0), _height(0) {}

RayTracerEngine::RayTracerEngine(const std::string &title, int width, int height) {

    this->_width = width;
    this->_height = height;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not SDL_Init. Reason: " << SDL_GetError() << "\n";
        // TODO: Clean exit
    }

    SDL_Window *_window = SDL_CreateWindow(title.c_str(),
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           width, height,
                                           0);

    if (_window == nullptr) {
        std::cerr << "SDL_Window has not been created. Reason: " << SDL_GetError() << "\n";
        // TODO: Clean exit
    }

    SDL_Renderer *_renderer = SDL_CreateRenderer(_window,
                                                 -1,
                                                 SDL_RENDERER_ACCELERATED);

    if (_renderer == nullptr) {
        std::cerr << "SDL_Renderer has not been created. Reason: " << SDL_GetError() << "\n";
        // TODO: Clean exit
    }

    this->window = std::unique_ptr<SDL_Window, SDL_WindowDestroyer>(_window);
    this->renderer = std::unique_ptr<SDL_Renderer, SDL_RendererDestroyer>(_renderer);
}


void RayTracerEngine::add_object(Object &obj) {
    objects.push_back(&obj);
}

void RayTracerEngine::add_camera(Camera &cam) {

    cam.create_texture(this->renderer.get());
    cameras.push_back(&cam);
}


void task_logic(bool *running) {
    SDL_Event event;

    while (*running) {
        if (SDL_PollEvent(&event)) {
            // we wrap the polling of event in a condition
            // so that we do not send an event to handle
            // that has been already processed
            handle_keyboard_event(&event, running);
            handle_sdl_event(&event, running);
        }
#if 0
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/ 60));
#endif
    }
}

void task_render(bool *running, SDL_Renderer *renderer, std::list<Object*> *objects, std::list<Camera*> *cameras) {

    while (*running) {
        // we iterate over all cameras and render its POV
        for (Camera *cam: *cameras) {
            cam->render(renderer, objects);
        }

        // after rendering all POVs from the camera, we present the frame to the user
        SDL_RenderPresent(renderer);
        std::cout << "Rendered frame\n";
    }

}

int RayTracerEngine::run() {

    bool running = true;

    std::jthread thread_logic{task_logic, &running};
    std::jthread thread_render{task_render, &running, renderer.get(), &objects, &cameras};

    thread_logic.join();
    thread_render.join();

    return 0;
}

RayTracerEngine::~RayTracerEngine() {
    SDL_Quit();
    std::cout << "RayTracerEngine has been successfully destroyed. SDL_Quit() triggered.\n";
}
