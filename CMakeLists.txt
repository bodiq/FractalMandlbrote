cmake_minimum_required(VERSION 3.17)
project(Fractal)

set(CMAKE_CXX_STANDARD 17)

add_executable(Fractal main.cpp BitMap.cpp Mandlbrote.cpp Mandlbrote.h Zoom.h ZoomList.cpp ZoomList.h)