# Author: Jeroen de Haas <jah.dehaas@avans.nl>
cmake_minimum_required(VERSION 3.1.3)
project(pigisland)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (MSVC)
    add_compile_options(/W3)
else ()
    add_compile_options(-Wall -Wpedantic)#  -Werror)
    add_compile_options("$<$<CONFIG:DEBUG>:-g>")
endif ()


add_executable(pigisland
        src/kmint/pigisland/main.cpp
        src/kmint/pigisland/node_algorithm.cpp
        src/kmint/pigisland/resources.cpp
        src/kmint/pigisland/shark.cpp
        src/kmint/pigisland/boat.cpp
        src/kmint/pigisland/pig.cpp
        src/kmint/pigisland/state/state.cpp
        src/kmint/pigisland/state/hunt.cpp
        src/kmint/pigisland/state/scared.cpp
        src/kmint/pigisland/state/tired.cpp
        src/kmint/pigisland/state/wandering.cpp
        src/kmint/pigisland/state/context.cpp
        src/kmint/pigisland/navigation.cpp
        src/kmint/pigisland/state/shark_wandering.cpp
        src/kmint/pigisland/fde/force_driven_entity.cpp
        include/kmint/pigisland/fde/iflock.hpp
        src/kmint/pigisland/fde/coherence_flock.cpp
        src/kmint/pigisland/fde/alignment_flock.cpp
        src/kmint/pigisland/fde/separation_flock.cpp
        src/kmint/pigisland/fde/separation_wall.cpp
        src/kmint/pigisland/fde/follow_actor.cpp
        src/kmint/pigisland/state/go_to_repair_place.cpp
        src/kmint/pigisland/repair_places/repair_place_factory.cpp)

target_compile_features(pigisland PUBLIC cxx_std_17)
target_link_libraries(pigisland PRIVATE kmint)
target_include_directories(pigisland PRIVATE
        src
        include)

add_custom_target(pigisland-resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/resources" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources")
