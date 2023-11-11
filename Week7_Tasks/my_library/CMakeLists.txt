cmake_minimum_required(VERSION 3.0)
project(my_library)

set(CMAKE_CXX_STANDARD 11)

# Define the library
add_library(my_library SHARED my_lib.cpp)

