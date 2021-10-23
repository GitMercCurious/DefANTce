#include <SFML/Graphics.hpp>
#include <iostream>

#include "utility/Event.h"

//class Test : public Event<Test>{};
//
//void Foo(const Event<Test>&){
//    std::cout << "Hey";
//}

#include "controller/App.h"
#include "view/View.h"

int main()
{
    App temp{};
    temp.loop();

//    Test temp;
//    Test::add_event_listener(&Foo);
//    temp.invoke();
    return 0;
}