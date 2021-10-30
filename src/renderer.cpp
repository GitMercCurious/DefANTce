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
    pRenderingQueue->poll([](const QueueEvent &ev) {
        sf::CircleShape circle(settings.circle_size);
        switch (ev.eType) {
            case QueueEventType::RENDER_PARTICLE:
                circle.setFillColor(make_sfml_color(settings.ball_color));
                circle.setPosition(ev.data->x - settings.circle_size, ev.data->y - settings.circle_size);
                Renderer::getInstance()->window.draw(circle);
                break;
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
                    auto *pModelData = new QueueData({(double)event.mouseButton.x, (double)event.mouseButton.y});
                    pModelingQueue->add(QueueEventType::ADD_PARTICLE, pModelData);
                }
                break;
            default:
                break;
        }
    }

    window.display();
    return 0;
}
