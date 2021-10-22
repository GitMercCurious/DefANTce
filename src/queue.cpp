#include <queue.h>

RenderingQueue::RenderingQueue() {}
RenderingQueue::~RenderingQueue() {} /* FIXME: possible leak */

void RenderingQueue::poll(void (*callback)(const RenderingQueueEvent &)) {
    for (auto &event : queue) {
        callback(event);
        delete event.data;
    }

    queue.clear();
}

void RenderingQueue::add(RenderingQueueEventType type, RenderData *data) {
    queue.emplace_back({type, data});
}

ModellingQueue::ModellingQueue() {}
ModellingQueue::~ModellingQueue() {} /* FIXME: possible leak */

void ModellingQueue::poll(void (*callback)(const ModellingQueueEvent &)) {
    for (auto &event : queue) {
        callback(event);
        delete event.data;
    }

    queue.clear();
}

void ModellingQueue::add(ModelingQueueEventType type, ModelData *data) {
    queue.emplace_back({type, data});
}
