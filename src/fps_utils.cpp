#include <fps_utils.h>

#include <iostream>

FpsHandler::FpsHandler(float fps)
    : state(FpsHandlerState::INVALID)
    , fps(fps)
{}
FpsHandler::~FpsHandler() {}

void FpsHandler::startFrame() {
    start = std::chrono::high_resolution_clock::now();
    state = FpsHandlerState::FRAME_START;
}

void FpsHandler::hang() {
    auto end = std::chrono::high_resolution_clock::now();
    double elapsed_time_ms;
    if (state != FpsHandlerState::FRAME_START) {
        return;
    }
    elapsed_time_ms = std::chrono::duration<double, std::milli>(end - start).count();
    std::this_thread::sleep_for(std::chrono::milliseconds((int)(1000.0 / fps - elapsed_time_ms)));
    std::cerr << elapsed_time_ms << '\n';
}
