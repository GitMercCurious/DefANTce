#include <model.h>

#include <consts.h>
#include <queue.h>

#include <cmath>
#include <random>
#include <chrono>

std::default_random_engine r_engine = std::default_random_engine(std::chrono::steady_clock::now().time_since_epoch().count());

Model::Model(RenderingQueue *pRenderingQueue,
             ModellingQueue *pModellingQueue)
    : pRenderingQueue(pRenderingQueue)
    , pModellingQueue(pModellingQueue)
    , system(std::list<Particle>())
{
    pInstance = this;
}

Model::~Model() {}

Model *Model::getInstance() {
    return pInstance;
}

void Model::modelFrame() {
    /* polling pModellingQueue */
    pModellingQueue->poll([](const ModellingQueueEvent &ev) {
        switch (ev.eType) {
            case ModellingQueueEventType::mINVALID:
                break;
            case ModellingQueueEventType::mADD_PARTICLE:
            {
                double angle;
                double r = 1.0;
                std::uniform_real_distribution<double> d(0, 2*M_PI);
                angle = d(r_engine);
                Model::getInstance()->system.emplace_back({ev.data->x, ev.data->y}, {r * cos(angle), r * sin(angle)});
                break;
            }
            default:
                break;
        }
    });

    for (auto &particle : system) { /* FIXME: try to do everything in 1 pass */
        particle.x += particle.vx / FPS;
        particle.y += particle.vy / FPS;
        if (particle.x >= 0 && particle.x < WINDOW_EXTENT.width &&
            particle.y >= 0 && particle.y < WINDOW_EXTENT.height) {
            /* adding event to pRenderingQueue */
            RenderData *pRenderData = new RenderData({particle.x, particle.y});
            pRenderingQueue->add(RenderingQueueEventType::rRENDER_PARTICLE, pRenderData);
        } else {
            /* marking particle as invalid */
            particle.valid = false;
        }
    }

    system.remove_if([](Particle p) {return !(p.valid);});
}
