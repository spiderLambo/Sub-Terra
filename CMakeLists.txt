cmake_minimum_required(VERSION 3.18)
project(subterra)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -g)

add_executable(${PROJECT_NAME}.out
  src/main.cpp
  src/entities/player.cpp
  src/tuiles/tuile.cpp
  src/tuiles/tuile_corde.cpp
  src/tuiles/tuile_depart.cpp
  src/tuiles/tuile_effondrement.cpp
  src/tuiles/tuile_emanation.cpp
  src/tuiles/tuile_horreur.cpp
  src/tuiles/tuile_inondable.cpp
  src/tuiles/tuile_ordinaire.cpp
  src/tuiles/tuile_retrecissement.cpp
  src/tuiles/tuile_sortie.cpp
  src/tuiles/tuile_terrain_accidente.cpp
  src/plateau.cpp
  src/display/render.cpp
  src/display/engine/window.cpp
  src/display/engine/geometry.cpp
  src/display/entities/tuile.cpp

  src/utils/Str_to_color.cpp
)

target_include_directories(${PROJECT_NAME}.out PRIVATE includes)
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)
target_link_libraries(${PROJECT_NAME}.out PRIVATE
  sfml-graphics
  sfml-window
  sfml-system
)
