cmake_minimum_required(VERSION 3.7)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${CMAKE_PROJECT_NAME} main.cc controller.hpp controller.cc game.hpp game.cc renderer.hpp renderer.cc snake.hpp snake.cc)
target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARIES})