#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <list>

enum QueueEventType {
    INVALID = 0,
    RENDER_PARTICLE,
    ADD_PARTICLE,
};

struct QueueData {
    double x;
    double y;
};

struct QueueEvent {
    enum QueueEventType eType;
    QueueData *data;
};

class Queue {
private:
    std::list<QueueEvent> queue;
public:
    Queue();
    ~Queue();

    void poll(void (*callback)(const QueueEvent &));
    void add(QueueEventType, QueueData *);
};

class RenderingQueue : public Queue {
private:
    RenderingQueue();
public:
    ~RenderingQueue();
    static RenderingQueue *getInstance();
};

class ModelingQueue : public Queue {
private:
    ModelingQueue();
public:
    ~ModelingQueue();
    static ModelingQueue *getInstance();
};

#endif
