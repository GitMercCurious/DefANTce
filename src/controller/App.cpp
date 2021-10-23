//
// Created by Meevere on 23.10.2021.
//

#include "App.h"

App::App(): field(RESOLUTION_X, RESOLUTION_Y) {
    view->get_instance(RESOLUTION);
    view->init();
}

void App::loop() {

}
