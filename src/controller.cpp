#include <controller.h>

#include <consts.h>

#include <chrono>
#include <thread>

Controller::Controller() {
    pRenderingQueue = RenderingQueue::getInstance();
    pModelingQueue = ModelingQueue::getInstance();
    
    Renderer::settings = rendererSettings;
    Model::settings = modelSettings;

    Renderer::pRenderingQueue = pRenderingQueue;
    Renderer::pModelingQueue = pModelingQueue;
    Model::pRenderingQueue = pRenderingQueue;
    Model::pModelingQueue = pModelingQueue;

    pRenderer = Renderer::getInstance();
    pModel = Model::getInstance();
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
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(1000.0 / FPS - elapsed_time_ms)));
    }
}
