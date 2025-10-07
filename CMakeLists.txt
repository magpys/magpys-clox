cmake_minimum_required(VERSION 4.0)
project(clox C)

set(CMAKE_C_STANDARD 11)

add_executable(clox main.c
        memory.h
        memory.c
        common.h
        chunk.h
        chunk.c
        debug.h
        debug.c
        value.h
        value.c
        vm.h
        vm.c
        compiler.h
        compiler.c
        scanner.c
        scanner.h
)
