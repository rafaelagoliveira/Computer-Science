cmake_minimum_required(VERSION 3.23)
project(circunferencia2d)

set(CMAKE_CXX_STANDARD 14)

add_executable(circunferencia2d main.cpp Circunference.h circunference.cpp Point.h point.cpp)
