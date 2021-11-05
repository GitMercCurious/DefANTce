#include <model.h>

#include <queue.h>

#include <cmath>
#include <random>
#include <chrono>

std::default_random_engine r_engine = std::default_random_engine(std::chrono::steady_clock::now().time_since_epoch().count());

Model::Model()
    : system(std::list<Particle>())
{}

Model::~Model() {}

Model *Model::getInstance() {
    static Model model;
    return &model;
}

void Model::modelFrame() {
    /* polling pModelingQueue */
    pModelingQueue->poll([](const QueueEvent &ev) {
        switch (ev.getType()) {
            case QueueEventType::ADD_PARTICLE:
            {
                auto pEvent = dynamic_cast<const AddParticleEvent *>(&ev);
                double angle;
                double r = settings.velocity;
                std::uniform_real_distribution<double> d(0, 2*M_PI);
                angle = d(r_engine);
                Model::getInstance()->system.push_back({{pEvent->x, pEvent->y}, {r * cos(angle), r * sin(angle)}, true});
                break;
            }
            case QueueEventType::INVALID:
                break; /* TODO: handle this case */
            default:
                break;
        }
    });

    for (auto &particle : system) { /* FIXME: try to do everything in 1 pass */
        particle.x += particle.vx / settings.fps;
        particle.y += particle.vy / settings.fps;
        if (particle.x >= 0 && particle.x < settings.extent.x &&
            particle.y >= 0 && particle.y < settings.extent.y) {
            /* adding event to pRenderingQueue */
            auto *pEvent = new RenderParticleEvent();
            pEvent->x = particle.x;
            pEvent->y = particle.y;
            pRenderingQueue->add(pEvent);
        } else {
            /* marking particle as invalid */
            particle.valid = false;
        }
    }

    system.remove_if([](Particle p) {return !(p.valid);});
}
