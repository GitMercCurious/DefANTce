#include <renderer.h>

#include <consts.h>
#include <queue.h>
#include <model.h>

Renderer::Renderer(Extent2D * pExtent, RenderingQueue * pRenderingQueue,
             ModellingQueue * pModellingQueue)
    : pRenderingQueue(pRenderingQueue)
    , pModellingQueue(pModellingQueue)
    , window(sf::VideoMode(pExtent->width, pExtent->height), APP_NAME)
{
    pInstance = this;
}

Renderer::~Renderer() {}

Renderer *Renderer::getInstance() {
    return pInstance;
}

int Renderer::renderFrame() {
    pRenderingQueue->poll([](const RenderingQueueEvent &ev) {
        sf::CircleShape circle(50.0f);
        switch (ev.eType) {
            case RenderingQueueEventType::rINVALID:
                break;
            case RenderingQueueEventType::rRENDER_PARTICLE:
                circle.setFillColor(sf::Color::Red);
                circle.setPosition(ev.data->x, ev.data->y);
                Renderer::getInstance()->window.draw(circle);
                break;
            default:
                break;
        }
    });

    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                return 1;
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    ModelData *pModelData = new ModelData({(double)event.mouseButton.x, (double)event.mouseButton.y});
                    pModellingQueue->add(ModellingQueueEventType::mADD_PARTICLE, pModelData);
                }
                break;
            default:
                break;
        }
    }

    return 0;
}
