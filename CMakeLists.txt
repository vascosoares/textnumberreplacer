cmake_minimum_required(VERSION 3.22)
project(NumbersParser)

set(CMAKE_CXX_STANDARD 17)
set(ENABLE_TESTING TRUE)

add_executable(NumbersParser main.cpp parser.h tests.h)
