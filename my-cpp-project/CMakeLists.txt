cmake_minimum_required(VERSION 3.10)
project(my_cpp_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_subdirectory(tests)

# Add a library target for MyClass and other source files
add_library(my_cpp_project_lib src/MyClass.cpp)

add_executable(my_cpp_project src/main.cpp src/MyClass.cpp)