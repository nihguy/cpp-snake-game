cmake_minimum_required(VERSION 3.7)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${CMAKE_PROJECT_NAME} main.cc core/controller.hpp core/controller.cc core/game.hpp core/game.cc core/renderer.hpp core/renderer.cc actor/snake.hpp actor/snake.cc core/color.hpp core/color.cc core/vector2.hpp core/vector2.inl core/allocation.hpp core/allocation.inl)
target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARIES})