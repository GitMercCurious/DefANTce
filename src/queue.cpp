#include <queue.h>

#include <iostream>

Queue::Queue() {}
Queue::~Queue() {
    for (auto &event : queue) {
        delete event.data;
    }

    queue.clear();
}

void Queue::poll(void (*callback)(const QueueEvent &)) {
    for (auto &event : queue) {
        callback(event);
        delete event.data;
    }

    queue.clear();
}

void Queue::add(QueueEventType type, QueueData *data) {
    queue.push_back({type, data});
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
