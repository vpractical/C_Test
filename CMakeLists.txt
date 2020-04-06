# cmake_minimum_required(VERSION <specify CMake version here>)
project(C_Test C)

set(CMAKE_C_STANDARD 99)

add_executable(C_Test main.c h/login.h login.c)