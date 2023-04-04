#pragma once
#include "impetus/core/renderer.hpp"
#include "impetus/core/camera.hpp"

class Engine {
public:
    Engine();
    ~Engine();
    void Run();

private:
    Camera camera_;
    Renderer renderer_;
};