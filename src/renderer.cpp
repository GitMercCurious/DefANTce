#include <renderer.h>

#include <consts.h>
#include <queue.h>
#include <model.h>

Renderer::Renderer(const Extent2D * pExtent, RenderingQueue * pRenderingQueue,
             ModelingQueue * pModelingQueue)
    : pRenderingQueue(pRenderingQueue)
    , pModelingQueue(pModelingQueue)
    , window(sf::VideoMode(pExtent->width, pExtent->height), APP_NAME)
{}

Renderer::~Renderer() {}

Renderer *Renderer::setInstance(const Extent2D * pExtent, RenderingQueue * pRenderingQueue,
             ModelingQueue * pModelingQueue) {
    static Renderer renderer(pExtent, pRenderingQueue, pModelingQueue);
    return &renderer;
}

Renderer *Renderer::getInstance() {
    return setInstance(nullptr, nullptr, nullptr);
}

int Renderer::renderFrame() {
    window.clear(sf::Color::Green);
    pRenderingQueue->poll([](const RenderingQueueEvent &ev) {
        sf::CircleShape circle(SIRCLE_SIZE);
        switch (ev.eType) {
            case RenderingQueueEventType::rINVALID:
                break;
            case RenderingQueueEventType::rRENDER_PARTICLE:
                circle.setFillColor(sf::Color::Red);
                circle.setPosition(ev.data->x - SIRCLE_SIZE, ev.data->y - SIRCLE_SIZE);
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
                    pModelingQueue->add(ModelingQueueEventType::mADD_PARTICLE, pModelData);
                }
                break;
            default:
                break;
        }
    }

    window.display();
    return 0;
}
