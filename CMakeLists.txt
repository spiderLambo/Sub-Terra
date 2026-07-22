cmake_minimum_required(VERSION 3.18)
project(subterra)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -g)

add_executable(${PROJECT_NAME}.out
  src/main.cpp
  src/entities/player.cpp
)

target_include_directories(${PROJECT_NAME}.out PRIVATE includes)
