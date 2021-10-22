//
// Created by Meevere on 23.10.2021.
//

#include "Circle.h"

Circle::Circle(float radius, const Vector2f &position):
radius(radius), position(position) {}

void Circle::update(float dt) {
    position += velocity * dt;
}
