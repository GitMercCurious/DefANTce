#ifndef __EVENT_H__
#define __EVENT_H__

enum QueueEventType {
    INVALID = 0,
    RENDER_PARTICLE,
    ADD_PARTICLE,
};

class QueueEvent {
protected:
    enum QueueEventType eType;
public:
    QueueEvent();
    QueueEvent(enum QueueEventType);
    virtual ~QueueEvent() = 0;
    enum QueueEventType getType() const;
};

class RenderParticleEvent : public QueueEvent {
public:
    double x;
    double y;

    RenderParticleEvent();
    ~RenderParticleEvent();
};

class AddParticleEvent : public QueueEvent {
public:
    double x;
    double y;

    AddParticleEvent();
    ~AddParticleEvent();
};

#endif
