#include <model.h>

#include <queue.h>

#include <cmath>

Model::Model(const RenderingQueue const *pRenderingQueue,
             const ModellingQueue const *pModellingQueue)
    : pRenderingQueue = pRenderingQueue
    , pModellingQueue = pModellingQueue
    , system = std::list<Particle>()
{}

Model::~Model() {}

void Model::modelFrame() {
    /* polling pModellingQueue */
    pModellingQueue->poll([](const ModellingQueueEvent &ev) {
        switch (ev.eType) {
            case ModellingQueueEventType::INVALID:
                break;
            case ModellingQueueEventType::ADD_PARTICLE:
                double angle;
                double r = 1.0;
                std::uniform_real_distribution<double> d(min, max);
                angle = d(std::default_random_engine(std::chrono::steady_clock::now().time_since_epoch().count()));
                ev.pModel->system.emplace_back(ev.x, ev.y, r * cos(angle), r * sin(angle));
                break;
            default:
                break;
        }
    });

    for (auto &particle : system) { /* FIXME: try to do everything in 1 pass */
        particle->x += particle->vx / FPS;
        particle->y += particle->vy / FPS;
        if (particle->x >= 0 && particle->x < Extent2D->width &&
            particle->y >= 0 && particle->y < Extent2D->height) {
            /* adding event to pRenderingQueue */
            Extent2D *ppos = new Extent2D({particle->x, particle->y});
            pRenderingQueue->add(RenderingQueueEventType::RENDER_PARTICLE, ppos);
        } else {
            /* marking particle as invalid */
            particle->valid = false;
        }
    }

    system.remove_if([](Particle p) {return !(p->valid)});
}
