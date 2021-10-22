#include <controller.h>

#include <chrono>
#include <thread>

Controller::Controller(const Extent2D const *window_extent)
    : pRenderingQueue()
    , pModellingQueue()
    , pRenderer(window_extent, this->pRenderingQueue, this->pModellingQueue)
    , pModel(window_extent, this->pRenderingQueue, this->pModellingQueue)
{}

Controller::~Controller() {}

void Controller::run() {
    while (true) {
        auto t_start = std::chrono::high_resolution_clock::now();
        Model->modelFrame();
        if (Renderer->renderFrame()) {
            break;
        }
        auto t_end = std::chrono::high_resolution_clock::now();
        double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
        std::this_thread::sleep_for(std::chrono::milliseconds(std::chrono::milliseconds(1s) / FPS - elapsed_time_ms));
    }
}
