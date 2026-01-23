cmake_minimum_required(VERSION 4.1)
project(CCraft C)

set(CMAKE_C_STANDARD 23)

find_package(raylib REQUIRED)

add_executable(CCraft main.c
        src/obj.c
        src/obj.h
        src/world.c
        src/world.h
        src/block.h
        src/player.c
        src/player.h
        src/controls.c
        src/controls.h
)
