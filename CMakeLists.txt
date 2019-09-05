cmake_minimum_required(VERSION 3.7)
project(cpp_snake_game)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTS "Use BUILD_TESTS to compile the test cases" OFF) # OFF by default
if (BUILD_TESTS)
    message("Building tests")
    set(BUILD_GMOCK ON)
    add_subdirectory(vendor/googletest)
    add_subdirectory(tests)
endif()

add_subdirectory(src)
unset(BUILD_TESTS CACHE)
