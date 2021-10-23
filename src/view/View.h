//
// Created by Meevere on 23.10.2021.
//

#ifndef DEFANTCE_VIEW_H
#define DEFANTCE_VIEW_H

#include "utility/Vector.h"
#include <SFML/Graphics.hpp>

// singleton
class View {
private:
    explicit View(Vector2f resolution);

    Vector2f resolution;
    sf::RenderWindow window;
public:
    View(const View&) = delete;
    View& operator=(const View&) = delete;

    static View* get_instance(Vector2f resolution = Vector2f{0.0f,0.0f});
    static View* init();

    static void draw_circle(float radius, const Vector2f& position);
    static void clear();

    static void handle_events();
};

#endif //DEFANTCE_VIEW_H
