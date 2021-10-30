#include <model.h>

#include <consts.h>
#include <queue.h>

#include <cmath>
#include <random>
#include <chrono>

std::default_random_engine r_engine = std::default_random_engine(std::chrono::steady_clock::now().time_since_epoch().count());

Model::Model(RenderingQueue *pRenderingQueue,
             ModelingQueue *pModelingQueue)
    : pRenderingQueue(pRenderingQueue)
    , pModelingQueue(pModelingQueue)
    , system(std::list<Particle>())
{}

Model::~Model() {}

Model *Model::setInstance(RenderingQueue *pRenderingQueue, ModelingQueue *pModelingQueue) {
    static Model model(pRenderingQueue, pModelingQueue);
    return &model;
}

Model *Model::getInstance() {
    return setInstance(nullptr, nullptr);
}

void Model::modelFrame() {
    /* polling pModelingQueue */
    pModelingQueue->poll([](const QueueEvent &ev) {
        switch (ev.eType) {
            case QueueEventType::ADD_PARTICLE:
            {
                double angle;
                double r = VEL;
                std::uniform_real_distribution<double> d(0, 2*M_PI);
                angle = d(r_engine);
                Model::getInstance()->system.push_back({{ev.data->x, ev.data->y}, {r * cos(angle), r * sin(angle)}, true});
                break;
            }
            case QueueEventType::INVALID:
                break; /* TODO: handle this case */
            default:
                break;
        }
    });

    for (auto &particle : system) { /* FIXME: try to do everything in 1 pass */
        particle.x += particle.vx / FPS;
        particle.y += particle.vy / FPS;
        if (particle.x >= 0 && particle.x < WINDOW_EXTENT_X &&
            particle.y >= 0 && particle.y < WINDOW_EXTENT_Y) {
            /* adding event to pRenderingQueue */
            auto *pRenderData = new QueueData({particle.x, particle.y});
            pRenderingQueue->add(QueueEventType::RENDER_PARTICLE, pRenderData);
        } else {
            /* marking particle as invalid */
            particle.valid = false;
        }
    }

    system.remove_if([](Particle p) {return !(p.valid);});
}
