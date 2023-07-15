cmake_minimum_required(VERSION 3.21.2)

add_subdirectory(setup)
add_subdirectory(tools)

target_sources(${PROJECT_NAME} PRIVATE
        vision.cc)

