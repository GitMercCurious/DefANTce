#ifndef __MODEL_H__
#define __MODEL_H__

#include <queue.h>
#include <misc.h>

/* class that will model the system */
class Model {
private:
    RenderingQueue *pRenderingQueue; /* queue where we put what we want to draw */

    ModellingQueue *pModellingQueue; /* queue that tells us what happens outside */

    std::list<Particle> system;

    static Model *pInstance;
public:
    Model(
        RenderingQueue *,
        ModellingQueue *
    );
    ~Model();

    static Model *getInstance();

    void modelFrame(); /* the controller will call this every frame,
                          our task is to update window and poll user events */
};

#endif
