cmake_minimum_required(VERSION 3.14)
project(adventOfCode2022)

# Add each advent of code subdir
add_subdirectory(01_calories)

add_subdirectory(my_util)
add_subdirectory(my_datastructures)


# testing needs to be enabled in every CMakeLists.txt file
enable_testing()
