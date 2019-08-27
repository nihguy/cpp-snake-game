cmake_minimum_required(VERSION 3.7)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${CMAKE_PROJECT_NAME} main.cc core/controller.hpp core/game.hpp core/game.cc core/renderer.hpp actor/snake.hpp actor/snake.cc core/color.hpp core/color.cc core/vector2.hpp core/vector2.inl core/allocation.hpp core/allocation.inl core/game_state.hpp core/game_object.hpp core/block.cc core/block.hpp states/main_state.cc states/main_state.hpp sdl/renderer.cc sdl/renderer.hpp core/game_loop.hpp sdl/game_loop.cc sdl/game_loop.hpp sdl/controller.cc sdl/controller.hpp core/random_position.cc core/random_position.hpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARIES})