cmake_minimum_required(VERSION 3.7)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package (Threads REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIR})

add_executable(${CMAKE_PROJECT_NAME} main.cc core/controller.hpp core/game.hpp core/game.cc core/renderer.hpp actor/snake.hpp actor/snake.cc core/color.hpp core/color.cc core/vector2.hpp core/vector2.inl core/allocation.hpp core/allocation.inl core/game_state.hpp core/game_object.hpp core/block.cc core/block.hpp states/main_state.cc states/main_state.hpp sdl/renderer.cc sdl/renderer.hpp core/game_loop.hpp sdl/game_loop.cc sdl/game_loop.hpp sdl/controller.cc sdl/controller.hpp core/random_position.cc core/random_position.hpp core/food.cc core/food.hpp core/game_thread.cc core/game_thread.hpp core/font.cc core/font.hpp core/game_font.hpp sdl/typography.cc sdl/typography.hpp sdl/game_font_builder.cc sdl/game_font_builder.hpp sdl/font_maker.cc sdl/font_maker.hpp states/splash_screen_state.cc states/splash_screen_state.hpp core/button_chooser.cc core/button_chooser.hpp states/pause_state.cc states/pause_state.hpp states/game_over_state.cc states/game_over_state.hpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} pthread)

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/resources $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/resources)
