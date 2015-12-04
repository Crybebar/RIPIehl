cmake_minimum_required(VERSION 3.3)
project(RIPIehl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -I/Math")

set(SOURCE_FILES main.cpp Math/Mat4.h Math/Vec2.h Math/Vec3.h Math/Vec4.h)
add_executable(RIPIehl ${SOURCE_FILES})