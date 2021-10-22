//
// Created by Meevere on 23.10.2021.
//

#ifndef DEFANTCE_CIRCLE_H
#define DEFANTCE_CIRCLE_H

#include "utility/Vector.h"

class Circle {
public:
    float radius;
    Vector2f position;
    Vector2f velocity;

    Circle(float radius,const Vector2f& position);

    void update(float dt);
};


#endif //DEFANTCE_CIRCLE_H
