cmake_minimum_required(VERSION 3.14)

project(myDatastructures)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

# Add the library sources
add_library(my_datastructures INTERFACE)

# Add the header files
target_include_directories(my_datastructures INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Add dependency on my_util
target_link_libraries(my_datastructures INTERFACE my_util)

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

add_executable(heap_test test/heap_test.cc)
target_link_libraries(heap_test GTest::gtest_main my_datastructures)

include(GoogleTest)
gtest_discover_tests(heap_test)
