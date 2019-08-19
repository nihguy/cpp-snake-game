cmake_minimum_required(VERSION 3.7)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${CMAKE_PROJECT_NAME} main.cpp controller.h controller.cpp game.h game.cpp renderer.h renderer.cpp snake.h snake.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARIES})