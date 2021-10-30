#include <main.h>

#include <controller.h>
#include <consts.h>
#include <misc.h>

int main() {
    Controller::rendererSettings = {
        .app_name = APP_NAME,
        .extent = WINDOW_EXTENT,
        .circle_size = CIRCLE_SIZE,
        .ball_color = BALL_COLOR,
        .bg_color = BG_COLOR,
    };
    Controller::modelSettings = {
        .extent = WINDOW_EXTENT,
        .fps = FPS,
        .velocity = VEL,
    };
    Controller controller;
    controller.run();

    return 0;
}
