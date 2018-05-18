cmake_minimum_required(VERSION 3.10)
project(Priority_queue_method)

set(CMAKE_CXX_STANDARD 11)

add_executable(Priority_queue_method main.cpp Graph.cpp Graph.h node.cpp node.h)


set(QMAKE_CXXFLAGS "-std=c++11" -Wall -Werror -pedantic )