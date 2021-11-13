#include <renderer.h>

#include <queue.h>

Renderer::Renderer()
    : window(sf::VideoMode(settings.extent.width, settings.extent.height), settings.app_name)
{}

Renderer::~Renderer() {}

Renderer *Renderer::getInstance() {
    static Renderer renderer;
    return &renderer;
}

sf::Color make_sfml_color(Color color) {
    return sf::Color(color.r, color.g, color.b, color.a);
}

int Renderer::renderFrame() {
    window.clear(make_sfml_color(settings.bg_color));
    pRenderingQueue->poll([this](const QueueEvent &ev) {
        sf::CircleShape circle(settings.circle_size);
        switch (ev.getType()) {
            case QueueEventType::RENDER_PARTICLE:
            {
                auto *pEvent = dynamic_cast<const RenderParticleEvent *>(&ev);
                circle.setFillColor(make_sfml_color(settings.ball_color));
                circle.setPosition(pEvent->x - settings.circle_size, pEvent->y - settings.circle_size);
                window.draw(circle);
                break;
            }
            case QueueEventType::RENDER_MANY_PARTICLES:
            {
                auto *pEvent = dynamic_cast<const RenderManyParticlesEvent *>(&ev);
                for (const auto &particle : (pEvent->particleList)) {
                    sf::CircleShape _circle(settings.circle_size);
                    _circle.setFillColor(make_sfml_color(settings.ball_color));
                    _circle.setPosition(particle.x - settings.circle_size, particle.y - settings.circle_size);
                    window.draw(_circle);
                }
            }
            case QueueEventType::INVALID:
                break; /* TODO: handle this case */
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
                    auto *pEvent = new MouseClickEvent;
                    pEvent->x = (double)event.mouseButton.x;
                    pEvent->y = (double)event.mouseButton.y;
                    pUIEventsQueue->add(pEvent);
                }
                break;
            default:
                break;
        }
    }

    window.display();
    return 0;
}
