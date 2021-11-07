#ifndef __MODEL_H__
#define __MODEL_H__

#include <queue.h>
#include <misc.h>

struct ModelSettings {
    Extent2D extent;
    float fps;
    float velocity;
};

/* class that will model the system */
class Model {
private:
    /*RenderingQueue *pRenderingQueue;*/ /* queue where we put what we want to draw */

    /*ModelingQueue *pModelingQueue;*/ /* queue that tells us what happens outside */

    std::list<Particle> system;

    Model();
public:
    inline static ModelSettings settings;
    inline static RenderingQueue *pRenderingQueue;
    inline static ModelingQueue *pModelingQueue;

    Model(const Model &) = delete;
    Model &operator=(const Model &) = delete;
    ~Model();

    static Model *getInstance();

    void modelFrame(); /* the controller will call this every frame,
                          our task is to update window and poll user events */
};

#endif
