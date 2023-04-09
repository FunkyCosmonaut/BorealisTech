#pragma once
#include "borealistech/core/renderer.hpp"
#include "borealistech/core/camera.hpp"

class Engine {
public:
    Engine();
    ~Engine();
    void Run();

private:
    Camera camera_;
    Renderer renderer_;
};