#ifndef __EVENT_H__
#define __EVENT_H__

#include <misc.h>
#include <list>

enum class QueueEventType {
    INVALID = 0,
    RENDER_PARTICLE,
    RENDER_MANY_PARTICLES,
    MOUSE_CLICK,
    ADD_PARTICLE,
};

class QueueEvent {
protected:
    QueueEventType eType;
public:
    QueueEvent();
    QueueEvent(QueueEventType);
    virtual ~QueueEvent() = 0;
    QueueEventType getType() const;
};

class RenderParticleEvent : public QueueEvent {
public:
    double x;
    double y;

    RenderParticleEvent();
    ~RenderParticleEvent();
};

class RenderManyParticlesEvent : public QueueEvent {
public:
    std::list<Particle> particleList;

    RenderManyParticlesEvent();
    ~RenderManyParticlesEvent();
};

class MouseClickEvent : public QueueEvent {
public:
    double x;
    double y;

    MouseClickEvent();
    ~MouseClickEvent();
};

class AddParticleEvent : public QueueEvent {
public:
    double x;
    double y;

    AddParticleEvent();
    ~AddParticleEvent();
};

#endif
