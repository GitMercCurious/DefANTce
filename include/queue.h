#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <event.h>

#include <functional>
#include <list>

class Queue {
private:
    std::list<QueueEvent *> queue;
public:
    Queue();
    ~Queue();

    /* void poll(void (*callback)(const QueueEvent &)); */
    void poll(std::function<void(const QueueEvent &)>);
    void add(QueueEvent *);
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

class UIEventsQueue : public Queue {
private:
    UIEventsQueue();
public:
    ~UIEventsQueue();
    static UIEventsQueue *getInstance();
};

#endif
