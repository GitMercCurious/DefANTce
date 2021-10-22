//
// Created by Meevere on 23.10.2021.
//

#include "View.h"

View *View::get_instance(Vector2f resolution) {
    static View instance(resolution);
    return &instance;
}

View* View::init(){
    auto view = get_instance();
    view->window.create(sf::VideoMode(view->resolution[0], view->resolution[1]), "Test", sf::Style::Default);
    view->window.setFramerateLimit(60);
}

View::View(Vector2f resolution):
resolution(resolution){}

void View::draw_circle(float radius, const Vector2f &position) {
    auto view = get_instance();

    sf::CircleShape shape(radius);
    shape.setPosition(position[0], position[1]);
    shape.setFillColor(sf::Color(100,250,50));
    view->window.draw(shape);
}

void View::clear() {
    auto view = get_instance();
    view->window.clear();
}
