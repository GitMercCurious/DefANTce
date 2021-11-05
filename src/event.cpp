#include <event.h>

QueueEvent::QueueEvent() {}
QueueEvent::QueueEvent(enum QueueEventType type) : eType(type) {}
QueueEvent::~QueueEvent() {}

enum QueueEventType QueueEvent::getType() const {
    return eType;
}

RenderParticleEvent::RenderParticleEvent()
    : QueueEvent(QueueEventType::RENDER_PARTICLE) {}
RenderParticleEvent::~RenderParticleEvent() {}

AddParticleEvent::AddParticleEvent()
    : QueueEvent(QueueEventType::ADD_PARTICLE) {}
AddParticleEvent::~AddParticleEvent() {}
