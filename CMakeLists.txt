cmake_minimum_required(VERSION 3.8)
project(cini)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES ini.c ini.h datastructs-c/src/hashtable.c datastructs-c/src/hashtable.h)
add_library(cini ${SOURCE_FILES})

set(EXAMPLE_SOURCE_FILES examples/main.c)
add_executable(cinidemo ${EXAMPLE_SOURCE_FILES})
target_link_libraries(cinidemo cini)
