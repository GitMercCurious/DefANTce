#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <renderer.h>
#include <model.h>

#include <queue.h>
#include <misc.h>
#include <fps_utils.h>

#include <string>

struct ControllerSettings {
    float fps;
};

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
    UIEventsQueue *pUIEventsQueue;
    /* enf of queues */

    FpsHandler fpsHandler;

    Controller();

    void __convert_events();
public:
    inline static ControllerSettings controllerSettings;
    inline static ModelSettings modelSettings;
    inline static RendererSettings rendererSettings;

    Controller(const Controller &) = delete;
    Controller &operator=(const Controller &) = delete;
    static Controller *getInstance();
    ~Controller();

    void run(); /* main loop will live here */
};

#endif
