cmake_minimum_required(VERSION 3.24)

add_subdirectory(game_object)

target_sources(${PROJECT_NAME} PRIVATE
        object.cc)
