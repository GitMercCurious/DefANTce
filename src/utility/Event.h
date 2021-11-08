//
// Created by Meevere on 23.10.2021.
//

#ifndef DEFANTCE_EVENT_H
#define DEFANTCE_EVENT_H

/**
 Example of an EventWrapper class

 class EventWrapper {
// Something that all Events share (but each have it's own)
 private:
    static std::vector<std::function<void(EventWrapper)>*> event_listeners;
 public:
    static add_event_listener(std::function<void(EventWrapper)> func){
        event_listeners.push_front(func);
    }

// Main body
    int property;
    EventWrapper(property);

    void invoke() {
        for(auto& listener : event_listeners){
            (&listener)(*this);
        }
    }
 };
 **/

#include <functional>
#include <vector>

class Event {
    virtual void invoke() = 0;
};

template<typename EventType>
class EventWrapper : Event {
// Something that all Events share (but each have it's own)
private:
    static std::vector<std::function<void(const EventType&)>> event_listeners;
public:
    static void add_event_listener(const std::function<void(const EventType&)>& func){
        event_listeners.push_back(func);
    }

    static void add_event_listener(const std::function<void()>& func){
        event_listeners.push_back([func](const EventType& e){
            func();
        });
    }

    virtual void invoke() final {
        for(auto& listener : event_listeners)
            // Casting EventWrapper<EventType> to EventType
            // It always works cuz there are none standalone EventWrapper<EventType> objects
            listener(*((EventType*)this));
    }
};

template <typename T>
std::vector<std::function<void(const T&)>> EventWrapper<T>::event_listeners{};

#endif //DEFANTCE_EVENT_H
