cmake_minimum_required(VERSION 3.24)

target_sources(${PROJECT_NAME} PRIVATE
        engine.cc
        keyboard.cc
        events.cc
        raytracer_engine.cc
        )