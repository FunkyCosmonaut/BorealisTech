#include "borealistech/core/engine.hpp"
#include <iostream>

Engine::Engine()
    : camera_(0.0f, 0.0f, 3.0f, 0.0f, 1.0f, 0.0f, -90.0f, 0.0f),
      renderer_(camera_) {}

Engine::~Engine() {
}

void Engine::Run() {
    if (!renderer_.Initialize()) {
        std::cerr << "Failed to initialize renderer" << std::endl;
        return;
    }

    renderer_.RenderScene();
}