cmake_minimum_required(VERSION 3.20)
project(DefANTce)

set(CMAKE_CXX_STANDARD 17)

add_executable(DefANTce main.cpp)

if (WIN32)
    set(SFML_DIR ../SFML-2.5.1/lib/cmake/SFML)
endif()

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(DefANTce sfml-graphics sfml-audio)