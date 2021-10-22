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
    const sf::RenderWindow window;
    /* end of sfml stuff */

    const RenderingQueue *pRenderingQueue; /* queue that tells us what we need to draw */

    const ModellingQueue *pModellingQueue; /* queue where we put events from user */

public:
    Renderer(
        const Extent2D const *,
        const RenderingQueue const *,
        const ModellingQueue const *
    );
    ~Renderer();

    int renderFrame(); /* the controller will call this every frame,
                          our task is to update window and poll user events */
};

#endif
