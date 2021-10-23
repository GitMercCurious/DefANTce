//
// Created by Meevere on 23.10.2021.
//

#ifndef DEFANTCE_FIELD_H
#define DEFANTCE_FIELD_H

#include "model/Circle.h"
#include <vector>

//For Giggles
#include "utility/Event.h"

class Field : public Event<Field> {
private:
    std::vector<Circle> game_objects;
    float sizeX;
    float sizeY;
public:
    Field(float sizeX, float sizeY);

    void update(float dt);
    void add_circle(const Circle& circle);
};


#endif //DEFANTCE_FIELD_H
