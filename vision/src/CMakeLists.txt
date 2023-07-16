cmake_minimum_required(VERSION 3.21.2)

add_subdirectory(engine)
add_subdirectory(tools)
add_subdirectory(transform)
add_subdirectory(maths)
add_subdirectory(object)

target_sources(${PROJECT_NAME} PRIVATE
        vision.cc)

