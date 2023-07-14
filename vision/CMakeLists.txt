cmake_minimum_required(VERSION 3.21.2)

project(vision)
include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)


add_library(vision SHARED src/vision.cc)

set_target_properties(vision PROPERTIES OUTPUT_NAME vision)
set_target_properties(vision PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)

target_compile_options(vision PRIVATE -Wall -Wextra -Werror -pedantic)

target_include_directories(vision PUBLIC "include/")
find_package(SDL2 REQUIRED)

FetchContent_Declare(
        SDL2_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
        GIT_TAG release-2.6.3
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
)

# START ADDITION
set(SDL2IMAGE_INSTALL OFF)
set(BUILD_SHARED_LIBS FALSE)
# END ADDITION

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

subdirs(src)
