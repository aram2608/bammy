cmake_minimum_required(VERSION 3.20)
project(bammy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(bammylib
    bammy/src/io/fastx.cpp
    bammy/src/cli/bammy.cpp
)

target_include_directories(bammylib
    PUBLIC 
    bammy/src/io/
    bammy/src/cli/
)

target_compile_options(bammylib
    PRIVATE
    -Wall 
    -Wextra 
    -Wpedantic 
    -Wconversion
    -Wpessimizing-move
    -Wredundant-move
    -Wmove
    -Wrange-loop-construct
)

add_executable(bammy
    bammy/src/main.cpp
)

target_link_libraries(bammy PRIVATE bammylib)