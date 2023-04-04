#include "impetus/core/renderer.hpp"
#include <iostream>

int main() {
    Camera camera(0.0f, 0.0f, 3.0f, 0.0f, 1.0f, 0.0f, -90.0f, 0.0f);
    Renderer renderer(camera);

    if (!renderer.Initialize()) {
        std::cerr << "Failed to initialize renderer" << std::endl;
        return -1;
    }

    renderer.RenderScene();

    return 0;
}
