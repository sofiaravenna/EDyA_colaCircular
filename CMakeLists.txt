cmake_minimum_required(VERSION 3.21)
project(EDyA_colaCircular C)

set(CMAKE_C_STANDARD 11)

add_executable(EDyA_colaCircular main.c colaCircular.c colaCircular.h)
