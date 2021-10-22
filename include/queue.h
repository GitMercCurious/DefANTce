#ifndef __QUEUE_H__
#define __QUEUE_H__

enum RenderingQueueEventType {
    INVALID = 0,
    RENDER_PARTICLE,
};

enum ModellingQueueEventType {
    INVALID = 0,
    ADD_PARTICLE,
};

struct RenderingQueueEvent {
    enum RenderingQueueEventType eType;
    void *data; /* TODO: make a wrapper cast with proper casts */
};

struct ModellingQueueEvent {
    enum ModellingQueueEventType eType;
    void *data; /* TODO: make a wrapper cast with proper casts */
};

class RenderingQueue {
    RenderingQueue();
    ~RenderingQueue();

    void poll(void (*callback)(const RenderingQueueEvent &));
    void add(RenderingQueueEventType, void *);
};

class ModellingQueue {
    ModellingQueue();
    ~ModellingQueue();

    void poll(void (*callback)(const ModellingQueueEvent &));
    void add(ModellingQueueEventType, void *);
};

#endif
