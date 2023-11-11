cmake_minimum_required(VERSION 3.0)
project(my_app)

set(CMAKE_CXX_STANDARD 11)

# Find the library and link against it
find_library(MY_LIBRARY /home/Embedded Linux Diploma/3- Linux/02_Shell Tasks/my_library/build/libmy_library.so)
add_executable(my_app main.cpp)
target_link_libraries(my_app ${MY_LIBRARY})
