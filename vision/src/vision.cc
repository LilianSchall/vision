#include "vision.hh"

int main() {

    std::unique_ptr<Engine> engine = std::make_unique<Engine>("vision", 680, 420);

    return engine->run();
}
