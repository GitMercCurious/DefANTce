//
// Created by Meevere on 23.10.2021.
//

#include "Field.h"

Field::Field(float sizeX, float sizeY):
sizeX(sizeX), sizeY(sizeY), game_objects(){}

void Field::update(float dt) {
    for(auto& object_ : game_objects){
        auto object = &object_;
        object->update(dt);
        if( object->position[0] < 0 ) {
            object->position[0] = -object->position[0];
            object->velocity[0] = -object->velocity[0];
        }
        if( object->position[1] < 0 ) {
            object->position[1] = -object->position[1];
            object->velocity[1] = -object->velocity[1];
        }

        if( object->position[0] > sizeX ){
            object->position[0] = 2*sizeX - object->position[0];
            object->velocity[0] = -object->velocity[0];
        }
        if( object->position[1] > sizeY ){
            object->position[1] = 2*sizeY - object->position[1];
            object->velocity[1] = -object->velocity[1];
        }
    }
    // Model got updated;
    invoke();
}

void Field::add_circle(const Circle& circle) {
    game_objects.push_back(circle);
}

void Field::generate_circle_at(Vector2f position) {
    Vector2f velocity{
        float(rand() % 100 - 50), float(rand() % 100 - 50)
    };
    Circle circle{float(rand() % 10 + 5), position, velocity};
    this->game_objects.push_back(circle);
    std::cout << "generated";
}

const std::vector<Circle> &Field::getGameObjects() const {
    return game_objects;
}
