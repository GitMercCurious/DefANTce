if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  if(NOT DEFINED IN_SOURCE_BUILD)
    message(FATAL_ERROR
        "In-source build aren't allowed. Please, remove \"CMakeCache.txt\" and \"CMakeFiles/\" directory."
        "\n Or define IN_SOURCE_BUILD to force this option (not recommended!)"
    )
  endif()
endif()

cmake_minimum_required(VERSION 3.17)
project(DefANTce)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_compile_options(
  "-Wall;-Wextra;-O2;"
  "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb;-pg>"
)

set(EXEC
    src/main.cpp
    src/renderer.cpp
    src/model.cpp
    src/controller.cpp
    src/queue.cpp
    src/event.cpp
    src/fps_utils.cpp
)

add_executable(DefANTce ${EXEC})

if (WIN32)
    set(SFML_DIR ../SFML-2.5.1/lib/cmake/SFML)
    file(GLOB BINARY_DEP_DLLS "../SFML-2.5.1/bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()

if (DEFINED SFML_LINK_STATIC)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR ${CUSTOM_SFML_DIR})
else()
    if (DEFINED CUSTOM_SFML_DIR)
        message("Custom sfml dir: ${CUSTOM_SFML_DIR}")
        set(SFML_DIR ${CUSTOM_SFML_DIR})
        find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED PATHS CUSTOM_SFML_DIR NO_DEFAULT_PATH)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,${CUSTOM_SFML_DIR}/lib")
    endif()
endif()

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(DefANTce sfml-graphics sfml-audio)
