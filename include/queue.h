#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <list>

enum RenderingQueueEventType {
    rINVALID = 0,
    rRENDER_PARTICLE,
};

enum ModelingQueueEventType {
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

struct ModelingQueueEvent {
    enum ModelingQueueEventType eType;
    ModelData *data;
};

class RenderingQueue {
private:
    std::list<RenderingQueueEvent> queue;
    RenderingQueue();
public:
    ~RenderingQueue();

    static RenderingQueue *getInstance();

    void poll(void (*callback)(const RenderingQueueEvent &));
    void add(RenderingQueueEventType, RenderData *);
};

class ModelingQueue {
private:
    std::list<ModelingQueueEvent> queue;
    ModelingQueue();
public:
    ~ModelingQueue();

    static ModelingQueue *getInstance();

    void poll(void (*callback)(const ModelingQueueEvent &));
    void add(ModelingQueueEventType, ModelData *);
};

#endif
