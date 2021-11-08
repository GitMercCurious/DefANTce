//
// Created by Meevere on 23.10.2021.
//

#ifndef DEFANTCE_DRAWER_H
#define DEFANTCE_DRAWER_H

#include "utility/Vector.h"
#include <SFML/Graphics.hpp>

// singleton
class Drawer {
private:
//public:
    explicit Drawer(Vector2f resolution);

    Vector2f resolution;
    sf::RenderWindow window;
public:
    Drawer(const Drawer&) = delete;
    Drawer& operator=(const Drawer&) = delete;

    static Drawer* get_instance(Vector2f resolution = Vector2f{0.0f, 0.0f});
    static Drawer* init();

    static void draw_circle(float radius, const Vector2f& position);
//    static void draw_sprite(const Sprite& sprite, const Vector2f& position);
    static void display();
    static void clear();

    static void handle_events();
};


#endif //DEFANTCE_DRAWER_H
