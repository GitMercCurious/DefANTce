//
// Created by Meevere on 23.10.2021.
//

#include "Drawer.h"
#include "view/events/Exit.h"
#include "view/events/Mouse.h"

Drawer *Drawer::get_instance(Vector2f resolution) {
    static Drawer instance(resolution);
    return &instance;
}

Drawer* Drawer::init(){
    auto view = get_instance();
    view->window.create(sf::VideoMode(view->resolution[0], view->resolution[1]), "Test", sf::Style::Default);
    view->window.setFramerateLimit(60);
    return view;
}

Drawer::Drawer(Vector2f resolution):
resolution(resolution){}

void Drawer::draw_circle(float radius, const Vector2f &position) {
    auto view = get_instance();

    sf::CircleShape shape(radius);
    shape.setPosition(position[0], position[1]);
    shape.setFillColor(sf::Color(100,250,50));
    view->window.draw(shape);
}

void Drawer::clear() {
    auto view = get_instance();
    view->window.clear();
}

void Drawer::handle_events() {
    sf::Event event{};
    auto view = get_instance();
    while (view->window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            ExitEvent().invoke();
        }
        if(event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Left){};
                MouseClick(
                        Vector2f{
                            float(event.mouseButton.x),
                            float(event.mouseButton.y)
                        }).invoke();
        }
    }
}

void Drawer::display() {
    auto drawer = get_instance();
    drawer->window.display();
}
