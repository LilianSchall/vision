cmake_minimum_required(VERSION 3.24)

project(vision)

add_executable(vision)
add_subdirectory(src/)

set_target_properties(vision PROPERTIES OUTPUT_NAME vision)
set_target_properties(vision PROPERTIES
        CXX_STANDARD 20
        )

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -pedantic -g -pthread)
target_include_directories(${PROJECT_NAME} PUBLIC src/)

find_library(SDL2 NAMES SDL2)

target_link_libraries(${PROJECT_NAME} ${SDL2})
