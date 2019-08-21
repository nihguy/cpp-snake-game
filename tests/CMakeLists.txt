###################################################
# Testing
###################################################

# Download and unpack googletest at configure time
include(${PROJECT_SOURCE_DIR}/cmake/gtest.cmake)
enable_testing()
include(GoogleTest)

# Add executable and link library
function(create_test PROJECT_TEST_NAME TEST_CASES_FILES)
    message(STATUS "Adding target ${PROJECT_TEST_NAME} for test cases: ${TEST_CASES_FILES}" )

    add_executable(${PROJECT_TEST_NAME} ${TEST_CASES_FILES})

    target_link_libraries(${PROJECT_TEST_NAME} gtest gtest_main)
    target_include_directories(${PROJECT_TEST_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
    target_include_directories(${PROJECT_TEST_NAME} PUBLIC ${GTEST_INCLUDE_DIRS})

    gtest_add_tests(
            TARGET      ${PROJECT_TEST_NAME}
            TEST_LIST   ${PROJECT_TEST_NAME}_targets
    )
endfunction()

# Run test with all files from src folder except main.cc
function(run_test)
    set(FILES gtest.cc
              # Color test
              ../src/core/color.hpp ../src/core/color.cc core/color_test.cc

              # Vector2
              ../src/core/vector2.hpp ../src/core/vector2.inl core/vector2_test.cc

              # Allocation
              ../src/core/allocation.hpp ../src/core/allocation.inl core/allocation_test.cc)

    create_test(test "${FILES}")

    unset(FILES CACHE)
endfunction()

run_test()
