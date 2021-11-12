#ifndef __FPS_UTILS_H__
#define __FPS_UTILS_H__

#include <chrono>
#include <thread>

enum class FpsHandlerState {
    INVALID = 0,
    FRAME_START,
    FRAME_END,
};

class FpsHandler {
private:
    float fps;
    FpsHandlerState state;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    FpsHandler(float fps);
    ~FpsHandler();

    void startFrame();
    void hang();
};

#endif
