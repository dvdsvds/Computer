cmake_minimum_required(VERSION 3.20)
project(ComputerSim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(Computer
    src/lg.cpp
    src/circuit.cpp
    src/main.cpp
)
