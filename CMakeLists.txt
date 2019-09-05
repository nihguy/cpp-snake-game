cmake_minimum_required(VERSION 3.7)
project(cpp_snake_game)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTS      "Use BUILD_TESTS to compile the project and its test cases as well" OFF) # OFF by default
option(BUILD_TESTS_ONLY "Use BUILD_TESTS_ONLY to compile only the test cases without the project" OFF) # OFF by default

if (BUILD_TESTS OR BUILD_TESTS_ONLY)
    message("Building tests")
    set(BUILD_GMOCK ON)
    add_subdirectory(vendor/googletest)
    add_subdirectory(tests)
endif()

if (NOT BUILD_TESTS_ONLY)
    add_subdirectory(src)
endif()

unset(BUILD_TESTS CACHE)
unset(BUILD_TESTS_ONLY CACHE)
