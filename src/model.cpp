#include <model.h>

#include <queue.h>

#include <cmath>

Model::Model(const RenderingQueue const *pRenderingQueue,
             const ModellingQueue const *pModellingQueue)
    : pRenderingQueue = pRenderingQueue
    , pModellingQueue = pModellingQueue
    , system = std::list<Particle>()
    , pInstance = this
{}

Model::~Model() {}

static Model *Model::getInstance() {
    return pInstance;
}

void Model::modelFrame() {
    /* polling pModellingQueue */
    pModellingQueue->poll([system](const ModellingQueue &ev) {
        switch (ev.eType) {
            case ModellingQueueEventType::mINVALID:
                break;
            case ModellingQueueEventType::mADD_PARTICLE:
                double angle;
                double r = 1.0;
                RenderData *data = (RenderData *)ev->data;
                std::uniform_real_distribution<double> d(min, max);
                angle = d(std::default_random_engine(std::chrono::steady_clock::now().time_since_epoch().count()));
                system.emplace_back(data->x, data->y, r * cos(angle), r * sin(angle));
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
            RenderData *pRenderData = new RenderData({particle->x, particle->y});
            pRenderingQueue->add(RenderingQueueEventType::rRENDER_PARTICLE, pRenderData);
        } else {
            /* marking particle as invalid */
            particle->valid = false;
        }
    }

    system.remove_if([](Particle p) {return !(p->valid)});
}
