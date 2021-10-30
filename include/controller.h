#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <renderer.h>
#include <model.h>

#include <queue.h>
#include <misc.h>

#include <string>

/* class that will be a middleman between renderer and model */
class Controller {
private:
    /* Renderer stuff */
    Renderer *pRenderer;
    /* end of Renderer stuff */

    /* Model stuff */
    Model *pModel;
    /* end of Model stuff */

    /* queues */
    RenderingQueue *pRenderingQueue;
    ModelingQueue *pModelingQueue;
    /* enf of queues */

public:
    inline static ModelSettings modelSettings;
    inline static RendererSettings rendererSettings;

    Controller();
    ~Controller();

    void run(); /* main loop will live here */
};

#endif
