//
// Created by Meevere on 23.10.2021.
//

#include "Circle.h"

Circle::Circle(float radius, const Vector2f &position):
radius(radius), position(position) {}

Circle::Circle(float radius, const Vector2f &position, const Vector2f &velocity):
radius(radius), position(position), velocity(velocity){}

void Circle::update(float dt) {
    position += velocity * dt;
}


