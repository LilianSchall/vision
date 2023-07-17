cmake_minimum_required(VERSION 3.24)

add_subdirectory(sphere)

target_sources(${PROJECT_NAME} PRIVATE
        object.cc)
