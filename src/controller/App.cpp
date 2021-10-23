//
// Created by Meevere on 23.10.2021.
//

#include "App.h"
#include "view/events/Mouse.h"

void MouseHandler(const MouseClick& e){

}

App::App(): field(RESOLUTION_X, RESOLUTION_Y) {
    view->get_instance(RESOLUTION);
    view->init();

//    auto []()

    MouseClick::add_event_listener(MouseHandler);
}


void App::loop() {
    while(true){
        view->handle_events();
    };
}
