#include <controller.h>

#include <consts.h>

#include <chrono>
#include <thread>

Controller::Controller(const Extent2D *window_extent) {
    pRenderingQueue = RenderingQueue::getInstance();
    pModelingQueue = ModelingQueue::getInstance();
    pRenderer = Renderer::setInstance(window_extent, this->pRenderingQueue, this->pModelingQueue);
    pModel = Model::setInstance(this->pRenderingQueue, this->pModelingQueue);
}

Controller::~Controller() {}

void Controller::run() {
    while (true) {
        auto t_start = std::chrono::high_resolution_clock::now();
        pModel->modelFrame();
        if (pRenderer->renderFrame()) {
            break;
        }
        auto t_end = std::chrono::high_resolution_clock::now();
        double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(T_1SEC / FPS - elapsed_time_ms)));
    }
}
