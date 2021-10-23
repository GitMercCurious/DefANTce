//
// Created by Meevere on 23.10.2021.
//

#ifndef DEFANTCE_EVENT_H
#define DEFANTCE_EVENT_H

/**
 Example of an Event class

 class Event {
// Something that all Events share (but each have it's own)
 private:
    static std::vector<std::function<void(Event)>*> event_listeners;
 public:
    static add_event_listener(std::function<void(Event)> func){
        event_listeners.push_front(func);
    }

// Main body
    int property;
    Event(property);

    void invoke() {
        for(auto& listener : event_listeners){
            (&listener)(*this);
        }
    }
 };
 **/

#include <functional>
#include <vector>

template<typename EventType>
class Event {
// Something that all Events share (but each have it's own)
private:
    static std::vector<std::function<void(Event<EventType>*)>*> event_listeners;
public:
    static void add_event_listener(std::function<void(Event<EventType>*)> func){
        event_listeners.push_front(&func);
    }

    void invoke() {
        for(auto& listener : event_listeners){
            (*listener)(this);
        }
    }
};

#endif //DEFANTCE_EVENT_H
