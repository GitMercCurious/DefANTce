//
// Created by Meevere on 23.10.2021.
//

#ifndef DEFANTCE_APP_H
#define DEFANTCE_APP_H

#include "model/Field.h"
#include "view/View.h"

#include "utility/Vector.h"

#define RESOLUTION_X 500
#define RESOLUTION_Y 500

#define RESOLUTION Vector2f{RESOLUTION_X, RESOLUTION_Y}

class App {
    Field field;
    View* view;

    App();
    void loop();
};


#endif //DEFANTCE_APP_H
