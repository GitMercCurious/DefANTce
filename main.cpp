#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <functional>

#include "controller/App.h"
#include "view/Drawer.h"

//void foo(){
//    std::cout << "Foo" << std::endl;
//}
//
//
//typedef void(*void_func)();

int main()
{
    App temp{};
    temp.loop();
//    std::vector<std::function<void(void)>> f_arr;
//    for(i=0; i<100; ++i){
//        f_arr.emplace_back([i](){
//            std::cout << i << ' ';
//        });
//    }
//    for(i=0; i<100; ++i){
//        f_arr[i]();
//    }
//    return 0;
}