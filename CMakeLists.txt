cmake_minimum_required(VERSION 3.20)
project(DinoGame)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES src/main.cpp)

add_executable(dinogg ${SOURCES})

target_link_libraries(dinogg curses)
