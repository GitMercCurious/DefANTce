#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <list>

enum RenderingQueueEventType {
    rINVALID = 0,
    rRENDER_PARTICLE,
};

enum ModellingQueueEventType {
    mINVALID = 0,
    mADD_PARTICLE,
};

struct RenderData {
    double x;
    double y;
};

struct ModelData {
    double x;
    double y;
};

struct RenderingQueueEvent {
    enum RenderingQueueEventType eType;
    RenderData *data;
};

struct ModellingQueueEvent {
    enum ModellingQueueEventType eType;
    ModelData *data;
};

class RenderingQueue {
private:
    std::list<RenderingQueueEvent> queue;
public:
    RenderingQueue();
    ~RenderingQueue();

    void poll(void (*callback)(const RenderingQueueEvent &));
    void add(RenderingQueueEventType, RenderData *);
};

class ModellingQueue {
private:
    std::list<ModellingQueueEvent> queue;
public:
    ModellingQueue();
    ~ModellingQueue();

    void poll(void (*callback)(const ModellingQueueEvent &));
    void add(ModellingQueueEventType, ModelData *);
};

#endif
