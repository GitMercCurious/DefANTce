#include <queue.h>

#include <iostream>

Queue::Queue() {}
Queue::~Queue() {
    for (auto pEvent : queue) {
        delete pEvent;
    }

    queue.clear();
}

void Queue::poll(void (*callback)(const QueueEvent &)) {
    for (auto &pEvent : queue) {
        callback(*pEvent);
        delete pEvent;
    }

    queue.clear();
}

void Queue::add(QueueEvent *pEvent) {
    queue.push_back(pEvent);
}

RenderingQueue::RenderingQueue() {}
RenderingQueue::~RenderingQueue() {}

ModelingQueue::ModelingQueue() {}
ModelingQueue::~ModelingQueue() {}

ModelingQueue *ModelingQueue::getInstance() {
    static ModelingQueue modellingQueue;
    return &modellingQueue;
}

RenderingQueue *RenderingQueue::getInstance() {
    static RenderingQueue renderingQueue;
    return &renderingQueue;
}
