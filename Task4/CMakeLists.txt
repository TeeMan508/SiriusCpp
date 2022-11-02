cmake_minimum_required(VERSION 3.23)
project(Task4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task4 main.cpp load_png/lodepng.h load_png/lodepng.cpp FindMinPath.h FindMinPath.cpp ArgErrorsHandler.h ArgErrorsHandler.cpp)
