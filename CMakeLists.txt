cmake_minimum_required(VERSION 3.14)
project(cpp_snake_game)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

option(TESTING "Use TESTING to compile the test cases" OFF) # OFF by default
if (TESTING)
    add_subdirectory(tests)
endif()

unset(TESTING CACHE)
