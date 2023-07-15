cmake_minimum_required(VERSION 3.21.2)

target_sources(${PROJECT_NAME} PUBLIC
        vision.cc)

add_subdirectory(setup)
add_subdirectory(tools)
