cmake_minimum_required(VERSION 3.19)
project(Redes C)

set(CMAKE_C_STANDARD 11)

add_executable(Redes
        server.c server.h client.c client.h)
