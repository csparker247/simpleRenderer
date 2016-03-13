project(simpleRenderer)
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_library(SimpleRenderer STATIC simpleRender.h simpleRender.cpp Mesh.h Mesh.cpp)

add_executable(simpleTest main.cpp)
target_link_libraries(simpleTest ${OpenCV_LIBRARIES} SimpleRenderer)
