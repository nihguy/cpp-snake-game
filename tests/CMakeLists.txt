cmake_minimum_required(VERSION 3.7)
project(cpp_snake_game_tests)

include_directories(../ ../vendor/googletest/googletest/include ../vendor/googletest/googlemock/include)

add_executable(order order.cc core/allocation_test.cc ../src/core/allocation.hpp ../src/core/allocation.inl ../src/core/color.hpp ../src/core/color.cc ../src/core/vector2.hpp ../src/core/vector2.inl)

target_link_libraries(order gmock gtest)
