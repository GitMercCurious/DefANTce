#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <queue.h>
#include <misc.h>

#include <string>

#include <SFML/Graphics.hpp>

struct RendererSettings {
    std::string app_name;
    Extent2D extent;
    int circle_size;
    Color ball_color;
    Color bg_color;
};

/* class that will convert events
   from the controller to sfml instrucitons and
   sfml window events to the model events */
class Renderer {
private:
    /* sfml stuff */
    sf::RenderWindow window;
    /* end of sfml stuff */

    /*RenderingQueue *pRenderingQueue;*/ /* queue that tells us what we need to draw */

    /*ModelingQueue *pModelingQueue;*/ /* queue where we put events from user */

    Renderer();
public:
    inline static RendererSettings settings;
    inline static RenderingQueue *pRenderingQueue;
    inline static UIEventsQueue *pUIEventsQueue;

    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;
    ~Renderer();

    static Renderer *getInstance();

    int renderFrame(); /* the controller will call this every frame,
                          our task is to update window and poll user events */
};

#endif
