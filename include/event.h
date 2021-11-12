#ifndef __EVENT_H__
#define __EVENT_H__

enum class QueueEventType {
    INVALID = 0,
    RENDER_PARTICLE,
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
