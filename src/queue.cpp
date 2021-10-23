#include <queue.h>

#include <iostream>

RenderingQueue::RenderingQueue() {}
RenderingQueue::~RenderingQueue() {} /* FIXME: possible leak */

RenderingQueue *RenderingQueue::getInstance() {
    static RenderingQueue renderingQueue;
    return &renderingQueue;
}

void RenderingQueue::poll(void (*callback)(const RenderingQueueEvent &)) {
    for (auto &event : queue) {
        callback(event);
        delete event.data;
    }

    queue.clear();
}

void RenderingQueue::add(RenderingQueueEventType type, RenderData *data) {
    queue.push_back({type, data});
}

ModelingQueue::ModelingQueue() {}
ModelingQueue::~ModelingQueue() {} /* FIXME: possible leak */

ModelingQueue *ModelingQueue::getInstance() {
    static ModelingQueue modellingQueue;
    return &modellingQueue;
}

void ModelingQueue::poll(void (*callback)(const ModelingQueueEvent &)) {
    for (auto &event : queue) {
        callback(event);
        delete event.data;
    }

    queue.clear();
}

void ModelingQueue::add(ModelingQueueEventType type, ModelData *data) {
    queue.push_back({type, data});
}
