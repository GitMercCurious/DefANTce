cmake_minimum_required(VERSION 3.16)
project(DefANTce)

set(CMAKE_CXX_STANDARD 17)

add_executable(DefANTce main.cpp
        src/model/Circle.cpp
        src/model/Circle.h
        src/utility/Vector.h
        src/view/View.cpp
        src/view/View.h
        src/model/Field.cpp
        src/model/Field.h src/utility/Event.h src/view/events/Mouse.h src/controller/App.cpp src/controller/App.h src/view/events/Exit.h src/view/events/Mouse.cpp)

if (WIN32)
    set(SFML_DIR ../SFML-2.5.1/lib/cmake/SFML)
    file(GLOB BINARY_DEP_DLLS "../SFML-2.5.1/bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(DefANTce sfml-graphics sfml-audio)

include_directories(src)