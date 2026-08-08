cmake_minimum_required(VERSION 3.18)
project(subterra)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -g)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME}.out ${SOURCES})

target_include_directories(${PROJECT_NAME}.out PRIVATE includes)
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)
target_link_libraries(${PROJECT_NAME}.out PRIVATE
  sfml-graphics
  sfml-window
  sfml-system
)
