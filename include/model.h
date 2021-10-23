#ifndef __MODEL_H__
#define __MODEL_H__

#include <queue.h>
#include <misc.h>

/* class that will model the system */
class Model {
private:
    RenderingQueue *pRenderingQueue; /* queue where we put what we want to draw */

    ModelingQueue *pModelingQueue; /* queue that tells us what happens outside */

    std::list<Particle> system;

    Model(
        RenderingQueue *,
        ModelingQueue *
    );
public:
    Model(const Model &) = delete;
    Model &operator=(const Model &) = delete;
    ~Model();

    static Model *getInstance();
    static Model *setInstance(
        RenderingQueue *,
        ModelingQueue *
    );

    void modelFrame(); /* the controller will call this every frame,
                          our task is to update window and poll user events */
};

#endif
