cmake_minimum_required(VERSION 2.8.4)
project(words)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -Werror")

set(SOURCE_FILES main.c dyn_str.c)
add_executable(words ${SOURCE_FILES})