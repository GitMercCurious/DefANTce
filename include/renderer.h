#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <queue.h>
#include <misc.h>

#include <SFML/Graphics.hpp>

/* class that will convert events
   from the controller to sfml instrucitons and
   sfml window events to the model events */
class Renderer {
private:
    /* sfml stuff */
    sf::RenderWindow window;
    /* end of sfml stuff */

    RenderingQueue *pRenderingQueue; /* queue that tells us what we need to draw */

    ModelingQueue *pModelingQueue; /* queue where we put events from user */

    Renderer(
        const Extent2D *,
        RenderingQueue *,
        ModelingQueue *
    );
public:
    ~Renderer();

    static Renderer *getInstance(); /* FIXME: bad global variable implementation */
    static Renderer *setInstance(
        const Extent2D *,
        RenderingQueue *,
        ModelingQueue *
    );

    int renderFrame(); /* the controller will call this every frame,
                          our task is to update window and poll user events */
};

#endif
