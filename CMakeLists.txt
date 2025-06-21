cmake_minimum_required(VERSION 3.10)
project(computer)

set(CMAKE_CXX_STANDARD 17)

add_executable(computer
    src/main.cpp
    src/gates.cpp
    src/adder.cpp
)

target_include_directories(computer PRIVATE ${CMAKE_SOURCE_DIR}/include)
