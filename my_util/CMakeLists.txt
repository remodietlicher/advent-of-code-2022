cmake_minimum_required(VERSION 3.10)

project(myUtil)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

# Add the library sources
add_library(my_util swap.cc)

# Add the header files
target_include_directories(my_util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(swap_test test/swap_test.cc)
target_link_libraries(swap_test GTest::gtest_main my_util)

include(GoogleTest)
gtest_discover_tests(swap_test)
