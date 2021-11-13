#include <event.h>

QueueEvent::QueueEvent() {}
QueueEvent::QueueEvent(QueueEventType type) : eType(type) {}
QueueEvent::~QueueEvent() {}

QueueEventType QueueEvent::getType() const {
    return eType;
}

RenderParticleEvent::RenderParticleEvent()
    : QueueEvent(QueueEventType::RENDER_PARTICLE) {}
RenderParticleEvent::~RenderParticleEvent() {}

RenderManyParticlesEvent::RenderManyParticlesEvent()
    : QueueEvent(QueueEventType::RENDER_MANY_PARTICLES) {}
RenderManyParticlesEvent::~RenderManyParticlesEvent() {}

MouseClickEvent::MouseClickEvent()
    : QueueEvent(QueueEventType::MOUSE_CLICK) {}
MouseClickEvent::~MouseClickEvent() {}

AddParticleEvent::AddParticleEvent()
    : QueueEvent(QueueEventType::ADD_PARTICLE) {}
AddParticleEvent::~AddParticleEvent() {}
