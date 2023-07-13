cmake_minimum_required(VERSION 3.21.2)

project(vision)

add_library(vision SHARED src/vision.cc)

set_target_properties(vision PROPERTIES OUTPUT_NAME vision)
set_target_properties(vision PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)

target_compile_options(vision PRIVATE -Wall -Wextra -Werror -pedantic)

target_include_directories(vision PUBLIC include/)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

subdirs(src)
