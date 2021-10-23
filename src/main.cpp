#include <main.h>

#include <misc.h>

int main() {
    Extent2D window_extent = {WINDOW_EXTENT_X, WINDOW_EXTENT_Y};
    Controller controller(&window_extent);
    controller.run();

    return 0;
}
