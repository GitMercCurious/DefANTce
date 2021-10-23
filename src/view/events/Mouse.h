//
// Created by Meevere on 23.10.2021.
//

#ifndef DEFANTCE_MOUSE_H
#define DEFANTCE_MOUSE_H

#include "utility/Event.h"
#include "utility/Vector.h"

//class MouseMove: public Event<MouseMove> {
//public:
//    Vector2f position;
//};

class MouseClick: public Event<MouseClick> {
public:
    Vector2f position;
    MouseClick(Vector2f position);
};


#endif //DEFANTCE_MOUSE_H
