//
// Created by Meevere on 23.10.2021.
//

#include "App.h"
#include "view/events/Mouse.h"
#include "view/events/Exit.h"

App::App(): field(RESOLUTION_X, RESOLUTION_Y) {
    view->get_instance(RESOLUTION);
    view->init();
    Field::add_event_listener([this](const Field& e){
        for(auto circle : e.getGameObjects()) {
            this->view->draw_circle(circle.radius, circle.position);
            std::cout << "process\n";
        }
    });
    MouseClick::add_event_listener([this](const MouseClick& e){
        this->field.generate_circle_at(e.position);
    });
    ExitEvent::add_event_listener([this]{this->end();});
}

void App::loop() {
    while(this->is_running){
        view->clear();
        field.update(0.1);
        view->handle_events();
        view->display();
    };
}

void App::end() {
    this->is_running = false;
}
