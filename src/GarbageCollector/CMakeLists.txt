cmake_minimum_required(VERSION 3.19)
project(GarbgeCollector C)

set(CMAKE_C_STANDARD 99)

add_executable(GarbgeCollector mserver.c server.c server.c client.c
        node.h node.c)